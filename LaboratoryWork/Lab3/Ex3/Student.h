#pragma once

#include "Human.h"
#include <vector>

class Student : public Human
{
private:
    std::vector<int> scores;

public:
    Student();
    Student(const std::string& name, const std::string& surname,
        const std::string& patronymic, const std::vector<int>& scores);

    void addScore(int score);
    double getAverageScore() const;
    std::string getShortStudentInfo() const;
    std::string getFullStudentInfo() const;
    std::vector<int> getScores() const;
};

