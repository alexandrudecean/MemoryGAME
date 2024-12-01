#pragma once
#include "Observer.h"
#include "gmock/gmock.h"

class MockObserver : public Observer {
public:
	MOCK_METHOD(void, updateResult, (int result), (override));
	MOCK_METHOD(void, displayBoard, (int rows, int cols, const std::vector<std::vector<Card>>& cards), (override));
	MOCK_METHOD(void, gameEnded, (), (override));
};