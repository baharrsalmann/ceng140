#include <stdio.h>

//program determines whether given array is a narrowing zigzag

int createarr(int N) {
    int arr[N],i,iszigzag=1;
    for(i=0;i<N;i++) scanf("%d",&arr[i]);

    
    for(i=1;i<N-1;i++) {
        if (i%2==0) {
            if ((arr[i]>arr[i-1]) && (arr[i]>arr[i+1])) continue;
            else iszigzag=0;
        }
        else if (i%2==1) { 
            if ((arr[i]<arr[i-1]) && (arr[i]<arr[i+1])) continue;
            else iszigzag=0;
        }
}
    if (iszigzag==0) {
        printf("Not a zigzag");
        return 0;
    }

    int isnarrowing=1;
    for(i=1;i<N-1;i++) {
        if (i%2==1) {
            if (-arr[i]+arr[i-1]>arr[i+1]-arr[i]) continue;
            else isnarrowing=0; }
    else if (i%2==0) {
        if (arr[i]-arr[i-1]>-arr[i+1]+arr[i]) continue;
        else isnarrowing=0; }
    }

    if (isnarrowing==1) printf("Narrowing zigzag");
    else printf("Zigzag but not narrowing");
}




int main() {
    int size;
    scanf("%d",&size);
    createarr(size);    
}
