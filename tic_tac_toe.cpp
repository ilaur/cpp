//Chapter 10_5
/*Make your tic-tac-toe game into a version of connect-4 that allow boards bigger than 3 by 3 but
requires 4-in-a-row to win. Allow the players to specify the size of the board while the program
is running. (Hint: right now, you have to define your board to be a fixed size at compile time, so
you may need to limit the maximum size of the board.)*/

#include <iostream>
#include <cstdlib>

using namespace std;

void Tic_Tac_Toe();
void Game(int size);
void Set_Board(char a[][1001],int size,char mark=' ');
void Display_Board(char a[][1001],int size);
void Set_Mark(char a[][1001],int size,int turn);
void Rules();
void Dispaly_Winner(char a[][1001],int row,int column);
bool Checker(char a[][1001],int size,int turn);
int Main_Menu();
int Secondary_Menu();

int main(int argc,char* argv[])
{
    Tic_Tac_Toe();
    return 0;
}

void Rules()
{
    system("CLS");
    cout<<"\n\n          \"Tic-Tac-Toe\" connect-4 Rules\n\n";
    cout<<"Boards 4x4 or higher connect 4 marks in a row,column or diagonal\n";
    cout<<"Input values for rows and columns higher than 0 and lower than given size\n\n";
    system("PAUSE");
}

void Set_Mark(char a[][1001],int size,int turn)
{
    if(turn%2!=0)
    {
        cout<<"\nPlayer 1 put X\n\n";
        cout<<"\nRow: ";
        int i=0;cin>>i;
        if(i<1 || i>size)
        {
            cout<<"\nNo such row\n\n";
            return Set_Mark(a,size,turn);
        }
        cout<<"\nColumn: ";
        int j=0;cin>>j;
        if(j<1 || j>size)
        {
            cout<<"\nNo such column\n\n";
            return Set_Mark(a,size,turn);
        }
        if(a[i][j]!='?')
        {
            cout<<"\nPosition already marked\n\n";
            return Set_Mark(a,size,turn);
        }
        a[i][j]='X';
    }
    else
    {
        cout<<"\nPlayer 2 put O\n\n";
        cout<<"\nRow: ";
        int i=0;cin>>i;
        if(i<1 || i>size)
        {
            cout<<"\nNo such row\n\n";
            return Set_Mark(a,size,turn);
        }
        cout<<"\nColumn: ";
        int j=0;cin>>j;
        if(j<1 || j>size)
        {
            cout<<"\nNo such column\n\n";
            return Set_Mark(a,size,turn);
        }
        if(a[i][j]!='?')
        {
            cout<<"\nPosition already marked\n\n";
            return Set_Mark(a,size,turn);
        }
        a[i][j]='O';
    }
    Display_Board(a,size);
}

void Dispaly_Winner(int turn)
{
    if(turn%2!=0)
    {
        cout<<"\n\nPlayer 1 wins\n\n";
        system("PAUSE");
    }
    else
    {
        cout<<"\n\nPlayer 2 wins\n\n";
        system("PAUSE");
    }
}

void Set_Board(char a[][1001],int size,char mark)
{
    for(int i=1;i<=size;i++)
    {
        for(int j=1;j<=size;j++)
        {
            a[i][j]=mark;
        }
    }
}

void Tic_Tac_Toe()
{
    int option=Main_Menu();
    while(option!=3)
    {
        switch(option)
        {
        case 1 :
            Game(Secondary_Menu());
            break;
        case 2 :
            Rules();
            break;
        }
        option=Main_Menu();
    }
}

void Game(int size)
{
    char board[1001][1001];
    Set_Board(board,size,'?');
    Display_Board(board,size);
    int turns=size*size;
    for(int i=1;i<=turns;i++)
    {
        Set_Mark(board,size,i);
        if(Checker(board,size,i))
        {
            return;
        }
    }
    system("PAUSE");
}

bool Checker(char a[][1001],int size,int turn)
{
    for(int j=1;j<=size;j++)
    {
        for(int i=1;i<=size;i++)
        {
            int aux=i;
            if(a[i][j]==a[++i][j]&&a[i][j]==a[++i][j]&&a[i][j]==a[++i][j]&&a[i][j]!='?')
            {
                Dispaly_Winner(turn);
                return true;
            } //rows
            i=aux;
            aux=i;
            if(a[j][i]==a[j][++i]&&a[j][i]==a[j][++i]&&a[j][i]==a[j][++i]&&a[j][i]!='?')
            {
                Dispaly_Winner(turn);
                return true;
            } //columns
            i=aux;
        }
    }
    for(int i=1;i<=size;i++)
    {
        int curr_i=i;
        for(int j=1;j<=size;j++)
        {
            int curr_j=j;
            if(a[i][j]!='?')
            {
                if(a[i][j]==a[++i][++j]&&a[i][j]==a[++i][++j]&&a[i][j]==a[++i][++j])
                {
                    Dispaly_Winner(turn);
                    return true;
                }
            j=curr_j;
            }
        i=curr_i;
        }
    } //west_to_east diagonals
    for(int i=1;i<=size;i++)
    {
        int curr_i=i;
        for(int j=size;j>=1;j--)
        {
            int curr_j=j;
            if(a[i][j]!='?')
            {
                if(a[i][j]==a[++i][--j]&&a[i][j]==a[++i][--j]&&a[i][j]==a[++i][--j])
                {
                    Dispaly_Winner(turn);
                    return true;
                }
            }
            j=curr_j;
        }
        i=curr_i;
    } //east_to_vest diagonals
    return false;
}

void Display_Board(char a[][1001],int size)
{
    system("CLS");
    cout<<"\n                            \"Tic-Tac-Toe\"\n\n";
    int n=1;
    for(int i=1;i<=size;i++)
    {
        if(i==1)
        {
            cout<<"\t ";
            for(int m=1;m<=size;m++)
            {
                cout<<"\t"<<m;
            }
            cout<<"\n\n";
        }
        for(int j=1;j<=size;j++)
        {
            if(j==1)
            {
                cout<<"\t"<<n;
                n++;
            }
            cout<<"\t"<<a[i][j];
        }
        cout<<"\n\n";
    }
    cout<<"\n\n";
}

int Secondary_Menu()
{
    system("CLS");
    cout<<"\n\n     \"Tic-Tac-Toe\"\n\n";
    cout<<"     Size interval [4,1000]\n";
    cout<<"     Please input board size: ";
    int size=0;
    cin>>size;
    if(size<4||size>1000)
    {
        cout<<"\n     Invalid board size\n\n";
        system("PAUSE");
        return Secondary_Menu();
    }
    return size;
}

int Main_Menu()
{
    system("CLS");
    cout<<"\n\n     Welcome to \"Tic-Tac-Toe\" v1.5 \n\n";
    cout<<"     1.Start game\n";
    cout<<"     2.Rules\n";
    cout<<"     3.Quit game\n\n";
    cout<<"     Select option: ";
    int option=0;
    cin>>option;
    if(option>3||option<1)
    {
        cout<<"\n     Invalid option\n\n";
        system("PAUSE");
        return Main_Menu();
    }
    return option;
}
