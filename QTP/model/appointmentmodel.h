#ifndef APPOINTMENTMODEL_H
#define APPOINTMENTMODEL_H

#include "appointment.h"

#include <QList>
#include <QDate>

class AppointmentModel
{
public:
    AppointmentModel();

    /**
     * @brief createAppointment
     * @param staffId
     * @param clientId
     * @return a list of appointments
     */
    static int createAppointment(int staffId, int clientId);

    /**
     * @brief getAppointmentsByDate
     * @param date
     * @return a list of appointments
     */
    static QList<Appointment> getAppointmentsByDate(QDate date);

    /**
     * @brief getAppointmentsById
     * @param appointmentId
     * @return a list of appointments
     */
    static QList<Appointment> getAppointmentsById(int appointmentId);

    /**
     * @brief getAppointmentsByStaffId
     * @param staffId
     * @return a list of appointments
     */
    static QList<Appointment> getAppointmentsByStaffId(int staffId);

    /**
     * @brief getAppointmentsByClientId
     * @param clientId
     * @return a list of appointments
     */
    static QList<Appointment> getAppointmentsByClientId(int clientId);

    /**
     * @brief deleteAppointmentById
     * @param id
     */
    static void deleteAppointmentById(int id);
};

#endif // APPOINTMENTMODEL_H
