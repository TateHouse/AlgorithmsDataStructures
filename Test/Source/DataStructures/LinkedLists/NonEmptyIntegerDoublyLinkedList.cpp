#include <gmock/gmock.h>

#include "DataStructures/LinkedLists/DoublyLinkedList.hpp"
#include "IntegerPredicates.hpp"

namespace Core::DataStructures::LinkedLists::Test {
class NonEmptyIntegerDoublyLinkedList : public testing::Test {
public:
	NonEmptyIntegerDoublyLinkedList() noexcept;
	~NonEmptyIntegerDoublyLinkedList() noexcept override = default;

protected:
	DoublyLinkedList<int> doublyLinkedList {};
};

NonEmptyIntegerDoublyLinkedList::NonEmptyIntegerDoublyLinkedList() noexcept {
	for (auto element {50}; element >= 10; element = element - 10) {
		doublyLinkedList.insertAtHead(element);
	}
}

TEST_F(NonEmptyIntegerDoublyLinkedList,
       GivenNonEmptyIntegerDoublyLinkedList_WhenCopyConstruct_ThenNewDoublyLinkedListIsEqualToOriginal) {
	const auto otherDoublyLinkedList {doublyLinkedList};
	
	EXPECT_THAT(otherDoublyLinkedList, testing::Eq(doublyLinkedList));
}

TEST_F(NonEmptyIntegerDoublyLinkedList,
       GivenNonEmptyIntegerDoublyLinkedList_WhenMoveConstruct_ThenNewDoublyLinkedListIsEqualToOriginal) {
	const auto otherDoublyLinkedList {std::move(doublyLinkedList)};
	
	EXPECT_THAT(otherDoublyLinkedList, testing::ElementsAre(10, 20, 30, 40, 50));
}

TEST_F(NonEmptyIntegerDoublyLinkedList,
       GivenNonEmptyIntegerDoublyLinkedList_WhenCopyAssign_ThenNewDoublyLinkedListIsEqualToOriginal) {
	auto otherDoublyLinkedList = doublyLinkedList;
	
	EXPECT_THAT(otherDoublyLinkedList, testing::Eq(doublyLinkedList));
}

TEST_F(NonEmptyIntegerDoublyLinkedList,
       GivenNonEmptyIntegerDoublyLinkedList_WhenMoveAssign_ThenNewDoublyLinkedListIsEqualToOriginal) {
	auto otherDoublyLinkedList = std::move(doublyLinkedList);
	
	EXPECT_THAT(otherDoublyLinkedList, testing::ElementsAre(10, 20, 30, 40, 50));
}

TEST_F(NonEmptyIntegerDoublyLinkedList, WhenIterateForward_ThenElementsAreIteratedInExpectedOrder) {
	const auto expectedElements {std::vector<int> {10, 20, 30, 40, 50}};
	auto elementIndex {0};
	
	for (const auto& element: doublyLinkedList) {
		EXPECT_THAT(element, testing::Eq(expectedElements[elementIndex]));
		++elementIndex;
	}
}

TEST_F(NonEmptyIntegerDoublyLinkedList, WhenConstIterateForward_ThenElementsAreIteratedInExpectedOrder) {
	const auto constDoubleLinkedList {doublyLinkedList};
	const auto expectedElements {std::vector<int> {10, 20, 30, 40, 50}};
	auto elementIndex {0};
	
	for (const auto& element: constDoubleLinkedList) {
		EXPECT_THAT(element, testing::Eq(expectedElements[elementIndex]));
		++elementIndex;
	}
}

TEST_F(NonEmptyIntegerDoublyLinkedList, WhenIterateBackward_ThenElementsAreIteratedInExpectedOrder) {
	const auto expectedElements {std::vector<int> {50, 40, 30, 20, 10}};
	auto elementIndex {0};
	
	for (auto iterator {doublyLinkedList.rbegin()}; iterator != doublyLinkedList.rend(); ++iterator) {
		EXPECT_THAT(*iterator, testing::Eq(expectedElements[elementIndex]));
		++elementIndex;
	}
}

TEST_F(NonEmptyIntegerDoublyLinkedList, WhenConstIterateBackward_ThenElementsAreIteratedInExpectedOrder) {
	const auto constDoubleLinkedList {doublyLinkedList};
	const auto expectedElements {std::vector<int> {50, 40, 30, 20, 10}};
	auto elementIndex {0};
	
	for (auto iterator {constDoubleLinkedList.rbegin()}; iterator != constDoubleLinkedList.rend(); ++iterator) {
		EXPECT_THAT(*iterator, testing::Eq(expectedElements[elementIndex]));
		++elementIndex;
	}
}

TEST_F(NonEmptyIntegerDoublyLinkedList,
       GivenTwoNonEqualIntegerDoublyLinkedListsOfDifferentSizes_WhenCompare_ThenReturnsFalse) {
	DoublyLinkedList<int> otherDoublyLinkedList {};
	doublyLinkedList.insertAtHead(10);
	
	EXPECT_THAT(doublyLinkedList, testing::Ne(otherDoublyLinkedList));
}

TEST_F(NonEmptyIntegerDoublyLinkedList,
       GivenTwoNonEqualIntegerDoublyLinkedListsOfSameSize_WhenCompare_ThenReturnsFalse) {
	DoublyLinkedList<int> otherDoublyLinkedList {};
	for (auto element {50}; element >= 10; element = element - 10) {
		otherDoublyLinkedList.insertAtTail(element);
	}
	
	EXPECT_THAT(doublyLinkedList, testing::Ne(otherDoublyLinkedList));
}

TEST_F(NonEmptyIntegerDoublyLinkedList, GivenTwoEqualNonEmptyIntegerDoublyLinkedLists_WhenCompare_ThenReturnsTrue) {
	DoublyLinkedList<int> otherDoublyLinkedList {};
	for (auto element {50}; element >= 10; element = element - 10) {
		otherDoublyLinkedList.insertAtHead(element);
	}
	
	EXPECT_THAT(doublyLinkedList, testing::Eq(otherDoublyLinkedList));
}

TEST_F(NonEmptyIntegerDoublyLinkedList, GivenInteger_WhenInsertAtHead_ThenElementsAreInExpectedOrder) {
	doublyLinkedList.insertAtHead(5);
	
	EXPECT_THAT(doublyLinkedList, testing::ElementsAre(5, 10, 20, 30, 40, 50));
}

TEST_F(NonEmptyIntegerDoublyLinkedList, GivenInteger_WhenInsertAtHead_ThenSizeIsIncremented) {
	doublyLinkedList.insertAtHead(5);
	const auto nodeCount {doublyLinkedList.getNodeCount()};
	
	EXPECT_THAT(nodeCount, testing::Eq(6));
}

TEST_F(NonEmptyIntegerDoublyLinkedList, GivenInteger_WhenInsertAtTail_ThenElementsAreInExpectedOrder) {
	doublyLinkedList.insertAtTail(60);
	
	EXPECT_THAT(doublyLinkedList, testing::ElementsAre(10, 20, 30, 40, 50, 60));
}

TEST_F(NonEmptyIntegerDoublyLinkedList, GivenInteger_WhenInsertAtTail_ThenSizeIsIncremented) {
	doublyLinkedList.insertAtTail(60);
	const auto nodeCount {doublyLinkedList.getNodeCount()};
	
	EXPECT_THAT(nodeCount, testing::Eq(6));
}

TEST_F(NonEmptyIntegerDoublyLinkedList, GivenIntegerAndValidIndex_WhenInsertAtIndex_ThenElementsAreInExpectedOrder) {
	doublyLinkedList.insertAtIndex(35, 3);
	
	EXPECT_THAT(doublyLinkedList, testing::ElementsAre(10, 20, 30, 35, 40, 50));
}

TEST_F(NonEmptyIntegerDoublyLinkedList, GivenIntegerAndInvalidIndex_WhenInsertAtIndex_ThenElementWasNotInserted) {
	doublyLinkedList.insertAtIndex(60, 6);
	
	EXPECT_THAT(doublyLinkedList, testing::ElementsAre(10, 20, 30, 40, 50));
}

TEST_F(NonEmptyIntegerDoublyLinkedList, GivenIntegerAndValidIndex_WhenInsertAtIndex_ThenSizeIsIncremented) {
	doublyLinkedList.insertAtIndex(35, 3);
	const auto nodeCount {doublyLinkedList.getNodeCount()};
	
	EXPECT_THAT(nodeCount, testing::Eq(6));
}

TEST_F(NonEmptyIntegerDoublyLinkedList, GivenIntegerAndValidIndex_WhenInsertAtIndex_ThenReturnsTrue) {
	const auto result {doublyLinkedList.insertAtIndex(35, 3)};
	
	EXPECT_THAT(result, testing::IsTrue());
}

TEST_F(NonEmptyIntegerDoublyLinkedList, GivenIntegerAndInvalidIndex_WhenInsertAtIndex_ThenReturnsFalse) {
	const auto result {doublyLinkedList.insertAtIndex(60, 10)};
	
	EXPECT_THAT(result, testing::IsFalse());
}

TEST_F(NonEmptyIntegerDoublyLinkedList, WhenRemoveAtHead_ThenElementsAreInExpectedOrder) {
	doublyLinkedList.removeAtHead();
	
	EXPECT_THAT(doublyLinkedList, testing::ElementsAre(20, 30, 40, 50));
}

TEST_F(NonEmptyIntegerDoublyLinkedList, WhenRemoveAtHead_ThenSizeIsDecremented) {
	doublyLinkedList.removeAtHead();
	const auto nodeCount {doublyLinkedList.getNodeCount()};
	
	EXPECT_THAT(nodeCount, testing::Eq(4));
}

TEST_F(NonEmptyIntegerDoublyLinkedList, WhenRemoveAtHead_ThenReturnsElement) {
	const auto result {doublyLinkedList.removeAtHead()};
	
	EXPECT_THAT(result, testing::Optional(10));
}

TEST_F(NonEmptyIntegerDoublyLinkedList, WhenRemoveAtTail_ThenElementsAreInExpectedOrder) {
	doublyLinkedList.removeAtTail();
	
	EXPECT_THAT(doublyLinkedList, testing::ElementsAre(10, 20, 30, 40));
}

TEST_F(NonEmptyIntegerDoublyLinkedList, WhenRemoveAtTail_ThenSizeIsDecremented) {
	doublyLinkedList.removeAtTail();
	const auto nodeCount {doublyLinkedList.getNodeCount()};
	
	EXPECT_THAT(nodeCount, testing::Eq(4));
}

TEST_F(NonEmptyIntegerDoublyLinkedList, WhenRemoveAtTail_ThenReturnsElement) {
	const auto result {doublyLinkedList.removeAtTail()};
	
	EXPECT_THAT(result, testing::Optional(50));
}

TEST_F(NonEmptyIntegerDoublyLinkedList, GivenValidIndex_WhenRemoveAtIndex_ThenElementsAreInExpectedOrder) {
	doublyLinkedList.removeAtIndex(2);
	
	EXPECT_THAT(doublyLinkedList, testing::ElementsAre(10, 20, 40, 50));
}

TEST_F(NonEmptyIntegerDoublyLinkedList, GivenInvalidIndex_WhenRemoveAtIndex_ThenElementsAreInExpectedOrder) {
	doublyLinkedList.removeAtIndex(10);
	
	EXPECT_THAT(doublyLinkedList, testing::ElementsAre(10, 20, 30, 40, 50));
}

TEST_F(NonEmptyIntegerDoublyLinkedList, GivenValidIndex_WhenRemoveAtIndex_ThenSizeIsDecremented) {
	doublyLinkedList.removeAtIndex(2);
	const auto nodeCount {doublyLinkedList.getNodeCount()};
	
	EXPECT_THAT(nodeCount, testing::Eq(4));
}

TEST_F(NonEmptyIntegerDoublyLinkedList, GivenValidIndex_WhenRemoveAtIndex_ThenReturnsElement) {
	const auto result {doublyLinkedList.removeAtIndex(2)};
	
	EXPECT_THAT(result, testing::Optional(30));
}

TEST_F(NonEmptyIntegerDoublyLinkedList, WhenRemoveAll_ThenElementsAreRemoved) {
	doublyLinkedList.removeAll();
	
	EXPECT_THAT(doublyLinkedList, testing::ElementsAre());
}

TEST_F(NonEmptyIntegerDoublyLinkedList, WhenRemoveAll_ThenReturnsVectorOfElements) {
	const auto result {doublyLinkedList.removeAll()};
	
	EXPECT_THAT(result, testing::ElementsAre(10, 20, 30, 40, 50));
}

TEST_F(NonEmptyIntegerDoublyLinkedList, WhenRemoveAll_ThenSizeIsZero) {
	doublyLinkedList.removeAll();
	const auto nodeCount {doublyLinkedList.getNodeCount()};
	
	EXPECT_THAT(nodeCount, testing::Eq(0));
}

TEST_F(NonEmptyIntegerDoublyLinkedList,
       GivenPredicateMatchingAtLeastOneElement_WhenFindFirstConst_ThenReturnsConstIterator) {
	const auto constDoublyLinkedList {doublyLinkedList};
	const auto result {constDoublyLinkedList.findFirst(::Test::isThirty)};
	
	auto expectedIterator {constDoublyLinkedList.cbegin()};
	std::advance(expectedIterator, 2);
	
	EXPECT_THAT(result, testing::Eq(expectedIterator));
}

TEST_F(NonEmptyIntegerDoublyLinkedList,
       GivenPredicateMatchingNoElements_WhenFindFirstConst_ThenReturnsConstEndIterator) {
	const auto constDoublyLinkedList {doublyLinkedList};
	const auto result {constDoublyLinkedList.findFirst(::Test::isSixty)};
	
	EXPECT_THAT(result, testing::Eq(constDoublyLinkedList.cend()));
}

TEST_F(NonEmptyIntegerDoublyLinkedList, GivenPredicateMatchingAtLeastOneElement_WhenFindFirst_ThenReturnsIterator) {
	const auto result {doublyLinkedList.findFirst(::Test::isThirty)};
	
	auto expectedIterator {doublyLinkedList.begin()};
	std::advance(expectedIterator, 2);
	
	EXPECT_THAT(result, testing::Eq(expectedIterator));
}

TEST_F(NonEmptyIntegerDoublyLinkedList, GivenPredicateMatchingNoElements_WhenFindFirst_ThenReturnsEndIterator) {
	const auto result {doublyLinkedList.findFirst(::Test::isSixty)};
	
	EXPECT_THAT(result, testing::Eq(doublyLinkedList.end()));
}

TEST_F(NonEmptyIntegerDoublyLinkedList,
       GivenPredicateMatchingAtLeastOneElement_WhenFindLastConst_ThenReturnsConstReverseIterator) {
	const auto constDoublyLinkedList {doublyLinkedList};
	const auto result {constDoublyLinkedList.findLast(::Test::isThirty)};
	
	auto expectedIterator {constDoublyLinkedList.crbegin()};
	std::advance(expectedIterator, 2);
	
	EXPECT_THAT(result, testing::Eq(expectedIterator));
}

TEST_F(NonEmptyIntegerDoublyLinkedList,
       GivenPredicateMatchingNoElements_WhenFindLastConst_ThenReturnsConstReverseEndIterator) {
	const auto constDoublyLinkedList {doublyLinkedList};
	const auto result {constDoublyLinkedList.findLast(::Test::isSixty)};
	
	EXPECT_THAT(result, testing::Eq(constDoublyLinkedList.crend()));
}

TEST_F(NonEmptyIntegerDoublyLinkedList,
       GivenPredicateMatchingAtLeastOneElement_WhenFindLast_ThenReturnsReverseIterator) {
	const auto result {doublyLinkedList.findLast(::Test::isThirty)};
	
	auto expectedIterator {doublyLinkedList.rbegin()};
	std::advance(expectedIterator, 2);
	
	EXPECT_THAT(result, testing::Eq(expectedIterator));
}

TEST_F(NonEmptyIntegerDoublyLinkedList, GivenPredicateMatchingNoElements_WhenFindLast_ThenReturnsReverseEndIterator) {
	const auto result {doublyLinkedList.findLast(::Test::isSixty)};
	
	EXPECT_THAT(result, testing::Eq(doublyLinkedList.rend()));
}

TEST_F(NonEmptyIntegerDoublyLinkedList, GivenNonEmptyIntegerDoublyLinkedList_WhenReverse_ThenElementsAreInExpectedOrder) {
	doublyLinkedList.reverse();
	
	EXPECT_THAT(doublyLinkedList, testing::ElementsAre(50, 40, 30, 20, 10));
}

TEST_F(NonEmptyIntegerDoublyLinkedList, GivenPredicateMatchingAtLeastOneElement_WhenContains_ThenReturnsTrue) {
	const auto result {doublyLinkedList.contains(::Test::isThirty)};
	
	EXPECT_THAT(result, testing::IsTrue());
}

TEST_F(NonEmptyIntegerDoublyLinkedList, GivenPredicateMatchingNoElements_WhenContains_ThenReturnsFalse) {
	const auto result {doublyLinkedList.contains(::Test::isSixty)};
	
	EXPECT_THAT(result, testing::IsFalse());
}

TEST_F(NonEmptyIntegerDoublyLinkedList, GivenPredicatesMatchingAtLeastOneElementEach_WhenContainsAll_ThenReturnsTrue) {
	const auto result {doublyLinkedList.containsAll({::Test::isThirty, ::Test::isForty})};
	
	EXPECT_THAT(result, testing::IsTrue());
}

TEST_F(NonEmptyIntegerDoublyLinkedList,
       GivenPredicatesNotMatchingAtLeastOneElementEach_WhenContainsAll_ThenReturnsFalse) {
	const auto result {doublyLinkedList.containsAll({::Test::isThirty, ::Test::isSixty})};
	
	EXPECT_THAT(result, testing::IsFalse());
}

TEST_F(NonEmptyIntegerDoublyLinkedList, WhenIsEmpty_ThenReturnsFalse) {
	const auto result {doublyLinkedList.isEmpty()};
	
	EXPECT_THAT(result, testing::IsFalse());
}
}