#include "appointmentmodel.h"

#include <QtSql>
#include "databasecreator.h"
#include <QDebug>

AppointmentModel::AppointmentModel()
{

}

int AppointmentModel::createAppointment(int staffId, int clientId)
{
    QSqlDatabase db = DatabaseCreator::getInstance();
    QSqlQuery query(db);

    query.prepare("INSERT INTO TRdv (IdClient, IdRessource) "
                  "VALUES (:idC, :idS)");
    query.bindValue(":idC", clientId);
    query.bindValue(":idC", staffId);

    if(!query.exec())
    {
        qDebug() << "Error while creating account : " << query.lastError();
    }

    return query.lastInsertId().toInt();
}

QList<Appointment> AppointmentModel::getAppointmentsByDate(QDate date)
{
    QSqlDatabase db = DatabaseCreator::getInstance();

    QList<Appointment> Appointments;

    QSqlQuery query(db);
    query.setForwardOnly(true);

    query.prepare("SELECT Id, IdClient, IdRessource FROM TRdv rdv INNER JOIN TClient client ON client.Id = rdv.IdClient WHERE client.DateRdv = :date");
    query.bindValue(":date", date);
    bool querySuccess = query.exec();

    if(!querySuccess)
    {
        qDebug() << "Error while getting staff list : " << query.lastError().text();
    }
    else
    {
        while(query.next())
        {
            Appointments.append(Appointment(query.value(0).toInt(), query.value(1).toInt(), query.value(2).toInt()));
        }
    }

    return Appointments;
}

QList<Appointment> AppointmentModel::getAppointmentsById(int appointmentId)
{
    QSqlDatabase db = DatabaseCreator::getInstance();

    QList<Appointment> Appointments;

    QSqlQuery query(db);
    query.setForwardOnly(true);

    query.prepare("SELECT Id, IdClient, IdRessource FROM TRdv rdv WHERE Id = :id");
    query.bindValue(":id", appointmentId);
    bool querySuccess = query.exec();

    if(!querySuccess)
    {
        qDebug() << "Error while getting staff list : " << query.lastError().text();
    }
    else
    {
        while(query.next())
        {
            Appointments.append(Appointment(query.value(0).toInt(), query.value(1).toInt(), query.value(2).toInt()));
        }
    }

    return Appointments;
}

QList<Appointment> AppointmentModel::getAppointmentsByStaffId(int staffId)
{
    QSqlDatabase db = DatabaseCreator::getInstance();

    QList<Appointment> Appointments;

    QSqlQuery query(db);
    query.setForwardOnly(true);

    query.prepare("SELECT Id, IdClient, IdRessource FROM TRdv rdv WHERE IdRessource = :id");
    query.bindValue(":id", staffId);
    bool querySuccess = query.exec();

    if(!querySuccess)
    {
        qDebug() << "Error while getting staff list : " << query.lastError().text();
    }
    else
    {
        while(query.next())
        {
            Appointments.append(Appointment(query.value(0).toInt(), query.value(1).toInt(), query.value(2).toInt()));
        }
    }

    return Appointments;
}

QList<Appointment> AppointmentModel::getAppointmentsByClientId(int clientId)
{
    QSqlDatabase db = DatabaseCreator::getInstance();

    QList<Appointment> Appointments;

    QSqlQuery query(db);
    query.setForwardOnly(true);

    query.prepare("SELECT Id, IdClient, IdRessource FROM TRdv rdv WHERE IdClient = :id");
    query.bindValue(":id", clientId);
    bool querySuccess = query.exec();

    if(!querySuccess)
    {
        qDebug() << "Error while getting staff list : " << query.lastError().text();
    }
    else
    {
        while(query.next())
        {
            Appointments.append(Appointment(query.value(0).toInt(), query.value(1).toInt(), query.value(2).toInt()));
        }
    }

    return Appointments;
}

void AppointmentModel::deleteAppointmentById(int id)
{
    QSqlDatabase db = DatabaseCreator::getInstance();
    QSqlQuery query(db);

    query.prepare("DELETE FROM TRdv WHERE Id = :id");
    query.bindValue(":id", id);

    if(!query.exec())
    {
        qDebug() << "Error while removing staff : " << query.lastError();
    }
}
