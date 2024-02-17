#include <stdio.h>
#include <stdlib.h>

int startx,starty,row_no=0,column_no=0,n=1;
int **path;
char** grid;

int main() {
    int i=0,j,index=1;
   char lineinput[134000]={0};
    int char_no;    
   void recursive(int x,int y);
    scanf("%d%d",&startx,&starty);

    while ((scanf("%c",&lineinput[i])) != EOF)  i++; 
    

    char_no=i;  
    i=1;                                   
    while (lineinput[i]!='\n') {
        column_no++  ;            
        i++; }

    for(i=1;i<char_no-1;i++)  {
        if (lineinput[i]=='\n') row_no++;  }  
  

     grid= malloc((row_no+1)*sizeof(char*));             
    
 for(i=0;i<row_no+1;i++) {
        grid[i]=malloc((column_no)*sizeof(char));
    }

    for (i = 0; i < row_no+1; i++) {                
        for (j = 0; j < column_no; j++) {
            grid[i][j] = lineinput[index];
            index++; }
        index++;                           
    } 

    grid[starty][startx]='.';

    
    

    path=malloc(sizeof(int*)*1);       
        path[0]=malloc(sizeof(int)*2);
        path[0][0]=startx; 
        path[0][1]=starty; 

    recursive(startx,starty); 
    return 0;
}

    void recursive(int x,int y) {
        int i,j;
        if (x==0 || x==column_no-1 || y==0 || y==row_no)  {                           
        
        for(i=0;i<n;i++) grid[path[i][1]][path[i][0]]='*';
        
        
        for(i=0;i<row_no+1;i++){
            for(j=0;j<column_no;j++) {
                if (grid[i][j]=='.') grid[i][j]=' '; 
                printf("%c",grid[i][j]);}
            printf("\n");             
        }
        
        
        return;
        }

        else if(x==startx && y==starty && grid[y][x+1]!=' ' && grid[y+1][x]!=' ' && grid[y][x-1]!=' ' && grid[y-1][x]!=' ') {
        
        
        for(i=0;i<row_no+1;i++){
            for(j=0;j<column_no;j++) { 
                printf("%c",grid[i][j]);
            }
                printf("\n");             
        }
       
        return;
        
    }

        else if (y-1>=0 && grid[y-1][x]==' ') { 
        n++;
        path=realloc(path,sizeof(int*)*n);
        path[n-1]=malloc(sizeof(int)*2);
        path[n-1][0]=x;
        path[n-1][1]=y-1;
        grid[y-1][x]='.';
        recursive(x,y-1);
        }
        
        else if (x-1>=0 && grid[y][x-1]==' ') { 
        n++;
        path=realloc(path,sizeof(int*)*n);
        path[n-1]=malloc(sizeof(int)*2);
        path[n-1][0]=x-1;
        path[n-1][1]=y;
        grid[y][x-1]='.';
        recursive(x-1,y);
        }
        
        else if (y+1<=row_no && grid[y+1][x]==' ') {  
        n++;
        path=realloc(path,sizeof(int*)*n);
        path[n-1]=malloc(sizeof(int)*2);
        path[n-1][0]=x;
        path[n-1][1]=y+1;
        grid[y+1][x]='.';
        recursive(x,y+1);
        }

        else if (x+1<column_no && grid[y][x+1]==' ') { 
        n++;
        path=realloc(path,sizeof(int*)*n);
        path[n-1]=malloc(sizeof(int)*2);
        path[n-1][0]=x+1;
        path[n-1][1]=y;
        grid[y][x+1]='.';
        recursive(x+1,y);
        }
        
        else if (x+1<column_no && y+1<=row_no && x-1>=0 && y-1>=0 && grid[y][x+1]!=' ' && grid[y+1][x]!=' ' && grid[y][x-1]!=' ' && grid[y-1][x]!=' ') {
            n--;
            free(path[n]);
            path=realloc(path,sizeof(int*)*(n));
            recursive(path[n-1][0],path[n-1][1]);
        }
    }
