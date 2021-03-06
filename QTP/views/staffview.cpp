#include "staffview.h"

#include <QStandardItemModel>
#include <QStandardItem>
#include <QDebug>

#include "../model/staffmodel.h"
#include "../model/staff.h"

StaffView::StaffView(QWidget * parent) : QTreeView(parent)
{
	refreshData();
}

void StaffView::refreshData()
{
	// Create a model.
	QStandardItemModel *model = new QStandardItemModel();

	// Get the staff types.
	QList<StaffType> staffTypes = StaffModel::getStaffTypes();

	for(QList<StaffType>::iterator typeIterator(staffTypes.begin()) ; typeIterator != staffTypes.end() ; ++typeIterator)
	{
		StaffType& st = *typeIterator;

		// Create an item.
		QStandardItem *typeItem = new QStandardItem(st.label);

		// Get the staff of the current type.
		QList<Staff> staffList = StaffModel::getStaffListByType(st.id);

		// Append.
		model->invisibleRootItem()->appendRow(typeItem);

		for(QList<Staff>::iterator staffIterator(staffList.begin()) ; staffIterator != staffList.end() ; ++staffIterator)
		{
			Staff& staff = *staffIterator;

			// Create an item list.
			// We will only display the first one, then "hide" the id of the staff in the second item.
			QList<QStandardItem*> staffItems;

			QStandardItem *staffNameItem = new QStandardItem(staff.getFirstName() + " " + staff.getLastName());
			QStandardItem *staffIdItem = new QStandardItem(QString::number(staff.getId()));

			staffItems << staffNameItem << staffIdItem;

			// Append.
			typeItem->appendRow(staffItems);
		}
	}

	// Set the model.
	setModel(model);
	expandAll();
}


int StaffView::getSelectedStaffId()
{
	// Get the currently selected staff.
	QModelIndex selectedIndex = this->currentIndex();

	// If invalid, return -1.
	if(!selectedIndex.isValid())
		return -1;

	// Move the index one column.
	QModelIndex idIndex = selectedIndex.sibling(selectedIndex.row(), 1);

	// If invalid, return -1.
	if(!idIndex.isValid())
		return -1;

	// Get the data pointed by the moved-index.
	return idIndex.data().toString().toInt();
}
