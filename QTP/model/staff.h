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
		 * @brief getType
		 * @return the staff type
		 */
		QString getType() const {return type;}

		/**
		 * @brief getLogin
		 * @return the staff login
		 */
		QString getLogin() const {return login;}

		/**
		 * @brief getPassword
		 * @return the staff password
		 */
		QString getPassword() const {return password;}

	private:
		int id;
		QString firstName;
		QString lastName;
		QString type;
		QString login;
		QString password;
};

#endif // STAFF_H
