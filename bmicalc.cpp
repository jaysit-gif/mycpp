#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <limits>

using namespace std;

const double POUND_TO_KG = 0.453592;
const double GRAM_TO_KG = 0.001;
const double CM_TO_M = 0.01;
const double FEET_TO_M = 0.3048;
const double BMI_UNDERWEIGHT = 18.5;
const double BMI_NORMAL_MAX = 25.0;

struct Measurement {
    double height; // in meters
    double weight; // in kg
};

string toLowerCase(const string& s) {
    string result = s;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

double convertweight(double x, string s) {
    s = toLowerCase(s);
    if (s == "pound") return POUND_TO_KG * x;
    if (s == "gram") return GRAM_TO_KG * x;
    if (s == "kg") return x;
    return -1;
}

double convertheight(double x, string s) {
    s = toLowerCase(s);
    if (s == "cm") return CM_TO_M * x;
    if (s == "feet") return FEET_TO_M * x;
    if (s == "metre" || s == "meter" || s == "m") return x;
    return -1;
}

Measurement convert(double height, double weight, string heightUnit, string weightUnit) {
    Measurement t;
    t.height = convertheight(height, heightUnit);
    t.weight = convertweight(weight, weightUnit);
    return t;
}

double BMI(double weight, double height) {
    if (height <= 0 || weight <= 0) {
        return -1;
    }
    return weight / (height * height);
}

void putBMI(double bmi) {
    cout << fixed << setprecision(3);
    if (bmi == -1) {
        cout << "INVALID INPUT" << endl;
    } else if (bmi < BMI_UNDERWEIGHT) {
        cout << "BMI: " << bmi << endl;
        cout << "Category: Underweight" << endl;
    } else if (bmi < BMI_NORMAL_MAX) {
        cout << "BMI: " << bmi << endl;
        cout << "Category: Normal weight" << endl;
    } else if (bmi < 30) {
        cout << "BMI: " << bmi << endl;
        cout << "Category: Overweight" << endl;
    } else {
        cout << "BMI: " << bmi << endl;
        cout << "Category: Obese" << endl;
    }
}

Measurement healthyweight(double height) {
    Measurement t;
    t.height = BMI_UNDERWEIGHT * height * height; // min weight
    t.weight = BMI_NORMAL_MAX * height * height;  // max weight
    return t;
}

double getValidNumber(const string& prompt) {
    double value;
    cout << prompt;
    while (!(cin >> value)) {
        cout << "Invalid input. Please enter a number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return value;
}

Measurement input(void) {
    double weight = getValidNumber("WEIGHT (kg, pound, gram): ");
    string weightUnit;
    cin >> weightUnit;
    double height = getValidNumber("HEIGHT (meter, cm, feet): ");
    string heightUnit;
    cin >> heightUnit;
    if (height <= 0 || weight <= 0) {
        Measurement t = {-1, -1};
        return t;
    }
    return convert(height, weight, heightUnit, weightUnit);
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

void program(void) {
    Measurement t = input();
    if (t.height == -1 || t.weight == -1) {
        if (t.height == -1) {
            cout << "INVALID HEIGHT or HEIGHT UNITS" << endl;
        }
        if (t.weight == -1) {
            cout << "INVALID WEIGHT or WEIGHT UNITS" << endl;
        }
        return;
    }
    double bmi = BMI(t.weight, t.height);
    putBMI(bmi);
    if (bmi != -1) {
        Measurement a = healthyweight(t.height);
        cout << "MAXIMUM HEALTHY WEIGHT AT YOUR HEIGHT: " << a.weight << " kg" << endl;
        cout << "MINIMUM HEALTHY WEIGHT AT YOUR HEIGHT: " << a.height << " kg" << endl;
    }
}

int main(void) {
    while (true) {
        program();
        if (getQuitChoice() == 'y') {
            return 0;
        }
    }
}
