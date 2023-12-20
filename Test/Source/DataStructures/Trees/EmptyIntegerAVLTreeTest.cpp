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

TEST_F(EmptyIntegerAVLTreeTest, GivenInteger_WhenInsert_ThenElementsAreInExpectedOrder) {
	avlTree.insert(10);
	
	auto iterator {avlTree.cbeginLevelOrder()};
	
	EXPECT_THAT(*iterator, testing::Eq(10));
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

TEST_F(EmptyIntegerAVLTreeTest, GivenInteger_WhenInsertAndLeftAndRightRotationsArePerformed_ThenElementsAreInExpectedOrder) {
	avlTree.insert(30);
	avlTree.insert(10);
	avlTree.insert(20);
	
	std::vector<int> elements {};
	for (auto iterator {avlTree.cbeginLevelOrder()}; iterator != avlTree.cendLevelOrder(); ++iterator) {
		elements.push_back(*iterator);
	}
	
	EXPECT_THAT(elements, testing::ElementsAre(20, 10, 30));
}

TEST_F(EmptyIntegerAVLTreeTest, GivenInteger_WhenInsertAndRightAndLeftRotationsArePerformed_ThenElementsAreInExpectedOrder) {
	avlTree.insert(10);
	avlTree.insert(30);
	avlTree.insert(20);
	
	std::vector<int> elements {};
	for (auto iterator {avlTree.cbeginLevelOrder()}; iterator != avlTree.cendLevelOrder(); ++iterator) {
		elements.push_back(*iterator);
	}
	
	EXPECT_THAT(elements, testing::ElementsAre(20, 10, 30));
}

TEST_F(EmptyIntegerAVLTreeTest, GivenInteger_WhenFindFirst_ThenReturnsNullOptional) {
	const auto result {avlTree.findFirst(10)};
	
	EXPECT_THAT(result, testing::Eq(std::nullopt));
}
}