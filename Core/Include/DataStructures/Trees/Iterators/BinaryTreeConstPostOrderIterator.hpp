#pragma once

#include <iterator>

#include "DataStructures/Trees/BinaryTreeNode.hpp"
#include "DataStructures/Stacks/SinglyLinkedListStack.hpp"

namespace Core::DataStructures::Trees::Iterators {
template<typename ElementType>
class BinaryTreeConstPostOrderIterator final {
public:
	using iterator_category = std::forward_iterator_tag;
	using difference_type = std::ptrdiff_t;
	using value_type = const ElementType;
	using reference = const ElementType&;
	using pointer = const ElementType* const;
	
	explicit BinaryTreeConstPostOrderIterator(const BinaryTreeNode<ElementType>* node) noexcept;
	
public:
	const bool operator==(const BinaryTreeConstPostOrderIterator<ElementType>& other) const noexcept;
	
public:
	reference operator*() const noexcept;
	pointer operator->() const noexcept;
	BinaryTreeConstPostOrderIterator<ElementType>& operator++() noexcept;
	BinaryTreeConstPostOrderIterator<ElementType> operator++(int) noexcept;
	
private:
	Stacks::SinglyLinkedListStack<const BinaryTreeNode<ElementType>*> nodeStack {};
};

template<typename ElementType>
BinaryTreeConstPostOrderIterator<ElementType>::BinaryTreeConstPostOrderIterator(const BinaryTreeNode<ElementType>* node) noexcept {
	if (node == nullptr) {
		return;
	}
	
	auto stack {Stacks::SinglyLinkedListStack<const BinaryTreeNode<ElementType>*> {}};
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
const bool BinaryTreeConstPostOrderIterator<ElementType>::operator==(const BinaryTreeConstPostOrderIterator<ElementType>& other) const noexcept {
	return nodeStack == other.nodeStack;
}

template<typename ElementType>
const ElementType& BinaryTreeConstPostOrderIterator<ElementType>::operator*() const noexcept {
	assert(!nodeStack.isEmpty() && "Cannot dereference a null iterator.");
	const auto* const node {*nodeStack.getTop()};
	return node->getElement();
}

template<typename ElementType>
const ElementType* const BinaryTreeConstPostOrderIterator<ElementType>::operator->() const noexcept {
	assert(!nodeStack.isEmpty() && "Cannot dereference a null iterator.");
	return nodeStack.getTop();
}

template<typename ElementType>
BinaryTreeConstPostOrderIterator<ElementType>& BinaryTreeConstPostOrderIterator<ElementType>::operator++() noexcept {
	assert(!nodeStack.isEmpty() && "Cannot increment a null iterator.");
	nodeStack.pop();
	return *this;
}

template<typename ElementType>
BinaryTreeConstPostOrderIterator<ElementType> BinaryTreeConstPostOrderIterator<ElementType>::operator++(int) noexcept {
	auto iterator {*this};
	++(*this);
	return iterator;
}
}