#include <iostream>
#include <string>
using namespace std;

class Cat {
protected:
    string name;
    int age;
    string color;

    static int count;  // статическое поле — сколько всего кошек

public:
    // Конструктор с параметрами
    Cat(const string& name, int age, const string& color)
        : name(name), age(age), color(color) {
        count++;
        cout << "Конструктор Cat: " << name << endl;
    }

    // Деструктор
    virtual ~Cat() {
        cout << "Деструктор Cat: " << name << " уничтожен" << endl;
        count--;
    }

    // Методы
    void printInfo() const {
        cout << "Имя: " << name << ", Возраст: " << age << ", Окрас: " << color;
    }

    void sound() const {
        cout << "Кошка издает звук: Мяу!" << endl;
    }

    // Геттеры
    string getName() const { return name; }
    int getAge() const { return age; }
    string getColor() const { return color; }

    // Статический метод
    static int getCount() {
        return count;
    }
};

// Инициализация статического поля
int Cat::count = 0;

class HouseCat : public Cat {
private:
    string ownerName;

public:
    HouseCat(const string& name, int age, const string& color, const string& owner)
        : Cat(name, age, color), ownerName(owner) {
        cout << "Конструктор HouseCat: " << name << endl;
    }

    ~HouseCat() {
        cout << "Деструктор HouseCat: " << name << " уничтожен" << endl;
    }

    void sound() const {
        cout << name << " мурлыкает: Мрр-мрр" << endl;
    }

    void printInfo() const {
        Cat::printInfo();
        cout << ", Хозяин: " << ownerName << endl;
    }

    void play() const {
        cout << name << " играет с мячиком" << endl;
    }
};

class WildCat : public Cat {
private:
    string habitat;

public:
    WildCat(const string& name, int age, const string& color, const string& habitat)
        : Cat(name, age, color), habitat(habitat) {
        cout << "Конструктор WildCat: " << name << endl;
    }

    ~WildCat() {
        cout << "Деструктор WildCat: " << name << " уничтожен" << endl;
    }

    void sound() const {
        cout << name << " рычит: Рррр!" << endl;
    }

    void printInfo() const {
        Cat::printInfo();
        cout << ", Среда обитания: " << habitat << endl;
    }

    void hunt() const {
        cout << name << " охотится" << endl;
    }
};

class PersianCat : public Cat {
private:
    int woolLength; // длина шерсти в см

public:
    PersianCat(const string& name, int age, const string& color, int woolLength)
        : Cat(name, age, color), woolLength(woolLength) {
        cout << "Конструктор PersianCat: " << name << endl;
    }

    ~PersianCat() {
        cout << "Деструктор PersianCat: " << name << " уничтожен" << endl;
    }

    void sound() const {
        cout << name << " тихо мяукает: Мяу" << endl;
    }

    void printInfo() const {
        Cat::printInfo();
        cout << ", Длина шерсти: " << woolLength << " см" << endl;
    }

    void groom() const {
        cout << name << " нуждается в расчесывании" << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    cout << "Создание объектов\n";
    cout << "Начальное количество кошек: " << Cat::getCount() << "\n\n";

    // Создаём объекты разных типов
    HouseCat house("Мурка", 3, "серая", "Иван");
    WildCat wild("Рысь", 5, "пятнистая", "лес");
    PersianCat persian("Пушистик", 2, "белая", 10);

    // Ещё одна домашняя кошка
    HouseCat house2("Барсик", 1, "черный", "Петр");

    cout << "\nТекущее количество кошек: " << Cat::getCount() << "\n\n";

    cout << "Демонстрация методов через объекты\n";
    house.printInfo();
    house.sound();
    house.play();
    cout << endl;

    wild.printInfo();
    wild.sound();
    wild.hunt();
    cout << endl;

    persian.printInfo();
    persian.sound();
    persian.groom();
    cout << endl;

    cout << "Демонстрация через указатели на базовый класс\n";
    Cat* ptr1 = &house;
    Cat* ptr2 = &wild;
    Cat* ptr3 = &persian;

    ptr1->printInfo();
    cout << " (через указатель на Cat)\n";
    ptr1->sound();
    cout << "Обрати внимание: sound() вызывается из Cat, потому что нет virtual\n";
    cout << "Если бы использовали virtual, вызвались бы переопределённые методы.\n\n";

    // Чтобы вызвать специфические методы, нужно привести тип обратно
    cout << "Приведение к производному типу:\n";
    static_cast<HouseCat*>(ptr1)->play();
    static_cast<WildCat*>(ptr2)->hunt();
    static_cast<PersianCat*>(ptr3)->groom();

    cout << "\n Конец main — автоматическое уничтожение объектов\n";
    return 0;
}
