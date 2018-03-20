#include "staffmodel.h"

#include <QDebug>
#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <iostream>
#include "databasecreator.h"

Staff StaffModel::getStaffById(int id)
{
	QSqlDatabase db = DatabaseCreator::getInstance();

	Staff staff(-1, "", "", -1);

	QSqlQuery query(db);
	query.setForwardOnly(true);
	query.prepare("SELECT Id, Nom, Prenom, IdType FROM TRessource WHERE Id = :id");
	query.bindValue(":id", id);

	if(!query.exec())
	{
		qDebug() << "Error while getting staff : " << query.lastError().text();
	}
	else
	{
		if(query.first())
		{
			staff = Staff(query.value(0).toInt(), query.value(1).toString(), query.value(2).toString(), query.value(3).toInt());
		}
	}

	return staff;
}

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
			staffs.append(Staff(query.value(0).toInt(), query.value(1).toString(), query.value(2).toString(), query.value(3).toInt()));
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
			staffs.append(Staff(query.value(0).toInt(), query.value(1).toString(), query.value(2).toString(), query.value(3).toInt()));
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
			StaffType st;
			st.id = query.value(0).toInt();
			st.label = query.value(1).toString();

			types.append(st);
		}
	}

	return types;
}

int StaffModel::addStaff(Staff staff)
{
    QSqlDatabase db = DatabaseCreator::getInstance();

    QSqlQuery query(db);

	query.prepare("INSERT INTO TRessource (Nom, Prenom, IdType) "
                  "VALUES (:Nom, :Prenom, :IdType)");
    query.bindValue(":Nom", staff.getLastName());
    query.bindValue(":Prenom", staff.getFirstName());
    query.bindValue(":IdType", staff.getTypeId());

	if(!query.exec())
	{
		qDebug() << "Error while creating staff : " << query.lastError();
	}

	return query.lastInsertId().toInt();
}

void StaffModel::updateStaff(Staff staff)
{
	QSqlDatabase db = DatabaseCreator::getInstance();

	QSqlQuery query(db);

	query.prepare("UPDATE TRessource SET (Nom, Prenom, IdType) VALUES (:Nom, :Prenom, :IdType) WHERE Id = :Id");
	query.bindValue(":Id", staff.getId());
	query.bindValue(":Nom", staff.getLastName());
	query.bindValue(":Prenom", staff.getFirstName());
	query.bindValue(":IdType", staff.getTypeId());

	if(!query.exec())
	{
		qDebug() << "Error while updating staff : " << query.lastError();
	}
}

void StaffModel::removeStaff(int id)
{
	QSqlDatabase db = DatabaseCreator::getInstance();
	QSqlQuery query(db);

	query.prepare("DELETE FROM TRessource WHERE Id = :id");
	query.bindValue(":id", id);

	if(!query.exec())
	{
		qDebug() << "Error while removing staff : " << query.lastError();
	}
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
