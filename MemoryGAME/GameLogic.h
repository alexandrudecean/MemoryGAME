﻿#ifndef GAMELOGIC_H
#define GAMELOGIC_H
#include <thread> // Pentru std::this_thread::sleep_for
#include <chrono> // Pentru std::chrono::milliseconds
#include "Board.h"


class GameLogic {
private:
	Board& board;              // Referință la tabelă
	int score;                 // Scorul jocului
	std::pair<int, int> firstCard;  // Coordonatele primei cărți întoarse
	std::pair<int, int> secondCard; // Coordonatele celei de-a doua cărți întoarse
	bool firstCardFlipped;     // True dacă o carte a fost întoarsă

public:
	GameLogic(Board& board);

	void flipCard(int row, int col); // Gestionarea întoarcerii unei cărți
	bool areMatches() const;         // Verifică dacă cele două cărți sunt la fel
	int getScore() const; // Returnează scorul
	void resetGame();
};

#endif // GAMELOGIC_H
