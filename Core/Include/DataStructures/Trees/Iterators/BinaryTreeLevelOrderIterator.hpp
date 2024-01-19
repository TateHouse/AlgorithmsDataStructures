#pragma once

#include <iterator>

#include "DataStructures/Trees/BinaryTreeNode.hpp"
#include "DataStructures/Queues/SinglyLinkedListQueue.hpp"

namespace Core::DataStructures::Trees::Iterators {
/**
 * @brief An iterator that traverses a binary tree in level order.
 * @class BinaryTreeLevelOrderIterator
 * @tparam ElementType: The type of the elements stored in the binary tree.
 */
template<typename ElementType>
class BinaryTreeLevelOrderIterator final {
public:
	using iterator_category = std::forward_iterator_tag;
	using difference_type = std::ptrdiff_t;
	using value_type = ElementType;
	using reference = ElementType&;
	using pointer = ElementType*;
	
	/**
	 * @brief Instantiates a new level order iterator for binary trees.
	 * @param node: The node to iterate from.
	 */
	explicit BinaryTreeLevelOrderIterator(BinaryTreeNode<ElementType>* node) noexcept;
	
	/**
	 * @brief Instantiates a new level order iterator for binary trees by copying the given level order iterator for
	 * binary trees.
	 * @param other The level order iterator for binary trees to copy.
	 */
	BinaryTreeLevelOrderIterator(const BinaryTreeLevelOrderIterator<ElementType>& other) = default;
	
	/**
	 * @brief Instantiates a new level order iterator for binary trees by moving the given level order iterator for
	 * binary trees.
	 * @param other The level order iterator for binary trees to move.
	 */
	BinaryTreeLevelOrderIterator(BinaryTreeLevelOrderIterator<ElementType>&& other) noexcept = default;
	
	/**
	 * @brief Destroys the level order iterator for binary trees.
	 */
	~BinaryTreeLevelOrderIterator() noexcept = default;

public:
	/**
	 * @brief Assigns the given level order iterator for binary trees to this level order iterator for binary trees
	 * using copy semantics.
	 * @param other The level order iterator for binary trees to copy.
	 * @return A reference to the level order iterator for binary trees.
	 */
	BinaryTreeLevelOrderIterator<ElementType>& operator=(const BinaryTreeLevelOrderIterator<ElementType>& other) = default;
	
	/**
	 * @brief Assigns the given level order iterator for binary trees to this level order iterator for binary trees
	 * using move semantics.
	 * @param other The level order iterator for binary trees to move.
	 * @return A reference to the level order iterator for binary trees.
	 */
	BinaryTreeLevelOrderIterator<ElementType>& operator=(BinaryTreeLevelOrderIterator<ElementType>&& other) noexcept = default;
	
	/**
	 * @brief Compares two level order iterators for binary trees.
	 * @details Two level order iterators for binary trees are equal if they point to the same node.
	 * @param other: The other level order iterator for binary trees to compare with.
	 * @return True if the two level order iterators for binary trees are equal, false otherwise.
	 */
	bool operator==(const BinaryTreeLevelOrderIterator<ElementType>& other) const noexcept;

	/**
	 * @brief Dereferences the level order iterator for binary trees.
	 * @return A reference to the element stored in the node pointed to by the level order iterator for binary trees.
	 */
	reference operator*() const noexcept;
	
	/**
	 * @brief Dereferences the level order iterator for binary trees.
	 * @return A pointer to the element stored in the node pointed to by the level order iterator for binary trees.
	 */
	pointer operator->() const noexcept;
	
	/**
	 * @brief Increments the level order iterator for binary trees.
	 * @return A reference to the level order iterator for binary trees.
	 */
	BinaryTreeLevelOrderIterator<ElementType>& operator++() noexcept;
	
	/**
	 * @brief Increments the level order iterator for binary trees.
	 * @return A copy of the level order iterator for binary trees before it was incremented.
	 */
	BinaryTreeLevelOrderIterator<ElementType> operator++(int) noexcept;

private:
	Queues::SinglyLinkedListQueue<BinaryTreeNode<ElementType>*> nodeQueue {};
};

template<typename ElementType>
BinaryTreeLevelOrderIterator<ElementType>::BinaryTreeLevelOrderIterator(BinaryTreeNode<ElementType>* node) noexcept {
	if (node != nullptr) {
		nodeQueue.enqueue(node);
	}
}

template<typename ElementType>
bool BinaryTreeLevelOrderIterator<ElementType>::operator==(const BinaryTreeLevelOrderIterator<ElementType>& other) const noexcept {
	return nodeQueue == other.nodeQueue;
}

template<typename ElementType>
ElementType& BinaryTreeLevelOrderIterator<ElementType>::operator*() const noexcept {
	assert(!nodeQueue.isEmpty() && "Cannot dereference a null iterator.");
	const auto* const node {nodeQueue.getFront()};
	
	return (*node)->getElement();
}

template<typename ElementType>
ElementType* BinaryTreeLevelOrderIterator<ElementType>::operator->() const noexcept {
	assert(!nodeQueue.isEmpty() && "Cannot dereference a null iterator.");
	return nodeQueue.getFront();
}

template<typename ElementType>
BinaryTreeLevelOrderIterator<ElementType>& BinaryTreeLevelOrderIterator<ElementType>::operator++() noexcept {
	assert(!nodeQueue.isEmpty() && "Cannot increment a null iterator.");
	
	const auto optionalNode {nodeQueue.dequeue()};
	assert(optionalNode.has_value() && "Queue should not be empty.");
	
	const auto& node {optionalNode.value()};
	
	if (node->getLeftChild() != nullptr) {
		nodeQueue.enqueue(node->getLeftChild());
	}
	
	if (node->getRightChild() != nullptr) {
		nodeQueue.enqueue(node->getRightChild());
	}
	
	return *this;
}

template<typename ElementType>
BinaryTreeLevelOrderIterator<ElementType> BinaryTreeLevelOrderIterator<ElementType>::operator++(int) noexcept {
	auto iterator {*this};
	++(*this);
	return iterator;
}
}