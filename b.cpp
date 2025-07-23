#include <iostream>
using namespace std;

int addone(int z){
    return z+1;
}

int main(void){
    int z;
    cout<< "enter:";
    cin >> z;
    z = addone(z);
    cout << z<<endl;
    return 0;
}