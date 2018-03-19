#ifndef STAFF_H
#define STAFF_H

#include <QString>

class Staff
{
	public:
		/**
		 * @brief StaffModel constructor
		 * @param id
		 * @param firstName
		 * @param lastName
		 * @param type
		 */
		Staff(int id, QString firstName, QString lastName, int type);

		/**
		 * @brief getID
		 * @return  the staff id
		 */
		int getId() const {return id;}

		/**
		 * @brief getFirstName
		 * @return the staff firstname
		 */
		QString getFirstName() const {return firstName;}

		/**
		 * @brief getLastName
		 * @return the staff lastname
		 */
		QString getLastName() const {return lastName;}

		/**
		 * @brief getTypeId
		 * @return the staff type id
		 */
		int getTypeId() const {return type;}

	private:
		int id;
		QString firstName;
		QString lastName;
		int type;
};

#endif // STAFF_H
