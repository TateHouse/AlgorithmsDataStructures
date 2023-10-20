#pragma once

#include <functional>
#include <optional>
#include <vector>

#include "DataStructures/Queues/SinglyLinkedListQueue.hpp"
#include "DataStructures/Trees/BinaryTreeNode.hpp"
#include "DataStructures/Trees/Iterators/BinaryTreeConstInOrderIterator.hpp"
#include "DataStructures/Trees/Iterators/BinaryTreeConstLevelOrderIterator.hpp"
#include "DataStructures/Trees/Iterators/BinaryTreeConstPostOrderIterator.hpp"
#include "DataStructures/Trees/Iterators/BinaryTreeConstPreOrderIterator.hpp"
#include "DataStructures/Trees/Iterators/BinaryTreeInOrderIterator.hpp"
#include "DataStructures/Trees/Iterators/BinaryTreeLevelOrderIterator.hpp"
#include "DataStructures/Trees/Iterators/BinaryTreePostOrderIterator.hpp"
#include "DataStructures/Trees/Iterators/BinaryTreePreOrderIterator.hpp"

namespace Core::DataStructures::Trees {
template<typename ElementType>
class BinaryTree final {
public:
	BinaryTree() noexcept = default;

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
	std::optional<ElementType> removeFirst(const std::function<bool(const ElementType&)>& predicate);
	std::vector<ElementType> removeAll(BinaryTreeNode<ElementType>* node);

private:
	void insertLevelOrder(BinaryTreeNode<ElementType>* node);
	void removeAll(BinaryTreeNode<ElementType>* node, std::vector<ElementType>& elements);

private:
	std::size_t nodeCount {0};
	BinaryTreeNode<ElementType>* rootNode {nullptr};
};

template<typename ElementType>
BinaryTree<ElementType>::ConstInOrderIterator BinaryTree<ElementType>::cbeginInOrder() const noexcept {
	return ConstInOrderIterator(rootNode);
}

template<typename ElementType>
BinaryTree<ElementType>::ConstInOrderIterator BinaryTree<ElementType>::cendInOrder() const noexcept {
	return ConstInOrderIterator(nullptr);
}

template<typename ElementType>
BinaryTree<ElementType>::ConstLevelOrderIterator BinaryTree<ElementType>::cbeginLevelOrder() const noexcept {
	return ConstLevelOrderIterator(rootNode);
}

template<typename ElementType>
BinaryTree<ElementType>::ConstLevelOrderIterator BinaryTree<ElementType>::cendLevelOrder() const noexcept {
	return ConstLevelOrderIterator(nullptr);
}

template<typename ElementType>
BinaryTree<ElementType>::ConstPostOrderIterator BinaryTree<ElementType>::cbeginPostOrder() const noexcept {
	return ConstPostOrderIterator(rootNode);
}

template<typename ElementType>
BinaryTree<ElementType>::ConstPostOrderIterator BinaryTree<ElementType>::cendPostOrder() const noexcept {
	return ConstPostOrderIterator(nullptr);
}

template<typename ElementType>
BinaryTree<ElementType>::ConstPreOrderIterator BinaryTree<ElementType>::cbeginPreOrder() const noexcept {
	return ConstPreOrderIterator(rootNode);
}

template<typename ElementType>
BinaryTree<ElementType>::ConstPreOrderIterator BinaryTree<ElementType>::cendPreOrder() const noexcept {
	return ConstPreOrderIterator(nullptr);
}

template<typename ElementType>
BinaryTree<ElementType>::InOrderIterator BinaryTree<ElementType>::beginInOrder() const noexcept {
	return InOrderIterator(rootNode);
}

template<typename ElementType>
BinaryTree<ElementType>::InOrderIterator BinaryTree<ElementType>::endInOrder() const noexcept {
	return InOrderIterator(nullptr);
}

template<typename ElementType>
BinaryTree<ElementType>::LevelOrderIterator BinaryTree<ElementType>::beginLevelOrder() const noexcept {
	return LevelOrderIterator(rootNode);
}

template<typename ElementType>
BinaryTree<ElementType>::LevelOrderIterator BinaryTree<ElementType>::endLevelOrder() const noexcept {
	return LevelOrderIterator(nullptr);
}

template<typename ElementType>
BinaryTree<ElementType>::PostOrderIterator BinaryTree<ElementType>::beginPostOrder() const noexcept {
	return PostOrderIterator(rootNode);
}

template<typename ElementType>
BinaryTree<ElementType>::PostOrderIterator BinaryTree<ElementType>::endPostOrder() const noexcept {
	return PostOrderIterator(nullptr);
}

template<typename ElementType>
BinaryTree<ElementType>::PreOrderIterator BinaryTree<ElementType>::beginPreOrder() const noexcept {
	return PreOrderIterator(rootNode);
}

template<typename ElementType>
BinaryTree<ElementType>::PreOrderIterator BinaryTree<ElementType>::endPreOrder() const noexcept {
	return PreOrderIterator(nullptr);
}

template<typename ElementType>
void BinaryTree<ElementType>::insert(const ElementType& element) {
	auto* node {new BinaryTreeNode<ElementType>(element)};
	insertLevelOrder(node);
}

template<typename ElementType>
void BinaryTree<ElementType>::insert(ElementType&& element) {
	auto* node {new BinaryTreeNode<ElementType>(std::move(element))};
	insertLevelOrder(node);
}

template<typename ElementType>
std::optional<ElementType> BinaryTree<ElementType>::removeFirst(const std::function<bool(const ElementType&)>& predicate) {
	if (rootNode == nullptr) {
		return std::nullopt;
	}
	
	auto nodeQueue {Queues::SinglyLinkedListQueue<BinaryTreeNode<ElementType>*>()};
	nodeQueue.enqueue(rootNode);
	
	BinaryTreeNode<ElementType>* currentNode {nullptr};
	BinaryTreeNode<ElementType>* parentOfCurrentNode {nullptr};
	BinaryTreeNode<ElementType>* targetNode {nullptr};
	BinaryTreeNode<ElementType>* parentOfTargetNode {nullptr};
	BinaryTreeNode<ElementType>* parentOfDeepestNode {nullptr};
	auto isLastNodeLeftChild {false};
	
	while (!nodeQueue.isEmpty()) {
		auto optionalNode {nodeQueue.dequeue()};
		if (!optionalNode.has_value()) {
			continue;
		}
		
		currentNode = optionalNode.value();
		
		if (predicate(currentNode->getElement())) {
			targetNode = currentNode;
			parentOfTargetNode = parentOfCurrentNode;
		}
		
		if (auto leftChild {currentNode->getLeftChild()}; leftChild != nullptr) {
			nodeQueue.enqueue(leftChild);
			parentOfDeepestNode = currentNode;
			isLastNodeLeftChild = true;
		}
		
		if (auto rightChild {currentNode->getRightChild()}; rightChild != nullptr) {
			nodeQueue.enqueue(rightChild);
			parentOfDeepestNode = currentNode;
			isLastNodeLeftChild = false;
		}
		
		parentOfCurrentNode = currentNode;
	}
	
	if (targetNode == nullptr) {
		return std::nullopt;
	}
	
	const auto removedElement {targetNode->getElement()};
	
	BinaryTreeNode<ElementType>* node {nullptr};
	if (isLastNodeLeftChild) {
		node = new BinaryTreeNode<ElementType> {parentOfDeepestNode->getLeftChild()->getElement()};
	} else {
		node = new BinaryTreeNode<ElementType> {parentOfDeepestNode->getRightChild()->getElement()};
	}
	
	node->setLeftChild(targetNode->getLeftChild());
	node->setRightChild(targetNode->getRightChild());
	
	if (parentOfTargetNode != nullptr) {
		if (parentOfTargetNode->getLeftChild() == targetNode) {
			parentOfTargetNode->setLeftChild(node);
		} else {
			parentOfTargetNode->setRightChild(node);
		}
	} else {
		rootNode = node;
	}
	
	delete targetNode;
	
	if (isLastNodeLeftChild) {
		delete parentOfDeepestNode->getLeftChild();
		parentOfDeepestNode->setLeftChild(nullptr);
	} else {
		delete parentOfDeepestNode->getRightChild();
		parentOfDeepestNode->setRightChild(nullptr);
	}
	
	--nodeCount;
	
	return removedElement;
}

template<typename ElementType>
std::vector<ElementType> BinaryTree<ElementType>::removeAll(BinaryTreeNode<ElementType>* node) {
	std::vector<ElementType> elements {};
	removeAll(node, elements);
	rootNode = nullptr;
	nodeCount = 0;
	
	return elements;
}

template<typename ElementType>
void BinaryTree<ElementType>::insertLevelOrder(BinaryTreeNode<ElementType>* node) {
	if (rootNode == nullptr) {
		rootNode = node;
		++nodeCount;
		return;
	}
	
	auto nodeQueue {Queues::SinglyLinkedListQueue<BinaryTreeNode<ElementType>*>()};
	nodeQueue.enqueue(rootNode);
	
	auto currentLevelNodeCount {1};
	while (!nodeQueue.isEmpty()) {
		auto nextLevelNodeCount {0};
		
		for (std::size_t index {0}; index < currentLevelNodeCount; ++index) {
			auto optionalNode {nodeQueue.dequeue()};
			if (!optionalNode.has_value()) {
				continue;
			}
			
			auto* currentNode {optionalNode.value()};
			
			if (currentNode->getLeftChild() == nullptr) {
				currentNode->setLeftChild(node);
				++nodeCount;
				return;
			} else {
				nodeQueue.enqueue(currentNode->getLeftChild());
				++nextLevelNodeCount;
			}
			
			if (currentNode->getRightChild() == nullptr) {
				currentNode->setRightChild(node);
				++nodeCount;
				return;
			} else {
				nodeQueue.enqueue(currentNode->getRightChild());
				++nextLevelNodeCount;
			}
		}
		
		currentLevelNodeCount = nextLevelNodeCount;
	}
}

template<typename ElementType>
void BinaryTree<ElementType>::removeAll(BinaryTreeNode<ElementType>* node, std::vector<ElementType>& elements) {
	if (node == nullptr) {
		return;
	}
	
	removeAll(node->getLeftChild(), elements);
	removeAll(node->getRightChild(), elements);
	
	elements.emplace_back(node->getElement());
	
	delete node;
}
}