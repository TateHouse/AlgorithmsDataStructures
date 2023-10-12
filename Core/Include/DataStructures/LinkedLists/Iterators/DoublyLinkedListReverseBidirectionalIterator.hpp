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
	reference operator*() const;
	pointer operator->() const;
	DoublyLinkedListReverseBidirectionalIterator<ElementType>& operator++();
	DoublyLinkedListReverseBidirectionalIterator<ElementType> operator++(int);
	DoublyLinkedListReverseBidirectionalIterator<ElementType>& operator--();
	DoublyLinkedListReverseBidirectionalIterator<ElementType> operator--(int);

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
DoublyLinkedListReverseBidirectionalIterator<ElementType>::reference DoublyLinkedListReverseBidirectionalIterator<ElementType>::operator*() const {
	return node->getElement();
}

template<typename ElementType>
DoublyLinkedListReverseBidirectionalIterator<ElementType>::pointer DoublyLinkedListReverseBidirectionalIterator<ElementType>::operator->() const {
	return &node->getElement();
}

template<typename ElementType>
DoublyLinkedListReverseBidirectionalIterator<ElementType>& DoublyLinkedListReverseBidirectionalIterator<ElementType>::operator++() {
	node = node->getPreviousNode();
	return *this;
}

template<typename ElementType>
DoublyLinkedListReverseBidirectionalIterator<ElementType> DoublyLinkedListReverseBidirectionalIterator<ElementType>::operator++(
		int) {
	auto iterator {*this};
	node = node->getPreviousNode();
	return iterator;
}

template<typename ElementType>
DoublyLinkedListReverseBidirectionalIterator<ElementType>& DoublyLinkedListReverseBidirectionalIterator<ElementType>::operator--() {
	node = node->getNextNode();
	return *this;
}

template<typename ElementType>
DoublyLinkedListReverseBidirectionalIterator<ElementType> DoublyLinkedListReverseBidirectionalIterator<ElementType>::operator--(int) {
	auto iterator {*this};
	node = node->getNextNode();
	return iterator;
}
}
