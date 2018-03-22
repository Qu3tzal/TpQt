#ifndef CLIENTMODEL_H
#define CLIENTMODEL_H

#include "databasecreator.h"
#include "client.h"

#include <QtSql>
#include <QList>

class ClientModel
{
	public:
		/**
		 * @brief getClientsList
		 * @return a list containing all the clients
		 */
		static QList<Client> getClientsList();

		/**
		 * @brief getClientsList
		 * @return a model containing all the clients
		 */
		static QSqlQueryModel *getClientsModel();

		/**
		 * @brief getClientsListFiltered
		 * @param firstname
		 * @param lastname
		 * @param minDate
		 * @param maxDate
		 * @return a list containing the clients filtered
		 */
		static QList<Client> getClientsListFiltered(QString firstname, QString lastname, QDate minDate, QDate maxDate);

		/**
		 * @brief getClientsModelFiltered
		 * @param firstname
		 * @param lastname
		 * @param minDate
		 * @param maxDate
		 * @return a model containing the clients filtered
		 */
		static QSqlQueryModel *getClientsModelFiltered(QString firstname, QString lastname, QDate minDate, QDate maxDate);

        /**
         * @brief getClientsById
         * @param id
         * @return the client
         */
        static Client getClientById(int id);

        /**
         * @brief createClient
         * @param client
         * @return the client id
         */
        static int createClient(Client client);

        /**
         * @brief deleteClientById
         * @param id
         */
        static void deleteClientById(int id);

        /**
         * @brief updateClient
         * @param client
         */
        static void updateClient(Client client);
};

#endif // CLIENTMODEL_H
