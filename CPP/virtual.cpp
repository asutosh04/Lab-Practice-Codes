
#include <iostream>
using namespace std;
class student{
    int roll;
    string name;
    string branch;
    public:
    void getstudent(){
        cout<<"Enter the (roll , name , branch) : ";
        cin>>roll>>name>>branch;
    }
};

class internal:public student{
    protected:
    int internals;
    public:
    internal(){
    getstudent();
    cout<<"Enter the internal marks out of 30 : ";
    cin>>internals;
    }
};

class midsem:public student{
    protected:
    int mid;
    public:
    midsem(){
    cout<<"Enter the midsem marks out of 20 : ";
    cin>>mid;
    }
};

class endsem:public student{
    protected:
    int end;
    public:
    endsem(){
    cout<<"Enter the endsem marks out of 50 : ";
    cin>>end;
    }

};

class result:virtual public internal,public midsem,public endsem{
    int total;
    float per;
    public:
    void display(){
        total=internals+mid+end;
        per=total/100*100;
        cout<<"Total Marks is : "<<total<<endl;
        cout<<"Percentage is : "<<per<<endl;
    }
};

int main(){
    result r1;
    r1.display();
}
