#pragma once

#include <iostream>
#include <string>

using namespace std;

class STUDENT {
private:
    string name;
    int groupNumber;
    double grades[5];

public:
    STUDENT();

    bool operator>(const STUDENT& s) const;

    const string& getName() const;
    int getGroupNumber() const;
    const double* getGrades() const;
    double getAverageGrade() const;

    friend ostream& operator<<(ostream& os, const STUDENT& student);

    friend bool operator<(const STUDENT& s1, const STUDENT& s2);

    void inputStudent();
};