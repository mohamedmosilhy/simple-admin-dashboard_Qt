#ifndef PROFESSOR_H
#define PROFESSOR_H

#pragma once
#include<QString>
#include<vector>
#include"person.h"
using namespace std;

class Course;
/// this is the brief description for the Professor class.
///
/// this class inherits person class and all his basic information which consist of his first name, last name, mobile, email, age, password and username
/// in addition to title of the professor and his courses
class Professor :public Person{
    private:
        QString title;
        QVector<Course*> course;
    public:
        /// Brief desc
        ///
        /// Parameterized constructor
        /// @param fn describes first name of the professor
        /// @param ln describes last name of the professor
        /// @param age describes age of the professor
        /// @param mob describes mobile of the professor
        /// @param em describes email of the professor
        /// @param pass describes password of the professor
        /// @param us describes username of the professor
        /// @param prof_title describes title of the professor
        Professor (QString fn, QString ln, int age, QString mob, QString em, QString pass, QString us, QString prof_title);

        /// Brief desc
        ///
        /// function that stores title of the professor
        /// @returns Nothing
        /// @param prof_title describes title of the professor
        void set_title(QString prof_title);

        /// Brief desc
        ///
        /// function that stores first name of the professor
        /// @returns Nothing
        /// @param *prof_course describes professor course
        void set_course(Course *prof_course);

        /// Brief desc
        ///
        /// function that returns title of the professor
        /// @returns title
        /// @param Nothing
        QString get_title();

        /// Brief desc
        ///
        /// function that returns vector of the professor courses
        /// @returns vector of the professor courses
        /// @param Nothing
        QVector<Course*> get_course();
};

#endif // PROFESSOR_H
