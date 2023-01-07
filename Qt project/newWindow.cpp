#include "newWindow.h"
#include "ui_newWindow.h"
#include"fstream"


newWindow::newWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newWindow)

{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
//    QPixmap pix ("icon.png");
QIcon icon = QIcon(":/feather (1)/icon.png/");
    this->setWindowIcon(icon);
    this->setWindowTitle("Admin Dashboard");

}

newWindow::~newWindow()
{
    delete ui;
}

//7bt zraer
void newWindow::on_Login_1_clicked()
{

    if((ui->username_lineEdit->text()==database.admin[0].get_username()) && (ui->password_lineEdit->text())==(database.admin[0].get_password())){
        ui->stackedWidget->setCurrentIndex(6);
    }
    else{
        QMessageBox::critical(this,"Warning","username or password is incorrect");
    }
}


void newWindow::on_Student_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    for (int i = 0; i < database.students.size(); ++i) {
        QString fullname=database.students[i]->get_firstname()+" "+database.students[i]->get_lastname();
        ui->listWidget->addItem(database.students[i]->get_username());
    }
}


void newWindow::on_Professor_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    for (int i = 0; i < database.professors.size(); ++i) {
        QString fullname=database.professors[i]->get_firstname()+" "+database.professors[i]->get_lastname();
        ui->ProfessorsList->addItem(database.professors[i]->get_username());
    }
}


void newWindow::on_Courses_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
    for (int i = 0; i < database.courses.size(); ++i) {
        ui->Courses_listWidget->addItem(database.courses[i]->get_name());
    }
    ui->error_p->hide();
    ui->error_s->hide();
    QStringList list;
        list<<"Filter"<<"A"<<"B"<<"C"<<"D"<<"F";

        ui->comboBoxT->addItems(list);
}


void newWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
    ui->listWidget->clear();
}


void newWindow::on_AddStudent_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->label_grade->hide();
    ui->label_first_name->hide();
     ui->label_last_name->hide();
     ui->label_age->hide();
     ui->mobile_label->setText("Mobile number already exists");

    ui->username_label->hide();
    ui->mobile_label->hide();
    ui->email_label->hide();
    ui->CourseNameResult->clear();
    for (int i = 0; i < database.courses.size(); ++i) {
        ui->CourseNameResult->addItem(database.courses[i]->get_name());
    }
    ui->formGroupBox_2->hide();
    ui->Error->hide();
    ui->AddCourse->hide();
    ui->Done->hide();
}


void newWindow::on_prev_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void newWindow::on_Done_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->UsernameResult->clear();
    ui->PasswordResult->clear();
    ui->EmailResult_2->clear();
    ui->AgeResult_2->clear();
    ui->FirstNameResult_2->clear();
    ui->LastNameResult_2->clear();
    ui->MobileResult_2->clear();
    ui->formGroupBox->setDisabled(false);
    ui->Confirm->show();
    Student *st;
    int n = database.students.size()-1;
    st = database.students[n];
    QString fullname=st->get_firstname()+" "+st->get_lastname();
    ui->listWidget->addItem(st->get_username());
}


void newWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
    ui->ProfessorsList->clear();
    ui->groupBox_10->show();
    ui->AddProfessor->show();
    ui->listWidget_profcourses->clear();
}


void newWindow::on_AddProfessor_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    ui->label_first_name_2->hide();
    ui->label_last_name_2->hide();
    ui->label_age_2->hide();
    ui->label_mobile_2->setText("Mobile number already exists");

    ui->label_username_2->hide();
    ui->label_mobile_2->hide();
    ui->label_email_2->hide();
    ui->CourseNameResult_2->clear();
    for (int i = 0; i < database.courses.size(); ++i) {
        ui->CourseNameResult_2->addItem(database.courses[i]->get_name());
    }
    ui->formGroupBox_4->hide();
    ui->Error_2->hide();
    ui->AddCourse_2->hide();
    ui->Done_2->hide();
}


void newWindow::on_prev_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void newWindow::on_Done_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->UsernameResult_2->clear();
    ui->PasswordResult_2->clear();
    ui->EmailResult_4->clear();
    ui->AgeResult_4->clear();
    ui->FirstNameResult_4->clear();
    ui->LastNameResult_4->clear();
    ui->MobileResult_4->clear();
    ui->formGroupBox_3->setDisabled(false);
    ui->Confirm_2->show();
    Professor *prof;
    int n = database.professors.size()-1;
    prof = database.professors[n];
    QString fullname=prof->get_firstname()+" "+prof->get_lastname();
    ui->ProfessorsList->addItem(prof->get_username());
}


void newWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
    ui->Courses_listWidget->clear();
    ui->comboBoxT->clear();
}


void newWindow::on_Confirm_clicked()
{
    ui->username_label->hide();
    ui->mobile_label->hide();
    ui->email_label->hide();
    ui->label_first_name->hide();
    ui->label_last_name->hide();
    ui->label_age->hide();
    ui->mobile_label->setText("Mobile number already exists");

    QString username = ui->UsernameResult->text();

    QString password = ui->PasswordResult->text();

    QString email = ui->EmailResult_2->text();

    QString grade = ui->GradeYearResult_2 ->currentText();
    int x =grade.toInt() ;
    QString age = ui->AgeResult_2->text();
    int y =age.toInt();
    QString first = ui->FirstNameResult_2->text();

    QString last = ui->LastNameResult_2->text();

    QString number = ui->MobileResult_2 ->text();

    if(username!="" && password!="" && email!="" && age!="" && first!="" && last!="" && number!="" && grade!="" ){
        bool valid = true;
        if(!database.valid_string(first)){
            ui->label_first_name->show();
            valid = false;
        }
        if(!database.valid_string(last)){
            ui->label_last_name->show();
            valid = false;
        }
        if(!database.valid_int(age)){
            ui->label_age->show();
            valid = false;
        }
        if(!database.valid_int(number) || number.size()!=11 || number[0] != '0' || number[1] != '1' || (number[2]!= '0' && number[2]!= '1' && number[2]!= '2' && number[2]!= '5')){
            ui->mobile_label->setText("Invalid mobile number");
            ui->mobile_label->show();
            valid = false;
        }
        if(database.student_username_exist(username)){
            ui->username_label->show();
        }
        if(database.student_mobile_exist(number)){
            ui->mobile_label->show();
         }
        if(database.student_email_exist(email)){
            ui->email_label->show();
         }
        if(!database.student_username_exist(username) && !database.student_mobile_exist(number) && !database.student_email_exist(email) && valid){
           Student *s = new Student (first,last,y,number,email,password,username,x);
           database.students.push_back(s);

           ui->formGroupBox->setDisabled(true);
           ui->formGroupBox_2->show();
           ui->AddCourse->show();
           ui->Confirm->hide();
           ui->Error->hide();
           ui->prev->hide();
           ui->username_label->hide();
           ui->mobile_label->hide();
           ui->email_label->hide();
           ui->label_first_name->hide();
           ui->label_last_name->hide();
           ui->label_age->hide();
           ui->mobile_label->setText("Mobile number already exists");


            }
   }
   else {
        ui->Error->show();
   }

}


void newWindow::on_AddCourse_clicked()
{
    ui->label_grade->hide();
    QString coursen = ui->CourseNameResult->currentText();
    Course *c = database.search_for_course(coursen);
    QString g = ui->GradeResult ->text();
    int gg =g.toInt() ;
    if (database.valid_int(g)){
        if((gg>=0 && gg<=c->get_total_grade())){
            ui->CourseNameResult->removeItem(ui->CourseNameResult->currentIndex());
            Student *st;
            int n = database.students.size()-1;
            st = database.students[n];
            st->set_courses(c,gg);
            c->set_std(st,gg);
            ui->GradeResult->clear();
            ui->Done->show();
            ui->prev->show();
        }
        else{
            ui->label_grade->setText("Grade is out of range");
            ui->label_grade->show();
        }

    }
    else {
        ui->label_grade->setText("Invalid grade");
        ui->label_grade->show();
    }

}


void newWindow::on_listWidget_itemPressed(QListWidgetItem *item)
{
    ui->listWidget_courses->clear();
    ui->listWidget_coursegrade->clear();
    Student *st=database.search_for_student(item->text());
    ui->FirstNameResult->setText(st->get_firstname());
    ui->LastNameResult->setText(st->get_lastname());
    QString s;
    s.setNum(st->get_age());
    ui->AgeResult->setText(s);
    ui->MobileResult->setText(st->get_mobile());
    ui->EmailResult->setText(st->get_email());
    s.setNum(st->get_gradeyear());
    ui->GradeYearResult->setText(s);
    QVector <pair<Course*,int>> v=st->get_courses();
    for (int i = 0; i < v.size(); i++) {
        ui->listWidget_courses->addItem(v[i].first->get_name());
        QString string;
        string.setNum(v[i].second);
        Course* c = database.search_for_course(v[i].first->get_name());
        QString s = QString::number(c->get_total_grade());
        string = string + "/" + s;
        ui->listWidget_coursegrade->addItem(string);
    }
}


void newWindow::on_Search_textEdited(const QString &arg1)
{
    ui->listWidget_2->clear();
    for (int i = 0; i < database.students.size(); i++) {
        QString fullname=database.students[i]->get_firstname()+" "+database.students[i]->get_lastname();
        QString s=database.students[i]->get_username();
        bool t=false;
        for (int j = 0; j < arg1.size(); ++j) {
            if((arg1[j]==s[j]) || (arg1[j] == s[j].toUpper()))
                t=true;
            else{
                t=false;
                break;
            }
        }
        if(t)
            ui->listWidget_2->addItem(s);
    }
}


void newWindow::on_listWidget_2_itemPressed(QListWidgetItem *item)
{
    ui->listWidget_courses->clear();
    ui->listWidget_coursegrade->clear();
    Student *st=database.search_for_student(item->text());
    ui->FirstNameResult->setText(st->get_firstname());
    ui->LastNameResult->setText(st->get_lastname());
    QString s;
    s.setNum(st->get_age());
    ui->AgeResult->setText(s);
    ui->MobileResult->setText(st->get_mobile());
    ui->EmailResult->setText(st->get_email());
    s.setNum(st->get_gradeyear());
    ui->GradeResult->setText(s);
    QVector <pair<Course*,int>> v=st->get_courses();
    for (int i = 0; i < v.size(); i++) {
        ui->listWidget_courses->addItem(v[i].first->get_name());
        QString string;
        string.setNum(v[i].second);
        QString s = QString::number(v[i].first->get_total_grade());
        string = string + "/" + s;
        ui->listWidget_coursegrade->addItem(string);
    }
}


void newWindow::on_ProfessorsList_itemPressed(QListWidgetItem *item)
{
    ui->listWidget_profcourses->clear();
    Professor *prof=database.search_for_professor(item->text());
    ui->FirstNameResult_3->setText(prof->get_firstname());
    ui->LastNameResult_3->setText(prof->get_lastname());
    QString s;
    s.setNum(prof->get_age());
    ui->AgeResult_3->setText(s);
    ui->MobileResult_3->setText(prof->get_mobile());
    ui->EmailResult_3->setText(prof->get_email());
    ui->TitleResult->setText(prof->get_title());
    QVector<Course*> v=prof->get_course();
    for (int i = 0; i < v.size(); i++) {
        ui->listWidget_profcourses->addItem(v[i]->get_name());
    }
}



void newWindow::on_Search_2_textEdited(const QString &arg1)
{
    ui->SearchList->clear();
    for (int i = 0; i < database.professors.size(); i++) {
        QString fullname=database.professors[i]->get_firstname()+" "+database.professors[i]->get_lastname();

        QString s=database.professors[i]->get_username();
        bool t=false;
        for (int j = 0; j < arg1.size(); ++j) {
            if((arg1[j]==s[j]) || (arg1[j] == s[j].toUpper()))
                t=true;
            else{
                t=false;
                break;
            }
        }
        if(t)
            ui->SearchList->addItem(s);
    }
}


void newWindow::on_SearchList_itemPressed(QListWidgetItem *item)
{
    ui->listWidget_profcourses->clear();
    Professor *prof=database.search_for_professor(item->text());
    ui->FirstNameResult_3->setText(prof->get_firstname());
    ui->LastNameResult_3->setText(prof->get_lastname());
    QString s;
    s.setNum(prof->get_age());
    ui->AgeResult_3->setText(s);
    ui->MobileResult_3->setText(prof->get_mobile());
    ui->EmailResult_3->setText(prof->get_email());
    ui->TitleResult->setText(prof->get_title());
    QVector<Course*> v=prof->get_course();
    for (int i = 0; i < v.size(); i++) {
        ui->listWidget_profcourses->addItem(v[i]->get_name());
    }
}


void newWindow::on_Courses_listWidget_itemPressed(QListWidgetItem *item)
{
    ui->comboBoxT->setCurrentIndex(0);
    ui->listWidget_4->clear();
    Course *c = database.search_for_course(item->text());
    ui->CourseNameResult_3->setText(c->get_name());
    QVector<Professor*> prof=c->get_prof();
    QString fullname=prof[0]->get_firstname()+" "+prof[0]->get_lastname();
    ui->listWidget_4->addItem(prof[0]->get_username());
    ui->listWidget_4->addItem("  ");
    QString s = QString::number(c->get_total_grade());
    ui->StudentGradeEdit->setPlaceholderText(s);
    for (int i = 1; i < prof.size(); ++i) {
        QString fullname=prof[i]->get_firstname()+" "+prof[i]->get_lastname();
        ui->listWidget_4->addItem("& ");
        ui->listWidget_4->addItem(prof[i]->get_username());
        ui->listWidget_4->addItem("  ");
    }
    ui->LectureHallResult->setText(c->get_hall());
    ui->TimeResult->setText(c->get_time());
    ui->CodeResult->setText(c->get_code());
    QVector<pair<Student*,int>> v = c->get_std();
    QStringList tlabels;
    tlabels<<"Name"<<"Grade(%)";
    ui->tableWidget->setHorizontalHeaderLabels(tlabels);
    ui->tableWidget->setRowCount(v.size());
    for (int i = 0; i < ui->tableWidget->rowCount() ; ++i) {
            QTableWidgetItem *item;
            for (int j = 0; j < ui->tableWidget->columnCount(); ++j) {
                item = new QTableWidgetItem;
                if (j==0){
                    QString fullname=v[i].first->get_firstname()+" "+v[i].first->get_lastname();
                    item->setText(fullname);
                }
                if (j==1){
                    float x = (v[i].second * 100.0 / c->get_total_grade());
                    x = ceil(x*100.0) / 100.0;
                    QString s = QString::number(x) + "%";
                    item->setText(s);
                }
                ui->tableWidget->setItem(i,j,item);

            }
        }
}


void newWindow::on_Confirm_2_clicked()
{
    ui->label_username_2->hide();
    ui->label_mobile_2->hide();
    ui->label_email_2->hide();
    ui->label_first_name_2->hide();
    ui->label_last_name_2->hide();
    ui->label_age_2->hide();
    ui->label_mobile_2->setText("Mobile number already exists");

    QString username = ui->UsernameResult_2->text();

    QString password = ui->PasswordResult_2->text();

    QString email = ui->EmailResult_4->text();

    QString title = ui->TitleResult_2 ->currentText();

    QString age = ui->AgeResult_4->text();
    int y =age.toInt();
    QString first = ui->FirstNameResult_4->text();

    QString last = ui->LastNameResult_4->text();

    QString number = ui->MobileResult_4 ->text();

    if(username!="" && password!="" && email!="" && age!="" && first!="" && last!="" && number!="" && title!="" ){
        bool valid = true;
        if(!database.valid_string(first)){
            ui->label_first_name_2->show();
            valid = false;
        }
        if(!database.valid_string(last)){
            ui->label_last_name_2->show();
            valid = false;
        }
        if(!database.valid_int(age)){
            ui->label_age_2->show();
            valid = false;
        }
        if(!database.valid_int(number) || number.size()!=11 || number[0] != '0' || number[1] != '1' || (number[2]!= '0' && number[2]!= '1' && number[2]!= '2' && number[2]!= '5')){
            ui->label_mobile_2->setText("Invalid mobile number");
            ui->label_mobile_2->show();
            valid = false;
        }
        if(database.professor_username_exist(username)){
            ui->label_username_2->show();
        }
        if(database.professor_mobile_exist(number)){
            ui->label_mobile_2->show();
         }
        if(database.professor_email_exist(email)){
            ui->label_email_2->show();
         }
        if(!database.professor_username_exist(username) && !database.professor_mobile_exist(number) && !database.professor_email_exist(email) && valid){
            Professor *p = new Professor (first,last,y,number,email,password,username,title);
            database.professors.push_back(p);

            ui->formGroupBox_3->setDisabled(true);
            ui->formGroupBox_4->show();
            ui->AddCourse_2->show();
            ui->Confirm_2->hide();
            ui->Error_2->hide();
            ui->prev_2->hide();
            ui->label_username_2->hide();
            ui->label_mobile_2->hide();
            ui->label_email_2->hide();
            ui->label_first_name_2->hide();
            ui->label_last_name_2->hide();
            ui->label_age_2->hide();
            ui->label_mobile_2->setText("Mobile number already exists");
        }
    }

    else {

        ui->Error_2->show();
    }
  }



void newWindow::on_AddCourse_2_clicked()
{
    QString coursen = ui->CourseNameResult_2->currentText();
    ui->CourseNameResult_2->removeItem(ui->CourseNameResult_2->currentIndex());
    Course *c = database.search_for_course(coursen);
    Professor *prof;
    int n = database.professors.size()-1;
    prof = database.professors[n];
    prof->set_course(c);
    c->set_prof(prof);
    ui->Done_2->show();
    ui->prev_2->show();
}


void newWindow::on_Search_3_textEdited(const QString &arg1)
{
    ui->listWidget_3->clear();
    for (int i = 0; i < database.courses.size(); i++) {
        QString c=database.courses[i]->get_name();
        bool t=false;
        for (int j = 0; j < arg1.size(); ++j) {
            if((arg1[j]==c[j]) || (arg1[j] == c[j].toLower()))
                t=true;
            else{
                t=false;
                break;
            }
        }
        if(t)
            ui->listWidget_3->addItem(c);
    }
}


void newWindow::on_listWidget_3_itemPressed(QListWidgetItem *item)
{
    ui->listWidget_4->clear();
    Course *c = database.search_for_course(item->text());
    ui->CourseNameResult_3->setText(c->get_name());
    QVector<Professor*> prof=c->get_prof();
    for (int i = 0; i < prof.size(); ++i) {

        QString fullname=prof[i]->get_firstname()+" "+prof[i]->get_lastname();

        ui->listWidget_4->addItem(prof[i]->get_username());
        ui->listWidget_4->addItem("  ");
    }
    ui->LectureHallResult->setText(c->get_hall());
    ui->TimeResult->setText(c->get_time());
    ui->CodeResult->setText(c->get_code());



}


void newWindow::on_AddStudent_3_clicked()
{
    QString stdname=ui->StudentNameEdit->text();
//    stdname[0]=stdname[0].toUpper();
//    for (int i = 0; i < stdname.size(); ++i) {
//        if (stdname[i] == ' '){
//            stdname[i+1]=stdname[i+1].toUpper();
//            break;
//        }
//    }
    QString stdgrade=ui->StudentGradeEdit->text();
    int x = stdgrade.toInt();
    Student *st = database.search_for_student(stdname);
    QString s = ui->CourseNameResult_3->text();
    Course *c=database.search_for_course(s);

    if(database.valid_int(stdgrade)) {
        if(x>=0 && x<= c->get_total_grade()){
            QVector<pair<Course* , int>> vc  =st->get_courses() ;
            QVector<QString> sc;
            int t=0;
            for (int i = 0; i < vc.size(); ++i) {
                sc.push_back(vc[i].first->get_name());
                if(c->get_name()==vc[i].first->get_name()){
                    t=i;
                }

            }
        //t=sc.indexOf(stdname);
            QVector<pair<Student* , int>> vv  =c->get_std() ;
            QVector<QString> ss;
            int y=0;
            for (int i = 0; i < vv.size(); ++i) {
                QString fullname=vv[i].first->get_firstname()+" "+vv[i].first->get_lastname();
                ss.push_back(vv[i].first->get_username());
            }
        //    y = ss.indexOf(stdname);
            y = database.f_st_in_Table(stdname,ss);
            if(st==database.ErrorS){
            ui->error_s->setText("Student Not Found");
                ui->error_s->show();
            }
            else if(ss.contains(stdname)){
                c->update(st,x,y);
               st->updatec(c , x , t);
               ui->error_s->setText("Student's grade updated ");
               ui->error_s->show();
            }
            else {
                ui->error_s->hide();
                st->set_courses(c,x);
                c->set_std(st,x);
                ui->StudentNameEdit->clear();
                 ui->StudentGradeEdit->clear();
            }
            ui->tableWidget->clear();
        QStringList tlabels;
        tlabels<<"Name"<<"Grade";
        ui->tableWidget->setHorizontalHeaderLabels(tlabels);
            QVector<pair<Student*,int>> v = c->get_std();
            ui->tableWidget->setRowCount(v.size());
            for (int i = 0; i < ui->tableWidget->rowCount() ; ++i) {
                QTableWidgetItem *item;
                for (int j = 0; j < ui->tableWidget->columnCount(); ++j) {
                    item = new QTableWidgetItem;
                    if (j==0){
                    QString fullname=v[i].first->get_firstname()+" "+v[i].first->get_lastname();
                        item->setText(fullname);
                    }
                    if (j==1){
                        float x = (v[i].second * 100.0 / c->get_total_grade());
                        x = ceil(x*100.0) / 100.0;
                        QString s = QString::number(x) + "%";
                        item->setText(s);
                    }
                    ui->tableWidget->setItem(i,j,item);
                }
            }
        }

        else {
            ui->error_s->setText("Grade is out of range");
            ui->error_s->show();
        }

    }
    else {
        ui->error_s->setText("Invalid grade");
        ui->error_s->show();
    }


}


void newWindow::on_AddProfessor_3_clicked()
{
    QString profname=ui->ProfessorNameEdit->text();
//    profname[0]=profname[0].toUpper();
//    for (int i = 0; i < profname.size(); ++i) {
//        if (profname[i] == ' '){
//            profname[i+1]=profname[i+1].toUpper();
//            break;
//        }
//    }
    Professor *prof = database.search_for_professor(profname);
    ui->error_p->hide();


    QString s = ui->CourseNameResult_3->text();
    Course *c=database.search_for_course(s);
    QVector<Professor*> vv  = c->get_prof();
    QVector<QString> ss;
    for (int i = 0; i < vv.size(); ++i) {
        QString fullname=vv[i]->get_firstname()+" "+vv[i]->get_lastname();
        ss.push_back(vv[i]->get_username());}
    if(prof==database.ErrorP){
        ui->error_p->setText("Professor not found");
        ui->error_p->show();

    }
    else if(ss.contains(profname)){
        ui->error_p->show();
        ui->error_p->setText("Professor Already in this course");
    }

    else{
        ui->error_p->hide();
        QString s = ui->CourseNameResult_3->text();
        Course *c=database.search_for_course(s);
        prof->set_course(c);
        c->set_prof(prof);
        ui->ProfessorNameEdit->clear();
        QString fullname=prof->get_firstname()+" "+prof->get_lastname();
        ui->listWidget_4->addItem("& ");
        ui->listWidget_4->addItem(prof->get_username());
    }
}


void newWindow::on_export_2_clicked()
{
    string g = QCoreApplication::applicationDirPath().toStdString() + "/data.csv";
    fstream fout;
    fout.open(g, ios::out | ios::trunc);
    fout<<"Students"<<","<<"firstname"<<","
       <<"lastname"<<","
       <<"age"<<","
       <<"email"<<","
       <<"mobile"<<","
       <<"username"<<","
       <<"password"<<","
       <<"courses"<<","
       <<"grades"<<endl;
    for(int i = 0; i< database.students.size(); i++){
        fout<<i<<","<<database.students[i]->get_firstname().toStdString()<<","
           <<database.students[i]->get_lastname().toStdString()<<","
           <<database.students[i]->get_age()<<","
           <<database.students[i]->get_email().toStdString()<<","
           <<database.students[i]->get_mobile().toStdString()<<","
           <<database.students[i]->get_username().toStdString()<<","
           <<database.students[i]->get_password().toStdString()<<",";
        for(auto j : database.students[i]->get_courses()){
            fout<<j.first->get_name().toStdString()<<","
                <<j.second<<",";
        }
        fout<<endl;
    }
    fout<<endl;

    fout<<"Professors"<<","<<"firstname"<<","
       <<"lastname"<<","
       <<"age"<<","
       <<"email"<<","
       <<"mobile"<<","
       <<"username"<<","
       <<"password"<<","
       <<"courses"<<endl;

    for(int i = 0; i< database.professors.size(); i++){
        fout<<i<<","<<database.professors[i]->get_firstname().toStdString()<<","
           <<database.professors[i]->get_lastname().toStdString()<<","
           <<database.professors[i]->get_age()<<","
           <<database.professors[i]->get_email().toStdString()<<","
           <<database.professors[i]->get_mobile().toStdString()<<","
           <<database.professors[i]->get_username().toStdString()<<","
           <<database.professors[i]->get_password().toStdString()<<",";
        for(auto j : database.professors[i]->get_course()){
            fout<<j->get_name().toStdString()<<",";
        }
        fout<<endl;
    }

    fout<<endl;

    fout<<"Courses"<<","<<"name"<<","
       <<"hall"<<","
       <<"time"<<","
       <<"code"<<","
       <<"students"<<",";
         for(int j =0; j<database.students.size()-1;j++){
             fout<<""<<",";
         }
         fout<<"professors"<<endl;
    for(int i = 0; i< database.courses.size(); i++){
        fout<<i<<","<<database.courses[i]->get_name().toStdString()<<","
           <<database.courses[i]->get_hall().toStdString()<<","
           <<database.courses[i]->get_time().toStdString()<<","
           <<database.courses[i]->get_code().toStdString()<<",";
        for(auto std : database.courses[i]->get_std()){
            fout<<std.first->get_firstname().toStdString()<<",";
        }
        fout<<","<<",";
        for(auto prof : database.courses[i]->get_prof()){
            fout<<prof->get_firstname().toStdString()<<",";
        }
         fout<<endl;
    }
    fout<<endl;
    fout.close();
    QMessageBox::information(this,"confirm","done");
}


void newWindow::on_listWidget_4_itemPressed(QListWidgetItem *item)
{   if(item->text()!="& "){
    ui->Courses_listWidget->clear();
    on_Professor_clicked();
    on_ProfessorsList_itemPressed(item);
    ui->comboBoxT->clear();
}
}


void newWindow::on_listWidget_profcourses_itemPressed(QListWidgetItem *item)
{
    ui->ProfessorsList->clear();
    on_Courses_clicked();
    on_Courses_listWidget_itemPressed(item);
    //ui->comboBoxT->clear();
}


void newWindow::on_listWidget_courses_itemPressed(QListWidgetItem *item)
{
    ui->listWidget->clear();
    on_Courses_clicked();
    on_Courses_listWidget_itemPressed(item);
}





void newWindow::on_tableWidget_itemClicked(QTableWidgetItem *item)
{
    ui->comboBoxT->clear();
    int x = item->row();
        Course *c = database.search_for_course(ui->CourseNameResult_3->text());
        QVector <pair<Student*,int>> v = c->get_std();
        Student *stu = v[x].first;
    if(stu!=database.ErrorS){
    ui->Courses_listWidget->clear();
    on_Student_clicked();

            ui->listWidget_courses->clear();
            ui->listWidget_coursegrade->clear();
            Student *st=v[x].first;
            ui->FirstNameResult->setText(st->get_firstname());
            ui->LastNameResult->setText(st->get_lastname());
            QString s;
            s.setNum(st->get_age());
            ui->AgeResult->setText(s);
            ui->MobileResult->setText(st->get_mobile());
            ui->EmailResult->setText(st->get_email());
            s.setNum(st->get_gradeyear());
            ui->GradeYearResult->setText(s);
            QVector <pair<Course*,int>> v=st->get_courses();
            for (int i = 0; i < v.size(); i++) {
                ui->listWidget_courses->addItem(v[i].first->get_name());
                QString string;
                string.setNum(v[i].second);
                QString s = QString::number(c->get_total_grade());
                string = string + "/" + s;
                ui->listWidget_coursegrade->addItem(string);
            }
}
}

void newWindow::on_comboBoxT_currentIndexChanged(int index)
{
    QString s = ui->CourseNameResult_3->text();
    Course *c=database.search_for_course(s);
    QVector<pair<Student*,int>> v = c->get_std();
    for (int i = 0; i < ui->tableWidget->rowCount(); ++i) {
     ui->tableWidget->showRow(i);

    }

    if(index==1){
            for (int j=0 ; j<ui->tableWidget->rowCount(); j++ ) {
                ui->tableWidget->hideRow(j);
                float x = (v[j].second * 100.0 / c->get_total_grade());
                x = ceil(x*100.0) / 100.0;
                if(x >= 90 ){

                   ui->tableWidget->showRow(j);

                }

            }
        }
        else if(index==2){
            for (int j=0 ; j<ui->tableWidget->rowCount(); j++ ) {
                ui->tableWidget->hideRow(j);
                float x = (v[j].second * 100.0 / c->get_total_grade());
                x = ceil(x*100.0) / 100.0;
                if(x >= 80 && x< 90 ){

                   ui->tableWidget->showRow(j);

                }

            }
        }

        else if(index==3){
            for (int j=0 ; j<ui->tableWidget->rowCount() ; j++ ) {
                    ui->tableWidget->hideRow(j);
                    float x = (v[j].second * 100.0 / c->get_total_grade());
                    x = ceil(x*100.0) / 100.0;
                if(x >= 70 && x < 80 ){

                   ui->tableWidget->showRow(j);

                }

            }
        }

        else if(index==4){
            for (int j=0 ; j<ui->tableWidget->rowCount(); j++ ) {
                ui->tableWidget->hideRow(j);
                float x = (v[j].second * 100.0 / c->get_total_grade());
                x = ceil(x*100.0) / 100.0;
                if(x >= 60 && x < 70 ){

                   ui->tableWidget->showRow(j);

                }

            }
        }

        else if(index==5){
            for (int j=0 ; j < ui->tableWidget->rowCount(); j++ ) {
                ui->tableWidget->hideRow(j);
                float x = (v[j].second * 100.0 / c->get_total_grade());
                x = ceil(x*100.0) / 100.0;
                if(x <60){

                   ui->tableWidget->showRow(j);

                }

            }
        }
    }



void newWindow::on_CourseNameResult_currentTextChanged(const QString &arg1)
{
    Course* c = database.search_for_course(arg1);
    QString s = QString::number(c->get_total_grade());
    ui->GradeResult->setPlaceholderText(s);
}




//7mdla 3al slama <3





