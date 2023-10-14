#include <gmock/gmock.h>

#include "DataStructures/Stacks/SinglyLinkedListStack.hpp"

namespace Core::DataStructures::Stacks::Test {
class EmptyIntegerSinglyLinkedListStackTest : public testing::Test {
public:
	EmptyIntegerSinglyLinkedListStackTest() noexcept = default;
	~EmptyIntegerSinglyLinkedListStackTest() noexcept override = default;
	
protected:
	SinglyLinkedListStack<int> singlyLinkedListStack {};
};

TEST_F(EmptyIntegerSinglyLinkedListStackTest, GivenInteger_WhenPush_ThenElementsAreInExpectedOrder) {
	singlyLinkedListStack.push(10);
	
	EXPECT_THAT(singlyLinkedListStack.getTop(), testing::Pointee(10));
}

TEST_F(EmptyIntegerSinglyLinkedListStackTest, GivenInteger_WhenPush_ThenSizeIsIncremented) {
	singlyLinkedListStack.push(10);
	const auto size {singlyLinkedListStack.getSize()};
	
	EXPECT_THAT(size, testing::Eq(1));
}

TEST_F(EmptyIntegerSinglyLinkedListStackTest, WhenPop_ThenReturnsNullOptional) {
	const auto result {singlyLinkedListStack.pop()};
	
	EXPECT_THAT(result, testing::Eq(std::nullopt));
}

TEST_F(EmptyIntegerSinglyLinkedListStackTest, WhenPop_ThenSizeIsNotDecremented) {
	singlyLinkedListStack.pop();
	const auto size {singlyLinkedListStack.getSize()};
	
	EXPECT_THAT(size, testing::Eq(0));
}

TEST_F(EmptyIntegerSinglyLinkedListStackTest, WhenPopAll_ThenReturnsEmptyVector) {
	const auto result {singlyLinkedListStack.popAll()};
	
	EXPECT_THAT(result, testing::IsEmpty());
}

TEST_F(EmptyIntegerSinglyLinkedListStackTest, WhenPopAll_ThenSizeIsNotDecremented) {
	singlyLinkedListStack.popAll();
	const auto size {singlyLinkedListStack.getSize()};
	
	EXPECT_THAT(size, testing::Eq(0));
}

TEST_F(EmptyIntegerSinglyLinkedListStackTest, WhenIsEmpty_ThenReturnsTrue) {
	const auto result {singlyLinkedListStack.isEmpty()};
	
	EXPECT_THAT(result, testing::IsTrue());
}
}