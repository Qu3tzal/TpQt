#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QString>

class Account
{
	public:
		/**
		 * @brief Account constructor
		 * @param id
		 * @param idStaff
		 * @param login
		 * @param password
		 */
		Account(int id, int idStaff, QString login, QString password);

		/*
		 * Getters.
		 */
		int getId() const {return id;}
		int getIdStaff() const {return idStaff;}
		QString getLogin() const {return login;};
		QString getPassword() const {return password;}

	private:
		int id, idStaff;
		QString login, password;
};

#endif // ACCOUNT_H
