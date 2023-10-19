#pragma once

#include <iterator>

#include "DataStructures/Trees/BinaryTreeNode.hpp"
#include "DataStructures/Stacks/SinglyLinkedListStack.hpp"

namespace Core::DataStructures::Trees::Iterators {
template<typename ElementType>
class BinaryTreeConstInOrderIterator final {
public:
	using iterator_category = std::forward_iterator_tag;
	using difference_type = std::ptrdiff_t;
	using value_type = const ElementType;
	using reference = const ElementType&;
	using pointer = const ElementType* const;
	
	explicit BinaryTreeConstInOrderIterator(const BinaryTreeNode<ElementType>* node) noexcept;

public:
	const bool operator==(const BinaryTreeConstInOrderIterator<ElementType>& other) const noexcept;

public:
	reference operator*() const noexcept;
	pointer operator->() const noexcept;
	BinaryTreeConstInOrderIterator<ElementType>& operator++() noexcept;
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
	return *nodeStack.getTop();
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
	
	const auto node {optionalNode.value()};
	
	if (auto* rightChild {node.getRightChild()}; rightChild != nullptr) {
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