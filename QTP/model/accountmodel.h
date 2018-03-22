#ifndef ACCOUNTMODEL_H
#define ACCOUNTMODEL_H

#include <QString>
#include "account.h"

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
		 * @param idStaff
		 */
		static void removeAccountOfStaff(int idStaff);

        /**
         * @brief getAccountById
         * @param id
         * @return the account according to the StaffId in DB
         */
        static Account getAccountById(int staffId);

        /**
         * @brief updateAccount in db
         * @param account
         */
        static void updateAccount(Account account);
};

#endif // ACCOUNTMODEL_H
