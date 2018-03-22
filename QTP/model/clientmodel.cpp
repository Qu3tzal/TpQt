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
        while(query.next())
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

QSqlQueryModel *ClientModel::getClientsModel()
{
	QSqlDatabase db = DatabaseCreator::getInstance();

	QSqlQuery query(db);

	query.prepare("SELECT Id, Nom, Prenom, Adresse, Ville, CP, Commentaire, Tel, DateRdv, DureeRdv, Priorite FROM TClient");

	if(!query.exec())
	{
		qDebug() << "Error while getting the client list : " << query.lastError();
	}

	QSqlQueryModel *queryModel = new QSqlQueryModel();
	queryModel->setQuery(query);

	return queryModel;
}

QList<Client> ClientModel::getClientsListFiltered(QString firstname, QString lastname, QDate minDate, QDate maxDate)
{
	QList<Client> clients;

	QSqlDatabase db = DatabaseCreator::getInstance();

	QSqlQuery query(db);

	query.prepare("SELECT Id, Nom, Prenom, Adresse, Ville, CP, Commentaire, Tel, DateRdv, DureeRdv, Priorite FROM TClient WHERE LOWER(Nom) LIKE LOWER(:lastname) AND LOWER(Prenom) LIKE LOWER(:firstname) AND DateRdv BETWEEN :mindate AND :maxdate");

	query.bindValue(":lastname", lastname + "%");
	query.bindValue(":firstname", firstname + "%");
	query.bindValue(":mindate", minDate);
	query.bindValue(":maxdate", maxDate);

	if(!query.exec())
	{
		qDebug() << "Error while getting the client list (with filters) : " << query.lastError();
	}
	else
	{
        while(query.next())
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

QSqlQueryModel *ClientModel::getClientsModelFiltered(QString firstname, QString lastname, QDate minDate, QDate maxDate)
{
	QSqlDatabase db = DatabaseCreator::getInstance();

	QSqlQuery query(db);

	query.prepare("SELECT Id, Nom, Prenom, Adresse, Ville, CP, Commentaire, Tel, DateRdv, DureeRdv, Priorite FROM TClient WHERE LOWER(Nom) LIKE LOWER(:lastname) AND LOWER(Prenom) LIKE LOWER(:firstname) AND DateRdv BETWEEN :mindate AND :maxdate");

	query.bindValue(":lastname", lastname + "%");
	query.bindValue(":firstname", firstname + "%");
	query.bindValue(":mindate", minDate);
	query.bindValue(":maxdate", maxDate);

	if(!query.exec())
	{
		qDebug() << "Error while getting the client list (with filters) : " << query.lastError();
	}

	QSqlQueryModel *queryModel = new QSqlQueryModel();
	queryModel->setQuery(query);

    return queryModel;
}

Client ClientModel::getClientById(int id)
{
    Client client;
    QSqlDatabase db = DatabaseCreator::getInstance();

    QSqlQuery query(db);

    if(!query.exec("SELECT Id, Nom, Prenom, Adresse, Ville, CP, Commentaire, Tel, DateRdv, DureeRdv, Priorite FROM TClient"))
    {
        qDebug() << "Error while getting the client list : " << query.lastError();
    }
    else
    {
        if(query.first())
        {
            client = Client(query.value(0).toInt(),
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
                            );
        }
    }

    return client;
}

int ClientModel::createClient(Client client)
{
    QSqlDatabase db = DatabaseCreator::getInstance();

    QSqlQuery query(db);

    query.prepare("INSERT INTO TClient (Nom, Prenom, Adresse, Ville, CP, Commentaire, Tel, DateRdv, DureeRdv, Priorite) "
                  "VALUES (:Nom, :Prenom, :Adresse, :Ville, :CP, :Commentaire, :Tel, :DateRdv, :DureeRdv, :Priorite)");
    query.bindValue(":Nom", client.getLastName());
    query.bindValue(":Prenom", client.getFirstName());
    query.bindValue(":Adresse", client.getAdress());
    query.bindValue(":Ville", client.getCity());
    query.bindValue(":CP", client.getPostalCode());
    query.bindValue(":Commentaire", client.getCommentary());
    query.bindValue(":Tel", client.getPhoneNumber());
    query.bindValue(":DateRdv", client.getAppointmentDate());
    query.bindValue(":DureeRdv", client.getAppointmentDuration());
    query.bindValue(":Priorite", client.getPriority());


    if(!query.exec())
    {
        qDebug() << "Error while creating Client : " << query.lastError();
    }

    return query.lastInsertId().toInt();
}
