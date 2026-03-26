#include <iostream>
#include <string>
using namespace std;

template<typename T>
class SinglyLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& val) : data(val), next(nullptr) {}
    };
    Node* head = nullptr;
    size_t sz = 0;
    
public:
    ~SinglyLinkedList() { clear(); }
    
    void push_front(const T& val) {
        Node* n = new Node(val);
        n->next = head;
        head = n;
        sz++;
    }
    
    void push_back(const T& val) {
        Node* n = new Node(val);
        if (!head) head = n;
        else {
            Node* cur = head;
            while (cur->next) cur = cur->next;
            cur->next = n;
        }
        sz++;
    }
    
    void pop_front() {
        if (!head) return;
        Node* tmp = head;
        head = head->next;
        delete tmp;
        sz--;
    }
    
    void pop_back() {
        if (!head) return;
        if (!head->next) { delete head; head = nullptr; }
        else {
            Node* cur = head;
            while (cur->next->next) cur = cur->next;
            delete cur->next;
            cur->next = nullptr;
        }
        sz--;
    }
    
    T& front() { return head->data; }
    T& back() {
        Node* cur = head;
        while (cur->next) cur = cur->next;
        return cur->data;
    }
    
    bool empty() const { return !head; }
    size_t size() const { return sz; }
    void clear() { while (!empty()) pop_front(); }
    
    // Запрещаем копирование
    SinglyLinkedList(const SinglyLinkedList&) = delete;
    SinglyLinkedList& operator=(const SinglyLinkedList&) = delete;
    
    // Итератор
    class Iterator {
        Node* cur;
    public:
        Iterator(Node* n) : cur(n) {}
        T& operator*() { return cur->data; }
        Iterator& operator++() { cur = cur->next; return *this; }
        bool operator!=(const Iterator& other) { return cur != other.cur; }
    };
    
    Iterator begin() { return Iterator(head); }
    Iterator end() { return Iterator(nullptr); }
};

int main() {
    setlocale(LC_ALL, "ru");
    SinglyLinkedList<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_front(5);
    
    cout << "Размер: " << list.size() << "\nЭлементы: ";
    for (int x : list) cout << x << " ";
    
    list.pop_front();
    list.pop_back();
    cout << "\nПосле удаления: ";
    for (int x : list) cout << x << " ";
    
    SinglyLinkedList<string> slist;
    slist.push_back("Hello");
    slist.push_back("World");
    cout << "\n\nСтроки: ";
    for (auto& s : slist) cout << s << " ";
    
    return 0;
}
