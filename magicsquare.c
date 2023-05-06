#include <stdio.h>

int fonk(int n) {
    int arr[n][n],i,j,k,x,y;
    
    for(x=0;x<n;x++) {
        for(y=0;y<n;y++) {
        arr[x][y]=0;       
    }    
}

i=n-2;
j=(n+1)/2;

for(k=1;k<(n*n+1);k++) {
    i=i+1;
    j=j-1;
    if (i==n && j==-1) {i=i-2;  j=j+1;}                        
    else if (i==n) {i=0; }                                              
    else if (j==-1) { j=(n-1);}
    else if (arr[i][j]!=0) {i=i-2;  j=j+1;}

    arr[i][j]=k;
    
    }

    for(x=0;x<n;x++) {
    for(y=0;y<n;y++) {
        
            printf("%d ",arr[x][y]);
             
    }    
    printf("\n");
}
}


int main() {
    int size;
    scanf("%d",&size);
    fonk(size);
    return 0;
}