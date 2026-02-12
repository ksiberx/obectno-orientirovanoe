#include <iostream>      // ввод и вывод
#include <fstream>       // работа с файлами
using namespace std;     // чтобы не писать std::

const int MAX = 10;      // максимальное количество студентов и предметов

class Subject {
public:
    char name[20];       // название предмета
};

class Student {
public:
    char name[20];       // имя студента
    int grades[MAX];     // оценки по предметам
};

class Group {
public:
    Student students[MAX];   // массив студентов
    Subject subjects[MAX];   // массив предметов
    int sc, pc;              // sc — число студентов, pc — число предметов
};

int main() {
    setlocale(LC_ALL, "ru");
    Group g;                  // создаём группу
    ifstream fs, fp, fg;      // файловые потоки

    fs.open("students.txt");  // открываем файл студентов
    fs >> g.sc;               // считываем количество студентов
    for (int i = 0; i < g.sc; i++)
        fs >> g.students[i].name; // считываем имена студентов
    fs.close();               // закрываем файл

    fp.open("subjects.txt");  // открываем файл предметов
    fp >> g.pc;               // считываем количество предметов
    for (int i = 0; i < g.pc; i++)
        fp >> g.subjects[i].name; // считываем названия предметов
    fp.close();               // закрываем файл

    fg.open("grades.txt");    // открываем файл оценок
    for (int i = 0; i < g.sc; i++)
        for (int j = 0; j < g.pc; j++)
            fg >> g.students[i].grades[j]; // считываем оценки
    fg.close();               // закрываем файл

    // вывод таблицы оценок
    for (int i = 0; i < g.sc; i++) {
        cout << g.students[i].name << ": "; // вывод имени студента
        for (int j = 0; j < g.pc; j++)
            cout << g.students[i].grades[j] << " "; // оценки
        cout << endl;        // переход на новую строку
    }

    // средний балл каждого студента
    for (int i = 0; i < g.sc; i++) {
        double s = 0;        // сумма оценок
        for (int j = 0; j < g.pc; j++)
            s += g.students[i].grades[j]; // складываем оценки
        cout << "Средний балл " << g.students[i].name
            << ": " << s / g.pc << endl; // вывод среднего
    }

    // средние, максимальные и минимальные оценки по предметам
    for (int j = 0; j < g.pc; j++) {
        int min = g.students[0].grades[j]; // начальный минимум
        int max = min;                     // начальный максимум
        int imin = 0, imax = 0;            // индексы студентов
        double sum = 0;                    // сумма оценок

        for (int i = 0; i < g.sc; i++) {
            int v = g.students[i].grades[j]; // текущая оценка
            sum += v;                         // добавляем к сумме
            if (v < min) { min = v; imin = i; } // поиск минимума
            if (v > max) { max = v; imax = i; } // поиск максимума
        }

        cout << g.subjects[j].name << ": ср="
            << sum / g.sc                 // средняя по предмету
            << " max=" << max << " (" << g.students[imax].name << ")"
            << " min=" << min << " (" << g.students[imin].name << ")"
            << endl;                      // вывод результатов
    }

    return 0;                              // завершение программы
}
