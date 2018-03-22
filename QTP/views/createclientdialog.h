#ifndef CREATECLIENTDIALOG_H
#define CREATECLIENTDIALOG_H

#include <QDialog>
#include <QStandardItemModel>
#include "model/client.h"

namespace Ui {
class CreateClientDialog;
}

/**
 * @brief The CreateClientDialog class. This dialogs allows the user to enter the data for a new client.
 */
class CreateClientDialog : public QDialog
{
		Q_OBJECT

	public:
		/**
		 * @brief Constructor.
		 * @param parent the parent of this dialog
		 */
        explicit CreateClientDialog(int clientId, QWidget *parent = 0);

		/**
		 * @brief Destructor.
		 */
		~CreateClientDialog();

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
		 * @brief onAddStaffButtonClicked slot called when the user wants to add a staff member to the staff list.
		 */
		void onAddStaffButtonClicked();

		/**
		 * @brief onRemoveStaffButtonClicked slot called when the user wants to remove a staff member from the staff list.
		 */
		void onRemoveStaffButtonClicked();

	private:
		// User interface.
		Ui::CreateClientDialog *ui;
		QStandardItemModel *availableStaffModel, *selectedStaffModel;
        Client client;
};

#endif // CREATECLIENTDIALOG_H
