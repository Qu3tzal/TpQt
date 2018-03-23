#include "mainwindow.h"
#include "authentificationdialog.h"
#include <QApplication>
#include <QDebug>
#include <iostream>
#include <map>
#include <string>
#include <utility>

#include "model/databasecreator.h"
#include "model/staffmodel.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	// Uncomment only to create the database.
    DatabaseCreator::createDB();

    /** Multimap. */

    std::multimap<int, std::string> myMap;
    myMap.insert(std::pair<int, std::string>(1, "titi"));
    myMap.insert(std::pair<int, std::string>(4, "toto"));
    myMap.insert(std::pair<int, std::string>(3, "tutu"));
    myMap.insert(std::pair<int, std::string>(4, "tata"));

    std::multimap<int, std::string>::iterator elementItr = myMap.find(3);

    if(elementItr != myMap.end())
        myMap.erase(elementItr);

    myMap.insert(std::pair<int, std::string>(0, "tete"));

    for(std::multimap<int, std::string>::iterator i(myMap.begin()) ; i != myMap.end() ; i++) {
        std::cout << i->second << std::endl;
    }

    /** End of multimap. */

	// Launches the authentification dialog.
	AuthentificationDialog authentification;

	// Once we got the authentification success, we launch the main window.
	if(authentification.exec() == QDialog::Accepted)
	{
		MainWindow w;
		w.show();

		// We need to do the application exec here, otherwise the MainWindow would get out of scope.
        int result = a.exec();
        std::cout << "Nombre d'insert : " << DatabaseCreator::insertNumber << std::endl;
        return result;
	}
	else
	{
        std::cout << "Nombre d'insert : " << DatabaseCreator::insertNumber << std::endl;
		// Return 1 (= login failure).
		return 1;
	}
}
