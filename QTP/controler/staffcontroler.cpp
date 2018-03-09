#include "staffcontroler.h"

StaffControler::StaffControler()
{

}

void StaffControler::createStaff(QString firstName, QString lastName, QString type, QString login, QString password)
{
	StaffDAO staffModel(firstName, lastName, type, login, password);
	staffModel.save();
}
