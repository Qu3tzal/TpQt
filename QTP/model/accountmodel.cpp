#include "accountmodel.h"

#include <QtSql>
#include <QDebug>

#include "databasecreator.h"

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
