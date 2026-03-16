#include <iostream>
using namespace std;

template <typename T>
class Array {
private:
    T* data;
    int size;
    int count;
    int grow;

public:
    Array() : data(nullptr), size(0), count(0), grow(1) {}
    
    ~Array() { if (data) delete[] data; }
    
    int GetSize() { return size; }
    
    void SetSize(int newSize, int newGrow = 1) {
        grow = newGrow;
        T* newData = new T[newSize];
        for (int i = 0; i < count && i < newSize; i++) 
            newData[i] = data[i];
        delete[] data;
        data = newData;
        size = newSize;
        if (count > size) count = size;
    }
    
    int GetUpperBound() { return count - 1; }
    
    bool IsEmpty() { return count == 0; }
    
    void FreeExtra() {
        if (count < size) SetSize(count, grow);
    }
    
    void RemoveAll() {
        delete[] data;
        data = nullptr;
        size = count = 0;
    }
    
    T GetAt(int index) { return data[index]; }
    
    void SetAt(int index, T value) { 
        data[index] = value; 
        if (index >= count) count = index + 1;
    }
    
    T& operator[](int index) { 
        if (index >= count) count = index + 1;
        return data[index]; 
    }
    
    void Add(T value) {
        if (count >= size) SetSize(size + grow, grow);
        data[count++] = value;
    }
    
    Array<T> Append(Array<T>& other) {
        Array<T> res;
        res.SetSize(count + other.count, grow);
        for (int i = 0; i < count; i++) res.Add(data[i]);
        for (int i = 0; i < other.count; i++) res.Add(other.data[i]);
        return res;
    }
    
    Array<T>& operator=(Array<T>& other) {
        if (this != &other) {
            RemoveAll();
            SetSize(other.size, other.grow);
            for (int i = 0; i < other.count; i++) Add(other.data[i]);
        }
        return *this;
    }
    
    T* GetData() { return data; }
    
    void InsertAt(T value, int pos) {
        if (count >= size) SetSize(size + grow, grow);
        for (int i = count; i > pos; i--) data[i] = data[i - 1];
        data[pos] = value;
        count++;
    }
    
    void RemoveAt(int pos) {
        for (int i = pos; i < count - 1; i++) data[i] = data[i + 1];
        count--;
    }
    
    void Print() {
        for (int i = 0; i < count; i++) cout << data[i] << " ";
        cout << endl;
    }
};

int main() {
    setlocale(LC_aLL, "RU");
    // Проверка работы
    Array<int> arr;
    
    arr.Add(10);
    arr.Add(20);
    arr.Add(30);
    arr.Print(); // 10 20 30
    
    arr.InsertAt(99, 1);
    arr.Print(); // 10 99 20 30
    
    arr.RemoveAt(2);
    arr.Print(); // 10 99 30
    
    arr[0] = 777;
    cout << arr[0] << endl; // 777
    
    return 0;
}
