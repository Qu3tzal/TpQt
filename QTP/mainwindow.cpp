#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QDebug>
#include <QFileDialog>
#include <QXmlStreamWriter>

#include "views/createclientdialog.h"
#include "views/createmiscdialog.h"
#include "views/createstaffdialog.h"
#include "views/staffview.h"
#include "model/accountmodel.h"
#include "model/staffmodel.h"
#include "model/clientmodel.h"
#include "model/appointmentmodel.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	// Load the UI.
	ui->setupUi(this);

	// Maximize the window.
	//setWindowState(Qt::WindowMaximized);

	// Connections.
	connect(ui->actionCreateClient, SIGNAL(triggered(bool)), this, SLOT(onCreateClientAction()));
    connect(ui->actionDivers, SIGNAL(triggered(bool)), this, SLOT(onDiversAction()));
	connect(ui->actionToolbarCreateClient, SIGNAL(triggered(bool)), this, SLOT(onCreateClientAction()));
	connect(ui->actionCreateStaff, SIGNAL(triggered(bool)), this, SLOT(onCreateStaffAction()));
	connect(ui->actionToolbarCreateStaff, SIGNAL(triggered(bool)), this, SLOT(onCreateStaffAction()));
	connect(ui->actionAboutUs, SIGNAL(triggered(bool)), this, SLOT(onAboutUsAction()));
	connect(ui->actionAboutQt, SIGNAL(triggered(bool)), this, SLOT(onAboutQtAction()));

	connect(ui->modifyStaffButton, SIGNAL(clicked(bool)), this, SLOT(onModifyStaffButtonCliked()));
	connect(ui->deleteStaffButton, SIGNAL(clicked(bool)), this, SLOT(onDeleteStaffButtonCliked()));

	connect(ui->clientSearchPushButton, SIGNAL(clicked(bool)), this, SLOT(onClientSearch()));
	connect(ui->clientSearchFirstNameEdit, SIGNAL(textChanged(QString)), this, SLOT(onClientSearch()));
	connect(ui->clientSearchLastNameEdit, SIGNAL(textChanged(QString)), this, SLOT(onClientSearch()));
	connect(ui->clientSearchStartDate, SIGNAL(dateChanged(QDate)), this, SLOT(onClientSearch()));
	connect(ui->clientSearchEndDate, SIGNAL(dateChanged(QDate)), this, SLOT(onClientSearch()));

	connect(ui->modifyClientPushButton, SIGNAL(clicked(bool)), this, SLOT(onModifyClientButtonClicked()));
	connect(ui->removeClientPushButton, SIGNAL(clicked(bool)), this, SLOT(onDeleteClientButtonClicked()));

    connect(ui->exportStaffToXMLPushButton, SIGNAL(clicked(bool)), this, SLOT(onExportStaffToXMLPushButton()));

	// Client table view.
    QSqlQueryModel *model = ClientModel::getClientsModel();
    ui->clientSearchTableView->setModel(model);
    ui->clientSearchTableView->verticalHeader()->setVisible(false);
    ui->clientSearchTableView->sortByColumn(1);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::onCreateClientAction()
{
	setStatusTip("Creating a new client");

    CreateClientDialog *ccd = new CreateClientDialog(0, this);
	ccd->exec();

	// Refresh the client view.
    QSqlQueryModel *model = ClientModel::getClientsModel();
    ui->clientSearchTableView->setModel(model);
}

void MainWindow::onCreateStaffAction()
{
	setStatusTip("Creating a new staff");

    CreateStaffDialog *csd = new CreateStaffDialog(-1, this);
	csd->exec();

	// Refresh the staff view.
	ui->staffTreeView->refreshData();
}

void MainWindow::onAboutUsAction()
{
	QMessageBox box(QString("À propos"), QString("Créateurs : Louis & Maxime"), QMessageBox::NoIcon, QMessageBox::Ok | QMessageBox::Default, QMessageBox::NoButton, QMessageBox::NoButton, this);
	box.setIconPixmap(QPixmap(":/icons/polytechtours-166x166.png"));
	box.exec();
}

void MainWindow::onAboutQtAction()
{
	QMessageBox::aboutQt(this);
}

void MainWindow::onModifyStaffButtonCliked()
{
	setStatusTip("Modifying a staff member");

    CreateStaffDialog *csd = new CreateStaffDialog(ui->staffTreeView->getSelectedStaffId(), this);
    csd->exec();

    // Refresh the staff view.
    ui->staffTreeView->refreshData();
}

void MainWindow::onDeleteStaffButtonCliked()
{
	setStatusTip("Deleting a staff member");

	int staffId = ui->staffTreeView->getSelectedStaffId();

	if(staffId == -1)
		return;

	Staff staff = StaffModel::getStaffById(staffId);

	if(staff.getId() == -1)
		qDebug() << "Error while retrieving the staff : id = -1";

	// Remove the staff.
	StaffModel::removeStaff(staff.getId());

	// Check the type.
	if(staff.getTypeId() == 7) // Type 7 = Informaticien
		AccountModel::removeAccountOfStaff(staff.getId());

	// Update staff view.
	ui->staffTreeView->refreshData();
}

void MainWindow::onClientSearch()
{
	QSqlQueryModel *model = ClientModel::getClientsModelFiltered(ui->clientSearchFirstNameEdit->text(), ui->clientSearchLastNameEdit->text(), ui->clientSearchStartDate->date(), ui->clientSearchEndDate->date());
    ui->clientSearchTableView->setModel(model);
}

void MainWindow::onModifyClientButtonClicked()
{
	// Get the selected client.
	QModelIndex selectedClient = ui->clientSearchTableView->currentIndex();

    int clientId = ui->clientSearchTableView->model()->index(selectedClient.row(), 0).data().toString().toInt();

    CreateClientDialog *csd = new CreateClientDialog(clientId, this);
    csd->exec();

    // Refresh the staff view.
    QSqlQueryModel *model = ClientModel::getClientsModel();
    ui->clientSearchTableView->setModel(model);
}

void MainWindow::onDeleteClientButtonClicked()
{
	// Get the selected client.
    QModelIndex selectedClient = ui->clientSearchTableView->currentIndex();

    int clientId = ui->clientSearchTableView->model()->index(selectedClient.row(), 0).data().toString().toInt();

    // Delete Appointments and client
    ClientModel::deleteClientById(clientId);
    AppointmentModel::deleteAppointmentByClientId(clientId);

    // Refresh the staff view.
    QSqlQueryModel *model = ClientModel::getClientsModel();
    ui->clientSearchTableView->setModel(model);
}

void MainWindow::onClientAdded()
{
    setStatusTip("Ajout de personne terminé");
}

void MainWindow::onExportStaffToXMLPushButton()
{
    // Get the filename.
    QString filename = QFileDialog::getSaveFileName(this, "Exporter en XML", "C:\\", "Fichiers XML (*.xml)");

    // Open the file.
    QFile file(filename);
    if(!file.open(QIODevice::WriteOnly))
        QMessageBox::critical(this, "Erreur export XML", "Impossible d'écrire le fichier \"" + filename + "\".");

    // Start the xml writer.
    QXmlStreamWriter xmlWriter(&file);

    // Start document.
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("TRessource");

    QList<Staff> staffList = StaffModel::getStaffList();

    for(int i(0) ; i < staffList.size() ; ++i)
    {
        Staff& s = staffList[i];

        xmlWriter.writeStartElement("Ressource");
        xmlWriter.writeAttribute("Id", QString::number(s.getId()));
            xmlWriter.writeTextElement("Nom", s.getLastName());
            xmlWriter.writeTextElement("Prenom", s.getFirstName());
        xmlWriter.writeEndElement();
    }

    // End document.
    xmlWriter.writeEndElement();
    xmlWriter.writeEndDocument();
    file.close();

    // Notify success.
    QMessageBox::information(this, "Export XML réussi", "L'export XML vers le fichier \"" + filename + "\" a réussi.");
}

void MainWindow::onDiversAction()
{
    CreateMiscDialog *cmd = new CreateMiscDialog(this);
    cmd->exec();

    // Update staff view.
    ui->staffTreeView->refreshData();
}
