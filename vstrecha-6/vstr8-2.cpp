#include <iostream>
#include <cstring>
using namespace std;

class Human {
private:
    char* name;
    int age;
    
public:
    Human(const char* n, int a) : age(a) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }
    
    // Конструктор переноса
    Human(Human&& other) noexcept 
        : name(other.name), age(other.age) {
        other.name = nullptr;
        other.age = 0;
    }
    
    ~Human() { delete[] name; }
    
    void print() const {
        cout << name << " (" << age << " лет)";
    }
};

class Apartment {
private:
    Human** residents;
    int numResidents;
    
public:
    Apartment(Human** r, int n) : numResidents(n) {
        residents = new Human*[n];
        for (int i = 0; i < n; i++)
            residents[i] = r[i];
    }
    
    // Конструктор переноса
    Apartment(Apartment&& other) noexcept 
        : residents(other.residents), numResidents(other.numResidents) {
        other.residents = nullptr;
        other.numResidents = 0;
    }
    
    ~Apartment() { delete[] residents; }
    
    void print() const {
        cout << "Жильцы (" << numResidents << "): ";
        for (int i = 0; i < numResidents; i++) {
            residents[i]->print();
            cout << " ";
        }
    }
};

class House {
private:
    Apartment** apartments;
    int numApartments;
    char* address;
    
public:
    House(Apartment** a, int n, const char* addr) : numApartments(n) {
        address = new char[strlen(addr) + 1];
        strcpy(address, addr);
        
        apartments = new Apartment*[n];
        for (int i = 0; i < n; i++)
            apartments[i] = a[i];
    }
    
    // Конструктор переноса
    House(House&& other) noexcept 
        : apartments(other.apartments), 
          numApartments(other.numApartments),
          address(other.address) {
        other.apartments = nullptr;
        other.numApartments = 0;
        other.address = nullptr;
    }
    
    ~House() {
        delete[] address;
        delete[] apartments;
    }
    
    void print() const {
        cout << "Дом по адресу: " << address << endl;
        for (int i = 0; i < numApartments; i++) {
            cout << "Кв " << i + 1 << ": ";
            apartments[i]->print();
            cout << endl;
        }
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    // Создаем людей
    Human h1("Иван", 30);
    Human h2("Мария", 28);
    Human h3("Петр", 10);
    
    // Создаем квартиры
    Human* apt1_res[] = {&h1, &h2};
    Human* apt2_res[] = {&h3};
    
    Apartment apt1(apt1_res, 2);
    Apartment apt2(apt2_res, 1);
    
    // Создаем дом
    Apartment* house_apts[] = {&apt1, &apt2};
    House house1(house_apts, 2, "ул. Ленина, 1");
    
    // Переносим дом
    House house2 = move(house1);
    
    house2.print();
    
    return 0;
}
