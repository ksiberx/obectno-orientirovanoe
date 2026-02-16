#include "Fraction.h"
using namespace std;
int main() {
    setlocale(LC_ALL, "ru");
    Fraction f;
    f.input();

    int choice;

    do {
        cout << "\nВыберите операцию:\n";
        cout << "1 - Сложить с дробью\n";
        cout << "2 - Вычесть дробь\n";
        cout << "3 - Умножить на дробь\n";
        cout << "4 - Сложить с числом\n";
        cout << "5 - Вычесть число\n";
        cout << "6 - Умножить на число\n";
        cout << "7 - Показать дробь\n";
        cout << "0 - Выход\n";
        cout << "Ваш выбор: ";
        cin >> choice;

        if (choice >= 1 && choice <= 3) {
            Fraction temp;
            temp.input();

            if (choice == 1) f.add(temp);
            if (choice == 2) f.sub(temp);
            if (choice == 3) f.mul(temp);
        }
        else if (choice >= 4 && choice <= 6) {
            int num;
            cout << "Введите число: ";
            cin >> num;

            if (choice == 4) f.add(num);
            if (choice == 5) f.sub(num);
            if (choice == 6) f.mul(num);
        }
        else if (choice == 7) {
            f.print();
        }

    } while (choice != 0);

    return 0;
}
