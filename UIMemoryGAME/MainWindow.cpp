#include "MainWindow.h"
#include <QMessageBox>
#include <QCoreApplication>

MainWindow::MainWindow(Board* board, QWidget* parent)
    : QMainWindow(parent), board(board), currentRows(board->getRows()), currentCols(board->getCols()) {
    setWindowTitle("MemoryGame");

    auto* centralWidget = new QWidget(this);
    auto* layout = new QVBoxLayout;

    boardLayout = new QGridLayout;
    resultLabel = new QLabel(QString("Scor: %1").arg(board->getScore())); // Folosește scorul din Board

    layout->addLayout(boardLayout);
    layout->addWidget(resultLabel);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
}

void MainWindow::updateResult(int result) {
    resultLabel->setText(QString("Scor: %1").arg(board->getScore())); // Obține scorul din Board

    // Verificăm dacă scorul atinge maximul
    if (board->getScore() == board->getMaxScore()) {
        WinWindow* winWindow = new WinWindow("Congratulations! You've completed the round.", this);

        connect(winWindow, &WinWindow::playAgain, [this, winWindow]() {
            winWindow->close(); // Închide fereastra de câștig
            emit requestResetBoard(); // Cere backend-ului să reseteze tabla
            });

        connect(winWindow, &WinWindow::exitGame, [this, winWindow]() {
            winWindow->close();
            close(); // Închide aplicația
            });

        winWindow->show();
    }
}




void MainWindow::displayBoard(int rows, int cols, const std::vector<std::vector<Card>>& cards) {
    if (buttons.size() != rows || (buttons.size() > 0 && buttons[0].size() != cols)) {
        QLayoutItem* item;
        while ((item = boardLayout->takeAt(0))) {
            delete item->widget();
            delete item;
        }
        buttons.resize(rows, std::vector<QPushButton*>(cols, nullptr));
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (!buttons[i][j]) {
                buttons[i][j] = new QPushButton(this);
                boardLayout->addWidget(buttons[i][j], i, j);
                connect(buttons[i][j], &QPushButton::clicked, this, [this, i, j]() {
                    emit flipCard(i, j);
                    });
            }

            if (cards[i][j].isFlipped()) {
                buttons[i][j]->setStyleSheet(
                    QString("QPushButton {"
                        "background-image: url(%1);"
                        "background-position: center;"
                        "background-repeat: no-repeat;"
                        "border: 1px solid black;"
                        "width: 100px; height: 150px; }")
                    .arg(QString::fromStdString(cards[i][j].getImagePath())));
            }
            else {
                buttons[i][j]->setStyleSheet(
                    "QPushButton {"
                    "background-color: white;"
                    "border: 1px solid black;"
                    "width: 200px; height: 250px; }");
            }
        }
    }

    QCoreApplication::processEvents();
}


void MainWindow::resetGame() {
    board->setScore(0); // Resetează scorul din backend
    resultLabel->setText("Scor: 0"); // Actualizează afișajul

    // Notifică backend-ul să reinitializeze tabla
    emit requestResetBoard(); // Emite semnalul pentru resetarea tablei
}



void MainWindow::gameEnded() {
    WinWindow* winWindow = new WinWindow("Congratulations! You've completed the round.", this);
    connect(winWindow, &WinWindow::playAgain, [this, winWindow]() {
        winWindow->close();
        resetGame(); 
        });
    connect(winWindow, &WinWindow::exitGame, [this, winWindow]() {
        winWindow->close();
        close();
        });
    winWindow->show();
}

int MainWindow::getCurrentRows() const {
    return currentRows;
}

int MainWindow::getCurrentCols() const {
    return currentCols;
}
