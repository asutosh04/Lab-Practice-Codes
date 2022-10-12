#include<iostream>
using namespace std;

class Account
{
    protected:
    static int anum;
    static string name;

    public:
    static int objcount;
    static float balance;
    Account(int a)
    {
        objcount++;
        if(objcount==1){
        cout<<"Enter the account number : ";
        cin>>anum;
        cout<<"Enter the customer name : ";
        cin>>name;
        }
    }



    void display(){
        cout<<"\nCurrent Balance is : "<<balance<<endl;
    }

};

class Savings:public Account
{
    static float minbal;
    public:
    Savings(int a):Account(a)
    {

    }

    void withdraw(){
        float wb;
        cout<<"Enter the amount to be withdrawn : ";
        cin>>wb;
        if(balance-wb<minbal){
            cout<<"\nInsufficient Balance!\n";
        }
        else{
            balance=balance-wb;
        }
    }

    void deposit(){
        float amt;
        cout<<"Enter the amount to be deposited : ";
        cin>>amt;
        balance=amt;
    }

};

class Current:public Account
{
    static float overdue;
    public:
    Current(int c):Account(c)
    {

    }
    void withdraw(){
        float wb;
        float rem;
        cout<<"Enter the amount to be withdrawn : ";
        cin>>wb;
        if(balance==0)
        {
            overdue=overdue-wb;
        }
        else if(balance<wb)
        {
            overdue=balance-wb;
            balance=balance-balance;
        }
        else 
        {
            balance=balance-wb;
        }
    }

    void deposit(){
        float amt;
        cout<<"Enter the amount to be deposited : ";
        cin>>amt;
        if(overdue<0)
        {
            if(amt>(-1)*overdue)
            {
                balance=amt+overdue;
                overdue=0;
            }
            else if(amt<(-1)*overdue)
            {
                balance=0;
                overdue=amt+overdue;
            }
        }
        else
        {
            balance=balance+amt;
        }
        
    }

    void displayoverdue(){
        cout<<"Overdue is : "<<overdue;
    }
};

float Account::balance=0;
float Savings::minbal=100;
float Current::overdue=0;
int Account::objcount=0;
int Account::anum;
string Account::name;

int main()
{
    int ch,chh;
    Current c(0);
    Savings s(0);
    
    while(1)
    {
        cout<<"\nBANKING\n";
        cout<<"\n1.FOR SAVINGS ACCOUNT\n";
        cout<<"\n2.FOR CURRENT ACCOUNT\n";
        cout<<"\n0.FOR CANCEL TRANSACTION\n";
        cout<<"\nENTER YOUR CHOICE : ";
        cin>>ch;
        switch (ch)
        {

        case 1:
            cout<<"\nSAVINGS ACCOUNT\n";
            while(2)
            {
                cout<<"\nBANKING\n";
                cout<<"\n1.WITHDRAW AMOUNT\n";
                cout<<"\n2.DEPOSIT AMOUNT\n";
                cout<<"\n3.DISPLAY BALANCE\n";
                cout<<"\n0.CANCEL TRANSACTION\n";
                cout<<"\nENTER YOUR CHOICE : ";
                cin>>chh;
                switch (chh)
                {
                case 1:
                    s.withdraw();
                    break;
                case 2:
                    s.deposit();
                    break;
                case 3:
                    s.display();
                    break;
                case 0:
                    exit(2);
                    break;
                default:
                    cout<<"\nIncorrect Entry! Enter Again!\n";
                    break;
                }
            }
            break;

        case 2:
            cout<<"\nCURRENT ACCOUNT\n";
            while(3)
            {
                cout<<"\nBANKING\n";
                cout<<"\n1.WITHDRAW AMOUNT\n";
                cout<<"\n2.DEPOSIT AMOUNT\n";
                cout<<"\n3.DISPLAY BALANCE\n";
                cout<<"\n4.DISPLAY OVERDUE\n";
                cout<<"\n0.CANCEL TRANSACTION\n";
                cout<<"\nENTER YOUR CHOICE : ";
                cin>>ch;
                switch (ch)
                {
                case 1:
                    c.withdraw();
                    break;
                case 2:
                    c.deposit();
                    break;
                case 3:
                    c.display();
                    break;
                case 4:
                    c.displayoverdue();
                    break;
                case 0:
                    exit(3);
                    break;
                default:
                    cout<<"\nIncorrect Entry! Enter Again!\n";
                    break;
                }
            }       
            
        case 0:
            exit(1);
            break;
        
        default:
            cout<<"\nIncorrect Entry! Enter Again!\n";
            break;
        }
    }
    return 0;
}