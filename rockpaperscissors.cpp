
#include <iostream>
#include <random>
#include <string>
using namespace std;

void printresult(int a){
    if (a == 1){
        cout<<"YOU WIN"<<endl;
    }else if(a == 2){
        cout<<"DRAW"<<endl;
    }else{
        cout<<"YOU LOOSE"<<endl;
    } 
}
void usermanual(void);
int gamelogic(char a,char z);
char input(void);
char inputvalidator(char a);
char computerplayer(void);

/**how is v0.2.2 */
int main(void){
    char a;
    char c;
    int s;
    usermanual();
    while(1){
        a = input();      
        if(a == 't'){
            cout<<"THANKS FOR PLAYING!!!"<<endl;
            return 0;
        }
        c = computerplayer();
        cout<<"computers turn: "<<c<<endl;
        s = gamelogic(a,c);
        printresult(s);
    }
}

int gamelogic(char a,char z){
    if(a == 'P'&& z == 'R'){
        return 1;
    }else if(a == 'R' && z == 'S'){
        return 1;
    }else if(a == 'S'&& z == 'P'){
        return 1;
    }else if(a == z){
        return 2;
    }else{
        return 0;
    }
}

char input(void){
    char a;
    cout<<"YOUR TURN: ";
    cin>>a;
    a = inputvalidator(a);
    if(a == 'R'|| a == 'P' || a=='S'){
        return a;
    }else{
        return 't';
    }
}

void usermanual(void){
    string z = "WELCOME\nFOR ROCK PRESS R\nFOR SCISSORS PRESS S\nFOR PAPER PRESS P\nTO EXIT PRESS ANY OTHER KEY";
    cout<<z<<endl;
}

char inputvalidator(char a){
    if(a == 'R'||a == 'S' || a == 'P'){
        return a;
    }else if(a == 'r'){
        return 'R';
    }else if(a == 's'){
        return 'S';
    }else if(a == 'p'){
        return 'P';
    }else{
        return 't';
    }
}

char computerplayer(void){
    char arr[3] = {'R','P','S'};
    mt19937 rng(std::random_device{}());
    uniform_int_distribution<int> die(0,2);
    char z = arr[die(rng)];
    return z;
}