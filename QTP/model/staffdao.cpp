#include "staffdao.h"

StaffDAO::StaffDAO(QString firstName, QString lastName, QString type, QString login, QString password)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->type = type;
    this->login = login;
    this->password = password;
}

void StaffDAO::save()
{

}
