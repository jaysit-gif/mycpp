
#include <iostream>
#include <random>
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
void gamelogic(void);

/**how is v0.1 */
int main(void){
    while(1){
        gamelogic();
        if(getQuitChoice() == 'y'){
            break;
        }
    }

    return 0;
}

void gamelogic(void){
    char arr[3] = {'R','P','S'};
    char a;
    cout<<"YOUR TURN: ";
    cin>>a;
    mt19937 rng(std::random_device{}());
    uniform_int_distribution<int> die(0,2);
    char z = arr[die(rng)];
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