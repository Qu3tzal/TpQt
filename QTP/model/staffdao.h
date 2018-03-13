#ifndef STAFFDAO_H
#define STAFFDAO_H

#include <QtSql/QSqlDatabase>

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
		 * @return a model pointer
		 */
		QList<Staff> getStaffList();

	private:
		QSqlDatabase db;
};

#endif // STAFFDAO_H
