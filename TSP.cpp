#include <stdio.h>

const int N = 100;
int c[N][N];

int x[N];
int n;
bool m[N];
int f;
int min_f;
int cmin;

void input(){
    FILE* f = fopen("TSP-13.INP","r");
    fscanf(f,"%d",&n);
    //printf("read n = %d\n",n);
    cmin = 1000000;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            fscanf(f,"%d",&c[i][j]);
            if(i != j && c[i][j] < cmin) cmin = c[i][j];
        }
    fclose(f);
}
void solution(){
    if(f + c[x[n]][x[1]] < min_f){
        min_f = f + c[x[n]][x[1]];
        printf("update best = %d\n",min_f);
    }
}
void TRY(int k){
        for(int v = 1; v <= n; v++){
            if(!m[v]){
                x[k] = v;
                m[v] = true;
                f = f + c[x[k-1]][x[k]];
                if(k == n){
                    solution();
                }else{
                    int gk = f + (n-k+1)*cmin;
                    if(gk < min_f)
                        TRY(k+1);
                }
                m[v] = false;
                f = f - c[x[k-1]][x[k]];
            }
        }
}
void solve(){
    for(int v = 1; v <= n; v++) m[v] = false;
    x[1] = 1;
    m[x[1]] = true;
    f = 0;
    min_f = 10000000;
    TRY(2);
}
int main(){
    input();
    solve();
    printf("min_f = %d\n",min_f);
}
