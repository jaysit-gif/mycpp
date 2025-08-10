
#include <iostream>
#include <random>
#include <string>
using namespace std;

void win(void){
    cout<<"YOU WIN"<<endl;
}
char getQuitChoice() {
    char q;
    cout << "Do you wish to quit (y/n)? ";
    cin >> q;
    while (q != 'y' && q != 'n') {
        cout << "Please enter 'y' or 'n': ";
        cin >> q;
    }
    return q;
}
void usermanual(void);
void gamelogic(char a,char z);
char input(void);
char inputvalidator(char a);
char computerplayer(void);
/**how is v0.2 */
int main(void){
    char a;
    char c;
    usermanual();
    while(1){
        a = input();      
        if(a == 't'){
            cout<<"ERROR"<<endl;
            break;
        }
        c = computerplayer();
        gamelogic(a,c);
        if(getQuitChoice() == 'y'){
            break;
        }
    }

    return 0;
}

void gamelogic(char a,char z){
    cout<<"computers turn: "<<z<<endl;
    if(a == 'P'&& z == 'R'){
        win();
    }else if(a == 'R' && z == 'S'){
        win();
    }else if(a == 'S'&& z == 'P'){
        win();
    }else if(a == z){
        cout<<"DRAW"<<endl;
    }else{
        cout<<"YOU LOSE"<<endl;
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
    string z = "WELCOME\nFOR ROCK PRESS R\nFOR SCISSORS PRESS S\nFOR PAPER PRESS P\n";
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