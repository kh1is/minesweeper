#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>
#include <math.h>
#include <conio.h>
#include "project.h"

FILE *game;        /*initialization pointer game using it in save/load game in/from file*/
FILE *pointer;     /*initialization pointer pointer using it in save/load player's names and their scores in/from file*/


typedef struct     /*initialization struct userinfo to put player's names and their scores on it*/
{

char playername[100];
long long score;

}userinfo;


int main()
{

    printf("\n\n\t\t\t\t\t\t\t\t(Minesweeper)\n\n\n\n\n");
    printf("MAIN MENU\n\n\n");
    printf("(1) start game\n\n");
    printf("(2) load game\n\n");
    printf("(3) show players ordered with their score\n\n");
    int length,numofMain,i,j,numofRows,numofColumns,ifirst,jfirst,choice3first,counterflags=0,counterquestionmarks=0;
    /*initialization int length using it to take inputs from user*/
    char numof_Main[40],numof_Columns[40],numof_Rows[40],ifirst2[40],jfirst2[40],choice3_first[40];      //for testcases
     time_t start,end;
    start = time(NULL);

    for(i=0;i<100000;i++){             /*take input from user as string to verify that user's input is correct*/
    printf("Enter your choice: ");
       gets(numof_Main);
        length = strlen(numof_Main);
          if(length==1)
        {
          if(isdigit(numof_Main[0]))
              {
                sscanf(numof_Main,"%d",&numofMain);

                  if(1<=numofMain&&numofMain<=3)
                {
                    break;
                }
                }
        }
        printf("\n");
         }
     system("cls");
      printf("\n\n\t\t\t\t\t\t\t\t(Minesweeper)\n\n\n\n\n");

    if (numofMain==1)            /*if user choose numofMain = 1 then he will start new game*/
    {

    /*take dimensions from user*/
    for(i=0;i<100000;i++){                    /*take input from user as string to verify that user's input is correct*/
     printf("Enter Number of Rows: ");
      gets(numof_Rows);
        length = strlen(numof_Rows);
         if(length==1){
          if(isdigit(numof_Rows[0])){
                sscanf(numof_Rows,"%d",&numofRows);
                   if(2<=numofRows&&numofRows<=9)
                {
                    break;
                }
                }
        }
          if(length==2){
            if(isdigit(numof_Rows[0])&&isdigit(numof_Rows[1]))
               {
                sscanf(numof_Rows,"%d",&numofRows);
                if(2<=numofRows&&numofRows<=30)
                {
                    break;
                }
                   }
        }
       printf("\n");
    }
    printf("\n");
     for(i=0;i<100000;i++){             /*take input from user as string to verify that user's input is correct*/
    printf("Enter Number of Columns: ");
      gets(numof_Columns);
        length = strlen(numof_Columns);
         if(length==1){
          if(isdigit(numof_Columns[0])){
                sscanf(numof_Columns,"%d",&numofColumns);
                   if(2<=numofColumns&&numofColumns<=9){
                    break;
                }
                }
        }
          if(length==2){
            if(isdigit(numof_Columns[0])&&isdigit(numof_Columns[1])){
                sscanf(numof_Columns,"%d",&numofColumns);
                if(2<=numofColumns&&numofColumns<=30){
                    break;
                }
             }
        }
       printf("\n");
    }
     system("cls");
      printf("\n\n\t\t\t\t\t\t\t\t(Minesweeper)\n\n\n\n\n");

    int A[numofRows][numofColumns];       /*initialization array A as grid of the game*/

        startgrid(numofRows,numofColumns,A);          /*start game*/
         printgrid(numofRows,numofColumns,A);          /*print start grid*/
         printf("\n");

        int numofMines=1+(numofRows*numofColumns)/10;         /*calculate number of mines*/
        printf("number of mines=%d\n",numofMines);
        printf("\n\n");


         printf("(1)open cell\n");                            /*take first input*/
         printf("(2)put/remove Flag on/from cell\n");
         printf("(3)put/remove question mark on/from cell\n\n");
        for(i=0;i<100000;i++){                /*take input from user as string to verify that user's input is correct*/
         printf("Enter your choice: ");
         gets(choice3_first);
        length = strlen(choice3_first);
        if(length==1){
            if(isdigit(choice3_first[0])){
                sscanf(choice3_first,"%d",&choice3first);

                 if(1<=choice3first&&choice3first<=3){
                    break;
                }
              }
        }
       printf("\n");
         }
         printf("\n");
    for(i=0;i<100000;i++){                 /*take input from user as string to verify that user's input is correct*/
        printf("Enter Row Index: ");
        gets(ifirst2);
        length = strlen(ifirst2);

      if(length==1)
        {
            if(isdigit(ifirst2[0]))

            {
                sscanf(ifirst2,"%d",&ifirst);

                if(1<=ifirst&&ifirst<=numofRows)
                {
                    break;
                }

            }
        }

        if(length==2)
        {
            if(isdigit(ifirst2[0])&&isdigit(ifirst2[1]))

            {
                sscanf(ifirst2,"%d",&ifirst);
                if(1<=ifirst&&ifirst<=numofRows)
                {
                    break;
                }


            }
        }
       printf("\n");
         }
          printf("\n");
         for(i=0;i<100000;i++){                   /*take input from user as string to verify that user's input is correct*/
         printf("Enter Column Index: ");
         gets(jfirst2);
        length = strlen(jfirst2);
        if(length==1)
        {
            if(isdigit(jfirst2[0]))

            {
                sscanf(jfirst2,"%d",&jfirst);

                if(1<=jfirst&&jfirst<=numofColumns)
                {
                    break;
                }

            }
        }

        if(length==2){
            if(isdigit(jfirst2[0])&&isdigit(jfirst2[1])){
                sscanf(jfirst2,"%d",&jfirst);
                if(1<=jfirst&&jfirst<=numofColumns){
                    break;
                }
              }
        }
       printf("\n");
         }
          printf("\n");
          system("cls");
      printf("\n\n\t\t\t\t\t\t\t\t(Minesweeper)");

         int move=1;                                  /*initialization int move*/
         start = time(NULL);

        DistrubutionOfMines(ifirst-1,jfirst-1,numofMines,numofRows,numofColumns,A);        /*distribute mines in grid*/




        for(i=0; i<numofRows; i++)               /*calculate numbers next to mines*/
        {
            for(j=0; j<numofColumns; j++)
            {
                if(A[i][j]!=42)
                {
                    A[i][j]=48;
                }
            }
        }

        printf("\n");
        IncreaseNumberAroundMineCell(numofRows,numofColumns,A);


        FILE *f1;                      /*initialization pointer f1 using it to save solved grid for debug*/
        f1 = fopen("savegrid.txt","w");
       for(i=0;i<numofRows;i++){
        for(j=0;j<numofColumns;j++){
        fprintf(f1,"%c  ",A[i][j]);

        }
        fprintf(f1,"\n");
       }

         fclose(f1);



        printf("\n");

        printf("\n\n");

         /*initialization array visited2 put on it cells that have been opened then print it*/

        int visited2[numofRows][numofColumns];
         for(i=0;i<numofRows;i++){
        for(j=0;j<numofColumns;j++){
           visited2[i][j]=0;
        }
        }

        /*initialization array visited3 put on it cells that have been put on it flags and question marks*/

         int visited3[numofRows][numofColumns];
         for(i=0;i<numofRows;i++){
        for(j=0;j<numofColumns;j++){
                if((i==ifirst-1)&&(j==jfirst-1)&&(choice3first==2)){
                    visited3[i][j]=1;
                    counterflags=1;
                }
                else if((i==ifirst-1)&&(j==jfirst-1)&&(choice3first==3)){
                     visited3[i][j]=2;
                     counterquestionmarks=1;
                }
                else{
           visited3[i][j]=0;

        }
        }
}
    display(numofRows,numofColumns,A,visited2,ifirst-1,jfirst-1,visited3,choice3first,numofMines,
            start,move,counterflags,counterquestionmarks);

     printf("\n\n");

    }
   else if(numofMain==2){               /*if user choose numofMain = 2 then he will load game*/

game=fopen("savegame.txt","r");             /*read game from file*/

int n,m,moves,flags,questionmarks,numofmines;
time_t difference;
fscanf(game,"%d",&n);                    /*read number of rows*/
fscanf(game,"%d",&m);                     /*read number of columns*/
   /*initialization array A to put solved grid on it*/
   /*initialization array visited2 put on it array has been saved that contains cells that have been opened then print it*/
    /*initialization array visited3 put on it array has been saved that contains cells that have been put on it flags and question marks*/
int A[n][m],visited2[n][m],visited3[n][m];

               for(i=0;i<n;i++){
                for(j=0;j<m;j++)
                {
                    fscanf(game,"%d",&A[i][j]);
                }

            }
              for(i=0;i<n;i++){
                for(j=0;j<m;j++)
                {
                    fscanf(game,"%d",&visited2[i][j]);
                }

            }
             for(i=0;i<n;i++){
                for(j=0;j<m;j++)
                {
                    fscanf(game,"%d",&visited3[i][j]);
                }

            }
              fscanf(game,"%d", &difference);
             fscanf(game,"%d",&moves);
              fscanf(game,"%d",&flags);
               fscanf(game,"%d",&questionmarks);
               fscanf(game,"%d",&numofmines);

      printf("      ");          /*print game*/
    for(j=1 ; j<m+1 ; j++)
    {
        printf("%2d) ",j);
    }

    printf("\n\n\n");
      for(i=0;i<n;i++)
      {
            printf("%2d)    ",i+1);
        for(j=0;j<m;j++)
        {
        if((((visited2[i][j])==1)||((visited2[i][j])==2))&&((visited3[i][j])==0)){
        printf("%c   ",A[i][j]);
        }
        else if(visited3[i][j]==1){
          printf("F   ");
        }
        else if(visited3[i][j]==2){
            printf("?   ");
            }

                else{

                    printf("x   ");
                }
        }
        printf("\n\n\n");
        }
         printf("number of mines=%d\n",numofmines);
        printf("\n");

    printf ("Elasped time is %d minutes and %d seconds.\n",(int) difference/60,(int)difference%60 );
    printf("\n");
    printf("Number of moves=%d\n",moves);
     printf("\n");
    printf("Number of Flags=%d\n",flags);
     printf("\n");
    printf("Number of Question Marks=%d\n",questionmarks);
     printf("\n");

         printf("(1)open cell\n");             /*take input*/
         printf("(2)put/remove Flag on/from cell\n");
         printf("(3)put/remove question mark on/from cell\n\n");
         for(i=0;i<100000;i++){                    /*take input from user as string to verify that user's input is correct*/
         printf("Enter your choice: ");
         gets(choice3_first);
        length = strlen(choice3_first);
        if(length==1){
            if(isdigit(choice3_first[0])){
                sscanf(choice3_first,"%d",&choice3first);

                 if(1<=choice3first&&choice3first<=3){
                    break;
                }
              }
        }
       printf("\n");
         }
     printf("\n");
       for(i=0;i<100000;i++){                 /*take input from user as string to verify that user's input is correct*/
         printf("Enter Row Index: ");
         gets(ifirst2);
        length = strlen(ifirst2);

      if(length==1)
        {
            if(isdigit(ifirst2[0]))

            {
                sscanf(ifirst2,"%d",&ifirst);

                if(1<=ifirst&&ifirst<=numofRows)
                {
                    break;
                }

            }
        }

        if(length==2)
        {
            if(isdigit(ifirst2[0])&&isdigit(ifirst2[1]))

            {
                sscanf(ifirst2,"%d",&ifirst);
                if(1<=ifirst&&ifirst<=numofRows)
                {
                    break;
                }


            }
        }
       printf("\n");
         }
         printf("\n");
         for(i=0;i<100000;i++){                      /*take input from user as string to verify that user's input is correct*/
         printf("Enter Column Index: ");
         gets(jfirst2);
        length = strlen(jfirst2);
        if(length==1)
        {
            if(isdigit(jfirst2[0]))

            {
                sscanf(jfirst2,"%d",&jfirst);

                if(1<=jfirst&&jfirst<=numofColumns)
                {
                    break;
                }

            }
        }

        if(length==2){
            if(isdigit(jfirst2[0])&&isdigit(jfirst2[1])){
                sscanf(jfirst2,"%d",&jfirst);
                if(1<=jfirst&&jfirst<=numofColumns){
                    break;
                }
              }
        }
       printf("\n");
         }
          printf("\n");
          system("cls");
      printf("\n\n\t\t\t\t\t\t\t\t(Minesweeper)\n\n\n\n\n");

     if(choice3first==2){
            if(visited3[ifirst-1][jfirst-1]==0){
                visited3[ifirst-1][jfirst-1]=1;
                flags=flags+1;
            }
             else if(visited3[ifirst-1][jfirst-1]==1){
             visited3[ifirst-1][jfirst-1]=0;
             flags=flags-1;
             }
            }
                                               /*mark and unmark question marks*/
        if(choice3first==3){
            if(visited3[ifirst-1][jfirst-1]==0){
                visited3[ifirst-1][jfirst-1]=2;
                questionmarks=questionmarks+1;
            }
             else if( visited3[ifirst-1][jfirst-1]==2) {
             visited3[ifirst-1][jfirst-1]=0;
             questionmarks=questionmarks-1;
             }
            }
                                           /*if user open an opened cell visited2[i][j]=2*/
           if(choice3first==1){
            if(visited2[ifirst-1][jfirst-1]==1){
                visited2[ifirst-1][jfirst-1]=2;
            }
           }




   start=start-difference;

     display(n,m,A,visited2,ifirst-1,jfirst-1,visited3,choice3first,numofmines,
            start,(moves+1),flags,questionmarks);
    fclose(game);

    }
    else if(numofMain==3){                  /*if user choose numofMain = 3 then he will load leader board*/

        int counter=0;                /*initialization int counter to put on in number of players in leader board*/

        userinfo halloffame[100];          /*initialization array halloffame of structures to put on in it player's names and their scores*/

         pointer= fopen("leaderboard","r");    /*read player's names and scores and number of players from file*/
   fscanf(pointer,"%d",&counter);
    for(j=0;j<counter;j++)
    {

        fscanf(pointer,"%s",halloffame[j].playername);
        fscanf(pointer,"%lld",&halloffame[j].score);
    }
    printf("(leader board)\n\n\n");

for(j=0;j<counter;j++){         /*print leader board*/
    printf("%d)",j+1);
    printf("\t");
    printf("%s",halloffame[j].playername);
    printf("\t\t\t");
    printf("%lld",halloffame[j].score);
    printf("\n\n");
}


    }
    return 0;
}
