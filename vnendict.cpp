#include <bits/stdc++.h>
#define MAX 1000000
#define MAX_L 100
typedef struct Node{
    char* en_word;
    char* vn_meaning;
    Node* leftChild;
    Node* rightChild;
};

char words[MAX][MAX_L];
int N;// so luong tu
Node* root;// con tro den goc cua BST

Node* makeNode(char* k){
    Node* p = (Node*)malloc(sizeof(Node));
    p->en_word = k;
    p->vn_meaning = NULL;
    p->leftChild  = NULL;
    p->rightChild = NULL;
    return p;
}
void loadData(char* fn){
    FILE* f = fopen(fn,"r");
    N = 0;
    while(!feof(f)){
        fscanf(f,"%s",words[N]);
        //if(N % 1000 == 0)
        //    printf("%d: read %s, len = %d\n",N,words[N],strlen(words[N]));
        N++;
    }
    fclose(f);
}
void swap(int i, int j){
    char tmp[MAX_L];// tmp = a[i]; a[i] = a[j]; a[j] = tmp;
    strcpy(tmp,words[i]);
    strcpy(words[i],words[j]);
    strcpy(words[j],tmp);
}
int partition(int L, int R, int index){
    char pivot[MAX_L];
    strcpy(pivot,words[index]);
    swap(index,R);
    int storeIndex = L;
    for(int i = L; i <= R-1; i++){
        int c = strcmp(words[i],pivot);
        if(c < 0){
            swap(storeIndex, i);
            storeIndex++;
        }
    }
    swap(storeIndex, R);
    return storeIndex;
}
void quickSort(int L, int R){
    if(L < R){
        int index = (L+R)/2;
        index = partition(L,R,index);
        if(L < index) quickSort(L,index-1);
        if(index  < R) quickSort(index+1,R);
    }
}
Node* makeBST(int L, int R){
    if(L>R) return NULL;
    if(L == R){
        return makeNode(words[L]);
    }
    int m = (L+R)/2;
    Node* r = makeNode(words[m]);
    r->leftChild = makeBST(L,m-1);
    r->rightChild = makeBST(m+1,R);
    return r;
}
int height(Node* r){
    if(r == NULL) return 0;
    int ml = height(r->leftChild);
    int mr = height(r->rightChild);
    return ml > mr ? ml + 1 : mr + 1;
}
Node* find(Node* r, char* w){
    if(r==NULL) return NULL;
    int c = strcmp(r->en_word,w);
    if(c ==0) return r;
    if(c < 0) return find(r->rightChild,w);
    else return find(r->leftChild,w);
}
void freeTree(Node* r){
    if(r == NULL) return;
    freeTree(r->leftChild);
    freeTree(r->rightChild);
    free(r->vn_meaning);
    free(r);
}
void finalize(){
    // giai phong bo nho
    freeTree(root);
}
int main(){
    loadData("words.txt");
    quickSort(0,N-1);
    root = makeBST(0,N-1);
    printf("height BST = %d\n",height(root));

    while(1){
        char cmd[50];
        printf("Enter a command: "); scanf("%s",cmd);
        if(strcmp(cmd,"find") == 0){
                // find a word
                char w[MAX_L];
                scanf("%s",w);
                Node* p = find(root,w);
                if(p == NULL) printf("NOT FOUND word %s\n",w);
                else printf("Found word %s: vn_meaning = %s\n",p->en_word,p->vn_meaning);
        }else if(strcmp(cmd,"set") == 0){
                // set VN meaning of found word
                char w[MAX_L];
                char* vn = (char*)malloc(MAX_L);
                scanf("%s",w);
                scanf("%s",vn);
                Node* p = find(root,w);
                if(p == NULL) printf("NOT FOUND word %s\n",w);
                else p->vn_meaning = vn;
        }else if(strcmp(cmd,"quit") == 0)break;
    }
    finalize();
}
