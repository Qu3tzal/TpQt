#ifndef AUTHENTIFICATIONDIALOG_H
#define AUTHENTIFICATIONDIALOG_H

#include <QDialog>
#include <QMainWindow>

namespace Ui {
class AuthentificationDialog;
}

class AuthentificationDialog : public QDialog
{
		Q_OBJECT

	public:
		explicit AuthentificationDialog(QWidget *parent = nullptr);
		~AuthentificationDialog();
		bool loginSuccess() const;

	public slots:
		void login();

	private:
		Ui::AuthentificationDialog *ui;
		bool m_loginSuccess;
};

#endif // AUTHENTIFICATIONDIALOG_H
