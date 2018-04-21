#include <iostream>
#include <stdlib.h>
#include <sstream>

using namespace std;

int stoi(string number)
{
    int value;
    istringstream(number)>>value;
    return value;
}

string itos(int number)
{
    stringstream ss;
    ss<<number;
    string str=ss.str();
    return str;
}

string Display()
{
    system("CLS");
    cout<<"Please input number: ";
    string number;
    getline(cin,number,'\n');
    return number;
}

string Ones(string number)
{
    int value=stoi(number);
    if(value==0)
        return "Zero";
    else if(value==1)
        return "One";
    else if(value==2)
        return "Two";
    else if(value==3)
        return "Three";
    else if(value==4)
        return "Four";
    else if(value==5)
        return "Five";
    else if(value==6)
        return "Six";
    else if(value==7)
        return "Seven";
    else if(value==8)
        return "Eight";
    else if(value==9)
        return "Nine";
}

string Twos(string number)
{
    int value=stoi(number);
    if(value==10)
        return "Ten";
    else if(value==11)
        return "Eleven";
    else if(value==12)
        return "Twelve";
    else if(value==13)
        return "Thirteen";
    else if(value==14)
        return "Fourteen";
    else if(value==15)
        return "Fifteen";
    else if(value==16)
        return "Sixteen";
    else if(value==17)
        return "Seventeen";
    else if(value==18)
        return "Eighteen";
    else if(value==19)
        return "Nineteen";
    else if(value==20)
        return "Twenty";
    else if(value==30)
        return "Thirty";
    else if(value==40)
        return "Forty";
    else if(value==50)
        return "Fifty";
    else if(value==60)
        return "Sixty";
    else if(value==70)
        return "Seventy";
    else if(value==80)
        return "Eighty";
    else if(value==90)
        return "Ninety";
    else
    {
        number=itos(value);
        return Twos(number.substr(0,1)+"0")+" "+Ones(number.substr(1,1));
    }
}

string Hundreds(string number)
{
    if(number=="000")
        return " ";
    else if(number.substr(0,1)=="0"&&number.substr(1,1)!="0")
        return Twos(number.substr(1,2));
    else if(number.substr(0,2)=="00"&&number.substr(2,1)!="0")
        return Ones(number.substr(2,1));
    if(number.substr(1,1)=="0"&&number.substr(2,1)!="0")
        return Ones(number.substr(0,1))+" Hundred "+Ones(number.substr(2,1));
    else if(number.substr(1,1)!="0"&&number.substr(2,1)=="0")
        return Ones(number.substr(0,1))+" Hundred "+Twos(number.substr(1,2));
    else if(number.substr(1,2)=="00")
        return Ones(number.substr(0,1))+" Hundred ";
    else
        return Ones(number.substr(0,1))+" Hundred "+Twos(number.substr(1,2));
}

string Thousands(string number)
{
    if(number=="000000")
        return " ";
    if(number.size()%3==1)
        return Ones(number.substr(0,1))+" Thousand "+Hundreds(number.substr(1,3));
    else if(number.size()%3==2)
        return Twos(number.substr(0,2))+" Thousand "+Hundreds(number.substr(2,3));
    else if(number.size()%3==0)
        return Hundreds(number.substr(0,3))+" Thousand "+Hundreds(number.substr(3,3));
}

string Millions(string number)
{
    if(number.size()%3==1)
        return Ones(number.substr(0,1))+" Million "+Thousands(number.substr(1,6));
    else if(number.size()%3==2)
        return Twos(number.substr(0,2))+" Million "+Thousands(number.substr(2,6));
    else if(number.size()%3==0)
        return Hundreds(number.substr(0,3))+" Million "+Thousands(number.substr(3,6));
}

string Split(string number)
{
    if(number.size()/3==0)
    {
        if(number.size()%3==1)
            return Ones(number);
        else if(number.size()%3==2)
        {
            if(number.substr(0,1)=="0")
                return Ones(number.substr(1,1));
            else
                return Twos(number);
        }
    }
    else if(number.size()/3==1&&number.size()%3==0)
    {
        if(number.substr(0,2)!="00"&&number.substr(0,1)=="0")
            return Twos(number);
        else if(number.substr(0,2)=="00")
            return Ones(number);
        else
            return Hundreds(number);
    }
    else if(number.size()/3==1)
    {
        if(number.size()%3==1)
        {
            if(number.substr(0,1)=="0")
                return Split(number.substr(1,3));
            else
                return Thousands(number);
        }
        else if(number.size()%3==2)
        {
            if(number.substr(0,2)=="00")
                return Split(number.substr(2,3));
            else
                return Thousands(number);
        }
    }
    else if(number.size()/3==2&&number.size()%3==0)
    {
        if(number.size()%3==0)
        {
            if(number.substr(0,3)=="000")
                return Split(number.substr(3,3));
            else
                return Thousands(number);
        }
    }
    else if(number.size()/3==2)
    {
        if(number.size()%3==1)
        {
            if(number.substr(0,1)=="0")
                return Split(number.substr(1,6));
            else
                return Millions(number);
        }
        else if(number.size()%3==2)
        {
            if(number.substr(0,2)=="00")
                return Split(number.substr(2,6));
            else
                return Millions(number);
        }
    }
    else if(number.size()/3==3&&number.size()%3==0)
    {
        if(number.substr(0,3)=="000")
            return Split(number.substr(3,6));
        else
            return Millions(number);
    }
}

int main(int argc,char* argv[])
{
    while(1)
    {
        string number=" ";
        number=Display();
        number=Split(number);
        cout<<"\n"<<number<<"\n"<<endl;
        system("PAUSE");
    }
}
