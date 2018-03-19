#ifndef STAFFDAO_H
#define STAFFDAO_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlTableModel>

#include "staff.h"

/**
 * @brief The StaffType struct
 */
struct StaffType
{
		int id;
		QString label;
};

/**
 * @brief The StaffModel class
 */
class StaffModel
{
	public:

		/**
		 * @brief getStaffList
		 * @return a list of staff
		 */
		static QList<Staff> getStaffList();

		/**
		 * @brief getStaffListByType
		 * @param typeId the id of the type
		 * @return a list of staff
		 */
		static QList<Staff> getStaffListByType(int typeId);

		/**
		 * @brief getStaffTypes
		 * @return a list of staff types
		 */
		static QList<StaffType> getStaffTypes();
};

#endif // STAFFDAO_H
