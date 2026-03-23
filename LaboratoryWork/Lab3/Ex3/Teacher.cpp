#include "Teacher.h"
#include <sstream>

Teacher::Teacher() : Human(), position(Position::Unknown), subjects() {}

Teacher::Teacher(const std::string& name, const std::string& surname,
    const std::string& patronymic, Position position,
    const std::vector<std::string>& subjects)
    : Human(name, surname, patronymic), position(position), subjects(subjects) {}

void Teacher::addSubject(const std::string& subject) 
{
    subjects.push_back(subject);
}

std::string Teacher::getShortTeacherInfo() const 
{
    std::ostringstream oss;
    oss << getSurnameAndInitials();
    switch (position) {
    case Position::Assistant: oss << " ассистент"; break;
    case Position::SeniorLecturer: oss << " старший преподаватель"; break;
    case Position::AssociateProfessor: oss << " доцент"; break;
    case Position::Professor: oss << " профессор"; break;
    default: oss << " Неизвестно"; break;
    }
    oss << ": " << subjects.size();
    return oss.str();
}

std::string Teacher::getFullTeacherInfo() const 
{
    std::ostringstream oss;
    oss << getFullName();
    switch (position) {
    case Position::Assistant: oss << " ассистент"; break;
    case Position::SeniorLecturer: oss << " старший преподаватель"; break;
    case Position::AssociateProfessor: oss << " доцент"; break;
    case Position::Professor: oss << " профессор"; break;
    default: oss << " Неизвестно"; break;
    }
    oss << ": ";
    for (size_t i = 0; i < subjects.size(); ++i) {
        if (i > 0) oss << ", ";
        oss << subjects[i];
    }
    return oss.str();
}

Position Teacher::getPosition() const { return position; }
const std::vector<std::string>& Teacher::getSubjects() const { return subjects; }