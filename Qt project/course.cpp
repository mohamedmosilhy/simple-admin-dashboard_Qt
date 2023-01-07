#include "course.h"


Course :: Course (QString Course_name, QString Course_hall, QString Course_time, QString Course_code,int grade) {
    name = Course_name;
    hall = Course_hall;
    time = Course_time;
    code = Course_code;
    total_grade = grade;
}


int Course :: get_total_grade(){
    return total_grade;
}

void Course :: set_name (QString Course_name) {
    name = Course_name;
}

void Course :: set_hall (QString Course_hall) {
    hall = Course_hall;
}

void Course :: set_time (QString Course_time) {
    time = Course_time;
}

void Course :: set_code (QString Course_code) {
    code = Course_code;
}

void Course :: set_prof (Professor *Course_prof) {
    prof.push_back(Course_prof);
}

void Course :: set_std (Student *Course_std, int grade) {
    pair<Student*,int> p;
    p.first=Course_std;
    p.second=grade;
    std.push_back(p);
}
void Course :: update (Student *Course_std, int grade,int index){
    std[index].second = grade;
}

QString Course :: get_name () {
    return name;
}

QString Course :: get_hall () {
    return hall;
}

QString Course :: get_time () {
    return time;
}

QString Course :: get_code () {
    return code;
}

QVector<Professor*> Course :: get_prof () {
    return prof;
}

QVector<pair<Student*,int>> Course :: get_std () {
    return std;
}
