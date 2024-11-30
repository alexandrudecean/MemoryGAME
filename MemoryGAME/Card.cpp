#include "Card.h"

Card::Card(int id, const std::string& imagePath)
	: id(id), flipped(false), imagePath(imagePath) {
}

int Card::getId() const 
{ 
	return id; 
}

bool Card::isFlipped() const
{
	return flipped;
}

const std::string& Card::getImagePath() const
{
	return imagePath;
}

void Card::flip()
{
	flipped = !flipped;
}

void Card::reset()
{
	flipped = false;
}

bool Card::operator==(const Card& other) const
{
	return id == other.id;
}
