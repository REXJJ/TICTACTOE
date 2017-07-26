
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

  //int arr[3][3];

void gotoXY(int x, int y)
{
CursorPosition.X = x;
CursorPosition.Y = y;
SetConsoleCursorPosition(console,CursorPosition);
}

void display()
{
    gotoXY(35,0);//The end point is 79 and 20
    cout<<"Tic Tac Toe";
    char ph=196;
    char pv=179;
    gotoXY(35,5);
    cout<<ph<<ph<<ph<<pv<<ph<<ph<<ph<<pv<<ph<<ph<<ph;
    gotoXY(38,6);
    cout<<pv;
    gotoXY(42,6);
    cout<<pv;
    gotoXY(38,4);
    cout<<pv;
    gotoXY(42,4);
    cout<<pv;
    gotoXY(38,8);
    cout<<pv;
    gotoXY(42,8);
    cout<<pv;
    gotoXY(35,7);
    cout<<ph<<ph<<ph<<pv<<ph<<ph<<ph<<pv<<ph<<ph<<ph;
}

int check(int a[3][3])
{
int i,j,t1=0;
for(i=0;i<3;i++){
    for(j=0;j<3;j++){
   if(a[i][j]!=2)
   t1=t1+a[i][j];
   if(t1==3||t1==-3)
    return 1;
    }t1=0;}

    t1=0;
    for(i=0;i<3;i++){
    for(j=0;j<3;j++){
   if(a[j][i]!=2)
   t1=t1+a[j][i];
   if(t1==3||t1==-3)
    return 1;
    }t1=0;}
if(a[1][1]!=2){
    if(a[0][0]==a[1][1]&&a[1][1]==a[2][2])
        return 1;
    if(a[2][0]==a[1][1]&&a[0][2]==a[1][1])
        return 1;}

return 0;
}

void game()
{
    display();
    int arr[3][3],I=1,J=1,status=0;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        arr[i][j]=2;
    int i=0,ch,x=40,y=6;
    gotoXY(x,y);
    char c;
    int counter=0;
    while(counter<9)
    {
        ch=getch();
    if(ch==224)
    {ch=getch();
    if(ch==72)
        (y==4)?y=8,J=2:y=y-2,J=J-1;
    if(ch==77)
         (x==44)?x=36,I=0:x=x+4,I=I+1;
    if(ch==80)
        (y==8)?y=4,J=0:y=y+2,J=J+1;
    if(ch==75)
        (x==36)?x=44,I=2:x=x-4,I=I-1;

    gotoXY(x,y);
    }
    else
        {if(counter%2==0)
        {cout<<"X";arr[J][I]=1;}
        else
            {cout<<"O";arr[J][I]=-1;}
        gotoXY(x,y);
        counter++;
          }
    if(check(arr))
    {
        gotoXY(40,10);
        if(counter%2!=0)cout<<"X WINS";
            else cout<<"O WINS";
        status=1;
         break;
    }

    }//end of loop
if(!status)
{
    gotoXY(40,10);
    cout<<"DRAW";
    }

    }//end of function
 int checkwin(int a[3][3],int n)
{
int i,j,t1=0;
for(i=0;i<3;i++){
    for(j=0;j<3;j++){
   if(a[i][j]!=2)
   t1=t1+a[i][j];}
   if(t1==n)
    for(int k=0;k<3;k++)
        if(a[i][k]==2)
        return ((i+1)*10+k+1);
    t1=0;}

    t1=0;
    for(i=0;i<3;i++){
    for(j=0;j<3;j++){
   if(a[j][i]!=2)
   t1=t1+a[j][i];}
   if(t1==n)
    for(int k=0;k<3;k++)
        if(a[k][i]==2)
        return ((k+1)*10+i+1);
    t1=0;
    }

    if(a[0][0]+a[1][1]+a[2][2]==n+2)
        return ((a[0][0]==2)?11:(a[1][1]==2)?22:33);
    if(a[2][0]+a[1][1]+a[0][2]==n+2)
        return ((a[2][0]==2)?31:(a[1][1]==2)?22:13);

return 0;
}


int countfork(int a[3][3],int n)
{
int i,j,t1=0,t=0;
for(i=0;i<3;i++){
    for(j=0;j<3;j++){
   if(a[i][j]!=2)
   t1=t1+a[i][j];}
   if(t1==n)
    {t++;}
    t1=0;}

    t1=0;
    for(i=0;i<3;i++){
    for(j=0;j<3;j++){
   if(a[j][i]!=2)
   t1=t1+a[j][i];}
   if(t1==n)
        {t++;}

  t1=0;
    }
t1=0;
for(int i=0;i<3;i++)
    if(a[i][i]!=2)
        t1=t1+a[i][i];
    if(t1==n)
        t++;
    t1=0;
    for(int i=0;i<3;i++)
        for(j=0;j<3;j++)
        if(i+j==2)
            if(a[i][j]!=2)
        t1=t1+a[i][j];

        if(t1==n)
            t++;
if(t>1)
    return t;
return 0;
}

int checkfork(int a[3][3],int i,int j,int n)
{
    a[i][j]=n;
    if(countfork(a,2*n))
    {   a[i][j]=2;
        return 1;}
        a[i][j]=2;
    return 0;
}

int computerplay(int arr[3][3], int m)
{
    int n,x,st=1;
 (m==1)?n=2:n=-2;
     x=checkwin(arr,n);
     if(x)
       {return x;}
     x=checkwin(arr,-n);
     if(x)
        {return x;}

       int sum=0;
       for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        sum=sum+arr[i][j];

        if(sum==13)
        {if((arr[0][0]==1&&arr[2][2]==1)||(arr[0][2]==1&&arr[2][0]==1))
        if(arr[0][1]==2)
        return 12;}


           for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
            if(arr[i][j]==2)
            if(checkfork(arr,i,j,1))
                {return (10*(i+1)+j+1);}

                 for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
            if(arr[i][j]==2)
            if(checkfork(arr,i,j,-1))
        {return (10*(i+1)+j+1);}


        if(arr[1][1]==2)
        return 22;






     for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        if(arr[i][j]==2)
        return 10*(i+1)+j+1;
return 0;
}


void compgame(int m)
{
    display();
    int arr[3][3],I=0,J=0,status=0;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        arr[i][j]=2;
    int i=0,ch,x=36,y=4;
    gotoXY(x,y);
    char c;
    int counter=0;
    if(m==1)
    {
        cout<<"X";
        counter=counter+1;
        arr[0][0]=1;
        gotoXY(36,4);
    }
    while(counter<9)
    {
        if((counter%2==1&&m==1)||(counter%2==0&&m==2))
        ch=getch();
    if(ch==224)
    {ch=getch();
    if(ch==72)//up
        (I==0)?I=2:I=I-1;
    if(ch==77)//right
         (J==2)?J=0:J=J+1;
    if(ch==80)//down
        (I==2)?I=0:I=I+1;
    if(ch==75)//left
        (J==0)?J=2:J=J-1;
x=36+J*4;
y=4+I*2;
    gotoXY(x,y);
    }
    else
        {if(counter%2==0)
        {
            if(m==1){
            int z=computerplay(arr,m);
            I=z/10-1;
            J=z%10-1;
            x=36+J*4;
            y=4+I*2;
            }
            gotoXY(x,y);
            cout<<"X";arr[I][J]=1;}
        else
            {
            if(m==2){int z=computerplay(arr,m);
            I=z/10-1;
            J=z%10-1;
            //gotoXY(20,20);
            //cout<<I<<J<<z;
             x=36+J*4;
            y=4+I*2;
            }
                gotoXY(x,y);
                cout<<"O";arr[I][J]=-1;}
        gotoXY(x,y);
        counter++;
          }
    if(check(arr))
    {
        gotoXY(40,10);
        if(counter%2!=0)cout<<"X WINS";
            else cout<<"O WINS";
        status=1;
         break;
    }

    }//end of loop
if(!status)
{
    gotoXY(40,10);
    cout<<"DRAW";
    }
    /*gotoXY(40,15);
    for(int l=0;l<3;l++)
        for(int m=0;m<3;m++)
        cout<<arr[l][m];*/

    }//end of function

int main()
{
    int n,m,x,y,z;
    int ch=1;
    int num=175;
    char cha=num;
    gotoXY(35,0);//The end point is 79 and 20
    cout<<"Tic Tac Toe";
    gotoXY(35,5);
    cout<<"1.TWO PLAYERS";
    gotoXY(35,7);
    cout<<"2.vs COMPUTER";
    gotoXY(2,9);
    cout<<"Select any of the above by using arrow keys to navigate and enter to select";
    x=33;
    y=7;
    gotoXY(x,y);
    cout<<cha;
    gotoXY(x-1,y);
    while(1)
    {
        ch=getch();
        if(ch==13)
            break;
         if(ch==224)
    {ch=getch();
    if(ch==72)//up
        (y==5)?(y=7,z=5):(y=5,z=7);
    if(ch==80)//down
         (y==7)?(y=5,z=7):(y=7,z=5);}
         gotoXY(x,y);
         cout<<cha;
         gotoXY(x,z);
         cout<<" ";
         gotoXY(x,y);

    }
    (y==5)?n=1:n=2;
    if(n==1)
        {
        system("cls");
        game();
        gotoXY(0,20);}
    else
    {
        system("cls");
        gotoXY(35,0);//The end point is 79 and 20
    cout<<"Tic Tac Toe";
    gotoXY(35,5);
    cout<<"1.PLAY O";
    gotoXY(35,7);
    cout<<"2.PLAY X";
    gotoXY(35,9);
    cout<<"Select any of the above";
    gotoXY(0,15);
    x=33;
    y=7;
    gotoXY(x,y);
    cout<<cha;
    gotoXY(x-1,y);
    while(1)
    {
        ch=getch();
        if(ch==13)
            break;
         if(ch==224)
    {ch=getch();
    if(ch==72)//up
        (y==5)?(y=7,z=5):(y=5,z=7);
    if(ch==80)//down
         (y==7)?(y=5,z=7):(y=7,z=5);}
         gotoXY(x,y);
         cout<<cha;
         gotoXY(x,z);
         cout<<" ";
         gotoXY(x,y);

    }
    (y==5)?m=1:m=2;
    system("cls");
    //m=2;
    compgame(m);
    gotoXY(0,20);
    }
return 0;
}
