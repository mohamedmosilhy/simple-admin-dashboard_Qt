#pragma once
#include<iostream>
#include<QString>
#include<QVector>

/// this is the brief description for the Person class.
///
/// this class is for person and all his basic information which consist of his first name, last name, mobile, email, age, password and username

class Person {
    private:
      QString first_name;
      QString last_name;
      int age;
      QString mobile;
      QString email;
      QString password;
      QString username;

    public:
      /// Brief desc
      ///
      /// Parameterized constructor
      /// @param f describes first name of the person
      /// @param l describes last name of the person
      /// @param a describes age of the person
      /// @param m describes mobile of the person
      /// @param e describes email of the person
      /// @param p describes password of the person
      /// @param u describes username of the person
    Person(QString f, QString l, int a, QString m, QString e, QString p, QString u);

    /// Brief desc
    ///
    /// function that stores first name of the person
    /// @returns Nothing
    /// @param fn describes first name of the person
    void set_firstname(QString fn);

    /// Brief desc
    ///
    /// function that returns first name of the person
    /// @returns first name
    /// @param Nothing
    QString get_firstname();

    /// Brief desc
    ///
    /// function that stores last name of the person
    /// @returns Nothing
    /// @param ln describes last name of the person
    void set_lastname(QString ln);

    /// Brief desc
    ///
    /// function that returns last name of the person
    /// @returns last name
    /// @param Nothing
    QString get_lastname();

    /// Brief desc
    ///
    /// function that stores age of the person
    /// @returns Nothing
    /// @param ag describes age of the person
    void set_age(int ag);

    /// Brief desc
    ///
    /// function that returns age of the person
    /// @returns age
    /// @param Nothing
    int get_age();

    /// Brief desc
    ///
    /// function that stores mobile of the person
    /// @returns Nothing
    /// @param mob describes mobile of the person
    void set_mobile(QString mob);

    /// Brief desc
    ///
    /// function that returns mobile of the person
    /// @returns mobile
    /// @param Nothing
    QString get_mobile();

    /// Brief desc
    ///
    /// function that stores email of the person
    /// @returns Nothing
    /// @param em describes email of the person
    void set_email(QString em);

    /// Brief desc
    ///
    /// function that returns email of the person
    /// @returns email
    /// @param Nothing
    QString get_email();

    /// Brief desc
    ///
    /// function that stores pass of the person
    /// @returns Nothing
    /// @param pass describes pass of the person
    void set_password(QString pass);

    /// Brief desc
    ///
    /// function that returns password of the person
    /// @returns password
    /// @param Nothing
    QString get_password();

    /// Brief desc
    ///
    /// function that stores username of the person
    /// @returns Nothing
    /// @param un describes username of the person
    void set_username(QString un);

    /// Brief desc
    ///
    /// function that returns username of the person
    /// @returns username
    /// @param Nothing
    QString get_username();

};

