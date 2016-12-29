#include <stdio.h>
#include <stdlib.h>

void DistrubutionOfMines(int ifirst, int jfirst,int numofMines ,int numofRows, int numofColumns,int A[numofRows][numofColumns]){
int i,j;
if(ifirst<numofRows&&jfirst<numofColumns){

    int constant=0;
        time_t t;
        srand ((unsigned) time(&t));
        while( constant < numofMines )
        {
            i=rand() % numofRows;
            j=rand() % numofColumns;
            if(A[i][j]!=42&&((i!=ifirst)||(j!=jfirst)))
            {
                A[i][j]=42;
                constant++;
            }
        }

}


}
void IncreaseNumberAroundMineCell(int numofRows,int numofColumns, int A[numofRows][numofColumns])
{
int i,j;
 for(i=0; i<numofRows; i++)
        {
            for(j=0; j<numofColumns; j++)
            {
                if(A[i][j]==42)
                {
                    if ((A[i+1][j]!=42)&&(i!=numofRows-1))
                    {
                        A[i+1][j]+=1;
                    }
                    if ((A[i-1][j]!=42)&&(i!=0))
                    {
                        A[i-1][j]+=1;
                    }
                    if ((A[i][j+1]!=42)&&(j!=numofColumns-1))
                    {
                        A[i][j+1]+=1;
                    }
                    if ((A[i][j-1]!=42)&&(j!=0))
                    {
                        A[i][j-1]+=1;
                    }
                    if ((A[i+1][j+1]!=42)&&(i!=numofRows-1)&&(j!=numofColumns-1))
                    {
                        A[i+1][j+1]+=1;
                    }
                    if ((A[i-1][j-1]!=42)&&(i!=0)&&(j!=0))
                    {
                        A[i-1][j-1]+=1;
                    }
                    if (A[i+1][j-1]!=42&&(j!=0)&&(i!=numofRows-1))
                    {
                        A[i+1][j-1]+=1;
                    }
                    if ((A[i-1][j+1]!=42)&&(i!=0)&&(j!=numofColumns-1))
                    {
                        A[i-1][j+1]+=1;
                    }
                }
            }
        }

}

int count(char arrstr[265]){         /*function to count number of charachter in string*/
 int i=0,counter=0;
    while(arrstr[i]!='\0'){
        counter++;
        i++;
    }
    return counter;
}



