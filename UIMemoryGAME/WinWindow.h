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
    void playAgain(); // Semnal pentru a începe o nouă rundă
    void exitGame();  // Semnal pentru a ieși din joc

private:
    QLabel* messageLabel;
    QPushButton* playAgainButton;
    QPushButton* exitButton;
};

#endif // WINWINDOW_H
