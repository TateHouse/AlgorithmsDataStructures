#pragma once

#include <iterator>

#include "DataStructures/Trees/BinaryTreeNode.hpp"
#include "DataStructures/Queues/SinglyLinkedListQueue.hpp"

namespace Core::DataStructures::Trees::Iterators {
/**
 * @brief A const level-order iterator for binary trees.
 * @class BinaryTreeConstLevelOrderIterator
 * @tparam ElementType: The type of the elements stored in the binary tree.
 */
template<typename ElementType>
class BinaryTreeConstLevelOrderIterator final {
public:
	using iterator_category = std::forward_iterator_tag;
	using difference_type = std::ptrdiff_t;
	using value_type = const ElementType;
	using reference = const ElementType&;
	using pointer = const ElementType* const;
	
	/**
	 * @brief Instantiates a new const level-order iterator for binary trees.
	 * @param node: The node to iterate from.
	 */
	explicit BinaryTreeConstLevelOrderIterator(BinaryTreeNode<ElementType>* node) noexcept;
	
	/**
	 * @brief Instantiates a new const level-order iterator for binary trees by copying the given const level-order
	 * iterator for binary trees.
	 * @param other The const level-order iterator for binary trees to copy.
	 */
	BinaryTreeConstLevelOrderIterator(const BinaryTreeConstLevelOrderIterator<ElementType>& other) = default;
	
	/**
	 * @brief Instantiates a new const level-order iterator for binary trees by moving the given const level-order
	 * iterator for binary trees.
	 * @param other The const level-order iterator for binary trees to move.
	 */
	BinaryTreeConstLevelOrderIterator(BinaryTreeConstLevelOrderIterator<ElementType>&& other) noexcept = default;
	
	/**
	 * @brief Destroys the const level-order iterator for binary trees.
	 */
	~BinaryTreeConstLevelOrderIterator() noexcept = default;

public:
	/**
	 * @brief Assigns the given const level-order iterator for binary trees to this const level-order iterator for
	 * binary trees using copy semantics.
	 * @param other The const level-order iterator for binary trees to copy.
	 * @return A reference to the const level-order iterator for binary trees.
	 */
	BinaryTreeConstLevelOrderIterator<ElementType>& operator=(const BinaryTreeConstLevelOrderIterator<ElementType>& other) = default;
	
	/**
	 * @brief Assigns the given const level-order iterator for binary trees to this const level-order iterator for
	 * binary trees using move semantics.
	 * @param other The const level-order iterator for binary trees to move.
	 * @return A reference to the const level-order iterator for binary trees.
	 */
	BinaryTreeConstLevelOrderIterator<ElementType>& operator=(BinaryTreeConstLevelOrderIterator<ElementType>&& other) noexcept = default;
	
	/**
	 * @brief Compares two const level-order iterators for binary trees.
	 * @details Two const level-order iterators for binary trees are equal if they point to the same node.
	 * @param other: The other const level-order iterator for binary trees to compare with.
	 * @return True if the two const level-order iterators for binary trees are equal, false otherwise.
	 */
	const bool operator==(const BinaryTreeConstLevelOrderIterator<ElementType>& other) const noexcept;

	/**
	 * @brief Dereferences the const level-order iterator for binary trees.
	 * @return A reference to the element stored in the node pointed to by the const level-order iterator for binary trees.
	 */
	reference operator*() const noexcept;
	
	/**
	 * @brief Dereferences the const level-order iterator for binary trees.
	 * @return A pointer to the element stored in the node pointed to by the const level-order iterator for binary trees.
	 */
	pointer operator->() const noexcept;
	
	/**
	 * @brief Increments the const level-order iterator for binary trees.
	 * @return A reference to the const level-order iterator for binary trees.
	 */
	BinaryTreeConstLevelOrderIterator<ElementType>& operator++() noexcept;
	
	/**
	 * @brief Increments the const level-order iterator for binary trees.
	 * @return A copy of the const level-order iterator for binary trees before it was incremented.
	 */
	BinaryTreeConstLevelOrderIterator<ElementType> operator++(int) noexcept;

private:
	Queues::SinglyLinkedListQueue<BinaryTreeNode<ElementType>*> nodeQueue {};
};

template<typename ElementType>
BinaryTreeConstLevelOrderIterator<ElementType>::BinaryTreeConstLevelOrderIterator(BinaryTreeNode<ElementType>* node) noexcept {
	if (node != nullptr) {
		nodeQueue.enqueue(node);
	}
}

template<typename ElementType>
const bool BinaryTreeConstLevelOrderIterator<ElementType>::operator==(const BinaryTreeConstLevelOrderIterator<ElementType>& other) const noexcept {
	return nodeQueue == other.nodeQueue;
}

template<typename ElementType>
const ElementType& BinaryTreeConstLevelOrderIterator<ElementType>::operator*() const noexcept {
	assert(!nodeQueue.isEmpty() && "Cannot dereference a null iterator.");
	const auto* const node {nodeQueue.getFront()};
	
	return (*node)->getElement();
}

template<typename ElementType>
const ElementType* const  BinaryTreeConstLevelOrderIterator<ElementType>::operator->() const noexcept {
	assert(!nodeQueue.isEmpty() && "Cannot dereference a null iterator.");
	return nodeQueue.getFront();
}

template<typename ElementType>
BinaryTreeConstLevelOrderIterator<ElementType>& BinaryTreeConstLevelOrderIterator<ElementType>::operator++() noexcept {
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
BinaryTreeConstLevelOrderIterator<ElementType> BinaryTreeConstLevelOrderIterator<ElementType>::operator++(int) noexcept {
	auto iterator {*this};
	++(*this);
	return iterator;
}
}