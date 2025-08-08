#include <iostream>
#include <string>
using namespace std;

struct weight{
    double min;
    double max;
};

double converter(double x,string s);

double BMI(double weight,double height){
    if(height <= 0||weight <= 0){ 
        return -1;
    }
    return weight/(height*height);

}

void putBMI(double weight,double height){
    double bmi = BMI(weight,height);
    if(bmi==-1){
        cout<<"INVALID INPUT"<<endl;
    }
    else if (bmi < 18.5) {
        cout<<"BMI: "<<bmi<<endl;
        cout << "Category: Underweight" << endl;
    } else if (bmi >= 18.5 && bmi < 25) {
        cout<<"BMI: "<<bmi<<endl;
        cout << "Category: Normal weight" << endl;
    } else if (bmi >= 25 && bmi < 30) {
        cout<<"BMI: "<<bmi<<endl;
        cout << "Category: Overweight" << endl;
    } else {
        cout<<"BMI: "<<bmi<<endl;
        cout << "Category: Obese" << endl;
    }
}

weight maxhealthyweight(double height){
    weight t;
    t.min = 18.5*height*height;
    t.max = 25*height*height;
    return t;
}

void program(void){
    double w,z;
    string s,s1;
    cout<<"unit of weight: ";
    cin>>s;
    cout<<"WEIGHT: ";
    cin>>w;
    cout<<"unit of height: ";
    cin>>s1;
    cout<<"HEIGHT: ";
    cin>>z;
    w = converter(w,s);
    if(z > 0){
    z = converter(z,s1);
    if(w == -1||z == -1){
        cout<<"invalid conversion units"<<endl;
    }
    putBMI(w,z);
    weight t = maxhealthyweight(z);
    cout<<"MAX HEALTHY WEIGHT AT YOUR HEIGHT: "<<t.max<<endl<<"MIN HEALTHY WEIGHT AT YOUR HEIGHT: "<<t.min<<endl;
    }else{
        cout<<"INVALID HEIGHT"<<endl;
    }
}

int main(void){
    while(1){
        char q;
        program();
        cout<<"do you wish to quit(y/n)?? ";
        cin>>q;
        if(q == 'y'){
            return 0;
        }
    }
}

double converter(double x,string s){
   if(s == "cm"){
    return x/100;
   }else if(s == "gram"){
    return x/1000;
   }else if(s == "pound"){
    return 0.45359*x;
   }else if(s == "kg"||s == "metre"){ 
    return x;
   }else if(s == "meter"){
    return x;
   }else{
    return -1;
   }
}