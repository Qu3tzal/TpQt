#include "CreateStaffDialog.h"
#include "ui_createstaffdialog.h"
#include "model/staffmodel.h"
#include "model/accountmodel.h"
#include "model/account.h"
#include "model/staff.h"
#include "QMessageBox"
#include "mainwindow.h"
#include "stringutil.h"

CreateStaffDialog::CreateStaffDialog(int staffId, QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::CreateStaffDialog)
    , staff(Staff(staffId, "", "", -1))
    , account(Account(-1, -1, "", ""))
{
	// Load the UI.
	ui->setupUi(this);

	// Check if we are in modification or add.
    int currentIndex = 0;
    if(staffId != -1)
    {
		// Load the staff data.
        staff = StaffModel::getStaffById(staffId);

		// Fill the forms with the data.
        ui->firstNameLineEdit->setText(staff.getFirstName());
        ui->lastNameLineEdit->setText(staff.getLastName());

		if(staff.getTypeId() == 7)
            account = AccountModel::getAccountById(staff.getId());

		// Change window title.
		setWindowTitle(QString("Modification de la ressource ") + staff.getFirstName() + " " + staff.getLastName());
    }

    QList<StaffType> types = StaffModel::getStaffTypes();

    for(int i = 0; i < types.size(); i++)
    {
        ui->typeComboBox->addItem(types[i].label);
        if(staffId != -1 && types[i].id == staff.getTypeId())
            currentIndex = i;
    }
    if(staffId != -1)
    {
        ui->typeComboBox->setCurrentIndex(currentIndex);
    }

    // Hide login and password
    onComboBoxChanged();

	// Connections.
	connect(this, SIGNAL(accepted()), this, SLOT(onDialogAccepted()));
	connect(this, SIGNAL(rejected()), this, SLOT(onDialogRejected()));
    connect(ui->typeComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(onComboBoxChanged()));

    connect(this, SIGNAL(onStaffAdded()), (MainWindow*)parent, SLOT(onClientAdded()));

    // Capitalizer.
    QFont font = ui->firstNameLineEdit->font();
    font.setCapitalization(QFont::Capitalize);

    ui->firstNameLineEdit->setFont(font);
    ui->lastNameLineEdit->setFont(font);
}

CreateStaffDialog::~CreateStaffDialog()
{
	delete ui;
}

void CreateStaffDialog::onDialogAccepted()
{

    if(staff.getId() == -1)
    {
        // Create staff.
        int staffId = StaffModel::addStaff(Staff(-1, StringUtil::capitalize(ui->firstNameLineEdit->text()), StringUtil::capitalize(ui->lastNameLineEdit->text()), StaffModel::getTypeIdFromLabel(ui->typeComboBox->currentText())));

        // Create account only if needed.
        if(ui->typeComboBox->currentText() == "Informaticien")
        {
            QString login = ui->loginLineEdit->text();
            QString password = ui->passwordLineEdit->text();

            AccountModel::createAccount(login, password, staffId);
        }
    }
    else
    {
        // Create staff.
        StaffModel::updateStaff(Staff(staff.getId(), StringUtil::capitalize(ui->firstNameLineEdit->text()), StringUtil::capitalize(ui->lastNameLineEdit->text()), StaffModel::getTypeIdFromLabel(ui->typeComboBox->currentText())));

        // Create account only if needed.
        if(ui->typeComboBox->currentText() == "Informaticien")
        {
            QString login = ui->loginLineEdit->text();
            QString password = ui->passwordLineEdit->text();

            if(staff.getTypeId() == 7)
                AccountModel::updateAccount(Account(account.getId(), staff.getId(), login, password));
            else
                AccountModel::createAccount(login, password, staff.getId());
        }
        // Type 7 == informaticien
        else if(staff.getTypeId() == 7)
        {
            AccountModel::removeAccountOfStaff(staff.getId());
        }
    }
    emit onStaffAdded();
}

void CreateStaffDialog::onDialogRejected()
{

}

void CreateStaffDialog::onComboBoxChanged()
{
	// If the selected role is one with an account, display the login & password.
    if(ui->typeComboBox->currentText() == "Informaticien")
    {
        if(staff.getTypeId() == 7)
        {
            ui->passwordLineEdit->setText(account.getPassword());
            ui->loginLineEdit->setText(account.getLogin());
        }

        ui->loginLabel->setVisible(true);
        ui->loginLineEdit->setVisible(true);
        ui->passwordLabel->setVisible(true);
        ui->passwordLineEdit->setVisible(true);
    }
    else
    {
        if(staff.getTypeId() == 7)
        {
            QMessageBox::warning(this,"Attention", "Attention cela va supprimer le compte !");
        }

        ui->loginLabel->setVisible(false);
        ui->loginLineEdit->setVisible(false);
        ui->passwordLabel->setVisible(false);
        ui->passwordLineEdit->setVisible(false);
    }
}
