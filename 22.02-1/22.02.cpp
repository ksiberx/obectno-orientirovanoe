#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

class Contact {
private:
    char* fio;                  // динамическая строка ФИО
    string homePhone;           // домашний телефон
    string workPhone;           // рабочий телефон
    string mobilePhone;         // мобильный телефон
    string info;                // дополнительная информация

public:
    Contact() { fio = nullptr; }   // конструктор по умолчанию

    Contact(const char* f, string h, string w, string m, string i) {
        fio = new char[strlen(f) + 1];   // выделяем память под ФИО
#ifdef _MSC_VER
        strcpy_s(fio, strlen(f) + 1, f); // копируем ФИО (безопасный вариант для MSVC)
#else
        strcpy(fio, f);                  // копируем ФИО
#endif
        homePhone = h;                   // сохраняем данные
        workPhone = w;
        mobilePhone = m;
        info = i;
    }

    ~Contact() { delete[] fio; }         // освобождаем память

    void print() {                       // вывод информации
        cout << "\nФИО: " << fio << endl;
        cout << "Дом: " << homePhone << endl;
        cout << "Раб: " << workPhone << endl;
        cout << "Моб: " << mobilePhone << endl;
        cout << "Инфо: " << info << endl;
        cout << "----------------------\n";
    }

    const char* getFio() { return fio; } // вернуть ФИО

    void save(ofstream& out) {           // сохранение в файл
        out << fio << endl;              // записываем ФИО
        out << homePhone << endl;        // записываем телефоны
        out << workPhone << endl;
        out << mobilePhone << endl;
        out << info << endl;             // записываем доп. инфо
    }

    void load(ifstream& in) {            // загрузка из файла
        char buffer[100];
        in.getline(buffer, 100);         // читаем ФИО

        delete[] fio;                   // очищаем старую память
        fio = new char[strlen(buffer) + 1]; // выделяем новую
#ifdef _MSC_VER
        strcpy_s(fio, strlen(buffer) + 1, buffer); // копируем ФИО (safe for MSVC)
#else
        strcpy(fio, buffer);            // копируем ФИО
#endif

        getline(in, homePhone);         // читаем телефоны
        getline(in, workPhone);
        getline(in, mobilePhone);
        getline(in, info);              // читаем инфо
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    Contact* book = new Contact[100];   // массив из 100 контактов
    int count = 0;                      // текущее количество
    int choice;                         // выбор пользователя

    do {
        cout << "\n1. Добавить\n";
        cout << "2. Показать всех\n";
        cout << "3. Поиск по ФИО\n";
        cout << "4. Удалить\n";
        cout << "5. Сохранить\n";
        cout << "6. Загрузить\n";
        cout << "0. Выход\n";
        cout << "Выбор: ";

        cin >> choice;
        cin.ignore();                   // очищаем Enter

        switch (choice) {

        case 1: {                       // добавление
            char fio[100];
            string h, w, m, i;

            cout << "ФИО: ";
            cin.getline(fio, 100);

            cout << "Дом: ";
            getline(cin, h);

            cout << "Раб: ";
            getline(cin, w);

            cout << "Моб: ";
            getline(cin, m);

            cout << "Инфо: ";
            getline(cin, i);

            book[count++] = Contact(fio, h, w, m, i);  // создаем объект
            break;
        }

        case 2:                         // показать всех
            for (int j = 0; j < count; j++)
                book[j].print();
            break;

        case 3: {                       // поиск
            char search[100];
            cout << "Введите ФИО: ";
            cin.getline(search, 100);

            for (int j = 0; j < count; j++)
                if (strcmp(book[j].getFio(), search) == 0)
                    book[j].print();     // вывод найденного
            break;
        }

        case 4: {                       // удаление
            char del[100];
            cout << "Введите ФИО для удаления: ";
            cin.getline(del, 100);

            for (int j = 0; j < count; j++) {
                if (strcmp(book[j].getFio(), del) == 0) {
                    for (int k = j; k < count - 1; k++)
                        book[k] = book[k + 1];  // сдвигаем массив
                    count--;                   // уменьшаем количество
                    cout << "Удалено!\n";
                    break;
                }
            }
            break;
        }

        case 5: {                       // сохранение
            ofstream out("book.txt");
            out << count << endl;       // записываем количество
            for (int j = 0; j < count; j++)
                book[j].save(out);
            out.close();
            cout << "Сохранено в файл!\n";
            break;
        }

        case 6: {                       // загрузка
            ifstream in("book.txt");
            in >> count;                // читаем количество
            in.ignore();                // убираем Enter
            for (int j = 0; j < count; j++)
                book[j].load(in);
            in.close();
            cout << "Загружено из файла!\n";
            break;
        }

        case 0:
            cout << "Выход...\n";
            break;

        default:
            cout << "Неверный выбор!\n"; // если ввели не то
        }

    } while (choice != 0);

    delete[] book;                      // освобождаем память массива
    return 0;
}
