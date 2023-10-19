#pragma once

#include <iterator>

#include "DataStructures/Trees/BinaryTreeNode.hpp"
#include "DataStructures/Stacks/SinglyLinkedListStack.hpp"

namespace Core::DataStructures::Trees::Iterators {
template<typename ElementType>
class BinaryTreePreOrderIterator final {
public:
	using iterator_category = std::forward_iterator_tag;
	using difference_type = std::ptrdiff_t;
	using value_type = ElementType;
	using reference = ElementType&;
	using pointer = ElementType*;
	
	explicit BinaryTreePreOrderIterator(BinaryTreeNode<ElementType>* node) noexcept;

public:
	const bool operator==(const BinaryTreePreOrderIterator<ElementType>& other) const noexcept;

public:
	reference operator*() const noexcept;
	pointer operator->() const noexcept;
	BinaryTreePreOrderIterator<ElementType>& operator++() noexcept;
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
	return *nodeStack.getTop();
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
	
	const auto node {optionalNode.value()};
	
	if (node.getLeftChild() != nullptr) {
		nodeStack.push(node.getLeftChild());
	}
	
	if (node.getRightChild() != nullptr) {
		nodeStack.push(node.getRightChild());
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