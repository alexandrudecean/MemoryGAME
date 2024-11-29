#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include "Instructions.h"

class StartScreen : public QWidget {
    Q_OBJECT

public:
    explicit StartScreen(QWidget* parent = nullptr);

signals:
    void playButtonClicked(); // Semnal pentru a indica că s-a apăsat butonul Play

private slots:
    void onPlayButtonClicked(); // Slot pentru butonul Play

private:
    QLabel* titleLabel;
    QPushButton* playButton;
    Instructions* instructionsScreen;
};

#endif // STARTSCREEN_H
