#include <QApplication>
#include "GameWindow.h"
#include "Board.h"
#include "GameLogic.h"
#include "StartScreen.h"
#include "Instructions.h"
#include "Login.h"

int main(int argc, char* argv[]) {
	QApplication app(argc, argv);

	StartScreen startScreen;
	startScreen.show();

	Instructions instructions;

	Login login;

	Board* backend = nullptr;
	GameLogic* gameLogic = nullptr;
	GameWindow* mainWindow = nullptr;

	QObject::connect(&startScreen, &StartScreen::playButtonClicked, [&]() {
		startScreen.hide(); 
		instructions.show(); 
		});

	QObject::connect(&instructions, &Instructions::nextButtonClicked, [&]() {
		instructions.hide(); 
		login.show(); 
		});

	QObject::connect(&login, &Login::startSinglePlayer, [&](const QString& username) {
		login.hide(); 

		backend = new Board(2, 4); 
		gameLogic = new GameLogic(*backend); 
		mainWindow = new GameWindow(); 
		mainWindow->setWindowTitle("Memory Game - Single Player");

		backend->addObserver(mainWindow);

		backend->initializeBoard();

		QObject::connect(mainWindow, &GameWindow::flipCard, [gameLogic](int row, int col) {
			gameLogic->flipCard(row, col); 
			});

		QObject::connect(mainWindow, &GameWindow::requestResetBoard, [gameLogic]() {
			gameLogic->resetGame();
			});

		mainWindow->show();
		});

	QObject::connect(&login, &Login::startMultiplayer, [&](const QList<QString>& usernames) {
		login.hide(); 

		
		backend = new Board(2, 4);
		gameLogic = new GameLogic(*backend); 
		mainWindow = new GameWindow(); 
		mainWindow->setWindowTitle("Memory Game - Multiplayer");

		
		backend->addObserver(mainWindow);

		
		backend->initializeBoard();

		QObject::connect(mainWindow, &GameWindow::flipCard, [gameLogic](int row, int col) {
			gameLogic->flipCard(row, col); 
			});

		QObject::connect(mainWindow, &GameWindow::requestResetBoard, [gameLogic]() {
			gameLogic->resetGame();
			});

		mainWindow->show(); 
		});

	return app.exec();
}
