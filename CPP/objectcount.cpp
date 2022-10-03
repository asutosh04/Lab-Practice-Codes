#include <iostream>
using namespace std;

class nobj{
    int num;
    static int count;
    public:
    nobj(){
        count++;
    }
    void getcount(){
        cout<<"Count = "<<count<<endl;
    }
};

int nobj::count;

int main(){
    nobj o1;
    o1.getcount();

    nobj o2;
    o2.getcount();
    return 0;
}