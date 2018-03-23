#include "createclientdialog.h"
#include "ui_createclientdialog.h"

#include <QListView>
#include <QStandardItem>
#include <QDebug>

#include "model/staff.h"
#include "model/staffmodel.h"
#include "model/clientmodel.h"
#include "model/appointmentmodel.h"

CreateClientDialog::CreateClientDialog(int clientId, QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::CreateClientDialog)
    , client()
{
	// Load the UI.
	ui->setupUi(this);
    if(clientId != 0)
    {
        // Auto fill the form
        client = ClientModel::getClientById(clientId);
        ui->nameLineEdit->setText(client.getLastName());
        ui->firstnameLineEdit->setText(client.getFirstName());
        ui->addressLineEdit->setText(client.getAdress());
        ui->cityLineEdit->setText(client.getCity());
        ui->zipCodeSpinBox->setValue(client.getPostalCode());
        ui->commentTextEdit->setText(client.getCommentary());
        ui->phoneNumberLineEdit->setText(QString::number(client.getPhoneNumber()));
        ui->dateEdit->setDate(client.getAppointmentDate());
        ui->lengthAppointmentSpinBox->setValue(client.getAppointmentDuration());
        ui->prioritySpinBox->setValue(client.getPriority());
		setWindowTitle("Modification du client " + client.getFirstName() + " " + client.getLastName());
    }
	// Connections.
	connect(this, SIGNAL(accepted()), this, SLOT(onDialogAccepted()));
	connect(this, SIGNAL(rejected()), this, SLOT(onDialogRejected()));
	connect(ui->addStaffPushButton, SIGNAL(clicked(bool)), this, SLOT(onAddStaffButtonClicked()));
	connect(ui->removeStaffPushButton, SIGNAL(clicked(bool)), this, SLOT(onRemoveStaffButtonClicked()));

	// Populate the staff data.
	QList<Staff> staffs = StaffModel::getStaffList();
	availableStaffModel = new QStandardItemModel(ui->availableStaffListView);
	selectedStaffModel = new QStandardItemModel(ui->selectedStaffListView);

    if(clientId != 0)
    {
        QList<int> staffs = AppointmentModel::getStaffByClientId(clientId);
        QList<Staff> allStaffs = StaffModel::getStaffList();

        for(int i(0); i < staffs.size(); i++)
        {
            Staff staff = StaffModel::getStaffById(staffs[i]);
            QStandardItem* staffNameItem = new QStandardItem(staff.getFirstName() + " " + staff.getLastName());
            QStandardItem* staffIdItem = new QStandardItem(QString::number(staff.getId()));

            QList<QStandardItem*> staffItems;
            staffItems << staffNameItem << staffIdItem;

            selectedStaffModel->invisibleRootItem()->appendRow(staffItems);
        }
        for(int i(0); i < allStaffs.size(); i++)
        {
            if(!staffs.contains(allStaffs[i].getId()))
            {
                QStandardItem* staffNameItem = new QStandardItem(allStaffs[i].getFirstName() + " " + allStaffs[i].getLastName());
                QStandardItem* staffIdItem = new QStandardItem(QString::number(allStaffs[i].getId()));

                QList<QStandardItem*> staffItems;
                staffItems << staffNameItem << staffIdItem;

                availableStaffModel->invisibleRootItem()->appendRow(staffItems);
            }

        }
    }
    else
    {
        for(int i(0) ; i < staffs.size() ; ++i)
        {
            QStandardItem* staffNameItem = new QStandardItem(staffs[i].getFirstName() + " " + staffs[i].getLastName());
            QStandardItem* staffIdItem = new QStandardItem(QString::number(staffs[i].getId()));

            QList<QStandardItem*> staffItems;
            staffItems << staffNameItem << staffIdItem;

            availableStaffModel->invisibleRootItem()->appendRow(staffItems);
        }
    }

	availableStaffModel->sort(0);
	ui->availableStaffListView->setModel(availableStaffModel);
	ui->selectedStaffListView->setModel(selectedStaffModel);

    QRegExp ipRegex ("[0-9]*");
    QRegExpValidator *ipValidator = new QRegExpValidator(ipRegex, this);
    ui->phoneNumberLineEdit->setValidator(ipValidator);
}

CreateClientDialog::~CreateClientDialog()
{
	delete ui;
}

void CreateClientDialog::onDialogAccepted()
{
    if(client.getId() != 0)
    {
        client = Client(client.getId(), ui->nameLineEdit->text()
                        , ui->firstnameLineEdit->text()
                        , ui->addressLineEdit->text()
                        , ui->cityLineEdit->text()
                        , ui->zipCodeSpinBox->value()
                        , ui->commentTextEdit->toPlainText()
                        , ui->phoneNumberLineEdit->text().toInt()
                        , ui->dateEdit->date()
                        , ui->lengthAppointmentSpinBox->value()
                        , ui->prioritySpinBox->value());
        ClientModel::updateClient(client);

        AppointmentModel::deleteAppointmentByClientId(client.getId());
        for(int i(0); i < selectedStaffModel->rowCount(); i++)
        {
            QModelIndex selectedStaffIndex = selectedStaffModel->index(i, 0);
            QModelIndex selectedStaffIdIndex = selectedStaffIndex.sibling(selectedStaffIndex.row(), 1);
            AppointmentModel::createAppointment(selectedStaffIdIndex.data(Qt::DisplayRole).toString().toInt(), client.getId());
        }
    }
    else
    {
        client = Client(0, ui->nameLineEdit->text()
                        , ui->firstnameLineEdit->text()
                        , ui->addressLineEdit->text()
                        , ui->cityLineEdit->text()
                        , ui->zipCodeSpinBox->value()
                        , ui->commentTextEdit->toPlainText()
                        , ui->phoneNumberLineEdit->text().toInt()
                        , ui->dateEdit->date()
                        , ui->lengthAppointmentSpinBox->value()
                        , ui->prioritySpinBox->value());
        int clientId = ClientModel::createClient(client);
        for(int i(0); i < selectedStaffModel->rowCount(); i++)
        {
            QModelIndex selectedStaffIndex = selectedStaffModel->index(i, 0);
            QModelIndex selectedStaffIdIndex = selectedStaffIndex.sibling(selectedStaffIndex.row(), 1);
            AppointmentModel::createAppointment(selectedStaffIdIndex.data(Qt::DisplayRole).toString().toInt(), clientId);
        }
    }
}

void CreateClientDialog::onDialogRejected()
{

}

void CreateClientDialog::onAddStaffButtonClicked()
{
	// Get selected staff and its associated ID.
	QModelIndex selectedStaffIndex = ui->availableStaffListView->currentIndex();

	if(!selectedStaffIndex.isValid())
		return;

	QModelIndex selectedStaffIdIndex = selectedStaffIndex.sibling(selectedStaffIndex.row(), 1);

	// Create an item for the selected list.
	QStandardItem* staffNameItem = new QStandardItem(selectedStaffIndex.data().toString());
	QStandardItem* staffIdItem = new QStandardItem(selectedStaffIdIndex.data().toString());

	QList<QStandardItem *> staffItem;
	staffItem << staffNameItem << staffIdItem;

	selectedStaffModel->invisibleRootItem()->appendRow(staffItem);
	availableStaffModel->removeRow(selectedStaffIndex.row());
}

void CreateClientDialog::onRemoveStaffButtonClicked()
{
	// Get selected staff and its associated ID.
	QModelIndex selectedStaffIndex = ui->selectedStaffListView->currentIndex();

	if(!selectedStaffIndex.isValid())
		return;

	QModelIndex selectedStaffIdIndex = selectedStaffIndex.sibling(selectedStaffIndex.row(), 1);

	// Create an item for the selected list.
	QStandardItem* staffNameItem = new QStandardItem(selectedStaffIndex.data().toString());
	QStandardItem* staffIdItem = new QStandardItem(selectedStaffIdIndex.data().toString());

	QList<QStandardItem *> staffItem;
	staffItem << staffNameItem << staffIdItem;

	availableStaffModel->invisibleRootItem()->appendRow(staffItem);
	availableStaffModel->sort(0);
	selectedStaffModel->removeRow(selectedStaffIndex.row());
}
