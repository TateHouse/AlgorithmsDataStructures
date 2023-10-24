#include <gmock/gmock.h>

#include <array>

#include "DataStructures/Trees/BinarySearchTree.hpp"

namespace Core::DataStructures::Trees::Test {
class NonEmptyIntegerBinarySearchTreeTest : public testing::Test {
public:
	NonEmptyIntegerBinarySearchTreeTest();
	~NonEmptyIntegerBinarySearchTreeTest() override = default;

protected:
	BinarySearchTree<int> binarySearchTree {};
};

NonEmptyIntegerBinarySearchTreeTest::NonEmptyIntegerBinarySearchTreeTest() {
	const auto elements {std::array<int, 9> {0, 10, 5, 15, 20, -10, -5, -15, -20}};
	for (const auto& element: elements) {
		binarySearchTree.insert(element);
	}
}

TEST_F(NonEmptyIntegerBinarySearchTreeTest, WhenCopyConstruct_ThenNewBinarySearchTreeIsEqualToOriginal) {
	const auto otherBinarySearchTree {binarySearchTree};
	
	EXPECT_THAT(otherBinarySearchTree, testing::Eq(binarySearchTree));
}

TEST_F(NonEmptyIntegerBinarySearchTreeTest, WhenMoveConstruct_ThenNewBinarySearchTreeIsEqualToOriginal) {
	const auto otherBinarySearchTree {std::move(binarySearchTree)};
	
	std::vector<int> elements {};
	for (auto iterator {otherBinarySearchTree.cbeginInOrder()};
	     iterator != otherBinarySearchTree.cendInOrder(); ++iterator) {
		elements.push_back(*iterator);
	}
	
	EXPECT_THAT(elements, testing::ElementsAre(-20, -15, -10, -5, 0, 5, 10, 15, 20));
}

TEST_F(NonEmptyIntegerBinarySearchTreeTest, WhenCopyAssign_ThenNewBinarySearchTreeIsEqualToOriginal) {
	const auto otherBinarySearchTree = binarySearchTree;
	
	EXPECT_THAT(otherBinarySearchTree, testing::Eq(binarySearchTree));
}

TEST_F(NonEmptyIntegerBinarySearchTreeTest, WhenMoveAssign_ThenNewBinarySearchTreeIsEqualToOriginal) {
	const auto otherBinarySearchTree = std::move(binarySearchTree);
	
	std::vector<int> elements {};
	for (auto iterator {otherBinarySearchTree.cbeginInOrder()};
	     iterator != otherBinarySearchTree.cendInOrder(); ++iterator) {
		elements.push_back(*iterator);
	}
	
	EXPECT_THAT(elements, testing::ElementsAre(-20, -15, -10, -5, 0, 5, 10, 15, 20));
}

TEST_F(NonEmptyIntegerBinarySearchTreeTest,
       GivenTwoNonEqualNonEmptyIntegerBinarySearchTrees_WhenCompare_ThenReturnsFalse) {
	BinarySearchTree<int> otherBinarySearchTree {};
	const auto elements {std::array<int, 9> {0, 20, -20, 30, -30, 5, -5, 10, -10}};
	for (const auto& element: elements) {
		otherBinarySearchTree.insert(element);
	}
	
	EXPECT_THAT(binarySearchTree, testing::Ne(otherBinarySearchTree));
}

TEST_F(NonEmptyIntegerBinarySearchTreeTest, GivenTwoEqualNonEmptyIntegerBinaryTrees_WhenCompare_ReturnsTrue) {
	BinarySearchTree<int> otherBinarySearchTree {};
	const auto elements {std::array<int, 9> {0, 10, 5, 15, 20, -10, -5, -15, -20}};
	for (const auto& element: elements) {
		otherBinarySearchTree.insert(element);
	}
	
	EXPECT_THAT(binarySearchTree, testing::Eq(otherBinarySearchTree));
}

TEST_F(NonEmptyIntegerBinarySearchTreeTest, WhenIterateConstInOrder_ThenElementsAreInExpectedOrder) {
	std::vector<int> elements {};
	for (auto iterator {binarySearchTree.cbeginInOrder()}; iterator != binarySearchTree.cendInOrder(); ++iterator) {
		elements.push_back(*iterator);
	}
	
	EXPECT_THAT(elements, testing::ElementsAre(-20, -15, -10, -5, 0, 5, 10, 15, 20));
}

TEST_F(NonEmptyIntegerBinarySearchTreeTest, WhenIterateInOrder_ThenElementsAreInExpectedOrder) {
	std::vector<int> elements {};
	for (auto iterator {binarySearchTree.beginInOrder()}; iterator != binarySearchTree.endInOrder(); ++iterator) {
		elements.push_back(*iterator);
	}
	
	EXPECT_THAT(elements, testing::ElementsAre(-20, -15, -10, -5, 0, 5, 10, 15, 20));
}

TEST_F(NonEmptyIntegerBinarySearchTreeTest, WhenIterateConstLeveLOrder_ThenElementsAreInExpectedOrder) {
	std::vector<int> elements {};
	for (auto iterator {binarySearchTree.cbeginLevelOrder()};
	     iterator != binarySearchTree.cendLevelOrder(); ++iterator) {
		elements.push_back(*iterator);
	}
	
	EXPECT_THAT(elements, testing::ElementsAre(0, -10, 10, -15, -5, 5, 15, -20, 20));
}

TEST_F(NonEmptyIntegerBinarySearchTreeTest, WhenIterateLevelOrder_ThenElementsAreInExpectedOrder) {
	std::vector<int> elements {};
	for (auto iterator {binarySearchTree.beginLevelOrder()}; iterator != binarySearchTree.endLevelOrder(); ++iterator) {
		elements.push_back(*iterator);
	}
	
	EXPECT_THAT(elements, testing::ElementsAre(0, -10, 10, -15, -5, 5, 15, -20, 20));
}

TEST_F(NonEmptyIntegerBinarySearchTreeTest, WhenIterateConstPostOrder_ThenElementsAreInExpectedOrder) {
	std::vector<int> elements {};
	for (auto iterator {binarySearchTree.cbeginPostOrder()}; iterator != binarySearchTree.cendPostOrder(); ++iterator) {
		elements.push_back(*iterator);
	}
	
	EXPECT_THAT(elements, testing::ElementsAre(-20, -15, -5, -10, 5, 20, 15, 10, 0));
}

TEST_F(NonEmptyIntegerBinarySearchTreeTest, WhenIteratePostOrder_ThenElementsAreInExpectedOrder) {
	std::vector<int> elements {};
	for (auto iterator {binarySearchTree.beginPostOrder()}; iterator != binarySearchTree.endPostOrder(); ++iterator) {
		elements.push_back(*iterator);
	}
	
	EXPECT_THAT(elements, testing::ElementsAre(-20, -15, -5, -10, 5, 20, 15, 10, 0));
}

TEST_F(NonEmptyIntegerBinarySearchTreeTest, WhenIterateConstPreOrder_ThenElementsAreInExpectedOrder) {
	std::vector<int> elements {};
	for (auto iterator {binarySearchTree.cbeginPreOrder()}; iterator != binarySearchTree.cendPreOrder(); ++iterator) {
		elements.push_back(*iterator);
	}
	
	EXPECT_THAT(elements, testing::ElementsAre(0, -10, -15, -20, -5, 10, 5, 15, 20));
}

TEST_F(NonEmptyIntegerBinarySearchTreeTest, WhenIteratePreOrder_ThenElementsAreInExpectedOrder) {
	std::vector<int> elements {};
	for (auto iterator {binarySearchTree.beginPreOrder()}; iterator != binarySearchTree.endPreOrder(); ++iterator) {
		elements.push_back(*iterator);
	}
	
	EXPECT_THAT(elements, testing::ElementsAre(0, -10, -15, -20, -5, 10, 5, 15, 20));
}

TEST_F(NonEmptyIntegerBinarySearchTreeTest, GivenInteger_WhenInsert_ThenElementsAreInExpectedOrder) {
	binarySearchTree.insert(8);
	
	std::vector<int> elements {};
	for (auto iterator {binarySearchTree.cbeginInOrder()}; iterator != binarySearchTree.cendInOrder(); ++iterator) {
		elements.push_back(*iterator);
	}
	
	EXPECT_THAT(elements, testing::ElementsAre(-20, -15, -10, -5, 0, 5, 8, 10, 15, 20));
}

TEST_F(NonEmptyIntegerBinarySearchTreeTest, GivenInteger_WhenInsert_ThenSizeIsIncremented) {
	binarySearchTree.insert(8);
	const auto size {binarySearchTree.getNodeCount()};
	
	EXPECT_THAT(size, testing::Eq(10));
}

TEST_F(NonEmptyIntegerBinarySearchTreeTest, GivenInteger_WhenRemoveFirst_ThenReturnsElement) {
	const auto element {binarySearchTree.removeFirst(20)};
	
	EXPECT_THAT(element, testing::Optional(20));
}

TEST_F(NonEmptyIntegerBinarySearchTreeTest, GivenInteger_WhenRemoveFirst_ThenSizeIsDecremented) {
	const auto element {binarySearchTree.removeFirst(20)};
	const auto size {binarySearchTree.getNodeCount()};
	
	EXPECT_THAT(size, testing::Eq(8));
}

TEST_F(NonEmptyIntegerBinarySearchTreeTest, GivenInteger_WhenRemoveFirstAndIsLeafNode_ThenElementsAreInExpectedOrder) {
	const auto element {binarySearchTree.removeFirst(20)};
	
	std::vector<int> elements {};
	for (auto iterator {binarySearchTree.cbeginInOrder()}; iterator != binarySearchTree.cendInOrder(); ++iterator) {
		elements.push_back(*iterator);
	}
	
	EXPECT_THAT(elements, testing::ElementsAre(-20, -15, -10, -5, 0, 5, 10, 15));
}

TEST_F(NonEmptyIntegerBinarySearchTreeTest,
       GivenInteger_WhenRemoveFirstAndNodeHasOnlyLeftChild_ThenElementsAreInExpectedOrder) {
	const auto element {binarySearchTree.removeFirst(-15)};
	
	std::vector<int> elements {};
	for (auto iterator {binarySearchTree.cbeginInOrder()}; iterator != binarySearchTree.cendInOrder(); ++iterator) {
		elements.push_back(*iterator);
	}
	
	EXPECT_THAT(elements, testing::ElementsAre(-20, -10, -5, 0, 5, 10, 15, 20));
}

TEST_F(NonEmptyIntegerBinarySearchTreeTest,
       GivenInteger_WhenRemoveFirstAndNodeHasOnlyRightChild_ThenElementsAreInExpectedOrder) {
	const auto element {binarySearchTree.removeFirst(15)};
	
	std::vector<int> elements {};
	for (auto iterator {binarySearchTree.cbeginInOrder()}; iterator != binarySearchTree.cendInOrder(); ++iterator) {
		elements.push_back(*iterator);
	}
	
	EXPECT_THAT(elements, testing::ElementsAre(-20, -15, -10, -5, 0, 5, 10, 20));
}

TEST_F(NonEmptyIntegerBinarySearchTreeTest,
       GivenInteger_WhenRemoveFirstAndNodeHasBothChildren_ThenElementsAreInExpectedOrder) {
	const auto element {binarySearchTree.removeFirst(10)};
	
	std::vector<int> elements {};
	for (auto iterator {binarySearchTree.cbeginInOrder()}; iterator != binarySearchTree.cendInOrder(); ++iterator) {
		elements.push_back(*iterator);
	}
	
	EXPECT_THAT(elements, testing::ElementsAre(-20, -15, -10, -5, 0, 5, 15, 20));
}

TEST_F(NonEmptyIntegerBinarySearchTreeTest, GivenInteger_WhenRemoveFirstAndNodeIsRoot_ThenElementsAreInExpectedOrder) {
	const auto element {binarySearchTree.removeFirst(0)};
	
	std::vector<int> elements {};
	for (auto iterator {binarySearchTree.cbeginInOrder()}; iterator != binarySearchTree.cendInOrder(); ++iterator) {
		elements.push_back(*iterator);
	}
	
	EXPECT_THAT(elements, testing::ElementsAre(-20, -15, -10, -5, 5, 10, 15, 20));
}

TEST_F(NonEmptyIntegerBinarySearchTreeTest,
       GivenIntegerNotInBinarySearchTree_WhenRemoveFirst_ThenElementsOrderIsUnchanged) {
	binarySearchTree.removeFirst(100);
	
	std::vector<int> elements {};
	for (auto iterator {binarySearchTree.cbeginInOrder()}; iterator != binarySearchTree.cendInOrder(); ++iterator) {
		elements.push_back(*iterator);
	}
	
	EXPECT_THAT(elements, testing::ElementsAre(-20, -15, -10, -5, 0, 5, 10, 15, 20));
}

TEST_F(NonEmptyIntegerBinarySearchTreeTest,
       GivenIntegerNotInBinarySearchTree_WhenRemoveFirst_ThenSizeIsNotDecremented) {
	binarySearchTree.removeFirst(100);
	const auto size {binarySearchTree.getNodeCount()};
	
	EXPECT_THAT(size, testing::Eq(9));
}

TEST_F(NonEmptyIntegerBinarySearchTreeTest, WhenRemoveMinimum_ThenReturnsElement) {
	const auto element {binarySearchTree.removeMinimum()};
	
	EXPECT_THAT(element, testing::Optional(-20));
}

TEST_F(NonEmptyIntegerBinarySearchTreeTest, WhenRemoveMinimum_ThenSizeIsDecremented) {
	const auto element {binarySearchTree.removeMinimum()};
	const auto size {binarySearchTree.getNodeCount()};
	
	EXPECT_THAT(size, testing::Eq(8));
}

TEST_F(NonEmptyIntegerBinarySearchTreeTest, WhenRemoveMinimum_ThemElementsAreInExpectedOrder) {
	binarySearchTree.removeMinimum();
	
	std::vector<int> elements {};
	for (auto iterator {binarySearchTree.cbeginInOrder()}; iterator != binarySearchTree.cendInOrder(); ++iterator) {
		elements.push_back(*iterator);
	}
	
	EXPECT_THAT(elements, testing::ElementsAre(-15, -10, -5, 0, 5, 10, 15, 20));
}

TEST_F(NonEmptyIntegerBinarySearchTreeTest, WhenRemoveMaximum_ThenReturnsElement) {
	const auto element {binarySearchTree.removeMaximum()};
	
	EXPECT_THAT(element, testing::Optional(20));
}

TEST_F(NonEmptyIntegerBinarySearchTreeTest, WhenRemoveMaximum_ThenSizeIsDecremented) {
	const auto element {binarySearchTree.removeMaximum()};
	const auto size {binarySearchTree.getNodeCount()};
	
	EXPECT_THAT(size, testing::Eq(8));
}

TEST_F(NonEmptyIntegerBinarySearchTreeTest, WhenRemoveMaximum_ThenElementsAreInExpectedOrder) {
	binarySearchTree.removeMaximum();
	
	std::vector<int> elements {};
	for (auto iterator {binarySearchTree.cbeginInOrder()}; iterator != binarySearchTree.cendInOrder(); ++iterator) {
		elements.push_back(*iterator);
	}
	
	EXPECT_THAT(elements, testing::ElementsAre(-20, -15, -10, -5, 0, 5, 10, 15));
}

TEST_F(NonEmptyIntegerBinarySearchTreeTest, WhenRemoveAll_ThenReturnsElementsInPostOrder) {
	const auto result {binarySearchTree.removeAll()};
	
	EXPECT_THAT(result, testing::ElementsAre(-20, -15, -5, -10, 5, 20, 15, 10, 0));
}

TEST_F(NonEmptyIntegerBinarySearchTreeTest, WhenRemoveAll_ThenSizeIsZero) {
	binarySearchTree.removeAll();
	const auto size {binarySearchTree.getNodeCount()};
	
	EXPECT_THAT(size, testing::Eq(0));
}

TEST_F(NonEmptyIntegerBinarySearchTreeTest, GivenIntegerMatchingAtLeastOneElement_WhenFindFirst_ThenReturnsElement) {
	const auto element {binarySearchTree.findFirst(20)};
	
	EXPECT_THAT(element, testing::Optional(20));
}

TEST_F(NonEmptyIntegerBinarySearchTreeTest, GivenIntegerMatchingNoElements_WhenFindFirst_ThenReturnsNullOptional) {
	const auto element {binarySearchTree.findFirst(100)};
	
	EXPECT_THAT(element, testing::Eq(std::nullopt));
}

TEST_F(NonEmptyIntegerBinarySearchTreeTest, WhenFindMinimum_ThenReturnsElement) {
	const auto element {binarySearchTree.findMinimum()};
	
	EXPECT_THAT(element, testing::Optional(-20));
}

TEST_F(NonEmptyIntegerBinarySearchTreeTest, WhenFindMaximum_ThenReturnsElement) {
	const auto element {binarySearchTree.findMaximum()};
	
	EXPECT_THAT(element, testing::Optional(20));
}

TEST_F(NonEmptyIntegerBinarySearchTreeTest,
       GivenConstFunctionToApplyToEachElement_WhenConstTraverse_ThenFunctionIsAppliedToEachElement) {
	std::vector<int> elements {};
	const auto pushBack {[&elements](const int& element) {
		elements.push_back(element);
	}};
	
	const auto& constBinarySearchTree {binarySearchTree};
	constBinarySearchTree.traverse(constBinarySearchTree.cbeginInOrder(),
	                               constBinarySearchTree.cendInOrder(),
	                               pushBack);
	
	EXPECT_THAT(elements, testing::ElementsAre(-20, -15, -10, -5, 0, 5, 10, 15, 20));
}

TEST_F(NonEmptyIntegerBinarySearchTreeTest,
       GivenFunctionToApplyToEachElement_WhenConstTraverse_ThenFunctionIsAppliedToEachElement) {
	const auto doubleElement {[](int& element) {
		element = element * 2;
	}};
	
	binarySearchTree.traverse(binarySearchTree.beginInOrder(), binarySearchTree.endInOrder(), doubleElement);
	
	std::vector<int> elements {};
	for (auto iterator {binarySearchTree.cbeginInOrder()}; iterator != binarySearchTree.cendInOrder(); ++iterator) {
		elements.push_back(*iterator);
	}
	
	EXPECT_THAT(elements, testing::ElementsAre(-40, -30, -20, -10, 0, 10, 20, 30, 40));
}

TEST_F(NonEmptyIntegerBinarySearchTreeTest, GivenIntegerMatchingAtLeastOneElement_WhenContains_ThenReturnsTrue) {
	const auto contains {binarySearchTree.contains(20)};
	
	EXPECT_THAT(contains, testing::IsTrue());
}

TEST_F(NonEmptyIntegerBinarySearchTreeTest, WhenIsEmpty_ThenReturnsFalse) {
	const auto isEmpty {binarySearchTree.isEmpty()};
	
	EXPECT_THAT(isEmpty, testing::IsFalse());
}

TEST_F(NonEmptyIntegerBinarySearchTreeTest, WhenGetHeight_ThenReturnsHeight) {
	const auto height {binarySearchTree.getHeight()};
	
	EXPECT_THAT(height, testing::Eq(3));
}
}