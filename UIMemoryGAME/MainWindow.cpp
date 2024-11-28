#include "MainWindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    setWindowTitle("MemoryGame");

    auto* centralWidget = new QWidget(this);
    auto* layout = new QVBoxLayout;

    boardLayout = new QGridLayout;
    resultLabel = new QLabel("Scor: 0");

    layout->addLayout(boardLayout);
    layout->addWidget(resultLabel);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
}

void MainWindow::updateResult(int score) {
    // Actualizează scorul afișat
    resultLabel->setText(QString("Scor: %1").arg(score));
}

void MainWindow::displayBoard(int rows, int cols, const std::vector<std::vector<Card>>& cards) {
    // Resetează layout-ul pentru a afișa tabla de joc
    QLayoutItem* item;
    while ((item = boardLayout->takeAt(0))) {
        delete item->widget();
        delete item;
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            auto* cardButton = new QPushButton(this);

            if (cards[i][j].isFlipped()) {
                cardButton->setStyleSheet(
                    QString("QPushButton {"
                        "background-image: url(%1);"
                        "background-position: center;"
                        "background-repeat: no-repeat;"
                        "border: 1px solid black;"
                        "width: 100px; height: 150px; }")
                    .arg(QString::fromStdString(cards[i][j].getImagePath())));
            }
            else {
                cardButton->setStyleSheet(
                    "QPushButton {"
                    "background-color: white;"
                    "border: 1px solid black;"
                    "width: 100px; height: 150px;"
                    "}");
            }

            boardLayout->addWidget(cardButton, i, j);

            connect(cardButton, &QPushButton::clicked, this, [this, i, j]() {
                emit flipCard(i, j); // Semnal pentru backend
                });
        }
    }
}
