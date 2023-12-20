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

public:
	void insert(const ElementType& element) noexcept;
	void insert(ElementType&& element) noexcept;
	const std::optional<ElementType> findFirst(const ElementType& element) const noexcept;

private:
	BinaryTreeNode<ElementType>* insert(BinaryTreeNode<ElementType>* node, const ElementType& element);
	BinaryTreeNode<ElementType>* insert(BinaryTreeNode<ElementType>* node, ElementType&& element);
	const int getHeight(const BinaryTreeNode<ElementType>* const node) const noexcept;
	const int getBalanceFactor(const BinaryTreeNode<ElementType>* const node) const noexcept;
	BinaryTreeNode<ElementType>* rebalance(BinaryTreeNode<ElementType>* node);
	BinaryTreeNode<ElementType>* rotateLeft(BinaryTreeNode<ElementType>* node);
	BinaryTreeNode<ElementType>* rotateRight(BinaryTreeNode<ElementType>* node);

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

template<ElementTypeWithLessThanOperator ElementType>
void AVLTree<ElementType>::AVLTree::insert(const ElementType& element) noexcept {
	rootNode = insert(rootNode, element);
	++nodeCount;
}

template<ElementTypeWithLessThanOperator ElementType>
void AVLTree<ElementType>::AVLTree::insert(ElementType&& element) noexcept {
	rootNode = insert(rootNode, std::move(element));
	++nodeCount;
}

template<ElementTypeWithLessThanOperator ElementType>
BinaryTreeNode<ElementType>* AVLTree<ElementType>::insert(BinaryTreeNode<ElementType>* node,
                                                          const ElementType& element) {
	if (node == nullptr) {
		return new BinaryTreeNode<ElementType> {element};
	}
	
	if (const auto nodeElement {node->getElement()}; element < nodeElement) {
		node->setLeftChild(insert(node->getLeftChild(), element));
	} else {
		node->setRightChild(insert(node->getRightChild(), element));
	}
	
	return rebalance(node);
}

template<ElementTypeWithLessThanOperator ElementType>
BinaryTreeNode<ElementType>* AVLTree<ElementType>::insert(BinaryTreeNode<ElementType>* node, ElementType&& element) {
	if (node == nullptr) {
		return new BinaryTreeNode<ElementType> {std::move(element)};
	}
	
	if (const auto nodeElement {node->getElement()}; element < nodeElement) {
		node->setLeftChild(insert(node->getLeftChild(), std::move(element)));
	} else {
		node->setRightChild(insert(node->getRightChild(), std::move(element)));
	}
	
	return rebalance(node);
}

template<ElementTypeWithLessThanOperator ElementType>
const std::optional<ElementType> AVLTree<ElementType>::findFirst(const ElementType& element) const noexcept {
	if (rootNode == nullptr) {
		return std::nullopt;
	}
	
	auto* currentNode {rootNode};
	
	while (currentNode != nullptr) {
		const auto& currentNodeElement {currentNode->getElement()};
		
		if (element == currentNodeElement) {
			return currentNodeElement;
		}
		
		if (element < currentNodeElement) {
			currentNode = currentNode->getLeftChild();
		} else {
			currentNode = currentNode->getRightChild();
		}
	}
	
	return std::nullopt;
}

template<ElementTypeWithLessThanOperator ElementType>
const int AVLTree<ElementType>::AVLTree::getHeight(const BinaryTreeNode<ElementType>* const node) const noexcept {
	if (node == nullptr) {
		return -1;
	}
	
	const auto leftSubtreeHeight {getHeight(node->getLeftChild())};
	const auto rightSubtreeHeight {getHeight(node->getRightChild())};
	
	return std::max(leftSubtreeHeight, rightSubtreeHeight) + 1;
}

template<ElementTypeWithLessThanOperator ElementType>
const int AVLTree<ElementType>::getBalanceFactor(const BinaryTreeNode<ElementType>* node) const noexcept {
	if (node == nullptr) {
		return 0;
	}
	
	const auto leftSubtreeHeight {getHeight(node->getLeftChild())};
	const auto rightSubtreeHeight {getHeight(node->getRightChild())};
	
	return leftSubtreeHeight - rightSubtreeHeight;
}

template<ElementTypeWithLessThanOperator ElementType>
BinaryTreeNode<ElementType>* AVLTree<ElementType>::rebalance(BinaryTreeNode<ElementType>* node) {
	const auto balanceFactor {getBalanceFactor(node)};
	
	if (balanceFactor > 1) {
		if (const auto leftChildBalanceFactor {getBalanceFactor(node->getLeftChild())}; leftChildBalanceFactor < 0) {
			node->setLeftChild(rotateLeft(node->getLeftChild()));
		}
		
		return rotateRight(node);
	}
	
	if (balanceFactor < -1) {
		if (const auto rightChildBalanceFactor {getBalanceFactor(node->getRightChild())}; rightChildBalanceFactor > 0) {
			node->setRightChild(rotateRight(node->getRightChild()));
		}
		
		return rotateLeft(node);
	}
	
	return node;
}

template<ElementTypeWithLessThanOperator ElementType>
BinaryTreeNode<ElementType>* AVLTree<ElementType>::rotateLeft(BinaryTreeNode<ElementType>* node) {
	auto* newParent {node->getRightChild()};
	node->setRightChild(newParent->getLeftChild());
	newParent->setLeftChild(node);
	
	return newParent;
}

template<ElementTypeWithLessThanOperator ElementType>
BinaryTreeNode<ElementType>* AVLTree<ElementType>::rotateRight(BinaryTreeNode<ElementType>* node) {
	auto* newParent {node->getLeftChild()};
	node->setLeftChild(newParent->getRightChild());
	newParent->setRightChild(node);
	
	return newParent;
}
}
