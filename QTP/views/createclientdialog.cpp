#include "createclientdialog.h"
#include "ui_createclientdialog.h"

#include <QListView>
#include <QStandardItem>
#include <QDebug>

#include "model/staff.h"
#include "model/staffmodel.h"

CreateClientDialog::CreateClientDialog(QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::CreateClientDialog)
{
	// Load the UI.
	ui->setupUi(this);

	// Connections.
	connect(this, SIGNAL(accepted()), this, SLOT(onDialogAccepted()));
	connect(this, SIGNAL(rejected()), this, SLOT(onDialogRejected()));
	connect(ui->addStaffPushButton, SIGNAL(clicked(bool)), this, SLOT(onAddStaffButtonClicked()));
	connect(ui->removeStaffPushButton, SIGNAL(clicked(bool)), this, SLOT(onRemoveStaffButtonClicked()));

	// Populate the staff data.
	QList<Staff> staffs = StaffModel::getStaffList();
	availableStaffModel = new QStandardItemModel(ui->availableStaffListView);
	selectedStaffModel = new QStandardItemModel(ui->selectedStaffListView);

	for(int i(0) ; i < staffs.size() ; ++i)
	{
		QStandardItem* staffNameItem = new QStandardItem(staffs[i].getFirstName() + " " + staffs[i].getLastName());
		QStandardItem* staffIdItem = new QStandardItem(QString::number(staffs[i].getId()));

		QList<QStandardItem*> staffItems;
		staffItems << staffNameItem << staffIdItem;

		availableStaffModel->invisibleRootItem()->appendRow(staffItems);
	}

	availableStaffModel->sort(0);
	ui->availableStaffListView->setModel(availableStaffModel);
	ui->selectedStaffListView->setModel(selectedStaffModel);
}

CreateClientDialog::~CreateClientDialog()
{
	delete ui;
}

void CreateClientDialog::onDialogAccepted()
{

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

	qDebug() << "Added" << staffNameItem->data().toString() << "#" << staffIdItem->data().toString();
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

	qDebug() << "Removed" << staffNameItem->data().toString() << "#" << staffIdItem->data().toString();
}
