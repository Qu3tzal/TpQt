#include "appointment.h"

Appointment::Appointment(int _appointmentId, int _staffId, int _clientid):
    appointmentId(_appointmentId)
  , staffId(_staffId)
  , clientid(_clientid)
{

}

int Appointment::getAppointmentId() const
{
    return appointmentId;
}

int Appointment::getStaffId() const
{
    return staffId;
}

int Appointment::getClientid() const
{
    return clientid;
}
