#ifndef STAFFVIEW_H
#define STAFFVIEW_H

#include <QTreeView>
#include <QWidget>

class StaffView : public QTreeView
{
	public:
		/**
		 * @brief StaffView constructor
		 * @param parent
		 */
		StaffView(QWidget * parent = Q_NULLPTR);

		/**
		 * @brief refreshData reload the data displayed
		 */
		void refreshData();

		/**
		 * @brief getSelectedStaffId
		 * @return the id of the currently selected staff or -1 if none is selected
		 */
		int getSelectedStaffId();
};

#endif // STAFFVIEW_H
