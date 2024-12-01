#ifndef WINWINDOW_H
#define WINWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

class WinWindow : public QWidget {
	Q_OBJECT

public:
	explicit WinWindow(const QString& message, QWidget* parent = nullptr);

signals:
	void playAgain();
	void exitGame();

private:
	QLabel* messageLabel;
	QPushButton* playAgainButton;
	QPushButton* exitButton;
};

#endif 
