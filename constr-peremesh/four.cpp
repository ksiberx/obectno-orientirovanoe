#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class Buffer {
private:
    char* data;
    size_t size;
    
public:
    // Конструктор
    Buffer(size_t s) : size(s) {
        cout << "Constructor" << endl;
        data = new char[size];
    }
    
    // Конструктор копирования
    Buffer(const Buffer& other) : size(other.size) {
        cout << "Copy constructor" << endl;
        data = new char[size];
        memcpy(data, other.data, size);
    }
    
    // Конструктор перемещения (НОВЫЙ)
    Buffer(Buffer&& other) noexcept : data(other.data), size(other.size) {
        cout << "Move constructor" << endl;
        other.data = nullptr;
        other.size = 0;
    }
    
    // Деструктор
    ~Buffer() {
        cout << "Destructor" << endl;
        delete[] data;
    }
    
    // Оператор присваивания копированием
    Buffer& operator=(const Buffer& other) {
        cout << "Copy assignment" << endl;
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new char[size];
            memcpy(data, other.data, size);
        }
        return *this;
    }
    
    // Оператор присваивания перемещением (НОВЫЙ)
    Buffer& operator=(Buffer&& other) noexcept {
        cout << "Move assignment" << endl;
        if (this != &other) {
            delete[] data;
            data = other.data;
            size = other.size;
            other.data = nullptr;
            other.size = 0;
        }
        return *this;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    cout << " Демонстрация эффективного перемещения " << endl;
    
    vector<Buffer> vec;
    
    cout << "\nДобавление временного объекта (push_back):" << endl;
    vec.push_back(Buffer(10));  // Должен вызвать конструктор перемещения
    
    cout << "\nСоздание объекта и перемещение:" << endl;
    Buffer buf(20);
    vec.push_back(move(buf));    // Явное перемещение
    
    cout << "\nКонец программы" << endl;
    
    return 0;
}
