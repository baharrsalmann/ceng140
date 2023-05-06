#ifndef _LAB_2_
#define _LAB_2_

#define MAX_ARRAY_SIZE

float length(float vec[], int size);


float dot(float vec1[], float vec2[], int size);


void translateVertices(float vertices[], int vertexCount, float commands[], int commandCount);


void visualizeObjects(int A[], int vertexCountA,
                      int B[], int vertexCountB,
                      int rowSize, int columnSize);


#endif