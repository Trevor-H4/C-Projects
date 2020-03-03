//
//  Prelab5.c
//  
//
//  Created by Trevor Hileman on 2/17/20.
//

#include <stdio.h>
#include <stdlib.h>

void **createTable(int numRows, int numCols, int elemSize);
int getRowSize(void **arr);
int getColSize(void **arr);
void freeTable(void **arr);

int main(void)
{
    double **array = (double **)createTable(10, 15, sizeof(double));
    int row = getRowSize((void **)array);
    int col = getColSize((void **)array);
    
    printf("\nThere are %d rows and %d columns in this table\n", row, col);
    
    freeTable((void**)array);
    
    return 0;
}

void **createTable(int numRows, int numCols, int elemSize)
{
    int **arr = (int **) malloc(sizeof(void * ) * numRows + 2 * sizeof(int));
    
    if (arr == NULL)
    {
        puts("\nError. Memory could not be allocated.\n");
        return NULL;
    }
    
    *(int *)arr = numRows;
    arr = (int **)arr + 1;
    
    *(int *)arr = numCols;
    arr = (int **)arr + 1;
    
    for (int i = 0; i < numRows; i++)
    {
        *(arr + i) = malloc(numCols * elemSize);
        
        if ( *(arr + i) == NULL)
        {
            puts("\nError. Memory could not be allocated\n");
            return NULL;
        }
    }
    
    
    return (void **)arr;
}

int getRowSize(void **arr)
{
    return (*(int *)(arr - 2));
}

int getColSize(void **arr)
{
    return (*(int *)(arr - 1));
}

void freeTable(void **arr)
{
    arr = (void**)((int*)((int*)arr - 1) - 1);
    int rows = getRowSize(arr);
    
    for (int i = 0; i < rows; i++)
    {
        free(arr[i]);
    }
    
}
