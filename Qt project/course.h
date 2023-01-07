#pragma once
#include"professor.h"
#include"student.h"
#include<map>

/// this is the brief description for the Course class.
///
/// this class is for Course and all his basic information which consist of its total grade, name, hall, time, code, vector of professors and vector of students
class Course {
    private:
        int total_grade;
        QString name;
        QString hall;
        QString time;
        QString code;
        QVector<Professor*> prof;
        QVector<pair<Student*,int>> std;

    public:
        /// Brief desc
        ///
        /// Parameterized constructor
        /// @param Course_name describes name of the course
        /// @param Course_hall describes hall location of the course
        /// @param Course_time describes time of the course
        /// @param Course_code describes code of the course
        /// @param grade describes total grade of the course
        Course (QString Course_name, QString Course_hall, QString Course_time, QString Course_code,int grade);

        /// Brief desc
        ///
        /// function that returns the total grade of the course
        /// @returns total grade
        /// @param Nothing
        int get_total_grade();

        /// Brief desc
        ///
        /// function that stores the name of the course
        /// @returns Nothing
        /// @param Course_name describes name of the course
        void set_name (QString Course_name);

        /// Brief desc
        ///
        /// function that stores the hall location of the course
        /// @returns Nothing
        /// @param Course_hall describes hall location of the course
        void set_hall (QString Course_hall);

        /// Brief desc
        ///
        /// function that stores the time of the course
        /// @returns Nothing
        /// @param Course_time describes time of the course
        void set_time (QString Course_time);

        /// Brief desc
        ///
        /// function that stores the code of the course
        /// @returns Nothing
        /// @param Course_code describes code of the course
        void set_code (QString Course_code);

        /// Brief desc
        ///
        /// function that stores the professors that teach the course
        /// @returns Nothing
        /// @param *Course_prof describes the professor object
        void set_prof (Professor *Course_prof);

        /// Brief desc
        ///
        /// function that stores the students of the course and their grades
        /// @returns Nothing
        /// @param *Course_std describes the student object
        /// @param grade describes the student grade in the course
        void set_std (Student *Course_std, int grade);

        /// Brief desc
        ///
        /// function that returns the name of the course
        /// @returns name
        /// @param Nothing
        QString get_name ();

        /// Brief desc
        ///
        /// function that returns the hall location of the course
        /// @returns hall
        /// @param Nothing
        QString get_hall ();

        /// Brief desc
        ///
        /// function that returns the time of the course
        /// @returns time
        /// @param Nothing
        QString get_time ();

        /// Brief desc
        ///
        /// function that returns the code of the course
        /// @returns code
        /// @param Nothing
        QString get_code ();

        /// Brief desc
        ///
        /// function that returns the professors that teach the course
        /// @returns professors vector
        /// @param Nothing
        QVector<Professor*> get_prof ();

        /// Brief desc
        ///
        /// function that returns the students  that attend the course and their grades
        /// @returns students vector of pairs
        /// @param Nothing
        QVector<pair<Student*,int>> get_std ();

        /// Brief desc
        ///
        /// function that updates course grade of student
        /// @returns Nothing
        /// @param *Course_std describes the student object
        /// @param grade describes the student's updated grade
        /// @param index describes the student's index in the students vector
        void update (Student *Course_std, int grade,int index);
};

