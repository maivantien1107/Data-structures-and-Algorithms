#include <stdio.h>

int cnt;
void move(int n, char A, char B, char C){
    if(n == 1){
            cnt++;
            printf("Step %d: %c -> %c\n",cnt,A,B);
    }
    else{
        move(n-1,A,C,B);
        move(1,A,B,C);
        move(n-1,C,B,A);
    }
}
int main(){
    cnt = 0;
    move(20,'A','B','C');
}
