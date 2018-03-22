#ifndef CLIENTMODEL_H
#define CLIENTMODEL_H

#include "databasecreator.h"
#include "client.h"

#include <QList>

class ClientModel
{
	public:
		/**
		 * @brief getClientsList
		 * @return a list containing all the clients
		 */
		QList<Client> getClientsList();

		/**
		 * @brief getClientsListFiltered
		 * @param firstname
		 * @param lastname
		 * @param minDate
		 * @param maxDate
		 * @return a list containing the clients filtered
		 */
		QList<Client> getClientsListFiltered(QString firstname, QString lastname, QDate minDate, QDate maxDate);
};

#endif // CLIENTMODEL_H
