#include <gmock/gmock.h>

#include "DataStructures/Stacks/FixedSizeArrayStack.hpp"

namespace Core::DataStructures::Stacks::Test {
class NonEmptyIntegerFixedSizeArrayStackTest : public testing::Test {
public:
	NonEmptyIntegerFixedSizeArrayStackTest() noexcept;
	~NonEmptyIntegerFixedSizeArrayStackTest() noexcept override = default;

protected:
	FixedSizeArrayStack<int, 5> fixedSizeArrayStack {};
};

NonEmptyIntegerFixedSizeArrayStackTest::NonEmptyIntegerFixedSizeArrayStackTest() noexcept {
	for (auto element {10}; element < 50; element = element + 10) {
		fixedSizeArrayStack.push(element);
	}
}

TEST_F(NonEmptyIntegerFixedSizeArrayStackTest, GivenInteger_WhenPushAndStackIsNotFull_ThenElementsAreInExpectedOrder) {
	fixedSizeArrayStack.push(50);
	
	EXPECT_THAT(fixedSizeArrayStack.getTop(), testing::Pointee(50));
}

TEST_F(NonEmptyIntegerFixedSizeArrayStackTest, GivenInteger_WhenPushAndStackIsNotFull_ThenSizeIsIncremented) {
	fixedSizeArrayStack.push(50);
	const auto size {fixedSizeArrayStack.getSize()};
	
	EXPECT_THAT(size, testing::Eq(5));
}

TEST_F(NonEmptyIntegerFixedSizeArrayStackTest, GivenInteger_WhenPushAndStackIsFull_ThenReturnsFalse) {
	fixedSizeArrayStack.push(50);
	const auto result {fixedSizeArrayStack.push(60)};
	
	EXPECT_THAT(result, testing::IsFalse());
}

TEST_F(NonEmptyIntegerFixedSizeArrayStackTest, GivenInteger_WhenPushAndStackIsFull_ThenSizeIsNotIncremented) {
	fixedSizeArrayStack.push(50);
	fixedSizeArrayStack.push(60);
	const auto size {fixedSizeArrayStack.getSize()};
	
	EXPECT_THAT(size, testing::Eq(5));
}

TEST_F(NonEmptyIntegerFixedSizeArrayStackTest, WhenPop_ThenReturnsElementAtTopOfStack) {
	const auto result {fixedSizeArrayStack.pop()};
	
	EXPECT_THAT(result, testing::Eq(40));
}

TEST_F(NonEmptyIntegerFixedSizeArrayStackTest, WhenPop_ThenSizeIsDecremented) {
	fixedSizeArrayStack.pop();
	const auto size {fixedSizeArrayStack.getSize()};
	
	EXPECT_THAT(size, testing::Eq(3));
}

TEST_F(NonEmptyIntegerFixedSizeArrayStackTest, WhenPopAll_ThenReturnsElementsInExpectedOrder) {
	const auto result {fixedSizeArrayStack.popAll()};
	
	EXPECT_THAT(result, testing::ElementsAre(40, 30, 20, 10));
}

TEST_F(NonEmptyIntegerFixedSizeArrayStackTest, WhenPopAll_ThenSizeIsZero) {
	fixedSizeArrayStack.popAll();
	const auto size {fixedSizeArrayStack.getSize()};
	
	EXPECT_THAT(size, testing::Eq(0));
}

TEST_F(NonEmptyIntegerFixedSizeArrayStackTest, WhenIsEmpty_ThenReturnsFalse) {
	const auto result {fixedSizeArrayStack.isEmpty()};
	
	EXPECT_THAT(result, testing::IsFalse());
}

TEST_F(NonEmptyIntegerFixedSizeArrayStackTest, GivenNonFullIntegerFixedSizeArrayStack_WhenIsFull_ThenReturnsFalse) {
	const auto result {fixedSizeArrayStack.isFull()};
	
	EXPECT_THAT(result, testing::IsFalse());
}

TEST_F(NonEmptyIntegerFixedSizeArrayStackTest, GivenFullIntegerFixedSizeArrayStack_WhenIsFull_ThenReturnsTrue) {
	fixedSizeArrayStack.push(50);
	const auto result {fixedSizeArrayStack.isFull()};
	
	EXPECT_THAT(result, testing::IsTrue());
}
}