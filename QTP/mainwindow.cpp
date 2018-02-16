#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "views/createclientdialog.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	// Load the UI.
	ui->setupUi(this);

	// Connections.
	connect(ui->actionCreateClient, SIGNAL(triggered(bool)), this, SLOT(onCreateClientAction()));
	connect(ui->actionToolbarCreateClient, SIGNAL(triggered(bool)), this, SLOT(onCreateClientAction()));
	connect(ui->actionCreateStaff, SIGNAL(triggered(bool)), this, SLOT(onCreateStaffAction()));
	connect(ui->actionToolbarCreateStaff, SIGNAL(triggered(bool)), this, SLOT(onCreateStaffAction()));
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::onCreateClientAction()
{
	CreateClientDialog *ccd = new CreateClientDialog(this);
	ccd->exec();
}

void MainWindow::onCreateStaffAction()
{

}
