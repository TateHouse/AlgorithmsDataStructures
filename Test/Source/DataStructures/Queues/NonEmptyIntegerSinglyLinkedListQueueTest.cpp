#include <gmock/gmock.h>

#include "DataStructures/Queues/SinglyLinkedListQueue.hpp"

namespace Core::DataStructures::Queues::Test {
class NonEmptyIntegerSinglyLinkedListQueueTest : public testing::Test {
public:
	NonEmptyIntegerSinglyLinkedListQueueTest();
	~NonEmptyIntegerSinglyLinkedListQueueTest() noexcept override = default;

protected:
	SinglyLinkedListQueue<int> singlyLinkedListQueue {};
};

NonEmptyIntegerSinglyLinkedListQueueTest::NonEmptyIntegerSinglyLinkedListQueueTest() {
	for (auto element {10}; element < 50; element = element + 10) {
		singlyLinkedListQueue.enqueue(element);
	}
}

TEST_F(NonEmptyIntegerSinglyLinkedListQueueTest, GivenInteger_WhenEnqueue_ThenElementsAreInExpectedOrder) {
	singlyLinkedListQueue.enqueue(50);
	
	EXPECT_THAT(*singlyLinkedListQueue.getFront(), testing::Eq(10));
	EXPECT_THAT(*singlyLinkedListQueue.getBack(), testing::Eq(50));
}

TEST_F(NonEmptyIntegerSinglyLinkedListQueueTest, GivenInteger_WhenEnqueue_ThenSizeIsIncremented) {
	singlyLinkedListQueue.enqueue(50);
	const auto size {singlyLinkedListQueue.getSize()};
	
	EXPECT_THAT(size, testing::Eq(5));
}

TEST_F(NonEmptyIntegerSinglyLinkedListQueueTest, WhenDequeue_ThenReturnsElementAtFrontOfQueue) {
	const auto result {singlyLinkedListQueue.dequeue()};
	
	EXPECT_THAT(result, testing::Optional(10));
}

TEST_F(NonEmptyIntegerSinglyLinkedListQueueTest, WhenDequeue_ThenSizeIsDecremented) {
	singlyLinkedListQueue.dequeue();
	const auto size {singlyLinkedListQueue.getSize()};
	
	EXPECT_THAT(size, testing::Eq(3));
}

TEST_F(NonEmptyIntegerSinglyLinkedListQueueTest, WhenDequeue_ThenNextElementIsAtFrontOfQueue) {
	singlyLinkedListQueue.dequeue();
	const auto result {singlyLinkedListQueue.dequeue()};
	
	EXPECT_THAT(result, testing::Optional(20));
}

TEST_F(NonEmptyIntegerSinglyLinkedListQueueTest, WhenDequeueAll_ThenReturnsElementsInExpectedOrder) {
	const auto result {singlyLinkedListQueue.dequeueAll()};
	
	EXPECT_THAT(result, testing::ElementsAre(10, 20, 30, 40));
}

TEST_F(NonEmptyIntegerSinglyLinkedListQueueTest, WhenDequeueAll_ThenSizeIsZero) {
	singlyLinkedListQueue.dequeueAll();
	const auto size {singlyLinkedListQueue.getSize()};
	
	EXPECT_THAT(size, testing::Eq(0));
}

TEST_F(NonEmptyIntegerSinglyLinkedListQueueTest, WhenIsEmpty_ThenReturnsFalse) {
	const auto result {singlyLinkedListQueue.isEmpty()};
	
	EXPECT_THAT(result, testing::IsFalse());
}
}