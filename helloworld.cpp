#include <iostream>

int main(void){
    int k = 8;
    int n = 9;
    int t;
    t = k;
    k = n;
    n = t; 
    std::cout<<k;
    return 0;
}