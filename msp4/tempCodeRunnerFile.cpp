#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

struct GradeComponent {
    string name;
    int points;
};

struct Student {
    string name;
    string id;
    vector<GradeComponent> workGrades;
    vector<GradeComponent> recallGrades;
    int totalWorkPoints;
    int totalRecallPoints;
    char letterGrade;
};

// Function to calculate total points for a component
int calculateTotalPoints(const vector<GradeComponent>& grades) {
    int total = 0;
    for (const auto& grade : grades) {
        total += grade.points;
    }
    return total;
}

// Function to calculate the final letter grade
char calculateLetterGrade(double finalScore) {
    char grade;
    if (finalScore >= 90) return 'A';
    else if (finalScore >= 80) return 'B';
    else if (finalScore >= 70) return 'C';
    else if (finalScore >= 60) return 'D';
    else grade =  'F';

    return grade;
}

// Function to drop the lowest component
void dropLowestComponent(vector<GradeComponent>& grades) {
    if (!grades.empty()) {
        auto lowestGrade = min_element(grades.begin(), grades.end(), 
            [](const GradeComponent& a, const GradeComponent& b) {
                return a.points < b.points;
            }
        );
        grades.erase(lowestGrade);
    }
}

// Function to calculate the final grade for a student
void calculateFinalGrade(Student& student) {
    student.totalWorkPoints = calculateTotalPoints(student.workGrades);
    student.totalRecallPoints = calculateTotalPoints(student.recallGrades);

    dropLowestComponent(student.workGrades);
    dropLowestComponent(student.recallGrades);

    // Calculate final weighted score and determine the letter grade
    double finalWorkWeight = 0.6;
    double finalRecallWeight = 0.4;

    double finalScore = (student.totalWorkPoints * finalWorkWeight) +
                        (student.totalRecallPoints * finalRecallWeight);

    student.letterGrade = calculateLetterGrade(finalScore);
}

// Function to read grades from a CSV file
vector<Student> readGradesFromFile(const string& filename) {
    ifstream file(filename);
  vector<Student> students;

    if (file.is_open()) {
        string line;
       getline(file, line); // Read header and discard

        while (getline(file, line)) {
            istringstream ss(line);
            string token;

            Student student;
            getline(ss, token, ',');
            student.name = token;

            getline(ss, token, ',');
            student.id = token;

            // Loop to read grades
            while (std::getline(ss, token, ',')) {
                GradeComponent grade;
                grade.name = token;

                std::getline(ss, token, ',');
                grade.points = std::stoi(token);

                // Determine if it's a work grade or recall grade
                if (grade.name.find("MSP") != std::string::npos || grade.name.find("Lab Course") != std::string::npos) {
                    student.workGrades.push_back(grade);
                } else {
                    student.recallGrades.push_back(grade);
                }
            }
            students.push_back(student);
        }
        file.close();
    }
    return students;
}

// Function to write final grades to a CSV file
void writeGradesToFile(const std::vector<Student>& students, const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << "Name,Student ID,Final Grade\n";
        for (const auto& student : students) {
            file << student.name << "," << student.id << "," << student.letterGrade << "\n";
        }
        file.close();
    }
}

// Your main function remains the same...

int main() {
    // Read grades from CSV file
    std::vector<Student> students = readGradesFromFile("inputs.csv");

    // Calculate final grades for each student
    for (auto& student : students) {
        calculateFinalGrade(student);
    }

    // Write final grades to a new CSV file
    writeGradesToFile(students, "final_grades.csv");

    return 0;
}
