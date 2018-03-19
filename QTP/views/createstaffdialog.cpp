#include "CreateStaffDialog.h"
#include "ui_createstaffdialog.h"
#include "model/staffmodel.h"

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
    /*// Add items to the combo box
    ui->typeComboBox->addItem("Banquier type A");
    ui->typeComboBox->addItem("Banquier type B");
    ui->typeComboBox->addItem("Assureur logement");
    ui->typeComboBox->addItem("Assureur voiture");
    ui->typeComboBox->addItem("Assureur vie");
    ui->typeComboBox->addItem("Informaticien");
    ui->typeComboBox->addItem("Divers");*/

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
    QString login;
    QString password;
    if(ui->typeComboBox->currentText() == "Informaticien")
    {
        login = ui->loginLineEdit->text();
        password = ui->passwordLineEdit->text();
    }
    StaffModel::addStaff(Staff(-1, ui->firstNameLineEdit->text(), ui->lastNameLineEdit->text(), StaffModel::getId(ui->typeComboBox->currentText())), login, password);
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
