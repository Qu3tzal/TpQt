#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QDebug>

#include "views/createclientdialog.h"
#include "views/createstaffdialog.h"
#include "views/staffview.h"
#include "model/accountmodel.h"
#include "model/staffmodel.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	// Load the UI.
	ui->setupUi(this);

	// Maximize the window.
	setWindowState(Qt::WindowMaximized);

	// Connections.
	connect(ui->actionCreateClient, SIGNAL(triggered(bool)), this, SLOT(onCreateClientAction()));
	connect(ui->actionToolbarCreateClient, SIGNAL(triggered(bool)), this, SLOT(onCreateClientAction()));
	connect(ui->actionCreateStaff, SIGNAL(triggered(bool)), this, SLOT(onCreateStaffAction()));
	connect(ui->actionToolbarCreateStaff, SIGNAL(triggered(bool)), this, SLOT(onCreateStaffAction()));
	connect(ui->actionAboutUs, SIGNAL(triggered(bool)), this, SLOT(onAboutUsAction()));
	connect(ui->actionAboutQt, SIGNAL(triggered(bool)), this, SLOT(onAboutQtAction()));

	connect(ui->modifyStaffButton, SIGNAL(clicked(bool)), this, SLOT(onModifyStaffButtonCliked()));
	connect(ui->deleteStaffButton, SIGNAL(clicked(bool)), this, SLOT(onDeleteStaffButtonCliked()));
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::onCreateClientAction()
{
	setStatusTip("Creating a new client");

	CreateClientDialog *ccd = new CreateClientDialog(this);
	ccd->exec();

	// Refresh the client view.
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
	QMessageBox box(QString("À propos"), QString("Créateurs : Louis & Maxime"), QMessageBox::Icon::NoIcon, QMessageBox::Ok | QMessageBox::Default, QMessageBox::NoButton, QMessageBox::NoButton, this);
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
