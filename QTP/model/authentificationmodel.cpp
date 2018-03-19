#include "authentificationmodel.h"
#include <QtSql>

#include "databasecreator.h"

bool AuthentificationModel::checkLogin(const QString& login, const QString& password)
{
	QSqlDatabase db = DatabaseCreator::getInstance();

	QSqlQuery query(db);
	query.prepare("SELECT id FROM TCompte WHERE Login = ? AND MdP = ?");
	query.bindValue(0, login);
	query.bindValue(1, password);
	query.exec();

	// If we have at least one result, we can log.
	return query.first();
}
