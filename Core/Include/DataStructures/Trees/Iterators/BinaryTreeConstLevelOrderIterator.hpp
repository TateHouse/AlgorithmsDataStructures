#pragma once

#include <iterator>

#include "DataStructures/Trees/BinaryTreeNode.hpp"
#include "DataStructures/Queues/SinglyLinkedListQueue.hpp"

namespace Core::DataStructures::Trees::Iterators {
template<typename ElementType>
class BinaryTreeConstLevelOrderIterator final {
public:
	using iterator_category = std::forward_iterator_tag;
	using difference_type = std::ptrdiff_t;
	using value_type = const ElementType;
	using reference = const ElementType&;
	using pointer = const ElementType* const;
	
	explicit BinaryTreeConstLevelOrderIterator(BinaryTreeNode<ElementType>* node) noexcept;

public:
	const bool operator==(const BinaryTreeConstLevelOrderIterator<ElementType>& other) const noexcept;

public:
	reference operator*() const noexcept;
	pointer operator->() const noexcept;
	BinaryTreeConstLevelOrderIterator<ElementType>& operator++() noexcept;
	BinaryTreeConstLevelOrderIterator<ElementType> operator++(int) noexcept;

private:
	Queues::SinglyLinkedListQueue<BinaryTreeNode<ElementType>*> nodeQueue {};
};

template<typename ElementType>
BinaryTreeConstLevelOrderIterator<ElementType>::BinaryTreeConstLevelOrderIterator(BinaryTreeNode<ElementType>* node) noexcept {
	if (node != nullptr) {
		nodeQueue.enqueue(node);
	}
}

template<typename ElementType>
const bool BinaryTreeConstLevelOrderIterator<ElementType>::operator==(const BinaryTreeConstLevelOrderIterator<ElementType>& other) const noexcept {
	return nodeQueue == other.nodeQueue;
}

template<typename ElementType>
typename BinaryTreeConstLevelOrderIterator<ElementType>::reference BinaryTreeConstLevelOrderIterator<ElementType>::operator*() const noexcept {
	assert(!nodeQueue.isEmpty() && "Cannot dereference a null iterator.");
	return *nodeQueue.getFront();
}

template<typename ElementType>
typename BinaryTreeConstLevelOrderIterator<ElementType>::pointer BinaryTreeConstLevelOrderIterator<ElementType>::operator->() const noexcept {
	assert(!nodeQueue.isEmpty() && "Cannot dereference a null iterator.");
	return nodeQueue.getFront();
}

template<typename ElementType>
BinaryTreeConstLevelOrderIterator<ElementType>& BinaryTreeConstLevelOrderIterator<ElementType>::operator++() noexcept {
	assert(!nodeQueue.isEmpty() && "Cannot increment a null iterator.");
	
	const auto optionalNode {nodeQueue.dequeue()};
	assert(optionalNode.has_value() && "Queue should not be empty.");
	
	const auto node {optionalNode.value()};
	
	if (node.getLeftChild() != nullptr) {
		nodeQueue.enqueue(node.getLeftChild());
	}
	
	if (node.getRightChild() != nullptr) {
		nodeQueue.enqueue(node.getRightChild());
	}
	
	return *this;
}

template<typename ElementType>
BinaryTreeConstLevelOrderIterator<ElementType> BinaryTreeConstLevelOrderIterator<ElementType>::operator++(int) noexcept {
	auto iterator {*this};
	++(*this);
	return iterator;
}
}