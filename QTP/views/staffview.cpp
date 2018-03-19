#include "staffview.h"

#include <QStandardItemModel>
#include <QStandardItem>

#include "../model/staffmodel.h"
#include "../model/staff.h"

StaffView::StaffView(QWidget * parent) : QTreeView(parent)
{
	refreshData();
}

void StaffView::refreshData()
{
	// Create a model.
	QStandardItemModel *model = new QStandardItemModel(this);

	// Get the staff types.
	auto staffTypes = StaffModel::getStaffTypes();

	for(StaffType& st : staffTypes)
	{
		// Create an item.
		QStandardItem *typeItem = new QStandardItem(st.label);

		// Get the staff of the current type.
		auto staffList = StaffModel::getStaffListByType(st.id);

		// Append.
		model->invisibleRootItem()->appendRow(typeItem);

		for(Staff& staff : staffList)
		{
			// Create an item list.
			// We will only display the first one, then "hide" the id of the staff in the second item.
			QList<QStandardItem*> staffItems;

			QStandardItem *staffNameItem = new QStandardItem(staff.getFirstName() + " " + staff.getLastName());
			QStandardItem *staffIdItem = new QStandardItem(staff.getId());

			staffItems << staffNameItem << staffIdItem;

			// Append.
			typeItem->appendRow(staffItems);
		}
	}

	// Set the model.
	setModel(model);
}
