#ifndef NEWWINDOW_H
#define NEWWINDOW_H

#include <QDialog>
#include<QMessageBox>
#include"database.h"
#include"admin.h"
#include<QListWidgetItem>
#include <QTabWidget>
#include<QTableWidgetItem>
using namespace std;

/// this is the brief description for the newWindow class.
///
/// this class is for all the methods done to apply changes in the screens
///
namespace Ui {
class newWindow;
}

class newWindow : public QDialog
{
    Q_OBJECT

public:
    DataBase database;
    explicit newWindow(QWidget *parent = nullptr);
    ~newWindow();

public slots:
    /// Brief desc
    ///
    /// function that checks if the user is a registerd admin using his username and password and comparing them to the ones stored
    /// opens the mainWindow screen
    /// @returns Nothing
    void on_Login_1_clicked();

    /// Brief desc
    ///
    /// function that shows the manage student screen when clicking on the student push button
    /// display the students' names in the list widget
    /// @returns Nothing
    void on_Student_clicked();

    /// Brief desc
    ///
    /// function that shows the manage professor screen when clicking on the professor push button
    /// display the professors' names in the list widget
    /// @returns Nothing
    void on_Professor_clicked();

    /// Brief desc
    ///
    /// function that shows the manage course screen when clicking on the course push button
    /// display the courses' names in the list widget
    /// @returns Nothing
    void on_Courses_clicked();

    /// Brief desc
    ///
    /// function that opens mainWindow screen
    /// @returns Nothing
    void on_pushButton_clicked();

    /// Brief desc
    ///
    /// function that opens addStudent screen
    /// @returns Nothing
    void on_AddStudent_clicked();

    /// Brief desc
    ///
    /// function that opens manageStudent screen
    /// @returns Nothing
    void on_prev_clicked();

    /// Brief desc
    ///
    /// function that opens manageStudent screen
    /// @returns Nothing
    void on_Done_clicked();

    /// Brief desc
    ///
    /// function that opens mainWindow screen
    /// @returns Nothing
    void on_pushButton_2_clicked();

    /// Brief desc
    ///
    /// function that opens addProfessor screen
    /// @returns Nothing
    void on_AddProfessor_clicked();

    /// Brief desc
    ///
    /// function that opens manageProfessor screen
    /// @returns Nothing
    void on_prev_2_clicked();

    /// Brief desc
    ///
    /// function that opens manageProfessor screen
    /// @returns Nothing
    void on_Done_2_clicked();

    /// Brief desc
    ///
    /// function that opens mainWindow screen
    /// @returns Nothing
    void on_pushButton_3_clicked();

    /// Brief desc
    ///
    /// function that checks if student's data is valid
    /// if valid, it disables editing that data and enables adding courses to that student
    /// @returns Nothing
    void on_Confirm_clicked();

    /// Brief desc
    ///
    /// function that checks if course's grade is valid
    /// if valid, it adds the course to the shown student and allows adding more courses to that student
    /// @returns Nothing
    void on_AddCourse_clicked();

    /// Brief desc
    ///
    /// function that searches for that student in the database using his username
    /// it shows his data
    /// @returns Nothing
    void on_listWidget_itemPressed(QListWidgetItem *item);

    /// Brief desc
    ///
    /// function that searches for the required student and lists all the possible students alphabetically in the list below
    /// @returns Nothing
    void on_Search_textEdited(const QString &arg1);

    /// Brief desc
    ///
    /// function that searches for that student in the database using his username
    /// it shows his data
    /// @returns Nothing
    void on_listWidget_2_itemPressed(QListWidgetItem *item);

    /// Brief desc
    ///
    /// function that searches for that professor in the database using his username
    /// it shows his data
    /// @returns Nothing
    void on_ProfessorsList_itemPressed(QListWidgetItem *item);

    /// Brief desc
    ///
    /// function that searches for the required professor and lists all the possible professors alphabetically in the list below
    /// @returns Nothing
    void on_Search_2_textEdited(const QString &arg1);

    /// Brief desc
    ///
    /// function that searches for that professor in the database using his username
    /// it shows his data
    /// @returns Nothing
    void on_SearchList_itemPressed(QListWidgetItem *item);

    /// Brief desc
    ///
    /// function that searches for that course in the database using its name
    /// it shows its data
    /// @returns Nothing
    void on_Courses_listWidget_itemPressed(QListWidgetItem *item);

    /// Brief desc
    ///
    /// function that checks if professor's data is valid
    /// if valid, it disables editing that data and enables adding courses to that professor
    /// @returns Nothing
    void on_Confirm_2_clicked();

    /// Brief desc
    ///
    /// it adds the course to the shown professor and allows adding more courses to that professor
    /// @returns Nothing
    void on_AddCourse_2_clicked();

    /// Brief desc
    ///
    /// function that searches for the required course and lists all the possible courses alphabetically in the list below
    /// @returns Nothing
    void on_Search_3_textEdited(const QString &arg1);

    /// Brief desc
    ///
    /// function that searches for that course in the database using its name
    /// it shows its data
    /// @returns Nothing
    void on_listWidget_3_itemPressed(QListWidgetItem *item);

    /// Brief desc
    ///
    /// function that checks if course's grade is valid and the student is registerd
    /// if valid, it adds the student to the shown course and allows adding more students to that course
    /// checks if the student is already enrolled in this course
    /// if so, the grade is edited
    /// finally, the table above is updated with new data
    /// @returns Nothing
    void on_AddStudent_3_clicked();

    /// Brief desc
    ///
    /// function that checks if the professor is registerd
    /// if so, the professor is added to that course
    /// finally, the list of professors teaching that course is updated
    /// @returns Nothing
    void on_AddProfessor_3_clicked();

    /// Brief desc
    ///
    /// generates a csv file from the data in our database
    /// @returns Nothing
    void on_export_2_clicked();

    /// Brief desc
    ///
    /// function that opens manageProfessor screen and shows the data of the professor chosen from the professor's list in courses screen
    /// @returns Nothing
    void on_listWidget_4_itemPressed(QListWidgetItem *item);

    /// Brief desc
    ///
    /// function that opens courses screen and shows the data of the course chosen from the courses's list in manageProfessor screen
    /// @returns Nothing
    void on_listWidget_profcourses_itemPressed(QListWidgetItem *item);

    /// Brief desc
    ///
    /// function that opens courses screen and shows the data of the course chosen from the courses's list in manageStudent screen
    /// @returns Nothing
    void on_listWidget_courses_itemPressed(QListWidgetItem *item);

    /// Brief desc
    ///
    /// function that opens manageStudent screen and shows the data of the student chosen from the student's table in courses screen
    /// @returns Nothing
    void on_tableWidget_itemClicked(QTableWidgetItem *item);

    /// Brief desc
    ///
    /// function that filters students in the table according to chosen range of grades
    /// @returns Nothing
    void on_comboBoxT_currentIndexChanged(int index);

    /// Brief desc
    ///
    /// function that shows the total grade (as a placeholder text) of chosen course in the line edit below
    /// @returns Nothing
    void on_CourseNameResult_currentTextChanged(const QString &arg1);

private:

    Ui::newWindow *ui;
};

#endif // NEWWINDOW_H
