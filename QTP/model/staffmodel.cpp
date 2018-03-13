#include "staffmodel.h"

#include <QDebug>
#include <QString>

StaffModel::StaffModel()
{
	db = QSqlDatabase::database("QSQLITE");

	if(!db.isValid())
	{
		db = QSqlDatabase::addDatabase("QSQLITE");
	}

	db.setDatabaseName("base_tmp.sqli");

	if(!db.open())
		qDebug() << "Fuck\n";
}

QSqlTableModel *StaffModel::getStaffList()
{
	QSqlTableModel* model = new QSqlTableModel(0, db);

	model->setTable("TRessource");
	model->setEditStrategy(QSqlTableModel::OnManualSubmit);
	model->select();
	model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
	model->setHeaderData(1, Qt::Horizontal, QObject::tr("Last Name"));
	model->setHeaderData(2, Qt::Horizontal, QObject::tr("First Name"));
	model->setHeaderData(3, Qt::Horizontal, QObject::tr("Type"));

	return model;
}
