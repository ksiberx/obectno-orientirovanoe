#include <iostream>
#include <vector>

using namespace std;

class Animal {
public:
    virtual void speak() const {
        cout << "I am an animal" << endl;
    }
};

class Dog : public Animal {
public:
    void speak() const override {
        cout << "Woof! Woof!" << endl;
    }
};

class Cat : public Animal {
public:
    void speak() const override {
        cout << "Meow!" << endl;
    }
};

class Cow : public Animal {
public:
    void speak() const override {
        cout << "Moo!" << endl;
    }
};

class Horse : public Animal {
public:
    void speak() const override {
        cout << "Neigh!" << endl;
    }
};

// Дополнительное задание: класс Bird
class Bird : public Animal {
public:
    void speak() const override {
        cout << "Chirik!" << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    vector<Animal*> animals;
    
    animals.push_back(new Dog());
    animals.push_back(new Cat());
    animals.push_back(new Cow());
    animals.push_back(new Horse());
    animals.push_back(new Bird()); // дополнительное задание
    
    for (const auto& animal : animals) {
        animal->speak();
    }
    
    // Освобождение памяти
    for (auto& animal : animals) {
        delete animal;
    }
    
    return 0;
}
