#ifndef STAFFMODEL_H
#define STAFFMODEL_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlTableModel>

/**
 * @brief The StaffModel class
 */
class StaffModel
{
	public:
		/**
		 * @brief StaffModel constructor
		 */
		StaffModel();

		/**
		 * @brief getStaffList
		 * @return a model pointer
		 */
		QSqlTableModel *getStaffList();

	private:
		QSqlDatabase db;
};

#endif // STAFFMODEL_H
