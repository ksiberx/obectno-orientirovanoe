#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class String {
private:
    char* str;                 // Указатель на строку
    size_t size;               // Размер строки (включая '\0')
    static size_t objectCount; // Статический счетчик объектов

public:
    // Конструктор по умолчанию (строка 80 символов)
    String() : String(80) {
        // Делегирование конструктору с параметром
    }

    // Конструктор с размером (создает пустую строку указанного размера)
    explicit String(size_t length) : size(length + 1), str(new char[size]) {
        str[0] = '\0';
        ++objectCount;
        cout << "Создана строка размером " << length << " (конструктор с размером)\n";
    }

    // Конструктор с инициализацией от пользовательской строки
    String(const char* inputStr) {
        if (inputStr) {
            size = strlen(inputStr) + 1;
            str = new char[size];
            strcpy_s(str, size, inputStr);
        }
        else {
            size = 1;
            str = new char[size];
            str[0] = '\0';
        }
        ++objectCount;
        cout << "Создана строка из переданного значения (конструктор инициализации)\n";
    }

    // Конструктор копирования
    String(const String& other) : size(other.size), str(new char[size]) {
        strcpy_s(str, size, other.str);
        ++objectCount;
        cout << "Создана копия строки\n";
    }

    // Деструктор
    ~String() {
        delete[] str;
        --objectCount;
        cout << "Уничтожен объект String. Осталось объектов: " << objectCount << "\n";
    }

    // Метод ввода строки с клавиатуры
    void input() {
        cout << "Введите строку: ";
        string temp;
        getline(cin, temp);

        delete[] str;
        size = temp.length() + 1;
        str = new char[size];
        strcpy_s(str, size, temp.c_str());
    }

    // Метод вывода строки на экран
    void display() const {
        cout << "Строка: " << str << endl;
    }

    // Геттер для строки
    const char* c_str() const {
        return str;
    }

    // Геттер для размера
    size_t getSize() const {
        return size - 1; // Возвращаем длину строки без '\0'
    }

    // Статическая функция для получения количества объектов
    static size_t getObjectCount() {
        return objectCount;
    }
};

// Инициализация статического члена класса
size_t String::objectCount = 0;

// Демонстрационная функция
int main() {
    setlocale(LC_ALL, "Ru");

    cout << "Демонстрация работы класса String\n\n";

    cout << "Текущее количество объектов: " << String::getObjectCount() << "\n\n";

    // Использование конструктора по умолчанию (80 символов)
    cout << "--- Создание объекта s1 (конструктор по умолчанию) ---\n";
    String s1;
    cout << "Количество объектов после создания s1: " << String::getObjectCount() << "\n";

    // Использование конструктора с размером
    cout << "\n--- Создание объекта s2 (строка на 50 символов) ---\n";
    String s2(50);
    cout << "Количество объектов: " << String::getObjectCount() << "\n";

    // Использование конструктора инициализации
    cout << "\n--- Создание объекта s3 (инициализация строкой) ---\n";
    String s3("Привет, мир!");
    cout << "Количество объектов: " << String::getObjectCount() << "\n";

    // Демонстрация методов ввода/вывода
    cout << "\n--- Демонстрация методов ---\n";
    cout << "s3: ";
    s3.display();

    cout << "\n--- Ввод строки для s1 ---\n";
    s1.input();
    s1.display();

    // Демонстрация конструктора копирования
    cout << "\n--- Создание копии s4 из s3 ---\n";
    String s4(s3);
    cout << "s4: ";
    s4.display();

    // Показываем финальное количество объектов
    cout << "\n------ Информация о количестве объектов ------\n";
    cout << "Всего создано объектов: " << String::getObjectCount() << "\n";

    cout << "\n------ Завершение программы (объекты будут уничтожены) ------\n";

    return 0;
}
