#pragma once
#include"course.h"
/// this is the brief description for the Admin class.
///
/// this class is for admin and all his basic information which consist of his username and password
class Admin
{
private:
    QString username;
    QString password;
public:
    /// Brief desc
    ///
    /// Parameterized constructor
    /// @param us describes username of the admin
    /// @param pass describes password of the admin
    Admin(QString us, QString pass);

    /// Brief desc
    ///
    /// function that stores username of the admin
    /// @param us describes username of the admin
    /// @returns Nothing
    void set_username(QString us);

    /// Brief desc
    ///
    /// function that stores password of the admin
    /// @param pass describes password of the admin
    /// @returns Nothing
    void set_password(QString pass);

    /// Brief desc
    ///
    /// function that returns the username of the admin
    /// @param Nothing
    /// @returns username
    QString get_username();

    /// Brief desc
    ///
    /// function that returns the password of the admin
    /// @param Nothing
    /// @returns password
    QString get_password();
};
