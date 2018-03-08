#include "staffmodel.h"

StaffModel::StaffModel(QString firstName, QString lastName, QString type, QString login, QString password)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->type = type;
    this->login = login;
    this->password = password;
}

StaffModel::saveInBD()
{

}
