#include <gmock/gmock.h>

#include "DataStructures/Trees/BinarySearchTree.hpp"

namespace Core::DataStructures::Trees::Test {
class EmptyIntegerBinarySearchTreeTest : public testing::Test {
public:
	EmptyIntegerBinarySearchTreeTest() noexcept = default;
	~EmptyIntegerBinarySearchTreeTest() noexcept override = default;

protected:
	BinarySearchTree<int> binarySearchTree {};
};

TEST_F(EmptyIntegerBinarySearchTreeTest, GivenTwoEmptyIntegerBinarySearchTrees_WhenCompare_ThenReturnsTrue) {
	BinarySearchTree<int> otherBinarySearchTree {};
	
	EXPECT_THAT(binarySearchTree, testing::Eq(otherBinarySearchTree));
}

TEST_F(EmptyIntegerBinarySearchTreeTest, GivenInteger_WhenInsert_ThenElementsAreInExpectedOrder) {
	binarySearchTree.insert(10);
	
	auto iterator {binarySearchTree.cbeginLevelOrder()};
	
	EXPECT_THAT(*iterator, testing::Eq(10));
}

TEST_F(EmptyIntegerBinarySearchTreeTest, GivenInteger_WhenInsert_ThenSizeIsIncremented) {
	binarySearchTree.insert(10);
	const auto size {binarySearchTree.getNodeCount()};
	
	EXPECT_THAT(size, testing::Eq(1));
}

TEST_F(EmptyIntegerBinarySearchTreeTest, GivenInteger_WhenRemoveFirst_ThenReturnsNullOptional) {
	const auto result {binarySearchTree.removeFirst(10)};
	
	EXPECT_THAT(result, testing::Eq(std::nullopt));
}

TEST_F(EmptyIntegerBinarySearchTreeTest, GivenInteger_WhenRemoveFirst_ThenSizeIsNotDecremented) {
	binarySearchTree.removeFirst(10);
	const auto size {binarySearchTree.getNodeCount()};
	
	EXPECT_THAT(size, testing::Eq(0));
}

TEST_F(EmptyIntegerBinarySearchTreeTest, WhenRemoveMinimum_ThenReturnsNullOptional) {
	const auto result {binarySearchTree.removeMinimum()};
	
	EXPECT_THAT(result, testing::Eq(std::nullopt));
}

TEST_F(EmptyIntegerBinarySearchTreeTest, WhenRemoveMaximum_ThenReturnsNullOptional) {
	const auto result {binarySearchTree.removeMaximum()};
	
	EXPECT_THAT(result, testing::Eq(std::nullopt));
}

TEST_F(EmptyIntegerBinarySearchTreeTest, WhenRemoveAll_ThenReturnsEmptyVector) {
	const auto result {binarySearchTree.removeAll()};
	
	EXPECT_THAT(result, testing::IsEmpty());
}

TEST_F(EmptyIntegerBinarySearchTreeTest, GivenInteger_WhenFindFirst_ThenReturnsNullOptional) {
	const auto result {binarySearchTree.findFirst(10)};
	
	EXPECT_THAT(result, testing::Eq(std::nullopt));
}

TEST_F(EmptyIntegerBinarySearchTreeTest, WhenFindMinimum_ThenReturnsNullOptional) {
	const auto result {binarySearchTree.findMinimum()};
	
	EXPECT_THAT(result, testing::Eq(std::nullopt));
}

TEST_F(EmptyIntegerBinarySearchTreeTest, WhenFindMaximum_ThenReturnsNullOptional) {
	const auto result {binarySearchTree.findMaximum()};
	
	EXPECT_THAT(result, testing::Eq(std::nullopt));
}

TEST_F(EmptyIntegerBinarySearchTreeTest, GivenInteger_WhenContains_ThenReturnsFalse) {
	const auto result {binarySearchTree.contains(10)};
	
	EXPECT_THAT(result, testing::IsFalse());
}

TEST_F(EmptyIntegerBinarySearchTreeTest, WhenIsEmpty_ThenReturnsTrue) {
	const auto result {binarySearchTree.isEmpty()};
	
	EXPECT_THAT(result, testing::IsTrue());
}

TEST_F(EmptyIntegerBinarySearchTreeTest, WhenGetHeight_ThenReturnsNegativeOne) {
	const auto result {binarySearchTree.getHeight()};
	
	EXPECT_THAT(result, testing::Eq(-1));
}
}