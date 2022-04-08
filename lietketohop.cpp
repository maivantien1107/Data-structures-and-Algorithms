#include <stdio.h>
const int N = 100;
int x[N];
int n,k;

void solution(){
    for(int i = 1; i <= k; i++) printf("%d ",x[i]); printf("\n");
}
void TRY(int i){// thu gia tri cho x[i]
    for(int v = x[i-1] + 1; v <= n-k+i; v++){
        x[i] = v;
        if(i == k) solution();
        else TRY(i+1);
    }
}

int main(){
    n = 5; k = 3;
    x[0] = 0;
    TRY(1);
}
