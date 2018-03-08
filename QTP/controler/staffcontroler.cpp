#include "staffcontroler.h"

StaffControler::StaffControler()
{

}

void StaffControler::createStaff(QString firstName, QString lastName, QString type, QString login, QString password)
{
    StaffModel staffModel(firstName, lastName, type, login, password);
    staffModel.saveInBD();
}
