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
		 * @param login
		 * @param password
		 */
		Staff(int id, QString firstName, QString lastName, QString type, QString login, QString password);

		/**
		 * @brief getID
		 * @return  the staff id
		 */
		int getId() {return id;}

		/**
		 * @brief getFirstName
		 * @return the staff firstname
		 */
		QString getFirstName() {return firstName;}

		/**
		 * @brief getLastName
		 * @return the staff lastname
		 */
		QString getLastName() {return lastName;}

		/**
		 * @brief getType
		 * @return the staff type
		 */
		QString getType() {return type;}

		/**
		 * @brief getLogin
		 * @return the staff login
		 */
		QString getLogin() {return login;}

		/**
		 * @brief getPassword
		 * @return the staff password
		 */
		QString getPassword() {return password;}

	private:
		int id;
		QString firstName;
		QString lastName;
		QString type;
		QString login;
		QString password;
};

#endif // STAFF_H
