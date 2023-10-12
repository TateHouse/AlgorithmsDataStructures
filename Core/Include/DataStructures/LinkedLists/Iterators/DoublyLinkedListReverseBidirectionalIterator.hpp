#pragma once

#include <iterator>

#include "DataStructures/LinkedLists/DoublyLinkedListNode.hpp"

namespace Core::DataStructures::LinkedLists::Iterators {
template<typename ElementType>
class DoublyLinkedListReverseBidirectionalIterator final {
public:
	using iterator_category = std::bidirectional_iterator_tag;
	using difference_type = std::ptrdiff_t;
	using value_type = ElementType;
	using reference = ElementType&;
	using pointer = ElementType*;
	
	explicit DoublyLinkedListReverseBidirectionalIterator(DoublyLinkedListNode<ElementType>* node) noexcept;

public:
	const bool operator==(const DoublyLinkedListReverseBidirectionalIterator<ElementType>& other) const noexcept;

public:
	reference operator*() const noexcept;
	pointer operator->() const noexcept;
	DoublyLinkedListReverseBidirectionalIterator<ElementType>& operator++() noexcept;
	DoublyLinkedListReverseBidirectionalIterator<ElementType> operator++(int) noexcept;
	DoublyLinkedListReverseBidirectionalIterator<ElementType>& operator--() noexcept;
	DoublyLinkedListReverseBidirectionalIterator<ElementType> operator--(int) noexcept;

private:
	DoublyLinkedListNode<ElementType>* node;
};

template<typename ElementType>
DoublyLinkedListReverseBidirectionalIterator<ElementType>::DoublyLinkedListReverseBidirectionalIterator(
		DoublyLinkedListNode<ElementType>* node) noexcept: node(node) {
	
}

template<typename ElementType>
const bool DoublyLinkedListReverseBidirectionalIterator<ElementType>::operator==(const DoublyLinkedListReverseBidirectionalIterator<ElementType>& other) const noexcept {
	return node == other.node;
}

template<typename ElementType>
DoublyLinkedListReverseBidirectionalIterator<ElementType>::reference DoublyLinkedListReverseBidirectionalIterator<ElementType>::operator*() const noexcept {
	assert(node != nullptr && "Cannot dereference a null iterator.");
	return node->getElement();
}

template<typename ElementType>
DoublyLinkedListReverseBidirectionalIterator<ElementType>::pointer DoublyLinkedListReverseBidirectionalIterator<ElementType>::operator->() const noexcept {
	assert(node != nullptr && "Cannot dereference a null iterator.");
	return &node->getElement();
}

template<typename ElementType>
DoublyLinkedListReverseBidirectionalIterator<ElementType>& DoublyLinkedListReverseBidirectionalIterator<ElementType>::operator++() noexcept {
	assert(node != nullptr && "Cannot increment a null iterator.");
	node = node->getPreviousNode();
	return *this;
}

template<typename ElementType>
DoublyLinkedListReverseBidirectionalIterator<ElementType> DoublyLinkedListReverseBidirectionalIterator<ElementType>::operator++(int) noexcept {
	assert(node != nullptr && "Cannot increment a null iterator.");
	auto iterator {*this};
	node = node->getPreviousNode();
	return iterator;
}

template<typename ElementType>
DoublyLinkedListReverseBidirectionalIterator<ElementType>& DoublyLinkedListReverseBidirectionalIterator<ElementType>::operator--() noexcept {
	assert(node != nullptr && "Cannot decrement a null iterator.");
	node = node->getNextNode();
	return *this;
}

template<typename ElementType>
DoublyLinkedListReverseBidirectionalIterator<ElementType> DoublyLinkedListReverseBidirectionalIterator<ElementType>::operator--(int) noexcept {
	assert(node != nullptr && "Cannot decrement a null iterator.");
	auto iterator {*this};
	node = node->getNextNode();
	return iterator;
}
}
