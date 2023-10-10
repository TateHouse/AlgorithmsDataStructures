#include <gmock/gmock.h>

#include "DataStructures/LinkedLists/SinglyLinkedList.hpp"
#include "IntegerPredicates.hpp"

namespace Core::DataStructures::LinkedLists::Test {
class EmptyIntegerSinglyLinkedListTest : public testing::Test {
public:
	EmptyIntegerSinglyLinkedListTest() noexcept = default;
	~EmptyIntegerSinglyLinkedListTest() noexcept override = default;

protected:
	SinglyLinkedList<int> singlyLinkedList {};
};

TEST_F(EmptyIntegerSinglyLinkedListTest, GivenTwoEmptyIntegerSinglyLinkedLists_WhenCompare_ThenReturnsTrue) {
	SinglyLinkedList<int> otherSinglyLinkedList {};
	
	EXPECT_THAT(singlyLinkedList, testing::Eq(otherSinglyLinkedList));
}

TEST_F(EmptyIntegerSinglyLinkedListTest, GivenInteger_WhenInsertAtHead_ThenElementsAreInExpectedOrder) {
	singlyLinkedList.insertAtHead(10);
	
	EXPECT_THAT(singlyLinkedList, testing::ElementsAre(10));
}

TEST_F(EmptyIntegerSinglyLinkedListTest, GivenInteger_WhenInsertAtHead_ThenSizeInIncremented) {
	singlyLinkedList.insertAtHead(10);
	const auto nodeCount {singlyLinkedList.getNodeCount()};
	
	EXPECT_THAT(nodeCount, testing::Eq(1));
}

TEST_F(EmptyIntegerSinglyLinkedListTest, GivenInteger_WhenInsertAtTail_ThenElementsAreInExpectedOrder) {
	singlyLinkedList.insertAtTail(10);
	
	EXPECT_THAT(singlyLinkedList, testing::ElementsAre(10));
}

TEST_F(EmptyIntegerSinglyLinkedListTest, GivenInteger_WhenInsertAtTail_ThenSizeInIncremented) {
	singlyLinkedList.insertAtTail(10);
	const auto nodeCount {singlyLinkedList.getNodeCount()};
	
	EXPECT_THAT(nodeCount, testing::Eq(1));
}

TEST_F(EmptyIntegerSinglyLinkedListTest, GivenIntegerAndValidIndex_WhenInsertAtIndex_ThenElementsAreInExpectedOrder) {
	singlyLinkedList.insertAtIndex(10, 0);
	
	EXPECT_THAT(singlyLinkedList, testing::ElementsAre(10));
}

TEST_F(EmptyIntegerSinglyLinkedListTest, GivenIntegerAndInvalidIndex_WhenInsertAtIndex_ThenElementWasNotInserted) {
	singlyLinkedList.insertAtIndex(10, 5);
	
	EXPECT_THAT(singlyLinkedList, testing::ElementsAre());
}

TEST_F(EmptyIntegerSinglyLinkedListTest, GivenIntegerAndValidIndex_WhenInsertAtIndex_ThenSizeInIncremented) {
	singlyLinkedList.insertAtIndex(10, 0);
	const auto nodeCount {singlyLinkedList.getNodeCount()};
	
	EXPECT_THAT(nodeCount, testing::Eq(1));
}

TEST_F(EmptyIntegerSinglyLinkedListTest, GivenIntegerAndValidIndex_WhenInsertAtIndex_ThenReturnsTrue) {
	const auto result {singlyLinkedList.insertAtIndex(10, 0)};
	
	EXPECT_THAT(result, testing::IsTrue());
}

TEST_F(EmptyIntegerSinglyLinkedListTest, GivenIntegerAndInvalidIndex_WhenInsertAtIndex_ThenReturnsFalse) {
	const auto result {singlyLinkedList.insertAtIndex(10, 5)};
	
	EXPECT_THAT(result, testing::IsFalse());
}

TEST_F(EmptyIntegerSinglyLinkedListTest, WhenRemoveAtHead_ThenReturnsNullOptional) {
	const auto result {singlyLinkedList.removeAtHead()};
	
	EXPECT_THAT(result, testing::Eq(std::nullopt));
}

TEST_F(EmptyIntegerSinglyLinkedListTest, WhenRemoveAtHead_ThenSizeIsNotDecremented) {
	singlyLinkedList.removeAtHead();
	const auto nodeCount {singlyLinkedList.getNodeCount()};
	
	EXPECT_THAT(nodeCount, testing::Eq(0));
}

TEST_F(EmptyIntegerSinglyLinkedListTest, WhenRemoveAtTail_ThenReturnsNullOptional) {
	const auto result {singlyLinkedList.removeAtTail()};
	
	EXPECT_THAT(result, testing::Eq(std::nullopt));
}

TEST_F(EmptyIntegerSinglyLinkedListTest, WhenRemoveAtTail_ThenSizeIsNotDecremented) {
	singlyLinkedList.removeAtTail();
	const auto nodeCount {singlyLinkedList.getNodeCount()};
	
	EXPECT_THAT(nodeCount, testing::Eq(0));
}

TEST_F(EmptyIntegerSinglyLinkedListTest, GivenValidIndex_WhenRemoveAtIndex_ThenReturnsNullOptional) {
	const auto result {singlyLinkedList.removeAtIndex(0)};
	
	EXPECT_THAT(result, testing::Eq(std::nullopt));
}

TEST_F(EmptyIntegerSinglyLinkedListTest, GivenValidIndex_WhenRemoveAtIndex_ThenSizeIsNotDecremented) {
	singlyLinkedList.removeAtIndex(0);
	const auto nodeCount {singlyLinkedList.getNodeCount()};
	
	EXPECT_THAT(nodeCount, testing::Eq(0));
}

TEST_F(EmptyIntegerSinglyLinkedListTest, WhenRemoveAll_ThenReturnsEmptyVector) {
	const auto result {singlyLinkedList.removeAll()};
	
	EXPECT_THAT(result, testing::IsEmpty());
}

TEST_F(EmptyIntegerSinglyLinkedListTest, WhenRemoveAll_ThenSizeIsNotDecremented) {
	singlyLinkedList.removeAll();
	const auto nodeCount {singlyLinkedList.getNodeCount()};
	
	EXPECT_THAT(nodeCount, testing::Eq(0));
}

TEST_F(EmptyIntegerSinglyLinkedListTest, GivenPredicate_WhenFindFirstConst_ThenReturnsConstEndIterator) {
	const auto result {singlyLinkedList.findFirst(::Test::isTen)};
	
	EXPECT_THAT(result, testing::Eq(singlyLinkedList.end()));
}

TEST_F(EmptyIntegerSinglyLinkedListTest, GivenPredicate_WhenFindFirst_ThenReturnsEndIterator) {
	const auto result {singlyLinkedList.findFirst(::Test::isTen)};
	
	EXPECT_THAT(result, testing::Eq(singlyLinkedList.end()));
}

TEST_F(EmptyIntegerSinglyLinkedListTest, GivenPredicate_WhenContains_ThenReturnsFalse) {
	const auto result {singlyLinkedList.contains(::Test::isTen)};
	
	EXPECT_THAT(result, testing::IsFalse());
}

TEST_F(EmptyIntegerSinglyLinkedListTest, GivenPredicates_WhenContainsAll_ThenReturnsFalse) {
	const auto result {singlyLinkedList.containsAll({::Test::isTen, ::Test::isTwenty})};
	
	EXPECT_THAT(result, testing::IsFalse());
}

TEST_F(EmptyIntegerSinglyLinkedListTest, WhenIsEmpty_ThenReturnsTrue) {
	const auto result {singlyLinkedList.isEmpty()};
	
	EXPECT_THAT(result, testing::IsTrue());
}
}