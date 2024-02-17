#include <stdio.h>

double calculate(int row, int column, double block_weight) {
    if (row==0 && column==0) {
        return 0 ; }
    else if (column==0) {
        return (block_weight)/2 + calculate(row-1,0,block_weight)*15/100; }
    else if(row==column) {
        return block_weight/2 + calculate(row-1,column-1,block_weight)*15/100; }
    else {
        return block_weight + calculate(row-1,column-1,block_weight)*15/100 + calculate(row-1,column,block_weight)*15/100; }
}

int helper(int r,int c, double W,int N) {
    double result;
    result=calculate(r,c,W);

    if (r==N-1 && c==N-1){
        printf("(%d,%d) %.8f\n",r,c,result);
        return 0;
    } 
    else if (c<r) {
        printf("(%d,%d) %.8f\n",r,c,result);
        return helper(r,c+1,W,N);
    }
    else if (c==r) {
        printf("(%d,%d) %.8f\n",r,c,result);
        return helper(r+1,0,W,N);
    }
}

double calculate_pressure_on_block(int rc, int N, double block_weight) {  
    helper(0,0,block_weight,N);
    }        

int main() {
    double W;
    int N;
    scanf("%d%lf",&N,&W);
    calculate_pressure_on_block(0,N,W);

}