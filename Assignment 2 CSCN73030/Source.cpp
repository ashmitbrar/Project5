#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

// defining struct
struct STUDENT_DATA {
    std::string FirstName;
    std::string LastName;
    std::string Email;
};

int main() {
    // vector to stor teh data 
    std::vector<STUDENT_DATA> students;

    //// Open the input file
    //std::ifstream file("C:/Users/ashmi/OneDrive/Desktop/Assignment 2 CSCN73030/Assignment 2 CSCN73030/StudentData.txt");
    //std::string line;
    // 
     // Print message indicating the mode of the application
#ifdef PRE_RELEASE
    std::cout << "Running Pre-Release Version" << std::endl;
    std::ifstream file("C:/Users/ashmi/OneDrive/Desktop/Assignment 2 CSCN73030/Assignment 2 CSCN73030/StudentData_Emails.txt");
#else
    std::cout << "Running Standard Version" << std::endl;
    std::ifstream file("C:/Users/ashmi/OneDrive/Desktop/Assignment 2 CSCN73030/Assignment 2 CSCN73030/StudentData.txt");
#endif
    std::string line;

    // Check if the file opened 
    if (!file) {
        std::cerr << "Error file could not be opened." << std::endl;
        return 1;
    }

    // Reading and parsing
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string FirstName, LastName;

        // Take first anme and last name seperated by a comma
        if (std::getline(ss, FirstName, ',') && std::getline(ss, LastName)) {
            STUDENT_DATA student{ FirstName, LastName };


#ifdef PRE_RELEASE
            // If in pre-release mode, read the email (assuming it follows the same format)
            std::getline(ss, student.Email); // Read email if available
#endif


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
   
#ifdef PRE_RELEASE
        std::cout << ", Email: " << student.Email; // Print email in pre-release
#endif
        std::cout << std::endl;
    }
#endif

    return 0; // Return success
}


