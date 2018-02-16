#ifndef CREATECLIENTDIALOG_H
#define CREATECLIENTDIALOG_H

#include <QDialog>

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
		explicit CreateClientDialog(QWidget *parent = 0);

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

	private:
		// User interface.
		Ui::CreateClientDialog *ui;
};

#endif // CREATECLIENTDIALOG_H
