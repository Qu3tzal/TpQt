#ifndef STAFFDAO_H
#define STAFFDAO_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlTableModel>

#include "staff.h"

/**
 * @brief The StaffDAO class
 */
class StaffDAO
{
	public:
		/**
		 * @brief StaffDAO constructor
		 */
		StaffDAO();

		/**
		 * @brief getStaffList
		 * @return a list of staff
		 */
		QList<Staff> getStaffList();

		QList<QString> getStaffTypes();

	private:
		QSqlDatabase db;
};

#endif // STAFFDAO_H
