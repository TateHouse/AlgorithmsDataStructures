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
/**
 * @brief An Adelson-Velsky and Landis tree.
 * @class AVLTree
 * @tparam ElementType The type of the elements stored in the avl tree.
 */
template<ElementTypeWithLessThanOperator ElementType>
class AVLTree final {
public:
	/**
	 * @brief Instantiates a new avl tree with no nodes.
	 */
	AVLTree() noexcept = default;
	
	/**
	 * @brief Instantiates a new avl tree by copying the given avl tree.
	 * @param other The avl tree to copy.
	 */
	AVLTree(const AVLTree& other);
	
	/**
	 * @brief Instantiates a new avl tree by moving the given avl tree.
	 * @param other The avl tree to move.
	 */
	AVLTree(AVLTree&& other) noexcept;
	
	/**
	 * @brief Destroys the avl tree.
	 */
	~AVLTree() noexcept;
	
public:
	/**
	 * @brief Assigns the given avl tree to this avl tree using copy semantics.
	 * @param other The avl tree to copy.
	 * @return A reference to this avl tree.
	 */
	AVLTree<ElementType>& operator=(const AVLTree& other);
	
	/**
	 * @brief Assigns the given avl tree to this avl tree using move semantics.
	 * @param other The avl tree to move.
	 * @return A reference to this avl tree.
	 */
	AVLTree<ElementType>& operator=(AVLTree&& other) noexcept;
	
	/**
	 * @brief Checks if the given avl tree is equal to this avl tree.
	 * @details Two avl trees are equal if they have the same number of nodes, the node contain the same elements, and
	 * the nodes are in the same order.
	 * @param other The avl tree to check.
	 * @return True if the given avl tree is equal to this avl tree, false otherwise.
	 */
	const bool operator==(const AVLTree& other) const noexcept;

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
	 * @brief Gets a const in-order iterator to the first node in the avl tree.
	 * @return A const in-order iterator to the first node in the avl tree.
	 */
	ConstInOrderIterator cbeginInOrder() const noexcept;
	
	/**
	 * @brief Gets a const in-order iterator to the node after the last node in the avl tree.
	 * @return A const in-order iterator to the node after the last node in the avl tree.
	 */
	ConstInOrderIterator cendInOrder() const noexcept;
	
	/**
	 * @brief Gets a const level-order iterator to the first node in the avl tree.
	 * @return A const level-order iterator to the first node in the avl tree.
	 */
	ConstLevelOrderIterator cbeginLevelOrder() const noexcept;
	
	/**
	 * @brief Gets a const level-order iterator to the node after the last node in the avl tree.
	 * @return A const level-order iterator to the node after the last node in the avl tree.
	 */
	ConstLevelOrderIterator cendLevelOrder() const noexcept;
	
	/**
	 * @brief Gets a const post-order iterator to the first node in the avl tree.
	 * @return A const post-order iterator to the first node in the avl tree.
	 */
	ConstPostOrderIterator cbeginPostOrder() const noexcept;
	
	/**
	 * @brief Gets a const post-order iterator to the node after the last node in the avl tree.
	 * @return A const post-order iterator to the node after the last node in the avl tree.
	 */
	ConstPostOrderIterator cendPostOrder() const noexcept;
	
	/**
	 * @brief Gets a const pre-order iterator to the first node in the avl tree.
	 * @return A const pre-order iterator to the first node in the avl tree.
	 */
	ConstPreOrderIterator cbeginPreOrder() const noexcept;
	
	/**
	 * @brief Gets a const pre-order iterator to the node after the last node in the avl tree.
	 * @return A const pre-order iterator to the node after the last node in the avl tree.
	 */
	ConstPreOrderIterator cendPreOrder() const noexcept;
	
	/**
	 * @brief Gets an in-order iterator to the first node in the avl tree.
	 * @return An in-order iterator to the first node in the avl tree.
	 */
	InOrderIterator beginInOrder() noexcept;
	
	/**
	 * @brief Gets an in-order iterator to the node after the last node in the avl tree.
	 * @return An in-order iterator to the node after the last node in the avl tree.
	 */
	InOrderIterator endInOrder() noexcept;
	
	/**
	 * @brief Gets a level-order iterator to the first node in the avl tree.
	 * @return A level-order iterator to the first node in the avl tree.
	 */
	LevelOrderIterator beginLevelOrder() noexcept;
	
	/**
	 * @brief Gets a level-order iterator to the node after the last node in the avl tree.
	 * @return A level-order iterator to the node after the last node in the avl tree.
	 */
	LevelOrderIterator endLevelOrder() noexcept;
	
	/**
	 * @brief Gets a post-order iterator to the first node in the avl tree.
	 * @return A post-order iterator to the first node in the avl tree.
	 */
	PostOrderIterator beginPostOrder() noexcept;
	
	/**
	 * @brief Gets a post-order iterator to the node after the last node in the avl tree.
	 * @return A post-order iterator to the node after the last node in the avl tree.
	 */
	PostOrderIterator endPostOrder() noexcept;
	
	/**
	 * @brief Gets a pre-order iterator to the first node in the avl tree.
	 * @return A pre-order iterator to the first node in the avl tree.
	 */
	PreOrderIterator beginPreOrder() noexcept;
	
	/**
	 * @brief Gets a pre-order iterator to the node after the last node in the avl tree.
	 * @return A pre-order iterator to the node after the last node in the avl tree.
	 */
	PreOrderIterator endPreOrder() noexcept;

public:
	/**
	 * @brief Inserts the given element into the avl tree using copy semantics.
	 * @param element The element to insert.
	 */
	void insert(const ElementType& element) noexcept;
	
	/**
	 * @brief Inserts the given element into the avl tree using move semantics.
	 * @param element The element to insert.
	 */
	void insert(ElementType&& element) noexcept;
	
	/**
	 * @brief Removes the first occurrence of the given element from the avl tree.
	 * @param element The element to remove.
	 * @return The element that was removed from the avl tree, or std::nullopt if the avl tree is empty or the given
	 * element was not found in the avl tree.
	 */
	std::optional<ElementType> removeFirst(const ElementType& element);
	
	/**
	 * @brief Removes the minimum element from the avl tree.
	 * @return The minimum element from the avl tree, or std::nullopt if the avl tree is empty.
	 */
	std::optional<ElementType> removeMinimum();
	
	/**
	 * @brief Removes the maximum element from the avl tree.
	 * @return The maximum element from the avl tree, or std::nullopt if the avl tree is empty.
	 */
	std::optional<ElementType> removeMaximum();
	
	/**
	 * @brief Removes all elements from the avl tree resulting in an empty avl tree.
	 * @return A vector containing all elements that were removed from the avl tree.
	 */
	std::vector<ElementType> removeAll();
	
	/**
	 * @brief Finds the first occurrence of the given element in the avl tree.
	 * @param element The element to find.
	 * @return The first occurrence of the given element in the avl tree, or std::nullopt if the avl tree is empty or
	 * the given element was not found in the avl tree.
	 */
	const std::optional<ElementType> findFirst(const ElementType& element) const noexcept;
	
	/**
	 * @brief Finds the minimum element in the avl tree.
	 * @return The minimum element in the avl tree, or std::nullopt if the avl tree is empty.
	 */
	const std::optional<ElementType> findMinimum() const noexcept;
	
	/**
	 * @brief Finds the maximum element in the avl tree.
	 * @return The maximum element in the avl tree, or std::nullopt if the avl tree is empty.
	 */
	const std::optional<ElementType> findMaximum() const noexcept;
	
	/**
	 * @brief Traverses the avl tree using the given function on each node in the avl tree.
	 * @tparam ConstIteratorType The type of const iterator to use to traverse the avl tree.
	 * @param begin A const iterator to the first node in the avl tree.
	 * @param end A const iterator to the node after the last node in the avl tree.
	 * @param function The function to use to traverse the avl tree.
	 */
	template<typename ConstIteratorType>
	requires Iterators::AllowedConstIterator<ConstIteratorType, ElementType>
	void traverse(ConstIteratorType begin,
	              ConstIteratorType end,
	              const std::function<void(const ElementType&)>& function) const noexcept;
	
	/**
	 * @brief Traverses the avl tree using the given function on each node in the avl tree.
	 * @tparam IteratorType The type of iterator to use to traverse the avl tree.
	 * @param begin An iterator to the first node in the avl tree.
	 * @param end An iterator to the node after the last node in the avl tree.
	 * @param function The function to use to traverse the avl tree.
	 */
	template<typename IteratorType>
	requires Iterators::AllowedIterator<IteratorType, ElementType>
	void traverse(IteratorType begin,
	              IteratorType end,
	              const std::function<void(ElementType&)>& function) const noexcept;
	
	/**
	 * @brief Checks if the avl tree contains the given element.
	 * @param element The element to check.
	 * @return True if the avl tree contains the given element, false otherwise.
	 */
	const bool contains(const ElementType& element) const noexcept;
	
	/**
	 * @brief Checks if the avl tree is empty.
	 * @return True if the avl tree is empty, false otherwise.
	 */
	const bool isEmpty() const noexcept;
	
	/**
	 * @brief Gets the number of nodes in the avl tree.
	 * @return The number of nodes in the avl tree.
	 */
	const std::size_t getNodeCount() const noexcept;
	
	/**
	 * @brief Gets the height of the avl tree.
	 * @return The height of the avl tree.
	 */
	const int getHeight() const noexcept;

private:
	/**
	 * @brief Inserts the given element into the avl tree using copy semantics recursively.
	 * @param node The node to start inserting from.
	 * @param element The element to insert.
	 * @return The node that was inserted.
	 */
	BinaryTreeNode<ElementType>* insert(BinaryTreeNode<ElementType>* node, const ElementType& element);
	
	/**
	 * @brief Inserts the given element into the avl tree using move semantics recursively.
	 * @param node The node to start inserting from.
	 * @param element The element to insert.
	 * @return The node that was inserted.
	 */
	BinaryTreeNode<ElementType>* insert(BinaryTreeNode<ElementType>* node, ElementType&& element);
	
	/**
	 * @brief Removes the first occurrence of the given element from the avl tree recursively.
	 * @param node The node to start removing from.
	 * @param element The element to remove.
	 * @param removedElement The element that was removed from the avl tree.
	 * @return The node that was removed.
	 */
	BinaryTreeNode<ElementType>* removeFirst(BinaryTreeNode<ElementType>* node,
	                                         const ElementType& element,
	                                         std::optional<ElementType>& removedElement);
	
	/**
	 * @brief Gets the in-order successor of the given node.
	 * @param node The node to get the in-order successor of.
	 * @return The in-order successor of the given node.
	 */
	BinaryTreeNode<ElementType>* getInOrderSuccessor(BinaryTreeNode<ElementType>* node);
	
	/**
	 * @brief Removes the minimum element from the avl tree recursively.
	 * @param node The node to start removing from.
	 * @param removedElement The element that was removed from the avl tree.
	 * @return The node that was removed.
	 */
	BinaryTreeNode<ElementType>* removeMinimum(BinaryTreeNode<ElementType>* node,
	                                           std::optional<ElementType>& removedElement);
	
	/**
	 * @brief Removes the maximum element from the avl tree recursively.
	 * @param node The node to start removing from.
	 * @param removedElement The element that was removed from the avl tree.
	 * @return The node that was removed.
	 */
	BinaryTreeNode<ElementType>* removeMaximum(BinaryTreeNode<ElementType>* node,
	                                           std::optional<ElementType>& removedElement);
	
	/**
	 * @brief Removes all elements from the avl tree recursively.
	 * @param node The node to start removing from.
	 * @param elements The elements that were removed from the avl tree.
	 */
	void removeAll(BinaryTreeNode<ElementType>* node, std::vector<ElementType>& elements);
	
	/**
	 * @brief Gets the height of the given node recursively.
	 * @param node The node to get the height of.
	 * @return The height of the given node.
	 */
	const int getHeight(const BinaryTreeNode<ElementType>* const node) const noexcept;
	
	/**
	 * @brief Gets the balance factor of the given node recursively.
	 * @param node The node to get the balance factor of.
	 * @return The balance factor of the given node.
	 */
	const int getBalanceFactor(const BinaryTreeNode<ElementType>* const node) const noexcept;
	
	/**
	 * @brief Rebalances the given node recursively.
	 * @param node The node to rebalance.
	 * @return The node that was rebalanced.
	 */
	BinaryTreeNode<ElementType>* rebalance(BinaryTreeNode<ElementType>* node);
	
	/**
	 * @brief Rotates the given node left recursively.
	 * @param node The node to rotate left.
	 * @return The node that was rotated left.
	 */
	BinaryTreeNode<ElementType>* rotateLeft(BinaryTreeNode<ElementType>* node);
	
	/**
	 * @brief Rotates the given node right recursively.
	 * @param node The node to rotate right.
	 * @return The node that was rotated right.
	 */
	BinaryTreeNode<ElementType>* rotateRight(BinaryTreeNode<ElementType>* node);

private:
	std::size_t nodeCount {0};
	BinaryTreeNode<ElementType>* rootNode {nullptr};
};

template<ElementTypeWithLessThanOperator ElementType>
AVLTree<ElementType>::AVLTree(const AVLTree<ElementType>& other) {
	for (auto iterator {other.cbeginLevelOrder()}; iterator != other.cendLevelOrder(); ++iterator) {
		insert(*iterator);
	}
}

template<ElementTypeWithLessThanOperator ElementType>
AVLTree<ElementType>::AVLTree(AVLTree<ElementType>&& other) noexcept {
	removeAll();
	
	nodeCount = other.nodeCount;
	rootNode = other.rootNode;
	
	other.nodeCount = 0;
	other.rootNode = nullptr;
}

template<ElementTypeWithLessThanOperator ElementType>
AVLTree<ElementType>::~AVLTree() noexcept {
	removeAll();
}

template<ElementTypeWithLessThanOperator ElementType>
AVLTree<ElementType>& AVLTree<ElementType>::operator=(const AVLTree& other) {
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
AVLTree<ElementType>& AVLTree<ElementType>::operator=(AVLTree&& other) noexcept {
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
const bool AVLTree<ElementType>::operator==(const AVLTree& other) const noexcept {
	if (nodeCount != other.nodeCount) {
		return false;
	}
	
	return std::equal(cbeginInOrder(), cendInOrder(), other.cbeginInOrder(), other.cendInOrder());
}

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
const std::size_t AVLTree<ElementType>::getNodeCount() const noexcept {
	return nodeCount;
}

template<ElementTypeWithLessThanOperator ElementType>
const int AVLTree<ElementType>::getHeight() const noexcept {
	return getHeight(rootNode);
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
