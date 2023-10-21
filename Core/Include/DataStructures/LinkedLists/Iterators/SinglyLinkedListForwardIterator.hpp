#pragma once

#include <iterator>

#include "DataStructures/LinkedLists/SinglyLinkedListNode.hpp"

namespace Core::DataStructures::LinkedLists::Iterators {
template<typename ElementType>
class SinglyLinkedListForwardIterator final {
public:
	using iterator_category = std::forward_iterator_tag;
	using difference_type = std::ptrdiff_t;
	using value_type = ElementType;
	using reference = ElementType&;
	using pointer = ElementType*;
	
	explicit SinglyLinkedListForwardIterator(SinglyLinkedListNode<ElementType>* node) noexcept;

public:
	const bool operator==(const SinglyLinkedListForwardIterator<ElementType>& other) const noexcept;

public:
	reference operator*() const noexcept;
	pointer operator->() const noexcept;
	SinglyLinkedListForwardIterator<ElementType>& operator++() noexcept;
	SinglyLinkedListForwardIterator<ElementType> operator++(int) noexcept;

private:
	SinglyLinkedListNode<ElementType>* node;
};

template<typename ElementType>
SinglyLinkedListForwardIterator<ElementType>::SinglyLinkedListForwardIterator(SinglyLinkedListNode<ElementType>* node) noexcept:
		node {node} {
	
}

template<typename ElementType>
const bool SinglyLinkedListForwardIterator<ElementType>::operator==(const SinglyLinkedListForwardIterator<ElementType>& other) const noexcept {
	return node == other.node;
}

template<typename ElementType>
ElementType& SinglyLinkedListForwardIterator<ElementType>::operator*() const noexcept {
	assert(node != nullptr && "Cannot dereference a null iterator.");
	return node->getElement();
}

template<typename ElementType>
ElementType* SinglyLinkedListForwardIterator<ElementType>::operator->() const noexcept {
	assert(node != nullptr && "Cannot dereference a null iterator.");
	return &node->getElement();
}

template<typename ElementType>
SinglyLinkedListForwardIterator<ElementType>& SinglyLinkedListForwardIterator<ElementType>::operator++() noexcept {
	assert(node != nullptr && "Cannot increment a null iterator.");
	node = node->getNextNode();
	return *this;
}

template<typename ElementType>
SinglyLinkedListForwardIterator<ElementType> SinglyLinkedListForwardIterator<ElementType>::operator++(int) noexcept {
	assert(node != nullptr && "Cannot increment a null iterator.");
	auto iterator {*this};
	node = node->getNextNode();
	return iterator;
}
}