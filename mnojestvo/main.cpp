#include "head.h"
#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    // Создание множеств
    int arr1[] = {3, 8, 46, 5, 11};
    int arr2[] = {18, 8, 90, 11, 2};
    
    Set A(arr1, 5);
    Set B(arr2, 5);
    
    cout << "Множество A: " << A << endl;
    cout << "Множество B: " << B << endl;
    
    // Проверка принадлежности
    cout << "8 принадлежит A: " << (A.contains(8) ? "да" : "нет") << endl;
    cout << "10 принадлежит A: " << (A.contains(10) ? "да" : "нет") << endl;
    
    // Добавление элемента
    A += 4;
    cout << "A + 4: " << A << endl;
    A += 3;  // Повторный элемент
    cout << "A + 3 (повторно): " << A << endl;
    
    // Удаление элемента
    A -= 46;
    cout << "A - 46: " << A << endl;
    
    // Объединение
    Set C = A + B;
    cout << "A ∪ B: " << C << endl;
    
    // Пересечение
    Set D = A * B;
    cout << "A ∩ B: " << D << endl;
    
    // Разность
    Set E = A - B;
    cout << "A \\ B: " << E << endl;
    
    // Сравнение
    Set A_copy = A;
    cout << "A == A_copy: " << (A == A_copy ? "да" : "нет") << endl;
    cout << "A == B: " << (A == B ? "да" : "нет") << endl;
    
    // Присваивание
    Set F;
    F = A;
    cout << "F (копия A): " << F << endl;
    
    // Ввод с клавиатуры
    Set G;
    cin >> G;
    cout << "Введенное множество: " << G << endl;
    
    return 0;
}
