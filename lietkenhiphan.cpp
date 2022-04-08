#include <stdio.h>
const int N = 100;
int x[N];
int n;
int cnt;

int check(int v, int k){
    if(k == 1) return 1;
    return x[k-1] + v <= 1;
}
void solution(){
    cnt++;
    printf("solution %d: ",cnt);
    for(int i = 1; i<= n; i++) printf("%d ",x[i]);
    printf("\n");
}
void TRY(int k){// try all values for x[k] being aware x[1,...k-1]
    for(int v = 0; v <= 1; v++){
        if(check(v,k)){
            x[k] = v;
            if(k == n) solution();
            else TRY(k+1);
        }
    }
}
int main(){
    n = 3;
    cnt = 0;
    TRY(1);
}
