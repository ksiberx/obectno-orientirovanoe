#include <iostream>
#include <cstring>
using namespace std;

class IntArray {
private:
    int* data;      // Указатель на динамический массив
    size_t size;    // Количество элементов

public:
    // Конструктор по умолчанию - создаёт пустой массив
    IntArray() : data(nullptr), size(0) {
        cout << "Default constructor" << endl;
    }
    
    // Конструктор от size_t n - выделяет память под n элементов
    explicit IntArray(size_t n) : size(n) {
        cout << "Constructor with size" << endl;
        data = new int[size];
        for (size_t i = 0; i < size; i++)
            data[i] = 0;  // Заполняем нулями
    }
    
    // Конструктор копирования - глубокое копирование
    IntArray(const IntArray& other) : size(other.size) {
        cout << "Copy constructor" << endl;
        data = new int[size];
        for (size_t i = 0; i < size; i++)
            data[i] = other.data[i];  // Копируем все элементы
    }
    
    // Конструктор перемещения - передача владения ресурсом
    IntArray(IntArray&& other) noexcept : data(other.data), size(other.size) {
        cout << "Move constructor" << endl;
        other.data = nullptr;  // Обнуляем источник
        other.size = 0;
    }
    
    // Деструктор - освобождает память
    ~IntArray() {
        cout << "Destructor" << endl;
        delete[] data;
    }
    
    // Оператор присваивания копированием
    IntArray& operator=(const IntArray& other) {
        cout << "Copy assignment" << endl;
        if (this != &other) {  // Проверка на самоприсваивание
            delete[] data;  // Освобождаем старую память
            
            size = other.size;
            data = new int[size];
            for (size_t i = 0; i < size; i++)
                data[i] = other.data[i];
        }
        return *this;
    }
    
    // Оператор присваивания перемещением
    IntArray& operator=(IntArray&& other) noexcept {
        cout << "Move assignment" << endl;
        if (this != &other) {
            delete[] data;  // Освобождаем старую память
            
            data = other.data;  // Забираем ресурс
            size = other.size;
            
            other.data = nullptr;  // Обнуляем источник
            other.size = 0;
        }
        return *this;
    }
    
    // Метод для вывода элементов массива
    void print() const {
        cout << "[";
        for (size_t i = 0; i < size; i++) {
            cout << data[i];
            if (i < size - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    cout << " Демонстрация работы IntArray " << endl << endl;
    
    // 1. Создание объекта
    cout << "1. Создание объекта arr1 (5 элементов):" << endl;
    IntArray arr1(5);
    arr1.print();
    cout << endl;
    
    // 2. Копирование (lvalue)
    cout << "2. Копирование arr1 в arr2 (конструктор копирования):" << endl;
    IntArray arr2 = arr1;  // Вызов конструктора копирования
    arr2.print();
    cout << endl;
    
    // 3. Перемещение из временного объекта
    cout << "3. Перемещение из временного объекта в arr3:" << endl;
    IntArray arr3 = IntArray(3);  // Вызов конструктора перемещения
    arr3.print();
    cout << endl;
    
    // 4. Перемещение с помощью std::move
    cout << "4. Перемещение с помощью std::move (arr4 = move(arr3)):" << endl;
    IntArray arr4 = move(arr3);  // Вызов конструктора перемещения
    arr4.print();
    cout << "Состояние arr3 после перемещения: ";
    arr3.print();  // Должен быть пустым
    cout << endl;
    
    // 5. Присваивание копированием
    cout << "5. Присваивание копированием (arr5 = arr4):" << endl;
    IntArray arr5;
    arr5 = arr4;  // Вызов оператора присваивания копированием
    arr5.print();
    cout << endl;
    
    // 6. Присваивание перемещением
    cout << "6. Присваивание перемещением (arr6 = move(arr5)):" << endl;
    IntArray arr6;
    arr6 = move(arr5);  // Вызов оператора присваивания перемещением
    arr6.print();
    cout << "Состояние arr5 после перемещения: ";
    arr5.print();  // Должен быть пустым
    cout << endl;
    
    cout << "=== Конец программы (деструкторы) ===" << endl;
    return 0;
}
