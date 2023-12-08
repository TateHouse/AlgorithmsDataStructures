#pragma once

#include <iterator>

#include "DataStructures/Trees/BinaryTreeNode.hpp"
#include "DataStructures/Stacks/SinglyLinkedListStack.hpp"

namespace Core::DataStructures::Trees::Iterators {
/**
 * @brief A pre-order iterator for binary trees.
 * @class BinaryTreePreOrderIterator
 * @tparam ElementType: The type of the elements stored in the binary tree.
 */
template<typename ElementType>
class BinaryTreePreOrderIterator final {
public:
	using iterator_category = std::forward_iterator_tag;
	using difference_type = std::ptrdiff_t;
	using value_type = ElementType;
	using reference = ElementType&;
	using pointer = ElementType*;
	
	/**
	 * @brief Instantiates a new pre-order iterator for binary trees.
	 * @param node: The node to iterate from.
	 */
	explicit BinaryTreePreOrderIterator(BinaryTreeNode<ElementType>* node) noexcept;

public:
	/**
	 * @brief Compares two pre-order iterators for binary trees.
	 * @details Two pre-order iterators for binary trees are equal if they point to the same node.
	 * @param other: The other pre-order iterator for binary trees to compare with.
	 * @return True if the two pre-order iterators for binary trees are equal, false otherwise.
	 */
	const bool operator==(const BinaryTreePreOrderIterator<ElementType>& other) const noexcept;

public:
	/**
	 * @brief Dereferences the pre-order iterator for binary trees.
	 * @return A reference to the element stored in the node pointed to by the pre-order iterator for binary trees.
	 */
	reference operator*() const noexcept;
	
	/**
	 * @brief Dereferences the pre-order iterator for binary trees.
	 * @return A pointer to the element stored in the node pointed to by the pre-order iterator for binary trees.
	 */
	pointer operator->() const noexcept;
	
	/**
	 * @brief Increments the pre-order iterator for binary trees.
	 * @return A reference to the pre-order iterator for binary trees.
	 */
	BinaryTreePreOrderIterator<ElementType>& operator++() noexcept;
	
	/**
	 * @brief Increments the pre-order iterator for binary trees.
	 * @return A copy of the pre-order iterator for binary trees before it was incremented.
	 */
	BinaryTreePreOrderIterator<ElementType> operator++(int) noexcept;

private:
	Stacks::SinglyLinkedListStack<BinaryTreeNode<ElementType>*> nodeStack {};
};

template<typename ElementType>
BinaryTreePreOrderIterator<ElementType>::BinaryTreePreOrderIterator(BinaryTreeNode<ElementType>* node) noexcept {
	if (node != nullptr) {
		nodeStack.push(node);
	}
}

template<typename ElementType>
const bool BinaryTreePreOrderIterator<ElementType>::operator==(const BinaryTreePreOrderIterator<ElementType>& other) const noexcept {
	return nodeStack == other.nodeStack;
}

template<typename ElementType>
ElementType& BinaryTreePreOrderIterator<ElementType>::operator*() const noexcept {
	assert(!nodeStack.isEmpty() && "Cannot dereference a null iterator.");
	auto* const node {*nodeStack.getTop()};
	return node->getElement();
}

template<typename ElementType>
ElementType* BinaryTreePreOrderIterator<ElementType>::operator->() const noexcept {
	assert(!nodeStack.isEmpty() && "Cannot dereference a null iterator.");
	return nodeStack.getTop();
}

template<typename ElementType>
BinaryTreePreOrderIterator<ElementType>& BinaryTreePreOrderIterator<ElementType>::operator++() noexcept {
	assert(!nodeStack.isEmpty() && "Cannot increment a null iterator.");
	
	const auto optionalNode {nodeStack.pop()};
	assert(optionalNode.has_value() && "Cannot increment a null iterator.");
	
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
BinaryTreePreOrderIterator<ElementType> BinaryTreePreOrderIterator<ElementType>::operator++(int) noexcept {
	auto iterator {*this};
	++(*this);
	return iterator;
}
}