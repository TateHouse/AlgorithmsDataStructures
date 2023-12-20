#include <gmock/gmock.h>

#include <vector>

#include "DataStructures/Trees/AVLTree.hpp"

namespace Core::DataStructures::Trees::Test {
class EmptyIntegerAVLTreeTest : public testing::Test {
public:
	EmptyIntegerAVLTreeTest() noexcept = default;
	~EmptyIntegerAVLTreeTest() noexcept override = default;

protected:
	AVLTree<int> avlTree {};
};

TEST_F(EmptyIntegerAVLTreeTest, GivenTwoEmptyIntegerAVLTrees_WhenCompare_ThenReturnsTrue) {
	AVLTree<int> otherAVLTree {};
	
	EXPECT_THAT(avlTree, testing::Eq(otherAVLTree));
}

TEST_F(EmptyIntegerAVLTreeTest, GivenInteger_WhenInsert_ThenElementsAreInExpectedOrder) {
	avlTree.insert(10);
	
	auto iterator {avlTree.cbeginLevelOrder()};
	
	EXPECT_THAT(*iterator, testing::Eq(10));
}

TEST_F(EmptyIntegerAVLTreeTest, GivenInteger_WhenInsert_ThenSizeIsIncremented) {
	avlTree.insert(10);
	const auto size {avlTree.getNodeCount()};
	
	EXPECT_THAT(size, testing::Eq(1));
}

TEST_F(EmptyIntegerAVLTreeTest, GivenInteger_WhenInsertAndRightRotationIsPerformed_ThenElementsAreInExpectedOrder) {
	avlTree.insert(10);
	avlTree.insert(20);
	avlTree.insert(30);
	
	std::vector<int> elements {};
	for (auto iterator {avlTree.cbeginLevelOrder()}; iterator != avlTree.cendLevelOrder(); ++iterator) {
		elements.push_back(*iterator);
	}
	
	EXPECT_THAT(elements, testing::ElementsAre(20, 10, 30));
}

TEST_F(EmptyIntegerAVLTreeTest, GivenInteger_WhenInsertAndLeftRotationIsPerformed_ThenElementsAreInExpectedOrder) {
	avlTree.insert(30);
	avlTree.insert(20);
	avlTree.insert(10);
	
	std::vector<int> elements {};
	for (auto iterator {avlTree.cbeginLevelOrder()}; iterator != avlTree.cendLevelOrder(); ++iterator) {
		elements.push_back(*iterator);
	}
	
	EXPECT_THAT(elements, testing::ElementsAre(20, 10, 30));
}

TEST_F(EmptyIntegerAVLTreeTest,
       GivenInteger_WhenInsertAndLeftAndRightRotationsArePerformed_ThenElementsAreInExpectedOrder) {
	avlTree.insert(30);
	avlTree.insert(10);
	avlTree.insert(20);
	
	std::vector<int> elements {};
	for (auto iterator {avlTree.cbeginLevelOrder()}; iterator != avlTree.cendLevelOrder(); ++iterator) {
		elements.push_back(*iterator);
	}
	
	EXPECT_THAT(elements, testing::ElementsAre(20, 10, 30));
}

TEST_F(EmptyIntegerAVLTreeTest,
       GivenInteger_WhenInsertAndRightAndLeftRotationsArePerformed_ThenElementsAreInExpectedOrder) {
	avlTree.insert(10);
	avlTree.insert(30);
	avlTree.insert(20);
	
	std::vector<int> elements {};
	for (auto iterator {avlTree.cbeginLevelOrder()}; iterator != avlTree.cendLevelOrder(); ++iterator) {
		elements.push_back(*iterator);
	}
	
	EXPECT_THAT(elements, testing::ElementsAre(20, 10, 30));
}

TEST_F(EmptyIntegerAVLTreeTest, GivenInteger_WhenRemoveFirst_ThenReturnsNullOptional) {
	const auto result {avlTree.removeFirst(10)};
	
	EXPECT_THAT(result, testing::Eq(std::nullopt));
}

TEST_F(EmptyIntegerAVLTreeTest, GivenInteger_WhenRemoveFirst_ThenSizeIsNotDecremented) {
	avlTree.removeFirst(10);
	const auto size {avlTree.getNodeCount()};
	
	EXPECT_THAT(size, testing::Eq(0));
}

TEST_F(EmptyIntegerAVLTreeTest, WhenRemoveMinimum_ThenReturnsNullOptional) {
	const auto result {avlTree.removeMinimum()};
	
	EXPECT_THAT(result, testing::Eq(std::nullopt));
}

TEST_F(EmptyIntegerAVLTreeTest, WhenRemoveMinimum_ThenSizeIsNotDecremented) {
	avlTree.removeMinimum();
	const auto size {avlTree.getNodeCount()};
	
	EXPECT_THAT(size, testing::Eq(0));
}

TEST_F(EmptyIntegerAVLTreeTest, WhenRemoveMaximum_ThenReturnsNullOptional) {
	const auto result {avlTree.removeMaximum()};
	
	EXPECT_THAT(result, testing::Eq(std::nullopt));
}

TEST_F(EmptyIntegerAVLTreeTest, WhenRemoveMaximum_ThenSizeIsNotDecremented) {
	avlTree.removeMaximum();
	const auto size {avlTree.getNodeCount()};
	
	EXPECT_THAT(size, testing::Eq(0));
}

TEST_F(EmptyIntegerAVLTreeTest, GivenInteger_WhenRemoveAll_ThenReturnsEmptyVector) {
	const auto result {avlTree.removeAll()};
	
	EXPECT_THAT(result, testing::IsEmpty());
}

TEST_F(EmptyIntegerAVLTreeTest, GivenInteger_WhenFindFirst_ThenReturnsNullOptional) {
	const auto result {avlTree.findFirst(10)};
	
	EXPECT_THAT(result, testing::Eq(std::nullopt));
}

TEST_F(EmptyIntegerAVLTreeTest, WhenFindMinimum_ThenReturnsNullOptional) {
	const auto result {avlTree.findMinimum()};
	
	EXPECT_THAT(result, testing::Eq(std::nullopt));
}

TEST_F(EmptyIntegerAVLTreeTest, WhenFindMaximum_ThenReturnsNullOptional) {
	const auto result {avlTree.findMaximum()};
	
	EXPECT_THAT(result, testing::Eq(std::nullopt));
}

TEST_F(EmptyIntegerAVLTreeTest, GivenInteger_WhenContains_ThenReturnsFalse) {
	const auto result {avlTree.contains(10)};
	
	EXPECT_THAT(result, testing::IsFalse());
}

TEST_F(EmptyIntegerAVLTreeTest, WhenIsEmpty_ThenReturnsTrue) {
	const auto result {avlTree.isEmpty()};
	
	EXPECT_THAT(result, testing::IsTrue());
}

TEST_F(EmptyIntegerAVLTreeTest, WhenGetHeight_ThenReturnsNegativeOne) {
	const auto result {avlTree.getHeight()};
	
	EXPECT_THAT(result, testing::Eq(-1));
}
}