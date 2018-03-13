#ifndef STAFFDAO_H
#define STAFFDAO_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlTableModel>

/**
 * @brief The StaffDAO class
 */
class StaffDAOl
{
	public:
		/**
		 * @brief StaffDAO constructor
		 */
		StaffDAOl();

		/**
		 * @brief getStaffList
		 * @return a model pointer
		 */
		QSqlTableModel *getStaffList();

	private:
		QSqlDatabase db;
};

#endif // STAFFDAO_H
