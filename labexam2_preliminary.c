#include <math.h>
#include <stdio.h>

#include "lab_2.h"

/*
    This function takes:
        - vector that is array of floats (vec)
        - the size of the array (size)
    as parameters and returns the length of the vector
    that is given in the description
*/
float length(float vec[], int size)
{
    
    float result = 0.0;
    int i;
    float total=0;
    
    /* WRITE YOUR CODE HERE */
    
    for(i=0;i<size;i++) {
        total += (vec[i]*vec[i]) ; }
    
    result=sqrt(total);
    
    return result ;
}


/*
    This function takes:
        - vec1 (array of floats)
        - vec2 (array of floats)
        - size (size of vec1 and vec2)
    as parameters and returns the dot product
    of vec1.vec2 that is given in the description
*/
float dot(float vec1[], float vec2[], int size)
{
    float result = 0.0;
    int i;
    
    /* WRITE YOUR CODE HERE */
    for(i=0;i<size;i++) result += (vec1[i]*vec2[i]) ;
    
    return result;
}

/*
    This function takes:
        - vertices -> 2D vertex coordinates of an object (V1x, V1y, V2x, V2y, .... Vnx,Vny)
        - vertexCount -> how many vertices does the object have (Note: size of vertices array becomes vertexCount * 2)
        - commands -> Array of translation commands (C1x, C1y, C2x, C2y, ... Cnx, Cny)
        - commandCount -> how many commands exist (Note: size of commands array becomes commandCount * 2)
        
    You will print the resulting vertices as it is explained in the description. You just have to print the output using "printf"
    
     DO NOT TRY TO RETURN ANYTHING WITH THIS FUNCTION. THIS FUNCTION HAS VOID RETURN TYPE
*/
void translateVertices(float vertices[], int vertexCount, float commands[], int commandCount)
{
    /* WRITE YOUR CODE HERE */
    
    float xoperation=0 , yoperation=0 ;
    int i;
    
    for(i=0;i<commandCount*2;i=i+2) {
        xoperation += commands[i];
    }
    for(i=1;i<commandCount*2;i=i+2) {
        yoperation += commands[i];
    }
    
    for(i=0;i<vertexCount*2;i=i+2) {
        vertices[i] += xoperation;
    }
    for(i=1;i<vertexCount*2;i=i+2) {
        vertices[i] += yoperation;
    }
    
    for(i=0;i<vertexCount*2-1;i++) printf("%.2f ",vertices[i]);
    printf("%.2f",vertices[vertexCount*2-1]);
    
    
    
    
    
}

/*
    This function takes:
        - A -> 2D Vertex coordinates of object A
        - vertexCountA -> how many vertices does the object have (Note: size of A becomes vertexCountA * 2)
        - B -> 2D Vertex coordinates of object B
        - vertexCountB -> how many vertices does the object have (Note: size of B becomes vertexCountB * 2)
        - rowSize -> how many rows does the grid have
        - columnSize -> how many columns does the grid have
        
    You will print the 2D Grid as it is explained in the description. You just have to print the output using "printf"
    
    DO NOT TRY TO RETURN ANYTHING WITH THIS FUNCTION. THIS FUNCTION HAS VOID RETURN TYPE

*/
void visualizeObjects(int A[], int vertexCountA,
                      int B[], int vertexCountB,
                      int rowSize, int columnSize)
{
  /* WRITE YOUR CODE HERE */
    int grid[100][100];
  
  int i,j,x,y;
  
  for(i=0; i< rowSize; i++) {
      for(j=0; j<columnSize ; j++) {
          grid[i][j]='-'; }}
  
  for(i=0; i< rowSize; i++) {
      for(j=0; j<columnSize ; j++) {
         for(x=0; x<vertexCountA*2;x=x+2){
            if (i==A[x] && j==A[x+1]) {
                
                for(y=0;y<vertexCountB*2;y=y+2) {
                    if (i==B[y] && j==B[y+1]) {
                    grid[i][j]='x';
                    break;} }
            
                if (grid[i][j]=='-')
                {grid[i][j]='a';
                break; }
                
            }}
        if (grid[i][j]=='-') {
        for(x=0; x<vertexCountB*2;x=x+2){
            if (i==B[x] && j==B[x+1]) {
            grid[i][j]='b';
            break;}}
        }
         }}
         
    for(i=0; i< rowSize-1; i++) {
      for(j=0; j<columnSize-1 ; j++) { 
          printf("%c  ",grid[i][j]);  }
          
       printf("%c", grid[i][columnSize-1]);
       printf("\n"); }
    
    for(j=0;j<columnSize-1;j++) {
        printf("%c  ",grid[rowSize-1][j]); }
    
    printf("%c", grid[rowSize-1][columnSize-1]);
    
  
  }