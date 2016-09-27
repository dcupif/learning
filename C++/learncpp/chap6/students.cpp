#include <iostream>
#include <string>
#include <utility>

struct Student
{
    std::string name;
    int grade;
};

void sortByGrade(Student *students, int nbStudents)
{
    for (size_t i = 0; i < nbStudents; i++) {
        int highestIndex = i;
        for (size_t j = i+1; j < nbStudents; j++) {
            if (students[j].grade > students[highestIndex].grade)
                highestIndex = j;
        }
        std::swap(students[i], students[highestIndex]);
    }
}

int main(int argc, char const *argv[])
{
    std::cout << "Enter the number of students to be processed: ";
    int nbStudents;
    std::cin >> nbStudents;

    std::cout << "\n";

    Student *students = new Student[nbStudents];

    for (int i = 0; i < nbStudents; i++) {
        std::cout << "Enter name #" << i+1 << ": ";
        std::cin >> students[i].name;
        std::cout << "Enter grade #" << i+1 << ": ";
        std::cin >> students[i].grade;
    }

    sortByGrade(students, nbStudents);

    std::cout << "\n";

    for (size_t i = 0; i < nbStudents; i++) {
        std::cout << students[i].name << " got a grade of " <<
            students[i].grade << "\n";
    }

    delete[] students;

    return 0;
}
