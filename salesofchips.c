#include <stdio.h>
int main() {
    int arr[5][10][7];
int totalweeklychip[5],totalweeklycity[10],totaldaily[7],i,j,k;
for(i=0;i<5;i++) {
    for(j=0;j<10;j++) {
        for(k=0;k<7;k++) {
            totalweeklychip[i]+=arr[i][j][k]; 
            totalweeklycity[j]+=arr[i][j][k];
            totaldaily[k]+=arr[i][j][k];
        }}}

for(i=0;i<5;i++) printf("%d. çipin weekly salesi: %d\n",i,totalweeklychip[i]);
for(i=0;i<10;i++) printf("%d. citynin weekly salesi: %d\n",i,totalweeklycity[i]);
printf("average daily sale: %d",(totaldaily[0]+totaldaily[1]+totaldaily[2]+totaldaily[3]+totaldaily[4]+totaldaily[5]+totaldaily[6])/7);
}