#ifndef APPOINTMENT_H
#define APPOINTMENT_H


class Appointment
{
public:
    Appointment(int _appointmentId, int _staffId, int _clientid);

    /**
     * @brief getAppointmentId
     * @return the appointment id
     */
    int getAppointmentId() const;

    /**
     * @brief getStaffId
     * @return the staff id
     */
    int getStaffId() const;

    /**
     * @brief getClientid
     * @return the client id
     */
    int getClientid() const;

private:
    int appointmentId;
    int staffId;
    int clientid;
};

#endif // APPOINTMENT_H
