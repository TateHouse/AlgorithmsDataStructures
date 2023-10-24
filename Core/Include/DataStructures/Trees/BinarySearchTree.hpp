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
	std::vector<ElementType> removeAll();

private:
	void insert(BinaryTreeNode<ElementType>* node);
	void removeAll(BinaryTreeNode<ElementType>* node, std::vector<ElementType>& elements);

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
	} else if (currentNode->getRightChild() == nullptr) {
		if (parentNode == nullptr) {
			rootNode = currentNode->getLeftChild();
		} else if (isLeftChild) {
			parentNode->setLeftChild(currentNode->getLeftChild());
		} else {
			parentNode->setRightChild(currentNode->getLeftChild());
		}
		
		delete currentNode;
	} else if (currentNode->getLeftChild() == nullptr) {
		if (parentNode == nullptr) {
			rootNode = currentNode->getRightChild();
		} else if (isLeftChild) {
			parentNode->setLeftChild(currentNode->getRightChild());
		} else {
			parentNode->setRightChild(currentNode->getRightChild());
		}
		
		delete currentNode;
	} else {
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
}