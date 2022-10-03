#include <iostream>
using namespace std;

class tollbooth{
    static int totalcars;
    static double totalmoney;
    static int paycars;
    static int nonpaycars;

    public:

    void getdata(tollbooth t){
            cout<<"----Welcome To BBSR----"<<endl;
            while(1){
            int ch;
            cout<<"\nPress 0 for Non-Paying Car."<<endl;
            cout<<"\nPress 1 for Paying Car."<<endl;
            cout<<"\nPress 2 To Show Data."<<endl;
            cout<<"\nPress 9 to Exit."<<endl;
            cout<<"\nEnter your choice : ";
            cin>>ch;
            switch (ch)
            {
            case 0:
                t.nonpayingcar();
                break;
            case 1:
                t.payingcar();
                break;
            case 2:
                t.show();
                break;            
            case 9:
                cout<<"Thank You! Happy Journey!"<<endl;
                exit(1);
                break;
            default:
                cout<<"\nIncorrect Entry!!!!\nEnter again!!!!"<<endl;
                break;
            }
        }

    } 
    

    void payingcar(){
        totalcars++;
        paycars++;
        double pay=0.5;
        totalmoney=totalmoney+pay;
    }

    void nonpayingcar(){
        totalcars++;
        nonpaycars++;
        double nonpay=0;
        totalmoney=totalmoney+nonpay;
    }

    void show(){
        cout<<"\nTotal Numbers of cars crossed is : "<<totalcars<<endl;
        cout<<"\nTotal Numbers of Paying Cars crossed is : "<<paycars<<endl;
        cout<<"\nTotal Numbers of Non-Paying Cars crossed is : "<<nonpaycars<<endl;
        cout<<"\nTotal Money Collected is : "<<"Rs. "<<totalmoney<<endl;
    }
};

int tollbooth::totalcars=0;
double tollbooth::totalmoney=0;
int tollbooth::paycars=0;
int tollbooth::nonpaycars=0;

int main(){
    tollbooth t1;
    t1.getdata(t1);
}