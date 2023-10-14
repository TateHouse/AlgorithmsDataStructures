#include <gmock/gmock.h>

#include "DataStructures/Stacks/DynamicSizeArrayStack.hpp"

namespace Core::DataStructures::Stacks::Test {
class NonEmptyIntegerDynamicSizeArrayStackTest : public testing::Test {
public:
	NonEmptyIntegerDynamicSizeArrayStackTest() noexcept;
	~NonEmptyIntegerDynamicSizeArrayStackTest() noexcept override = default;
	
protected:
	DynamicSizeArrayStack<int> dynamicSizeArrayStack {};
};

NonEmptyIntegerDynamicSizeArrayStackTest::NonEmptyIntegerDynamicSizeArrayStackTest() noexcept {
	for (auto element {10}; element < 50; element = element + 10) {
		dynamicSizeArrayStack.push(element);
	}
}

TEST_F(NonEmptyIntegerDynamicSizeArrayStackTest, GivenInteger_WhenPush_ThenElementsAreInExpectedOrder) {
	dynamicSizeArrayStack.push(50);
	
	EXPECT_THAT(dynamicSizeArrayStack.getTop(), testing::Pointee(50));
}

TEST_F(NonEmptyIntegerDynamicSizeArrayStackTest, GivenInteger_WhenPush_ThenSizeIsIncremented) {
	dynamicSizeArrayStack.push(50);
	const auto size {dynamicSizeArrayStack.getSize()};
	
	EXPECT_THAT(size, testing::Eq(5));
}

TEST_F(NonEmptyIntegerDynamicSizeArrayStackTest, WhenPop_ThenReturnsElementAtTopOfStack) {
	const auto result {dynamicSizeArrayStack.pop()};
	
	EXPECT_THAT(result, testing::Eq(40));
}

TEST_F(NonEmptyIntegerDynamicSizeArrayStackTest, WhenPop_ThenSizeIsDecremented) {
	dynamicSizeArrayStack.pop();
	const auto size {dynamicSizeArrayStack.getSize()};
	
	EXPECT_THAT(size, testing::Eq(3));
}

TEST_F(NonEmptyIntegerDynamicSizeArrayStackTest, WhenPopAll_ThenReturnsElementsInExpectedOrder) {
	const auto result {dynamicSizeArrayStack.popAll()};
	
	EXPECT_THAT(result, testing::ElementsAre(10, 20, 30, 40));
}

TEST_F(NonEmptyIntegerDynamicSizeArrayStackTest, WhenPopAll_ThenSizeIsZero) {
	dynamicSizeArrayStack.popAll();
	const auto size {dynamicSizeArrayStack.getSize()};
	
	EXPECT_THAT(size, testing::Eq(0));
}

TEST_F(NonEmptyIntegerDynamicSizeArrayStackTest, WhenIsEmpty_ThenReturnsFalse) {
	const auto result {dynamicSizeArrayStack.isEmpty()};
	
	EXPECT_THAT(result, testing::IsFalse());
}
}