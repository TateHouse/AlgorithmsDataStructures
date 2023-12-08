#pragma once

#include <iterator>

#include "DataStructures/Trees/BinaryTreeNode.hpp"
#include "DataStructures/Stacks/SinglyLinkedListStack.hpp"

namespace Core::DataStructures::Trees::Iterators {
/**
 * @brief A const post-order iterator for binary trees.
 * @class BinaryTreeConstPostOrderIterator
 * @tparam ElementType: The type of the elements stored in the binary tree.
 */
template<typename ElementType>
class BinaryTreeConstPostOrderIterator final {
public:
	using iterator_category = std::forward_iterator_tag;
	using difference_type = std::ptrdiff_t;
	using value_type = const ElementType;
	using reference = const ElementType&;
	using pointer = const ElementType* const;
	
	/**
	 * @brief Instantiates a new const post-order iterator for binary trees.
	 * @param node: The node to iterate from.
	 */
	explicit BinaryTreeConstPostOrderIterator(const BinaryTreeNode<ElementType>* node) noexcept;
	
public:
	/**
	 * @brief Compares two const post-order iterators for binary trees.
	 * @details Two const post-order iterators for binary trees are equal if they point to the same node.
	 * @param other: The other const post-order iterator for binary trees to compare with.
	 * @return True if the two const post-order iterators for binary trees are equal, false otherwise.
	 */
	const bool operator==(const BinaryTreeConstPostOrderIterator<ElementType>& other) const noexcept;
	
public:
	/**
	 * @brief Dereferences the const post-order iterator for binary trees.
	 * @return A reference to the element stored in the node pointed to by the const post-order iterator for binary trees.
	 */
	reference operator*() const noexcept;
	
	/**
	 * @brief Dereferences the const post-order iterator for binary trees.
	 * @return A pointer to the element stored in the node pointed to by the const post-order iterator for binary trees.
	 */
	pointer operator->() const noexcept;
	
	/**
	 * @brief Increments the const post-order iterator for binary trees.
	 * @return A reference to the const post-order iterator for binary trees.
	 */
	BinaryTreeConstPostOrderIterator<ElementType>& operator++() noexcept;
	
	/**
	 * @brief Increments the const post-order iterator for binary trees.
	 * @return A copy of the const post-order iterator for binary trees before it was incremented.
	 */
	BinaryTreeConstPostOrderIterator<ElementType> operator++(int) noexcept;
	
private:
	Stacks::SinglyLinkedListStack<const BinaryTreeNode<ElementType>*> nodeStack {};
};

template<typename ElementType>
BinaryTreeConstPostOrderIterator<ElementType>::BinaryTreeConstPostOrderIterator(const BinaryTreeNode<ElementType>* node) noexcept {
	if (node == nullptr) {
		return;
	}
	
	auto stack {Stacks::SinglyLinkedListStack<const BinaryTreeNode<ElementType>*> {}};
	stack.push(node);
	
	while (!stack.isEmpty()) {
		const auto optionalNode {stack.pop()};
		assert(optionalNode.has_value() && "Stack should not be empty.");
		
		const auto& node {optionalNode.value()};
		nodeStack.push(node);
		
		if (node->getLeftChild() != nullptr) {
			stack.push(node->getLeftChild());
		}
		
		if (node->getRightChild() != nullptr) {
			stack.push(node->getRightChild());
		}
	}
}

template<typename ElementType>
const bool BinaryTreeConstPostOrderIterator<ElementType>::operator==(const BinaryTreeConstPostOrderIterator<ElementType>& other) const noexcept {
	return nodeStack == other.nodeStack;
}

template<typename ElementType>
const ElementType& BinaryTreeConstPostOrderIterator<ElementType>::operator*() const noexcept {
	assert(!nodeStack.isEmpty() && "Cannot dereference a null iterator.");
	const auto* const node {*nodeStack.getTop()};
	return node->getElement();
}

template<typename ElementType>
const ElementType* const BinaryTreeConstPostOrderIterator<ElementType>::operator->() const noexcept {
	assert(!nodeStack.isEmpty() && "Cannot dereference a null iterator.");
	return nodeStack.getTop();
}

template<typename ElementType>
BinaryTreeConstPostOrderIterator<ElementType>& BinaryTreeConstPostOrderIterator<ElementType>::operator++() noexcept {
	assert(!nodeStack.isEmpty() && "Cannot increment a null iterator.");
	nodeStack.pop();
	return *this;
}

template<typename ElementType>
BinaryTreeConstPostOrderIterator<ElementType> BinaryTreeConstPostOrderIterator<ElementType>::operator++(int) noexcept {
	auto iterator {*this};
	++(*this);
	return iterator;
}
}