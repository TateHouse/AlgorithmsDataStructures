#pragma once

#include <functional>
#include <optional>
#include <vector>

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
	BinarySearchTree(const BinarySearchTree<ElementType>& other);
	BinarySearchTree(BinarySearchTree<ElementType>&& other) noexcept;

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

public:
	void insert(const ElementType& element);
	void insert(ElementType&& element);
	std::optional<ElementType> removeFirst(const ElementType& element);
	std::optional<ElementType> removeMinimum();
	std::optional<ElementType> removeMaximum();
	std::vector<ElementType> removeAll();
	std::optional<ElementType> findFirst(const ElementType& element) const noexcept;
	std::optional<ElementType> findMinimum() const noexcept;
	std::optional<ElementType> findMaximum() const noexcept;
	
	template<typename ConstIteratorType>
	requires Iterators::AllowedConstIterator<ConstIteratorType, ElementType>
	void traverse(ConstIteratorType begin,
	              ConstIteratorType end,
	              const std::function<void(const ElementType&)>& function) const noexcept;
	
	template<typename IteratorType>
	requires Iterators::AllowedIterator<IteratorType, ElementType>
	void traverse(IteratorType begin, IteratorType end, const std::function<void(ElementType&)>& function) noexcept;
	
	const bool contains(const ElementType& element) const noexcept;
	const bool isEmpty() const noexcept;
	const std::size_t getNodeCount() const noexcept;
	const int getHeight() const noexcept;

private:
	void insert(BinaryTreeNode<ElementType>* node);
	void removeLeafNode(BinaryTreeNode<ElementType>* currentNode,
	                    BinaryTreeNode<ElementType>* parentNode,
	                    const bool isLeftChild);
	void removeNodeWithOnlyRightChild(BinaryTreeNode<ElementType>* currentNode,
	                                  BinaryTreeNode<ElementType>* parentNode,
	                                  const bool isLeftChild);
	void removeNodeWithOnlyLeftChild(BinaryTreeNode<ElementType>* currentNode,
	                                 BinaryTreeNode<ElementType>* parentNode,
	                                 const bool isLeftChild);
	void removeNodeWithTwoChildren(BinaryTreeNode<ElementType>* currentNode);
	void removeAll(BinaryTreeNode<ElementType>* node, std::vector<ElementType>& elements);
	const int getHeight(BinaryTreeNode<ElementType>* node) const noexcept;

private:
	std::size_t nodeCount {0};
	BinaryTreeNode<ElementType>* rootNode {nullptr};
};

template<ElementTypeWithLessThanOperator ElementType>
BinarySearchTree<ElementType>::BinarySearchTree(const BinarySearchTree<ElementType>& other) {
	for (auto iterator {other.cbeginInOrder()}; iterator != other.cendInOrder(); ++iterator) {
		insert(*iterator);
	}
}

template<ElementTypeWithLessThanOperator ElementType>
BinarySearchTree<ElementType>::BinarySearchTree(BinarySearchTree<ElementType>&& other) noexcept :
		nodeCount {other.nodeCount}, rootNode {other.rootNode} {
	other.rootNode = nullptr;
	other.nodeCount = 0;
}

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

template<ElementTypeWithLessThanOperator ElementType>
void BinarySearchTree<ElementType>::insert(const ElementType& element) {
	auto* node {new BinaryTreeNode<ElementType> {element}};
	insert(node);
}

template<ElementTypeWithLessThanOperator ElementType>
void BinarySearchTree<ElementType>::insert(ElementType&& element) {
	auto* node {new BinaryTreeNode<ElementType> {std::move(element)}};
	insert(node);
}

template<ElementTypeWithLessThanOperator ElementType>
std::optional<ElementType> BinarySearchTree<ElementType>::removeFirst(const ElementType& element) {
	if (rootNode == nullptr) {
		return std::nullopt;
	}
	
	BinaryTreeNode<ElementType>* currentNode {rootNode};
	BinaryTreeNode<ElementType>* parentNode {nullptr};
	auto isLeftChild {false};
	
	while (currentNode != nullptr && currentNode->getElement() != element) {
		parentNode = currentNode;
		
		const auto& currentNodeElement {currentNode->getElement()};
		if (element < currentNodeElement) {
			currentNode = currentNode->getLeftChild();
			isLeftChild = true;
		} else {
			currentNode = currentNode->getRightChild();
			isLeftChild = false;
		}
	}
	
	if (currentNode == nullptr) {
		return std::nullopt;
	}
	
	const auto removedElement {currentNode->getElement()};
	
	if (currentNode->getLeftChild() == nullptr && currentNode->getRightChild() == nullptr) {
		removeLeafNode(currentNode, parentNode, isLeftChild);
	} else if (currentNode->getRightChild() == nullptr) {
		removeNodeWithOnlyLeftChild(currentNode, parentNode, isLeftChild);
	} else if (currentNode->getLeftChild() == nullptr) {
		removeNodeWithOnlyRightChild(currentNode, parentNode, isLeftChild);
	} else {
		removeNodeWithTwoChildren(currentNode);
	}
	
	--nodeCount;
	
	return removedElement;
}

template<ElementTypeWithLessThanOperator ElementType>
std::optional<ElementType> BinarySearchTree<ElementType>::removeMinimum() {
	if (rootNode == nullptr) {
		return std::nullopt;
	}
	
	BinaryTreeNode<ElementType>* currentNode {rootNode};
	BinaryTreeNode<ElementType>* parentNode {nullptr};
	
	while (currentNode->getLeftChild() != nullptr) {
		parentNode = currentNode;
		currentNode = currentNode->getLeftChild();
	}
	
	const auto removedElement {currentNode->getElement()};
	
	if (currentNode->getRightChild() == nullptr) {
		removeLeafNode(currentNode, parentNode, true);
	} else {
		removeNodeWithOnlyRightChild(currentNode, parentNode, true);
	}
	
	--nodeCount;
	
	return removedElement;
}

template<ElementTypeWithLessThanOperator ElementType>
std::optional<ElementType> BinarySearchTree<ElementType>::removeMaximum() {
	if (rootNode == nullptr) {
		return std::nullopt;
	}
	
	BinaryTreeNode<ElementType>* currentNode {rootNode};
	BinaryTreeNode<ElementType>* parentNode {nullptr};
	
	while (currentNode->getRightChild() != nullptr) {
		parentNode = currentNode;
		currentNode = currentNode->getRightChild();
	}
	
	const auto removedElement {currentNode->getElement()};
	
	if (currentNode->getLeftChild() == nullptr) {
		removeLeafNode(currentNode, parentNode, false);
	} else {
		removeNodeWithOnlyLeftChild(currentNode, parentNode, false);
	}
	
	--nodeCount;
	
	return removedElement;
}

template<ElementTypeWithLessThanOperator ElementType>
std::vector<ElementType> BinarySearchTree<ElementType>::removeAll() {
	std::vector<ElementType> elements;
	removeAll(rootNode, elements);
	rootNode = nullptr;
	nodeCount = 0;
	
	return elements;
}

template<ElementTypeWithLessThanOperator ElementType>
std::optional<ElementType> BinarySearchTree<ElementType>::findFirst(const ElementType& element) const noexcept {
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
std::optional<ElementType> BinarySearchTree<ElementType>::findMinimum() const noexcept {
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
std::optional<ElementType> BinarySearchTree<ElementType>::findMaximum() const noexcept {
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
void BinarySearchTree<ElementType>::traverse(ConstIteratorType begin,
                                             ConstIteratorType end,
                                             const std::function<void(const ElementType&)>& function) const noexcept {
	std::for_each(begin, end, function);
}

template<ElementTypeWithLessThanOperator ElementType>
template<typename IteratorType>
requires Iterators::AllowedIterator<IteratorType, ElementType>
void BinarySearchTree<ElementType>::traverse(IteratorType begin,
                                             IteratorType end,
                                             const std::function<void(ElementType&)>& function) noexcept {
	std::for_each(begin, end, function);
}

template<ElementTypeWithLessThanOperator ElementType>
const bool BinarySearchTree<ElementType>::contains(const ElementType& element) const noexcept {
	return findFirst(element).has_value();
}

template<ElementTypeWithLessThanOperator ElementType>
const bool BinarySearchTree<ElementType>::isEmpty() const noexcept {
	return rootNode == nullptr && nodeCount == 0;
}

template<ElementTypeWithLessThanOperator ElementType>
const std::size_t BinarySearchTree<ElementType>::getNodeCount() const noexcept {
	return nodeCount;
}

template<ElementTypeWithLessThanOperator ElementType>
const int BinarySearchTree<ElementType>::getHeight() const noexcept {
	return getHeight(rootNode);
}

template<ElementTypeWithLessThanOperator ElementType>
void BinarySearchTree<ElementType>::insert(BinaryTreeNode<ElementType>* node) {
	if (rootNode == nullptr) {
		rootNode = node;
		return;
	}
	
	const auto& nodeElement {node->getElement()};
	BinaryTreeNode<ElementType>* currentNode {rootNode};
	BinaryTreeNode<ElementType>* parentNode {nullptr};
	
	while (currentNode != nullptr) {
		parentNode = currentNode;
		
		const auto& currentNodeElement {currentNode->getElement()};
		if (nodeElement < currentNodeElement) {
			currentNode = currentNode->getLeftChild();
		} else {
			currentNode = currentNode->getRightChild();
		}
	}
	
	if (nodeElement < parentNode->getElement()) {
		parentNode->setLeftChild(node);
	} else {
		parentNode->setRightChild(node);
	}
	
	++nodeCount;
}

template<ElementTypeWithLessThanOperator ElementType>
void BinarySearchTree<ElementType>::removeLeafNode(BinaryTreeNode<ElementType>* currentNode,
                                                   BinaryTreeNode<ElementType>* parentNode,
                                                   const bool isLeftChild) {
	if (parentNode == nullptr) {
		rootNode = nullptr;
		delete currentNode;
	} else if (isLeftChild) {
		parentNode->setLeftChild(nullptr);
		delete currentNode;
	} else {
		parentNode->setRightChild(nullptr);
		delete currentNode;
	}
}

template<ElementTypeWithLessThanOperator ElementType>
void BinarySearchTree<ElementType>::removeNodeWithOnlyRightChild(BinaryTreeNode<ElementType>* currentNode,
                                                                 BinaryTreeNode<ElementType>* parentNode,
                                                                 const bool isLeftChild) {
	if (parentNode == nullptr) {
		rootNode = currentNode->getRightChild();
	} else if (isLeftChild) {
		parentNode->setLeftChild(currentNode->getRightChild());
	} else {
		parentNode->setRightChild(currentNode->getRightChild());
	}
	
	delete currentNode;
}

template<ElementTypeWithLessThanOperator ElementType>
void BinarySearchTree<ElementType>::removeNodeWithOnlyLeftChild(BinaryTreeNode<ElementType>* currentNode,
                                                                BinaryTreeNode<ElementType>* parentNode,
                                                                const bool isLeftChild) {
	if (parentNode == nullptr) {
		rootNode = currentNode->getLeftChild();
	} else if (isLeftChild) {
		parentNode->setLeftChild(currentNode->getLeftChild());
	} else {
		parentNode->setRightChild(currentNode->getLeftChild());
	}
	
	delete currentNode;
}

template<ElementTypeWithLessThanOperator ElementType>
void BinarySearchTree<ElementType>::removeNodeWithTwoChildren(BinaryTreeNode<ElementType>* currentNode) {
	BinaryTreeNode<ElementType>* successorNode {currentNode->getRightChild()};
	BinaryTreeNode<ElementType>* successorParentNode {currentNode};
	
	while (successorNode->getLeftChild() != nullptr) {
		successorParentNode = successorNode;
		successorNode = successorNode->getLeftChild();
	}
	
	if (successorParentNode == currentNode) {
		successorParentNode->setRightChild(successorNode->getRightChild());
	} else {
		successorParentNode->setLeftChild(successorNode->getRightChild());
	}
	
	currentNode->setElement(successorNode->getElement());
	delete successorNode;
}

template<ElementTypeWithLessThanOperator ElementType>
void BinarySearchTree<ElementType>::removeAll(BinaryTreeNode<ElementType>* node, std::vector<ElementType>& elements) {
	if (node == nullptr) {
		return;
	}
	
	removeAll(node->getLeftChild(), elements);
	removeAll(node->getRightChild(), elements);
	
	elements.emplace_back(node->getElement());
	
	delete node;
}

template<ElementTypeWithLessThanOperator ElementType>
const int BinarySearchTree<ElementType>::getHeight(BinaryTreeNode<ElementType>* node) const noexcept {
	if (node == nullptr) {
		return -1;
	}
	
	const auto leftSubtreeHeight {getHeight(node->getLeftChild())};
	const auto rightSubtreeHeight {getHeight(node->getRightChild())};
	
	return std::max(leftSubtreeHeight, rightSubtreeHeight) + 1;
}
}