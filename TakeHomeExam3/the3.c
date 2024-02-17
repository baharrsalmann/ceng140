#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "the3.h"

/*
    Create a cache by reading inputs from stdin
*/
CacheNode * mknode() 
{ CacheNode* newnode;
newnode= malloc ( sizeof(CacheNode)); 
return newnode;}

DomainFreqNode * mkfreqnode()
{ DomainFreqNode* newfreqnode;
newfreqnode=malloc(sizeof(DomainFreqNode));
return newfreqnode;
}

DomainFreqList * mkfreqlist()
{DomainFreqList* freqlist;
freqlist=malloc(sizeof(DomainFreqList));
return freqlist;
}

Cache* createCache()
{Cache* cache;
CacheNode *newnode;
DomainFreqList* domainfreqlist;
DomainFreqNode *newfreqnode, *cursor;
char currentline[1001], *name, *name2;
int i;

cache=malloc(sizeof(Cache));
scanf("%d%d\n",&((cache)->cacheLimit),&((cache)->mediaCount));

cache->head=NULL;
cache->tail=NULL;
cache->currentSize=0;

for(i=0;i<cache->mediaCount;i++) {
    newnode= mknode();
    fgets(currentline,1001,stdin);
    
    name=strtok(currentline," "); 
    newnode->media.size=atoi(strtok(NULL," "));
    cache->currentSize+=newnode->media.size;
    newnode->prev=NULL;
    newnode->next=NULL;

    newnode->media.name = malloc(strlen(name) + 1);
    strcpy(newnode->media.name, name);

    domainfreqlist=mkfreqlist();
    domainfreqlist->head=NULL;
    domainfreqlist->tail=NULL;
    newnode->domainFreqList = domainfreqlist;

    while(1) {
    
    newfreqnode=mkfreqnode();
    name2=strtok(NULL," ");
    if (!name2) break;
    
    newfreqnode->name = malloc(strlen(name2) + 1);
    strcpy(newfreqnode->name, name2);
    newfreqnode->freq=atoi(strtok(NULL," "));
    newfreqnode->prev=NULL;
    newfreqnode->next=NULL;

    cursor=domainfreqlist->head;
    
    while ((cursor) && ((cursor->freq > newfreqnode->freq) || ((cursor->freq == newfreqnode->freq) && strcmp(cursor->name, newfreqnode->name) < 0))) 
    {cursor=cursor->next; }
    
    if (cursor==NULL) {

        if (domainfreqlist->tail==NULL) {
            domainfreqlist->head=newfreqnode;
            domainfreqlist->tail=newfreqnode;
        }

        else {
            newfreqnode->prev=domainfreqlist->tail;
            domainfreqlist->tail->next=newfreqnode;
            domainfreqlist->tail=newfreqnode;
        } }
    else {
        newfreqnode->prev = cursor->prev ;
        newfreqnode->next = cursor;
        
        
        if(cursor->prev==NULL) domainfreqlist->head=newfreqnode;
        else cursor->prev->next=newfreqnode;
        
        cursor->prev=newfreqnode;
        }
    }
    


    if (cache->head==NULL){

    cache->head=newnode;
    cache->tail=newnode;
    }

    else{
    cache->tail->next=newnode;
    newnode->prev=cache->tail;
    cache->tail=newnode;
}   
   
}   
    return cache;
}



void printCache(Cache* cache) {
    int i;
    CacheNode* curs;
    
    DomainFreqNode* cursfreq;
    
    if(cache->mediaCount==0) printf("The Cache is Empty\n");
    
    printf("-------------- Cache Information --------------\nCache Limit: %d KB\nCurrent Size: %d KB\nMedia Count: %d\nCache Media Info:\n",cache->cacheLimit,cache->currentSize,cache->mediaCount);

    curs=cache->head;

    for(i=0;i<cache->mediaCount;i++) {
        printf("    Name: %s    Size: %d KB\n   ------- Media Domain Frequencies -------\n",curs->media.name,curs->media.size);

        cursfreq=curs->domainFreqList->head;

        while(cursfreq){
        printf("        Name: %s    Freq: %d\n",cursfreq->name,cursfreq->freq);

        cursfreq=cursfreq->next;
        }
        printf("    ----------------------------------------\n");
        curs=curs->next;
    }
    printf("----------------------------------------------");
}


void sizebasedaddition(Cache* cache,CacheNode* newnode, Media media){
        if((cache->currentSize+media.size)<=(cache->cacheLimit)){
            cache->currentSize+=media.size;
            newnode->next=cache->head;
            cache->head->prev=newnode;
            newnode->prev=NULL;
            cache->head=newnode;
            cache->mediaCount++; 
            return;
        }
        else if(cache->mediaCount==1){
            cache->head=newnode;
            cache->tail=newnode;
            cache->currentSize=media.size;
            cache->mediaCount=1;
            return;
        }
        else {
            cache->currentSize-=cache->tail->media.size;
            cache->tail->prev->next=NULL;
            cache->tail=cache->tail->prev;
            cache->mediaCount--;
            sizebasedaddition(cache,newnode,media);
        }
        }

CacheNode* addMediaRequest(Cache* cache, Media media, char* domain) {
    CacheNode *curs, *newnode;
    DomainFreqList* domainfreqlist;
    DomainFreqNode* newfreqnode, *imlec, *freqcursor;
    int i;
    curs=cache->head;
    for(i=0;i<cache->mediaCount;i++){
        if (curs && strcmp(media.name,curs->media.name)) curs=curs->next;
        else break;
    }

    if(!curs) {
        newnode=mknode();
        newnode->media.size=media.size;
        newnode->media.name=malloc(strlen(media.name)+1);
        strcpy(newnode->media.name,media.name);
        domainfreqlist=mkfreqlist();
        newfreqnode=mkfreqnode();
        newfreqnode->name=malloc(strlen(domain)+1);
        strcpy(newfreqnode->name,domain);
        newfreqnode->freq=1;
        newfreqnode->prev=NULL;
        newfreqnode->next=NULL;
        domainfreqlist->head=newfreqnode;
        domainfreqlist->tail=newfreqnode;
        newnode->domainFreqList=domainfreqlist;

        sizebasedaddition(cache,newnode,media); 
        
    }

    else {   
        if (!(curs==cache->head)) {      
        curs->prev->next=curs->next;
        curs->next->prev=curs->prev;
        curs->prev=NULL;
        curs->next=cache->head;
        cache->head=curs;
        }
        
        freqcursor=curs->domainFreqList->head;
        while(freqcursor){
            if (freqcursor && strcmp(freqcursor->name,domain)) freqcursor=freqcursor->next;
            else break; }
        if(!freqcursor) { 
        newfreqnode=mkfreqnode();
        newfreqnode->name=malloc(strlen(domain)+1);
        strcpy(newfreqnode->name,domain);
        newfreqnode->freq=1;
        curs->domainFreqList->tail->next=newfreqnode;
        newfreqnode->prev=curs->domainFreqList->tail;
        newfreqnode->next=NULL;
        freqcursor=newfreqnode;
        }
        else { 
        (freqcursor->freq)++ ;
        }
        
        imlec=freqcursor->prev;
        while ((imlec) && ((freqcursor->freq > imlec->freq) || ((freqcursor->freq == imlec->freq) && strcmp(freqcursor->name, imlec->name) < 0))) {
        imlec=imlec->prev;
        }

        if(!imlec) { 
            freqcursor->prev->next=freqcursor->next;
            freqcursor->next->prev=freqcursor->prev;
            curs->domainFreqList->head->prev=freqcursor;
            freqcursor->next=curs->domainFreqList->head;
            freqcursor->prev=NULL;
        }
        else{ 
            if(!(freqcursor->next)&&!(imlec->next==freqcursor)) {
                freqcursor->prev->next=NULL;
                imlec->next->prev=freqcursor;
                freqcursor->next=imlec->next;
                imlec->next=freqcursor;
                freqcursor->prev=imlec;
            }
            else if(!(imlec->next==freqcursor)) {
            freqcursor->prev->next=freqcursor->next;
            freqcursor->next->prev=freqcursor->prev;
            imlec->next->prev=freqcursor;
            freqcursor->next=imlec->next;
            imlec->next=freqcursor;
            freqcursor->prev=imlec;
        } }
    }    
return curs;
    
}

CacheNode* findMedia(Cache* cache, char* name){
    CacheNode* cursor;
    int i;
    cursor=cache->head;
    for(i=0;i<cache->mediaCount;i++) {
        if (cursor && strcmp(name,cursor->media.name)) cursor=cursor->next;
        else break;
    }
    return cursor;
}

void deleteMedia(Cache* cache, char* name) {
    CacheNode* cursor;
    int i;
    cursor=cache->head;
    for(i=0;i<cache->mediaCount;i++) {
        if (cursor && strcmp(name,cursor->media.name)) cursor=cursor->next;
        else break;
    }
    if(cursor){
        cache->mediaCount-=1;
        cache->currentSize-=cursor->media.size;
        if(!(cursor->prev)) {
            cursor->next->prev=NULL;
            cache->head=cursor->next;}
        else if(!(cursor->next)){ 
            cursor->prev->next=NULL;
            cache->tail=cursor->prev; }
        else {
            cursor->prev->next=cursor->next;
            cursor->next->prev=cursor->prev;
        }
        
    }
}

