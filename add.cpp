#include <iostream>
using namespace std;

double add(double a,double b){
    return a+b;
}

int main(void){
    double a,b;
    cout<<"A: ";
    cin>>a;
    cout<<"B: ";
    cin>>b;
    cout<<add(a,b)<<endl;
    return 0;
}
