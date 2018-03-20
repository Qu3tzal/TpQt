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

        /**
         * @brief getId in db from StaffType
         * @param label
         * @return the id of the staffType
         */
		static int getTypeIdFromLabel(QString label);

		/**
		 * @brief getLabel
		 * @param id
		 * @return the
		 */
		static QString getTypeLabelFromId(int id);

		/**
         * @brief addStaff
         * @param staff
         * @return bool the sucess flag of the query
         */
        static bool addStaff(Staff staff, QString login, QString password);
};

#endif // STAFFDAO_H
