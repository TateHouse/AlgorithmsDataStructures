#pragma once

#include <iterator>

#include "DataStructures/LinkedLists/SinglyLinkedListNode.hpp"

namespace Core::DataStructures::LinkedLists::Iterators {
template<typename ElementType>
class SinglyLinkedListConstForwardIterator final {
public:
	using iterator_category = std::forward_iterator_tag;
	using difference_type = std::ptrdiff_t;
	using value_type = const ElementType;
	using reference = const ElementType&;
	using pointer = const ElementType* const;
	
	explicit SinglyLinkedListConstForwardIterator(SinglyLinkedListNode<ElementType>* node) noexcept;

public:
	const bool operator==(const SinglyLinkedListConstForwardIterator<ElementType>& other) const noexcept;

public:
	reference operator*() const noexcept;
	pointer operator->() const noexcept;
	const SinglyLinkedListConstForwardIterator<ElementType>& operator++() noexcept;
	const SinglyLinkedListConstForwardIterator<ElementType> operator++(int) noexcept;

private:
	SinglyLinkedListNode<ElementType>* node;
};

template<typename ElementType>
SinglyLinkedListConstForwardIterator<ElementType>::SinglyLinkedListConstForwardIterator(SinglyLinkedListNode<ElementType>* node) noexcept:
		node {node} {
	
}

template<typename ElementType>
const bool SinglyLinkedListConstForwardIterator<ElementType>::operator==(const SinglyLinkedListConstForwardIterator<ElementType>& other) const noexcept {
	return node == other.node;
}

template<typename ElementType>
const ElementType& SinglyLinkedListConstForwardIterator<ElementType>::operator*() const noexcept {
	assert(node != nullptr && "Cannot dereference a nullptr node.");
	return node->getElement();
}

template<typename ElementType>
const ElementType* const SinglyLinkedListConstForwardIterator<ElementType>::operator->() const noexcept {
	assert(node != nullptr && "Cannot dereference a nullptr node.");
	return &node->getElement();
}

template<typename ElementType>
const SinglyLinkedListConstForwardIterator<ElementType>& SinglyLinkedListConstForwardIterator<ElementType>::operator++() noexcept {
	assert(node != nullptr && "Cannot increment a nullptr node.");
	node = node->getNextNode();
	return *this;
}

template<typename ElementType>
const SinglyLinkedListConstForwardIterator<ElementType> SinglyLinkedListConstForwardIterator<ElementType>::operator++(int) noexcept {
	assert(node != nullptr && "Cannot increment a nullptr node.");
	const auto iterator {*this};
	node = node->getNextNode();
	return iterator;
}
}