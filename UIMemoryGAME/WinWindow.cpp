#include "WinWindow.h"

WinWindow::WinWindow(const QString& message, QWidget* parent)
    : QWidget(parent) {
    
    this->setFixedSize(800, 500);
    this->setStyleSheet(
        "background-color: #FF69B4; " 
        "border-radius: 25px; "
        "font-family: 'Arial';"
    );

    messageLabel = new QLabel(message, this);
    messageLabel->setStyleSheet(
        "font-size: 32px; "
        "font-weight: bold; "
        "color: white; "
        "padding: 20px;"
        "text-align: center;"
    );
    messageLabel->setAlignment(Qt::AlignCenter);

    playAgainButton = new QPushButton("🔄 Play Again", this);
    playAgainButton->setStyleSheet(
        "QPushButton {"
        "   font-size: 24px; "
        "   font-weight: bold; "
        "   color: white; "
        "   background-color: #FFB6C1; "
        "   border: none; "
        "   border-radius: 20px; "
        "   padding: 15px;"
        "} "
        "QPushButton:hover {"
        "   background-color: #FF1493;"
        "} "
        "QPushButton:pressed {"
        "   background-color: #C71585;"
        "}"
    );

    exitButton = new QPushButton("❌ Exit Game", this);
    exitButton->setStyleSheet(
        "QPushButton {"
        "   font-size: 24px; "
        "   font-weight: bold; "
        "   color: white; "
        "   background-color: #FFB6C1; "
        "   border: none; "
        "   border-radius: 20px; "
        "   padding: 15px;"
        "} "
        "QPushButton:hover {"
        "   background-color: #FF1493;"
        "} "
        "QPushButton:pressed {"
        "   background-color: #C71585;"
        "}"
    );

    QHBoxLayout* buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(playAgainButton);
    buttonLayout->addWidget(exitButton);
    buttonLayout->setSpacing(50);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(messageLabel, 0, Qt::AlignCenter);
    layout->addLayout(buttonLayout);
    layout->setSpacing(40);

    connect(playAgainButton, &QPushButton::clicked, this, &WinWindow::playAgain);
    connect(exitButton, &QPushButton::clicked, this, &WinWindow::exitGame);
}
