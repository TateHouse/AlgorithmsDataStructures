#include <gmock/gmock.h>

#include "DataStructures/LinkedLists/DoublyLinkedList.hpp"
#include "IntegerPredicates.hpp"

namespace Core::DataStructures::LinkedLists::Test {
class EmptyIntegerDoublyLinkedListTest : public testing::Test {
public:
	EmptyIntegerDoublyLinkedListTest() noexcept = default;
	~EmptyIntegerDoublyLinkedListTest() noexcept override = default;
	
protected:
	DoublyLinkedList<int> doublyLinkedList {};
};

TEST_F(EmptyIntegerDoublyLinkedListTest, GivenTwoEmptyIntegerDoublyLinkedLists_WhenCompare_ThenReturnsTrue) {
	DoublyLinkedList<int> otherDoublyLinkedList {};
	
	EXPECT_THAT(doublyLinkedList, testing::Eq(otherDoublyLinkedList));
}

TEST_F(EmptyIntegerDoublyLinkedListTest, GivenInteger_WhenInsertAtHead_ThenElementsAreInExpectedOrder) {
	doublyLinkedList.insertAtHead(10);
	
	EXPECT_THAT(doublyLinkedList, testing::ElementsAre(10));
}

TEST_F(EmptyIntegerDoublyLinkedListTest, GivenInteger_WhenInsertAtHead_ThenSizeInIncremented) {
	doublyLinkedList.insertAtHead(10);
	const auto nodeCount {doublyLinkedList.getNodeCount()};
	
	EXPECT_THAT(nodeCount, testing::Eq(1));
}

TEST_F(EmptyIntegerDoublyLinkedListTest, GivenInteger_WhenInsertAtTail_ThenElementsAreInExpectedOrder) {
	doublyLinkedList.insertAtTail(10);
	
	EXPECT_THAT(doublyLinkedList, testing::ElementsAre(10));
}

TEST_F(EmptyIntegerDoublyLinkedListTest, GivenInteger_WhenInsertAtTail_ThenSizeInIncremented) {
	doublyLinkedList.insertAtTail(10);
	const auto nodeCount {doublyLinkedList.getNodeCount()};
	
	EXPECT_THAT(nodeCount, testing::Eq(1));
}

TEST_F(EmptyIntegerDoublyLinkedListTest, GivenIntegerAndValidIndex_WhenInsertAtIndex_ThenElementsAreInExpectedOrder) {
	doublyLinkedList.insertAtIndex(10, 0);
	
	EXPECT_THAT(doublyLinkedList, testing::ElementsAre(10));
}

TEST_F(EmptyIntegerDoublyLinkedListTest, GivenIntegerAndInvalidIndex_WhenInsertAtIndex_ThenElementWasNotInserted) {
	doublyLinkedList.insertAtIndex(10, 5);
	
	EXPECT_THAT(doublyLinkedList, testing::ElementsAre());
}

TEST_F(EmptyIntegerDoublyLinkedListTest, GivenIntegerAndValidIndex_WhenInsertAtIndex_ThenSizeInIncremented) {
	doublyLinkedList.insertAtIndex(10, 0);
	const auto nodeCount {doublyLinkedList.getNodeCount()};
	
	EXPECT_THAT(nodeCount, testing::Eq(1));
}

TEST_F(EmptyIntegerDoublyLinkedListTest, GivenIntegerAndValidIndex_WhenInsertAtIndex_ThenReturnsTrue) {
	const auto insertAtIndex {doublyLinkedList.insertAtIndex(10, 0)};
	
	EXPECT_THAT(insertAtIndex, testing::IsTrue());
}

TEST_F(EmptyIntegerDoublyLinkedListTest, GivenIntegerAndInvalidIndex_WhenInsertAtIndex_ThenReturnsFalse) {
	const auto insertAtIndex {doublyLinkedList.insertAtIndex(10, 5)};
	
	EXPECT_THAT(insertAtIndex, testing::IsFalse());
}

TEST_F(EmptyIntegerDoublyLinkedListTest, WhenRemoveAtHead_ThenReturnsNullOptional) {
	const auto removedElement {doublyLinkedList.removeAtHead()};
	
	EXPECT_THAT(removedElement, testing::Eq(std::nullopt));
}

TEST_F(EmptyIntegerDoublyLinkedListTest, WhenRemovAtHead_ThenSizeIsNotDecremented) {
	doublyLinkedList.removeAtHead();
	const auto nodeCount {doublyLinkedList.getNodeCount()};
	
	EXPECT_THAT(nodeCount, testing::Eq(0));
}

TEST_F(EmptyIntegerDoublyLinkedListTest, WhenRemoveAtTail_ThenReturnsNullOptional) {
	const auto removedElement {doublyLinkedList.removeAtTail()};
	
	EXPECT_THAT(removedElement, testing::Eq(std::nullopt));
}

TEST_F(EmptyIntegerDoublyLinkedListTest, WhenRemoveAtTail_ThenSizeIsNotDecremented) {
	doublyLinkedList.removeAtTail();
	const auto nodeCount {doublyLinkedList.getNodeCount()};
	
	EXPECT_THAT(nodeCount, testing::Eq(0));
}

TEST_F(EmptyIntegerDoublyLinkedListTest, GivenValidIndex_WhenRemoveAtIndex_ThenReturnsNullOptional) {
	const auto removedElement {doublyLinkedList.removeAtIndex(0)};
	
	EXPECT_THAT(removedElement, testing::Eq(std::nullopt));
}

TEST_F(EmptyIntegerDoublyLinkedListTest, GivenValidIndex_WhenRemoveAtIndex_ThenSizeIsNotDecremented) {
	doublyLinkedList.removeAtIndex(0);
	const auto nodeCount {doublyLinkedList.getNodeCount()};
	
	EXPECT_THAT(nodeCount, testing::Eq(0));
}

TEST_F(EmptyIntegerDoublyLinkedListTest, WhenRemoveAll_ThenReturnsEmptyVector) {
	const auto removedElements {doublyLinkedList.removeAll()};
	
	EXPECT_THAT(removedElements, testing::IsEmpty());
}

TEST_F(EmptyIntegerDoublyLinkedListTest, WhenRemoveAll_ThenSizeIsNotDecremented) {
	doublyLinkedList.removeAll();
	const auto nodeCount {doublyLinkedList.getNodeCount()};
	
	EXPECT_THAT(nodeCount, testing::Eq(0));
}

TEST_F(EmptyIntegerDoublyLinkedListTest, GivenPredicate_WhenFindFirstConst_ThenReturnsConstEndIterator) {
	const auto constSinglyLinkedList {doublyLinkedList};
	const auto result {constSinglyLinkedList.findFirst(::Test::isTen)};
	
	EXPECT_THAT(result, testing::Eq(doublyLinkedList.cend()));
}

TEST_F(EmptyIntegerDoublyLinkedListTest, GivenPredicate_WhenFindFirst_ThenReturnsEndIterator) {
	const auto result {doublyLinkedList.findFirst(::Test::isTen)};
	
	EXPECT_THAT(result, testing::Eq(doublyLinkedList.end()));
}

TEST_F(EmptyIntegerDoublyLinkedListTest, GivenPredicate_WhenFindLastConst_ThenReturnsConstReverseEndIterator) {
	const auto constSinglyLinkedList {doublyLinkedList};
	const auto result {constSinglyLinkedList.findLast(::Test::isTen)};
	
	EXPECT_THAT(result, testing::Eq(doublyLinkedList.crend()));
}

TEST_F(EmptyIntegerDoublyLinkedListTest, GivenPredicate_WhenFindLast_ThenReturnsReverseEndIterator) {
	const auto result {doublyLinkedList.findLast(::Test::isTen)};
	
	EXPECT_THAT(result, testing::Eq(doublyLinkedList.rend()));
}

TEST_F(EmptyIntegerDoublyLinkedListTest, GivenPredicate_WhenContains_ThenReturnsFalse) {
	const auto result {doublyLinkedList.contains(::Test::isTen)};
	
	EXPECT_THAT(result, testing::IsFalse());
}

TEST_F(EmptyIntegerDoublyLinkedListTest, GivenPredicates_WhenContainsAll_ThenReturnsFalse) {
	const auto result {doublyLinkedList.containsAll({::Test::isTen, ::Test::isTwenty})};
	
	EXPECT_THAT(result, testing::IsFalse());
}

TEST_F(EmptyIntegerDoublyLinkedListTest, WhenIsEmpty_ThenReturnsTrue) {
	const auto result {doublyLinkedList.isEmpty()};
	
	EXPECT_THAT(result, testing::IsTrue());
}
}