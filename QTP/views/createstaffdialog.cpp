#include "CreateStaffDialog.h"
#include "ui_createstaffdialog.h"

CreateStaffDialog::CreateStaffDialog(QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::CreateStaffDialog)
{
	// Load the UI.
	ui->setupUi(this);

	// Connections.
	connect(this, SIGNAL(accepted()), this, SLOT(onDialogAccepted()));
	connect(this, SIGNAL(rejected()), this, SLOT(onDialogRejected()));
}

CreateStaffDialog::~CreateStaffDialog()
{
	delete ui;
}

void CreateStaffDialog::onDialogAccepted()
{

}

void CreateStaffDialog::onDialogRejected()
{

}
