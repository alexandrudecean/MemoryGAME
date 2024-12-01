#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>

class Observer;

class Subject {
protected:
    std::vector<Observer*> observers;

public:
    void addObserver(Observer* observer);
    //void notifyResult(int result);
    void notifyGameEnded();
};

#endif
