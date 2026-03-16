#include <iostream>
#include <vector>
using namespace std;

class Room {
public:
    string name;
    Room(string n) : name(n) {
        cout << "+ Комната: " << name << endl;
    }
    ~Room() {
        cout << "- Комната: " << name << endl;
    }
    void show() {
        cout << "  Комната: " << name << endl;
    }
};

class House {
private:
    vector<Room> rooms;  // vector сам управляет памятью

public:
    House() {
        rooms.push_back(Room("Гостиная"));
        rooms.push_back(Room("Спальня"));
        rooms.push_back(Room("Кухня"));
        cout << "Дом построен!" << endl;
    }

    void showRooms() {
        cout << "Комнаты в доме:" << endl;
        for (int i = 0; i < rooms.size(); i++) {
            rooms[i].show();
        }
    }

    // кога дом уничтожается, vector сам удаляет все комнаты
};

int main() {
    setlocale(LC_ALL, "Ru");
    cout << "Композиция" << endl;

    House myHouse;
    myHouse.showRooms();

    cout << "Дом разрушается..." << endl;
    // комнаты удалятся автоматически

    return 0;
}
