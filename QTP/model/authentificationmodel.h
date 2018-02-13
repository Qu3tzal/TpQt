#ifndef AUTHENTIFICATIONMODEL_H
#define AUTHENTIFICATIONMODEL_H

#include <QString>

/**
 * @brief This class only contacts the database then check the login/password.
 */
class AuthentificationModel
{
	public:
		/**
		 * @brief Connects to the database and checks the login/password.
		 * @param login
		 * @param password
		 * @return true if the login/password match
		 */
		static bool checkLogin(QString login, QString password);
};

#endif // AUTHENTIFICATIONMODEL_H
