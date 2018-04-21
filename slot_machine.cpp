#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int Solt_Machine(int credits);
int Rand_Range(int low,int high);
string Put_Txt(int wheel);
int Display(int w1,int w2,int w3,int w4,int w5,int w6,int w7,int w8,int w9,int credits);
int Wins_Com(int w1,int w2,int w3,int w4,int w5,int w6,int w7,int w8,int w9,int credits);
int MainMenu();

int main(int argc,char* argv[])
{
    int option=0;
    srand(time(NULL));
    while(option!=2)
    {
        option=MainMenu();
        int credits=100;
        switch(option)
        {
        case 0 :
            system("CLS");
            cout<<"\n\n    Please input no. of coins: ";
            cin>>credits;
        case 1 :
            while(credits)
            {
                credits=Solt_Machine(credits);
            }
            break;
        case 2 :
            return 0;
        }
     }
}

int MainMenu()
{
    system("CLS");
    cout<<"\n      Welcome to \"Slot machine\" v1.0\n\n";
    cout<<"              0.Input coins\n";
    cout<<"              1.Start game\n";
    cout<<"              2.Quit game\n\n";
    cout<<"              Select a option: ";
    int option=0;cin>>option;
    return option;
}

int Solt_Machine(int credits)
{
    int w1=Rand_Range(0,5),w2=Rand_Range(0,5),w3=Rand_Range(0,5),
    w4=Rand_Range(0,5),w5=Rand_Range(0,5),w6=Rand_Range(0,5),
    w7=Rand_Range(0,5),w8=Rand_Range(0,5),w9=Rand_Range(0,5);
    credits=Display(w1,w2,w3,w4,w5,w6,w7,w8,w9,credits);
    return credits;
}

int Display(int w1,int w2,int w3,int w4,int w5,int w6,int w7,int w8,int w9,int credits)
{
    system("CLS");
    cout<<"\n       \"Slot machine\"\n\n";
    cout<<"   "<<Put_Txt(w1)<<"   "<<Put_Txt(w2)<<"   "<<Put_Txt(w3)<<endl;
    cout<<"   "<<Put_Txt(w4)<<"   "<<Put_Txt(w5)<<"   "<<Put_Txt(w6)<<endl;
    cout<<"   "<<Put_Txt(w7)<<"   "<<Put_Txt(w8)<<"   "<<Put_Txt(w9)<<"\n\n";
    credits=Wins_Com(w1,w2,w3,w4,w5,w6,w7,w8,w9,credits);
    cout<<"Credits: "<<credits<<"\n\n";
    system("PAUSE");
    return credits;
}

int Wins_Com(int w1,int w2,int w3,int w4,int w5,int w6,int w7,int w8,int w9,int credits)
{
    if((w1==w2&&w2==w3)||(w4==w5 && w5==w6)||(w7==w8 && w8==w9))
    {
        cout<<"\nStraight line! +20\n\n";
        credits+=20;
        return credits;
    }
    else if((w1==w2&&w2==w4)||(w8==w9&&w6==w9)||(w7==w8&&w8==w4)||(w8==w9&&w9==w6))
    {
        cout<<"\nCorner bonus! +30\n\n";
        credits+=40;
        return credits;
    }
    else if((w1==w5&&w5==w9)||(w3==w5&&w5==w7))
    {
        cout<<"\nCrazy bonus! +60\n\n";
        credits+=60;
        return credits;
    }
    else
    {
        credits-=10;
        return credits;
    }
}

string Put_Txt(int wheel)
{
    switch(wheel)
    {
    case 0 :
        return "Lemon";
    case 1 :
        return "Seven";
    case 2 :
        return "Cheery";
    case 3 :
        return "Diamond";
    case 4 :
        return "Bell";
    }
}

int Rand_Range(int low,int high)
{
    return rand()%(high-low)+low;
}
