#include "staffmodel.h"

#include <QDebug>
#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>

#include "databasecreator.h"

QList<Staff> StaffModel::getStaffList()
{
	QSqlDatabase db = DatabaseCreator::getInstance();

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
			staffs.append({query.value(0).toInt(), query.value(1).toString(), query.value(2).toString(), query.value(3).toInt()});
		}
	}

	return staffs;
}

QList<Staff> StaffModel::getStaffListByType(int typeId)
{
	QSqlDatabase db = DatabaseCreator::getInstance();

	QList<Staff> staffs;

	QSqlQuery query(db);
	query.setForwardOnly(true);
	query.prepare("SELECT Id, Nom, Prenom, IdType FROM TRessource WHERE IdType = ?");
	query.bindValue(0, typeId);

	bool querySuccess = query.exec();

	if(!querySuccess)
	{
		qDebug() << "Error while getting staff list : " << query.lastError().text();
	}
	else
	{
		while(query.next())
		{
			staffs.append({query.value(0).toInt(), query.value(1).toString(), query.value(2).toString(), query.value(3).toInt()});
		}
	}

	return staffs;
}

QList<StaffType> StaffModel::getStaffTypes()
{
	QSqlDatabase db = DatabaseCreator::getInstance();

	QList<StaffType> types;

	QSqlQuery query(db);
	query.setForwardOnly(true);
	bool querySuccess = query.exec("SELECT Id, Label FROM TType ");

	if(!querySuccess)
	{
		qDebug() << "Error while getting staff types list : " << query.lastError().text();
	}
	else
	{
		while(query.next())
		{
			types.append({query.value(0).toInt(), query.value(1).toString()});
		}
	}

	return types;
}
