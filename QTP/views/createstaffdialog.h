#ifndef CREATESTAFFDIALOG_H
#define CREATESTAFFDIALOG_H

#include <QDialog>
#include "controler/staffcontroler.h"
#include "model/staff.h"
#include "model/account.h"

namespace Ui {
class CreateStaffDialog;
}

/**
 * @brief The CreateStaffDialog class. This dialogs allows the user to enter the data for a new staff member.
 */
class CreateStaffDialog : public QDialog
{
		Q_OBJECT

	public:
		/**
		 * @brief Constructor.
		 * @param parent the parent of this dialog
		 */
        explicit CreateStaffDialog(int staffId, QWidget *parent = 0);

		/**
		 * @brief Destructor.
		 */
		~CreateStaffDialog();

	private slots:
		/**
		 * @brief onDialogAccepted slot called when the user "accepts" the dialog.
		 */
		void onDialogAccepted();

		/**
		 * @brief onDialogRejected slot called when the user "rejects" the dialog.
		 */
		void onDialogRejected();

        /**
         * @brief onComboBoxChanged slot called when the combo box index change
         * and hide or show login and password edit
         */
        void onComboBoxChanged();

private:
		// User interface.
		Ui::CreateStaffDialog *ui;

        // The id of the staff (If modification Mode)
        Staff staff;

        // The id of the account (if modification Mode)
        Account account;
};

#endif // CREATESTAFFDIALOG_H
