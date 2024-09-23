#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

// defining struct
struct STUDENT_DATA {
    std::string FirstName;
    std::string LastName;
};

int main() {
    // vector to stor teh data 
    std::vector<STUDENT_DATA> students;

    // Open the input file
    std::ifstream file("C:/Users/ashmi/OneDrive/Desktop/Assignment 2 CSCN73030/Assignment 2 CSCN73030/StudentData.txt");
    std::string line;

    // Check if the file opened 
    if (!file) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    // Reading and parsing
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string FirstName, LastName;

        // Take first anme and last name seperated by a comma
        if (std::getline(ss, FirstName, ',') && std::getline(ss, LastName)) {
            STUDENT_DATA student{ FirstName, LastName };
            students.push_back(student);
        }
    }

    // Close the file
    file.close();

    // Print student information DEBUG functionality
#ifdef _DEBUG
    std::cout << "Student List:" << std::endl;
    for (const auto& student : students) {
        std::cout << "First Name: " << student.FirstName << ", Last Name: " << student.LastName << std::endl;
    }
#endif

    return 0; // Return success
}


