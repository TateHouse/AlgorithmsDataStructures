#include <gmock/gmock.h>

#include "DataStructures/Stacks/SinglyLinkedListStack.hpp"

namespace Core::DataStructures::Stacks::Test {
class NonEmptyIntegerSinglyLinkedListStackTest : public testing::Test {
public:
	NonEmptyIntegerSinglyLinkedListStackTest() noexcept;
	~NonEmptyIntegerSinglyLinkedListStackTest() noexcept override = default;

protected:
	SinglyLinkedListStack<int> singlyLinkedListStack {};
};

NonEmptyIntegerSinglyLinkedListStackTest::NonEmptyIntegerSinglyLinkedListStackTest() noexcept {
	for (auto element {10}; element < 50; element = element + 10) {
		singlyLinkedListStack.push(element);
	}
}

TEST_F(NonEmptyIntegerSinglyLinkedListStackTest, GivenInteger_WhenPush_ThenElementsAreInExpectedOrder) {
	singlyLinkedListStack.push(50);
	
	EXPECT_THAT(singlyLinkedListStack.getTop(), testing::Pointee(50));
}

TEST_F(NonEmptyIntegerSinglyLinkedListStackTest, GivenInteger_WhenPush_ThenSizeIsIncremented) {
	singlyLinkedListStack.push(50);
	const auto size {singlyLinkedListStack.getSize()};
	
	EXPECT_THAT(size, testing::Eq(5));
}

TEST_F(NonEmptyIntegerSinglyLinkedListStackTest, WhenPop_ThenReturnsElementAtTopOfStack) {
	const auto result {singlyLinkedListStack.pop()};
	
	EXPECT_THAT(result, testing::Eq(40));
}

TEST_F(NonEmptyIntegerSinglyLinkedListStackTest, WhenPop_ThenSizeIsDecremented) {
	singlyLinkedListStack.pop();
	const auto size {singlyLinkedListStack.getSize()};
	
	EXPECT_THAT(size, testing::Eq(3));
}

TEST_F(NonEmptyIntegerSinglyLinkedListStackTest, WhenPopAll_ThenReturnsElementsInExpectedOrder) {
	const auto result {singlyLinkedListStack.popAll()};
	
	EXPECT_THAT(result, testing::ElementsAre(40, 30, 20, 10));
}

TEST_F(NonEmptyIntegerSinglyLinkedListStackTest, WhenPopAll_ThenSizeIsZero) {
	singlyLinkedListStack.popAll();
	const auto size {singlyLinkedListStack.getSize()};
	
	EXPECT_THAT(size, testing::Eq(0));
}

TEST_F(NonEmptyIntegerSinglyLinkedListStackTest, WhenIsEmpty_ThenReturnsFalse) {
	const auto result {singlyLinkedListStack.isEmpty()};
	
	EXPECT_THAT(result, testing::IsFalse());
}
}