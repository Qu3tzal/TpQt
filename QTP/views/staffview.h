#ifndef STAFFVIEW_H
#define STAFFVIEW_H

#include <QTreeView>
#include <QWidget>

class StaffView : public QTreeView
{
	public:
		StaffView(QWidget * parent = Q_NULLPTR);

		void refreshData();
};

#endif // STAFFVIEW_H
