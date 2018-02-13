#include "mainwindow.h"
#include "authentificationdialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	AuthentificationDialog authentification;
	authentification.exec();

	if(authentification.loginSuccess())
	{
		MainWindow w;
		w.show();
		return a.exec();
	}

	return 0;
}
