#include "Subject.h"
#include "Observer.h"

void Subject::addObserver(Observer* observer) {
    observers.push_back(observer);
}

void Subject::notifyResult(int result) {
    for (Observer* observer : observers) {
        observer->updateResult(result);
    }
}

void Subject::notifyGameEnded()
{
	for (Observer* observer : observers) {
		observer->gameEnded();
	}
}
