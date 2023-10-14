#include <gmock/gmock.h>

#include "DataStructures/Stacks/DynamicSizeArrayStack.hpp"

namespace Core::DataStructures::Stacks::Test {
class EmptyIntegerDynamicSizeArrayStackTest : public testing::Test {
public:
	EmptyIntegerDynamicSizeArrayStackTest() noexcept = default;
	~EmptyIntegerDynamicSizeArrayStackTest() noexcept override = default;
	
protected:
	DynamicSizeArrayStack<int> dynamicSizeArrayStack {};
};

TEST_F(EmptyIntegerDynamicSizeArrayStackTest, GivenInteger_WhenPush_ThenElementsAreInExpectedOrder) {
	dynamicSizeArrayStack.push(10);
	
	EXPECT_THAT(dynamicSizeArrayStack.getTop(), testing::Pointee(10));
}

TEST_F(EmptyIntegerDynamicSizeArrayStackTest, GivenInteger_WhenPush_ThenSizeIsIncremented) {
	dynamicSizeArrayStack.push(10);
	const auto size {dynamicSizeArrayStack.getSize()};
	
	EXPECT_THAT(size, testing::Eq(1));
}

TEST_F(EmptyIntegerDynamicSizeArrayStackTest, WhenPop_ThenReturnsNullOptional) {
	const auto result {dynamicSizeArrayStack.pop()};
	
	EXPECT_THAT(result, testing::Eq(std::nullopt));
}

TEST_F(EmptyIntegerDynamicSizeArrayStackTest, WhenPop_ThenSizeIsNotDecremented) {
	dynamicSizeArrayStack.pop();
	const auto size {dynamicSizeArrayStack.getSize()};
	
	EXPECT_THAT(size, testing::Eq(0));
}

TEST_F(EmptyIntegerDynamicSizeArrayStackTest, WhenPopAll_ThenReturnsEmptyVector) {
	const auto result {dynamicSizeArrayStack.popAll()};
	
	EXPECT_THAT(result, testing::IsEmpty());
}

TEST_F(EmptyIntegerDynamicSizeArrayStackTest, WhenPopAll_ThenSizeIsNotDecremented) {
	dynamicSizeArrayStack.popAll();
	const auto size {dynamicSizeArrayStack.getSize()};
	
	EXPECT_THAT(size, testing::Eq(0));
}

TEST_F(EmptyIntegerDynamicSizeArrayStackTest, WhenIsEmpty_ThenReturnsTrue) {
	const auto result {dynamicSizeArrayStack.isEmpty()};
	
	EXPECT_THAT(result, testing::IsTrue());
}
}