#pragma once

#include"DataStructures/Trees/BinaryTreeNode.hpp"
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
class AVLTree final {
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
	InOrderIterator beginInOrder() noexcept;
	InOrderIterator endInOrder() noexcept;
	LevelOrderIterator beginLevelOrder() noexcept;
	LevelOrderIterator endLevelOrder() noexcept;
	PostOrderIterator beginPostOrder() noexcept;
	PostOrderIterator endPostOrder() noexcept;
	PreOrderIterator beginPreOrder() noexcept;
	PreOrderIterator endPreOrder() noexcept;

private:
	std::size_t nodeCount {0};
	BinaryTreeNode<ElementType>* rootNode {nullptr};
};

template<ElementTypeWithLessThanOperator ElementType>
AVLTree<ElementType>::ConstInOrderIterator AVLTree<ElementType>::AVLTree::cbeginInOrder() const noexcept {
	return ConstInOrderIterator {rootNode};
}

template<ElementTypeWithLessThanOperator ElementType>
AVLTree<ElementType>::ConstInOrderIterator AVLTree<ElementType>::AVLTree::cendInOrder() const noexcept {
	return ConstInOrderIterator {nullptr};
}

template<ElementTypeWithLessThanOperator ElementType>
AVLTree<ElementType>::ConstLevelOrderIterator AVLTree<ElementType>::AVLTree::cbeginLevelOrder() const noexcept {
	return ConstLevelOrderIterator {rootNode};
}

template<ElementTypeWithLessThanOperator ElementType>
AVLTree<ElementType>::ConstLevelOrderIterator AVLTree<ElementType>::AVLTree::cendLevelOrder() const noexcept {
	return ConstLevelOrderIterator {nullptr};
}

template<ElementTypeWithLessThanOperator ElementType>
AVLTree<ElementType>::ConstPostOrderIterator AVLTree<ElementType>::AVLTree::cbeginPostOrder() const noexcept {
	return ConstPostOrderIterator {rootNode};
}

template<ElementTypeWithLessThanOperator ElementType>
AVLTree<ElementType>::ConstPostOrderIterator AVLTree<ElementType>::AVLTree::cendPostOrder() const noexcept {
	return ConstPostOrderIterator {nullptr};
}

template<ElementTypeWithLessThanOperator ElementType>
AVLTree<ElementType>::ConstPreOrderIterator AVLTree<ElementType>::AVLTree::cbeginPreOrder() const noexcept {
	return ConstPreOrderIterator {rootNode};
}

template<ElementTypeWithLessThanOperator ElementType>
AVLTree<ElementType>::ConstPreOrderIterator AVLTree<ElementType>::AVLTree::cendPreOrder() const noexcept {
	return ConstPreOrderIterator {nullptr};
}

template<ElementTypeWithLessThanOperator ElementType>
AVLTree<ElementType>::InOrderIterator AVLTree<ElementType>::AVLTree::beginInOrder() noexcept {
	return InOrderIterator {rootNode};
}

template<ElementTypeWithLessThanOperator ElementType>
AVLTree<ElementType>::InOrderIterator AVLTree<ElementType>::AVLTree::endInOrder() noexcept {
	return InOrderIterator {nullptr};
}

template<ElementTypeWithLessThanOperator ElementType>
AVLTree<ElementType>::LevelOrderIterator AVLTree<ElementType>::AVLTree::beginLevelOrder() noexcept {
	return LevelOrderIterator {rootNode};
}

template<ElementTypeWithLessThanOperator ElementType>
AVLTree<ElementType>::LevelOrderIterator AVLTree<ElementType>::AVLTree::endLevelOrder() noexcept {
	return LevelOrderIterator {nullptr};
}

template<ElementTypeWithLessThanOperator ElementType>
AVLTree<ElementType>::PostOrderIterator AVLTree<ElementType>::AVLTree::beginPostOrder() noexcept {
	return PostOrderIterator {rootNode};
}

template<ElementTypeWithLessThanOperator ElementType>
AVLTree<ElementType>::PostOrderIterator AVLTree<ElementType>::AVLTree::endPostOrder() noexcept {
	return PostOrderIterator {nullptr};
}

template<ElementTypeWithLessThanOperator ElementType>
AVLTree<ElementType>::PreOrderIterator AVLTree<ElementType>::AVLTree::beginPreOrder() noexcept {
	return PreOrderIterator {rootNode};
}

template<ElementTypeWithLessThanOperator ElementType>
AVLTree<ElementType>::PreOrderIterator AVLTree<ElementType>::AVLTree::endPreOrder() noexcept {
	return PreOrderIterator {nullptr};
}
}
