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

	private:
		// The user interface class.
		Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
