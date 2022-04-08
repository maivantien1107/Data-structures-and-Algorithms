#include <stdio.h>
const int N = 100;

int m[N][N];

void init(){
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            m[i][j] = -1;
}

int C(int k, int n){
    if(k == 0 || k == n){
            m[k][n] = 1;
    } else{
        if(m[k][n] < 0)
            m[k][n] = C(k,n-1) + C(k-1,n-1);
    }
    return m[k][n];
}
int main(){
    init();
    printf("%d\n",C(16,32));
}
