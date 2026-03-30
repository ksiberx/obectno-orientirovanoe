#include <iostream>
#include <cstring>
using namespace std;

class StringHolder {
protected:
    char* str;
public:
    StringHolder(const char* s) {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
        cout << "StringHolder created: " << str << endl;
    }
    
    virtual ~StringHolder() {
        cout << "StringHolder deleted: " << str << endl;
        delete[] str;
    }
    
    virtual void print() const {
        cout << str;
    }
};

class ReverseString : public StringHolder {
public:
    ReverseString(const char* s) : StringHolder(s) {}
    
    void print() const override {
        int len = strlen(str);
        for (int i = len - 1; i >= 0; i--)
            cout << str[i];
    }
};

int main() {
    StringHolder* s1 = new StringHolder("Hello");
    StringHolder* s2 = new ReverseString("World");
    
    s1->print(); cout << endl;
    s2->print(); cout << endl;
    
    delete s1;
    delete s2;
    return 0;
}
