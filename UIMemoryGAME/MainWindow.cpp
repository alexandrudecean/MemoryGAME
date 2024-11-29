#include "MainWindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), currentRows(2), currentCols(2), score(0), maxScore(4) {
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

void MainWindow::updateResult(int result) {
    score = result;
    resultLabel->setText(QString("Scor: %1").arg(score));
    qDebug() << "Score:" << score << "MaxScore:" << maxScore;

    if (score == maxScore) {
        WinWindow* winWindow = new WinWindow("Congratulations! You've completed the round.", this);
        connect(winWindow, &WinWindow::playAgain, [this, winWindow]() {
            winWindow->close();
            resetGame(); // Pornește o nouă rundă
            });
        connect(winWindow, &WinWindow::exitGame, [this, winWindow]() {
            winWindow->close();
            close(); // Închide aplicația
            });
        winWindow->show();
    }
}

void MainWindow::displayBoard(int rows, int cols, const std::vector<std::vector<Card>>& cards) {
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
                    "width: 200px; height: 250px;"
                    "}");
            }

            boardLayout->addWidget(cardButton, i, j);

            connect(cardButton, &QPushButton::clicked, this, [this, i, j]() {
                emit flipCard(i, j);
                });
        }
    }
}

void MainWindow::resetGame() {
    currentRows *= 2;
    currentCols *= 2;

    score = 0;
    maxScore = (currentRows * currentCols) / 2;

    resultLabel->setText("Scor: 0");

    emit flipCard(-1, -1); // Semnal special pentru resetare
}

int MainWindow::getCurrentRows() const {
    return currentRows;
}

int MainWindow::getCurrentCols() const {
    return currentCols;
}
