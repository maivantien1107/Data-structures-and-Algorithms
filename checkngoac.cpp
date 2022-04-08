#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Node{
    char c;
    Node* next;
};

typedef struct Stack{
    Node* top;
    Stack(){
        top = NULL;
    }
    void push(char c){
        Node* q = (Node*)malloc(sizeof(Node));
        q->c = c;
        q->next = top;
        top = q;
    }
    char pop(){
        if(empty()) return ' ';
        Node* tmp = top;
        char x = tmp->c;
        top = top->next;
        free(tmp);
        return x;
    }
    bool empty(){
        return top == NULL;
    }
};
bool match(char a, char b){
    if(a == '(' && b == ')') return true;
    if(a == '[' && b == ']') return true;
    if(a == '{' && b == '}') return true;
    return false;
}
bool check(char* s){
    Stack S;
    for(int i = 0; i < strlen(s); i++){
        if(s[i] == '[' || s[i] == '(' || s[i] == '{'){
                S.push(s[i]);
        }else{
            if(S.empty()) return false;
            char a  = S.pop();
            if(!match(a,s[i])) return false;
        }
    }
    return S.empty();
}

int main(){
    char* s = "[({})[]}()()[()(){}]";
    bool ok = check(s);
    if(ok) printf("Y\n"); else printf("N\n");

}
