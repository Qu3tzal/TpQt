#ifndef CREATEMISCDIALOG_H
#define CREATEMISCDIALOG_H

#include <QDialog>

namespace Ui {
class CreateMiscDialog;
}

class CreateMiscDialog : public QDialog
{
    Q_OBJECT

    public:
        explicit CreateMiscDialog(QWidget *parent = 0);
        ~CreateMiscDialog();

    public slots:
        /**
         * @brief onDialogAccepted slot called when the user "accepts" the dialog.
         */
        void onDialogAccepted();

        /**
         * @brief onDialogRejected slot called when the user "rejects" the dialog.
         */
        void onDialogRejected();

    private:
        Ui::CreateMiscDialog *ui;
};

#endif // CREATEMISCDIALOG_H
