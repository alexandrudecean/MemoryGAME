#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include "Card.h"
#include "Board.h"
#include "Observer.h"
#include "WinWindow.h"
#include <vector>

class GameWindow : public QMainWindow, public Observer {
    Q_OBJECT

private:
    QGridLayout* boardLayout;
    QLabel* resultLabel;
    std::vector<std::vector<QPushButton*>> buttons;
    std::vector<std::vector<Card>> cards;
public:
    explicit GameWindow(QWidget* parent = nullptr);

    void updateResult(int result) override; 
    void displayBoard(int rows, int cols, const std::vector<std::vector<Card>>& cards);
    void resetGame(); 
	void gameEnded() override;

signals:
    void flipCard(int row, int col);
    void requestResetBoard();
};

#endif