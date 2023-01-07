#pragma once
#include"person.h"
#include<map>
#include<QString>
using namespace std;
class Course;

/// this is the brief description for the student class.
///
/// this class inherits person class and all his basic information which consist of his first name, last name, mobile, email, age, password and username
/// in addition to grade year of the student, his courses and their grades
class Student : public Person {
    private:
      int gradeyear;
      QVector<pair <Course*,int>> courses;

    public:
      /// Brief desc
      ///
      /// Parameterized constructor
      /// @param fn describes first name of the student
      /// @param ln describes last name of the student
      /// @param age describes age of the student
      /// @param mob describes mobile of the student
      /// @param em describes email of the student
      /// @param pass describes password of the student
      /// @param us describes username of the student
      /// @param grdy describes grade year of the student
      Student(QString fn , QString ln , int age , QString mob ,QString em , QString pass , QString us , int grdy);

      /// Brief desc
      ///
      /// function that stores grade year of the student
      /// @returns Nothing
      /// @param grdy describes grade year of the student
      void set_gradeyear( int grdy);

      /// Brief desc
      ///
      /// function that returns grade year of the student
      /// @returns grade year
      /// @param Nothing
      int get_gradeyear();

      /// Brief desc
      ///
      /// function that stores course of the student and his grade in it
      /// @returns Nothing
      /// @param *c describes course of the student
      /// @param grade describes grade of the student
      void set_courses(Course *c , int grade);

      /// Brief desc
      ///
      /// function that returns vector of pairs that contains courses and their grades
      /// @returns vector of pairs that contains courses and their grades
      /// @param Nothing
      QVector<pair<Course* , int>>  get_courses();

      /// Brief desc
      ///
      /// function that updates course grade of student
      /// @returns Nothing
      /// @param *c describes the course object
      /// @param grade describes the course's updated grade
      /// @param index describes the course's index in the courses vector
      void updatec (Course*c , int grade, int index);
};
