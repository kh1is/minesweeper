#include <stdio.h>
#include <stdlib.h>

void recursion(int i, int j, int numofRows, int numofColumns, int A[numofRows][numofColumns])
{
    //we initialize A[i-1][j-1]=35 if A[i-1][j-1]=48 then enter the void recursion function
    if(A[i][j]!=48||i<0||j<0||i>numofRows-1||j>numofColumns-1)
    {
        return;
    }
    else
    {
        A[i][j]=0;

        recursion(i+1, j, numofRows, numofColumns, A);

        recursion( i-1,  j,  numofRows, numofColumns,  A);

        recursion( i,  j+1,  numofRows,  numofColumns,  A);

        recursion( i,  j-1,  numofRows,  numofColumns,  A);

        recursion(i+1, j+1, numofRows,  numofColumns,  A);

        recursion( i-1,  j-1,  numofRows,  numofColumns,  A);

        recursion( i+1,  j-1,  numofRows,  numofColumns,  A);

        recursion( i-1,  j+1,  numofRows,  numofColumns,  A);
    }
}


void specialdisplay(int numofRows,int numofColumns,int A[numofRows][numofColumns],int visited2[numofRows][numofColumns],
                    int input1,int input2,int visited3[numofRows][numofColumns],int input3){
                   int i,j,visited[numofRows][numofColumns];

     if(((A[input1][input2])==48)&&(input3==1)&&((visited3[input1][input2])==0))
    {
        recursion(input1,input2 , numofRows, numofColumns, A);
    }
/*initialization array visited to put on it cells which have numbers next to empty cells*/
          for(i=0;i<numofRows;i++){
        for(j=0;j<numofColumns;j++){
           visited[i][j]=0;
        }
        }
        for(i=0;i<numofRows;i++){
        for(j=0;j<numofColumns;j++){
           if(((A[input1][input2])==0)&&(input3==1)&&((visited3[input1][input2])==0)){
            if(A[i][j]==0){

             if((i!=numofRows-1)&&((A[i+1][j])!=0)&&(visited[i+1][j]==0)){
                    visited[i+1][j]=1;
            }
            if((i!=0)&&((A[i-1][j])!=0)&&(visited[i-1][j]==0)){
                  visited[i-1][j]=1;
           }

        if((j!=numofColumns-1)&&((A[i][j+1])!=0)&&(visited[i][j+1]==0)){
                   visited[i][j+1]=1;
        }
         if((j!=0)&&((A[i][j-1])!=0)&&(visited[i][j-1]==0)){
               visited[i][j-1]=1;
         }
         if((i!=numofRows-1)&&(j!=numofColumns-1)&&((A[i+1][j+1])!=0)&&(visited[i+1][j+1]==0)){
             visited[i+1][j+1]=1;
         }
           if((i!=0)&&(j!=0)&&((A[i-1][j-1])!=0)&&(visited[i-1][j-1]==0)){
        visited[i-1][j-1]=1;
           }
           if((j!=0)&&(i!=numofRows-1)&&((A[i+1][j-1])!=0)&&(visited[i+1][j-1]==0)){
        visited[i+1][j-1]=1;
           }
          if((i!=0)&&(j!=numofColumns-1)&&((A[i-1][j+1])!=0)&&(visited[i-1][j+1]==0)){
        visited[i-1][j+1]=1;
          }
            }
           }
        }
        }
        for(i=0;i<numofRows;i++){
        for(j=0;j<numofColumns;j++){
                  if((((i==input1)&&(j==input2))||((A[i][j])==0)||((visited[i][j])==1))&&((input3==1)&&((visited3[input1][input2])==0))&&(visited2[i][j]==0)){
                    visited2[i][j]=1;
                  }
        }
        }


}


