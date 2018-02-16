#include "createclientdialog.h"
#include "ui_createclientdialog.h"

CreateClientDialog::CreateClientDialog(QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::CreateClientDialog)
{
	// Load the UI.
	ui->setupUi(this);

	// Connections.
	connect(this, SIGNAL(accepted()), this, SLOT(onDialogAccepted()));
	connect(this, SIGNAL(rejected()), this, SLOT(onDialogRejected()));
}

CreateClientDialog::~CreateClientDialog()
{
	delete ui;
}

void CreateClientDialog::onDialogAccepted()
{

}

void CreateClientDialog::onDialogRejected()
{

}
