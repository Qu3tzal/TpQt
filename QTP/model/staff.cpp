#include "staff.h"

Staff::Staff(int id, QString firstName, QString lastName, QString type, QString login, QString password)
{
	this->id = id;
    this->firstName = firstName;
    this->lastName = lastName;
    this->type = type;
    this->login = login;
    this->password = password;
}
