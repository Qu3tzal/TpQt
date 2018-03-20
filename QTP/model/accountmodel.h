#ifndef ACCOUNTMODEL_H
#define ACCOUNTMODEL_H

#include <QString>

class AccountModel
{
	public:
		/**
		 * @brief createAccount
		 * @param login
		 * @param password
		 * @param idStaff
		 * @return the id of the account that has been created
		 */
		static int createAccount(QString login, QString password, int idStaff);

		/**
		 * @brief removeAccount
		 * @param id
		 */
		static void removeAccount(int id);
};

#endif // ACCOUNTMODEL_H
