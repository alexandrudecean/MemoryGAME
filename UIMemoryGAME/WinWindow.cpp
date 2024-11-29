#include "WinWindow.h"

WinWindow::WinWindow(const QString& message, QWidget* parent)
    : QWidget(parent) {
    // Dimensiuni mari
    this->setFixedSize(800, 500);
    this->setStyleSheet(
        "background-color: #FF69B4; " // Roz intens
        "border-radius: 25px; "
        "font-family: 'Arial';"
    );

    // Mesajul principal
    messageLabel = new QLabel(message, this);
    messageLabel->setStyleSheet(
        "font-size: 32px; "
        "font-weight: bold; "
        "color: white; "
        "padding: 20px;"
        "text-align: center;"
    );
    messageLabel->setAlignment(Qt::AlignCenter);

    // Buton "Play Again"
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

    // Buton "Exit"
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

    // Layout pentru butoane
    QHBoxLayout* buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(playAgainButton);
    buttonLayout->addWidget(exitButton);
    buttonLayout->setSpacing(50);

    // Layout principal
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(messageLabel, 0, Qt::AlignCenter);
    layout->addLayout(buttonLayout);
    layout->setSpacing(40);

    // Conectare butoane la semnale
    connect(playAgainButton, &QPushButton::clicked, this, &WinWindow::playAgain);
    connect(exitButton, &QPushButton::clicked, this, &WinWindow::exitGame);
}
