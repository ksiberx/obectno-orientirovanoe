#include <iostream>
#include <cstring>
using namespace std;
class String {
private:
    int length;
    char* str;

public:
    String(const char* s) {
        this->length = strlen(s);
        this->str = new char[this->length + 1];
        strcpy(this->str, s);
    }

    String(int len) {
        this->length = len;
        this->str = new char[this->length + 1];
        this->str[0] = '\0';
    }

    String(const String& other) {
        this->length = other.length;
        this->str = new char[this->length + 1];
        strcpy(this->str, other.str);
    }

    ~String() {
        delete[] this->str;
    }

    void print() const {
        cout << this->str;
    }

    void set(const char* s) {
        int newLength = strlen(s);

        if (newLength > this->length) {
            delete[] this->str;
            this->str = new char[newLength + 1];
            this->length = newLength;
        }

        strcpy(this->str, s);
    }
};
