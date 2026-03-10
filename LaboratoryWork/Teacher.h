#pragma once
#include "Human.h"
#include <vector>

enum class Position 
{
    Assistant,
    SeniorLecturer,
    AssociateProfessor,
    Professor,
    Unknown
};

class Teacher : public Human
{
private:
    Position position;
    std::vector<std::string> subjects;

public:
    Teacher();
    Teacher(const std::string& name, const std::string& surname,
        const std::string& patronymic, Position position,
        const std::vector<std::string>& subjects);

    void addSubject(const std::string& subject);
    std::string getShortTeacherInfo() const;
    std::string getFullTeacherInfo() const;
    Position getPosition() const;
    const std::vector<std::string>& getSubjects() const;
};

