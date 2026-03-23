#include "HumanManager.h"

#include <algorithm>
#include <sstream>

void HumanManager::saveStudentsToFile(const std::vector<Student>& students, const std::string& filename) 
{
    std::ofstream out(filename);
    if (!out.is_open()) 
    {
        std::cerr << "Не удалось открыть файл для записи: " << filename << std::endl;
        return;
    }

    for (const auto& student : students) 
    {
        out << student.getFullName() << ";";
        const auto& scores = student.getScores();
        for (size_t i = 0; i < scores.size(); ++i) 
        {
            if (i > 0) out << " ";
            out << scores[i];
        }
        out << std::endl;
    }
    out.close();
}

void HumanManager::loadStudentsFromFile(std::vector<Student>& students, const std::string& filename) 
{
    students.clear();
    std::ifstream in(filename);
    if (!in.is_open()) 
    {
        std::cerr << "Не удалось открыть файл для чтения: " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(in, line)) 
    {
        std::istringstream iss(line);
        std::string fullName, scoreStr;
        std::vector<int> scores;

        if (std::getline(iss, fullName, ';')) 
        {
            while (iss >> scoreStr) 
            {
                scores.push_back(std::stoi(scoreStr));
            }

            // Разбираем fullName на имя, фамилию, отчество
            std::istringstream nameStream(fullName);
            std::string surname, name, patronymic;
            nameStream >> surname >> name >> patronymic;

            students.emplace_back(name, surname, patronymic, scores);
        }
    }
    in.close();
}

void HumanManager::saveTeachersToFile(const std::vector<Teacher>& teachers, const std::string& filename) 
{
    std::ofstream out(filename);
    if (!out.is_open()) 
    {
        std::cerr << "Не удалось открыть файл для записи: " << filename << std::endl;
        return;
    }

    for (const auto& teacher : teachers) 
    {
        out << teacher.getFullName() << ";";

        switch (teacher.getPosition()) 
        {
        case Position::Assistant: out << "Assistant"; break;
        case Position::SeniorLecturer: out << "SeniorLecturer"; break;
        case Position::AssociateProfessor: out << "AssociateProfessor"; break;
        case Position::Professor: out << "Professor"; break;
        default: out << "Unknown"; break;
        }

        out << ";";
        const auto& subjects = teacher.getSubjects();
        for (size_t i = 0; i < subjects.size(); ++i) 
        {
            if (i > 0) out << ",";
            out << subjects[i];
        }
        out << std::endl;
    }
    out.close();
}

void HumanManager::loadTeachersFromFile(std::vector<Teacher>& teachers, const std::string& filename) 
{
    teachers.clear();
    std::ifstream in(filename);
    if (!in.is_open()) 
    {
        std::cerr << "Не удалось открыть файл для чтения: " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(in, line)) 
    {
        std::istringstream iss(line);
        std::string fullName, posStr, subjectStr;
        std::vector<std::string> subjects;
        Position position = Position::Unknown;

        if (std::getline(iss, fullName, ';') && std::getline(iss, posStr, ';')) 
        {
            // Парсим позицию
            if (posStr == "Assistant") position = Position::Assistant;
            else if (posStr == "SeniorLecturer") position = Position::SeniorLecturer;
            else if (posStr == "AssociateProfessor") position = Position::AssociateProfessor;
            else if (posStr == "Professor") position = Position::Professor;

            // Парсим предметы
            while (std::getline(iss, subjectStr, ',')) 
            {
                subjects.push_back(subjectStr);
            }

            // Разбираем fullName
            std::istringstream nameStream(fullName);
            std::string surname, name, patronymic;
            nameStream >> surname >> name >> patronymic;

            teachers.emplace_back(name, surname, patronymic, position, subjects);
        }
    }
    in.close();
}

void HumanManager::Start()
{
    std::vector<Student> students = {
        Student("Иван", "Иванов", "Иванович", {4, 5, 4, 5}),
        Student("Пётр", "Петров", "Петрович", {3, 3, 4}),
        Student("Мария", "Сидорова", "Сергеевна", {5, 5, 5, 4}),
        Student("Анна", "Козлова", "Андреевна", {4, 4, 3}),
        Student("Сергей", "Смирнов", "Семёнович", {5, 5, 5, 5}),
        Student("Елена", "Волкова", "Евгеньевна", {3, 4, 3, 4}),
        Student("Дмитрий", "Николаев", "Дмитриевич", {4, 4, 4}),
        Student("Ольга", "Павлова", "Олеговна", {5, 5, 4, 5}),
        Student("Алексей", "Фёдоров", "Алексеевич", {3, 3, 3}),
        Student("Наталья", "Морозова", "Николаевна", {4, 5, 4})
    };

    std::vector<Teacher> teachers = {
        Teacher("Андрей", "Лебедев", "Андреевич", Position::Professor, {"Математика", "Физика"}),
        Teacher("Виктор", "Орлов", "Викторович", Position::AssociateProfessor, {"Информатика", "Программирование"}),
        Teacher("Татьяна", "Белова", "Тихоновна", Position::SeniorLecturer, {"Химия", "Биология"}),
        Teacher("Михаил", "Григорьев", "Михайлович", Position::Assistant, {"История", "Философия"}),
        Teacher("Светлана", "Васильева", "Сергеевна", Position::Professor, {"Литература", "Русский язык"}),
        Teacher("Николай", "Соколов", "Николаевич", Position::AssociateProfessor, {"Информатика"}),
        Teacher("Ирина", "Новикова", "Игоревна", Position::SeniorLecturer, {"Экономика", "Менеджмент"}),
        Teacher("Александр", "Павлов", "Александрович", Position::Assistant, {"Физика", "Астрономия"}),
        Teacher("Юлия", "Семёнова", "Юрьевна", Position::Professor, {"Информатика", "Базы данных", "Алгоритмы"}),
        Teacher("Роман", "Кузнецов", "Романович", Position::AssociateProfessor, {"Информатика", "Сетевые технологии"})
    };

    // Демонстрация работы функций сохранения/загрузки
    saveStudentsToFile(students, "students.txt");
    saveTeachersToFile(teachers, "teachers.txt");

    std::vector<Student> loadedStudents;
    std::vector<Teacher> loadedTeachers;
    loadStudentsFromFile(loadedStudents, "students.txt");
    loadTeachersFromFile(loadedTeachers, "teachers.txt");

    // Вывод требуемой информации
    std::cout << "1) Студенты со средним баллом > 4:" << std::endl;
    for (const auto& student : students) 
    {
        if (student.getAverageScore() > 4.0) 
        {
            std::cout << student.getShortStudentInfo() << std::endl;
        }
    }

    std::cout << "\n2) Студенты со средним баллом < 3:" << std::endl;
    for (const auto& student : students) 
    {
        if (student.getAverageScore() < 3.0) 
        {
            std::cout << student.getShortStudentInfo() << std::endl;
        }
    }
    
    std::cout << "\n3) Студент с наибольшим количеством оценок:" << std::endl;
    auto maxScoresStudent = std::max_element(
        students.begin(), students.end(),
        [](const Student& a, const Student& b) 
        {
            return a.getScores().size() < b.getScores().size();
        }
    );
    if (maxScoresStudent != students.end()) 
    {
        std::cout << maxScoresStudent->getFullStudentInfo() << std::endl;
    }
    else 
    {
        std::cout << "Студенты не найдены" << std::endl;
    }

    std::cout << "\n4) Доценты:" << std::endl;
    for (const auto& teacher : teachers) 
    {
        if (teacher.getPosition() == Position::AssociateProfessor) 
        {
            std::cout << teacher.getShortTeacherInfo() << std::endl;
        }
    }

    std::cout << "\n5) Профессор с наибольшим количеством предметов:" << std::endl;
    Teacher* maxSubjectsProfessor = nullptr;
    size_t maxSubjectsCount = 0;

    for (auto& teacher : teachers) 
    {
        if (teacher.getPosition() == Position::Professor) 
        {
            size_t currentCount = teacher.getSubjects().size();
            if (currentCount > maxSubjectsCount) 
            {
                maxSubjectsCount = currentCount;
                maxSubjectsProfessor = &teacher;
            }
        }
    }

    if (maxSubjectsProfessor) 
    {
        std::cout << maxSubjectsProfessor->getFullTeacherInfo() << std::endl;
    }
    else 
    {
        std::cout << "Профессора не найдены" << std::endl;
    }

    std::cout << "\n6) Преподаватели, ведущие информатику:" << std::endl;
    bool hasComputerScienceTeachers = false;
    for (const auto& teacher : teachers)
    {
        const auto& subjects = teacher.getSubjects();
        if (std::find(subjects.begin(), subjects.end(), "Информатика") != subjects.end()) 
        {
            std::cout << teacher.getFullTeacherInfo() << std::endl;
            hasComputerScienceTeachers = true;
        }
    }

    if (!hasComputerScienceTeachers) 
    {
        std::cout << "Преподаватели, ведущие информатику, не найдены" << std::endl;
    }

    // Дополнительная проверка загрузки данных
    std::cout << "\n=== Проверка загрузки данных ===" << std::endl;
    std::cout << "Загружено студентов: " << loadedStudents.size() << std::endl;
    std::cout << "Загружено преподавателей: " << loadedTeachers.size() << std::endl;
}