#include "authentificationdialog.h"
#include "ui_authentificationdialog.h"

AuthentificationDialog::AuthentificationDialog(QWidget *parent, QMainWindow *windowToLaunch)
	: QDialog(parent)
	, ui(new Ui::AuthentificationDialog)
	, m_windowToLaunch(windowToLaunch)
{
	ui->setupUi(this);

	connect(ui->authentificationDialogButtonBox, SIGNAL(rejected()), QApplication::instance(), SLOT(quit()));
	connect(ui->authentificationDialogButtonBox, SIGNAL(accepted()), this, SLOT(login()));
}

AuthentificationDialog::~AuthentificationDialog()
{
	delete ui;
}

#include <iostream>

void AuthentificationDialog::login()
{
	std::cout << "Il le fait" << std::endl << "Login de : " <<  ui->loginLineEdit->text().toStdString() << " (password: " << ui->passwordLineEdit->text().toStdString() << ")" << std::endl;

	if(m_windowToLaunch)
	{
		m_windowToLaunch->show();
		close();
	}
}
