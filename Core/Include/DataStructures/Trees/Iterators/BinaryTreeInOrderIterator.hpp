#pragma once

#include <iterator>

#include "DataStructures/Trees/BinaryTreeNode.hpp"
#include "DataStructures/Stacks/SinglyLinkedListStack.hpp"

namespace Core::DataStructures::Trees::Iterators {
/**
 * @brief An in-order iterator for binary trees.
 * @class BinaryTreeInOrderIterator
 * @tparam ElementType: The type of the elements stored in the binary tree.
 */
template<typename ElementType>
class BinaryTreeInOrderIterator final {
public:
	using iterator_category = std::forward_iterator_tag;
	using difference_type = std::ptrdiff_t;
	using value_type = ElementType;
	using reference = ElementType&;
	using pointer = ElementType*;
	
	/**
	 * @brief Instantiates a new in-order iterator for binary trees.
	 * @param node: The node to iterate from.
	 */
	explicit BinaryTreeInOrderIterator(BinaryTreeNode<ElementType>* node) noexcept;

public:
	/**
	 * @brief Compares two in-order iterators for binary trees.
	 * @details Two in-order iterators for binary trees are equal if they point to the same node.
	 * @param other: The other in-order iterator for binary trees to compare with.
	 * @return True if the two in-order iterators for binary trees are equal, false otherwise.
	 */
	const bool operator==(const BinaryTreeInOrderIterator<ElementType>& other) const noexcept;

public:
	/**
	 * @brief Dereferences the in-order iterator for binary trees.
	 * @return A reference to the element stored in the node pointed to by the in-order iterator for binary trees.
	 */
	reference operator*() const noexcept;
	
	/**
	 * @brief Dereferences the in-order iterator for binary trees.
	 * @return A pointer to the element stored in the node pointed to by the in-order iterator for binary trees.
	 */
	pointer operator->() const noexcept;
	
	/**
	 * @brief Increments the in-order iterator for binary trees.
	 * @return A reference to the in-order iterator for binary trees.
	 */
	BinaryTreeInOrderIterator<ElementType>& operator++() noexcept;
	
	/**
	 * @brief Increments the in-order iterator for binary trees.
	 * @return A copy of the in-order iterator for binary trees before it was incremented.
	 */
	BinaryTreeInOrderIterator<ElementType> operator++(int) noexcept;

private:
	Stacks::SinglyLinkedListStack<BinaryTreeNode<ElementType>*> nodeStack {};
};

template<typename ElementType>
BinaryTreeInOrderIterator<ElementType>::BinaryTreeInOrderIterator(BinaryTreeNode<ElementType>* node) noexcept {
	while (node != nullptr) {
		nodeStack.push(node);
		node = node->getLeftChild();
	}
}

template<typename ElementType>
const bool BinaryTreeInOrderIterator<ElementType>::operator==(const BinaryTreeInOrderIterator<ElementType>& other) const noexcept {
	return nodeStack == other.nodeStack;
}

template<typename ElementType>
ElementType& BinaryTreeInOrderIterator<ElementType>::operator*() const noexcept {
	assert(!nodeStack.isEmpty() && "Cannot dereference a null iterator.");
	auto* const node {*nodeStack.getTop()};
	return node->getElement();
}

template<typename ElementType>
ElementType* BinaryTreeInOrderIterator<ElementType>::operator->() const noexcept {
	assert(!nodeStack.isEmpty() && "Cannot dereference a null iterator.");
	return nodeStack.getTop();
}

template<typename ElementType>
BinaryTreeInOrderIterator<ElementType>& BinaryTreeInOrderIterator<ElementType>::operator++() noexcept {
	assert(!nodeStack.isEmpty() && "Cannot increment a null iterator.");
	
	const auto optionalNode {nodeStack.pop()};
	assert(optionalNode.has_value() && "Cannot increment a null iterator.");
	
	const auto& node {optionalNode.value()};
	
	if (auto* rightChild {node->getRightChild()}; rightChild != nullptr) {
		auto currentNode {rightChild};
		
		while (currentNode != nullptr) {
			nodeStack.push(currentNode);
			currentNode = currentNode->getLeftChild();
		}
	}
	
	return *this;
}

template<typename ElementType>
BinaryTreeInOrderIterator<ElementType> BinaryTreeInOrderIterator<ElementType>::operator++(int) noexcept {
	auto iterator {*this};
	++(*this);
	return iterator;
}
}