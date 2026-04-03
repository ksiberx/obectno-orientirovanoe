#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

class ThreadGuard {
private:
    thread m_thread;
    
public:
    template<typename Callable>
    ThreadGuard(Callable&& func) : m_thread(forward<Callable>(func)) {}
    
    // Запрещаем копирование
    ThreadGuard(const ThreadGuard&) = delete;
    ThreadGuard& operator=(const ThreadGuard&) = delete;
    
    // Деструктор: автоматически вызывает join()
    ~ThreadGuard() {
        if (m_thread.joinable()) {
            m_thread.join();
        }
    }
};

// Функция 1: простое сообщение
void printMessage() {
    cout << "Поток 1: Привет из потока!" << endl;
}

// Функция 2: с задержкой
void delayedMessage() {
    this_thread::sleep_for(chrono::seconds(2));
    cout << "Поток 2: Я подождал 2 секунды!" << endl;
}

int main() {
    setlocale(LC_ALL, "ru");
    cout << "Главный поток: Запускаем потоки..." << endl;
    
    ThreadGuard t1(printMessage);
    ThreadGuard t2(delayedMessage);
    
    cout << "Главный поток: Потоки запущены и будут автоматически завершены" << endl;
    cout << "Главный поток: Завершаем работу..." << endl;
    
    // Деструкторы t1 и t2 автоматически вызовут join()
    return 0;
}
