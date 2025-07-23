#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

int main(void){
    int k = 0;
    string x;
    while(1){
        cout << "S: ";
        cin>>x;
        if(x == "q"||x == "Q"){
            break;
        }
        stringstream ss(x);
        int a,b;
        char op;
        if(ss>>a>>op>>b && ss.eof()){
            switch(op){
                case '+':k= a+b;break;
                case '-':k= a-b;break;
                case '*':k = a*b;break;
                case '/':
                    if(b == 0){
                        cout<<"ERROR"<<endl;
                        continue;
                    }
                    k = a/b;break;
                default:
                    cout<<"UNKNOWN OPERATOR";
                    continue;    
                      
            }
        }else{
            try{
                k += stoi(x);               
            }catch(...){
                cout<<"INVALID\n";
                continue;
            }

        }
    }
    
    cout<<"SOL:  "<<k<<endl;
    return 0;
}