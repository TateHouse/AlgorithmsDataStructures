#pragma once

#include <format>
#include <iterator>
#include <stdexcept>

#include "DataStructures/LinkedLists/DoublyLinkedListNode.hpp"

namespace Core::DataStructures::LinkedLists::Iterators {
template<typename ElementType>
class DoublyLinkedListConstBidirectionalIterator final {
public:
	using iterator_category = std::bidirectional_iterator_tag;
	using difference_type = std::ptrdiff_t;
	using value_type = const ElementType;
	using reference = const ElementType&;
	using pointer = const ElementType* const;
	
	explicit DoublyLinkedListConstBidirectionalIterator(DoublyLinkedListNode<ElementType>* const node) noexcept;

public:
	const bool operator==(const DoublyLinkedListConstBidirectionalIterator<ElementType>& other) const noexcept;

public:
	reference operator*() const noexcept;
	pointer operator->() const noexcept;
	const DoublyLinkedListConstBidirectionalIterator<ElementType>& operator++() noexcept;
	const DoublyLinkedListConstBidirectionalIterator<ElementType> operator++(int) noexcept;
	const DoublyLinkedListConstBidirectionalIterator<ElementType>& operator--() noexcept;
	const DoublyLinkedListConstBidirectionalIterator<ElementType> operator--(int) noexcept;

private:
	DoublyLinkedListNode<ElementType>* node;
};

template<typename ElementType>
DoublyLinkedListConstBidirectionalIterator<ElementType>::DoublyLinkedListConstBidirectionalIterator(DoublyLinkedListNode<ElementType>* const node) noexcept:
		node {node} {
	
}

template<typename ElementType>
const bool DoublyLinkedListConstBidirectionalIterator<ElementType>::operator==(const DoublyLinkedListConstBidirectionalIterator<ElementType>& other) const noexcept {
	return node == other.node;
}

template<typename ElementType>
const ElementType& DoublyLinkedListConstBidirectionalIterator<ElementType>::operator*() const noexcept {
	assert(node != nullptr && "Cannot dereference a null iterator.");
	return node->getElement();
}

template<typename ElementType>
const ElementType* const DoublyLinkedListConstBidirectionalIterator<ElementType>::operator->() const noexcept {
	assert(node != nullptr && "Cannot dereference a null iterator.");
	return &node->getElement();
}

template<typename ElementType>
const DoublyLinkedListConstBidirectionalIterator<ElementType>& DoublyLinkedListConstBidirectionalIterator<ElementType>::operator++() noexcept {
	assert(node != nullptr && "Cannot increment a null iterator.");
	node = node->getNextNode();
	return *this;
}

template<typename ElementType>
const DoublyLinkedListConstBidirectionalIterator<ElementType> DoublyLinkedListConstBidirectionalIterator<ElementType>::operator++(int) noexcept {
	assert(node != nullptr && "Cannot increment a null iterator.");
	const auto iterator {*this};
	node = node->getNextNode();
	return iterator;
}

template<typename ElementType>
const DoublyLinkedListConstBidirectionalIterator<ElementType>& DoublyLinkedListConstBidirectionalIterator<ElementType>::operator--() noexcept {
	assert(node != nullptr && "Cannot decrement a null iterator.");
	node = node->getPreviousNode();
	return *this;
}

template<typename ElementType>
const DoublyLinkedListConstBidirectionalIterator<ElementType> DoublyLinkedListConstBidirectionalIterator<ElementType>::operator--(int) noexcept {
	assert(node != nullptr && "Cannot decrement a null iterator.");
	const auto iterator {*this};
	node = node->getPreviousNode();
	return iterator;
}
}