#include <QApplication>
#include "MainWindow.h"
#include "Board.h"
#include "GameLogic.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    // Creează backend-ul
    Board backend(2, 4);              // Tabla de joc
    GameLogic gameLogic(backend);     // Logica jocului

    // Creează frontend-ul
    MainWindow window;

    // Adaugă frontend-ul ca observator al backend-ului
    backend.addObserver(&window);

    // Inițializează tabla doar după adăugarea observatorului
    backend.initializeBoard();

    // Conectează semnalele
    QObject::connect(&window, &MainWindow::flipCard, [&gameLogic](int row, int col) {
        gameLogic.flipCard(row, col); // Gestionare logică a întoarcerii cărților
        });

    // Afișează tabla de joc în UI
    window.displayBoard(backend.getRows(), backend.getCols(), backend.getCards());
    window.show();

    return app.exec();
}
