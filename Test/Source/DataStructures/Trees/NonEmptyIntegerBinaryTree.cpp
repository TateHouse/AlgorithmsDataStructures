#include <gmock/gmock.h>

#include "DataStructures/Trees/BinaryTree.hpp"
#include "IntegerPredicates.hpp"

namespace Core::DataStructures::Trees::Test {
class NonEmptyIntegerBinaryTreeTest : public testing::Test {
public:
	NonEmptyIntegerBinaryTreeTest() noexcept;
	~NonEmptyIntegerBinaryTreeTest() noexcept override = default;

protected:
	BinaryTree<int> binaryTree {};
};

NonEmptyIntegerBinaryTreeTest::NonEmptyIntegerBinaryTreeTest() noexcept {
	for (auto element {10}; element <= 50; element = element + 10) {
		binaryTree.insert(element);
	}
}

TEST_F(NonEmptyIntegerBinaryTreeTest, WhenCopyConstruct_ThenNewBinaryTreeIsEqualToOriginal) {
	const auto otherBinaryTree {binaryTree};
	
	EXPECT_THAT(otherBinaryTree, testing::Eq(binaryTree));
}

TEST_F(NonEmptyIntegerBinaryTreeTest, WhenMoveConstruct_ThenNewBinaryTreeIsEqualToOriginal) {
	const auto otherBinaryTree {std::move(binaryTree)};
	
	std::vector<int> elements {};
	for (auto iterator {otherBinaryTree.cbeginLevelOrder()}; iterator != otherBinaryTree.cendLevelOrder(); ++iterator) {
		elements.push_back(*iterator);
	}
	
	EXPECT_THAT(elements, testing::ElementsAre(10, 20, 30, 40, 50));
}

TEST_F(NonEmptyIntegerBinaryTreeTest,
       GivenNonEmptyIntegerBinaryTree_WhenCopyAssign_ThenNewBinaryTreeIsEqualToOriginal) {
	auto otherBinaryTree = binaryTree;
	
	EXPECT_THAT(otherBinaryTree, testing::Eq(binaryTree));
}

TEST_F(NonEmptyIntegerBinaryTreeTest,
       GivenNonEmptyIntegerBinaryTree_WhenMoveAssign_ThenNewBinaryTreeIsEqualToOriginal) {
	auto otherBinaryTree = std::move(binaryTree);
	
	std::vector<int> elements {};
	for (auto iterator {otherBinaryTree.cbeginLevelOrder()}; iterator != otherBinaryTree.cendLevelOrder(); ++iterator) {
		elements.push_back(*iterator);
	}
	
	EXPECT_THAT(elements, testing::ElementsAre(10, 20, 30, 40, 50));
}

TEST_F(NonEmptyIntegerBinaryTreeTest, GivenTwoNonEqualNonEmptyIntegerBinaryTrees_WhenCompare_ThenReturnsFalse) {
	BinaryTree<int> otherBinaryTree {};
	for (auto element {100}; element >= 50; element = element - 10) {
		otherBinaryTree.insert(element);
	}
	
	EXPECT_THAT(binaryTree, testing::Ne(otherBinaryTree));
}

TEST_F(NonEmptyIntegerBinaryTreeTest, GivenTwoEqualNonEmptyIntegerBinaryTrees_WhenCompare_ThenReturnsTrue) {
	BinaryTree<int> otherBinaryTree {};
	for (auto element {10}; element <= 50; element = element + 10) {
		otherBinaryTree.insert(element);
	}
	
	EXPECT_THAT(binaryTree, testing::Eq(otherBinaryTree));
}

TEST_F(NonEmptyIntegerBinaryTreeTest, WhenIterateConstInOrder_ThenElementsAreInExpectedOrder) {
	std::vector<int> elements {};
	for (auto iterator {binaryTree.cbeginInOrder()}; iterator != binaryTree.cendInOrder(); ++iterator) {
		elements.push_back(*iterator);
	}
	
	EXPECT_THAT(elements, testing::ElementsAre(40, 20, 50, 10, 30));
}

TEST_F(NonEmptyIntegerBinaryTreeTest, WhenIterateInOrder_ThenElementsAreInExpectedOrder) {
	std::vector<int> elements {};
	for (auto iterator {binaryTree.beginInOrder()}; iterator != binaryTree.endInOrder(); ++iterator) {
		elements.push_back(*iterator);
	}
	
	EXPECT_THAT(elements, testing::ElementsAre(40, 20, 50, 10, 30));
}

TEST_F(NonEmptyIntegerBinaryTreeTest, WhenIterateConstLevelOrder_ThenElementsAreInExpectedOrder) {
	std::vector<int> elements {};
	for (auto iterator {binaryTree.cbeginLevelOrder()}; iterator != binaryTree.cendLevelOrder(); ++iterator) {
		elements.push_back(*iterator);
	}
	
	EXPECT_THAT(elements, testing::ElementsAre(10, 20, 30, 40, 50));
}

TEST_F(NonEmptyIntegerBinaryTreeTest, WhenIterateLevelOrder_ThenElementsAreInExpectedOrder) {
	std::vector<int> elements {};
	for (auto iterator {binaryTree.beginLevelOrder()}; iterator != binaryTree.endLevelOrder(); ++iterator) {
		elements.push_back(*iterator);
	}
	
	EXPECT_THAT(elements, testing::ElementsAre(10, 20, 30, 40, 50));
}

TEST_F(NonEmptyIntegerBinaryTreeTest, WhenIterateConstPostOrder_ThenElementsAreInExpectedOrder) {
	std::vector<int> elements {};
	for (auto iterator {binaryTree.cbeginPostOrder()}; iterator != binaryTree.cendPostOrder(); ++iterator) {
		elements.push_back(*iterator);
	}
	
	EXPECT_THAT(elements, testing::ElementsAre(40, 50, 20, 30, 10));
}

TEST_F(NonEmptyIntegerBinaryTreeTest, WhenIteratePostOrder_ThenElementsAreInExpectedOrder) {
	std::vector<int> elements {};
	for (auto iterator {binaryTree.beginPostOrder()}; iterator != binaryTree.endPostOrder(); ++iterator) {
		elements.push_back(*iterator);
	}
	
	EXPECT_THAT(elements, testing::ElementsAre(40, 50, 20, 30, 10));
}

TEST_F(NonEmptyIntegerBinaryTreeTest, WhenIterateConstPreOrder_ThenElementsAreInExpectedOrder) {
	std::vector<int> elements {};
	for (auto iterator {binaryTree.cbeginPreOrder()}; iterator != binaryTree.cendPreOrder(); ++iterator) {
		elements.push_back(*iterator);
	}
	
	EXPECT_THAT(elements, testing::ElementsAre(10, 20, 40, 50, 30));
}

TEST_F(NonEmptyIntegerBinaryTreeTest, WhenIteratePreOrder_ThenElementsAreInExpectedOrder) {
	std::vector<int> elements {};
	for (auto iterator {binaryTree.beginPreOrder()}; iterator != binaryTree.endPreOrder(); ++iterator) {
		elements.push_back(*iterator);
	}
	
	EXPECT_THAT(elements, testing::ElementsAre(10, 20, 40, 50, 30));
}

TEST_F(NonEmptyIntegerBinaryTreeTest, GivenInteger_WhenInsert_ThenElementsAreInExpectedOrder) {
	binaryTree.insert(60);
	
	std::vector<int> elements {};
	for (auto iterator {binaryTree.cbeginLevelOrder()}; iterator != binaryTree.cendLevelOrder(); ++iterator) {
		elements.push_back(*iterator);
	}
	
	EXPECT_THAT(elements, testing::ElementsAre(10, 20, 30, 40, 50, 60));
}

TEST_F(NonEmptyIntegerBinaryTreeTest, GivenInteger_WhenInsert_ThenSizeIsIncremented) {
	binaryTree.insert(60);
	const auto size {binaryTree.getNodeCount()};
	
	EXPECT_THAT(size, testing::Eq(6));
}

TEST_F(NonEmptyIntegerBinaryTreeTest, GivenPredicateMatchingAtLeastOneElement_WhenRemoveFirst_ThenReturnsElement) {
	const auto result {binaryTree.removeFirst(::Test::isTen)};
	
	EXPECT_THAT(result, testing::Optional(10));
}

TEST_F(NonEmptyIntegerBinaryTreeTest, GivenPredicateMatchingAtLeastOneElement_WhenRemoveFirst_ThenSizeIsDecremented) {
	binaryTree.removeFirst(::Test::isTen);
	const auto size {binaryTree.getNodeCount()};
	
	EXPECT_THAT(size, testing::Eq(4));
}

TEST_F(NonEmptyIntegerBinaryTreeTest,
       GivenPredicateMatchingAtLeastOneElement_WhenRemoveFirst_ThenRemovedNodeIsReplacedWithDeepestRightmostNode) {
	binaryTree.removeFirst(::Test::isTen);
	
	std::vector<int> elements {};
	for (auto iterator {binaryTree.cbeginLevelOrder()}; iterator != binaryTree.cendLevelOrder(); ++iterator) {
		elements.push_back(*iterator);
	}
	
	EXPECT_THAT(elements, testing::ElementsAre(50, 20, 30, 40));
}

TEST_F(NonEmptyIntegerBinaryTreeTest, GivenPredicateMatchingNoElements_WhenRemoveFirst_ThenReturnsNullOptional) {
	const auto result {binaryTree.removeFirst(::Test::isSixty)};
	
	EXPECT_THAT(result, testing::Eq(std::nullopt));
}

TEST_F(NonEmptyIntegerBinaryTreeTest, GivenPredicateMatchingNoElements_WhenRemoveFirst_ThenSizeIsNotDecremented) {
	binaryTree.removeFirst(::Test::isSixty);
	const auto size {binaryTree.getNodeCount()};
	
	EXPECT_THAT(size, testing::Eq(5));
}

TEST_F(NonEmptyIntegerBinaryTreeTest, GivenPredicateMatchingNoElements_WhenRemoveFirst_ThenElementsOrderIsUnchanged) {
	binaryTree.removeFirst(::Test::isSixty);
	
	std::vector<int> elements {};
	for (auto iterator {binaryTree.cbeginLevelOrder()}; iterator != binaryTree.cendLevelOrder(); ++iterator) {
		elements.push_back(*iterator);
	}
	
	EXPECT_THAT(elements, testing::ElementsAre(10, 20, 30, 40, 50));
}

TEST_F(NonEmptyIntegerBinaryTreeTest, GivenNode_WhenRemoveAll_ThenReturnsElementsInExpectedOrder) {
	const auto result {binaryTree.removeAll()};
	
	EXPECT_THAT(result, testing::ElementsAre(40, 50, 20, 30, 10));
}

TEST_F(NonEmptyIntegerBinaryTreeTest, GivenNode_WhenRemoveAll_ThenSizeIsZero) {
	binaryTree.removeAll();
	const auto size {binaryTree.getNodeCount()};
	
	EXPECT_THAT(size, testing::Eq(0));
}

TEST_F(NonEmptyIntegerBinaryTreeTest,
       GivenPredicateMatchingAtLeastOneElement_WhenFindFirstConstLevelOrder_ThenReturnsConstIterator) {
	const auto result {binaryTree.findFirst(binaryTree.cbeginLevelOrder(),
	                                        binaryTree.cendLevelOrder(),
	                                        ::Test::isTwenty)};
	
	EXPECT_THAT(*result, testing::Eq(20));
}

TEST_F(NonEmptyIntegerBinaryTreeTest,
       GivenPredicateMatchingNoElements_WhenFindFirstConstLevelOrder_ThenReturnsEndIterator) {
	const auto result {binaryTree.findFirst(binaryTree.cbeginLevelOrder(),
	                                        binaryTree.cendLevelOrder(),
	                                        ::Test::isSixty)};
	
	EXPECT_THAT(result, testing::Eq(binaryTree.cendLevelOrder()));
}

TEST_F(NonEmptyIntegerBinaryTreeTest,
       GivenPredicateMatchingAtLeastOneElement_WhenFindFirstLevelOrder_ThenReturnsIterator) {
	const auto result {binaryTree.findFirst(binaryTree.beginLevelOrder(),
	                                        binaryTree.endLevelOrder(),
	                                        ::Test::isTwenty)};
	
	EXPECT_THAT(*result, testing::Eq(20));
}

TEST_F(NonEmptyIntegerBinaryTreeTest, GivenPredicateMatchingNoElements_WhenFindFirstLevelOrder_ThenReturnsEndIterator) {
	const auto result {binaryTree.findFirst(binaryTree.beginLevelOrder(), binaryTree.endLevelOrder(), ::Test::isSixty)};
	
	EXPECT_THAT(result, testing::Eq(binaryTree.endLevelOrder()));
}

TEST_F(NonEmptyIntegerBinaryTreeTest,
       GivenConstFunctionToApplyToEachElement_WhenConstTraverse_ThenElementsAreTraversedAndFunctionIsAppliedInExpectedOrder) {
	std::vector<int> elements {};
	const auto pushBack {[&elements](const int& element) {
		elements.push_back(element);
	}};
	
	const auto& constBinaryTree {binaryTree};
	constBinaryTree.traverse(constBinaryTree.cbeginLevelOrder(), constBinaryTree.cendLevelOrder(), pushBack);
	
	EXPECT_THAT(elements, testing::ElementsAre(10, 20, 30, 40, 50));
}

TEST_F(NonEmptyIntegerBinaryTreeTest,
       GivenFunctionToApplyToEachElement_WhenTraverse_ThenElementsAreTraversedAndFunctionIsAppliedInExpectedOrder) {
	const auto doubleElement {[](int& element) {
		element = element * 2;
	}};
	
	binaryTree.traverse(binaryTree.beginLevelOrder(), binaryTree.endLevelOrder(), doubleElement);
	
	std::vector<int> elements {};
	for (auto iterator {binaryTree.cbeginLevelOrder()}; iterator != binaryTree.cendLevelOrder(); ++iterator) {
		elements.push_back(*iterator);
	}
	
	EXPECT_THAT(elements, testing::ElementsAre(20, 40, 60, 80, 100));
}

TEST_F(NonEmptyIntegerBinaryTreeTest, GivenPredicateMatchingAtLeastOneElement_WhenContains_ThenReturnsTrue) {
	const auto result {binaryTree.contains(::Test::isTen)};
	
	EXPECT_THAT(result, testing::IsTrue());
}

TEST_F(NonEmptyIntegerBinaryTreeTest, GivenPredicateMatchingNoElements_WhenContains_ThenReturnsFalse) {
	const auto result {binaryTree.contains(::Test::isSixty)};
	
	EXPECT_THAT(result, testing::IsFalse());
}

TEST_F(NonEmptyIntegerBinaryTreeTest, WhenIsEmpty_ThenReturnsFalse) {
	const auto result {binaryTree.isEmpty()};
	
	EXPECT_THAT(result, testing::IsFalse());
}

TEST_F(NonEmptyIntegerBinaryTreeTest, WhenGetHeight_ThenReturnsHeight) {
	const auto height {binaryTree.getHeight()};
	
	EXPECT_THAT(height, testing::Eq(2));
}
}