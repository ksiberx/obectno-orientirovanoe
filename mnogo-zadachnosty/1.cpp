#include <iostream>
#include <memory>
#include <ctime>
using namespace std;

class Timer {
private:
    time_t startTime;
    string name;

public:
    // Конструктор - запоминаем время создания
    Timer(const string& timerName) : name(timerName) {
        startTime = time(nullptr);
        cout << "Таймер \"" << name << "\" запущен\n";
    }
    
    // Деструктор - выводим прошедшее время
    ~Timer() {
        time_t endTime = time(nullptr);
        double duration = difftime(endTime, startTime);
        cout << "Таймер \"" << name << "\" остановлен. Прошло: " 
             << duration << " секунд\n";
    }
    
    // Метод для имитации работы
    void doWork() {
        cout << "Таймер \"" << name << "\" выполняет работу...\n";
        // Имитация работы (задержка)
        for (int i = 0; i < 100000000; i++) {
            // Простая задержка
        }
    }
};

// Функция возвращает unique_ptr на Timer
unique_ptr<Timer> createTimer(const string& name) {
    return make_unique<Timer>(name);
}

int main() {
    setlocale(LC_ALL, "ru");
    cout << "1. Создаем таймер внутри блока:\n";
    
    // Блок видимости
    {
        auto timer = createTimer("Блоковый таймер");
        timer->doWork();
        cout << "   Выходим из блока...\n";
    } // Здесь timer автоматически удаляется
    
    cout << "\n2. Создаем таймер и передаем владение:\n";
    
    auto timer1 = createTimer("Таймер 1");
    timer1->doWork();
    
    cout << "   Передаем владение в timer2...\n";
    auto timer2 = move(timer1); // Перемещаем владение
    
    if (timer1 == nullptr) {
        cout << "   timer1 теперь пуст\n";
    }
    
    timer2->doWork();
    
    cout << "\n3. Демонстрация автоматического удаления:\n";
    {
        cout << "   Вход в блок...\n";
        auto autoTimer = createTimer("Автоматический таймер");
        autoTimer->doWork();
        cout << "   Выход из блока...\n";
    } // Здесь таймер автоматически уничтожится
    
    cout << "\nКонец программы\n";
    // Все оставшиеся unique_ptr автоматически удалятся
    
    return 0;
}
