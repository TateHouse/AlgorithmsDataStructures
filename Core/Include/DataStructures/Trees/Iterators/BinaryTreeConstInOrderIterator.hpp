#pragma once

#include <iterator>

#include "DataStructures/Trees/BinaryTreeNode.hpp"
#include "DataStructures/Stacks/SinglyLinkedListStack.hpp"

namespace Core::DataStructures::Trees::Iterators {
/**
 * @brief A const in-order iterator for binary trees.
 * @class BinaryTreeConstInOrderIterator
 * @tparam ElementType: The type of the elements stored in the binary tree.
 */
template<typename ElementType>
class BinaryTreeConstInOrderIterator final {
public:
	using iterator_category = std::forward_iterator_tag;
	using difference_type = std::ptrdiff_t;
	using value_type = const ElementType;
	using reference = const ElementType&;
	using pointer = const ElementType* const;
	
	/**
	 * @brief Instantiates a new const in-order iterator for binary trees.
	 * @param node: The node to iterate from.
	 */
	explicit BinaryTreeConstInOrderIterator(const BinaryTreeNode<ElementType>* node) noexcept;
	
	/**
	 * @brief Instantiates a new const in-order iterator for binary trees by copying the given const in-order iterator
	 * for binary trees.
	 * @param other The const in-order iterator for binary trees to copy.
	 */
	BinaryTreeConstInOrderIterator(const BinaryTreeConstInOrderIterator<ElementType>& other) = default;
	
	/**
	 * @brief Instantiates a new const in-order iterator for binary trees by moving the given const in-order iterator
	 * for binary trees.
	 * @param other The const in-order iterator for binary trees to move.
	 */
	BinaryTreeConstInOrderIterator(BinaryTreeConstInOrderIterator<ElementType>&& other) noexcept = default;
	
	/**
	 * @brief Destroys the const in-order iterator for binary trees.
	 */
	~BinaryTreeConstInOrderIterator() noexcept = default;

public:
	/**
	 * @brief Assigns the given const in-order iterator for binary trees to this const in-order iterator for binary
	 * trees using copy semantics.
	 * @param other The const in-order iterator for binary trees to copy.
	 * @return A reference to the const in-order iterator for binary trees.
	 */
	BinaryTreeConstInOrderIterator<ElementType>& operator=(const BinaryTreeConstInOrderIterator<ElementType>& other) = default;
	
	/**
	 * @brief Assigns the given const in-order iterator for binary trees to this const in-order iterator for binary
	 * trees using move semantics.
	 * @param other The const in-order iterator for binary trees to move.
	 * @return A reference to the const in-order iterator for binary trees.
	 */
	BinaryTreeConstInOrderIterator<ElementType>& operator=(BinaryTreeConstInOrderIterator<ElementType>&& other) noexcept = default;
	
	/**
	 * @brief Compares two const in-order iterators for binary trees.
	 * @details Two const in-order iterators for binary trees are equal if they point to the same node.
	 * @param other: The other const in-order iterator for binary trees to compare with.
	 * @return True if the two const in-order iterators for binary trees are equal, false otherwise.
	 */
	const bool operator==(const BinaryTreeConstInOrderIterator<ElementType>& other) const noexcept;

	/**
	 * @brief Dereferences the const in-order iterator for binary trees.
	 * @return A reference to the element stored in the node pointed to by the const in-order iterator for binary trees.
	 */
	reference operator*() const noexcept;
	
	/**
	 * @brief Dereferences the const in-order iterator for binary trees.
	 * @return A pointer to the element stored in the node pointed to by the const in-order iterator for binary trees.
	 */
	pointer operator->() const noexcept;
	
/**
	 * @brief Increments the const in-order iterator for binary trees.
	 * @return A reference to the const in-order iterator for binary trees.
	 */
	BinaryTreeConstInOrderIterator<ElementType>& operator++() noexcept;
	
	/**
	 * @brief Increments the const in-order iterator for binary trees.
	 * @return A copy of the const in-order iterator for binary trees before it was incremented.
	 */
	BinaryTreeConstInOrderIterator<ElementType> operator++(int) noexcept;

private:
	Stacks::SinglyLinkedListStack<const BinaryTreeNode<ElementType>*> nodeStack {};
};

template<typename ElementType>
BinaryTreeConstInOrderIterator<ElementType>::BinaryTreeConstInOrderIterator(const BinaryTreeNode<ElementType>* node) noexcept {
	while (node != nullptr) {
		nodeStack.push(node);
		node = node->getLeftChild();
	}
}

template<typename ElementType>
const bool BinaryTreeConstInOrderIterator<ElementType>::operator==(const BinaryTreeConstInOrderIterator<ElementType>& other) const noexcept {
	return nodeStack == other.nodeStack;
}

template<typename ElementType>
const ElementType& BinaryTreeConstInOrderIterator<ElementType>::operator*() const noexcept {
	assert(!nodeStack.isEmpty() && "Cannot dereference a null iterator.");
	const auto* const node {*nodeStack.getTop()};
	return node->getElement();
}

template<typename ElementType>
const ElementType* const BinaryTreeConstInOrderIterator<ElementType>::operator->() const noexcept {
	assert(!nodeStack.isEmpty() && "Cannot dereference a null iterator.");
	return nodeStack.getTop();
}

template<typename ElementType>
BinaryTreeConstInOrderIterator<ElementType>& BinaryTreeConstInOrderIterator<ElementType>::operator++() noexcept {
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
BinaryTreeConstInOrderIterator<ElementType> BinaryTreeConstInOrderIterator<ElementType>::operator++(int) noexcept {
	const auto iterator {*this};
	++(*this);
	return iterator;
}
}