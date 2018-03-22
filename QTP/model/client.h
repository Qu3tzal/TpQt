#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <QDate>

class Client
{
public:
		Client(int _id, QString _lastName, QString _firstName, QString _adress, QString _city, int _postalCode, QString _commentary, int _phoneNumber, QDate _appointmentDate, int _appointmentDuration, int _priority);

        Client();
    /**
     * @brief getId
     * @return The client id
     */
    int getId() const ;

    /**
     * @brief getAppointmentDuration
     * @return the appointment duration
     */
    int getAppointmentDuration() const;

    /**
     * @brief getPriority
     * @return the client priority
     */
    int getPriority() const;

    /**
     * @brief getPostalCode
     * @return the client postal code
     */
    int getPostalCode() const;

    /**
     * @brief getPhoneNumber
     * @return the client phone number
     */
    int getPhoneNumber() const;

    /**
     * @brief getCommentary
     * @return the commentary
     */
    QString getCommentary() const;

    /**
     * @brief getFirstName
     * @return the client first name
     */
    QString getFirstName() const;

    /**
     * @brief getLastName
     * @return the client last name
     */
    QString getLastName() const;

    /**
     * @brief getAdress
     * @return the client adress
     */
    QString getAdress() const;

    /**
     * @brief getCity
     * @return the client city
     */
    QString getCity() const;

    /**
     * @brief getAppointmentDate
     * @return the client appointment date
     */
    QDate getAppointmentDate() const;

private:

    int id;
    QString firstName;
    QString lastName;
    QString adress;
    QString city;
    int postalCode;
    QDate appointmentDate;
    int appointmentDuration;
    int priority;
    QString commentary;
    int phoneNumber;


};

#endif // CLIENT_H
