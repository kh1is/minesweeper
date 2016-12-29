#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

FILE *game;

void display(int numofRows,int numofColumns,int A[numofRows][numofColumns],int visited2[numofRows][numofColumns],
             int input1,int input2,int visited3[numofRows][numofColumns],int input3,int numofmines,
             time_t start,int move,int counterflags,int counterquestionmarks){

  /*initialization int choice1,choice2 to take row index ,column index from user*/

int i,j,visited[numofRows][numofColumns],choice1,choice2;
  /*initialization int length using it to take inputs from user*/
  /*initialization int choice3 to mark,unmark flags and questionmarks*/
   /*initialization int choice4 using to ask the user if he want to save game*/
     /*initialization int choice5 using to ask the user if he want to exit game*/
     /*initialization int counter using it to calculate number of flags around an opened cell*/
       /*initialization int counter2 using it to calculate number of closed cells to determine if the player win or not*/
         /*initialization int flag using it to determine if the player lose or win or not*/
int choice3,choice4,choice5,counter=48,flag=0,counter2=0,numofMines=0,length;
time_t end;
        for(i=0;i<numofRows;i++){       /*calculate number of mines*/
        for(j=0;j<numofColumns;j++){
             if(A[i][j]==42){
                numofMines++;
             }
        }
        }
        /*if user open empty cell then all empty cells next to it wiil be opened*/
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
        /*if user open cell has been opened and next to cell number of flags equel to it*/
        if(visited2[input1][input2]==2){
            if((A[input1][input2]!=42)&&(A[input1][input2]!=0)){
               if ((visited3[input1+1][input2]==1)&&(input1!=numofRows-1)){
                counter++;
               }
               if((visited3[input1-1][input2]==1)&&(input1!=0)){
                counter++;
               }
               if((visited3[input1][input2+1]==1)&&(input2!=numofColumns-1)){
                counter++;
               }
               if((visited3[input1][input2-1]==1)&&(input2!=0)){
                counter++;
               }
               if ((visited3[input1+1][input2+1]==1)&&(input1!=numofRows-1)&&(input2!=numofColumns-1)){
                counter++;
               }
               if((visited3[input1-1][input2-1]==1)&&(input1!=0)&&(input2!=0)){
                counter++;
               }
               if((visited3[input1-1][input2+1]==1)&&(input2!=numofColumns-1)&&(input1!=0)){
                counter++;
               }
               if((visited3[input1+1][input2-1]==1)&&(input2!=0)&&(input1!=numofRows-1)){
                counter++;
               }
            }
            if(A[input1][input2]==counter){
                if ((visited3[input1+1][input2]==0)&&(input1!=numofRows-1)){
                specialdisplay(numofRows,numofColumns,A,visited2,input1+1,input2,visited3,input3);
               }
               if((visited3[input1-1][input2]==0)&&(input1!=0)){
                specialdisplay(numofRows,numofColumns,A,visited2,input1-1,input2,visited3,input3);
               }
               if((visited3[input1][input2+1]==0)&&(input2!=numofColumns-1)){
                specialdisplay(numofRows,numofColumns,A,visited2,input1,input2+1,visited3,input3);
               }
               if((visited3[input1][input2-1]==0)&&(input2!=0)){
                specialdisplay(numofRows,numofColumns,A,visited2,input1,input2-1,visited3,input3);
               }
               if ((visited3[input1+1][input2+1]==0)&&(input1!=numofRows-1)&&(input2!=numofColumns-1)){
                specialdisplay(numofRows,numofColumns,A,visited2,input1+1,input2+1,visited3,input3);
               }
               if((visited3[input1-1][input2-1]==0)&&(input1!=0)&&(input2!=0)){
                specialdisplay(numofRows,numofColumns,A,visited2,input1-1,input2-1,visited3,input3);
               }
               if((visited3[input1-1][input2+1]==0)&&(input2!=numofColumns-1)&&(input1!=0)){
                specialdisplay(numofRows,numofColumns,A,visited2,input1-1,input2+1,visited3,input3);
               }
               if((visited3[input1+1][input2-1]==0)&&(input2!=0)&&(input1!=numofRows-1)){
                specialdisplay(numofRows,numofColumns,A,visited2,input1+1,input2-1,visited3,input3);
               }
            }
        }
        /*if user open mine flag=1 and he lose*/
        for(i=0;i<numofRows;i++){
        for(j=0;j<numofColumns;j++){
         if(visited2[i][j]==1){
            if(A[i][j]==42){
                flag=1;
            }
         }
          }
        }
        /*if user does not open any mine flag=2 and he win*/
        for(i=0;i<numofRows;i++){
        for(j=0;j<numofColumns;j++){
          if(visited2[i][j]==0){
            counter2++;
          }
         }
        }
        if(counter2==numofmines){
            flag=2;
        }
          if(flag==1){
            printf("\n\n");
            lose(numofRows,numofColumns,A,visited2,input1,input2,visited3,start,move,counterflags,counterquestionmarks,numofmines);
          }
          else if(flag==2){

            printf("\n\n");
            win(numofRows,numofColumns,A,start,move,counterflags,counterquestionmarks,numofmines);

          }
       else{                        /*print playing game*/
           printf("\n\n");
    printf("      ");
    for(j=1 ; j<numofColumns+1 ; j++)
    {
        printf("%2d) ",j);
    }

    printf("\n\n\n");
      for(i=0;i<numofRows;i++)
      {
            printf("%2d)    ",i+1);
        for(j=0;j<numofColumns;j++)
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
        end = time(NULL);
    printf ("Elasped time is %d minutes and %d seconds.\n", (int)difftime(end,start)/60,(int)difftime(end,start)%60 );
    printf("\n");
    printf("Number of moves=%d\n",move);
     printf("\n");
    printf("Number of Flags=%d\n",counterflags);
     printf("\n");
    printf("Number of Question Marks=%d\n",counterquestionmarks);
     printf("\n");
       }
       /*if flag=0 continue*/
       if(flag==0){
        char choice_4[40];     //for testcase
        printf("(1)save game \n");      /*ask the user if he want save game*/
        printf("(2)don't save game \n\n");
        time_t t;


        for(i=0;i<100000;i++){                     /*take input from user as string to verify that user's input is correct*/
         printf("Enter your choice: ");
         for(j=0;j<100;j++){                    /*if user didn't choose any thing for 60 seconds i will print time to warn him*/
    while (!_kbhit())
    {
        t = time(NULL);
        if(((int)difftime(t,start)-(int)difftime(end,start))/60!=0)
        {
            end = time(NULL);
            printf("\n");
            printf("Elasped time is %d minutes and %d seconds.\n", (int)difftime(t,start)/60,(int)difftime(t,start)%60);
            printf("\n");
            printf("Enter your choice: ");

            break;

        }
    }
        }
         gets(choice_4);
        length = strlen(choice_4);
          if(length==1)
        {
            if(isdigit(choice_4[0]))

            {
                sscanf(choice_4,"%d",&choice4);

                if(choice4==1||choice4==2)
                {
                    break;
                }

            }
        }
    printf("\n");
    }
printf("\n");
        if(choice4==1){               /*if user choose choice4 = 1 then the game will be saved*/

         game = fopen("savegame.txt","w");
         fprintf(game,"%d\n",numofRows);

         fprintf(game,"%d\n",numofColumns);

            for(i=0;i<numofRows;i++){
                for(j=0;j<numofColumns;j++)
                {
                    fprintf(game,"%d\t",A[i][j]);
                }
                fprintf(game,"\n");
            }
              for(i=0;i<numofRows;i++){
                for(j=0;j<numofColumns;j++)
                {
                    fprintf(game,"%d\t",visited2[i][j]);
                }
                fprintf(game,"\n");
            }
             for(i=0;i<numofRows;i++){
                for(j=0;j<numofColumns;j++)
                {
                    fprintf(game,"%d\t",visited3[i][j]);
                }
                fprintf(game,"\n");
            }
            fprintf(game,"%d\n", (int)difftime(end,start));
             fprintf(game,"%d\n",move);
              fprintf(game,"%d\n",counterflags);
               fprintf(game,"%d\n",counterquestionmarks);
               fprintf(game,"%d\n",numofMines);
            fclose(game);
    }

      char choice_5[40];        /*ask the user if he want exit game*/
        printf("(1)exit game \n");
        printf("(2)continue \n\n");



        for(i=0;i<100000;i++){              /*take input from user as string to verify that user's input is correct*/
        printf("Enter your choice: ");
         for(j=0;j<100;j++){                  /*if user didn't choose any thing for 60 seconds i will print time to warn him*/
    while (!_kbhit())
    {
        t = time(NULL);
        if(((int)difftime(t,start)-(int)difftime(end,start))/60!=0)
        {
            end = time(NULL);
            printf("\n");
            printf("Elasped time is %d minutes and %d seconds.\n", (int)difftime(t,start)/60,(int)difftime(t,start)%60);
            printf("\n");
            printf("Enter your choice: ");

            break;

        }
    }
        }
        gets(choice_5);
        length = strlen(choice_5);

        if(length==1)
        {
            if(isdigit(choice_5[0]))

            {
                sscanf(choice_5,"%d",&choice5);

                if(choice5==1||choice5==2)
                {
                    break;
                }

            }
        }
     printf("\n");
    }
     printf("\n");
if(choice5==2){                             /*if user choose choice5 = 1 he will exit game else if choice5=1 he will continue*/
    char choice_3[40],choice_1[40],choice_2[40];         /*for testcase*/
    printf("(1)open cell\n");              /*ask the user if he want open cell or mark,unmark cells with flags,questionmarks*/
    printf("(2)put/remove Flag on/from cell\n");
    printf("(3)put/remove question mark on/from cell\n\n");




    for(i=0;i<100000;i++){           /*take input from user as string to verify that user's input is correct*/
      printf("Enter your choice: ");
         for(j=0;j<100;j++){            /*if user didn't choose any thing for 60 seconds i will print time to warn him*/
    while (!_kbhit())
    {
        t = time(NULL);
        if(((int)difftime(t,start)-(int)difftime(end,start))/60!=0)
        {
            end = time(NULL);
            printf("\n");
            printf("Elasped time is %d minutes and %d seconds.\n", (int)difftime(t,start)/60,(int)difftime(t,start)%60);
            printf("\n");
            printf("Enter your choice: ");

            break;

        }
    }
        }
   gets(choice_3);
        length = strlen(choice_3);

        if(length==1)
        {
            if(isdigit(choice_3[0]))

            {
                sscanf(choice_3,"%d",&choice3);

                if(1<=choice3&&choice3<=3)
                {
                    break;
                }

            }
        }
    printf("\n");
    }
    printf("\n");

       /*take input from user*/

    for(i=0;i<100000;i++){       /*take input from user as string to verify that user's input is correct*/
     printf("Enter Row Index: ");
     for(j=0;j<100;j++){          /*if user didn't choose any thing for 60 seconds i will print time to warn him*/
    while (!_kbhit())
    {
        t = time(NULL);
        if(((int)difftime(t,start)-(int)difftime(end,start))/60!=0)
        {
            end = time(NULL);
            printf("\n");
            printf("Elasped time is %d minutes and %d seconds.\n", (int)difftime(t,start)/60,(int)difftime(t,start)%60);
            printf("\n");
             printf("Enter Row Index: ");

            break;

        }
    }
        }
      gets(choice_1);
      length = strlen(choice_1);

        if(length==1)
        {
            if(isdigit(choice_1[0]))

            {
                sscanf(choice_1,"%d",&choice1);

                if(1<=choice1&&choice1<=numofRows)
                {
                    break;
                }

            }
        }

        if(length==2)
        {
            if(isdigit(choice_1[0])&&isdigit(choice_1[1]))

            {
                sscanf(choice_1,"%d",&choice1);
                if(1<=choice1&&choice1<=numofRows)
                {
                    break;
                }


            }
        }
   printf("\n");
   }
     printf("\n");


     for(i=0;i<100000;i++){        /*take input from user as string to verify that user's input is correct*/
 printf("Enter Column Index: ");
      for(j=0;j<100;j++){          /*if user didn't choose any thing for 60 seconds i will print time to warn him*/
    while (!_kbhit())
    {
        t = time(NULL);
        if(((int)difftime(t,start)-(int)difftime(end,start))/60!=0)
        {
            end = time(NULL);
            printf("\n");
            printf("Elasped time is %d minutes and %d seconds.\n", (int)difftime(t,start)/60,(int)difftime(t,start)%60);
            printf("\n");
            printf("Enter Column Index: ");

            break;

        }
    }
        }
    gets(choice_2);
        length = strlen(choice_2);
       if(length==1)
        {
            if(isdigit(choice_2[0]))
           {
                sscanf(choice_2,"%d",&choice2);

                if(1<=choice2&&choice2<=numofColumns)
                {
                    break;
                }

            }
        }

        if(length==2)
        {
            if(isdigit(choice_2[0])&&isdigit(choice_2[1]))

            {
                sscanf(choice_2,"%d",&choice2);
                if(1<=choice2&&choice2<=numofColumns)
                {
                    break;
                }


            }
        }
    printf("\n");
    }
    printf("\n");
       system("cls");
      printf("\n\n\t\t\t\t\t\t\t\t(Minesweeper)\n\n\n");

    /*to calculate number of moves*/
    move=move+1;
    int counterflags=0,counterquestionmarks=0;
    /*mark and unmark flags*/
        if(choice3==2){
            if(visited3[choice1-1][choice2-1]==0){
                visited3[choice1-1][choice2-1]=1;
            }
             else if(visited3[choice1-1][choice2-1]==1){
             visited3[choice1-1][choice2-1]=0;
             }
            }
             /*mark and unmark question marks*/
        if(choice3==3){
            if(visited3[choice1-1][choice2-1]==0){
                visited3[choice1-1][choice2-1]=2;
            }
             else if(visited3[choice1-1][choice2-1]==2) {
             visited3[choice1-1][choice2-1]=0;
             }
            }
            /*if user open an opened cell visited2[i][j]=2*/
           if(choice3==1){
            if(visited2[choice1-1][choice2-1]==1){
                visited2[choice1-1][choice2-1]=2;
            }
           }
           /*calculate number of flags and question marks*/
            for(i=0;i<numofRows;i++){
        for(j=0;j<numofColumns;j++){
        if(visited3[i][j]==1){
            counterflags++;
        }
        if(visited3[i][j]==2){
            counterquestionmarks++;
        }

        }
            }

        if(((A[choice1-1][choice2-1])==42)&&((choice3==1)&&(visited3[choice1-1][choice2-1]==0))){
            printf("\n\n");
           lose(numofRows,numofColumns,A,visited2,choice1-1,choice2-1,visited3,start,move,counterflags,counterquestionmarks,numofMines);
        }
        else{
             display(numofRows,numofColumns,A,visited2,choice1-1,choice2-1,visited3,choice3,numofMines,start,move,
                     counterflags,counterquestionmarks);
     printf("\n\n");
        }
       }
       }
}
