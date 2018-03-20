#include "staffmodel.h"

#include <QDebug>
#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <iostream>
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

bool StaffModel::addStaff(Staff staff, QString login, QString password)
{
    QSqlDatabase db = DatabaseCreator::getInstance();

    QSqlQuery query(db);
    query.setForwardOnly(true);

    query.prepare("INSERT INTO TRessource (Nom , Prenom, IdType) "
                  "VALUES (:Nom, :Prenom, :IdType)");
    query.bindValue(":Nom", staff.getLastName());
    query.bindValue(":Prenom", staff.getFirstName());
    query.bindValue(":IdType", staff.getTypeId());

    bool querySuccess = query.exec();

    if(getTypeLabelFromId(staff.getTypeId()) == "Informaticien" && querySuccess)
    {
        int staffId = query.lastInsertId().toInt();
        query.prepare("INSERT INTO TCompte (IdRessource , Login, MdP) "
                      "VALUES (:id, :login, :mdp)");
        query.bindValue(":id", staffId);
        query.bindValue(":login", login);
        query.bindValue(":mdp", password);

        querySuccess = query.exec();
    }


    return querySuccess;

}

QString StaffModel::getTypeLabelFromId(int id)
{
    QSqlDatabase db = DatabaseCreator::getInstance();

    QSqlQuery query(db);
    query.setForwardOnly(true);

    query.prepare("SELECT Label FROM TType WHERE Id = :id");

    query.bindValue(":id", id);

    bool querySuccess = query.exec();
    query.next();

    if(querySuccess)
        return query.value(0).toString();
    else
        return QString();
}

int StaffModel::getTypeIdFromLabel(QString label)
{
    QSqlDatabase db = DatabaseCreator::getInstance();

    QSqlQuery query(db);
    query.setForwardOnly(true);

    query.prepare("SELECT Id FROM TType WHERE Label LIKE :label");

    query.bindValue(":label", label);

    bool querySuccess = query.exec();
    query.next();
    if(querySuccess)
        return query.value(0).toInt();
    else
        return -1;

}
