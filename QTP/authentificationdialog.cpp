#include "authentificationdialog.h"
#include "ui_authentificationdialog.h"

#include <QMessageBox>

AuthentificationDialog::AuthentificationDialog(QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::AuthentificationDialog)
	, m_loginSuccess(false)
{
	// Load the UI.
	ui->setupUi(this);

	// Set the window as modal. This makes the exec() function blocking.
	setWindowModality(Qt::WindowModal);

	// Connect the rejected signal to QApplication::quit() and the accepted signal to the login() slot.
	connect(ui->authentificationDialogButtonBox, SIGNAL(rejected()), QApplication::instance(), SLOT(quit()));
	connect(ui->authentificationDialogButtonBox, SIGNAL(accepted()), this, SLOT(login()));
}

AuthentificationDialog::~AuthentificationDialog()
{
	delete ui;
}

bool AuthentificationDialog::loginSuccess() const
{
	return m_loginSuccess;
}

void AuthentificationDialog::login()
{
	// TODO: do the login/password verification.

	if(ui->loginLineEdit->text() == "Louis")
	{
		m_loginSuccess = true;

		// We close this dialog.
		close();
	}
	else
	{
		QMessageBox::warning(this, "Login failure", "The login/password did not match.");
		ui->passwordLineEdit->setText("");
	}
}
