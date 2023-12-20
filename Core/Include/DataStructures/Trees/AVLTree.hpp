#pragma once

#include <functional>
#include <optional>
#include <vector>

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
	std::optional<ElementType> removeFirst(const ElementType& element);
	std::optional<ElementType> removeMinimum();
	std::optional<ElementType> removeMaximum();
	std::vector<ElementType> removeAll();
	const std::optional<ElementType> findFirst(const ElementType& element) const noexcept;
	const std::optional<ElementType> findMinimum() const noexcept;
	const std::optional<ElementType> findMaximum() const noexcept;
	
	template<typename ConstIteratorType>
	requires Iterators::AllowedConstIterator<ConstIteratorType, ElementType>
	void traverse(ConstIteratorType begin,
	              ConstIteratorType end,
	              const std::function<void(const ElementType&)>& function) const noexcept;
	
	template<typename IteratorType>
	requires Iterators::AllowedIterator<IteratorType, ElementType>
	void traverse(IteratorType begin,
	              IteratorType end,
	              const std::function<void(ElementType&)>& function) const noexcept;
	
	const bool contains(const ElementType& element) const noexcept;
	const bool isEmpty() const noexcept;

private:
	BinaryTreeNode<ElementType>* insert(BinaryTreeNode<ElementType>* node, const ElementType& element);
	BinaryTreeNode<ElementType>* insert(BinaryTreeNode<ElementType>* node, ElementType&& element);
	BinaryTreeNode<ElementType>* removeFirst(BinaryTreeNode<ElementType>* node,
	                                         const ElementType& element,
	                                         std::optional<ElementType>& removedElement);
	BinaryTreeNode<ElementType>* getInOrderSuccessor(BinaryTreeNode<ElementType>* node);
	BinaryTreeNode<ElementType>* removeMinimum(BinaryTreeNode<ElementType>* node,
	                                           std::optional<ElementType>& removedElement);
	BinaryTreeNode<ElementType>* removeMaximum(BinaryTreeNode<ElementType>* node,
	                                           std::optional<ElementType>& removedElement);
	void removeAll(BinaryTreeNode<ElementType>* node, std::vector<ElementType>& elements);
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
std::optional<ElementType> AVLTree<ElementType>::removeFirst(const ElementType& element) {
	std::optional<ElementType> removedElement;
	rootNode = removeFirst(rootNode, element, removedElement);
	
	if (removedElement.has_value()) {
		--nodeCount;
	}
	
	return removedElement;
}

template<ElementTypeWithLessThanOperator ElementType>
std::optional<ElementType> AVLTree<ElementType>::removeMinimum() {
	if (rootNode == nullptr) {
		return std::nullopt;
	}
	
	std::optional<ElementType> removedElement;
	rootNode = removeMinimum(rootNode, removedElement);
	
	if (removedElement.has_value()) {
		--nodeCount;
	}
	
	return removedElement;
}

template<ElementTypeWithLessThanOperator ElementType>
std::optional<ElementType> AVLTree<ElementType>::removeMaximum() {
	if (rootNode == nullptr) {
		return std::nullopt;
	}
	
	std::optional<ElementType> removedElement;
	rootNode = removeMaximum(rootNode, removedElement);
	
	if (removedElement.has_value()) {
		--nodeCount;
	}
	
	return removedElement;
}

template<ElementTypeWithLessThanOperator ElementType>
std::vector<ElementType> AVLTree<ElementType>::removeAll() {
	std::vector<ElementType> elements {};
	removeAll(rootNode, elements);
	rootNode = nullptr;
	nodeCount = 0;
	
	return elements;
}

template<ElementTypeWithLessThanOperator ElementType>
BinaryTreeNode<ElementType>* AVLTree<ElementType>::insert(BinaryTreeNode<ElementType>* node,
                                                          const ElementType& element) {
	if (node == nullptr) {
		return new BinaryTreeNode<ElementType> {element};
	}
	
	if (const auto& nodeElement {node->getElement()}; element < nodeElement) {
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
	
	if (const auto& nodeElement {node->getElement()}; element < nodeElement) {
		node->setLeftChild(insert(node->getLeftChild(), std::move(element)));
	} else {
		node->setRightChild(insert(node->getRightChild(), std::move(element)));
	}
	
	return rebalance(node);
}

template<ElementTypeWithLessThanOperator ElementType>
BinaryTreeNode<ElementType>* AVLTree<ElementType>::removeFirst(BinaryTreeNode<ElementType>* node,
                                                               const ElementType& element,
                                                               std::optional<ElementType>& removedElement) {
	if (node == nullptr) {
		return nullptr;
	}
	
	if (const auto& nodeElement {node->getElement()}; element < nodeElement) {
		node->setLeftChild(removeFirst(node->getLeftChild(), element, removedElement));
	} else if (element > nodeElement) {
		node->setRightChild(removeFirst(node->getRightChild(), element, removedElement));
	} else {
		removedElement = node->getElement();
		
		if (node->getLeftChild() != nullptr && node->getRightChild() != nullptr) {
			auto* inOrderSuccessorParent {node};
			auto* inOrderSuccessor {getInOrderSuccessor(node->getRightChild())};
			
			if (inOrderSuccessorParent != node) {
				inOrderSuccessorParent->setLeftChild(inOrderSuccessor->getRightChild());
			} else {
				inOrderSuccessorParent->setRightChild(inOrderSuccessor->getRightChild());
			}
			
			inOrderSuccessor->setLeftChild(node->getLeftChild());
			inOrderSuccessor->setRightChild(
					node->getRightChild() == inOrderSuccessor ? inOrderSuccessorParent : node->getRightChild());
			
			delete node;
			
			node = inOrderSuccessor;
		} else {
			
			auto* childNode {node->getLeftChild() != nullptr ? node->getLeftChild() : node->getRightChild()};
			
			delete node;
			
			node = childNode;
		}
	}
	
	if (node == nullptr) {
		return node;
	}
	
	return rebalance(node);
}

template<ElementTypeWithLessThanOperator ElementType>
BinaryTreeNode<ElementType>* AVLTree<ElementType>::getInOrderSuccessor(BinaryTreeNode<ElementType>* node) {
	auto* currentNode {node};
	
	while (currentNode != nullptr && currentNode->getLeftChild() != nullptr) {
		currentNode = currentNode->getLeftChild();
	}
	
	return currentNode;
}

template<ElementTypeWithLessThanOperator ElementType>
BinaryTreeNode<ElementType>* AVLTree<ElementType>::removeMinimum(BinaryTreeNode<ElementType>* node,
                                                                 std::optional<ElementType>& removedElement) {
	if (node == nullptr) {
		return nullptr;
	}
	
	if (node->getLeftChild() == nullptr) {
		removedElement = node->getElement();
		auto* rightChild {node->getRightChild()};
		delete node;
		
		return rightChild;
	}
	
	node->setLeftChild(removeMinimum(node->getLeftChild(), removedElement));
	
	return rebalance(node);
}

template<ElementTypeWithLessThanOperator ElementType>
BinaryTreeNode<ElementType>* AVLTree<ElementType>::removeMaximum(BinaryTreeNode<ElementType>* node,
                                                                 std::optional<ElementType>& removedElement) {
	if (node == nullptr) {
		return nullptr;
	}
	
	if (node->getRightChild() == nullptr) {
		removedElement = node->getElement();
		auto* leftChild {node->getLeftChild()};
		delete node;
		
		return leftChild;
	}
	
	node->setRightChild(removeMaximum(node->getRightChild(), removedElement));
	
	return rebalance(node);
}

template<ElementTypeWithLessThanOperator ElementType>
void AVLTree<ElementType>::removeAll(BinaryTreeNode<ElementType>* node, std::vector<ElementType>& elements) {
	if (node == nullptr) {
		return;
	}
	
	removeAll(node->getLeftChild(), elements);
	removeAll(node->getRightChild(), elements);
	
	elements.emplace_back(node->getElement());
	
	delete node;
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
const std::optional<ElementType> AVLTree<ElementType>::findMinimum() const noexcept {
	if (rootNode == nullptr) {
		return std::nullopt;
	}
	
	auto* currentNode {rootNode};
	
	while (currentNode->getLeftChild() != nullptr) {
		currentNode = currentNode->getLeftChild();
	}
	
	return currentNode->getElement();
}

template<ElementTypeWithLessThanOperator ElementType>
const std::optional<ElementType> AVLTree<ElementType>::findMaximum() const noexcept {
	if (rootNode == nullptr) {
		return std::nullopt;
	}
	
	auto* currentNode {rootNode};
	
	while (currentNode->getRightChild() != nullptr) {
		currentNode = currentNode->getRightChild();
	}
	
	return currentNode->getElement();
}

template<ElementTypeWithLessThanOperator ElementType>
template<typename ConstIteratorType>
requires Iterators::AllowedConstIterator<ConstIteratorType, ElementType>
void AVLTree<ElementType>::traverse(ConstIteratorType begin,
                                    ConstIteratorType end,
                                    const std::function<void(const ElementType&)>& function) const noexcept {
	std::for_each(begin, end, function);
}

template<ElementTypeWithLessThanOperator ElementType>
template<typename IteratorType>
requires Iterators::AllowedIterator<IteratorType, ElementType>
void AVLTree<ElementType>::traverse(IteratorType begin,
                                    IteratorType end,
                                    const std::function<void(ElementType&)>& function) const noexcept {
	std::for_each(begin, end, function);
}

template<ElementTypeWithLessThanOperator ElementType>
const bool AVLTree<ElementType>::contains(const ElementType& element) const noexcept {
	return findFirst(element).has_value();
}

template<ElementTypeWithLessThanOperator ElementType>
const bool AVLTree<ElementType>::isEmpty() const noexcept {
	return rootNode == nullptr && nodeCount == 0;
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
