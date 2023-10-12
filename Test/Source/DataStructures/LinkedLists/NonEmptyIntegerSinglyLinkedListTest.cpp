#include <gmock/gmock.h>

#include "DataStructures/LinkedLists/SinglyLinkedList.hpp"
#include "IntegerPredicates.hpp"

namespace Core::DataStructures::LinkedLists::Test {
class NonEmptyIntegerSinglyLinkedListTest : public testing::Test {
public:
	NonEmptyIntegerSinglyLinkedListTest() noexcept;
	~NonEmptyIntegerSinglyLinkedListTest() noexcept override = default;

protected:
	SinglyLinkedList<int> singlyLinkedList {};
};

NonEmptyIntegerSinglyLinkedListTest::NonEmptyIntegerSinglyLinkedListTest() noexcept {
	for (auto element {50}; element >= 10; element = element - 10) {
		singlyLinkedList.insertAtHead(element);
	}
}

TEST_F(NonEmptyIntegerSinglyLinkedListTest,
       GivenNonEmptyIntegerSinglyLinkedList_WhenCopyConstruct_ThenNewSinglyLinkedListIsEqualToOriginal) {
	const auto otherSinglyLinkedList {singlyLinkedList};
	
	EXPECT_THAT(otherSinglyLinkedList, testing::Eq(singlyLinkedList));
}

TEST_F(NonEmptyIntegerSinglyLinkedListTest,
       GivenNonEmptyIntegerSinglyLinkedList_WhenMoveConstruct_ThenNewSinglyLinkedListContainsElementsFromOriginal) {
	const auto otherSinglyLinkedList {std::move(singlyLinkedList)};
	
	EXPECT_THAT(otherSinglyLinkedList, testing::ElementsAre(10, 20, 30, 40, 50));
}

TEST_F(NonEmptyIntegerSinglyLinkedListTest,
       GivenNonEmptyIntegerSinglyLinkedList_WhenCopyAssign_ThenNewSinglyLinkedListIsEqualToOriginal) {
	auto otherSinglyLinkedList {SinglyLinkedList<int> {}};
	otherSinglyLinkedList = singlyLinkedList;
	
	EXPECT_THAT(otherSinglyLinkedList, testing::Eq(singlyLinkedList));
}

TEST_F(NonEmptyIntegerSinglyLinkedListTest,
       GivenNonEmptyIntegerSinglyLinkedList_WhenMoveAssign_ThenNewSinglyLinkedListContainsElementsFromOriginal) {
	auto otherSinglyLinkedList {SinglyLinkedList<int> {}};
	otherSinglyLinkedList = std::move(singlyLinkedList);
	
	EXPECT_THAT(otherSinglyLinkedList, testing::ElementsAre(10, 20, 30, 40, 50));
}

TEST_F(NonEmptyIntegerSinglyLinkedListTest, WhenIterate_ThenElementsAreIteratedInExpectedOrder) {
	const auto expectedElements {std::vector<int> {10, 20, 30, 40, 50}};
	auto elementIndex {0};
	
	for (const auto& element: singlyLinkedList) {
		EXPECT_THAT(element, testing::Eq(expectedElements[elementIndex]));
		++elementIndex;
	}
}

TEST_F(NonEmptyIntegerSinglyLinkedListTest, WhenConstIterate_ThenElementsAreIteratedInExpectedOrder) {
	const auto constSinglyLinkedList {singlyLinkedList};
	const auto expectedElements {std::vector<int> {10, 20, 30, 40, 50}};
	auto elementIndex {0};
	
	for (const auto& element: constSinglyLinkedList) {
		EXPECT_THAT(element, testing::Eq(expectedElements[elementIndex]));
		++elementIndex;
	}
}

TEST_F(NonEmptyIntegerSinglyLinkedListTest,
       GivenTwoNonEqualNonEmptyIntegerSinglyLinkedListsOfDifferentSizes_WhenCompare_ThenReturnsFalse) {
	SinglyLinkedList<int> otherSinglyLinkedList {};
	otherSinglyLinkedList.insertAtHead(10);
	
	EXPECT_THAT(singlyLinkedList, testing::Ne(otherSinglyLinkedList));
}

TEST_F(NonEmptyIntegerSinglyLinkedListTest,
       GivenTwoNonEqualNonEmptyIntegerSinglyLinkedListsOfSameSize_WhenCompare_ThenReturnsFalse) {
	SinglyLinkedList<int> otherSinglyLinkedList {};
	for (auto element {50}; element >= 10; element = element - 10) {
		otherSinglyLinkedList.insertAtTail(element);
	}
	
	EXPECT_THAT(singlyLinkedList, testing::Ne(otherSinglyLinkedList));
}

TEST_F(NonEmptyIntegerSinglyLinkedListTest, GivenTwoEqualNonEmptyIntegerSinglyLinkedLists_WhenCompare_ThenReturnsTrue) {
	SinglyLinkedList<int> otherSinglyLinkedList {};
	for (auto element {50}; element >= 10; element = element - 10) {
		otherSinglyLinkedList.insertAtHead(element);
	}
	
	EXPECT_THAT(singlyLinkedList, testing::Eq(otherSinglyLinkedList));
}

TEST_F(NonEmptyIntegerSinglyLinkedListTest, GivenInteger_WhenInsertAtHead_ThenElementsAreInExpectedOrder) {
	singlyLinkedList.insertAtHead(5);
	
	EXPECT_THAT(singlyLinkedList, testing::ElementsAre(5, 10, 20, 30, 40, 50));
}

TEST_F(NonEmptyIntegerSinglyLinkedListTest, GivenInteger_WhenInsertAtHead_ThenSizeInIncremented) {
	singlyLinkedList.insertAtHead(5);
	const auto nodeCount {singlyLinkedList.getNodeCount()};
	
	EXPECT_THAT(nodeCount, testing::Eq(6));
}

TEST_F(NonEmptyIntegerSinglyLinkedListTest, GivenInteger_WhenInsertAtTail_ThenElementsAreInExpectedOrder) {
	singlyLinkedList.insertAtTail(60);
	
	EXPECT_THAT(singlyLinkedList, testing::ElementsAre(10, 20, 30, 40, 50, 60));
}

TEST_F(NonEmptyIntegerSinglyLinkedListTest, GivenInteger_WhenInsertAtTail_ThenSizeInIncremented) {
	singlyLinkedList.insertAtTail(60);
	const auto nodeCount {singlyLinkedList.getNodeCount()};
	
	EXPECT_THAT(nodeCount, testing::Eq(6));
}

TEST_F(NonEmptyIntegerSinglyLinkedListTest,
       GivenIntegerAndValidIndex_WhenInsertAtIndex_ThenElementsAreInExpectedOrder) {
	singlyLinkedList.insertAtIndex(35, 3);
	
	EXPECT_THAT(singlyLinkedList, testing::ElementsAre(10, 20, 30, 35, 40, 50));
}

TEST_F(NonEmptyIntegerSinglyLinkedListTest, GivenIntegerAndInvalidIndex_WhenInsertAtIndex_ThenElementWasNotInserted) {
	singlyLinkedList.insertAtIndex(60, 6);
	
	EXPECT_THAT(singlyLinkedList, testing::ElementsAre(10, 20, 30, 40, 50));
}

TEST_F(NonEmptyIntegerSinglyLinkedListTest, GivenIntegerAndValidIndex_WhenInsertAtIndex_ThenSizeInIncremented) {
	singlyLinkedList.insertAtIndex(35, 3);
	const auto nodeCount {singlyLinkedList.getNodeCount()};
	
	EXPECT_THAT(nodeCount, testing::Eq(6));
}

TEST_F(NonEmptyIntegerSinglyLinkedListTest, GivenIntegerAndValidIndex_WhenInsertAtIndex_ThenReturnsTrue) {
	const auto result {singlyLinkedList.insertAtIndex(35, 3)};
	
	EXPECT_THAT(result, testing::IsTrue());
}

TEST_F(NonEmptyIntegerSinglyLinkedListTest, GivenIntegerAndInvalidIndex_WhenInsertAtIndex_ThenReturnsFalse) {
	const auto result {singlyLinkedList.insertAtIndex(60, 10)};
	
	EXPECT_THAT(result, testing::IsFalse());
}

TEST_F(NonEmptyIntegerSinglyLinkedListTest, WhenRemoveAtHead_ThenElementsAreInExpectedOrder) {
	singlyLinkedList.removeAtHead();
	
	EXPECT_THAT(singlyLinkedList, testing::ElementsAre(20, 30, 40, 50));
}

TEST_F(NonEmptyIntegerSinglyLinkedListTest, WhenRemoveAtHead_ThenSizeInDecremented) {
	singlyLinkedList.removeAtHead();
	const auto nodeCount {singlyLinkedList.getNodeCount()};
	
	EXPECT_THAT(nodeCount, testing::Eq(4));
}

TEST_F(NonEmptyIntegerSinglyLinkedListTest, WhenRemoveAtHead_ThenReturnsElement) {
	const auto result {singlyLinkedList.removeAtHead()};
	
	EXPECT_THAT(result, testing::Optional(10));
}

TEST_F(NonEmptyIntegerSinglyLinkedListTest, WhenRemoveAtTail_ThenElementsAreInExpectedOrder) {
	singlyLinkedList.removeAtTail();
	
	EXPECT_THAT(singlyLinkedList, testing::ElementsAre(10, 20, 30, 40));
}

TEST_F(NonEmptyIntegerSinglyLinkedListTest, WhenRemoveAtTail_ThenSizeInDecremented) {
	singlyLinkedList.removeAtTail();
	const auto nodeCount {singlyLinkedList.getNodeCount()};
	
	EXPECT_THAT(nodeCount, testing::Eq(4));
}

TEST_F(NonEmptyIntegerSinglyLinkedListTest, WhenRemoveAtTail_ThenReturnsElement) {
	const auto result {singlyLinkedList.removeAtTail()};
	
	EXPECT_THAT(result, testing::Optional(50));
}

TEST_F(NonEmptyIntegerSinglyLinkedListTest, GivenValidIndex_WhenRemoveAtIndex_ThenElementsAreInExpectedOrder) {
	singlyLinkedList.removeAtIndex(3);
	
	EXPECT_THAT(singlyLinkedList, testing::ElementsAre(10, 20, 30, 50));
}

TEST_F(NonEmptyIntegerSinglyLinkedListTest, GivenInvalidIndex_WhenRemoveAtIndex_ThenElementsAreInExpectedOrder) {
	singlyLinkedList.removeAtIndex(10);
	
	EXPECT_THAT(singlyLinkedList, testing::ElementsAre(10, 20, 30, 40, 50));
}

TEST_F(NonEmptyIntegerSinglyLinkedListTest, GivenValidIndex_WhenRemoveAtIndex_ThenSizeInDecremented) {
	singlyLinkedList.removeAtIndex(3);
	const auto nodeCount {singlyLinkedList.getNodeCount()};
	
	EXPECT_THAT(nodeCount, testing::Eq(4));
}

TEST_F(NonEmptyIntegerSinglyLinkedListTest, GivenValidIndex_WhenRemoveAtIndex_ThenReturnsElement) {
	const auto result {singlyLinkedList.removeAtIndex(3)};
	
	EXPECT_THAT(result, testing::Optional(40));
}

TEST_F(NonEmptyIntegerSinglyLinkedListTest, WhenRemoveAll_ThenElementsAreRemoved) {
	singlyLinkedList.removeAll();
	
	EXPECT_THAT(singlyLinkedList, testing::ElementsAre());
}

TEST_F(NonEmptyIntegerSinglyLinkedListTest, WhenRemoveAll_ThenReturnsVectorOfElements) {
	const auto result {singlyLinkedList.removeAll()};
	
	EXPECT_THAT(result, testing::ElementsAre(10, 20, 30, 40, 50));
}

TEST_F(NonEmptyIntegerSinglyLinkedListTest, WhenRemoveAll_ThenSizeIsZero) {
	singlyLinkedList.removeAll();
	const auto nodeCount {singlyLinkedList.getNodeCount()};
	
	EXPECT_THAT(nodeCount, testing::Eq(0));
}

TEST_F(NonEmptyIntegerSinglyLinkedListTest,
       GivenPredicateMatchingAtLeastOneElement_WhenFindFirstConst_ThenReturnsConstIterator) {
	const auto constSinglyLinkedList {singlyLinkedList};
	const auto result {constSinglyLinkedList.findFirst(::Test::isThirty)};
	
	auto expectedIterator {constSinglyLinkedList.cbegin()};
	std::advance(expectedIterator, 2);
	
	EXPECT_THAT(result, testing::Eq(expectedIterator));
}

TEST_F(NonEmptyIntegerSinglyLinkedListTest,
       GivenPredicateMatchingNoElements_WhenFindFirstConst_ThenReturnsConstEndIterator) {
	const auto constSinglyLinkedList {singlyLinkedList};
	const auto result {constSinglyLinkedList.findFirst(::Test::isSixty)};
	
	EXPECT_THAT(result, testing::Eq(constSinglyLinkedList.cend()));
}

TEST_F(NonEmptyIntegerSinglyLinkedListTest, GivenPredicateMatchingAtLeastOneElement_WhenFindFirst_ThenReturnsIterator) {
	const auto result {singlyLinkedList.findFirst(::Test::isThirty)};
	
	auto expectedIterator {singlyLinkedList.begin()};
	std::advance(expectedIterator, 2);
	
	EXPECT_THAT(result, testing::Eq(expectedIterator));
}

TEST_F(NonEmptyIntegerSinglyLinkedListTest, GivenPredicateMatchingNoElements_WhenFindFirst_ThenReturnsEndIterator) {
	const auto result {singlyLinkedList.findFirst(::Test::isSixty)};
	
	EXPECT_THAT(result, testing::Eq(singlyLinkedList.end()));
}

TEST_F(NonEmptyIntegerSinglyLinkedListTest, GivenPredicateMatchingAtLeastOneElement_WhenContains_ThenReturnsTrue) {
	const auto result {singlyLinkedList.contains(::Test::isThirty)};
	
	EXPECT_THAT(result, testing::IsTrue());
}

TEST_F(NonEmptyIntegerSinglyLinkedListTest, GivenPredicateMatchingNoElements_WhenContains_ThenReturnsFalse) {
	const auto result {singlyLinkedList.contains(::Test::isSixty)};
	
	EXPECT_THAT(result, testing::IsFalse());
}

TEST_F(NonEmptyIntegerSinglyLinkedListTest,
       GivenPredicatesMatchingAtLeastOneElementEach_WhenContainsAll_ThenReturnsTrue) {
	const auto result {singlyLinkedList.containsAll({::Test::isThirty, ::Test::isForty})};
	
	EXPECT_THAT(result, testing::IsTrue());
}

TEST_F(NonEmptyIntegerSinglyLinkedListTest,
       GivenPredicatesNotMatchingAtLeastOneElementEach_WhenContainsAll_ThenReturnsFalse) {
	const auto result {singlyLinkedList.containsAll({::Test::isThirty, ::Test::isSixty})};
	
	EXPECT_THAT(result, testing::IsFalse());
}

TEST_F(NonEmptyIntegerSinglyLinkedListTest, WhenIsEmpty_ThenReturnsFalse) {
	const auto result {singlyLinkedList.isEmpty()};
	
	EXPECT_THAT(result, testing::IsFalse());
}
}