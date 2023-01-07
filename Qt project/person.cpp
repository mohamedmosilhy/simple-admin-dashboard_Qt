#include "person.h"

Person::Person(QString fn, QString ln, int ag, QString mob, QString em, QString pass, QString un) {
    first_name=fn;
    last_name=ln;
    age=ag;
    mobile=mob;
    email=em;
    password=pass;
    username=un;
}

void Person::set_firstname(QString fn) {
    first_name=fn;
}
QString Person::get_firstname() {
    return first_name;
}
void Person::set_lastname(QString ln) {
    last_name=ln;
}
QString Person::get_lastname() {
    return last_name;
}
void Person::set_age(int ag) {
    age=ag;
}
int Person::get_age(){
    return age;
}
void Person::set_mobile(QString mob) {
    mobile=mob;
}
QString Person::get_mobile() {
    return mobile;
}
void Person::set_email(QString em) {
    email=em;
}
QString Person::get_email() {
    return email;
}
void Person::set_password(QString pass) {
    password=pass;
}
QString Person::get_password() {
    return password;
}
void Person::set_username(QString un) {
     username=un;
}
QString Person::get_username() {
    return username;
}
