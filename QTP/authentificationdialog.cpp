#include "authentificationdialog.h"
#include "ui_authentificationdialog.h"

AuthentificationDialog::AuthentificationDialog(QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::AuthentificationDialog)
	, m_loginSuccess(false)
{
	ui->setupUi(this);
	setWindowModality(Qt::WindowModal);

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
	m_loginSuccess = true;
	close();
}
