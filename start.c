#include <stdio.h>
#include <stdlib.h>

void startgrid(int numofRows,int numofColumns,int A[numofRows][numofColumns] )
{
    int i,j;
    for(i=0;i<numofRows;i++){
        for(j=0;j<numofColumns;j++){
           A[i][j]='x';
        }

    }

}


void printgrid(int numofRows,int numofColumns,int A[numofRows][numofColumns])
{
    int i,j;
    printf("      ");
    for(j=1 ; j<numofColumns+1 ; j++)
    {
        printf("%2d) ",j);
    }
    printf("\n\n\n");
     for(i=0;i<numofRows;i++){
            printf("%2d)    ",i+1);
        for(j=0;j<numofColumns;j++){
            printf("%c   ",A[i][j]);
        }
         printf("\n\n\n");
    }
}
