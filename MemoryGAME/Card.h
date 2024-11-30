#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
private:
    int id;
    bool flipped;
    std::string imagePath;

public:
    Card(int id, const std::string& imagePath);

    int getId() const;
    bool isFlipped() const;
    const std::string& getImagePath() const;

    void flip();
    void reset();

    bool operator==(const Card& other) const;
};

#endif
