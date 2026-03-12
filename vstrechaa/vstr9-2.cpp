#include <iostream>
#include <cstring>
using namespace std;

class String {
private:
    char* str;
    
public:
    String(const char* s = "") {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
    
    String(const String& other) {
        str = new char[strlen(other.str) + 1];
        strcpy(str, other.str);
    }
    
    ~String() {
        delete[] str;
    }
    
    const char* c_str() const { return str; }
    
    String operator+(const String& other) const {
        char* temp = new char[strlen(str) + strlen(other.str) + 1];
        strcpy(temp, str);
        strcat(temp, other.str);
        String result(temp);
        delete[] temp;
        return result;
    }
    
    String operator*(const String& other) const {
        char result[1000] = "";
        for (int i = 0; str[i]; i++) {
            for (int j = 0; other.str[j]; j++) {
                if (str[i] == other.str[j]) {
                    char c[2] = {str[i], '\0'};
                    strcat(result, c);
                    break;
                }
            }
        }
        return String(result);
    }
    
    String operator/(const String& other) const {
        char result[1000] = "";
        for (int i = 0; str[i]; i++) {
            bool found = false;
            for (int j = 0; other.str[j]; j++) {
                if (str[i] == other.str[j]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                char c[2] = {str[i], '\0'};
                strcat(result, c);
            }
        }
        return String(result);
    }
    
    void operator*=(const String& other) {
        *this = *this * other;
    }
    
    void operator/=(const String& other) {
        *this = *this / other;
    }
    
    bool operator==(const String& other) const {
        return strcmp(str, other.str) == 0;
    }
    
    bool operator!=(const String& other) const {
        return !(*this == other);
    }
    
    void show() const {
        cout << str;
    }
};

class var {
private:
    enum Type { INT, DOUBLE, STRING } type;
    union {
        int i;
        double d;
        String* s;
    };
    
    void copy(const var& other) {
        type = other.type;
        switch(type) {
            case INT: i = other.i; break;
            case DOUBLE: d = other.d; break;
            case STRING: s = new String(*other.s); break;
        }
    }
    
    void clear() {
        if (type == STRING) delete s;
    }
    
public:
    var(int v) : type(INT), i(v) {}
    var(double v) : type(DOUBLE), d(v) {}
    var(const char* v) : type(STRING) { s = new String(v); }
    var(const String& v) : type(STRING) { s = new String(v); }
    
    var(const var& other) { copy(other); }
    
    ~var() { clear(); }
    
    var& operator=(const var& other) {
        if (this != &other) {
            clear();
            copy(other);
        }
        return *this;
    }
    
    // Преобразования типов
    operator int() {
        if (type == INT) return i;
        if (type == DOUBLE) return (int)d;
        return atoi(s->c_str());
    }
    
    operator double() {
        if (type == DOUBLE) return d;
        if (type == INT) return (double)i;
        return atof(s->c_str());
    }
    
    operator char*() {
        static char buffer[100];
        if (type == INT) sprintf(buffer, "%d", i);
        else if (type == DOUBLE) sprintf(buffer, "%f", d);
        else strcpy(buffer, s->c_str());
        return buffer;
    }
    
    // Арифметические операторы
    var operator+(const var& other) const {
        if (type == STRING || (type == INT && other.type == STRING)) {
            String s1 = (type == STRING) ? *s : String((char*)(int)*this);
            String s2 = (other.type == STRING) ? *other.s : String((char*)(int)other);
            return var(s1 + s2);
        }
        else if (type == DOUBLE || other.type == DOUBLE) {
            return var((double)*this + (double)other);
        }
        else {
            return var((int)*this + (int)other);
        }
    }
    
    var operator-(const var& other) const {
        if (type == DOUBLE || other.type == DOUBLE)
            return var((double)*this - (double)other);
        return var((int)*this - (int)other);
    }
    
    var operator*(const var& other) const {
        if (type == STRING && other.type == STRING) {
            return var(*s * *other.s);
        }
        else if (type == DOUBLE || other.type == DOUBLE)
            return var((double)*this * (double)other);
        return var((int)*this * (int)other);
    }
    
    var operator/(const var& other) const {
        if (type == STRING && other.type == STRING) {
            return var(*s / *other.s);
        }
        else if (type == DOUBLE || other.type == DOUBLE)
            return var((double)*this / (double)other);
        return var((int)*this / (int)other);
    }
    
    var& operator+=(const var& other) {
        *this = *this + other;
        return *this;
    }
    
    var& operator-=(const var& other) {
        *this = *this - other;
        return *this;
    }
    
    var& operator*=(const var& other) {
        *this = *this * other;
        return *this;
    }
    
    var& operator/=(const var& other) {
        *this = *this / other;
        return *this;
    }
    
    // Операторы сравнения
    bool operator==(const var& other) const {
        if (type == STRING || other.type == STRING) {
            String s1 = (type == STRING) ? *s : String((char*)(int)*this);
            String s2 = (other.type == STRING) ? *other.s : String((char*)(int)other);
            return s1 == s2;
        }
        else if (type == DOUBLE || other.type == DOUBLE)
            return (double)*this == (double)other;
        return (int)*this == (int)other;
    }
    
    bool operator!=(const var& other) const { return !(*this == other); }
    
    bool operator<(const var& other) const {
        if (type == STRING || other.type == STRING)
            return strcmp((char*)*this, (char*)other) < 0;
        else if (type == DOUBLE || other.type == DOUBLE)
            return (double)*this < (double)other;
        return (int)*this < (int)other;
    }
    
    bool operator>(const var& other) const { return other < *this; }
    bool operator<=(const var& other) const { return !(*this > other); }
    bool operator>=(const var& other) const { return !(*this < other); }
    
    void show() const {
        if (type == INT) cout << i;
        else if (type == DOUBLE) cout << d;
        else s->show();
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    // Пример 1
    var a = 15;
    var b = "Hello";
    var c = 7.8;
    var d = "50";
    
    b = a + d;
    cout << "b = a + d: ";
    b.show();
    cout << endl;
    
    if (a == b) cout << "Equal\n";
    else cout << "Not Equal\n";
    
    // Пример 2
    var x = "Microsoft";
    var y = "Windows";
    var z;
    
    z = x * y;
    cout << "Microsoft * Windows = ";
    z.show();
    cout << endl;
    
    z = x / y;
    cout << "Microsoft / Windows = ";
    z.show();
    cout << endl;
    
    // Пример 3
    var i1 = 10;
    var i2 = "120";
    var res;
    
    res = i1 + i2;
    cout << "10 + \"120\" = ";
    res.show();
    cout << endl;
    
    res = i2 + i1;
    cout << "\"120\" + 10 = ";
    res.show();
    cout << endl;
    
    return 0;
}
