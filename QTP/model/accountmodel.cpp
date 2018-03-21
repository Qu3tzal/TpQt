#include "accountmodel.h"

#include <QtSql>
#include <QDebug>

#include "databasecreator.h"
#include "account.h"

int AccountModel::createAccount(QString login, QString password, int idStaff)
{
	QSqlDatabase db = DatabaseCreator::getInstance();
	QSqlQuery query(db);

	query.prepare("INSERT INTO TCompte (IdRessource, Login, MdP) "
				  "VALUES (:id, :login, :mdp)");
	query.bindValue(":id", idStaff);
	query.bindValue(":login", login);
	query.bindValue(":mdp", password);

	if(!query.exec())
	{
		qDebug() << "Error while creating account : " << query.lastError();
	}

	return query.lastInsertId().toInt();
}

void AccountModel::removeAccountOfStaff(int idStaff)
{
	QSqlDatabase db = DatabaseCreator::getInstance();
	QSqlQuery query(db);

	query.prepare("DELETE FROM TCompte WHERE IdRessource = :id");
	query.bindValue(":id", idStaff);

	if(!query.exec())
	{
		qDebug() << "Error while removing account : " << query.lastError();
	}
}

Account AccountModel::getAccountById(int staffId)
{
    QSqlDatabase db = DatabaseCreator::getInstance();

    Account account(-1, -1, "", "");

    QSqlQuery query(db);

    query.prepare("SELECT Id, IdRessource, Login, MdP FROM TCompte WHERE IdRessource = :id");
    query.bindValue(":id", staffId);

    if(!query.exec())
    {
        qDebug() << "Error while getting Account : " << query.lastError().text();
    }
    else
    {
        if(query.first())
        {
            account = Account(query.value(0).toInt(), query.value(1).toInt(), query.value(2).toString(), query.value(3).toString());
        }
    }

    return account;
}

void AccountModel::updateAccount(Account account)
{
    QSqlDatabase db = DatabaseCreator::getInstance();

    QSqlQuery query(db);

    query.prepare("UPDATE TCompte SET (Login, MdP) VALUES (:login, :mdp) WHERE Id = :Id");
    query.bindValue(":login", account.getLogin());
    query.bindValue(":mdp", account.getPassword());
    query.bindValue(":Id", account.getId());

    if(!query.exec())
    {
        qDebug() << "Error while updating account : " << query.lastError();
    }
}
