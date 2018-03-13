#include "staffdao.h"

#include <QDebug>
#include <QString>

StaffDAO::StaffDAO()
{
	db = QSqlDatabase::database("QSQLITE");

	if(!db.isValid())
	{
		db = QSqlDatabase::addDatabase("QSQLITE");
	}

	db.setDatabaseName("base_tmp.sqli");

	if(!db.open())
		qDebug() << "Error while openning the database.\n";
}

QList<Staff> StaffDAO::getStaffList()
{
	QList<Staff> staffs;

	QSqlQuery query(db);
	query.setForwardOnly(true);
	bool querySuccess = query.exec("SELECT Id, Nom, Prenom, IdType FROM TRessource");

	if(!querySuccess)
	{
		qDebug() << "Error while getting staff list : " << query.lastError().text();
	}
	else
	{
		while(query.next())
		{
			staffs.append({query.value(0).toInt(), query.value(1).toString(), query.value(2).toString(), query.value(3).toString(), query.value(4).toString(), query.value(5).toString()});
		}
	}

	return staffs;
}
