#include "staff.h"

Staff::Staff(QString firstName, QString lastName, QString type, QString login, QString password)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->type = type;
    this->login = login;
    this->password = password;
}

void Staff::save()
{

}
