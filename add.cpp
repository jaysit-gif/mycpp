#include <iostream>
using namespace std;

double add(double a,double b){
    return a+b;
}

int main(void){
    double a = add(3,2);
    cout<<add(4,3)<<endl;
    cout<<add(a,5)<<endl;
    return 0;
}
