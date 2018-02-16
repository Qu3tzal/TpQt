#include "createclientdialog.h"
#include "ui_createclientdialog.h"

CreateClientDialog::CreateClientDialog(QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::CreateClientDialog)
{
	// Load the UI.
	ui->setupUi(this);
}

CreateClientDialog::~CreateClientDialog()
{
	delete ui;
}

void CreateClientDialog::accept()
{

}

void CreateClientDialog::reject()
{

}
