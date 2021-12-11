#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

int main(int argc, char* argv[])
{
    // Read the file grades.txt (assumed to be in working dir)
    std::ifstream inStream {"grades.txt"};

    if (!inStream)
    {
        std::cerr << "Could not read file grades.txt" << std::endl;
        return 0;
    }

    // First line is the correct answers
    std::string correctAnswers;
    std::getline(inStream, correctAnswers);

    // Subsequent lines are split into pairs
    // 1st line: Students name
    // 2nd line: Their answers
    std::vector<std::string> students;
    std::vector<int> scores;
    while (!inStream.eof())
    {
        std::string studentName;
        std::getline(inStream, studentName);
        students.emplace_back(studentName);

        std::string answers;
        std::getline(inStream, answers);

        int score{0};
        for (int i=0; i < correctAnswers.size(); ++i)
        {
            if (correctAnswers[i] == answers[i])
            {
                ++score;
            }
        }

        scores.emplace_back(score);
    }
    

    // Output should be each student's grade (numerical)
    // With the average for the class

    std::cout << std::setw(10) << std::left << "Student" << std::setw(10) << std::right << "Score" << std::endl;
    std::cout << std::setw(20) << std::setfill('-') << "" << std::endl;

    std::cout << std::setfill(' ');

    int sum{0};
    for (int i=0; i < students.size(); ++i)
    {
        std::cout << std::setw(10) << std::left << students[i]
                << std::setw(10) << std::right << scores[i]
                << std::endl; 

        sum += scores[i];  
    }
    
    std::cout << std::setw(20) << std::setfill('-') << "" << std::endl;

    std::cout << std::setfill(' ');
    double average = (double) sum / scores.size();
    std::cout << std::setw(10) << std::left << "Average " << std::setw(10) << std::right << average << std::endl;

    return 0;
}