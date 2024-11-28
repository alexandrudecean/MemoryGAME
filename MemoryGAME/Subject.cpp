#include "Subject.h"
#include "Observer.h" // Include fișierul complet pentru a folosi Observer

void Subject::addObserver(Observer* observer) {
    observers.push_back(observer);
}

void Subject::notifyResult(int result) {
    for (Observer* observer : observers) {
        observer->updateResult(result); // Acum compilatorul știe detaliile lui Observer
    }
}
