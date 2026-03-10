#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include "Student.h"
#include "Teacher.h"

class HumanManager
{
private:
	void saveStudentsToFile(const std::vector<Student>& students, const std::string& filename);
	void loadStudentsFromFile(std::vector<Student>& students, const std::string& filename);
	void saveTeachersToFile(const std::vector<Teacher>& teachers, const std::string& filename);
	void loadTeachersFromFile(std::vector<Teacher>& teachers, const std::string& filename);
public:
	void Start();
};