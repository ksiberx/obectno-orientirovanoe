#include <iostream>
using namespace std;

class Vehicle {
public:
    virtual void startEngine() const { cout << "Engine started" << endl; }
    virtual double getMaxSpeed() const { return 0; }
    virtual void info() const { cout << "Vehicle" << endl; }
    virtual ~Vehicle() {}
};

class Car : public Vehicle {
public:
    void startEngine() const override { cout << "Car engine started" << endl; }
    double getMaxSpeed() const override { return 180; }
    void info() const override { cout << "Car" << endl; }
};

class ElectricCar : public Car {
public:
    void startEngine() const override { cout << "Electric motor started" << endl; }
    double getMaxSpeed() const override final { return 180; }
};

class Bicycle final : public Vehicle {
public:
    void startEngine() const override { cout << "No engine" << endl; }
    double getMaxSpeed() const override { return 25; }
};

int main() {
    Vehicle* v1 = new Car();
    Vehicle* v2 = new ElectricCar();
    Vehicle* v3 = new Bicycle();
    
    v1->startEngine();
    cout << "Speed: " << v1->getMaxSpeed() << endl;
    
    v2->startEngine();
    cout << "Speed: " << v2->getMaxSpeed() << endl;
    
    v3->startEngine();
    cout << "Speed: " << v3->getMaxSpeed() << endl;
    
    delete v1;
    delete v2;
    delete v3;
    return 0;
}
