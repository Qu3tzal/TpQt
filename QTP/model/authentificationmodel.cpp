#include "authentificationmodel.h"

bool AuthentificationModel::checkLogin(QString login, QString password)
{
	return login == "Louis" && password == "Louis";
}
