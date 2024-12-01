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
    void playButtonClicked(); 

private slots:
    void onPlayButtonClicked(); 

private:
    QLabel* titleLabel;
    QPushButton* playButton;
    Instructions* instructionsScreen;
};

#endif 
