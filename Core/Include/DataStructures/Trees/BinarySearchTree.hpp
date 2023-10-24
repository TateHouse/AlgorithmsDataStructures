#pragma once

#include "DataStructures/Trees/BinaryTreeNode.hpp"
#include "DataStructures/Trees/Iterators/BinaryTreeConstInOrderIterator.hpp"
#include "DataStructures/Trees/Iterators/BinaryTreeConstLevelOrderIterator.hpp"
#include "DataStructures/Trees/Iterators/BinaryTreeConstPostOrderIterator.hpp"
#include "DataStructures/Trees/Iterators/BinaryTreeConstPreOrderIterator.hpp"
#include "DataStructures/Trees/Iterators/BinaryTreeInOrderIterator.hpp"
#include "DataStructures/Trees/Iterators/BinaryTreeIteratorConcepts.hpp"
#include "DataStructures/Trees/Iterators/BinaryTreeLevelOrderIterator.hpp"
#include "DataStructures/Trees/Iterators/BinaryTreePostOrderIterator.hpp"
#include "DataStructures/Trees/Iterators/BinaryTreePreOrderIterator.hpp"
#include "BinarySearchTreeConcepts.hpp"

namespace Core::DataStructures::Trees {
template<ElementTypeWithLessThanOperator ElementType>
class BinarySearchTree final {
public:
	BinarySearchTree() noexcept = default;

public:
	using value_type = ElementType;
	using ConstInOrderIterator = Iterators::BinaryTreeConstInOrderIterator<ElementType>;
	using ConstLevelOrderIterator = Iterators::BinaryTreeConstLevelOrderIterator<ElementType>;
	using ConstPostOrderIterator = Iterators::BinaryTreeConstPostOrderIterator<ElementType>;
	using ConstPreOrderIterator = Iterators::BinaryTreeConstPreOrderIterator<ElementType>;
	using InOrderIterator = Iterators::BinaryTreeInOrderIterator<ElementType>;
	using LevelOrderIterator = Iterators::BinaryTreeLevelOrderIterator<ElementType>;
	using PostOrderIterator = Iterators::BinaryTreePostOrderIterator<ElementType>;
	using PreOrderIterator = Iterators::BinaryTreePreOrderIterator<ElementType>;
	
	ConstInOrderIterator cbeginInOrder() const noexcept;
	ConstInOrderIterator cendInOrder() const noexcept;
	ConstLevelOrderIterator cbeginLevelOrder() const noexcept;
	ConstLevelOrderIterator cendLevelOrder() const noexcept;
	ConstPostOrderIterator cbeginPostOrder() const noexcept;
	ConstPostOrderIterator cendPostOrder() const noexcept;
	ConstPreOrderIterator cbeginPreOrder() const noexcept;
	ConstPreOrderIterator cendPreOrder() const noexcept;
	InOrderIterator beginInOrder() const noexcept;
	InOrderIterator endInOrder() const noexcept;
	LevelOrderIterator beginLevelOrder() const noexcept;
	LevelOrderIterator endLevelOrder() const noexcept;
	PostOrderIterator beginPostOrder() const noexcept;
	PostOrderIterator endPostOrder() const noexcept;
	PreOrderIterator beginPreOrder() const noexcept;
	PreOrderIterator endPreOrder() const noexcept;

private:
	std::size_t nodeCount {0};
	BinaryTreeNode<ElementType>* rootNode {nullptr};
};

template<ElementTypeWithLessThanOperator ElementType>
BinarySearchTree<ElementType>::ConstInOrderIterator BinarySearchTree<ElementType>::cbeginInOrder() const noexcept {
	return ConstInOrderIterator {rootNode};
}

template<ElementTypeWithLessThanOperator ElementType>
BinarySearchTree<ElementType>::ConstInOrderIterator BinarySearchTree<ElementType>::cendInOrder() const noexcept {
	return ConstInOrderIterator {nullptr};
}

template<ElementTypeWithLessThanOperator ElementType>
BinarySearchTree<ElementType>::ConstLevelOrderIterator BinarySearchTree<ElementType>::cbeginLevelOrder() const noexcept {
	return ConstLevelOrderIterator {rootNode};
}

template<ElementTypeWithLessThanOperator ElementType>
BinarySearchTree<ElementType>::ConstLevelOrderIterator BinarySearchTree<ElementType>::cendLevelOrder() const noexcept {
	return ConstLevelOrderIterator {nullptr};
}

template<ElementTypeWithLessThanOperator ElementType>
BinarySearchTree<ElementType>::ConstPostOrderIterator BinarySearchTree<ElementType>::cbeginPostOrder() const noexcept {
	return ConstPostOrderIterator {rootNode};
}

template<ElementTypeWithLessThanOperator ElementType>
BinarySearchTree<ElementType>::ConstPostOrderIterator BinarySearchTree<ElementType>::cendPostOrder() const noexcept {
	return ConstPostOrderIterator {nullptr};
}

template<ElementTypeWithLessThanOperator ElementType>
BinarySearchTree<ElementType>::ConstPreOrderIterator BinarySearchTree<ElementType>::cbeginPreOrder() const noexcept {
	return ConstPreOrderIterator {rootNode};
}

template<ElementTypeWithLessThanOperator ElementType>
BinarySearchTree<ElementType>::ConstPreOrderIterator BinarySearchTree<ElementType>::cendPreOrder() const noexcept {
	return ConstPreOrderIterator {nullptr};
}

template<ElementTypeWithLessThanOperator ElementType>
BinarySearchTree<ElementType>::InOrderIterator BinarySearchTree<ElementType>::beginInOrder() const noexcept {
	return InOrderIterator {rootNode};
}

template<ElementTypeWithLessThanOperator ElementType>
BinarySearchTree<ElementType>::InOrderIterator BinarySearchTree<ElementType>::endInOrder() const noexcept {
	return InOrderIterator {nullptr};
}

template<ElementTypeWithLessThanOperator ElementType>
BinarySearchTree<ElementType>::LevelOrderIterator BinarySearchTree<ElementType>::beginLevelOrder() const noexcept {
	return LevelOrderIterator {rootNode};
}

template<ElementTypeWithLessThanOperator ElementType>
BinarySearchTree<ElementType>::LevelOrderIterator BinarySearchTree<ElementType>::endLevelOrder() const noexcept {
	return LevelOrderIterator {nullptr};
}

template<ElementTypeWithLessThanOperator ElementType>
BinarySearchTree<ElementType>::PostOrderIterator BinarySearchTree<ElementType>::beginPostOrder() const noexcept {
	return PostOrderIterator {rootNode};
}

template<ElementTypeWithLessThanOperator ElementType>
BinarySearchTree<ElementType>::PostOrderIterator BinarySearchTree<ElementType>::endPostOrder() const noexcept {
	return PostOrderIterator {nullptr};
}

template<ElementTypeWithLessThanOperator ElementType>
BinarySearchTree<ElementType>::PreOrderIterator BinarySearchTree<ElementType>::beginPreOrder() const noexcept {
	return PreOrderIterator {rootNode};
}

template<ElementTypeWithLessThanOperator ElementType>
BinarySearchTree<ElementType>::PreOrderIterator BinarySearchTree<ElementType>::endPreOrder() const noexcept {
	return PreOrderIterator {nullptr};
}
}