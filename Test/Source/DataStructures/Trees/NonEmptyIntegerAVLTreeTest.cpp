#include <gmock/gmock.h>

#include <array>

#include "DataStructures/Trees/AVLTree.hpp"

namespace Core::DataStructures::Trees::Test {
class NonEmptyIntegerAVLTreeTest : public testing::Test {
public:
	NonEmptyIntegerAVLTreeTest();
	~NonEmptyIntegerAVLTreeTest() noexcept override = default;

protected:
	AVLTree<int> avlTree {};
};

NonEmptyIntegerAVLTreeTest::NonEmptyIntegerAVLTreeTest() {
	const auto elements {std::array<int, 9> {0, 10, -20, 40, 30, -10, -50, -5, 50}};
	for (const auto& element : elements) {
		avlTree.insert(element);
	}
}

TEST_F(NonEmptyIntegerAVLTreeTest, GivenInteger_WhenInsertAndRightRotationPerformed_ThenElementsAreInExpectedOrder) {
	avlTree.insert(-60);
	avlTree.insert(-70);
	
	std::vector<int> elements {};
	for (auto iterator {avlTree.cbeginLevelOrder()}; iterator != avlTree.cendLevelOrder(); ++iterator) {
		elements.push_back(*iterator);
	}
	
	EXPECT_THAT(elements, testing::ElementsAre(0, -20, 30, -60, -10, 10, 40, -70, -50, -5, 50));
}

TEST_F(NonEmptyIntegerAVLTreeTest, GivenInteger_WhenInsertAndLeftRotationPerformed_ThenElementsAreInExpectedOrder) {
	avlTree.insert(60);
	
	std::vector<int> elements {};
	for (auto iterator {avlTree.cbeginLevelOrder()}; iterator != avlTree.cendLevelOrder(); ++iterator) {
		elements.push_back(*iterator);
	}
	
	EXPECT_THAT(elements, testing::ElementsAre(0, -20, 30, -50, -10, 10, 50, -5, 40, 60));
}

TEST_F(NonEmptyIntegerAVLTreeTest,
       GivenInteger_WhenInsertAndLeftAndRightRotationsArePerformed_ThenElementsAreInExpectedOrder) {
	avlTree.insert(-70);
	avlTree.insert(-60);
	
	std::vector<int> elements {};
	for (auto iterator {avlTree.cbeginLevelOrder()}; iterator != avlTree.cendLevelOrder(); ++iterator) {
		elements.push_back(*iterator);
	}
	
	EXPECT_THAT(elements, testing::ElementsAre(0, -20, 30, -60, -10, 10, 40, -70, -50, -5, 50));
}

TEST_F(NonEmptyIntegerAVLTreeTest,
       GivenInteger_WhenInsertAndRightAndLeftRotationsArePerformed_ThenElementsAreInExpectedOrder) {
	avlTree.insert(-7);
	
	std::vector<int> elements {};
	for (auto iterator {avlTree.cbeginLevelOrder()}; iterator != avlTree.cendLevelOrder(); ++iterator) {
		elements.push_back(*iterator);
	}
	
	EXPECT_THAT(elements, testing::ElementsAre(0, -20, 30, -50, -7, 10, 40, -10, -5, 50));
}

TEST_F(NonEmptyIntegerAVLTreeTest, GivenInteger_WhenRemoveFirst_ThenReturnsElement) {
	const auto result {avlTree.removeFirst(50)};
	
	EXPECT_THAT(result, testing::Optional(50));
}

TEST_F(NonEmptyIntegerAVLTreeTest,
       GivenInteger_WhenRemoveFirstAndLeftRotationPerformed_ThenElementsAreInExpectedOrder) {
	const auto result {avlTree.removeFirst(-20)};
	
	ASSERT_THAT(result, testing::Optional(-20));
	
	std::vector<int> elements {};
	for (auto iterator {avlTree.cbeginLevelOrder()}; iterator != avlTree.cendLevelOrder(); ++iterator) {
		elements.push_back(*iterator);
	}
	
	EXPECT_THAT(elements, testing::ElementsAre(0, -10, 30, -50, -5, 10, 40, 50));
}

TEST_F(NonEmptyIntegerAVLTreeTest, WhenRemoveFirstAndRightRotationIsPerformed_ThenElementsAreInExpectedOrder) {
	const auto result {avlTree.removeFirst(10)};
	
	ASSERT_THAT(result, testing::Optional(10));
	
	std::vector<int> elements {};
	for (auto iterator {avlTree.cbeginLevelOrder()}; iterator != avlTree.cendLevelOrder(); ++iterator) {
		elements.push_back(*iterator);
	}
	
	EXPECT_THAT(elements, testing::ElementsAre(0, -20, 40, -50, -10, 30, 50, -5));
}

TEST_F(NonEmptyIntegerAVLTreeTest, WhenRemoveFirstAndLeftAndRightRotationsArePerformed_ThenElementsAreInExpectedOrder) {
	avlTree.removeFirst(-50);
	avlTree.removeFirst(50);
	avlTree.removeFirst(10);
	avlTree.removeFirst(40);
	avlTree.removeFirst(-20);
	
	const auto result {avlTree.removeFirst(30)};
	
	ASSERT_THAT(result, testing::Optional(30));
	
	std::vector<int> elements {};
	for (auto iterator {avlTree.cbeginLevelOrder()}; iterator != avlTree.cendLevelOrder(); ++iterator) {
		elements.push_back(*iterator);
	}
	
	EXPECT_THAT(elements, testing::ElementsAre(-5, -10, 0));
}

TEST_F(NonEmptyIntegerAVLTreeTest, WhenRemoveFirstAndRigthAndLeftRotationsArePerformed_ThenElementsAreInExpectedOrder) {
	avlTree.removeFirst(-50);
	avlTree.removeFirst(50);
	avlTree.removeFirst(40);
	avlTree.removeFirst(-5);
	avlTree.removeFirst(-20);
	
	const auto result {avlTree.removeFirst(-10)};
	
	ASSERT_THAT(result, testing::Optional(-10));
	
	std::vector<int> elements {};
	for (auto iterator {avlTree.cbeginLevelOrder()}; iterator != avlTree.cendLevelOrder(); ++iterator) {
		elements.push_back(*iterator);
	}
	
	EXPECT_THAT(elements, testing::ElementsAre(10, 0, 30));
}

TEST_F(NonEmptyIntegerAVLTreeTest, WhenRemoveMinimum_ThenReturnsElement) {
	const auto result {avlTree.removeMinimum()};
	
	EXPECT_THAT(result, testing::Optional(-50));
}

TEST_F(NonEmptyIntegerAVLTreeTest, WhenRemoveMaximum_ThenReturnsElement) {
	const auto result {avlTree.removeMaximum()};
	
	EXPECT_THAT(result, testing::Optional(50));
}

TEST_F(NonEmptyIntegerAVLTreeTest, WhenRemoveAll_ThenReturnsElementsInPostOrder) {
	const auto result {avlTree.removeAll()};
	
	EXPECT_THAT(result, testing::ElementsAre(-50, -5, -10, -20, 10, 50, 40, 30, 0));
}

TEST_F(NonEmptyIntegerAVLTreeTest, GivenIntegerMatchingAtLeastOneElement_WhenFindFirst_ThenReturnsElement) {
	const auto result {avlTree.findFirst(50)};
	
	EXPECT_THAT(result, testing::Optional(50));
}

TEST_F(NonEmptyIntegerAVLTreeTest, GivenIntegerMatchingNoElements_WhenFindFirst_ThenReturnsNullOptional) {
	const auto result {avlTree.findFirst(100)};
	
	EXPECT_THAT(result, testing::Eq(std::nullopt));
}

TEST_F(NonEmptyIntegerAVLTreeTest, WhenFindMinimum_ThenReturnsElement) {
	const auto result {avlTree.findMinimum()};
	
	EXPECT_THAT(result, testing::Optional(-50));
}

TEST_F(NonEmptyIntegerAVLTreeTest, WhenFindMaximum_ThenReturnsElement) {
	const auto result {avlTree.findMaximum()};
	
	EXPECT_THAT(result, testing::Optional(50));
}

TEST_F(NonEmptyIntegerAVLTreeTest,
       GivenConstFunctionToApplyToEachElement_WhenConstTraverse_ThenFunctionIsAppliedToEachElement) {
	std::vector<int> elements {};
	const auto pushBack {[&elements](const int& element) {
		elements.push_back(element);
	}};
	
	const auto& constBinarySearchTree {avlTree};
	constBinarySearchTree.traverse(constBinarySearchTree.cbeginInOrder(),
	                               constBinarySearchTree.cendInOrder(),
	                               pushBack);
	
	EXPECT_THAT(elements, testing::ElementsAre(-50, -20, -10, -5, 0, 10, 30, 40, 50));
}

TEST_F(NonEmptyIntegerAVLTreeTest, GivenFunctionToApplyToEachElement_WhenTraverse_ThenFunctionIsAppliedToEachElement) {
	const auto doubleElement {[](int& element) {
		element = element * 2;
	}};
	
	avlTree.traverse(avlTree.beginInOrder(), avlTree.endInOrder(), doubleElement);
	
	std::vector<int> elements {};
	for (auto iterator {avlTree.cbeginInOrder()}; iterator != avlTree.cendInOrder(); ++iterator) {
		elements.push_back(*iterator);
	}
	
	EXPECT_THAT(elements, testing::ElementsAre(-100, -40, -20, -10, 0, 20, 60, 80, 100));
}
}