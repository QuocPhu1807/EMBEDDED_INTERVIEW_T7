#ifndef  _VECTOR_STUDENT_H
#define  _VECTOR_STUDENT_H

#include<iostream>
#include<vector>
#include<string>
#include<stdint.h>

using namespace std;

typedef enum{
    ADDOBJECT = 1,
    EDITOBJECTINLIST,
    ERASEOBJECTBYID,
    SEARCHNAME,
    SORTAVEGARESCORE,
    SORTNAME,
    PRINTSTUDENTLISTS 
}Functions;

typedef enum{
    VERYGOOD,
    GOOD,
    AVERAGE,
    WEAK
}TypeAcademicBackground;

typedef enum{
    MAN = 1,
    FEMALE
}TypeGender;

class Student{

    private:
        int StudentId;
        string StudentName;
        int StudentAge;
        TypeGender StudentGender;
        double MathScore;
        double PhysicalScore;
        double ChemistryScore;
        float AverageScore;

    public:
        Student(string ObjectName, int ObjectAge, TypeGender ObjectGener, double ObjectMathScore, double ObjectPhysicalScore, double ObjectChemstryScore);

        void SetObjectName(string ObjectName);
        void SetObjectAge(int ObjectAge);
        void SetObjectGender(TypeGender  ObjectGener);
        void SetObjectMathScore(double ObjectMathScore);
        void SetObjectChemstryScore(double ObjectChemstryScore);
        void SetObjectPhysicalScore(double ObjectPhysicalScore);

        int GetObjectId();
        string GetObjectName();
        int GetObjectAge();
        TypeGender GetObjectGender();
        double GetObjectMathScore();
        double GetObjectChemstryScore();
        double GetObjectPhysicalScore();
        float GetObjectAverageScore();
        TypeAcademicBackground GetObjectAcademyBackground();

};

void AddStudentIntoList(vector<Student> &ListOfStudents);

void FixObjectOfStudentList(vector<Student> &ListOfStudents);

void EraseStudentBasedOnID(vector<Student> &ListOfStudents);

void SearchNameOfObject(vector<Student> &ListOfStudents);

void SortByAverageScore(vector<Student> &ListOfStudents);

void SortNameOfStudent(vector<Student> &ListOfStudents);

void PrintListOfStudent(vector<Student> &ListOfStudents);


#endif // _VECTOR_STUDENT_H INCLUDED