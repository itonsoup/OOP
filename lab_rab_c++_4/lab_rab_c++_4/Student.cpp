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

//����������� ���������
int STUDENT::getGroupNumber() const {
    return groupNumber;
}

//��������� ������ ��������
const double* STUDENT::getGrades() const {
    return grades;
}

//��������� �������� ����� �� ������ ��������
double STUDENT::getAverageGrade() const {
    double sum = 0;
    for (int i = 0; i < 5; ++i) {
        sum += grades[i];
    }
    return sum / 5.0;
}

//����� ��������
ostream& operator<<(ostream& os, const STUDENT& student) {
    os << setw(20) << left << student.name << " | "
        << setw(5) << right << student.groupNumber << " | "
        << setw(5) << right << "��. ����: " << fixed << setprecision(2) << student.getAverageGrade();
    return os;
}

//��������� ������
bool operator<(const STUDENT& s1, const STUDENT& s2) {
    return s1.getAverageGrade() < s2.getAverageGrade();
}


//�������� ���������� � ��������
void STUDENT::inputStudent() {
    setlocale(LC_ALL, "RU");

    cout << "������� ������� � �������� ��������: ";
    getline(cin, name);

    cout << "������� ����� ������: ";
    cin >> groupNumber;

    cout << "������� ������ �������� (����� ������): ";
    for (int i = 0; i < 5; ++i) {
        cin >> grades[i];
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}