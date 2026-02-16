#include "Person.h"
using namespace std;
int main() {
    setlocale(LC_ALL, "ru");

    Person p1(1, "Иванов", "Иван", "Иванович", Date(10, 5, 2000));
    p1.print();

    cout << "\nКоличество объектов: "
        << Person::getCount() << endl;

    // Проверка копирования
    Person p2 = p1;
    p2.print();

    cout << "\nКоличество объектов: "
        << Person::getCount() << endl;

    return 0;
}
