#ifndef CREATESTAFFDIALOG_H
#define CREATESTAFFDIALOG_H

#include <QDialog>

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
		explicit CreateStaffDialog(QWidget *parent = 0);

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

	private:
		// User interface.
		Ui::CreateStaffDialog *ui;
};

#endif // CREATESTAFFDIALOG_H
