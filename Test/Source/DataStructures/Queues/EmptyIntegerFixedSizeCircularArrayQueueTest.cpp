#include <gmock/gmock.h>

#include "DataStructures/Queues/FixedSizeCircularArrayQueue.hpp"

namespace Core::DataStructures::Queues::Test {
class EmptyIntegerFixedSizeCircularArrayQueueTest : public testing::Test {
public:
	EmptyIntegerFixedSizeCircularArrayQueueTest() noexcept = default;
	~EmptyIntegerFixedSizeCircularArrayQueueTest() noexcept override = default;

protected:
	FixedSizeCircularArrayQueue<int, 5> fixedSizeCircularArrayQueue {};
};

TEST_F(EmptyIntegerFixedSizeCircularArrayQueueTest, GivenInteger_WhenEnqueue_ThenElementsAreInExpectedOrder) {
	fixedSizeCircularArrayQueue.enqueue(10);
	
	EXPECT_THAT(*fixedSizeCircularArrayQueue.getFront(), testing::Eq(10));
	EXPECT_THAT(*fixedSizeCircularArrayQueue.getBack(), testing::Eq(10));
}

TEST_F(EmptyIntegerFixedSizeCircularArrayQueueTest, GivenInteger_WhenEnqueue_ThenSizeIsIncremented) {
	fixedSizeCircularArrayQueue.enqueue(10);
	const auto size {fixedSizeCircularArrayQueue.getSize()};
	
	EXPECT_THAT(size, testing::Eq(1));
}

TEST_F(EmptyIntegerFixedSizeCircularArrayQueueTest, WhenDequeue_ThenReturnsNullOptional) {
	const auto result {fixedSizeCircularArrayQueue.dequeue()};
	
	EXPECT_THAT(result, testing::Eq(std::nullopt));
}

TEST_F(EmptyIntegerFixedSizeCircularArrayQueueTest, WhenDequeue_ThenSizeIsNotDecremented) {
	fixedSizeCircularArrayQueue.dequeue();
	const auto size {fixedSizeCircularArrayQueue.getSize()};
	
	EXPECT_THAT(size, testing::Eq(0));
}

TEST_F(EmptyIntegerFixedSizeCircularArrayQueueTest, WhenDequeueAll_ThenReturnsEmptyVector) {
	const auto result {fixedSizeCircularArrayQueue.dequeueAll()};
	
	EXPECT_THAT(result, testing::IsEmpty());
}

TEST_F(EmptyIntegerFixedSizeCircularArrayQueueTest, WhenDequeueAll_ThenSizeIsNotDecremented) {
	fixedSizeCircularArrayQueue.dequeueAll();
	const auto size {fixedSizeCircularArrayQueue.getSize()};
	
	EXPECT_THAT(size, testing::Eq(0));
}

TEST_F(EmptyIntegerFixedSizeCircularArrayQueueTest, WhenIsEmpty_ThenReturnsTrue) {
	const auto result {fixedSizeCircularArrayQueue.isEmpty()};
	
	EXPECT_THAT(result, testing::IsTrue());
}

TEST_F(EmptyIntegerFixedSizeCircularArrayQueueTest, WhenIsFull_ThenReturnsFalse) {
	const auto result {fixedSizeCircularArrayQueue.isFull()};
	
	EXPECT_THAT(result, testing::IsFalse());
}
}