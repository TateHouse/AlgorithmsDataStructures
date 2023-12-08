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
/**
 * @brief A binary search tree.
 * @class BinarySearchTree
 * @tparam ElementType: The type of the elements stored in the binary search tree.
 */
template<ElementTypeWithLessThanOperator ElementType>
class BinarySearchTree final {
public:
	/**
	 * @brief Instantiates a new binary search tree with no nodes.
	 */
	BinarySearchTree() noexcept = default;
	
	/**
	 * @brief Instantiates a new binary search tree by copying the given binary search tree.
	 * @param other: The binary search tree to copy.
	 */
	BinarySearchTree(const BinarySearchTree<ElementType>& other);
	
	/**
	 * @brief Instantiates a new binary search tree by moving the given binary search tree.
	 * @param other: The binary search tree to move.
	 */
	BinarySearchTree(BinarySearchTree<ElementType>&& other) noexcept;
	
	/**
	 * @brief Destroys the binary search tree.
	 */
	~BinarySearchTree() noexcept;

public:
	/**
	 * @brief Assigns the given binary search tree to this binary search tree using copy semantics.
	 * @param other: The binary search tree to copy.
	 * @return A reference to this binary search tree.
	 */
	BinarySearchTree<ElementType>& operator=(const BinarySearchTree<ElementType>& other);
	
	/**
	 * @brief Assigns the given binary search tree to this binary search tree using move semantics.
	 * @param other: The binary search tree to move.
	 * @return A reference to this binary search tree.
	 */
	BinarySearchTree<ElementType>& operator=(BinarySearchTree<ElementType>&& other) noexcept;
	
	/**
	 * @brief Checks if the given binary search tree is equal to this binary search tree.
	 * @details Two binary search trees are equal if they have the same number of nodes, the nodes contain the same
	 * elements, and the nodes are in the same order.
	 * @param other: The binary search tree to check.
	 * @return True if the given binary search tree is equal to this binary search tree, false otherwise.
	 */
	const bool operator==(const BinarySearchTree<ElementType>& other) const noexcept;

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
	 * @brief Gets a const in-order iterator to the first node in the binary search tree.
	 * @return A const in-order iterator to the first node in the binary search tree.
	 */
	ConstInOrderIterator cbeginInOrder() const noexcept;
	
	/**
	 * @brief Gets a const in-order iterator to the node after the last node in the binary search tree.
	 * @return A const in-order iterator to the node after the last node in the binary search tree.
	 */
	ConstInOrderIterator cendInOrder() const noexcept;
	
	/**
	 * @brief Gets a const level-order iterator to the first node in the binary search tree.
	 * @return A const level-order iterator to the first node in the binary search tree.
	 */
	ConstLevelOrderIterator cbeginLevelOrder() const noexcept;
	
	/**
	 * @brief Gets a const level-order iterator to the node after the last node in the binary search tree.
	 * @return A const level-order iterator to the node after the last node in the binary search tree.
	 */
	ConstLevelOrderIterator cendLevelOrder() const noexcept;
	
	/**
	 * @brief Gets a const post-order iterator to the first node in the binary search tree.
	 * @return A const post-order iterator to the first node in the binary search tree.
	 */
	ConstPostOrderIterator cbeginPostOrder() const noexcept;
	
	/**
	 * @brief Gets a const post-order iterator to the node after the last node in the binary search tree.
	 * @return A const post-order iterator to the node after the last node in the binary search tree.
	 */
	ConstPostOrderIterator cendPostOrder() const noexcept;
	
	/**
	 * @brief Gets a const pre-order iterator to the first node in the binary search tree.
	 * @return A const pre-order iterator to the first node in the binary search tree.
	 */
	ConstPreOrderIterator cbeginPreOrder() const noexcept;
	
	/**
	 * @brief Gets a const pre-order iterator to the node after the last node in the binary search tree.
	 * @return A const pre-order iterator to the node after the last node in the binary search tree.
	 */
	ConstPreOrderIterator cendPreOrder() const noexcept;
	
	/**
	 * @brief Gets an in-order iterator to the first node in the binary search tree.
	 * @return An in-order iterator to the first node in the binary search tree.
	 */
	
	InOrderIterator beginInOrder() const noexcept;
	
	/**
	 * @brief Gets an in-order iterator to the node after the last node in the binary search tree.
	 * @return An in-order iterator to the node after the last node in the binary search tree.
	 */
	InOrderIterator endInOrder() const noexcept;
	
	/**
	 * @brief Gets a level-order iterator to the first node in the binary search tree.
	 * @return A level-order iterator to the first node in the binary search tree.
	 */
	LevelOrderIterator beginLevelOrder() const noexcept;
	
	/**
	 * @brief Gets a level-order iterator to the node after the last node in the binary search tree.
	 * @return A level-order iterator to the node after the last node in the binary search tree.
	 */
	LevelOrderIterator endLevelOrder() const noexcept;
	
	/**
	 * @brief Gets a post-order iterator to the first node in the binary search tree.
	 * @return A post-order iterator to the first node in the binary search tree.
	 */
	PostOrderIterator beginPostOrder() const noexcept;
	
	/**
	 * @brief Gets a post-order iterator to the node after the last node in the binary search tree.
	 * @return A post-order iterator to the node after the last node in the binary search tree.
	 */
	PostOrderIterator endPostOrder() const noexcept;
	
	/**
	 * @brief Gets a pre-order iterator to the first node in the binary search tree.
	 * @return A pre-order iterator to the first node in the binary search tree.
	 */
	PreOrderIterator beginPreOrder() const noexcept;
	
	/**
	 * @brief Gets a pre-order iterator to the node after the last node in the binary search tree.
	 * @return A pre-order iterator to the node after the last node in the binary search tree.
	 */
	PreOrderIterator endPreOrder() const noexcept;

public:
	/**
	 * @brief Inserts the given element into the binary search tree using copy semantics.
	 * @param element: The element to insert.
	 */
	void insert(const ElementType& element);
	
	/**
	 * @brief Inserts the given element into the binary search tree using move semantics.
	 * @param element: The element to insert.
	 */
	void insert(ElementType&& element);
	
	// TODO: Refactor removeFirst to take a predicate instead of an element.
	std::optional<ElementType> removeFirst(const ElementType& element);
	
	/**
	 * @brief Removes the minimum element from the binary search tree.
	 * @return The minimum element from the binary search tree, or std::nullopt if the binary search tree is empty.
	 */
	std::optional<ElementType> removeMinimum();
	
	/**
	 * @brief Removes the maximum element from the binary search tree.
	 * @return The maximum element from the binary search tree, or std::nullopt if the binary search tree is empty.
	 */
	std::optional<ElementType> removeMaximum();
	
	/**
	 * @brief Removes all elements from the binary search tree resulting in an empty binary search tree.
	 * @return A vector containing the elements that were removed from the binary search tree.
	 */
	std::vector<ElementType> removeAll();
	
	// TODO: Refactor findFirst to take a predicate instead of an element.
	const std::optional<ElementType> findFirst(const ElementType& element) const noexcept;
	
	/**
	 * @brief Finds the minimum element in the binary search tree.
	 * @return The minimum element in the binary search tree, or std::nullopt if the binary search tree is empty.
	 */
	const std::optional<ElementType> findMinimum() const noexcept;
	
	/**
	 * @brief Finds the maximum element in the binary search tree.
	 * @return The maximum element in the binary search tree, or std::nullopt if the binary search tree is empty.
	 */
	const std::optional<ElementType> findMaximum() const noexcept;
	
	/**
	 * @brief Traverses the binary search tree using the given function on each node in the binary search tree.
	 * @tparam ConstIteratorType The type of const iterator to use to traverse the binary search tree.
	 * @param begin A const iterator to the first node in the binary search tree.
	 * @param end A const iterator to the node after the last node in the binary search tree.
	 * @param function The function to use to traverse the binary search tree.
	 */
	template<typename ConstIteratorType>
	requires Iterators::AllowedConstIterator<ConstIteratorType, ElementType>
	void traverse(ConstIteratorType begin,
	              ConstIteratorType end,
	              const std::function<void(const ElementType&)>& function) const noexcept;
	
	/**
	 * @brief Traverses the binary search tree using the given function on each node in the binary search tree.
	 * @tparam IteratorType The type of iterator to use to traverse the binary search tree.
	 * @param begin An iterator to the first node in the binary search tree.
	 * @param end An iterator to the node after the last node in the binary search tree.
	 * @param function The function to use to traverse the binary search tree.
	 */
	template<typename IteratorType>
	requires Iterators::AllowedIterator<IteratorType, ElementType>
	void traverse(IteratorType begin, IteratorType end, const std::function<void(ElementType&)>& function) noexcept;
	
	// TODO: Refactor contains to take a predicate instead of an element.
	const bool contains(const ElementType& element) const noexcept;
	
	/**
	 * @brief Checks if the binary search tree is empty.
	 * @return True if the binary search tree is empty, false otherwise.
	 */
	const bool isEmpty() const noexcept;
	
	/**
	 * @brief Gets the number of nodes in the binary search tree.
	 * @return The number of nodes in the binary search tree.
	 */
	const std::size_t getNodeCount() const noexcept;
	
	/**
	 * @brief Gets the height of the binary search tree.
	 * @return The height of the binary search tree.
	 */
	const int getHeight() const noexcept;

private:
	/**
	 * @brief Inserts the given node into the binary search tree.
	 * @param node: The node to insert.
	 */
	void insert(BinaryTreeNode<ElementType>* node);
	
	/**
	 * @brief Removes the given leaf node from the binary search tree.
	 * @param currentNode: The leaf node to remove.
	 * @param parentNode: The parent node of the leaf node to remove.
	 * @param isLeftChild: True if the leaf node to remove is a left child, false otherwise.
	 */
	void removeLeafNode(BinaryTreeNode<ElementType>* currentNode,
	                    BinaryTreeNode<ElementType>* parentNode,
	                    const bool isLeftChild);
	
	/**
	 * @brief Removes the given node from the binary search tree that has only a right child.
	 * @param currentNode: The node to remove.
	 * @param parentNode: The parent node of the node to remove.
	 * @param isLeftChild: True if the node to remove is a left child, false otherwise.
	 */
	void removeNodeWithOnlyRightChild(BinaryTreeNode<ElementType>* currentNode,
	                                  BinaryTreeNode<ElementType>* parentNode,
	                                  const bool isLeftChild);
	
	/**
	 * @brief Removes the given node from the binary search tree that has only a left child.
	 * @param currentNode: The node to remove.
	 * @param parentNode: The parent node of the node to remove.
	 * @param isLeftChild: True if the node to remove is a left child, false otherwise.
	 */
	void removeNodeWithOnlyLeftChild(BinaryTreeNode<ElementType>* currentNode,
	                                 BinaryTreeNode<ElementType>* parentNode,
	                                 const bool isLeftChild);
	
	/**
	 * @brief Removes the given node from the binary search tree that has two children.
	 * @param currentNode: The node to remove.
	 * @param parentNode: The parent node of the node to remove.
	 */
	void removeNodeWithTwoChildren(BinaryTreeNode<ElementType>* currentNode, BinaryTreeNode<ElementType>* parentNode);
	
	/**
	 * @brief Removes all nodes from the binary search tree.
	 * @param node: The node to remove.
	 * @param elements: The vector to store the elements of the nodes that were removed.
	 */
	void removeAll(BinaryTreeNode<ElementType>* node, std::vector<ElementType>& elements);
	
	/**
	 * @brief Gets the height of the given node.
	 * @param node: The node to get the height of.
	 * @return The height of the given node.
	 */
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
BinarySearchTree<ElementType>::~BinarySearchTree() noexcept {
	removeAll();
}

template<ElementTypeWithLessThanOperator ElementType>
BinarySearchTree<ElementType>& BinarySearchTree<ElementType>::operator=(const BinarySearchTree<ElementType>& other) {
	if (this == &other) {
		return *this;
	}
	
	removeAll();
	
	for (auto iterator {other.cbeginInOrder()}; iterator != other.cendInOrder(); ++iterator) {
		insert(*iterator);
	}
	
	return *this;
}

template<ElementTypeWithLessThanOperator ElementType>
BinarySearchTree<ElementType>& BinarySearchTree<ElementType>::operator=(BinarySearchTree<ElementType>&& other) noexcept {
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

template<ElementTypeWithLessThanOperator ElementType>
const bool BinarySearchTree<ElementType>::operator==(const BinarySearchTree<ElementType>& other) const noexcept {
	if (nodeCount != other.nodeCount) {
		return false;
	}
	
	return std::equal(cbeginInOrder(), cendInOrder(), other.cbeginInOrder(), other.cendInOrder());
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
		removeNodeWithTwoChildren(currentNode, parentNode);
	}
	
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
const std::optional<ElementType> BinarySearchTree<ElementType>::findFirst(const ElementType& element) const noexcept {
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
const std::optional<ElementType> BinarySearchTree<ElementType>::findMinimum() const noexcept {
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
const std::optional<ElementType> BinarySearchTree<ElementType>::findMaximum() const noexcept {
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
		++nodeCount;
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
	} else if (isLeftChild) {
		parentNode->setLeftChild(nullptr);
	} else {
		parentNode->setRightChild(nullptr);
	}
	
	--nodeCount;
	
	delete currentNode;
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
	
	--nodeCount;
	
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
	
	--nodeCount;
	
	delete currentNode;
}

template<ElementTypeWithLessThanOperator ElementType>
void BinarySearchTree<ElementType>::removeNodeWithTwoChildren(BinaryTreeNode<ElementType>* currentNode,
                                                              BinaryTreeNode<ElementType>* parentNode) {
	BinaryTreeNode<ElementType>* successorNode {currentNode->getRightChild()};
	BinaryTreeNode<ElementType>* successorParentNode {currentNode};
	
	const auto isLeftChild {successorNode->getLeftChild() != nullptr};
	
	while (successorNode->getLeftChild() != nullptr) {
		successorParentNode = successorNode;
		successorNode = successorNode->getLeftChild();
	}
	
	auto* node {new BinaryTreeNode<ElementType> {successorNode->getElement()}};
	
	if (currentNode == rootNode) {
		rootNode = node;
	} else if (currentNode->getElement() < parentNode->getElement()) {
		parentNode->setLeftChild(node);
	} else {
		parentNode->setRightChild(node);
	}
	
	if (isLeftChild) {
		successorParentNode->setLeftChild(successorNode->getRightChild());
	} else {
		successorParentNode->setRightChild(successorNode->getRightChild());
	}
	
	node->setLeftChild(currentNode->getLeftChild());
	node->setRightChild(currentNode->getRightChild());
	
	--nodeCount;
	
	delete currentNode;
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