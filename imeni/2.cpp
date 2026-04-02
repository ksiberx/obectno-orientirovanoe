#include <iostream>
#include <string>
using namespace std; 

namespace Logger {
    enum LogLevel {
        INFO,
        WARNING,
        ERROR
    };

    void log(LogLevel level, const string& message) {
        switch (level) {
            case INFO:
                cout << "[INFO] " << message << endl;
                break;
            case WARNING:
                cout << "[WARNING] " << message << endl;
                break;
            case ERROR:
                cout << "[ERROR] " << message << endl;
                break;
        }
    }

    namespace FileLogger {
        void logToFile(const string& filename, const string& message) {
            cout << "[File: " << filename << "] " << message << endl;
        }
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    using namespace Logger;
    
    log(INFO, "Программа запущена");
    log(WARNING, "Память почти заполнена");
    log(ERROR, "Ошибка подключения");
    
    FileLogger::logToFile("log.txt", "Важное событие");
    FileLogger::logToFile("error.log", "Критическая ошибка");

    return 0;
}
