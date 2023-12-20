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

TEST_F(NonEmptyIntegerAVLTreeTest, GivenInteger_WhenInsertAndLeftAndRightRotationsArePerformed_ThenElementsAreInExpectedOrder) {
	avlTree.insert(-70);
	avlTree.insert(-60);
	
	std::vector<int> elements {};
	for (auto iterator {avlTree.cbeginLevelOrder()}; iterator != avlTree.cendLevelOrder(); ++iterator) {
		elements.push_back(*iterator);
	}
	
	EXPECT_THAT(elements, testing::ElementsAre(0, -20, 30, -60, -10, 10, 40, -70, -50, -5, 50));
}

TEST_F(NonEmptyIntegerAVLTreeTest, GivenInteger_WhenInsertAndRightAndLeftRotationsArePerformed_ThenElementsAreInExpectedOrder) {
	avlTree.insert(-7);
	
	std::vector<int> elements {};
	for (auto iterator {avlTree.cbeginLevelOrder()}; iterator != avlTree.cendLevelOrder(); ++iterator) {
		elements.push_back(*iterator);
	}
	
	EXPECT_THAT(elements, testing::ElementsAre(0, -20, 30, -50, -7, 10, 40, -10, -5, 50));
}
}