#pragma once

#include <iterator>

#include "DataStructures/Trees/BinaryTreeNode.hpp"
#include "DataStructures/Stacks/SinglyLinkedListStack.hpp"

namespace Core::DataStructures::Trees::Iterators {
/**
 * @brief A post-order iterator for binary trees.
 * @class BinaryTreePostOrderIterator
 * @tparam ElementType: The type of the elements stored in the binary tree.
 */
template<typename ElementType>
class BinaryTreePostOrderIterator final {
public:
	using iterator_category = std::forward_iterator_tag;
	using difference_type = std::ptrdiff_t;
	using value_type = ElementType;
	using reference = ElementType&;
	using pointer = ElementType*;
	
	/**
	 * @brief Instantiates a new post-order iterator for binary trees.
	 * @param node: The node to iterate from.
	 */
	explicit BinaryTreePostOrderIterator(BinaryTreeNode<ElementType>* node) noexcept;

public:
	/**
	 * @brief Compares two post-order iterators for binary trees.
	 * @details Two post-order iterators for binary trees are equal if they point to the same node.
	 * @param other: The other post-order iterator for binary trees to compare with.
	 * @return True if the two post-order iterators for binary trees are equal, false otherwise.
	 */
	const bool operator==(const BinaryTreePostOrderIterator<ElementType>& other) const noexcept;

public:
	/**
	 * @brief Dereferences the post-order iterator for binary trees.
	 * @return A reference to the element stored in the node pointed to by the post-order iterator for binary trees.
	 */
	reference operator*() const noexcept;
	
	/**
	 * @brief Dereferences the post-order iterator for binary trees.
	 * @return A pointer to the element stored in the node pointed to by the post-order iterator for binary trees.
	 */
	pointer operator->() const noexcept;
	
	/**
	 * @brief Increments the post-order iterator for binary trees.
	 * @return A reference to the post-order iterator for binary trees.
	 */
	BinaryTreePostOrderIterator<ElementType>& operator++() noexcept;
	
	/**
	 * @brief Increments the post-order iterator for binary trees.
	 * @return A copy of the post-order iterator for binary trees before it was incremented.
	 */
	BinaryTreePostOrderIterator<ElementType> operator++(int) noexcept;

private:
	Stacks::SinglyLinkedListStack<BinaryTreeNode<ElementType>*> nodeStack {};
};

template<typename ElementType>
BinaryTreePostOrderIterator<ElementType>::BinaryTreePostOrderIterator(BinaryTreeNode<ElementType>* node) noexcept {
	if (node == nullptr) {
		return;
	}
	
	auto stack {Stacks::SinglyLinkedListStack<BinaryTreeNode<ElementType>*> {}};
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
const bool BinaryTreePostOrderIterator<ElementType>::operator==(const BinaryTreePostOrderIterator<ElementType>& other) const noexcept {
	return nodeStack == other.nodeStack;
}

template<typename ElementType>
ElementType& BinaryTreePostOrderIterator<ElementType>::operator*() const noexcept {
	assert(!nodeStack.isEmpty() && "Cannot dereference a null iterator.");
	auto* const node {*nodeStack.getTop()};
	return node->getElement();
}

template<typename ElementType>
ElementType* BinaryTreePostOrderIterator<ElementType>::operator->() const noexcept {
	assert(!nodeStack.isEmpty() && "Cannot dereference a null iterator.");
	return nodeStack.getTop();
}

template<typename ElementType>
BinaryTreePostOrderIterator<ElementType>& BinaryTreePostOrderIterator<ElementType>::operator++() noexcept {
	assert(!nodeStack.isEmpty() && "Cannot increment a null iterator.");
	nodeStack.pop();
	return *this;
}

template<typename ElementType>
BinaryTreePostOrderIterator<ElementType> BinaryTreePostOrderIterator<ElementType>::operator++(int) noexcept {
	auto iterator {*this};
	++(*this);
	return iterator;
}
}