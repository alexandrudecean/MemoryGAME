#include "StartScreen.h"
#include "Instructions.h"

StartScreen::StartScreen(QWidget* parent) : QWidget(parent), instructionsScreen(nullptr) {
    this->setFixedSize(800, 600);

    this->setStyleSheet("background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #FFC1CC, stop:1 #FF69B4);");

    titleLabel = new QLabel("Memory Game", this);
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("font-size: 60px; font-weight: bold; color: #FF1493;");

    playButton = new QPushButton("Play", this);
    playButton->setStyleSheet(
        "QPushButton {"
        "   font-size: 24px; font-weight: bold; color: white;"
        "   background-color: #FF1493; border-radius: 25px; padding: 15px;"
        "} "
        "QPushButton:hover { background-color: #FF6EB4; }"
        "QPushButton:pressed { background-color: #C71585; }"
    );

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(titleLabel, 0, Qt::AlignCenter);
    layout->addWidget(playButton, 0, Qt::AlignCenter);

    connect(playButton, &QPushButton::clicked, this, &StartScreen::onPlayButtonClicked);
}

void StartScreen::onPlayButtonClicked() {
    emit playButtonClicked(); 
}
