#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>

// Declarație forward
class Observer;

class Subject {
protected:
    std::vector<Observer*> observers;

public:
    void addObserver(Observer* observer);
    void notifyResult(int result);
};

#endif // SUBJECT_H
