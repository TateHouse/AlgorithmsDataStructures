#pragma once

#include <iterator>

#include "DataStructures/Trees/BinaryTreeNode.hpp"
#include "DataStructures/Stacks/SinglyLinkedListStack.hpp"

namespace Core::DataStructures::Trees::Iterators {
template<typename ElementType>
class BinaryTreeConstPreOrderIterator final {
public:
	using iterator_category = std::forward_iterator_tag;
	using difference_type = std::ptrdiff_t;
	using value_type = const ElementType;
	using reference = const ElementType&;
	using pointer = const ElementType* const;
	
	explicit BinaryTreeConstPreOrderIterator(BinaryTreeNode<ElementType>* node) noexcept;
	
public:
	const bool operator==(const BinaryTreeConstPreOrderIterator<ElementType>& other) const noexcept;
	
public:
	reference operator*() const noexcept;
	pointer operator->() const noexcept;
	BinaryTreeConstPreOrderIterator<ElementType>& operator++() noexcept;
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
	return *nodeStack.getTop();
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
BinaryTreeConstPreOrderIterator<ElementType> BinaryTreeConstPreOrderIterator<ElementType>::operator++(int) noexcept {
	auto iterator {*this};
	++(*this);
	return iterator;
}
}