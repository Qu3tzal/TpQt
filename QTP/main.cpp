#include "mainwindow.h"
#include "authentificationdialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	MainWindow w;
	AuthentificationDialog authentification(0, &w);

	authentification.show();
	return a.exec();
}
