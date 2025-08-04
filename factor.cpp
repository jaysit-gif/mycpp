#include <iostream>
using namespace std;

void printarray(int arr[],int size){
    for(int i = 0;i<size;i++){
        cout<<arr[i]<<endl;
    }
}

int main(void){
    int z = 2148;
    int arr[12];
    int k = 0;  
    for(int i = 1;i<=z;i++){
        if(z % i == 0){
            arr[k] = i;
            k++;
        }
    }
    printarray(arr,12);
    return 0;
}
