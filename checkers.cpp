/*Make a two-player checkers program that allows each player to make a move, and checks for
legal moves and whether the game is over. Be sure to support kinging! Feel free to add support
for any house rules that you use when you play. Consider making the kind of rules used an
option at program startup.*/

#include <iostream>
#include <cstdlib>

using namespace std;

int SetMode();
bool CheckForJumps(char[][9],int pos[],int turn);
bool CheckMove(char a[][9],int row,int column,int newrow,int newcolumn,int turn);
bool CheckBoard(char a[][9],int turn,int pos[],int aux_turn[],int mode=0);
bool CheckJumpMoves(char a[][9],int turn,int row,int column);
void KingVQeen();
void KVQ_setPieces(char a[][9]);
void Kinging(char a[][9]);
void PieceJump(char a[][9],int turn,int row,int column);
void Checkers();
void Display_Main_Menu();
void Game(int mode);
void Standard_Game(int mode);
void Display_Board(char a[][9],string mode="Standard");
void SetPieces(char a[][9]);
void SetBoard(char a[][9],char mark='_');
void SelectPiece(char a[][9],int turn,int pos[]);
void MovePiece(char a[][9],int row,int column,int turn);
void Rules();

int main(int argc,char* argv[])
{
    Checkers();
    return 0;
}

int SetMode()
{
    system("CLS");
    cout<<"\n         \"Checkers\" Set Mode\n\n";
    cout<<"    1.Standard Checkers:Play a standard checkers game\n";
    cout<<"    2.House Rule:50 move without a capture or kinging\n";
    cout<<"        One player must make a capture in 50 moves or the other else it is a draw\n";
    cout<<"    3.House Rule:Anti-Checkers\n";
    cout<<"        You win if you are the first to lose all your pieces or to have no legal moves.\n";
    cout<<"    4.House Rule:Kings vs Queens\n        8 pieces for each player capture all the enemy pieces\n";
    cout<<"    \nSelect mode: ";
    int mode=0;cin>>mode;
    return mode;
}

bool CheckForJumps(char a[][9],int pos[],int turn)
{
    bool switcher=false;
    if(turn%2!=0)
    {
        for(int i=1;i<9;i++)
        {
            int aux_i=i;
            for(int j=1;j<9;j++)
            {
                int aux_j=j;
                if((a[i][j]=='B'||a[i][j]=='K')&&(a[--i][--j]=='W'||a[i][j]=='Q')&&a[--i][--j]=='_')
                {
                    i+=2;
                    j+=2;
                    for(int k=0;k<8;k++)
                    {
                        if(pos[k]==0)
                        {
                            pos[k++]=i;
                            pos[k]=j;
                            break;
                        }
                    }
                    switcher=true;
                }
                i=aux_i;
                j=aux_j;
                if(a[i][j]=='K'&&((a[++i][++j]=='W'||a[i][j]=='Q')&&a[++i][++j]=='_'))
                {
                    i=aux_i;
                    j=aux_j;
                    for(int k=0;k<8;k++)
                    {
                        if(pos[k]==0)
                        {
                            pos[k++]=i;
                            pos[k]=j;
                            break;
                        }
                    }
                    switcher=true;
                }
                i=aux_i;
                j=aux_j;
            }
        }
        for(int i=1;i<9;i++)
        {
            int aux_i=i;
            for(int j=8;j>0;j--)
            {
                int aux_j=j;
                if((a[i][j]=='B'||a[i][j]=='K')&&(a[--i][++j]=='W'||a[i][j]=='Q')&&a[--i][++j]=='_')
                {
                    i+=2;
                    j-=2;
                    for(int k=0;k<8;k++)
                    {
                        if(pos[k]==0)
                        {
                            pos[k++]=i;
                            pos[k]=j;
                            break;
                        }
                    }
                    switcher=true;
                }
                i=aux_i;
                j=aux_j;
                if(a[i][j]=='K'&&((a[++i][--j]=='W'||a[i][j]=='Q')&&a[++i][--j]=='_'))
                {
                    i=aux_i;
                    j=aux_j;
                    for(int k=0;k<8;k++)
                    {
                        if(pos[k]==0)
                        {
                            pos[k++]=i;
                            pos[k]=j;
                            break;
                        }
                    }
                    switcher=true;
                }
                i=aux_i;
                j=aux_j;
            }
        }
    }
    else
    {
        for(int i=1;i<9;i++)
        {
            int aux_i=i;
            for(int j=1;j<9;j++)
            {
                int aux_j=j;
                if((a[i][j]=='W'||a[i][j]=='Q')&&(a[++i][++j]=='B'||a[i][j]=='K')&&a[++i][++j]=='_')
                {
                    i-=2;
                    j-=2;
                    for(int k=0;k<8;k++)
                    {
                        if(pos[k]==0)
                        {
                            pos[k++]=i;
                            pos[k]=j;
                            break;
                        }
                    }
                    switcher=true;
                }
                i=aux_i;
                j=aux_j;
                if(a[i][j]=='Q'&&((a[--i][--j]=='B'||a[i][j]=='K')&&a[--i][--j]=='_'))
                {
                    i=aux_i;
                    j=aux_j;
                    for(int k=0;k<8;k++)
                    {
                        if(pos[k]==0)
                        {
                            pos[k++]=i;
                            pos[k]=j;
                            break;
                        }
                    }
                    switcher=true;
                }
                i=aux_i;
                j=aux_j;
            }
        }
        for(int i=1;i<9;i++)
        {
            int aux_i=i;
            for(int j=8;j>0;j--)
            {
                int aux_j=j;
                if((a[i][j]=='W'||a[i][j]=='Q')&&(a[++i][--j]=='B'||a[i][j]=='K')&&a[++i][--j]=='_')
                {
                    i-=2;
                    j+=2;
                    for(int k=0;k<8;k++)
                    {
                        if(pos[k]==0)
                        {
                            pos[k++]=i;
                            pos[k]=j;
                            break;
                        }
                    }
                    switcher=true;
                }
                i=aux_i;
                j=aux_j;
                if(a[i][j]=='Q'&&((a[--i][++j]=='B'||a[i][j]=='K')&&a[--i][++j]=='_'))
                {
                    i=aux_i;
                    j=aux_j;
                    for(int k=0;k<8;k++)
                    {
                        if(pos[k]==0)
                        {
                            pos[k++]=i;
                            pos[k]=j;
                            break;
                        }
                    }
                    switcher=true;
                }
                i=aux_i;
                j=aux_j;
            }
        }
    }
    return switcher;
}

bool CheckMove(char a[][9],int row,int column,int newrow,int newcolumn,int turn)
{
   int aux_row=row,aux_column=column;
   if(turn%2!=0)
   {
       if((a[row][column]=='B'||a[row][column]=='K')&&a[--row][--column]=='_'&&newrow==row&&newcolumn==column)
       {
           return true;
       }
       row=aux_row;
       column=aux_column;
       if((a[row][column]=='B'||a[row][column]=='K')&&a[--row][++column]=='_'&&newrow==row&&newcolumn==column)
       {
           return true;
       }
       row=aux_row;
       column=aux_column;
       if(a[row][column]=='K'&&a[++row][++column]=='_'&&newrow==row&&newcolumn==column)
       {
           return true;
       }
       row=aux_row;
       column=aux_column;
       if(a[row][column]=='K'&&a[++row][--column]=='_'&&newrow==row&&newcolumn==column)
       {
           return true;
       }
   }
   else
   {
       if((a[row][column]=='W'||a[row][column]=='Q')&&a[++row][++column]=='_'&&newrow==row&&newcolumn==column)
       {
           return true;
       }
       row=aux_row;
       column=aux_column;
       if((a[row][column]=='W'||a[row][column]=='Q')&&a[++row][--column]=='_'&&newrow==row&&newcolumn==column)
       {
           return true;
       }
       row=aux_row;
       column=aux_column;
       if(a[row][column]=='Q'&&a[--row][--column]=='_'&&newrow==row&&newcolumn==column)
       {
           return true;
       }
       row=aux_row;
       column=aux_column;
       if(a[row][column]=='Q'&&a[--row][++column]=='_'&&newrow==row&&newcolumn==column)
       {
           return true;
       }
   }
   return false;
}

bool CheckBoard(char a[][9],int turn,int pos[],int aux_turn[],int mode)
{
    if(mode==2)
    {
        int i=1;
        for(int j=1;j<9;j++)
        {
            if(a[i][j]=='B')
                aux_turn[0]=1;
        }
        i=8;
        for(int j=1;j<8;j++)
        {
            if(a[i][j]=='W')
                aux_turn[0]=1;
        }
        if(CheckForJumps(a,pos,turn))
        {
            for(int i=0;i<8;i++)
            {
                    pos[i]=0;
            }
            aux_turn[0]++;
        }
        aux_turn[0]++;
        if(aux_turn[0]==100)
        {
            cout<<"\n\nIt's a draw!\n\n";
            return false;
        }
    }
    else if(mode==3)
    {
    int buffer[]={0,0};
    for(int i=1;i<9;i++)
    {
        int row=i;
        for(int j=1;j<9;j++)
        {
        int column=j;
        if((a[row][column]=='B'||a[row][column]=='K')&&a[--row][--column]=='_')
        {
            buffer[0]++;
        }
        row=i;
        column=j;
        if((a[row][column]=='B'||a[row][column]=='K')&&a[--row][++column]=='_')
        {
            buffer[0]++;
        }
        row=i;
        column=j;
        if(a[row][column]=='K'&&a[++row][++column]=='_')
        {
            buffer[0]++;
        }
        row=i;
        column=j;
        if(a[row][column]=='K'&&a[++row][--column]=='_')
        {
           buffer[0]++;
        }
        row=i;
        column=j;
        if((a[row][column]=='W'||a[row][column]=='Q')&&a[++row][++column]=='_')
        {
            buffer[1]++;
        }
        row=i;
        column=j;
        if((a[row][column]=='W'||a[row][column]=='Q')&&a[++row][--column]=='_')
        {
            buffer[1]++;
        }
        row=i;
        column=j;
        if(a[row][column]=='Q'&&a[--row][--column]=='_')
        {
            buffer[1]++;
        }
        row=i;
        column=j;
        if(a[row][column]=='Q'&&a[--row][++column]=='_')
        {
            buffer[1]++;
        }
        }
        }
        if(buffer[0]==0 && !(CheckForJumps(a,pos,turn)))
        {
        for(int i=0;i<8;i++)
        {
            pos[i]=0;
        }
        Display_Board(a);
        cout<<"\n   Player 1 Black wins!\n\n";
        system("PAUSE");
        return false;
        }
        if(buffer[1]==0 && !(CheckForJumps(a,pos,turn)))
        {
        for(int i=0;i<8;i++)
        {
            pos[i]=0;
        }
        Display_Board(a);
        cout<<"\n   Player 2 White wins!\n\n";
        system("PAUSE");
        return false;
        }
    return true;
    }
    int buffer[]={0,0};
    for(int i=1;i<9;i++)
    {
        int row=i;
        for(int j=1;j<9;j++)
        {
        int column=j;
        if((a[row][column]=='B'||a[row][column]=='K')&&a[--row][--column]=='_')
        {
            buffer[0]++;
        }
        row=i;
        column=j;
        if((a[row][column]=='B'||a[row][column]=='K')&&a[--row][++column]=='_')
        {
            buffer[0]++;
        }
        row=i;
        column=j;
        if(a[row][column]=='K'&&a[++row][++column]=='_')
        {
            buffer[0]++;
        }
        row=i;
        column=j;
        if(a[row][column]=='K'&&a[++row][--column]=='_')
        {
           buffer[0]++;
        }
        row=i;
        column=j;
        if((a[row][column]=='W'||a[row][column]=='Q')&&a[++row][++column]=='_')
        {
            buffer[1]++;
        }
        row=i;
        column=j;
        if((a[row][column]=='W'||a[row][column]=='Q')&&a[++row][--column]=='_')
        {
            buffer[1]++;
        }
        row=i;
        column=j;
        if(a[row][column]=='Q'&&a[--row][--column]=='_')
        {
            buffer[1]++;
        }
        row=i;
        column=j;
        if(a[row][column]=='Q'&&a[--row][++column]=='_')
        {
            buffer[1]++;
        }
        }
    }
    if(buffer[0]==0 && !(CheckForJumps(a,pos,turn)))
    {
        for(int i=0;i<8;i++)
        {
            pos[i]=0;
        }
        Display_Board(a);
        cout<<"\n   Player 2 White wins!\n\n";
        system("PAUSE");
        return false;
    }
    if(buffer[1]==0 && !(CheckForJumps(a,pos,turn)))
    {
        for(int i=0;i<8;i++)
        {
            pos[i]=0;
        }
        Display_Board(a);
        cout<<"\n   Player 1 Black wins!\n\n";
        system("PAUSE");
        return false;
    }
    return true;
}

bool CheckJumpMoves(char a[][9],int turn,int row,int column)
{
    if(turn%2!=0)
    {
        int row_left=row,column_left=column,row_right=row,column_right=column,row1=row,col1=column,row2=row,col2=column;
        if(a[row][column]=='B'&&(a[--row_left][--column_left]=='W'||a[row][column]=='Q')&&a[--row_left][--column_left]=='_'||
           ((a[--row_right][++column_right]=='W'||a[row_right][column_right]=='Q')&&a[--row_right][++column_right]=='_'))
        {
            return true;
        }
        row_left=row,column_left=column,row_right=row,column_right=column;
        if(a[row][column]=='K'&&(((a[--row_left][--column_left]=='W'||a[row_left][column_left]=='Q')&&a[--row_left][--column_left]=='_')||
                                 ((a[--row_right][++column_right]=='W'||a[row_right][column_right]=='Q')&&a[--row_right][++column_right]=='_')||
                                 ((a[++row1][++col1]=='W'||a[row1][col1]=='Q')&&a[++row1][++col1]=='_')||
                                 ((a[++row2][--col2]=='W'||a[row2][col2]=='Q')&&a[++row2][--col2]=='_')))
        {
            return true;
        }
    }
    else
    {
        int row_left=row,column_left=column,row_right=row,column_right=column,row1=row,col1=column,row2=row,col2=column;
        if(a[row][column]=='W'&&((a[++row_left][++column_left]=='B'||a[row_left][column_left]=='K')&&a[++row_left][++column_left]=='_')||
           ((a[++row_right][--column_right]=='B'||a[row_right][column_right]=='K')&&a[++row_right][--column_right]=='_'))
        {
            return true;
        }
        row_left=row,column_left=column,row_right=row,column_right=column;
        if(a[row][column]=='Q'&&(((a[--row_left][--column_left]=='B'||a[row_left][column_left]=='K')&&a[--row_left][--column_left]=='_')||
                                 ((a[--row_right][++column_right]=='B'||a[row_right][column_right]=='K')&&a[--row_right][++column_right]=='_')||
                                 ((a[++row1][++col1]=='B'||a[row1][col1]=='K')&&a[++row1][++col1]=='_')||
                                 ((a[++row2][--col2]=='B'||a[row2][col2]=='K')&&a[++row2][--col2]=='_')))
        {
            return true;
        }
    }
    return false;
}

void Kinging(char a[][9])
{
    int i=1;
    for(int j=1;j<9;j++)
    {
        if(a[i][j]=='B')
        {
            a[i][j]='K';
        }
    }
    i=8;
    for(int j=1;j<9;j++)
    {
        if(a[i][j]=='W')
        {
            a[i][j]='Q';
        }
    }
}

void PieceJump(char a[][9],int turn,int row,int column)
{
    if(turn%2!=0)
    {
        while(CheckJumpMoves(a,turn,row,column))
        {
            cout<<"\nJump to row: ";
            int newrow=0;cin>>newrow;
            while(newrow<1 || newrow>8)
            {
                cout<<"\nInvalid row";
                cout<<"\nJump to row: ";
                cin>>newrow;
            }
            cout<<"\nJump to column: ";
            int newcolumn=0;cin>>newcolumn;
            while(newcolumn<1 || newcolumn>8)
            {
                cout<<"\nInvalid column";
                cout<<"\nJump to column: ";
                cin>>newcolumn;
            }
            int row_left=row,column_left=column,row_right=row,column_right=column,row1=row,col1=column,row2=row,col2=column;
            if((a[row][column]=='B'||a[row][column]=='K')&&(a[--row_left][--column_left]=='W'||a[row_left][column_left]=='Q')&&newrow==--row_left&&newcolumn==--column_left)
            {
                if(a[row][column]=='B')
                a[newrow][newcolumn]='B';
                else
                a[newrow][newcolumn]='K';
                a[++newrow][++newcolumn]='_';
                a[++newrow][++newcolumn]='_';
                Display_Board(a);
                row=newrow-2;
                column=newcolumn-2;
            }
            else if((a[row][column]=='B'||a[row][column]=='K')&&(a[--row_right][++column_right]=='W'||a[row_right][column_right]=='Q')&&newrow==--row_right&&newcolumn==++column_right)
            {
                if(a[row][column]=='B')
                a[newrow][newcolumn]='B';
                else
                a[newrow][newcolumn]='K';
                a[++newrow][--newcolumn]='_';
                a[++newrow][--newcolumn]='_';
                Display_Board(a);
                row=newrow-2;
                column=newcolumn+2;
            }
            else if(a[row][column]=='K'&&(a[++row1][++col1]=='W'||a[row1][col1]=='Q')&&newrow==++row1&&newcolumn==++col1)
            {
                a[newrow][newcolumn]='K';
                a[--newrow][--newcolumn]='_';
                a[--newrow][--newcolumn]='_';
                Display_Board(a);
                row=newrow+2;
                column=newcolumn+2;
            }
            else if(a[row][column]=='K'&&(a[++row2][--col2]=='W'||a[row2][col2]=='Q')&&newrow==++row2&&newcolumn==--col2)
            {
                a[newrow][newcolumn]='K';
                a[--newrow][++newcolumn]='_';
                a[--newrow][++newcolumn]='_';
                Display_Board(a);
                row=newrow+2;
                column=newcolumn+2;
            }
            else
            {
                cout<<"\nInvalid selection\n";
                return PieceJump(a,turn,row,column);
            }
        }
    }
    else
    {
        while(CheckJumpMoves(a,turn,row,column))
        {
            cout<<"\nJump to row: ";
            int newrow=0;cin>>newrow;
            while(newrow<1 || newrow>8)
            {
                cout<<"\nInvalid row";
                cout<<"\nJump to row: ";
                cin>>newrow;
            }
            cout<<"\nJump to column: ";
            int newcolumn=0;cin>>newcolumn;
            while(newcolumn<1 || newcolumn>8)
            {
                cout<<"\nInvalid column";
                cout<<"\nJump to column: ";
                cin>>newcolumn;
            }
            int row_left=row,column_left=column,row_right=row,column_right=column,row1=row,col1=column,row2=row,col2=column;
            if((a[row][column]=='W'||a[row][column]=='Q')&&(a[++row_left][++column_left]=='B'||a[row_left][column_left]=='K')&&newrow==++row_left&&newcolumn==++column_left)
            {
                if(a[row][column]=='W')
                a[newrow][newcolumn]='W';
                else
                a[newrow][newcolumn]='Q';
                a[--newrow][--newcolumn]='_';
                a[--newrow][--newcolumn]='_';
                Display_Board(a);
                row=newrow+2;
                column=newcolumn+2;
            }
            else if((a[row][column]=='W'||a[row][column]=='Q')&&(a[++row_right][--column_right]=='B'||a[row_right][column_right]=='K')&&newrow==++row_right&&newcolumn==--column_right)
            {
                if(a[row][column]='W')
                a[newrow][newcolumn]='W';
                else
                a[newrow][newcolumn]='Q';
                a[--newrow][++newcolumn]='_';
                a[--newrow][++newcolumn]='_';
                Display_Board(a);
                row=newrow+2;
                column=newcolumn-2;
            }
            else if(a[row][column]=='Q'&&(a[--row1][--col1]=='B'||a[row1][col1]=='K')&&newrow==--row1&&newcolumn==--col1)
            {
                a[newrow][newcolumn]='Q';
                a[++newrow][++newcolumn]='_';
                a[++newrow][++newcolumn]='_';
                Display_Board(a);
                row=newrow-2;
                column=newcolumn-2;
            }
            else if(a[row][column]=='Q'&&(a[--row2][++col2]=='B'||a[row2][col2]=='K')&&newrow==--row2&&newcolumn==++col2)
            {
                a[newrow][newcolumn]='Q';
                a[++newrow][--newcolumn]='_';
                a[++newrow][--newcolumn]='_';
                Display_Board(a);
                row=newrow-2;
                column=newcolumn+2;
            }
            else
            {
                cout<<"\nInvalid selection\n";
                return PieceJump(a,turn,row,column);
            }
        }
    }
}

void Standard_Game(int mode)
{
    char board[9][9];
    int pos[]={0,0,0,0,0,0,0,0},aux_turn[]={0};
    SetBoard(board);
    SetPieces(board);
    int turn=1;
    while(CheckBoard(board,turn,pos,aux_turn,mode))
    {
        Kinging(board);
        if(mode==2)
            Display_Board(board,"50 moves");
        else if(mode==3)
            Display_Board(board,"Anti-Checkers");
        else
        Display_Board(board);
        SelectPiece(board,turn,pos);
        turn++;
    }
}

void KVQ_setPieces(char a[][9])
{
    int i=3;
    for(int j=1;j<9;j++)
    {
        a[i][j]='K';
    }
    i=6;
    for(int j=1;j<9;j++)
    {
        a[i][j]='Q';
    }
}

void KingVQeen()
{
    char board[9][9];
    int pos[]={0,0,0,0,0,0,0,0},aux_turn[]={1};
    SetBoard(board);
    KVQ_setPieces(board);
    int turn=1;
    while(CheckBoard(board,turn,pos,aux_turn))
    {
        Display_Board(board,"Kings vs Queens");
        SelectPiece(board,turn,pos);
        turn++;
    }
}

void SelectPiece(char a[][9],int turn,int pos[])
{
    if(turn%2!=0)
    {
        while(CheckForJumps(a,pos,turn))
        {
            cout<<"\nJump(s) available at: \n";
            for(int i=0;i<8;i++)
            {
                if(pos[i]!=0)
                    cout<<pos[i]<<' ';
                if(i%2!=0 && pos[i]!=0)
                    cout<<"  ";
            }
            cout<<"\nBlack Player 1 select piece\n";
            cout<<"\nRow: ";
            int row=0;cin>>row;
            while(row<1 || row>8)
            {
                cout<<"\nInvalid row\n";
                cout<<"\nRow: ";cin>>row;
            }
            cout<<"\nColumn: ";
            int column=0;cin>>column;
            while(column<1 || column>8)
            {
                cout<<"\nInvalid column\n";
                cout<<"\nColumn: ";cin>>column;
            }
            int k=0;
            while(k<8)
            {
                if(row==pos[k++]&&column==pos[k])
                {
                    PieceJump(a,turn,row,column);
                    for(int i=0;i<8;i++)
                    {
                        pos[i]=0;
                    }
                    return;
                }
                k++;
            }
            k=7;
            while(k>=0)
            {
                if(column==pos[k--]&&row==pos[k])
                {
                    PieceJump(a,turn,row,column);
                    for(int i=0;i<8;i++)
                    {
                        pos[i]=0;
                    }
                    return;
                }
                k--;
            }
            cout<<"\nMust make a jump!\n";
            for(int i=0;i<8;i++)
            {
                    pos[i]=0;
            }
            return SelectPiece(a,turn,pos);
        }
        cout<<"\nBlack Player 1 select piece\n";
        cout<<"\nRow: ";
        int row=0;cin>>row;
        if(row<1 || row>8)
        {
            cout<<"\nInvalid row\n";
            return SelectPiece(a,turn,pos);
        }
        cout<<"\nColumn: ";
        int column=0;cin>>column;
        if(column<1 || column>8)
        {
            cout<<"\nInvalid column\n";
            return SelectPiece(a,turn,pos);
        }
        int aux_row=row,aux_column=column;
        if(a[row][column]=='B'&&(a[--row][--column]=='_'||a[row][column+2]=='_'))
        {
            MovePiece(a,aux_row,aux_column,turn);
            return;
        }
        row=aux_row,column=aux_column;
        if(a[row][column]=='K'&&(a[++row][++column]=='_'||a[row][column-2]=='_'||
                                          a[row-2][column]=='_'||a[row][column+2]=='_'))
        {
            MovePiece(a,aux_row,aux_column,turn);
            return;
        }
        cout<<"\nCan't move that piece\n";
        return SelectPiece(a,turn,pos);
    }
    else
    {
        while(CheckForJumps(a,pos,turn))
        {
            cout<<"\nJump(s) available at: \n";
            for(int i=0;i<8;i++)
            {
                if(pos[i]!=0)
                    cout<<pos[i]<<' ';
                if(i%2!=0 && pos[i]!=0)
                    cout<<"  ";
            }
            cout<<"\nWhite Player 2 select piece\n";
            cout<<"\nRow: ";
            int row=0;cin>>row;
            while(row<1 || row>8)
            {
                cout<<"\nInvalid row\n";
                cout<<"\nRow: ";cin>>row;
            }
            cout<<"\nColumn: ";
            int column=0;cin>>column;
            while(column<1 || column>8)
            {
                cout<<"\nInvalid column\n";
                cout<<"\nColumn: ";cin>>column;
            }
            int k=0;
            while(k<8)
            {
                if(row==pos[k++]&&column==pos[k])
                {
                    PieceJump(a,turn,row,column);
                    for(int i=0;i<8;i++)
                    {
                        pos[i]=0;
                    }
                    return;
                }
                k++;
            }
            k=7;
            while(row==pos[k--]&&column==pos[k])
            {
                if(column==pos[k]&&row==pos[--k])
                {
                    PieceJump(a,turn,row,column);
                    for(int i=0;i<8;i++)
                    {
                        pos[i]=0;
                    }
                    return;
                }
                k--;
            }
            cout<<"\nMust make a jump!\n";
            for(int i=0;i<8;i++)
            {
                pos[i]=0;
            }
            return SelectPiece(a,turn,pos);
        }
        cout<<"\nWhite Player 2 select piece\n";
        cout<<"\nRow: ";
        int row=0;cin>>row;
        if(row<1 || row>8)
        {
            cout<<"\nInvalid row\n";
            return SelectPiece(a,turn,pos);
        }
        cout<<"\nColumn: ";
        int column=0;cin>>column;
        if(column<1 || column>8)
        {
            cout<<"\nInvalid column\n";
            return SelectPiece(a,turn,pos);
        }
        int aux_row=row,aux_column=column;
        if(a[row][column]=='W'&&(a[++row][--column]=='_' || a[row][column+2]=='_'))
        {
            MovePiece(a,aux_row,aux_column,turn);
            return;
        }
        row=aux_row,column=aux_column;
        if(a[row][column]=='Q'&&(a[--row][--column]=='_'||a[row][column+2]=='_'||
                                 a[row+2][column]=='_'||a[row][column-2]=='_'))
        {
            MovePiece(a,aux_row,aux_column,turn);
            return;
        }
        cout<<"\nCan't move that piece\n";
        return SelectPiece(a,turn,pos);
    }
}

void MovePiece(char a[][9],int row,int column,int turn)
{
    cout<<"\nMove to row: ";
    int newrow=0;cin>>newrow;
    while(newrow<1 || newrow>8)
    {
        cout<<"\nInvalid row\n";
        cout<<"\nMove to row: ";
        cin>>newrow;
    }
    cout<<"\nMove to column: ";
    int newcolumn=0;cin>>newcolumn;
    while(newcolumn<1 || newcolumn>8)
    {
        cout<<"\nInvalid column\n";
        cout<<"\nMove to column: ";
        cin>>newcolumn;
    }
    if(CheckMove(a,row,column,newrow,newcolumn,turn))
    {
        a[newrow][newcolumn]=a[row][column];
        a[row][column]='_';
    }
    else
    {
        cout<<"\nInvalid position\n";
        return MovePiece(a,row,column,turn);
    }
}

void SetBoard(char a[][9],char mark)
{
    for(int i=1;i<9;i++)
    {
        for(int j=1;j<9;j++)
        {
            a[i][j]=mark;
        }
    }
}

void Display_Board(char a[][9],string mode)
{
    system("CLS");
    cout<<"\n\n                            \"Checkers " + mode + "\"\n\n";
    for(int i=1;i<9;i++)
    {
        cout<<'\t'<<i;
    }
    cout<<"\n\n";
    for(int i=1;i<9;i++)
    {
        cout<<"  "<<i<<"  ";
        for(int j=1;j<9;j++)
        {
            cout<<'\t'<<a[i][j];
        }
        cout<<"\n\n";
    }
    cout<<endl;
}

void SetPieces(char a[][9])
{
    for(int i=1;i<9;i++)
    {
        for(int j=1;j<9;j++)
        {
            int aux_j=j;
            switch(i)
            {
            case 1 :
                j=2;
                while(j<9)
                {
                    a[i][j]='W';
                    j+=2;
                }
                j=aux_j;
            break;
            case 2 :
                j=1;
                while(j<9)
                {
                    a[i][j]='W';
                    j+=2;
                }
                j=aux_j;
            break;
            case 3 :
                j=2;
                while(j<9)
                {
                    a[i][j]='W';
                    j+=2;
                }
            j=aux_j;
            break;
            case 6 :
                j=1;
                while(j<9)
                {
                    a[i][j]='B';
                    j+=2;
                }
            j=aux_j;
            break;
            case 7 :
                j=2;
                while(j<9)
                {
                    a[i][j]='B';
                    j+=2;
                }
            j=aux_j;
            break;
            case 8 :
                j=1;
                while(j<9)
                {
                    a[i][j]='B';
                    j+=2;
                }
            j=aux_j;
            break;
            }
        }
    }
}

void Checkers()
{
    unsigned option=0,mode=0;
    do
    {
        Display_Main_Menu();
        cin>>option;
        if(option<1 || option>4)
        {
            cout<<"\n     Invalid option\n\n";
            system("PAUSE");
            return Checkers();
        }
        switch(option)
        {
        case 1 :
            Game(mode);
            break;
        case 2 :
            Rules();
            break;
        case 3 :
            mode=SetMode();
            break;
        }
    }while(option!=4);
}

void Rules()
{
    system("CLS");
    cout<<"\n         \"Checkers\" Standard Rules\n\n";
    cout<<"     -Checkers is an 8x8 ,2 player, board game\n\n";
    cout<<"     -Each player has 12 pieces,the Black player starts followed by the White player.\n\n";
    cout<<"     -The goal is to capture all the enemy pieces or block \n    all the possible moves of the enemy pieces\n\n";
    cout<<"     -All pieces move diagonally forward to the left or right and are considered pawns\n\n";
    cout<<"     -If one of your pieces reaches the other end of the board,\n    that piece is crowned king and your turn ends\n\n";
    cout<<"     -A king can move diagonally forward but also backwards,use them wisely and can jump over pieces\n";
    cout<<"     -A enemy piece is captured by jumping over it diagonally if the spot is available,\n    you must always make a jump if available\n\n";
    system("PAUSE");
}

void Game(int mode)
{
    switch(mode)
    {
        case 1 :
            Standard_Game(mode);
            break;
        case 2 :
            Standard_Game(mode);
            break;
        case 3 :
            Standard_Game(mode);
            break;
        case 4 :
            KingVQeen();
            break;
        default :
            Standard_Game(mode);
    }
}

void Display_Main_Menu()
{
    system("CLS");
    cout<<"\n         \"Checkers\"-Two player v1.0\n\n";
    cout<<"     1.Start game\n";
    cout<<"     2.Rules\n";
    cout<<"     3.House rules(Select mode)\n";
    cout<<"     4.Quit game\n";
    cout<<"\n     Select option: ";
}
