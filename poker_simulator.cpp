/*************************************************************************************************
*                                  POKER TEXAS HOLD'EM SIMULATOR                                 *
*************************************************************************************************/
/* Write a program to play poker! You can provide 5 cards to the player, let that player choose new
cards, and then determine how good the hand is. Think about whether this is easy to do? What
problems might you have in terms of keeping track of cards that have been drawn already?
Was this easier or harder than the slot machine? */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int Game_Options(int turn);
int Menu();
int Rand_Range(int low,int high);
int Game();
int Tag(int card);
bool Unique(int c1,int c2,int c3,int c4,int c5,int c6=-1,int c7=-2);
void PKR_Texas_Holdem();
void Check(int c1,int c2,int c3,int c4,int c5,int c6,int c7);
void Display(int c1,int c2,int c3,int c4,int c5,int turn,int c6=0,int c7=0);
string Card_Skin(int number);
string Type(int number);

int main(int argc,char* argv[])
{
    PKR_Texas_Holdem();
    return 0;
}

int Game()
{
    srand(time(NULL));
    int c1=0,c2=0,c3=0,c4=0,c5=0,c6=0,c7=0,option=0;
    for(int turn=1;turn<=3;turn++)
    {
        switch(turn)
        {
        case 1 :
            while(Unique(c1,c2,c3,c4,c5))
            {
                c1=Rand_Range(0,52);
                c2=Rand_Range(0,52);
                c3=Rand_Range(0,52);
                c4=Rand_Range(0,52);
                c5=Rand_Range(0,52);
            }
            Display(c1,c2,c3,c4,c5,turn);
            option=Game_Options(turn);
            switch(option)
            {
            case 1 :
            continue;
            case 2 :
                cout<<"\nGame over.\n\n";
                system("PAUSE");
                return 0;
            }
        break;
        case 2 :
            c6=Rand_Range(0,52);
            while(Unique(c1,c2,c3,c4,c5,c6))
                c6=Rand_Range(0,52);
            Display(c1,c2,c3,c4,c5,turn,c6);
            option=Game_Options(turn);
            switch(option)
            {
            case 1 :
            continue;
            break;
            case 2 :
                cout<<"\nGame over.\n\n";
                system("PAUSE");
                return 0;
            }
        break;
        case 3 :
            c7=Rand_Range(0,52);
            while(Unique(c1,c2,c3,c4,c5,c6,c7))
                c7=Rand_Range(0,52);
            Display(c1,c2,c3,c4,c5,turn,c6,c7);
            option=Game_Options(turn);
            switch(option)
            {
            case 1 :
                Check(c1,c2,c3,c4,c5,c6,c7);
                system("PAUSE");
            break;
            case 2 :
                cout<<"\nGame over.\n\n";
                system("PAUSE");
                return 0;
            }
        }
    }
}

void Display(int c1,int c2,int c3,int c4,int c5,int turn,int c6,int c7)
{
    switch(turn)
    {
    case 1 :
        system("CLS");
        cout<<"\n\n        \"POKER Texas Hold'em\"\n";
        cout<<"                 Flop\n\n";
        cout<<"Your hand:\n\n"<<Card_Skin(c1)<<'\n'<<Card_Skin(c2)<<"\n\n";
        cout<<"Community cards:\n\n"<<Card_Skin(c3)<<'\n'<<Card_Skin(c4)<<'\n'<<Card_Skin(c5)<<"\n\n";
    break;
    case 2 :
        system("CLS");
        cout<<"\n\n        \"POKER Texas Hold'em\"\n";
        cout<<"                 Turn\n\n";
        cout<<"Your hand:\n\n"<<Card_Skin(c1)<<'\n'<<Card_Skin(c2)<<"\n\n";
        cout<<"Community cards:\n\n"<<Card_Skin(c3)<<'\n'<<Card_Skin(c4)<<'\n'<<Card_Skin(c5)<<'\n'<<Card_Skin(c6)<<"\n\n";
    break;
    case 3 :
        system("CLS");
        cout<<"\n\n        \"POKER Texas Hold'em\"\n";
        cout<<"                 River\n\n";
        cout<<"Your hand:\n\n"<<Card_Skin(c1)<<'\n'<<Card_Skin(c2)<<"\n\n";
        cout<<"Community cards:\n\n"<<Card_Skin(c3)<<'\n'<<Card_Skin(c4)<<'\n'<<Card_Skin(c5)<<'\n'<<Card_Skin(c6)<<'\n'<<Card_Skin(c7)<<"\n\n";
    }
}

void Check(int c1,int c2,int c3,int c4,int c5,int c6,int c7)
{
    if((Tag(c1)>=9)&&(Tag(c2)>=9)||(Tag(c3)>=9)&&(Tag(c4)>=9)&&(Tag(c5)>=9)&&(Tag(c6)>=9)&&(Tag(c7)>=9))
        cout<<"\nOutstanding hand!\n\n";
    else if((Tag(c1)>5)&&(Tag(c2)>5)||(Tag(c3)>5)&&(Tag(c4)>5)&&(Tag(c5)>5)&&(Tag(c6)>5)&&(Tag(c7)>5))
        cout<<"\nMedium hand.\n\n";
    else if((Tag(c1)<=5)&&(Tag(c2)<=5)||(Tag(c3)<=5)&&(Tag(c4)<=5)&&(Tag(c5)<=5)&&(Tag(c6)<=5)&&(Tag(c7)<=5))
        cout<<"\nAverage hand.\n\n";
    else
        cout<<"\nStandard hand,don't press your luck.\n\n";
}

int Tag(int card)
{
    card/=4;
    return card;
}

string Card_Skin(int number)
{
    if(number/4==0)
       return "Two of "+Type(number);
    else if(number/4==1)
       return "Three of "+Type(number);
    else if(number/4==2)
       return "Four of "+Type(number);
    else if(number/4==3)
       return "Five of "+Type(number);
    else if(number/4==4)
        return "Six of "+Type(number);
    else if(number/4==5)
        return "Seven of "+Type(number);
    else if(number/4==6)
        return "Eight of "+Type(number);
    else if(number/4==7)
        return "Nine of "+Type(number);
    else if(number/4==8)
        return "Ten of "+Type(number);
    else if(number/4==9)
        return "Jack of "+Type(number);
    else if(number/4==10)
        return "Queen of "+Type(number);
    else if(number/4==11)
        return "King of "+Type(number);
    else if(number/4==12)
        return "Ace of "+Type(number);
}

string Type(int number)
{
    if(number%4==1)
        return "Clubs";
    else if(number%4==2)
        return "Diamonds";
    else if(number%4==3)
        return "Hearts";
    else if(number%4==0)
        return "Spades";
}

int Game_Options(int turn)
{
    int option=0;
    switch(turn)
    {
        case 3 :
        cout<<"1.Check\n";
        cout<<"2.Fold\n";
        cout<<"\nSelect option: ";
        cin>>option;
        if(option>2 || option<1)
        {
            cout<<"\nNot a valid option.\n";
            return Game_Options(3);
        }
        break;
        default :
            cout<<"1.Draw\n";
            cout<<"2.Fold\n";
            cout<<"\nSelect option: ";
            cin>>option;
            if(option>2 || option<1)
            {
                cout<<"\nNot a valid option.\n";
                return Game_Options(1);
            }
    }
    return option;
}

bool Unique(int c1,int c2,int c3,int c4,int c5,int c6,int c7)
{
    if(c1==c2)
        return true;
    else if(c1==c3)
        return true;
    else if(c1==c4)
        return true;
    else if(c1==c5)
        return true;
    else if(c1==c6)
        return true;
    else if(c1==c7)
        return true;
    else if(c2==c3)
        return true;
    else if(c2==c4)
        return true;
    else if(c2==c5)
        return true;
    else if(c2==c6)
        return true;
    else if(c2==c7)
        return true;
    else if(c3==c4)
        return true;
    else if(c3==c5)
        return true;
    else if(c3==c6)
        return true;
    else if(c3==c7)
        return true;
    else if(c4==c5)
        return true;
    else if(c4==c6)
        return true;
    else if(c4==c7)
        return true;
    else if(c5==c6)
        return true;
    else if(c5==c7)
        return true;
    else if(c6==c7)
        return true;
    return false;
}

void PKR_Texas_Holdem()
{
    int option=Menu();
    while(option!=2)
    {
        switch(option)
        {
        case 1 :
            Game();
        }
        option=Menu();
    }
}

int Menu()
{
    system("CLS");
    cout<<"\n\n      Welcome to \"POKER Texas Hold'em\" v1.0\n\n";
    cout<<"       1.Start game\n";
    cout<<"       2.Quit game\n";
    cout<<"\n       Select option: ";
    int option;cin>>option;
    return option;
}

int Rand_Range(int low,int high)
{
    return rand()%(high-low)+low;
}
