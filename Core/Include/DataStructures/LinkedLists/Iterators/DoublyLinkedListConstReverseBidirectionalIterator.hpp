#pragma once

#include <iterator>

#include "DataStructures/LinkedLists/DoublyLinkedListNode.hpp"

namespace Core::DataStructures::LinkedLists::Iterators {
template<typename ElementType>
class DoublyLinkedListConstReverseBidirectionalIterator final {
public:
	using iterator_category = std::bidirectional_iterator_tag;
	using difference_type = std::ptrdiff_t;
	using value_type = const ElementType;
	using reference = const ElementType&;
	using pointer = const ElementType* const;
	
	explicit DoublyLinkedListConstReverseBidirectionalIterator(DoublyLinkedListNode<ElementType>* node) noexcept;

public:
	const bool operator==(const DoublyLinkedListConstReverseBidirectionalIterator<ElementType>& other) const noexcept;

public:
	reference operator*() const noexcept;
	pointer operator->() const noexcept;
	const DoublyLinkedListConstReverseBidirectionalIterator<ElementType>& operator++() noexcept;
	const DoublyLinkedListConstReverseBidirectionalIterator<ElementType> operator++(int) noexcept;
	const DoublyLinkedListConstReverseBidirectionalIterator<ElementType>& operator--() noexcept;
	const DoublyLinkedListConstReverseBidirectionalIterator<ElementType> operator--(int) noexcept;

private:
	DoublyLinkedListNode<ElementType>* node;
};

template<typename ElementType>
DoublyLinkedListConstReverseBidirectionalIterator<ElementType>::DoublyLinkedListConstReverseBidirectionalIterator(
		DoublyLinkedListNode<ElementType>* node) noexcept : node {node} {
	
}

template<typename ElementType>
const bool DoublyLinkedListConstReverseBidirectionalIterator<ElementType>::operator==(const DoublyLinkedListConstReverseBidirectionalIterator<ElementType>& other) const noexcept {
	return node == other.node;
}

template<typename ElementType>
const ElementType& DoublyLinkedListConstReverseBidirectionalIterator<ElementType>::operator*() const noexcept {
	assert(node != nullptr && "Cannot dereference a null iterator.");
	return node->getElement();
}

template<typename ElementType>
const ElementType* const DoublyLinkedListConstReverseBidirectionalIterator<ElementType>::operator->() const noexcept {
	assert(node != nullptr && "Cannot dereference a null iterator.");
	return &node->getElement();
}

template<typename ElementType>
const DoublyLinkedListConstReverseBidirectionalIterator<ElementType>& DoublyLinkedListConstReverseBidirectionalIterator<ElementType>::operator++() noexcept {
	assert(node != nullptr && "Cannot increment a null iterator.");
	node = node->getPreviousNode();
	return *this;
}

template<typename ElementType>
const DoublyLinkedListConstReverseBidirectionalIterator<ElementType> DoublyLinkedListConstReverseBidirectionalIterator<ElementType>::operator++(int) noexcept {
	assert(node != nullptr && "Cannot increment a null iterator.");
	const auto iterator{*this};
	node = node->getPreviousNode();
	return iterator;
}

template<typename ElementType>
const DoublyLinkedListConstReverseBidirectionalIterator<ElementType>& DoublyLinkedListConstReverseBidirectionalIterator<ElementType>::operator--() noexcept {
	assert(node != nullptr && "Cannot decrement a null iterator.");
	node = node->getNextNode();
	return *this;
}

template<typename ElementType>
const DoublyLinkedListConstReverseBidirectionalIterator<ElementType> DoublyLinkedListConstReverseBidirectionalIterator<ElementType>::operator--(int) noexcept {
	assert(node != nullptr && "Cannot decrement a null iterator.");
	const auto iterator{*this};
	node = node->getNextNode();
	return iterator;
}
}