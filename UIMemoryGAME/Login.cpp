#include "Login.h"
#include <QMessageBox>

Login::Login(QWidget* parent) : QWidget(parent) {
    this->setFixedSize(400, 300);

    QLabel* titleLabel = new QLabel("Login", this);
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("font-size: 24px; color: #FF1493; font-weight: bold;");

    modeSelector = new QComboBox(this);
    modeSelector->addItem("Single Player");
    modeSelector->addItem("Multiplayer");

    formLayout = new QFormLayout();
    usernameField = new QLineEdit(this);
    usernameField->setPlaceholderText("Enter your username");
    formLayout->addRow("Player:", usernameField);

    startButton = new QPushButton("Start", this);
    startButton->setStyleSheet("background-color: #FF1493; color: white; font-size: 18px; border-radius: 10px;");

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(titleLabel);
    layout->addWidget(modeSelector);
    layout->addLayout(formLayout);
    layout->addWidget(startButton);

    connect(startButton, &QPushButton::clicked, this, &Login::onStartClicked);
}

void Login::onStartClicked() {
    if (modeSelector->currentText() == "Single Player") {
        QString username = usernameField->text().trimmed();
        if (username.isEmpty()) {
            QMessageBox::warning(this, "Error", "Please enter your username!");
            return;
        }
        emit startSinglePlayer(username);
    }
    else {
        QList<QString> usernames;
        for (QLineEdit* field : playerFields) {
            QString username = field->text().trimmed();
            if (username.isEmpty()) {
                QMessageBox::warning(this, "Error", "All player fields must be filled!");
                return;
            }
            usernames.append(username);
        }
        emit startMultiplayer(usernames);
    }
}
