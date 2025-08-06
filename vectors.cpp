#include <iostream>
#include <string>

class Car {
private:
    std::string brand;
    int speed;
    double fuelLevel;
public:
    static int totalCars;

    Car(std::string b, int s, double f) : brand(b), speed(s >= 0 ? s : 0), fuelLevel(f >= 0 && f <= 100 ? f : 0) {
        totalCars++;
    }

    ~Car() {
        totalCars--;
    }

    void refuel(double amount) {
        if (amount > 0) {
            fuelLevel += amount;
            if (fuelLevel > 100) fuelLevel = 100;
        }
    }

    void display() const {
        std::cout << "Brand: " << brand << ", Speed: " << speed << " km/h, Fuel: " << fuelLevel << "L" << std::endl;
    }
};

int Car::totalCars = 0;

int main() {
    Car car1("AUDI", 180, 50);
    car1.refuel(30);
    car1.display();

    Car car2("BMW", 200, 20);
    car2.refuel(90);
    car2.display();

    std::cout << "Total cars: " << Car::totalCars << std::endl;

    return 0;
}
     