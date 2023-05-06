#include <stdio.h>
#define STATES 50 

int main() {

    int statecode,peoplecount[STATES]={0},i,totalpeople=0;
    float individualincome, arrincomes[STATES]={0},totalincome=0;
    while (((scanf("%d %f",&statecode,&individualincome))!=EOF) && (statecode>=1) && (statecode<STATES)) {
        arrincomes[statecode]+=individualincome;
        peoplecount[statecode]+=1;
        totalincome+=individualincome;
        totalpeople+=1;
    }

    for(i=0;i<STATES;i++) {
        if (peoplecount[i]!=0) printf("state %d : %.2f\n",i,arrincomes[i]/peoplecount[i]);
        else printf("no data for state %d\n",i);
    }

    printf("national average %.2f",totalincome/totalpeople);

    return 0;
}




