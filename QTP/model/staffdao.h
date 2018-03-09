#ifndef STAFFMODEL_H
#define STAFFMODEL_H

#include <QString>

class StaffDAO
{
	public:
		/**
		 * @brief StaffModel constructor
		 * @param firstName
		 * @param lastName
		 * @param type
		 * @param login
		 * @param password
		 */
		StaffDAO(QString firstName, QString lastName, QString type, QString login, QString password);

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

		void save();

	private:
		QString firstName;
		QString lastName;
		QString type;
		QString login;
		QString password;
};

#endif // STAFFMODEL_H
