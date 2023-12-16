#pragma once

#include <iterator>

#include "DataStructures/Trees/BinaryTreeNode.hpp"
#include "DataStructures/Stacks/SinglyLinkedListStack.hpp"

namespace Core::DataStructures::Trees::Iterators {
/**
 * @brief A const pre-order iterator for binary trees.
 * @class BinaryTreeConstPreOrderIterator
 * @tparam ElementType: The type of the elements stored in the binary tree.
 */
template<typename ElementType>
class BinaryTreeConstPreOrderIterator final {
public:
	using iterator_category = std::forward_iterator_tag;
	using difference_type = std::ptrdiff_t;
	using value_type = const ElementType;
	using reference = const ElementType&;
	using pointer = const ElementType* const;
	
	/**
	 * @brief Instantiates a new const pre-order iterator for binary trees.
	 * @param node: The node to iterate from.
	 */
	explicit BinaryTreeConstPreOrderIterator(BinaryTreeNode<ElementType>* node) noexcept;
	
	/**
	 * @brief Instantiates a new const pre-order iterator for binary trees by copying the given const pre-order
	 * iterator for binary trees.
	 * @param other The const pre-order iterator for binary trees to copy.
	 */
	BinaryTreeConstPreOrderIterator(const BinaryTreeConstPreOrderIterator<ElementType>& other) = default;
	
	/**
	 * @brief Instantiates a new const pre-order iterator for binary trees by moving the given const pre-order
	 * iterator for binary trees.
	 * @param other The const pre-order iterator for binary trees to move.
	 */
	BinaryTreeConstPreOrderIterator(BinaryTreeConstPreOrderIterator<ElementType>&& other) noexcept = default;
	
	/**
	 * @brief Destroys the const pre-order iterator for binary trees.
	 */
	~BinaryTreeConstPreOrderIterator() noexcept = default;

public:
	/**
	 * @brief Assigns the given const pre-order iterator for binary trees to this const pre-order iterator for
	 * binary trees using copy semantics.
	 * @param other The const pre-order iterator for binary trees to copy.
	 * @return A reference to the const pre-order iterator for binary trees.
	 */
	BinaryTreeConstPreOrderIterator<ElementType>& operator=(const BinaryTreeConstPreOrderIterator<ElementType>& other) = default;
	
	/**
	 * @brief Assigns the given const pre-order iterator for binary trees to this const pre-order iterator for
	 * binary trees using move semantics.
	 * @param other The const pre-order iterator for binary trees to move.
	 * @return A reference to the const pre-order iterator for binary trees.
	 */
	BinaryTreeConstPreOrderIterator<ElementType>& operator=(BinaryTreeConstPreOrderIterator<ElementType>&& other) noexcept = default;
	
	/**
	 * @brief Compares two const pre-order iterators for binary trees.
	 * @details Two const pre-order iterators for binary trees are equal if they point to the same node.
	 * @param other: The other const pre-order iterator for binary trees to compare with.
	 * @return True if the two const pre-order iterators for binary trees are equal, false otherwise.
	 */
	const bool operator==(const BinaryTreeConstPreOrderIterator<ElementType>& other) const noexcept;

	/**
	 * @brief Dereferences the const pre-order iterator for binary trees.
	 * @return A reference to the element stored in the node pointed to by the const pre-order iterator for binary trees.
	 */
	reference operator*() const noexcept;
	
	/**
	 * @brief Dereferences the const pre-order iterator for binary trees.
	 * @return A pointer to the element stored in the node pointed to by the const pre-order iterator for binary trees.
	 */
	pointer operator->() const noexcept;
	
	/**
	 * @brief Increments the const pre-order iterator for binary trees.
	 * @return A reference to the const pre-order iterator for binary trees.
	 */
	BinaryTreeConstPreOrderIterator<ElementType>& operator++() noexcept;
	
	/**
	 * @brief Increments the const pre-order iterator for binary trees.
	 * @return A copy of the const pre-order iterator for binary trees before it was incremented.
	 */
	BinaryTreeConstPreOrderIterator<ElementType> operator++(int) noexcept;

private:
	Stacks::SinglyLinkedListStack<BinaryTreeNode<ElementType>*> nodeStack {};
};

template<typename ElementType>
BinaryTreeConstPreOrderIterator<ElementType>::BinaryTreeConstPreOrderIterator(BinaryTreeNode<ElementType>* node) noexcept {
	if (node != nullptr) {
		nodeStack.push(node);
	}
}

template<typename ElementType>
const bool BinaryTreeConstPreOrderIterator<ElementType>::operator==(const BinaryTreeConstPreOrderIterator<ElementType>& other) const noexcept {
	return nodeStack == other.nodeStack;
}

template<typename ElementType>
const ElementType& BinaryTreeConstPreOrderIterator<ElementType>::operator*() const noexcept {
	assert(!nodeStack.isEmpty() && "Cannot dereference a null iterator.");
	const auto* const node {*nodeStack.getTop()};
	return node->getElement();
}

template<typename ElementType>
const ElementType* const BinaryTreeConstPreOrderIterator<ElementType>::operator->() const noexcept {
	assert(!nodeStack.isEmpty() && "Cannot dereference a null iterator.");
	return nodeStack.getTop();
}

template<typename ElementType>
BinaryTreeConstPreOrderIterator<ElementType>& BinaryTreeConstPreOrderIterator<ElementType>::operator++() noexcept {
	assert(!nodeStack.isEmpty() && "Cannot increment a null iterator.");
	
	const auto optionalNode {nodeStack.pop()};
	assert(optionalNode.has_value() && "Cannot dereference a null iterator.");
	
	const auto& node {optionalNode.value()};
	
	if (node->getRightChild() != nullptr) {
		nodeStack.push(node->getRightChild());
	}
	
	if (node->getLeftChild() != nullptr) {
		nodeStack.push(node->getLeftChild());
	}
	
	return *this;
}

template<typename ElementType>
BinaryTreeConstPreOrderIterator<ElementType> BinaryTreeConstPreOrderIterator<ElementType>::operator++(int) noexcept {
	auto iterator {*this};
	++(*this);
	return iterator;
}
}