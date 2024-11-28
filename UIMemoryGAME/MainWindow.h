#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include "Card.h"
#include "Observer.h"
#include <vector>

class MainWindow : public QMainWindow, public Observer {
    Q_OBJECT

private:
    QGridLayout* boardLayout;
    QLabel* resultLabel;
    std::vector<std::vector<QPushButton*>> buttons;
    std::vector<std::vector<Card>> cards;

public:
    explicit MainWindow(QWidget* parent = nullptr);

  //  void updateCardStyle(int row, int col);
    void updateResult(int result) override; // Notificare de la backend
    void displayBoard(int rows, int cols, const std::vector<std::vector<Card>>& cards);


signals:
    void flipCard(int row, int col);
};

#endif // MAINWINDOW_H
