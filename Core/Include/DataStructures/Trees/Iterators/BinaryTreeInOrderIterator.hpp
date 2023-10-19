#pragma once

#include <iterator>

#include "DataStructures/Trees/BinaryTreeNode.hpp"
#include "DataStructures/Stacks/SinglyLinkedListStack.hpp"

namespace Core::DataStructures::Trees::Iterators {
template<typename ElementType>
class BinaryTreeInOrderIterator final {
public:
	using iterator_category = std::forward_iterator_tag;
	using difference_type = std::ptrdiff_t;
	using value_type = ElementType;
	using reference = ElementType&;
	using pointer = ElementType*;
	
	explicit BinaryTreeInOrderIterator(BinaryTreeNode<ElementType>* node) noexcept;

public:
	const bool operator==(const BinaryTreeInOrderIterator<ElementType>& other) const noexcept;

public:
	reference operator*() const noexcept;
	pointer operator->() const noexcept;
	BinaryTreeInOrderIterator<ElementType>& operator++() noexcept;
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
	return *nodeStack.getTop();
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
BinaryTreeInOrderIterator<ElementType> BinaryTreeInOrderIterator<ElementType>::operator++(int) noexcept {
	auto iterator {*this};
	++(*this);
	return iterator;
}
}