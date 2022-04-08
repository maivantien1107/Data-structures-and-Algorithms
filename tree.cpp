#include <bits/stdc++.h>

struct Node{
    int id;
    Node* leftMostChild;
    Node* rightSibling;
};

Node* root;

Node* makeNode(int v){
    Node* p = (Node*)malloc(sizeof(Node));
    p->id = v;
    p->leftMostChild = NULL;
    p->rightSibling = NULL;
    return p;
}
Node* find(Node* r, int v){
    if(r == NULL) return NULL;
    if(r->id == v) return r;
    Node* p = r->leftMostChild;
    while(p != NULL){
        Node* q = find(p,v);
        if(q != NULL) return q;
        p = p->rightSibling;
    }
    return NULL;
}
void insert(int u, int v){
    // tao 1 nut co id = v, chen vao cuoi DS nut con cua nut co id = u
    Node* p = find(root,u);
    if(p == NULL) return;
    Node* tmp = p->leftMostChild;
    if(tmp == NULL){
        p->leftMostChild = makeNode(v); return;
    }
    while(tmp->rightSibling != NULL) tmp = tmp->rightSibling;
    tmp->rightSibling = makeNode(v);
}

void printTree(Node* r){
    if(r == NULL) return;
    printf("%d: ",r->id);// in ra id cua mut goc r
    Node* p = r->leftMostChild;
    while(p != NULL){
        printf("%d ",p->id);// in ra id cua cac nut con cua r tu trai qua phai
        p = p->rightSibling;
    }
    printf("\n");
    // goi de quy de in ra cac cay con cua r
    p = r->leftMostChild;
    while(p != NULL){
        printTree(p);// goi de quy de in ra cay con co goc p
        p = p->rightSibling;
    }
}
int count(Node* r){
    if(r == NULL) return 0;
    Node* p = r->leftMostChild;
    int cnt = 1;// nut goc
    while(p != NULL){
        cnt += count(p);// dem so nut tren cay con goc la p
        p = p->rightSibling;
    }
    return cnt;
}
int countLeaves(Node* r){
    if(r == NULL) return 0;
    Node* p = r->leftMostChild;
    if(p == NULL) return 1;
    int cnt = 0;
    while(p != NULL){
        cnt += countLeaves(p);
        p = p->rightSibling;
    }
    return cnt;
}
void preOrder(Node* r){
    if(r == NULL) return;
    printf("%d ",r->id);
    Node* p  = r->leftMostChild;
    while(p != NULL){
        preOrder(p);
        p = p->rightSibling;
    }
}
void inOrder(Node* r){
    if(r == NULL) return ;
    Node* p = r->leftMostChild;
    inOrder(p);
    printf("%d ",r->id);
    if(p != NULL) p = p->rightSibling;
    while(p != NULL){        inOrder(p);        p = p->rightSibling;    }
}
void postOrder(Node* r){
    if(r == NULL) return;
    Node* p = r->leftMostChild;
    while(p != NULL){        postOrder(p);        p = p->rightSibling;    }
    printf("%d ",r->id);
}
int heightNode(Node* r){
    if(r == NULL) return 0;
    int maxH = 0;
    Node* p = r->leftMostChild;
    while(p != NULL){
        int h = heightNode(p);// de quy de tinh do cao cua nut con p
        maxH = maxH < h ? h : maxH;
        p = p->rightSibling;
    }
    return maxH + 1;
}
int height(int v){
    // tra ve do cao cua nut v tren cay
    Node* p = find(root,v);
    return heightNode(p);
}
void freeTree(Node* r){
    if(r == NULL) return;
    Node* p = r->leftMostChild;
    if(p == NULL){
        free(r); return;
    }
    Node* np = p->rightSibling;
    while(p != NULL){
        freeTree(p);
        p = np;
        if(np != NULL)
            np = np->rightSibling;
    }
    free(r);// thu hoi bo nho doi voi nut goc r
}
int depthNode(Node* r, int dr, int v){
    // tra ve do sau cua nut id = v tren cay goc r ma do sau cua r so voi root = dr
    if(r == NULL) return -1;
    if(r->id == v) return dr;
    Node* p = r->leftMostChild;
    while(p != NULL){
        if(p->id == v) return dr + 1;
        int d = depthNode(p,dr+1,v);
        if(d > -1) return d;
        p = p->rightSibling;
    }
    return -1;
}
int depth(int v){
    return depthNode(root,1,v);
}
int main(){
    root = makeNode(10);
    insert(10,11);
    insert(10,1);
    insert(10,3);
    insert(11,5);
    insert(11,4);
    insert(3,8);
    insert(3,2);
    insert(3,7);
    insert(4,6);
    insert(4,9);
    printTree(root);
    printf("So nut tren cay la %d\n",count(root));
    printf("So nut la tren cay la %d\n",countLeaves(root));
    printf("Duyet thu tu truoc: "); preOrder(root);
    printf("Duyet thu tu giua: "); inOrder(root);
    printf("\n");
    printf("Do cao cua nut 1 = %d\n",height(1));

    freeTree(root);
}
