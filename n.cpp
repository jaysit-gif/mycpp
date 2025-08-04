#include <iostream>
using namespace std;

float d(float a,float b = 1){
    float z = a/b;
    return z;
}

int main(void){
    int z;
    int k = 1;
    while(k != 0){
        cout<<"ENTER:";
        cin>>z;
        if(z == 18){
            cout<<"congratulations"<<endl;
            break;
        }else{
            cout<<"better luck next time"<<endl;
        }
    }
    return 0;
}