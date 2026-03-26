#include <iostream>
#include <string>
using namespace std;

//  СТЕК 
template<typename T>
class Stack {
    T* arr;
    size_t cap, top_idx;
    
    void resize() {
        cap *= 2;
        T* new_arr = new T[cap];
        for (size_t i = 0; i < top_idx; i++) new_arr[i] = arr[i];
        delete[] arr;
        arr = new_arr;
    }
    
public:
    Stack(size_t init_cap = 10) : cap(init_cap), top_idx(0) {
        arr = new T[cap];
    }
    
    ~Stack() { delete[] arr; }
    
    Stack(const Stack& other) : cap(other.cap), top_idx(other.top_idx) {
        arr = new T[cap];
        for (size_t i = 0; i < top_idx; i++) arr[i] = other.arr[i];
    }
    
    Stack& operator=(const Stack& other) {
        if (this != &other) {
            delete[] arr;
            cap = other.cap;
            top_idx = other.top_idx;
            arr = new T[cap];
            for (size_t i = 0; i < top_idx; i++) arr[i] = other.arr[i];
        }
        return *this;
    }
    
    void push(const T& val) {
        if (top_idx == cap) resize();
        arr[top_idx++] = val;
    }
    
    void pop() { if (top_idx > 0) top_idx--; }
    T& top() { return arr[top_idx - 1]; }
    bool empty() const { return top_idx == 0; }
    size_t size() const { return top_idx; }
};

//  ОЧЕРЕДЬ 
template<typename T>
class Queue {
    T* arr;
    size_t cap, front_idx, back_idx, sz;
    
    void resize() {
        size_t new_cap = cap * 2;
        T* new_arr = new T[new_cap];
        for (size_t i = 0; i < sz; i++) {
            new_arr[i] = arr[(front_idx + i) % cap];
        }
        delete[] arr;
        arr = new_arr;
        front_idx = 0;
        back_idx = sz;
        cap = new_cap;
    }
    
public:
    Queue(size_t init_cap = 10) : cap(init_cap), front_idx(0), back_idx(0), sz(0) {
        arr = new T[cap];
    }
    
    ~Queue() { delete[] arr; }
    
    void enqueue(const T& val) {
        if (sz == cap) resize();
        arr[back_idx] = val;
        back_idx = (back_idx + 1) % cap;
        sz++;
    }
    
    void dequeue() {
        if (sz > 0) {
            front_idx = (front_idx + 1) % cap;
            sz--;
        }
    }
    
    T& front() { return arr[front_idx]; }
    bool empty() const { return sz == 0; }
    size_t size() const { return sz; }
};

//  ТЕСТИРОВАНИЕ 
int main() {
    setlocale(LC_ALL, "ru");
    // 1. Стек для проверки палиндрома
    cout <<  Проверка палиндромов \n";
    string words[] = {"radar", "hello", "level", "world"};
    
    for (string word : words) {
        Stack<char> st;
        for (char c : word) st.push(c);
        
        bool is_palindrome = true;
        for (char c : word) {
            if (c != st.top()) { is_palindrome = false; break; }
            st.pop();
        }
        cout << word << " - " << (is_palindrome ? "палиндром" : "не палиндром") << endl;
    }
    
    // 2. Очередь задач
    cout << "\n Очередь задач \n";
    Queue<int> tasks;
    
    tasks.enqueue(1);
    tasks.enqueue(2);
    tasks.enqueue(3);
    tasks.enqueue(4);
    
    cout << "Порядок обработки: ";
    while (!tasks.empty()) {
        cout << tasks.front() << " ";
        tasks.dequeue();
    }
    
    return 0;
}
