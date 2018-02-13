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
		explicit AuthentificationDialog(QWidget *parent = 0, QMainWindow *windowToLaunch = nullptr);
		~AuthentificationDialog();

	public slots:
		void login();

	private:
		Ui::AuthentificationDialog *ui;

		QMainWindow *m_windowToLaunch;
};

#endif // AUTHENTIFICATIONDIALOG_H
