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
#include "DataStructures/Trees/Iterators/BinaryTreeIteratorConcepts.hpp"
#include "DataStructures/Trees/Iterators/BinaryTreeLevelOrderIterator.hpp"
#include "DataStructures/Trees/Iterators/BinaryTreePostOrderIterator.hpp"
#include "DataStructures/Trees/Iterators/BinaryTreePreOrderIterator.hpp"

namespace Core::DataStructures::Trees {
/**
 * @brief A binary tree.
 * @class BinaryTree
 * @tparam ElementType: The type of the elements in the binary tree.
 */
template<typename ElementType>
class BinaryTree final {
public:
	/**
	 * @brief Instantiates a new binary tree with no nodes.
	 */
	BinaryTree() noexcept = default;
	
	/**
	 * @brief Instantiates a new binary tree by copying another binary tree.
	 * @param other: The binary tree to copy.
	 */
	BinaryTree(const BinaryTree<ElementType>& other);
	
	/**
	 * @brief Instantiates a new binary tree by moving another binary tree.
	 * @param other: The binary tree to move.
	 */
	BinaryTree(BinaryTree<ElementType>&& other) noexcept;
	
	/**
	 * @brief Destroys the binary tree.
	 */
	~BinaryTree() noexcept;

public:
	/**
	 * @brief Assigns another binary tree to this binary tree by copying it.
	 * @param other: The binary tree to copy.
	 * @return A reference to this binary tree.
	 */
	BinaryTree<ElementType>& operator=(const BinaryTree<ElementType>& other);
	
	/**
	 * @brief Assigns another binary tree to this binary tree by moving it.
	 * @param other: The binary tree to move.
	 * @return A reference to this binary tree.
	 */
	BinaryTree<ElementType>& operator=(BinaryTree<ElementType>&& other) noexcept;
	
	/**
	 * @brief Checks if another binary tree is equal to this binary tree.
	 * @details Two binary trees are equal if they have the same number of nodes and the same elements in the same order.
	 * @param other: The binary tree to check.
	 * @return True if the other binary tree is equal to this binary tree, false otherwise.
	 */
	const bool operator==(const BinaryTree<ElementType>& other) const noexcept;

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
	
	/**
	 * @brief Gets a const in-order iterator to the first node in the binary tree.
	 * @return A const in-order iterator to the first node in the binary tree.
	 */
	ConstInOrderIterator cbeginInOrder() const noexcept;
	
	/**
	 * @brief Gets a const in-order iterator to the node after the last node in the binary tree.
	 * @return A const in-order iterator to the node after the last node in the binary tree.
	 */
	ConstInOrderIterator cendInOrder() const noexcept;
	
	/**
	 * @brief Gets a const level-order iterator to the first node in the binary tree.
	 * @return A const level-order iterator to the first node in the binary tree.
	 */
	ConstLevelOrderIterator cbeginLevelOrder() const noexcept;
	
	/**
	 * @brief Gets a const level-order iterator to the node after the last node in the binary tree.
	 * @return A const level-order iterator to the node after the last node in the binary tree.
	 */
	ConstLevelOrderIterator cendLevelOrder() const noexcept;
	
	/**
	 * @brief Gets a const post-order iterator to the first node in the binary tree.
	 * @return A const post-order iterator to the first node in the binary tree.
	 */
	ConstPostOrderIterator cbeginPostOrder() const noexcept;
	
	/**
	 * @brief Gets a const post-order iterator to the node after the last node in the binary tree.
	 * @return A const post-order iterator to the node after the last node in the binary tree.
	 */
	ConstPostOrderIterator cendPostOrder() const noexcept;
	
	/**
	 * @brief Gets a const pre-order iterator to the first node in the binary tree.
	 * @return A const pre-order iterator to the first node in the binary tree.
	 */
	ConstPreOrderIterator cbeginPreOrder() const noexcept;
	
	/**
	 * @brief Gets a const pre-order iterator to the node after the last node in the binary tree.
	 * @return A const pre-order iterator to the node after the last node in the binary tree.
	 */
	ConstPreOrderIterator cendPreOrder() const noexcept;
	
	/**
	 * @brief Gets an in-order iterator to the first node in the binary tree.
	 * @return An in-order iterator to the first node in the binary tree.
	 */
	InOrderIterator beginInOrder() const noexcept;
	
	/**
	 * @brief Gets an in-order iterator to the node after the last node in the binary tree.
	 * @return An in-order iterator to the node after the last node in the binary tree.
	 */
	InOrderIterator endInOrder() const noexcept;
	
	/**
	 * @brief Gets a level-order iterator to the first node in the binary tree.
	 * @return A level-order iterator to the first node in the binary tree.
	 */
	LevelOrderIterator beginLevelOrder() const noexcept;
	
	/**
	 * @brief Gets a level-order iterator to the node after the last node in the binary tree.
	 * @return A level-order iterator to the node after the last node in the binary tree.
	 */
	LevelOrderIterator endLevelOrder() const noexcept;
	
	/**
	 * @brief Gets a post-order iterator to the first node in the binary tree.
	 * @return A post-order iterator to the first node in the binary tree.
	 */
	PostOrderIterator beginPostOrder() const noexcept;
	
	/**
	 * @brief Gets a post-order iterator to the node after the last node in the binary tree.
	 * @return A post-order iterator to the node after the last node in the binary tree.
	 */
	PostOrderIterator endPostOrder() const noexcept;
	
	/**
	 * @brief Gets a pre-order iterator to the first node in the binary tree.
	 * @return A pre-order iterator to the first node in the binary tree.
	 */
	PreOrderIterator beginPreOrder() const noexcept;
	
	/**
	 * @brief Gets a pre-order iterator to the node after the last node in the binary tree.
	 * @return A pre-order iterator to the node after the last node in the binary tree.
	 */
	PreOrderIterator endPreOrder() const noexcept;

public:
	/**
	 * @brief Inserts an element into the binary tree using copy semantics.
	 * @details The elements are inserted in level-order.
	 * @param element: The element to insert.
	 */
	void insert(const ElementType& element);
	
	/**
	 * @brief Inserts an element into the binary tree using move semantics.
	 * @details The elements are inserted in level-order.
	 * @param element: The element to insert.
	 */
	void insert(ElementType&& element);
	
	/**
	 * @brief Removes the first element in the binary tree that satisfies a predicate.
	 * @details The elements are traversed in level-order.
	 * @param predicate: The predicate to satisfy.
	 * @return The removed element if it exists, std::nullopt otherwise.
	 */
	std::optional<ElementType> removeFirst(const std::function<bool(const ElementType&)>& predicate);
	
	/**
	 * @brief Removes all elements in the binary tree.
	 * @details The elements are removed in post-order.
	 * @return A vector containing the removed elements in post-order.
	 */
	std::vector<ElementType> removeAll();
	
	/**
	 * @brief Finds the first element in the binary tree that satisfies a predicate.
	 * @tparam ConstIteratorType: The type of the const iterator.
	 * @param begin: A const iterator to the first element in the range to search.
	 * @param end: A const iterator to the node after the last element in the binary tree.
	 * @param predicate: The predicate to satisfy.
	 * @return A const iterator to the first element that satisfies the predicate if it exists, cend() otherwise.
	 */
	template<typename ConstIteratorType>
	requires Iterators::AllowedConstIterator<ConstIteratorType, ElementType>
	ConstIteratorType findFirst(ConstIteratorType begin,
	                            ConstIteratorType end,
	                            const std::function<bool(const ElementType&)>& predicate) const noexcept;
	
	/**
	 * @brief Finds the first element in the binary tree that satisfies a predicate.
	 * @tparam IteratorType: The type of the iterator.
	 * @param begin: An iterator to the first element in the range to search.
	 * @param end: An iterator to the node after the last node in the binary tree.
	 * @param predicate: The predicate to satisfy.
	 * @return An iterator to the first element that satisfies the predicate if it exists, end() otherwise.
	 */
	template<typename IteratorType>
	requires Iterators::AllowedIterator<IteratorType, ElementType>
	IteratorType findFirst(IteratorType begin,
	                       IteratorType end,
	                       const std::function<bool(const ElementType&)>& predicate) noexcept;
	
	/**
	 * @brief Traverses the binary tree using the given function on each node in the binary tree.
	 * @tparam ConstIteratorType: The type of the const iterator to use to traverse the binary tree.
	 * @param begin: A const iterator to the first node in the binary tree.
	 * @param end: A const iterator to the node after the last node in the binary tree.
	 * @param function: The function to use to traverse the binary tree.
	 */
	template<typename ConstIteratorType>
	requires Iterators::AllowedConstIterator<ConstIteratorType, ElementType>
	void traverse(ConstIteratorType begin,
	              ConstIteratorType end,
	              const std::function<void(const ElementType&)>& function) const noexcept;
	
	/**
	 * @brief Traverses the binary tree using the given function on each node in the binary tree.
	 * @tparam IteratorType: The type of the iterator to use to traverse the binary tree.
	 * @param begin: An iterator to the first node in the binary tree.
	 * @param end: An iterator to the node after the last node in the binary tree.
	 * @param function: The function to use to traverse the binary tree.
	 */
	template<typename IteratorType>
	requires Iterators::AllowedIterator<IteratorType, ElementType>
	void traverse(IteratorType begin, IteratorType end, const std::function<void(ElementType&)>& function) noexcept;
	
	/**
	 * @brief Checks if the binary tree contains an element that satisfies a predicate.
	 * @param predicate: The predicate to satisfy.
	 * @return True if the binary tree contains an element that satisfies the predicate, false otherwise.
	 */
	const bool contains(const std::function<bool(const ElementType&)>& predicate) const noexcept;
	
	/**
	 * @brief Checks if the binary tree is empty.
	 * @return True if the binary tree is empty, false otherwise.
	 */
	const bool isEmpty() const noexcept;
	
	/**
	 * @brief Gets the number of nodes in the binary tree.
	 * @return The number of nodes in the binary tree.
	 */
	const std::size_t getNodeCount() const noexcept;
	
	/**
	 * @brief Gets the height of the binary tree.
	 * @return The height of the binary tree.
	 */
	const int getHeight() const noexcept;

private:
	/**
	 * @brief Inserts a node into the binary tree in level-order.
	 * @param node: The node to insert.
	 */
	void insertLevelOrder(BinaryTreeNode<ElementType>* node);
	
	/**
	 * @brief Removes all nodes in the binary tree in post-order.
	 * @param node: The node to start removing from.
	 * @param elements: The vector to store the removed elements in.
	 */
	void removeAll(BinaryTreeNode<ElementType>* node, std::vector<ElementType>& elements);

private:
	std::size_t nodeCount {0};
	BinaryTreeNode<ElementType>* rootNode {nullptr};
};

template<typename ElementType>
BinaryTree<ElementType>::BinaryTree(const BinaryTree<ElementType>& other) {
	for (auto iterator {other.cbeginLevelOrder()}; iterator != other.cendLevelOrder(); ++iterator) {
		insert(*iterator);
	}
}

template<typename ElementType>
BinaryTree<ElementType>::BinaryTree(BinaryTree<ElementType>&& other) noexcept :
		nodeCount {other.nodeCount}, rootNode {other.rootNode} {
	other.nodeCount = 0;
	other.rootNode = nullptr;
}

template<typename ElementType>
BinaryTree<ElementType>::~BinaryTree() noexcept {
	removeAll();
}

template<typename ElementType>
BinaryTree<ElementType>& BinaryTree<ElementType>::operator=(const BinaryTree<ElementType>& other) {
	if (this == &other) {
		return *this;
	}
	
	removeAll();
	
	for (const auto& element : other) {
		insert(element);
	}
	
	return *this;
}

template<typename ElementType>
BinaryTree<ElementType>& BinaryTree<ElementType>::operator=(BinaryTree<ElementType>&& other) noexcept {
	if (this == &other) {
		return *this;
	}
	
	removeAll();
	
	nodeCount = other.nodeCount;
	rootNode = other.rootNode;
	
	other.nodeCount = 0;
	other.rootNode = nullptr;
	
	return *this;
}

template<typename ElementType>
const bool BinaryTree<ElementType>::operator==(const BinaryTree<ElementType>& other) const noexcept {
	if (nodeCount != other.nodeCount) {
		return false;
	}
	
	return std::equal(cbeginLevelOrder(), cendLevelOrder(), other.cbeginLevelOrder(), other.cendLevelOrder());
}

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
std::vector<ElementType> BinaryTree<ElementType>::removeAll() {
	std::vector<ElementType> elements {};
	removeAll(rootNode, elements);
	rootNode = nullptr;
	nodeCount = 0;
	
	return elements;
}

template<typename ElementType>
template<typename ConstIteratorType>
requires Iterators::AllowedConstIterator<ConstIteratorType, ElementType>
ConstIteratorType BinaryTree<ElementType>::findFirst(ConstIteratorType begin,
                                                     ConstIteratorType end,
                                                     const std::function<bool(const ElementType&)>& predicate) const noexcept {
	return std::find_if(begin, end, predicate);
}

template<typename ElementType>
template<typename IteratorType>
requires Iterators::AllowedIterator<IteratorType, ElementType>
IteratorType BinaryTree<ElementType>::findFirst(IteratorType begin,
                                                IteratorType end,
                                                const std::function<bool(const ElementType&)>& predicate) noexcept {
	return std::find_if(begin, end, predicate);
}

template<typename ElementType>
template<typename ConstIteratorType>
requires Iterators::AllowedConstIterator<ConstIteratorType, ElementType>
void BinaryTree<ElementType>::traverse(ConstIteratorType begin,
                                       ConstIteratorType end,
                                       const std::function<void(const ElementType&)>& function) const noexcept {
	std::for_each(begin, end, function);
}

template<typename ElementType>
template<typename IteratorType>
requires Iterators::AllowedIterator<IteratorType, ElementType>
void BinaryTree<ElementType>::traverse(IteratorType begin,
                                       IteratorType end,
                                       const std::function<void(ElementType&)>& function) noexcept {
	std::for_each(begin, end, function);
}

template<typename ElementType>
const bool BinaryTree<ElementType>::contains(const std::function<bool(const ElementType&)>& predicate) const noexcept {
	return std::any_of(cbeginLevelOrder(), cendLevelOrder(), predicate);
}

template<typename ElementType>
const bool BinaryTree<ElementType>::isEmpty() const noexcept {
	return rootNode == nullptr && nodeCount == 0;
}

template<typename ElementType>
const std::size_t BinaryTree<ElementType>::getNodeCount() const noexcept {
	return nodeCount;
}

template<typename ElementType>
const int BinaryTree<ElementType>::getHeight() const noexcept {
	auto height {-1};
	
	if (rootNode == nullptr) {
		return height;
	}
	
	auto* currentNode {rootNode};
	while (currentNode != nullptr) {
		++height;
		currentNode = currentNode->getLeftChild();
	}
	
	return height;
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
	
	while (!nodeQueue.isEmpty()) {
		const auto currentLevelNodeCount {nodeQueue.getSize()};
		
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
			}
			
			if (currentNode->getRightChild() == nullptr) {
				currentNode->setRightChild(node);
				++nodeCount;
				return;
			} else {
				nodeQueue.enqueue(currentNode->getRightChild());
			}
		}
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