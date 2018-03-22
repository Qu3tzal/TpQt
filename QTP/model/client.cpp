#include "client.h"

Client::Client(int _id, QString _lastName, QString _firstName, QString _adress, QString _city, int _postalCode, QDate _appointmentDate, int _appointmentDuration, int _priority, QString _commentary, int _phoneNumber)
    :id(_id)
    , firstName(_firstName)
    ,lastName(_lastName)
    , adress(_adress)
    , city(_city)
    , postalCode(_postalCode)
    , appointmentDate(_appointmentDate)
    , appointmentDuration(_appointmentDuration)
    , priority(_priority)
    , commentary(_commentary)
    , phoneNumber(_phoneNumber)

{

}

int Client::getId() const
{
    return id;
}

int Client::getAppointmentDuration() const
{
    return appointmentDuration;
}

int Client::getPriority() const
{
    return priority;
}

int Client::getPostalCode() const
{
    return postalCode;
}

int Client::getPhoneNumber() const
{
    return phoneNumber;
}

QString Client::getCommentary() const
{
    return commentary;
}

QString Client::getFirstName() const
{
    return firstName;
}

QString Client::getLastName() const
{
    return lastName;
}

QString Client::getAdress() const
{
    return adress;
}

QString Client::getCity() const
{
    return city;
}

QDate Client::getAppointmentDate() const
{
    return appointmentDate;
}
