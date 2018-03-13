#ifndef STAFFVIEW_H
#define STAFFVIEW_H

#include <QTreeWidget>
#include <QWidget>

class StaffView : public QTreeWidget
{
public:
    StaffView(QWidget * parent = Q_NULLPTR);
};

#endif // STAFFVIEW_H
