#include "professor.h"
class Course;

Professor::Professor (QString fn , QString ln , int age , QString mob ,QString em , QString pass , QString us,QString prof_title):Person(fn , ln , age , mob , em , pass , us)
{
    title = prof_title;
}

void Professor::set_title(QString prof_title){
    title = prof_title;
}

void Professor::set_course(Course *prof_course){
    course.push_back(prof_course);
}

QString Professor:: get_title(){
    return title;
}

QVector<Course*> Professor:: get_course(){
    return course;
}
