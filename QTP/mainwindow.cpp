#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "views/createclientdialog.h"
#include "views/createstaffdialog.h"
#include "views/staffview.h"

#include <QMessageBox>

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

   // StaffView * st = new StaffView(ui->tabWidget->widget(1));
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
}

void MainWindow::onCreateStaffAction()
{
	setStatusTip("Creating a new staff");

	CreateStaffDialog *csd = new CreateStaffDialog(this);
	csd->exec();
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
