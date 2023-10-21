#pragma once

#include <iterator>

#include "DataStructures/LinkedLists/DoublyLinkedListNode.hpp"

namespace Core::DataStructures::LinkedLists::Iterators {
template<typename ElementType>
class DoublyLinkedListBidirectionalIterator final {
public:
	using iterator_category = std::bidirectional_iterator_tag;
	using difference_type = std::ptrdiff_t;
	using value_type = ElementType;
	using reference = ElementType&;
	using pointer = ElementType*;
	
	explicit DoublyLinkedListBidirectionalIterator(DoublyLinkedListNode<ElementType>* node) noexcept;

public:
	const bool operator==(const DoublyLinkedListBidirectionalIterator<ElementType>& other) const noexcept;

public:
	reference operator*() const noexcept;
	pointer operator->() const noexcept;
	DoublyLinkedListBidirectionalIterator<ElementType>& operator++() noexcept;
	DoublyLinkedListBidirectionalIterator<ElementType> operator++(int) noexcept;
	DoublyLinkedListBidirectionalIterator<ElementType>& operator--() noexcept;
	DoublyLinkedListBidirectionalIterator<ElementType> operator--(int) noexcept;

private:
	DoublyLinkedListNode<ElementType>* node;
};

template<typename ElementType>
DoublyLinkedListBidirectionalIterator<ElementType>::DoublyLinkedListBidirectionalIterator(DoublyLinkedListNode<ElementType>* node) noexcept:
		node {node} {
	
}

template<typename ElementType>
const bool DoublyLinkedListBidirectionalIterator<ElementType>::operator==(const DoublyLinkedListBidirectionalIterator<ElementType>& other) const noexcept {
	return node == other.node;
}

template<typename ElementType>
ElementType& DoublyLinkedListBidirectionalIterator<ElementType>::operator*() const noexcept {
	assert(node != nullptr && "Cannot dereference a null iterator.");
	return node->getElement();
}

template<typename ElementType>
ElementType* DoublyLinkedListBidirectionalIterator<ElementType>::operator->() const noexcept {
	assert(node != nullptr && "Cannot dereference a null iterator.");
	return &node->getElement();
}

template<typename ElementType>
DoublyLinkedListBidirectionalIterator<ElementType>& DoublyLinkedListBidirectionalIterator<ElementType>::operator++() noexcept {
	assert(node != nullptr && "Cannot increment a null iterator.");
	node = node->getNextNode();
	return *this;
}

template<typename ElementType>
DoublyLinkedListBidirectionalIterator<ElementType> DoublyLinkedListBidirectionalIterator<ElementType>::operator++(int) noexcept {
	assert(node != nullptr && "Cannot increment a null iterator.");
	const auto iterator {*this};
	node = node->getNextNode();
	return iterator;
}

template<typename ElementType>
DoublyLinkedListBidirectionalIterator<ElementType>& DoublyLinkedListBidirectionalIterator<ElementType>::operator--() noexcept {
	assert(node != nullptr && "Cannot decrement a null iterator.");
	node = node->getPreviousNode();
	return *this;
}

template<typename ElementType>
DoublyLinkedListBidirectionalIterator<ElementType> DoublyLinkedListBidirectionalIterator<ElementType>::operator--(int) noexcept {
	assert(node != nullptr && "Cannot decrement a null iterator.");
	const auto iterator {*this};
	node = node->getPreviousNode();
	return iterator;
}
}