#include <iostream>
#include <math.h>
using namespace std;

char info[5][5];
void read ()
{
    for (int i=1; i<=4; i++)
    {
        for (int j=1; j<=4; j++)
        cin>>info[i][j];
    }
}

int arr[25];
int coins[5][5];
int _1Dto2D ()
{
    int k=1;
    int count = 0;
    for (int i=1; i<=4; i++)
    {
        for (int j=1; j<=4; j++)
        {
            coins[i][j]=arr[k];
            if (arr[k]==1) count++;
            k++;
        }
    }
    return count;
}

char rs[5][5];
int x_xq[]={+1, +0, -1, +0};
int y_xq[]={+0, -1, +0, +1};
void flip ()
{
    for (int i=1; i<=4; i++)
    {
        for (int j=1; j<=4; j++)
        rs[i][j]=info[i][j];
    }
    for (int i=1; i<=4; i++)
    {
        for (int j=1; j<=4; j++)
        {
            if (coins[i][j]==1)
            {
                if (rs[i][j]=='b') rs[i][j]='w';
                else rs[i][j]='b';
                for (int k=0; k<4; k++)
                {
                    int X=j+x_xq[k];
                    int Y=i+y_xq[k];
                    if (X>=1 && X<=4 && Y>=1 && Y<=4)
                    {
                        if (rs[Y][X]=='b') rs[Y][X]='w';
                        else rs[Y][X]='b';
                    }
                }
            }
        }
    }
}

int check ()
{
    char init = rs[1][1];
    for (int i=1; i<=4; i++)
    {
        for (int j=1; j<=4; j++)
        {
            if (rs[i][j]!=init) return 0;
        }
    }
    return 1;
}

char tt[5][5];
int t2[5][5];

int Ans = 25;
void genBit (int u)
{
    if (u>16)
    {
        int x = _1Dto2D ();
       	flip ();
        if (check()==1) Ans = min (Ans, x);
    }
    else
    {
        arr[u]=0;
        genBit (u+1);
        arr[u]=1;
        genBit (u+1); 
    }
}

int main ()
{
    read ();
    genBit (1);
    if (Ans != 25) cout<<Ans;
    else cout<<-1;
    return 0;
}