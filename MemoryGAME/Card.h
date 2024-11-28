#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
private:
    int id;
    bool flipped;
    std::string imagePath;

public:
    Card(int id, const std::string& imagePath)
        : id(id), flipped(false), imagePath(imagePath) {
    }

    int getId() const { return id; }
    bool isFlipped() const { return flipped; }
    const std::string& getImagePath() const { return imagePath; }

    void flip() { flipped = !flipped; }
    void reset() { flipped = false; }

    bool operator==(const Card& other) const {
        return id == other.id;
    }
};

#endif // CARD_H
