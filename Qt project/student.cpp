#include "student.h"

Student::Student(QString fn , QString ln , int age , QString mob ,QString em , QString pass , QString us , int grdy)
      :Person(fn , ln , age , mob , em , pass , us)
    {
        gradeyear=grdy;
    }
void Student::set_gradeyear(int grdy){
    gradeyear=grdy;
}

int Student::get_gradeyear(){
    return gradeyear;
}

void Student::set_courses(Course *c , int grade){
    pair <Course* , int> p;
    p.first=c;
    p.second=grade;
    courses.push_back(p);
}
void Student::updatec (Course *c , int grade, int index){
    courses[index].second=grade;

}

QVector<pair<Course* , int>> Student::get_courses(){
    return courses ;
}
