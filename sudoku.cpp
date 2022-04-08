#include <stdio.h>

int x[10][10];
bool m3[3][3][10];// m3[I][J][v] = true: gt v da xuat hien hinh vuong con (I,J)
bool m1[10][10];// m1[i][v] = true: gt v da xuat hien tren hang i
bool m2[10][10];// m2[i][v] = true: gt v da xuat hien tren cot i
bool found;

void solution(){
        found = true;
    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++)
            printf("%d ",x[i][j]);
        printf("\n");
    }
    printf("--------------------\n");
}
bool check(int v, int r, int c){
    if(m1[r][v]) return false;
    if(m2[c][v]) return false;
    if(m3[(r-1)/3][(c-1)/3][v]) return false;
    return true;
}
void TRY(int r, int c){
    if(found) return;
    for(int v = 1; v <= 9; v++){
        if(check(v,r,c)){
            x[r][c] = v;
            m1[r][v] = true;
            m2[c][v] = true;
            m3[(r-1)/3][(c-1)/3][v] = true;

            if(r == 9 && c == 9) solution();
            else{
                if(c < 9){
                    TRY(r,c+1);
                }else{
                    TRY(r+1,1);
                }
            }
            m1[r][v] = false;
            m2[c][v] = false;
            m3[(r-1)/3][(c-1)/3][v] = false;
        }
    }

}

int main(){
    for(int v = 1; v <= 9; v++){
        for(int r = 1; r <= 9; r++) m1[r][v] = false;
        for(int c = 1; c <= 9; c++) m2[c][v] = false;
        for(int I = 0; I <= 2; I++)
            for(int J = 0; J <= 2; J++)
                m3[I][J][v] = false;
    }
    found = false;
    TRY(1,1);
}
