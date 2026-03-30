#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
	string ownerName;
	double balance;

public:
	BankAccount(string name, double initialBalance) {
		if (initialBalance < 0) {
			throw "Ошибка: Отрицательный баланс!";
		}
		ownerName = name;
		balance = initialBalance;
		cout << "Счёт создан. Владелец: " << ownerName
			<< ", баланс: " << balance << "руб.\n";
	}
    // Снятие денег
    void withdraw(double amount) {
        if (amount < 0) {
            throw "Ошибка: Отрицательная сумма!";
        }
        if (amount > balance) {
            throw "Ошибка: Недостаточно средств!";
        }
        balance -= amount;
        cout << "Снято: " << amount << " руб. Остаток: " << balance << " руб.\n";
    }

    // Пополнение
    void deposit(double amount) {
        if (amount < 0) {
            throw "Ошибка: Отрицательная сумма!";
        }
        balance += amount;
        cout << "Пополнено: " << amount << " руб. Баланс: " << balance << " руб.\n";
    }

    double getBalance() { return balance; }
};

int main() {
    setlocale(LC_ALL, "ru");
    cout << "Задание 1.\n\n";

    // Пример 1: Успешная работа
    try {
        cout << "1. Создание счета:\n";
        BankAccount acc("Иван", 1000);
        acc.withdraw(300);
        acc.deposit(200);
        cout << "Итоговый баланс: " << acc.getBalance() << " руб.\n\n";
    }
    catch (const char* e) {
        cout << e << "\n\n";
    }

    // Пример 2: Отрицательный баланс
    try {
        cout << "2. Попытка создать счет с отрицательным балансом:\n";
        BankAccount acc("Петр", -500);
    }
    catch (const char* e) {
        cout << e << "\n\n";
    }

    // Пример 3: Недостаточно средств
    try {
        cout << "3. Попытка снять больше, чем есть:\n";
        BankAccount acc("Мария", 500);
        acc.withdraw(600);
    }
    catch (const char* e) {
        cout << e << "\n\n";
    }

    return 0;
};
