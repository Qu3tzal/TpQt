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
		explicit AuthentificationDialog(QWidget *parent = nullptr);

		/**
		 * @brief Destructor
		 */
		~AuthentificationDialog();

		/**
		 * @brief Returns the state of the login
		 * @attention Must be called AFTER exec()
		 * @return true if the login is successful, false otherwise
		 */
		bool loginSuccess() const;

	public slots:
		/**
		 * @brief Login slot called when the user wants to login.
		 */
		void login();

	private:
		// The user interface class.
		Ui::AuthentificationDialog *ui;

		// The login success flag.
		bool m_loginSuccess;
};

#endif // AUTHENTIFICATIONDIALOG_H
