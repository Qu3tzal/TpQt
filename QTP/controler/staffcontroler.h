#ifndef STAFFCONTROLER_H
#define STAFFCONTROLER_H

#include "model/staffmodel.h"
#include "views/createstaffdialog.h"
#include <QString>

/**
 * @brief The StaffControler class
 */
class StaffControler
{
	public:
		/**
		 * @brief StaffControler constructor
		 */
		StaffControler();

		/**
		 * @brief createStaff create a new staff
		 * @param firstName the first name of the staff
		 * @param lastName the last name of the staff
		 * @param type the type of the staff ("Banquier A", "Banquier B", ...)
		 * @param login the login for the staff ONLY USED FOR type "Informaticien"
		 * @param password the login for the staff ONLY USED FOR type "Informaticien"
		 */
		void createStaff(QString firstName, QString lastName, QString type, QString login, QString password);
};

#endif // STAFFCONTROLER_H
