#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn='X';
int row,column,k,draw=0;
void display_board()
{
system("cls");
printf("\n\t\t\tTIC TAC TOE GAME\t\t\t\t\t\t\t\tPress ESC key to exit");
printf("\n\n\t\tPlayer1 [X]\t\t     |     |     \n");
printf("\t\tPlayer2 [O]\t\t  %c  |  %c  |  %c  \n",board[0][0],board[0][1],board[0][2]);
printf("\t\t\t\t\t_____|_____|_____\n");
printf("\t\t\t\t\t     |     |     \n");
printf("\t\t\t\t\t  %c  |  %c  |  %c  \n",board[1][0],board[1][1],board[1][2]);
printf("\t\t\t\t\t_____|_____|_____\n");
printf("\t\t\t\t\t     |     |     \n");
printf("\t\t\t\t\t  %c  |  %c  |  %c  \n",board[2][0],board[2][1],board[2][2]);
printf("\t\t\t\t\t     |     |     \n\n");
}
void intro()
{
printf("\n\n\n\n\t&&        && &&&&&&& &&       &&&&&  &&&&&   &&     && &&&&&&&\n");
printf("\t&&        && &&      &&      &&     &&   &&  &&&   &&& &&\n");
printf("\t&&   &&   && &&___   &&     &&     &&     && &&&& &&&& &&___\n");
printf("\t&&   &&   && &&~~~   &&     &&     &&     && && &&& && &&~~~\n");
printf("\t&&   &&   && &&      &&      &&     &&   &&  &&     && &&\n");
printf("\t &&&&&&&&&&  &&&&&&& &&&&&&&  &&&&&  &&&&&   &&     && &&&&&&&\n");
printf("\n\n\t    &&&&& \t  TO THE TIC TAC TOE GAME\t   &&   &&\n\t   &&   &&\t THIS IS A MULTIPLAYER GAME\t     &&&  \n\t   &&   &&\tFIND YOUR MATE TO PLAY WITH\t     &&&  \n\t    &&&&&      AND MAKE WINSTREAKS WITH THEM\t   &&   &&");
}
void player_turn()
{
	int choice;
const char ESC=27;
char key=0;
if(turn=='X')
{
printf("\n\t\tPlayer1 [X] turn:");
scanf("%d",&choice);
key=getch();
if(key==ESC)
exit(0);
}
else if(turn=='O')
{
printf("\n\t\tPlayer2 [O] turn:");
scanf("%d",&choice);
key=getch();
if(key==ESC)
exit(0);
}
switch(choice)
{
case 1:row=0;column=0;break;
case 2:row=0;column=1;break;
case 3:row=0;column=2;break;
case 4:row=1;column=0;break;
case 5:row=1;column=1;break;
case 6:row=1;column=2;break;
case 7:row=2;column=0;break;
case 8:row=2;column=1;break;
case 9:row=2;column=2;break;
default:
printf("Invalid choice\n");
break;
}
if(turn=='X'&&board[row][column]!='X'&&board[row][column]!='O')
{
board[row][column]='X';
turn='O';
}
else if(turn=='O'&&board[row][column]!='X'&&board[row][column]!='O')
{
board[row][column]='O';
turn='X';
}
else
{printf("Box Already Filled!\nPlease Try Again!\n\n");
player_turn();
}display_board();
}
int gameover()
{
for(int i=0;i<3;i++)
if(board[i][0]==board[i][1]&&board[i][0]==board[i][2]||board[0][i]==board[1][i]&&board[0][i]==board[2][i])//straight check win
return 1;
else if(board[0][0]==board[1][1]&&board[0][0]==board[2][2]||board[0][2]==board[1][1]&&board[0][2]==board[2][0])//diagonal check win
return 1;
for(int i=0;i<3;i++)
for(int j=0;j<3;j++)
if(board[i][j]!='X'&&board[i][j]!='O')//if any of the box is not filled
return -1;
return 0;//draw
}
void endgame()
{
	printf("\n\n\t&&&&&&& &&   &&   &&&   &&&  &&  &&   &&  &&   &&  &&&&&  &&   &&");
    printf("\n\t  &&&   &&   &&  && &&  &&&& &&  &&  &&    &&&&&  &&   && &&   &&");
    printf("\n\t  &&&   &&&&&&& &&&&&&& && &&&&  &&&&&      &&&   &&   && &&   &&");
    printf("\n\t  &&&   &&   && &&   && &&  &&&  &&  &&     &&&   &&   && &&   &&");
    printf("\n\t  &&&   &&   && &&   && &&   &&  &&   &&    &&&    &&&&&   &&&&&\n\n\t\t\t!!FOR PLAYING OUR GAME!!");
}
int main()
{
system("cls");
printf("\n\n\t\tPASSWORD HINT :- 7-characters, name of developer\n\n\t\t\tENTER PASSWORD :- ");
char ch[10];
for(int i=0;i<7;i++)
{ch[i]=getch();
printf("*");}
if(strcmp(ch,"bhishek")==0)
{
intro();
const int ESC=27, Enter=13;
char key=0;
printf("\n\n\t\t\tPress Enter key to continue\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tPress ESC key to exit");
key=getch();
if(key==Enter)
{	
system("cls");
do{
display_board();
player_turn();
k=gameover();
}while(k==-1);
if(turn=='O'&& k==1)
printf("\n\t\t\tPlayer1 [X] Wins!! Congratulations\n");
else if(turn=='X'&& k==1)
printf("\n\t\t\tPlayer2 [O] Wins!! Congratulations\n");
else
printf("\n\t\t\tGame Draw!!\n");
endgame();
}
else if(key==ESC)
exit(0);
}
else
printf("\n\t\t\t\tSORRY! TRY AGAIN");
return 0;
}

