#include "mainwindow.h"
#include "authentificationdialog.h"
#include <QApplication>
#include <QDebug>

#include "model/databasecreator.h"
#include "model/staffmodel.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	// Uncomment only to create the database.
	//DatabaseCreator::createDB();

	StaffModel sdao;
	for(auto& str : sdao.getStaffTypes())
		qDebug() << "Type: " << str.label;

	// Launches the authentification dialog.
	AuthentificationDialog authentification;

	// Once we got the authentification success, we launch the main window.
	if(authentification.exec() == QDialog::Accepted)
	{
		MainWindow w;
		w.show();

		// We need to do the application exec here, otherwise the MainWindow would get out of scope.
		return a.exec();
	}
	else
	{
		// Return 1 (= login failure).
		return 1;
	}
}
