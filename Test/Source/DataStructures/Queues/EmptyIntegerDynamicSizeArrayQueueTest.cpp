#include <gmock/gmock.h>

#include "DataStructures/Queues/DynamicSizeArrayQueue.hpp"

namespace Core::DataStructures::Queues::Test {
class EmptyIntegerDynamicSizeArrayQueueTest : public testing::Test {
public:
	EmptyIntegerDynamicSizeArrayQueueTest() noexcept = default;
	~EmptyIntegerDynamicSizeArrayQueueTest() noexcept override = default;
	
protected:
	DynamicSizeArrayQueue<int> dynamicSizeArrayQueue {};
};

TEST_F(EmptyIntegerDynamicSizeArrayQueueTest, GivenInteger_WhenEnqueue_ThenElementsAreInExpectedOrder) {
	dynamicSizeArrayQueue.enqueue(10);
	
	EXPECT_THAT(dynamicSizeArrayQueue.getFront(), testing::Pointee(10));
}

TEST_F(EmptyIntegerDynamicSizeArrayQueueTest, GivenInteger_WhenEnqueue_ThenSizeIsIncremented) {
	dynamicSizeArrayQueue.enqueue(10);
	const auto size {dynamicSizeArrayQueue.getSize()};
	
	EXPECT_THAT(size, testing::Eq(1));
}

TEST_F(EmptyIntegerDynamicSizeArrayQueueTest, WhenDequeue_ThenReturnsNullOptional) {
	const auto result {dynamicSizeArrayQueue.dequeue()};
	
	EXPECT_THAT(result, testing::Eq(std::nullopt));
}

TEST_F(EmptyIntegerDynamicSizeArrayQueueTest, WhenDequeue_ThenSizeIsNotDecremented) {
	dynamicSizeArrayQueue.dequeue();
	const auto size {dynamicSizeArrayQueue.getSize()};
	
	EXPECT_THAT(size, testing::Eq(0));
}

TEST_F(EmptyIntegerDynamicSizeArrayQueueTest, WhenDequeueAll_ThenReturnsEmptyVector) {
	const auto result {dynamicSizeArrayQueue.dequeueAll()};
	
	EXPECT_THAT(result, testing::IsEmpty());
}

TEST_F(EmptyIntegerDynamicSizeArrayQueueTest, WhenDequeueAll_ThenSizeIsNotDecremented) {
	dynamicSizeArrayQueue.dequeueAll();
	const auto size {dynamicSizeArrayQueue.getSize()};
	
	EXPECT_THAT(size, testing::Eq(0));
}

TEST_F(EmptyIntegerDynamicSizeArrayQueueTest, WhenIsEmpty_ThenReturnsTrue) {
	const auto result {dynamicSizeArrayQueue.isEmpty()};
	
	EXPECT_THAT(result, testing::IsTrue());
}
}