#ifndef AUTHENTIFICATIONDIALOG_H
#define AUTHENTIFICATIONDIALOG_H

#include <QDialog>
#include <QMainWindow>

namespace Ui {
class AuthentificationDialog;
}

/**
 * @brief The AuthentificationDialog class
 *
 * This class shows a login/password dialog.
 *
 */
class AuthentificationDialog : public QDialog
{
	Q_OBJECT

	public:
		/**
		 * @brief Constructor
		 * @param parent the parent of the dialog
		 */
		explicit AuthentificationDialog(QWidget *parent = Q_NULLPTR);

		/**
		 * @brief Destructor
		 */
		~AuthentificationDialog();

	private slots:
		/**
		 * @brief on_authentificationDialogButtonBox_accepted slot called when the user "accepts" the dialog.
		 */
		void on_authentificationDialogButtonBox_accepted();

		/**
		 * @brief on_authentificationDialogButtonBox_rejected slot called when the user "rejects" the dialog.
		 */
		void on_authentificationDialogButtonBox_rejected();

	private:
		// The user interface class.
		Ui::AuthentificationDialog *ui;
};

#endif // AUTHENTIFICATIONDIALOG_H
