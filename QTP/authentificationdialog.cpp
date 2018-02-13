#include "authentificationdialog.h"
#include "ui_authentificationdialog.h"
#include "model/authentificationmodel.h"

#include <QMessageBox>

AuthentificationDialog::AuthentificationDialog(QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::AuthentificationDialog)
{
	// Load the UI.
	ui->setupUi(this);
}

AuthentificationDialog::~AuthentificationDialog()
{
	delete ui;
}

void AuthentificationDialog::on_authentificationDialogButtonBox_accepted()
{
	if(AuthentificationModel::checkLogin(ui->loginLineEdit->text(), ui->passwordLineEdit->text()))
	{
		accept();
	}
	else
	{
		// Display a warning and clear the password field.
		QMessageBox::warning(this, "Login failure", "The login/password did not match.");
		ui->passwordLineEdit->setText("");
	}
}

void AuthentificationDialog::on_authentificationDialogButtonBox_rejected()
{
	reject();
}
