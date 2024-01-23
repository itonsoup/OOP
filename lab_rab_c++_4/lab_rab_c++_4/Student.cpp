#include "student.h"
#include <iomanip>
#include <limits>
#include <locale.h>

using namespace std;

STUDENT::STUDENT() : name(""), groupNumber(0), grades{ 0, 0, 0, 0, 0 } {}

bool STUDENT::operator>(const STUDENT& s) const {
    return getAverageGrade() > s.getAverageGrade();
}

const string& STUDENT::getName() const {
    return name;
}

//группировка студентов
int STUDENT::getGroupNumber() const {
    return groupNumber;
}

//получение оценок студента
const double* STUDENT::getGrades() const {
    return grades;
}

//получение среднего числа из оценок студента
double STUDENT::getAverageGrade() const {
    double sum = 0;
    for (int i = 0; i < 5; ++i) {
        sum += grades[i];
    }
    return sum / 5.0;
}

//вывод студента
ostream& operator<<(ostream& os, const STUDENT& student) {
    os << setw(20) << left << student.name << " | "
        << setw(5) << right << student.groupNumber << " | "
        << setw(5) << right << "—р. балл: " << fixed << setprecision(2) << student.getAverageGrade();
    return os;
}

//сравнение оценок
bool operator<(const STUDENT& s1, const STUDENT& s2) {
    return s1.getAverageGrade() < s2.getAverageGrade();
}


//введение информации о студенте
void STUDENT::inputStudent() {
    setlocale(LC_ALL, "RU");

    cout << "¬ведите фамилию и инициалы студента: ";
    getline(cin, name);

    cout << "¬ведите номер группы: ";
    cin >> groupNumber;

    cout << "¬ведите оценки студента (через пробел): ";
    for (int i = 0; i < 5; ++i) {
        cin >> grades[i];
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}