#include <iostream>
#include <vector>
#include <string>
using namespace std;

// КОМПОЗИЦИЯ 
// Пример 1 Дом и комнаты
class Room {
public:
    string name;
    Room(string n) : name(n) { cout << "Комната " << name << " создана\n"; }
    ~Room() { cout << "Комната " << name << " удалена\n"; }
};

class House {
private:
    vector<Room> rooms; // комнаты существуют только внутри дома
public:
    void addRoom(string name) { rooms.emplace_back(name); }
};

// Пример 2 Компьютер и процессор
class Processor {
public:
    string model;
    Processor(string m) : model(m) { cout << "Процессор " << model << " создан\n"; }
    ~Processor() { cout << "Процессор " << model << " удалён\n"; }
};

class Computer {
private:
    Processor* cpu;
public:
    Computer(string model) : cpu(new Processor(model)) {}
    ~Computer() { delete cpu; }
    Computer(const Computer&) = delete; // запрет копирования
};

// АГРЕГАЦИЯ
// Пример 1 Университет и студенты
class Student {
public:
    string name;
    Student(string n) : name(n) { cout << "Студент " << name << " создан\n"; }
    ~Student() { cout << "Студент " << name << " удалён\n"; }
};

class University {
private:
    vector<Student*> students; // только указатели, не владеет
public:
    void enroll(Student* s) { students.push_back(s); }
};

// Пример 2 Библиотека и книги
class Book {
public:
    string title;
    Book(string t) : title(t) { cout << "Книга " << title << " создана\n"; }
    ~Book() { cout << "Книга " << title << " удалена\n"; }
};

class Library {
private:
    vector<Book*> books;
public:
    void addBook(Book* b) { books.push_back(b); }
};

//  ТЕСТ
int main() {
    setlocale(LC_ALL, "ru");
    cout << "\n КОМПОЗИЦИЯ \n";
    House house;
    house.addRoom("Гостиная");
    house.addRoom("Спальня");
    
    Computer pc("Intel i7");
    
    cout << "\n АГРЕГАЦИЯ\n";
    Student alice("Алиса");
    Student bob("Боб");
    University univ;
    univ.enroll(&alice);
    univ.enroll(&bob);
    
    Book book1("Война и мир");
    Book book2("Преступление и наказание");
    Library lib;
    lib.addBook(&book1);
    lib.addBook(&book2);
    
    cout << "\nКОНЕЦ (уничтожение объектов) \n";
    return 0;
}
