#include "admin.h"

Admin::Admin(QString us, QString pass)
{
    username = us;
    password = pass;
}
QString Admin::get_username(){
    return username;
}
QString Admin::get_password(){
    return password;
}
void Admin::set_username(QString us){
    username = us;
}
void Admin::set_password(QString pass){
    password = pass;
}
