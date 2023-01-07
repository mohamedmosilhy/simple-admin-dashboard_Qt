#ifndef LEARNING_MANAGEMENT_SYSTEM_DATABASE_H
#define LEARNING_MANAGEMENT_SYSTEM_DATABASE_H
#include<vector>
#include"admin.h"

/// this is the brief description for the DataBase class.
///
/// this class is for DataBase and all its basic information which consists of a number of vectors which are students, professors, admin and courses
class DataBase{

public:
    QVector<Student*> students;
    QVector<Professor*> professors;
    QVector<Admin> admin;
    QVector<Course*> courses;
    Student *ErrorS = new Student ("","",0,"","","","",0);
    Professor *ErrorP = new Professor ("","",0,"","","","","");

    /// Brief desc
    ///
    /// default constructor
    /// some objects generated on the fly from student, professor, admin and course and are pushed into database vectors
    DataBase(){

        Admin mina("mohamed","123");
        admin.push_back(mina);

        Course *Data = new Course("Data","3201","8:30","CMP2241",150);
        Course *Maths = new Course("Maths","3101","10:30","MTH2241",175);
        Course *Biochemistry = new Course("Biochemistry","3401","1:00","BCH2241",100);
        Course *General = new Course("General","3501","2:30","GEN2241",50);
        Course *Circuits = new Course("Circuits","3301","3:30","CIR2241",150);
        Course *Biology = new Course("Biology","3302","10:00","BIO2241",125);
        courses.push_back(Data);
        courses.push_back(Maths);
        courses.push_back(Biochemistry);
        courses.push_back(General);
        courses.push_back(Circuits);
        courses.push_back(Biology);





        Student *Mariem = new Student ("Mariem","Magdy",21,"01221150061","mariemmagdy68@gmail.com","marioma","mariem_magdy",2);
        Mariem->set_courses(Data,60);
        Data->set_std(Mariem,60);
        Mariem->set_courses(Maths,78);
        Maths->set_std(Mariem,78);
        Mariem->set_courses(Circuits,100);
        Circuits->set_std(Mariem,100);

        Student *Mina = new Student ("Mina","Adel",20,"0121011756","minaadel66@gmail.com","manmona","mina_adel",2);
        Mina->set_courses(Biology,74);
        Biology->set_std(Mina,74);
        Mina->set_courses(Biochemistry,94);
        Biochemistry->set_std(Mina,94);

        Student *Carol = new Student ("Carol","Emad",21,"01098525223","carolemad66@gmail.com","carcora","carol_emad",2);
        Carol->set_courses(General,50);
        General->set_std(Carol,50);
        Carol->set_courses(Maths,23);
        Maths->set_std(Carol,23);
        Carol->set_courses(Data,100);
        Data->set_std(Carol,100);
        Carol->set_courses(Biology,92);
        Biology->set_std(Carol,92);


        Student *Mirna = new Student ("Mirna","Ahmed",21,"01098665223","mirnaahmed66@gmail.com","marmora","mirna_ahmed",2);
        Mirna->set_courses(General,40);
        General->set_std(Mirna,40);
        Mirna->set_courses(Circuits,33);
        Circuits->set_std(Mirna,33);
        Mirna->set_courses(Data,90);
        Data->set_std(Mirna,90);
        Mirna->set_courses(Biology,92);
        Biology->set_std(Mirna,92);


        Student *Monika = new Student ("Monika","Adel",21,"01098525523","monikaadel66@gmail.com","moka","monika_adel",2);
        Monika->set_courses(Biochemistry,55);
        Biochemistry->set_std(Monika,55);
        Monika->set_courses(Maths,34);
        Maths->set_std(Monika,34);
        Monika->set_courses(Data,65);
        Data->set_std(Monika,65);
        Monika->set_courses(Biology,88);
        Biology->set_std(Monika,88);
        
        
        Student *Ali = new Student ("Ali","Maged",21,"01128525523","alimaged66@gmail.com","alilolo","ali_maged",3);
        Ali->set_courses(Biochemistry,77);
        Biochemistry->set_std(Ali,77);
        Ali->set_courses(Maths,85);
        Maths->set_std(Ali,85);
        Ali->set_courses(Data,96);
        Data->set_std(Ali,96);
        Ali->set_courses(Biology,93);
        Biology->set_std(Ali,93);




        students.push_back(Mariem);
        students.push_back(Mina);
        students.push_back(Ali);
        students.push_back(Monika);
        students.push_back(Mirna);
        students.push_back(Carol);





        Professor *Rana = new Professor ("Rana","Ibrahim",21,"01011546099","ranaibrahim68@gmail.com","ranona","rana_ibrahim","Professor");
        Rana->set_course(Data);
        Data->set_prof(Rana);
        Rana->set_course(Circuits);
        Circuits->set_prof(Rana);

        Professor *Nourhan = new Professor ("Nourhan","Ahmed",21,"01148995477","nourhanahmed68@gmail.com","nourhona","nourhan_ahmed","Assistant Professor");
        Nourhan->set_course(Biology);
        Biology->set_prof(Nourhan);
        Nourhan->set_course(Maths);
        Maths->set_prof(Nourhan);
        Nourhan->set_course(Data);
        Data->set_prof(Nourhan);

        Professor *Tahani = new Professor ("Tahani","Ahmed",21,"01148995477","tahaniahmed68@gmail.com","mtahani","tahani_ahmed","Professor");
        Tahani->set_course(Biology);
        Biology->set_prof(Tahani);
        Tahani->set_course(Maths);
        Maths->set_prof(Tahani);
        Tahani->set_course(Biochemistry);
        Biochemistry->set_prof(Tahani);

        Professor *Mohamed = new Professor ("Mohamed","Moselhy",21,"01147497471","mohamedmoselhy68@gmail.com","hackora","mohamed_moselhy","Instructor");
        Mohamed->set_course(Data);
        Data->set_prof(Mohamed);
        Mohamed->set_course(Biochemistry);
        Biochemistry->set_prof(Mohamed);
        Mohamed->set_course(General);
        General->set_prof(Mohamed);

        Professor *Fathy = new Professor ("Fathy","Mohamed",21,"01147497471","fathymohamed68@gmail.com","to7a","fathy_moh","Instructor");
        Fathy->set_course(Biochemistry);
        Biochemistry->set_prof(Fathy);
        Fathy->set_course(General);
        General->set_prof(Fathy);

        professors.push_back(Rana);
        professors.push_back(Nourhan);
        professors.push_back(Fathy);
        professors.push_back(Mohamed);
        professors.push_back(Tahani);

    }

    /// Brief desc
    ///
    /// function that returns course object from courses vector with the same name as the parameter
    /// @returns course object
    /// @param s describes course name searched for
    Course* search_for_course (QString s){
       for (int i = 0; i < courses.size(); i++) {
            QString ss=courses[i]->get_name();
            if(!s.compare(ss))
                return courses[i];
        }

       return courses[0];
    }

    /// Brief desc
    ///
    /// function that returns student object from students vector with the same name as the parameter
    /// @returns student object
    /// @param s describes student name searched for
    Student* search_for_student (QString s){
        for (int i = 0; i < students.size(); i++) {
            if(students[i]->get_username()==s)
                return students[i];
        }
        return ErrorS;
    }

    /// Brief desc
    ///
    /// function that returns student object from students vector with the same name as the parameter when both first and last names are concatenated
    /// @returns student object
    /// @param s describes student name searched for
    Student* search_for_studentf (QString s){
        for (int i = 0; i < students.size(); i++) {
            QString x= students[i]->get_firstname()+" "+students[i]->get_lastname();
            if(x==s)
                return students[i];
        }

        return ErrorS;
    }

    /// Brief desc
    ///
    /// function that returns professor object from professors vector with the same name as the parameter when both first and last names are concatenated
    /// @returns professor object
    /// @param s describes professor name searched for
    Professor* search_for_professorf (QString s){
        for (int i = 0; i < professors.size(); i++) {
            QString x= professors[i]->get_firstname()+" "+professors[i]->get_lastname();
            if(x==s)
                return professors[i];
        }

        return ErrorP;
    }

    /// Brief desc
    ///
    /// function that returns professor object from professors vector with the same name as the parameter
    /// @returns professor object
    /// @param s describes professor name searched for
    Professor* search_for_professor (QString s){
        for (int i = 0; i < professors.size(); i++) {
            if(professors[i]->get_username()==s)
                return professors[i];
        }

        return ErrorP;
    }

    /// Brief desc
    ///
    /// function that returns index of student in the table
    /// @returns index of student in the table
    /// @param y describes student name searched for
    /// @param x describes vector of names of students in that table
   int f_st_in_Table(QString y, QVector<QString> x){
        for (int i = 0; i < x.size(); ++i) {
            if(x[i]==y)
                return i;
        }
    }

   /// Brief desc
   ///
   /// function that returns true if the student's username exists in the students database vector else returns false
   /// @returns bool true if exists and false if not
   /// @param username describes username of student
   bool student_username_exist(QString username){
       for(int i = 0; i<students.size(); i++){
           if(students[i]->get_username() == username)
           {
               return true;
           }
       }
       return false;
   }

   /// Brief desc
   ///
   /// function that returns true if the student's mobile exists in the students database vector else returns false
   /// @returns bool true if exists and false if not
   /// @param mobile describes mobile of student
   bool student_mobile_exist(QString mobile){
       for(int i = 0; i<students.size(); i++){
           if(students[i]->get_mobile() == mobile)
           {
               return true;
           }
       }
       return false;
   }

   /// Brief desc
   ///
   /// function that returns true if the student's email exists in the students database vector else returns false
   /// @returns bool true if exists and false if not
   /// @param email describes email of student
   bool student_email_exist(QString email){
       for(int i = 0; i<students.size(); i++){
           if(students[i]->get_email() == email)
           {
               return true;
           }
       }
       return false;
   }

   /// Brief desc
   ///
   /// function that returns true if the professor's username exists in the professors database vector else returns false
   /// @returns bool true if exists and false if not
   /// @param username describes username of professor
   bool professor_username_exist(QString username){
       for(int i = 0; i<professors.size(); i++){
           if(professors[i]->get_username() == username)
           {
               return true;
           }
       }
       return false;
   }

   /// Brief desc
   ///
   /// function that returns true if the professor's mobile exists in the professors database vector else returns false
   /// @returns bool true if exists and false if not
   /// @param mobile describes mobile of professor
   bool professor_mobile_exist(QString mobile){
       for(int i = 0; i<professors.size(); i++){
           if(professors[i]->get_mobile() == mobile)
           {
               return true;
           }
       }
       return false;
   }

   /// Brief desc
   ///
   /// function that returns true if the professor's email exists in the professors database vector else returns false
   /// @returns bool true if exists and false if not
   /// @param email describes email of professor
   bool professor_email_exist(QString email){
       for(int i = 0; i<professors.size(); i++){
           if(professors[i]->get_email() == email)
           {
               return true;
           }
       }
       return false;
   }

   /// Brief desc
   ///
   /// function that checks whether input is string or not
   /// @returns bool true if it is a string and else false
   /// @param text describes input text
   bool valid_string(QString text){
       bool valid = false;
       for(auto i : text){
           int j = i.toLatin1();
           if((j>=65 && j<= 90) || (j>=97 && j<= 122)){
               valid = true;
           }
           else
               return false;
       }
       return valid;
   }

   /// Brief desc
   ///
   /// function that checks whether input is integer or not
   /// @returns bool true if it is a integer and else false
   /// @param text describes input text
   bool valid_int(QString text){
       bool valid = false;
       for(auto i : text){
           int j = i.toLatin1();
           if((j>=48 && j<= 57)){
               valid= true;
           }
           else
               return false;
       }
       return valid;
   }
};

#endif // DATABASE_H
