#include <stdio.h>
const int N = 100;
int x[N];
int n;
bool appear[N];

void solution(){
    for(int i = 1; i <= n; i++) printf("%d ",x[i]); printf("\n");
}
int check(int v, int k){
   return !appear[v];
}
void TRY(int k){
    for(int v = 1; v <= n; v++){
        if(check(v,k)){
            x[k] = v;
            appear[v] = true;
            if(k == n) solution();
            else TRY(k+1);
            appear[v] = false;// recover when backtracking
        }
    }
}
int main(){
    n = 4;
    for(int v = 1; v <= n; v++) appear[v] = false;
    TRY(1);
}
