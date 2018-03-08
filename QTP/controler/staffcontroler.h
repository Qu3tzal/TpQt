#ifndef STAFFCONTROLER_H
#define STAFFCONTROLER_H

#include "model/staffmodel.h"
#include "views/createstaffdialog.h"
#include <QString>

class StaffControler
{
public:
    StaffControler();

    void createStaff(QString firstName, QString lastName, QString type, QString login, QString password);
};

#endif // STAFFCONTROLER_H
