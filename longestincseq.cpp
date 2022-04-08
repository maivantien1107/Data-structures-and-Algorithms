#include <stdio.h>
const int N = 10000;
int n = 9;
int a[10] = {0,3,5,2,4,9,6,8,7,1};

int P[N];
int trace[N];
int ans,k;
int main(){
        P[1] = 1;
        ans = P[1];
        trace[1] = 0;
        k = 1;
        for(int i = 2; i <= n; i++){
                P[i] = 1; trace[i] = 0;
                for(int j = 1; j <= i-1; j++) if(a[j] < a[i]){
                    if(P[i] < P[j] + 1){
                        P[i] = P[j] + 1;
                        trace[i] = j;
                        printf("update P[%d] = %d, trace[%d] = %d\n",i,P[i],i,trace[i]);
                    }
                }
                if(ans < P[i]){
                    ans = P[i]; k = i;
                }
        }
        for(int i = 1; i <= n; i++){
            printf("%d ",P[i]);
        }
        printf("\n");
        for(int i = 1; i<= n; i++){
            printf("%d ",trace[i]);
        }
        printf("\n");

        int x = k;
        while(trace[x] > 0){
            printf("%d ",a[x]);
            x = trace[x];
        }
        printf("%d ",a[x]);

}

