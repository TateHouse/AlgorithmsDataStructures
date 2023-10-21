#include <gmock/gmock.h>

#include "DataStructures/Trees/BinaryTree.hpp"
#include "IntegerPredicates.hpp"

namespace Core::DataStructures::Trees::Test {
class EmptyIntegerBinaryTreeTest : public testing::Test {
public:
	EmptyIntegerBinaryTreeTest() noexcept = default;
	~EmptyIntegerBinaryTreeTest() noexcept override = default;

protected:
	BinaryTree<int> binaryTree {};
};

TEST_F(EmptyIntegerBinaryTreeTest, GivenTwoEmptyIntegerBinaryTrees_WhenCompare_ThenReturnsTrue) {
	BinaryTree<int> otherBinaryTree {};
	
	EXPECT_THAT(binaryTree, testing::Eq(otherBinaryTree));
}

TEST_F(EmptyIntegerBinaryTreeTest, GivenInteger_WhenInsert_ThenElementsAreInExpectedOrder) {
	binaryTree.insert(10);
	
	auto iterator {binaryTree.cbeginLevelOrder()};
	
	EXPECT_THAT(*iterator, testing::Eq(10));
}

TEST_F(EmptyIntegerBinaryTreeTest, GivenInteger_WhenInsert_ThenSizeIsIncremented) {
	binaryTree.insert(10);
	const auto size {binaryTree.getNodeCount()};
	
	EXPECT_THAT(size, testing::Eq(1));
}

TEST_F(EmptyIntegerBinaryTreeTest, GivenPredicate_WhenRemoveFirst_ThenReturnsNullOptional) {
	const auto result {binaryTree.removeFirst(::Test::isTen)};
	
	EXPECT_THAT(result, testing::Eq(std::nullopt));
}

TEST_F(EmptyIntegerBinaryTreeTest, GivenPredicate_WhenRemoveFirst_ThenSizeIsNotDecremented) {
	binaryTree.removeFirst(::Test::isTen);
	const auto size {binaryTree.getNodeCount()};
	
	EXPECT_THAT(size, testing::Eq(0));
}

TEST_F(EmptyIntegerBinaryTreeTest, GivenNode_WhenRemoveAll_ThenReturnsEmptyVector) {
	const auto result {binaryTree.removeAll()};
	
	EXPECT_THAT(result, testing::IsEmpty());
}

TEST_F(EmptyIntegerBinaryTreeTest, GivenPredicate_WhenFindFirstConst_ThenReturnsNullOptional) {
	const auto result {binaryTree.findFirst(binaryTree.cbeginLevelOrder(), binaryTree.cendLevelOrder(), ::Test::isTen)};
	
	EXPECT_THAT(result, testing::Eq(binaryTree.cendLevelOrder()));
}

TEST_F(EmptyIntegerBinaryTreeTest, GivenPredicate_WhenFindFirst_ThenReturnsNullOptional) {
	const auto result {binaryTree.findFirst(binaryTree.beginLevelOrder(), binaryTree.endLevelOrder(), ::Test::isTen)};
	
	EXPECT_THAT(result, testing::Eq(binaryTree.endLevelOrder()));
}

TEST_F(EmptyIntegerBinaryTreeTest, GivenPredicate_WhenContains_ThenReturnsFalse) {
	const auto result {binaryTree.contains(::Test::isTen)};
	
	EXPECT_THAT(result, testing::IsFalse());
}

TEST_F(EmptyIntegerBinaryTreeTest, WhenIsEmpty_ThenReturnsTrue) {
	const auto result {binaryTree.isEmpty()};
	
	EXPECT_THAT(result, testing::IsTrue());
}

TEST_F(EmptyIntegerBinaryTreeTest, WhenGetHeight_ThenReturnsNegativeOne) {
	const auto height {binaryTree.getHeight()};
	
	EXPECT_THAT(height, testing::Eq(-1));
}
}