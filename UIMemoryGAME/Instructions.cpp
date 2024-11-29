#include "Instructions.h"

Instructions::Instructions(QWidget* parent) : QWidget(parent) {
    this->setFixedSize(800, 600);

    this->setStyleSheet("background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #FFC1CC, stop:1 #FF69B4);");

    titleLabel = new QLabel("Instructions", this);
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("font-size: 40px; font-weight: bold; color: white;");

    instructionsText = new QLabel(
        "• Flip two cards to find a match.\n"
        "• If they match, you score a point.\n"
        "• If not, they flip back.\n"
        "• The player with the most matches wins!",
        this
    );
    instructionsText->setWordWrap(true);
    instructionsText->setAlignment(Qt::AlignLeft);
    instructionsText->setStyleSheet("font-size: 18px; color: black; padding: 10px; background: white; border-radius: 10px;");

    nextButton = new QPushButton("Next", this);
    nextButton->setStyleSheet(
        "QPushButton { font-size: 18px; background-color: #FF1493; color: white; border-radius: 15px; }"
        "QPushButton:hover { background-color: #FF6EB4; }"
        "QPushButton:pressed { background-color: #C71585; }"
    );

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(titleLabel, 0, Qt::AlignCenter);
    layout->addWidget(instructionsText, 0, Qt::AlignCenter);
    layout->addWidget(nextButton, 0, Qt::AlignCenter);

    connect(nextButton, &QPushButton::clicked, this, &Instructions::onNextButtonClicked);
}

void Instructions::onNextButtonClicked() {
    emit nextButtonClicked();
}
