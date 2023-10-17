#include <gmock/gmock.h>

#include "DataStructures/Queues/SinglyLinkedListQueue.hpp"

namespace Core::DataStructures::Queues::Test {
class EmptyIntegerSinglyLinkedListQueueTest : public testing::Test {
public:
	EmptyIntegerSinglyLinkedListQueueTest() noexcept = default;
	~EmptyIntegerSinglyLinkedListQueueTest() noexcept override = default;
	
protected:
	SinglyLinkedListQueue<int> singlyLinkedListQueue {};
};

TEST_F(EmptyIntegerSinglyLinkedListQueueTest, GivenInteger_WhenEnqueue_ThenElementsAreInExpectedOrder) {
	singlyLinkedListQueue.enqueue(10);
	
	EXPECT_THAT(singlyLinkedListQueue.getFront(), testing::Pointee(10));
	EXPECT_THAT(singlyLinkedListQueue.getBack(), testing::Pointee(10));
}

TEST_F(EmptyIntegerSinglyLinkedListQueueTest, GivenInteger_WhenEnqueue_ThenSizeIsIncremented) {
	singlyLinkedListQueue.enqueue(10);
	const auto size {singlyLinkedListQueue.getSize()};
	
	EXPECT_THAT(size, testing::Eq(1));
}

TEST_F(EmptyIntegerSinglyLinkedListQueueTest, WhenDequeue_ThenReturnsNullOptional) {
	const auto result {singlyLinkedListQueue.dequeue()};
	
	EXPECT_THAT(result, testing::Eq(std::nullopt));
}

TEST_F(EmptyIntegerSinglyLinkedListQueueTest, WhenDequeue_ThenSizeIsNotDecremented) {
	singlyLinkedListQueue.dequeue();
	const auto size {singlyLinkedListQueue.getSize()};
	
	EXPECT_THAT(size, testing::Eq(0));
}

TEST_F(EmptyIntegerSinglyLinkedListQueueTest, WhenDequeueAll_ThenReturnsEmptyVector) {
	const auto result {singlyLinkedListQueue.dequeueAll()};
	
	EXPECT_THAT(result, testing::IsEmpty());
}

TEST_F(EmptyIntegerSinglyLinkedListQueueTest, WhenDequeueAll_ThenSizeIsNotDecremented) {
	singlyLinkedListQueue.dequeueAll();
	const auto size {singlyLinkedListQueue.getSize()};
	
	EXPECT_THAT(size, testing::Eq(0));
}

TEST_F(EmptyIntegerSinglyLinkedListQueueTest, WhenIsEmpty_ThenReturnsTrue) {
	const auto result {singlyLinkedListQueue.isEmpty()};
	
	EXPECT_THAT(result, testing::IsTrue());
}
}