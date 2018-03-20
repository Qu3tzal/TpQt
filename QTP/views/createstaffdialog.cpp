#include "CreateStaffDialog.h"
#include "ui_createstaffdialog.h"
#include "model/staffmodel.h"
#include "model/accountmodel.h"

CreateStaffDialog::CreateStaffDialog(QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::CreateStaffDialog)
{
	// Load the UI.
	ui->setupUi(this);


    QList<StaffType> types = StaffModel::getStaffTypes();

    for(int i = 0; i < types.size(); i++)
    {
        ui->typeComboBox->addItem(types[i].label);
    }

    // Hide login and password
    onComboBoxChanged();

	// Connections.
	connect(this, SIGNAL(accepted()), this, SLOT(onDialogAccepted()));
	connect(this, SIGNAL(rejected()), this, SLOT(onDialogRejected()));
    connect(ui->typeComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(onComboBoxChanged()));
}

CreateStaffDialog::~CreateStaffDialog()
{
	delete ui;
}

void CreateStaffDialog::onDialogAccepted()
{
	// Create staff.
	int staffId = StaffModel::addStaff(Staff(-1, ui->firstNameLineEdit->text(), ui->lastNameLineEdit->text(), StaffModel::getTypeIdFromLabel(ui->typeComboBox->currentText())));

	// Create account only if needed.
	if(ui->typeComboBox->currentText() == "Informaticien")
    {
		QString login = ui->loginLineEdit->text();
		QString password = ui->passwordLineEdit->text();

		AccountModel::createAccount(login, password, staffId);
    }
}

void CreateStaffDialog::onDialogRejected()
{

}

void CreateStaffDialog::onComboBoxChanged()
{
    if(ui->typeComboBox->currentText() == "Informaticien")
    {
        ui->loginLabel->setVisible(true);
        ui->loginLineEdit->setVisible(true);
        ui->passwordLabel->setVisible(true);
        ui->passwordLineEdit->setVisible(true);
    }
    else
    {
        ui->loginLabel->setVisible(false);
        ui->loginLineEdit->setVisible(false);
        ui->passwordLabel->setVisible(false);
        ui->passwordLineEdit->setVisible(false);
    }
}
