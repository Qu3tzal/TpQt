#include "CreateStaffDialog.h"
#include "ui_createstaffdialog.h"

CreateStaffDialog::CreateStaffDialog(QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::CreateStaffDialog)
{
	// Load the UI.
	ui->setupUi(this);

    // Add items to the combo box
    ui->comboBox->addItem("Banquier type A");
    ui->comboBox->addItem("Banquier type B");
    ui->comboBox->addItem("Assureur logement");
    ui->comboBox->addItem("Assureur voiture");
    ui->comboBox->addItem("Assureur vie");
    ui->comboBox->addItem("Informaticien");
    ui->comboBox->addItem("Divers");

    // Hide login and password
    onComboBoxChanged();

	// Connections.
	connect(this, SIGNAL(accepted()), this, SLOT(onDialogAccepted()));
	connect(this, SIGNAL(rejected()), this, SLOT(onDialogRejected()));
    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(onComboBoxChanged()));
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

void CreateStaffDialog::onComboBoxChanged()
{
    if(ui->comboBox->currentText() == "Informaticien")
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
