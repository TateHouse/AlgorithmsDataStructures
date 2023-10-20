#pragma once

#include <iterator>

#include "DataStructures/Trees/BinaryTreeNode.hpp"
#include "DataStructures/Queues/SinglyLinkedListQueue.hpp"

namespace Core::DataStructures::Trees::Iterators {
template<typename ElementType>
class BinaryTreeLevelOrderIterator final {
public:
	using iterator_category = std::forward_iterator_tag;
	using difference_type = std::ptrdiff_t;
	using value_type = ElementType;
	using reference = ElementType&;
	using pointer = ElementType*;
	
	explicit BinaryTreeLevelOrderIterator(BinaryTreeNode<ElementType>* node) noexcept;

public:
	const bool operator==(const BinaryTreeLevelOrderIterator<ElementType>& other) const noexcept;

public:
	reference operator*() const noexcept;
	pointer operator->() const noexcept;
	BinaryTreeLevelOrderIterator<ElementType>& operator++() noexcept;
	BinaryTreeLevelOrderIterator<ElementType> operator++(int) noexcept;

private:
	Queues::SinglyLinkedListQueue<BinaryTreeNode<ElementType>*> nodeQueue {};
};

template<typename ElementType>
BinaryTreeLevelOrderIterator<ElementType>::BinaryTreeLevelOrderIterator(BinaryTreeNode<ElementType>* node) noexcept {
	if (node != nullptr) {
		nodeQueue.enqueue(node);
	}
}

template<typename ElementType>
const bool BinaryTreeLevelOrderIterator<ElementType>::operator==(const BinaryTreeLevelOrderIterator<ElementType>& other) const noexcept {
	return nodeQueue == other.nodeQueue;
}

template<typename ElementType>
ElementType& BinaryTreeLevelOrderIterator<ElementType>::operator*() const noexcept {
	assert(!nodeQueue.isEmpty() && "Cannot dereference a null iterator.");
	const auto* const node {nodeQueue.getFront()};
	
	return (*node)->getElement();
}

template<typename ElementType>
ElementType* BinaryTreeLevelOrderIterator<ElementType>::operator->() const noexcept {
	assert(!nodeQueue.isEmpty() && "Cannot dereference a null iterator.");
	return nodeQueue.getFront();
}

template<typename ElementType>
BinaryTreeLevelOrderIterator<ElementType>& BinaryTreeLevelOrderIterator<ElementType>::operator++() noexcept {
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
BinaryTreeLevelOrderIterator<ElementType> BinaryTreeLevelOrderIterator<ElementType>::operator++(int) noexcept {
	auto iterator {*this};
	++(*this);
	return iterator;
}
}