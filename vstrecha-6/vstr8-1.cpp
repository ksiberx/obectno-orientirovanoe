#include <iostream>
#include <cstring>
using namespace std;

class Student {
private:
    char* name;
    int* grades;
    int count;

public:
    // Конструктор
    Student(const char* n, const int* g, int cnt) : count(cnt) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        
        grades = new int[count];
        for (int i = 0; i < count; i++)
            grades[i] = g[i];
    }
    
    // Конструктор переноса
    Student(Student&& other) noexcept 
        : name(other.name), grades(other.grades), count(other.count) {
        other.name = nullptr;
        other.grades = nullptr;
        other.count = 0;
    }
    
    // Деструктор
    ~Student() {
        delete[] name;
        delete[] grades;
    }
    
    void print() {
        cout << "Студент: " << name << ", оценки: ";
        for (int i = 0; i < count; i++)
            cout << grades[i] << " ";
        cout << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    int grades[] = {5, 4, 5};
    Student s1("Иван", grades, 3);
    Student s2 = move(s1);  // Вызов конструктора переноса
    
    s2.print();
    // s1.print() // Не вызываем - объект пустой
    return 0;
}
