#include "clientmodel.h"

#include <QtSql>
#include <QDebug>

QList<Client> ClientModel::getClientsList()
{
	QList<Client> clients;

	QSqlDatabase db = DatabaseCreator::getInstance();

	QSqlQuery query(db);

	if(!query.exec("SELECT Id, Nom, Prenom, Adresse, Ville, CP, Commentaire, Tel, DateRdv, DureeRdv, Priorite FROM TClient"))
	{
		qDebug() << "Error while getting the client list : " << query.lastError();
	}
	else
	{
		while(query.first())
		{
			clients.append(Client(query.value(0).toInt(),
								  query.value(1).toString(),
								  query.value(2).toString(),
								  query.value(3).toString(),
								  query.value(4).toString(),
								  query.value(5).toInt(),
								  query.value(6).toString(),
								  query.value(7).toInt(),
								  query.value(8).toDate(),
								  query.value(9).toInt(),
								  query.value(10).toInt()
							));
		}
	}

	return clients;
}

QList<Client> ClientModel::getClientsListFiltered(QString firstname, QString lastname, QDate minDate, QDate maxDate)
{
	QList<Client> clients;

	QSqlDatabase db = DatabaseCreator::getInstance();

	QSqlQuery query(db);

	query.prepare("SELECT Id, Nom, Prenom, Adresse, Ville, CP, Commentaire, Tel, DateRdv, DureeRdv, Priorite FROM TClient WHERE (Nom LIKE :lastname AND Prenom LIKE :firstname) AND DateRdv BETWEEN :mindate AND :maxdate");

	query.bindValue(":lastname", lastname);
	query.bindValue(":firstname", firstname);
	query.bindValue(":mindate", minDate);
	query.bindValue(":maxdate", maxDate);

	if(!query.exec())
	{
		qDebug() << "Error while getting the client list (with filters) : " << query.lastError();
	}
	else
	{
		while(query.first())
		{
			clients.append(Client(query.value(0).toInt(),
								  query.value(1).toString(),
								  query.value(2).toString(),
								  query.value(3).toString(),
								  query.value(4).toString(),
								  query.value(5).toInt(),
								  query.value(6).toString(),
								  query.value(7).toInt(),
								  query.value(8).toDate(),
								  query.value(9).toInt(),
								  query.value(10).toInt()
							));
		}
	}

	return clients;
}
