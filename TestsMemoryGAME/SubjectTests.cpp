#include "Subject.h"
#include "MockObserver.h"
#include "gtest/gtest.h"


using ::testing::_;
using ::testing::Exactly;

namespace BackendTests {

	class TestableSubject : public Subject {
	public:
		const std::vector<Observer*>& getObservers() const {
			return observers;
		}
	};

	TEST(SubjectTests, AddObserverWorksCorrectly) {
		Subject subject;
		MockObserver observer1, observer2;

		subject.addObserver(&observer1);
		subject.addObserver(&observer2);

		EXPECT_NO_THROW(subject.addObserver(&observer1));
	}

	TEST(SubjectTests, NotifyResultCallsUpdateResult) {
		Subject subject;
		MockObserver observer1, observer2;

		subject.addObserver(&observer1);
		subject.addObserver(&observer2);

		EXPECT_CALL(observer1, updateResult(42)).Times(1);
		EXPECT_CALL(observer2, updateResult(42)).Times(1);

		subject.notifyResult(42);
	}

	TEST(SubjectTests, NotifyGameEndedCallsGameEnded) {
		Subject subject;
		MockObserver observer1, observer2;

		subject.addObserver(&observer1);
		subject.addObserver(&observer2);

		EXPECT_CALL(observer1, gameEnded()).Times(1);
		EXPECT_CALL(observer2, gameEnded()).Times(1);

		subject.notifyGameEnded();
	}

	TEST(SubjectTests, NotifyDisplayBoardCallsDisplayBoard) {
		TestableSubject subject;
		MockObserver observer1, observer2;

		subject.addObserver(&observer1);
		subject.addObserver(&observer2);

		std::vector<std::vector<Card>> mockBoard = {
			{ Card(1, "../images/1.jpg"), Card(2, "../images/2.jpg") },
			{ Card(3, "../images/3.jpg"), Card(4, "../images/4.jpg") }
		};

		EXPECT_CALL(observer1, displayBoard(2, 2, mockBoard)).Times(1);
		EXPECT_CALL(observer2, displayBoard(2, 2, mockBoard)).Times(1);

		for (Observer* observer : subject.getObservers()) {
			observer->displayBoard(2, 2, mockBoard);
		}
	}

}