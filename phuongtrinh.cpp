#include <stdio.h>

const int N = 100;
int x[N];
int n,M;

int sum;

void solution(){
    for(int i = 1; i <= n; i++) printf("%d ",x[i]); printf("\n");
}
int check(int v, int k){
    if(k < n) return 1;
    return sum+v == M;
}
void TRY(int k){
    for(int v = 1; v <= M - sum - (n-k) ; v++){
        if(check(v,k)){
            //printf("TRY(%d), v = %d, sum = %d\n",k,v,sum);
            x[k] = v;
            sum += v; // update incrementally
            if(k == n) solution();
            else TRY(k+1);
            sum -= v; // recover when backtracking
        }
    }
}
int main(){
    n =10; M = 30;
    sum = 0;
    TRY(1);
}
