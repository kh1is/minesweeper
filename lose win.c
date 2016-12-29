#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>
#include <math.h>
#include <conio.h>

FILE *pointer;

typedef struct
{

char playername[100];
long long score;

}userinfo;

void lose(int numofRows,int numofColumns,int A[numofRows][numofColumns],int visited2[numofRows][numofColumns],
          int input1,int input2,int visited3[numofRows][numofColumns],time_t start,int move,
          int counterflags,int counterquestionmarks,int numofmines)
          {

int i,j;
printf("      ");                         /*print grid*/
    for(j=1 ; j<numofColumns+1 ; j++)
    {
        printf("%2d) ",j);
    }

    printf("\n\n\n");
for(i=0;i<numofRows;i++){
        printf("%2d)    ",i+1);

        for(j=0;j<numofColumns;j++){
                  if((((visited2[i][j])==1)||((visited2[i][j])==2))&&((visited3[i][j]==0)&&((A[i][j])!='*'))){
                    printf("%c   ",A[i][j]);
                  }
                  else if((visited3[i][j]==1)&&((A[i][j])!=42)){
                  printf("-   ");
                  }
                  else if(visited3[i][j]==1){
                    printf("F   ");
                  }
                  else if((i==input1)&&(j==input2)){
                    printf("!   ");
                  }
                  else if(A[i][j]==42){
                    printf("M   ");
                  }
                else{

                    printf("x   ");
                }
        }
        printf("\n\n\n");
        }
         printf("number of mines=%d\n",numofmines);
        printf("\n");
           time_t end = time(NULL);
    printf ("Elasped time is %d minutes and %d seconds.\n", (int)difftime(end,start)/60,(int)difftime(end,start)%60 );
    printf("\n");
     printf("Number of moves=%d\n",move);
      printf("\n");
     printf("Number of Flags=%d\n",counterflags);
      printf("\n");
    printf("Number of Question Marks=%d\n",counterquestionmarks);
     printf("\n");
         printf("Game Over!");

}
void win(int numofRows,int numofColumns,int A[numofRows][numofColumns],time_t start,
         int move,int counterflags,int counterquestionmarks,int numofmines)
         {

  int i,j;
  time_t difference;
  long long score;
  char name[100];        /*initialization string array name to take player's name*/

printf("      ");        /*print grid*/
    for(j=1 ; j<numofColumns+1 ; j++)
    {
        printf("%2d) ",j);
    }

    printf("\n\n\n");
  for(i=0;i<numofRows;i++){
         printf("%2d)    ",i+1);
    for(j=0;j<numofColumns;j++){
        if(A[i][j]==42){
            printf("F   ");
        }
        else{
            printf("%c   ",A[i][j]);
        }

    }
    printf("\n\n\n");
  }
   printf("number of mines=%d\n",numofmines);
        printf("\n");
  time_t end = time(NULL);
    printf ("Elasped time is %d minutes and %d seconds.\n", (int)difftime(end,start)/60,(int)difftime(end,start)%60 );
    printf("\n");
       printf("Number of moves=%d\n",move);
        printf("\n");
       printf("Number of Flags=%d\n",counterflags);
        printf("\n");
    printf("Number of Question Marks=%d\n",counterquestionmarks);
     printf("\n");
     difference=difftime(end,start);
     if(((int)difftime(end,start))==0){
        difference=1;
     }
     score=(int)((int)((pow(numofRows,4))*(pow(numofColumns,4)))/(((int)difference)*move));

     printf("your score:%lld",score);
     printf("\n\n");
   printf("Winner\n\n");

   printf("Enter your name: ");
   fflush(stdin);
   scanf("%s",name);
      system("cls");
      printf("\n\n\t\t\t\t\t\t\t\t(Minesweeper)\n\n\n\n\n");

   int counter=0,flag;
   /*initialization int flag using it to know if the player's name is exsited in leader board or not*/
      /*initialization int counter to put on in number of players in leader board*/

    printf("\n\n");
    userinfo halloffame[100];         /*initialization array halloffame of structures to put on in it player's names and their scores*/
    pointer= fopen("leaderboard","r");     /*read player's names and scores and number of players from file*/
   fscanf(pointer,"%d",&counter);
    for(j=0;j<counter;j++)
    {

        fscanf(pointer,"%s",halloffame[j].playername);
        fscanf(pointer,"%lld",&halloffame[j].score);
    }



    for(i=0;i<100;i++)          /*put player's name in uppercase*/
{
    name[i]=toupper(name[i]);
}
for(j=0;j<counter;j++){         /*determine if  the player's name is exsited in leader board or not*/
        flag=0;
for(i=0;i<count(name);i++){

    if(name[i]==halloffame[j].playername[i]){

        continue;
    }
    else {
        flag=1;
    }
}
    if(flag==0){            /*if player's name is existed i will add his current score to his old score*/
    if(count(name)==count(halloffame[j].playername)){
    halloffame[j].score+=score;
        break;
    }
     else {
        flag=1;
    }
    }
}
if((flag==1)||(counter==0)){          /*if player's name ia not existed i will add him to leader board*/
counter=counter+1;
        for(i=0;i<=count(name);i++){
    halloffame[counter-1].playername[i]= name[i];
        }
    halloffame[counter-1].score= score;
}



int max,tmp,k;             /*sorting the leader board*/
char maxname[100],tmpname[100];

for(i=0;i<counter;i++){
    max=halloffame[i].score;
       for(k=0;k<100;k++){
          maxname[k]=0;
    }
     for(k=0;k<count(halloffame[i].playername);k++){
        maxname[k]=halloffame[i].playername[k];
     }
    for(j=i+1;j<counter;j++){
        if(max<halloffame[j].score){
        tmp=max;
        for(k=0;k<100;k++){
           tmpname[k]=0;
       }
        for(k=0;k<count(maxname);k++){
        tmpname[k]=maxname[k];
     }
      max=halloffame[j].score;
      for(k=0;k<100;k++){
           maxname[k]=0;
        }
      for(k=0;k<count(halloffame[j].playername);k++){
        maxname[k]=halloffame[j].playername[k];
     }
            halloffame[j].score=tmp;
            for(k=0;k<100;k++){
             halloffame[j].playername[k]=0;
                  }
             for(k=0;k<count(tmpname);k++){
        halloffame[j].playername[k]=tmpname[k];
     }
        }
    }
    halloffame[i].score=max;
    for(k=0;k<100;k++){
    halloffame[i].playername[k]=0;
        }
    for(k=0;k<count(maxname);k++){
        halloffame[i].playername[k]=maxname[k];
     }
}
pointer= fopen("leaderboard","w");      /*write leader board in file*/
printf("\n");
fprintf(pointer,"%d\n",counter);
for(j=0;j<counter;j++)
{

fprintf(pointer,"%s",halloffame[j].playername);
fprintf(pointer,"\t\t\t");
fprintf(pointer,"%lld",halloffame[j].score);
fprintf(pointer,"\n");
}
/*print leader board*/
printf("(leader board)\n\n\n");
for(j=0;j<counter;j++){
    printf("%d)",j+1);
    printf("\t");
    printf("%s",halloffame[j].playername);
    printf("\t\t\t");
    printf("%lld",halloffame[j].score);
    printf("\n\n");
}

}
