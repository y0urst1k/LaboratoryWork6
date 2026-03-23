#include "Student.h"
#include <numeric>
#include <sstream>

Student::Student() : Human(), scores() {}

Student::Student(const std::string& name, const std::string& surname,
    const std::string& patronymic, const std::vector<int>& scores)
    : Human(name, surname, patronymic), scores(scores) {}

void Student::addScore(int score)
{
    scores.push_back(score);
}

double Student::getAverageScore() const 
{
    if (scores.empty())
        return 0.0;
    double sum = std::accumulate(scores.begin(), scores.end(), 0);
    return sum / scores.size();
}

std::string Student::getShortStudentInfo() const 
{
    std::ostringstream oss;
    oss << getSurnameAndInitials() << ": " << getAverageScore();
    return oss.str();
}

std::string Student::getFullStudentInfo() const 
{
    std::ostringstream oss;
    oss << getFullName() << ": ";
    for (size_t i = 0; i < scores.size(); ++i) 
    {
        if (i > 0) oss << " ";
        oss << scores[i];
    }
    oss << " – " << getAverageScore();
    return oss.str();
}

std::vector<int> Student::getScores() const
{
    return scores;
}