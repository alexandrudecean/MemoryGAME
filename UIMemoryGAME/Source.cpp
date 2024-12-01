#include <QApplication>
#include "MainWindow.h"
#include "Board.h"
#include "GameLogic.h"
#include "StartScreen.h"
#include "Instructions.h"
#include "Login.h"

int main(int argc, char* argv[]) {
	QApplication app(argc, argv);

	// Creează ecranul de start
	StartScreen startScreen;
	startScreen.show();

	// Creează fereastra de instrucțiuni (ascunsă inițial)
	Instructions instructions;

	// Creează fereastra de login (ascunsă inițial)
	Login login;

	// Creează backend-ul și frontend-ul (ascunse inițial)
	Board* backend = nullptr;
	GameLogic* gameLogic = nullptr;
	MainWindow* mainWindow = nullptr;

	// Conectează butonul Play din StartScreen pentru a arăta ecranul de instrucțiuni
	QObject::connect(&startScreen, &StartScreen::playButtonClicked, [&]() {
		startScreen.hide(); // Ascunde StartScreen
		instructions.show(); // Arată ecranul de instrucțiuni
		});

	// Conectează butonul Next din Instructions pentru a arăta fereastra de login
	QObject::connect(&instructions, &Instructions::nextButtonClicked, [&]() {
		instructions.hide(); // Ascunde Instructions
		login.show(); // Arată Login
		});

	// Conectează butonul Start din Login pentru modul Single Player
	QObject::connect(&login, &Login::startSinglePlayer, [&](const QString& username) {
		login.hide(); // Ascunde Login

		// Creează backend-ul pentru joc
		backend = new Board(2, 4); // Creează tabla
		gameLogic = new GameLogic(*backend); // Creează logica jocului
		mainWindow = new MainWindow(); // Creează interfața grafică
		mainWindow->setWindowTitle("Memory Game - Single Player");

		// Adaugă frontend-ul ca observator al backend-ului
		backend->addObserver(mainWindow);

		// Inițializează tabla
		backend->initializeBoard();

		// Conectează semnalele
		QObject::connect(mainWindow, &MainWindow::flipCard, [gameLogic](int row, int col) {
			gameLogic->flipCard(row, col); // Gestionare logică a întoarcerii cărților
			});

		QObject::connect(mainWindow, &MainWindow::requestResetBoard, [gameLogic]() {
			gameLogic->resetGame();
			});

		mainWindow->show(); // Arată fereastra principală
		});

	// Conectează butonul Start din Login pentru modul Multiplayer
	QObject::connect(&login, &Login::startMultiplayer, [&](const QList<QString>& usernames) {
		login.hide(); // Ascunde Login

		// Creează backend-ul pentru joc
		backend = new Board(2, 4); // Creează tabla
		gameLogic = new GameLogic(*backend); // Creează logica jocului
		mainWindow = new MainWindow(); // Creează interfața grafică
		mainWindow->setWindowTitle("Memory Game - Multiplayer");

		// Adaugă frontend-ul ca observator al backend-ului
		backend->addObserver(mainWindow);

		// Inițializează tabla
		backend->initializeBoard();

		// Conectează semnalele
		QObject::connect(mainWindow, &MainWindow::flipCard, [gameLogic](int row, int col) {
			gameLogic->flipCard(row, col); // Gestionare logică a întoarcerii cărților
			});

		QObject::connect(mainWindow, &MainWindow::requestResetBoard, [gameLogic]() {
			gameLogic->resetGame();
			});

		mainWindow->show(); // Arată fereastra principală
		});

	return app.exec();
}
