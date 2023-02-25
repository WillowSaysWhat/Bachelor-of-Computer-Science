#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class StudentPerformace
{
private:
    string name;
    double academicScore = 0,
           extraCurricularScore = 0;

public:
    StudentPerformace() // Default Constructor
    {
        setStudent();
    }
    void setStudent(); // setStudent prototype

    string GetName() // getName
    {
        return name;
    }
    int getAcademicScore() // getAcademicScore
    {
        return academicScore;
    }
    int getExtraCurricularScore() // getExtraCurricularScore
    {
        return extraCurricularScore;
    }
    double getPerformance() // getPerformace
    {
        return (academicScore * 0.75) + (extraCurricularScore * 0.25); // math
    }
    char getGrade(); // getGrade prototype
};

void StudentPerformace::setStudent() // setStudent
{
    getline(cin, name); // get the name

    do
    {
        cin >> academicScore;                                // get input for academic score
    } while (!(academicScore >= 0 && academicScore <= 100)); // loop if the value is greater than 100

    do
    {
        cin >> extraCurricularScore;                                  // get input for extra curricular score
    } while (extraCurricularScore < 0 && extraCurricularScore > 100); // loop if value is greater than 100
}

char StudentPerformace::getGrade() // getGrade
{
    /*0 – 39% = F
    40 – 49% = D
    50 – 59% = C
    60 – 69% = B
    70 – 100% = A
    */
    int total = getPerformance(); // return value for 'getPerformance'
    char outcome = 'A';           // create variable with value 'A'

    if (total < 40) // if total is less than 40
    {
        outcome = 'F';
    }
    else if (total >= 40 && total < 50) // if total is 40 - 49
    {
        outcome = 'D';
    }
    else if (total >= 50 && total < 60) // if total is 50 - 59
    {
        outcome = 'C';
    }
    else if (total >= 60 && total < 70) // if total is 60 - 69
    {
        outcome = 'B';
    }
    return outcome; // return variable
}

int main()
{

    StudentPerformace ThisStudent; // initialising object

    cout << "Student " << ThisStudent.GetName() << endl                                               // display student name
         << "Performance " << fixed << setprecision(2) << ThisStudent.getPerformance() << '%' << endl // dislay student performance
         << ThisStudent.getGrade();                                                                   // display grade
}
