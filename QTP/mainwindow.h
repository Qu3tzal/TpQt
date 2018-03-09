#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

/**
 * @brief The MainWindow class. Provides the main view.
 */
class MainWindow : public QMainWindow
{
		Q_OBJECT

	public:
		/**
		 * @brief Constructor
		 * @param parent the parent of the MainWindow
		 */
		explicit MainWindow(QWidget *parent = 0);

		/**
		 * @brief Destructor
		 */
		~MainWindow();

	private slots:
		/**
		 * @brief onCreateClientAction slot called when the user wants to create a new client.
		 */
		void onCreateClientAction();

		/**
		 * @brief onCreateStaffAction slot called when the user wants to create a new staff member.
		 */
		void onCreateStaffAction();

		/**
		 * @brief onAboutUsAction slot called when the user wants to display the about us window.
		 */
		void onAboutUsAction();

		/**
		 * @brief onAboutQtAction slot called when the user wants to display the about Qt window.
		 */
		void onAboutQtAction();

	private:
		// The user interface class.
		Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
