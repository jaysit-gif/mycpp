#include <iostream>
#include <sstream>
using namespace std;

int main(void){
    int k = 0;
    string x;

    while(true){ 
        cout << "ENTER THE NUMBER or EXPRESSION: ";
        cin >> x;

        
        if(x == "q" || x == "Q"){
            break;
        }

    
        stringstream ss(x);
        int a, b;
        char op;

        if(ss >> a >> op >> b && ss.eof()){  
            switch(op){
                case '+': k = a + b; break;
                case '-': k = a - b; break;
                case '*': k = a * b; break;
                case '/': 
                    if(b == 0){
                        cout << "DIVIDE BY ZERO? NICE TRY HACKER.\n";
                        continue;
                    }
                    k = a / b; break;
                default:
                    cout << "UNKNOWN OPERATOR\n";
                    continue;
            }
        }
        else {
            try {
                k += stoi(x);  
            } catch(...) {
                cout << "INVALID INPUT, YOU GET NOTHING!\n";
                continue;
            }
        }
    }

    cout << "SOL: " << k << endl;
    return 0;
}