#include <gmock/gmock.h>

#include "DataStructures/Queues/DynamicSizeArrayQueue.hpp"

namespace Core::DataStructures::Queues::Test {
class NonEmptyIntegerDynamicSizeArrayQueue : public testing::Test {
public:
	NonEmptyIntegerDynamicSizeArrayQueue() noexcept;
	~NonEmptyIntegerDynamicSizeArrayQueue() noexcept override = default;
	
protected:
	DynamicSizeArrayQueue<int> dynamicSizeArrayQueue {};
};

NonEmptyIntegerDynamicSizeArrayQueue::NonEmptyIntegerDynamicSizeArrayQueue() noexcept {
	for (auto element {10}; element < 50; element = element + 10) {
		dynamicSizeArrayQueue.enqueue(element);
	}
}

TEST_F(NonEmptyIntegerDynamicSizeArrayQueue, GivenInteger_WhenEnqueue_ThenElementsAreInExpectedOrder) {
	dynamicSizeArrayQueue.enqueue(50);
	
	EXPECT_THAT(*dynamicSizeArrayQueue.getFront(), testing::Eq(10));
	EXPECT_THAT(*dynamicSizeArrayQueue.getBack(), testing::Eq(50));
}

TEST_F(NonEmptyIntegerDynamicSizeArrayQueue, GivenInteger_WhenEnqueue_ThenSizeIsIncremented) {
	dynamicSizeArrayQueue.enqueue(50);
	const auto size {dynamicSizeArrayQueue.getSize()};
	
	EXPECT_THAT(size, testing::Eq(5));
}

TEST_F(NonEmptyIntegerDynamicSizeArrayQueue, WhenDequeue_ThenReturnsElementAtFrontOfQueue) {
	const auto result {dynamicSizeArrayQueue.dequeue()};
	
	EXPECT_THAT(result, testing::Optional(10));
}

TEST_F(NonEmptyIntegerDynamicSizeArrayQueue, WhenDequeue_ThenSizeIsDecremented) {
	dynamicSizeArrayQueue.dequeue();
	const auto size {dynamicSizeArrayQueue.getSize()};
	
	EXPECT_THAT(size, testing::Eq(3));
}

TEST_F(NonEmptyIntegerDynamicSizeArrayQueue, WhenDequeue_ThenNextElementIsAtFrontOfQueue) {
	dynamicSizeArrayQueue.dequeue();
	const auto result {dynamicSizeArrayQueue.dequeue()};
	
	EXPECT_THAT(result, testing::Optional(20));
}

TEST_F(NonEmptyIntegerDynamicSizeArrayQueue, WhenDequeueAll_ThenReturnsElementsInExpectedOrder) {
	const auto result {dynamicSizeArrayQueue.dequeueAll()};
	
	EXPECT_THAT(result, testing::ElementsAre(10, 20, 30, 40));
}

TEST_F(NonEmptyIntegerDynamicSizeArrayQueue, WhenDequeueAll_ThenSizeIsZero) {
	dynamicSizeArrayQueue.dequeueAll();
	const auto size {dynamicSizeArrayQueue.getSize()};
	
	EXPECT_THAT(size, testing::Eq(0));
}

TEST_F(NonEmptyIntegerDynamicSizeArrayQueue, WhenIsEmpty_ThenReturnsFalse) {
	const auto result {dynamicSizeArrayQueue.isEmpty()};
	
	EXPECT_THAT(result, testing::IsFalse());
}
}