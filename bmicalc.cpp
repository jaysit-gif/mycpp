#include <iostream>
#include <string>
using namespace std;

double converter(double x,string s);

double BMI(double weight,double height){
    if(height <= 0||weight <= 0){ //error handling for zero value
        return -1;
    }
    return weight/(height*height);/**did it for faster calculation */

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

double maxhealthyweight(double height){
    return 25*height*height;
}
/**hows the new version?? */
int main(void){
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
    z = converter(z,s1);
    if(w == 1||z == 1){
        cout<<"invalid conversion units"<<endl;
        return 1;
    }
    putBMI(w,z);
    cout<<"MAX HEALTHY WEIGHT AT YOUR HEIGHT "<<maxhealthyweight(z);
    return 0;
}

double converter(double x,string s){
   if(s == "cm"){
    return x/100;
   }else if(s == "gram"){
    return x/1000;
   }else if(s == "pound"){
    return 0.45359*x;
   }else if(s == "meter"||s == "kg"||s == "metre"){ //program recognizes both meter and metre
    return x;
   }else{
    return 1;
   }
}