#include <gmock/gmock.h>

#include "DataStructures/Queues/FixedSizeCircularArrayQueue.hpp"

namespace Core::DataStructures::Queues::Test {
class NonEmptyIntegerFixedSizeCircularArrayQueueTest : public testing::Test {
public:
	NonEmptyIntegerFixedSizeCircularArrayQueueTest() noexcept;
	~NonEmptyIntegerFixedSizeCircularArrayQueueTest() noexcept override = default;

protected:
	FixedSizeCircularArrayQueue<int, 5> fixedSizeCircularArrayQueue {};
};

NonEmptyIntegerFixedSizeCircularArrayQueueTest::NonEmptyIntegerFixedSizeCircularArrayQueueTest() noexcept {
	for (auto element {10}; element < 50; element = element + 10) {
		fixedSizeCircularArrayQueue.enqueue(element);
	}
}

TEST_F(NonEmptyIntegerFixedSizeCircularArrayQueueTest,
       GivenInteger_WhenEnqueueAndQueueIsNotFull_ThenElementsAreInExpectedOrder) {
	fixedSizeCircularArrayQueue.enqueue(50);
	
	EXPECT_THAT(*fixedSizeCircularArrayQueue.getFront(), testing::Eq(10));
	EXPECT_THAT(*fixedSizeCircularArrayQueue.getBack(), testing::Eq(50));
}

TEST_F(NonEmptyIntegerFixedSizeCircularArrayQueueTest, GivenInteger_WhenEnqueueAndQueueIsNotFull_ThenSizeIsIncremented) {
	fixedSizeCircularArrayQueue.enqueue(50);
	const auto size {fixedSizeCircularArrayQueue.getSize()};
	
	EXPECT_THAT(size, testing::Eq(5));
}

TEST_F(NonEmptyIntegerFixedSizeCircularArrayQueueTest, GivenInteger_WhenEnqueueAndQueueIsNotFull_ThenReturnsTrue) {
	const auto result {fixedSizeCircularArrayQueue.enqueue(50)};
	
	EXPECT_THAT(result, testing::IsTrue());
}

TEST_F(NonEmptyIntegerFixedSizeCircularArrayQueueTest, GivenInteger_WhenEnqueueAndQueueIsFull_ThenSizeIsNotIncremented) {
	fixedSizeCircularArrayQueue.enqueue(50);
	const auto size {fixedSizeCircularArrayQueue.getSize()};
	
	EXPECT_THAT(size, testing::Eq(5));
}

TEST_F(NonEmptyIntegerFixedSizeCircularArrayQueueTest, GivenInteger_WhenEnqueueAndQueueIsFull_ThenReturnsFalse) {
	fixedSizeCircularArrayQueue.enqueue(50);
	const auto result {fixedSizeCircularArrayQueue.enqueue(60)};
	
	EXPECT_THAT(result, testing::IsFalse());
}

TEST_F(NonEmptyIntegerFixedSizeCircularArrayQueueTest, WhenDequeue_ThenReturnsElementAtFrontOfQueue) {
	const auto result {fixedSizeCircularArrayQueue.dequeue()};
	
	EXPECT_THAT(result, testing::Optional(10));
}

TEST_F(NonEmptyIntegerFixedSizeCircularArrayQueueTest, WhenDequeue_ThenSizeIsDecremented) {
	fixedSizeCircularArrayQueue.dequeue();
	const auto size {fixedSizeCircularArrayQueue.getSize()};
	
	EXPECT_THAT(size, testing::Eq(3));
}

TEST_F(NonEmptyIntegerFixedSizeCircularArrayQueueTest, WhenDequeue_ThenNextElementIsAtFrontOfQueue) {
	fixedSizeCircularArrayQueue.dequeue();
	
	EXPECT_THAT(*fixedSizeCircularArrayQueue.getFront(), testing::Eq(20));
}

TEST_F(NonEmptyIntegerFixedSizeCircularArrayQueueTest, WhenDequeueAll_ThenReturnsElementsInExpectedOrder) {
	const auto result {fixedSizeCircularArrayQueue.dequeueAll()};
	
	EXPECT_THAT(result, testing::ElementsAre(10, 20, 30, 40));
}

TEST_F(NonEmptyIntegerFixedSizeCircularArrayQueueTest, WhenDequeueAll_ThenSizeIsZero) {
	fixedSizeCircularArrayQueue.dequeueAll();
	const auto size {fixedSizeCircularArrayQueue.getSize()};
	
	EXPECT_THAT(size, testing::Eq(0));
}

TEST_F(NonEmptyIntegerFixedSizeCircularArrayQueueTest, WhenIsEmpty_ThenReturnsFalse) {
	const auto result {fixedSizeCircularArrayQueue.isEmpty()};
	
	EXPECT_THAT(result, testing::IsFalse());
}

TEST_F(NonEmptyIntegerFixedSizeCircularArrayQueueTest, GivenNonFullIntegerFixedSizeCircularArrayQueue_WhenIsFull_ThenReturnsFalse) {
	const auto result {fixedSizeCircularArrayQueue.isFull()};
	
	EXPECT_THAT(result, testing::IsFalse());
}

TEST_F(NonEmptyIntegerFixedSizeCircularArrayQueueTest, GivenFullIntegerFixedSizeCircularArrayQueue_WhenIsFull_ThenReturnsTrue) {
	fixedSizeCircularArrayQueue.enqueue(50);
	const auto result {fixedSizeCircularArrayQueue.isFull()};
	
	EXPECT_THAT(result, testing::IsTrue());
}
}