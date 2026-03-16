#include <iostream>
using namespace std;

class Student {
public:
	string name;
	Student(string n) : name(n) {
		cout << "Студент " << name << " поступил" << endl;
	}
	~Student() {
		cout << "Студент" << name << " отчислен" << endl;
	}
	void stude() {
		cout << name << " учится" << endl;
	}
};

class University {
private:
	Student* students[10]; // макс 10 студентов
	int count;
public:
	University() : count(0) {
		cout << "Университет открыт!" << endl;
	}
	~University() {
		cout << "Университет закрыт!" << endl;
		// Не удаляем стдуентов - они живут отдельно!
	}

	void addStudent(Student* s) {
		if (count < 10) {
			students[count++] = s;
			cout << s->name << " зачислен в университет" << endl;
		}
	}

	void showStudents() {
		cout << "Студенты университета: " << endl;
		for (int i = 0; i < count; i++) {
			cout << " - " << students[i]->name << endl;
		}
	}
};

int main() {
	setlocale(LC_ALL, "Ru");
	cout << "Агрегация" << endl;

	// студенты создаются отдельно
	Student vasya(" Вася");
	Student dasha(" Даша");
	Student danya(" Даня");

	{
		University mgu;
		mgu.addStudent(&vasya);
		mgu.addStudent(&dasha);
		mgu.addStudent(&danya);
		mgu.showStudents();

		// университет закроется, но студенты останутся
		cout << "Университет закрывается." << endl;
	}

	cout << "Студенты всё ещё существуют!" << endl;
	vasya.stude();
	dasha.stude();
	danya.stude();

	return 0;
}
