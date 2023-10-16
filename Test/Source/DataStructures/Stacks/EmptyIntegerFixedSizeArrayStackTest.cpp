#include <gmock/gmock.h>

#include "DataStructures/Stacks/FixedSizeArrayStack.hpp"

namespace Core::DataStructures::Stacks::Test {
class EmptyIntegerFixedSizeArrayStackTest : public testing::Test {
public:
	EmptyIntegerFixedSizeArrayStackTest() noexcept = default;
	~EmptyIntegerFixedSizeArrayStackTest() noexcept override = default;

protected:
	FixedSizeArrayStack<int, 5> fixedSizeArrayStack {};
};

TEST_F(EmptyIntegerFixedSizeArrayStackTest, GivenInteger_WhenPush_ThenElementsAreInExpectedOrder) {
	fixedSizeArrayStack.push(10);
	
	EXPECT_THAT(fixedSizeArrayStack.getTop(), testing::Pointee(10));
}

TEST_F(EmptyIntegerFixedSizeArrayStackTest, GivenInteger_WhenPush_ThenSizeIsIncremented) {
	fixedSizeArrayStack.push(10);
	const auto size {fixedSizeArrayStack.getSize()};
	
	EXPECT_THAT(size, testing::Eq(1));
}

TEST_F(EmptyIntegerFixedSizeArrayStackTest, WhenPop_ThenReturnsNullOptional) {
	const auto result {fixedSizeArrayStack.pop()};
	
	EXPECT_THAT(result, testing::Eq(std::nullopt));
}

TEST_F(EmptyIntegerFixedSizeArrayStackTest, WhenPop_ThenSizeIsNotDecremented) {
	fixedSizeArrayStack.pop();
	const auto size {fixedSizeArrayStack.getSize()};
	
	EXPECT_THAT(size, testing::Eq(0));
}

TEST_F(EmptyIntegerFixedSizeArrayStackTest, WhenPopAll_ThenReturnsEmptyVector) {
	const auto result {fixedSizeArrayStack.popAll()};
	
	EXPECT_THAT(result, testing::IsEmpty());
}

TEST_F(EmptyIntegerFixedSizeArrayStackTest, WhenPopAll_ThenSizeIsNotDecremented) {
	fixedSizeArrayStack.popAll();
	const auto size {fixedSizeArrayStack.getSize()};
	
	EXPECT_THAT(size, testing::Eq(0));
}

TEST_F(EmptyIntegerFixedSizeArrayStackTest, WhenIsEmpty_ThenReturnsTrue) {
	const auto result {fixedSizeArrayStack.isEmpty()};
	
	EXPECT_THAT(result, testing::IsTrue());
}

TEST_F(EmptyIntegerFixedSizeArrayStackTest, WhenIsFull_ThenReturnsFalse) {
	const auto result {fixedSizeArrayStack.isFull()};
	
	EXPECT_THAT(result, testing::IsFalse());
}
}