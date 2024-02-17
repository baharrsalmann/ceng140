#include <stdio.h>

int main() {


int  partynum,seatnum,x,i,lastswitch,lastie;
float votes[26];
int denominators[26];
int seats[26];
float maks,maksie;
char parties[]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

scanf("%d%d",&partynum,&seatnum);
for(x=0;x<partynum;x++) {
    scanf("%f",&votes[x]);
    denominators[x]=1;
    seats[x]=0;
}
for(x=0;x<seatnum;x++) {
    lastswitch=0 ;
    maks=votes[0]/denominators[0] ;
        for(i=1;i<partynum;i++) {
            if ((votes[i]/denominators[i])>maks) {
                maks=votes[i]/denominators[i] ;
                lastswitch=i;
            }
            else if (((votes[i]/denominators[i])==maks) && (votes[i]>votes[lastswitch])) {
                maks=votes[i]/denominators[i] ;
                lastswitch=i;
            }
        }
    
    denominators[lastswitch]++ ;
    seats[lastswitch]++ ;
}

for(x=0;x<partynum;x++) {
    lastie=0;
    maksie=seats[0];
    for(i=1;i<partynum;i++) {
        if(seats[i]>maksie) {
            maksie=seats[i];
            lastie=i;
            
        }
    }
    if (maksie==0) {break;}
    else {
    printf("%c: %d\n",parties[lastie],seats[lastie]);
    seats[lastie]=0;
    }
}
return 0 ;
}