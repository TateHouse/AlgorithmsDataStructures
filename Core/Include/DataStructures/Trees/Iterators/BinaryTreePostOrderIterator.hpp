#pragma once

#include <iterator>

#include "DataStructures/Trees/BinaryTreeNode.hpp"
#include "DataStructures/Stacks/SinglyLinkedListStack.hpp"

namespace Core::DataStructures::Trees::Iterators {
template<typename ElementType>
class BinaryTreePostOrderIterator final {
public:
	using iterator_category = std::forward_iterator_tag;
	using difference_type = std::ptrdiff_t;
	using value_type = ElementType;
	using reference = ElementType&;
	using pointer = ElementType*;
	
	explicit BinaryTreePostOrderIterator(BinaryTreeNode<ElementType>* node) noexcept;

public:
	const bool operator==(const BinaryTreePostOrderIterator<ElementType>& other) const noexcept;

public:
	reference operator*() const noexcept;
	pointer operator->() const noexcept;
	BinaryTreePostOrderIterator<ElementType>& operator++() noexcept;
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