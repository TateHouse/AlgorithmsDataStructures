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
	reference operator*() const;
	pointer operator->() const;
	const DoublyLinkedListConstBidirectionalIterator<ElementType>& operator++();
	const DoublyLinkedListConstBidirectionalIterator<ElementType> operator++(int);
	const DoublyLinkedListConstBidirectionalIterator<ElementType>& operator--();
	const DoublyLinkedListConstBidirectionalIterator<ElementType> operator--(int);

private:
	void validateNode(const std::string_view action) const;

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
const ElementType& DoublyLinkedListConstBidirectionalIterator<ElementType>::operator*() const {
	validateNode("dereference");
	
	return node->getElement();
}

template<typename ElementType>
const ElementType* const DoublyLinkedListConstBidirectionalIterator<ElementType>::operator->() const {
	validateNode("dereference");
	
	return &node->getElement();
}

template<typename ElementType>
const DoublyLinkedListConstBidirectionalIterator<ElementType>& DoublyLinkedListConstBidirectionalIterator<ElementType>::operator++() {
	validateNode("increment");
	
	node = node->getNextNode();
	return *this;
}

template<typename ElementType>
const DoublyLinkedListConstBidirectionalIterator<ElementType> DoublyLinkedListConstBidirectionalIterator<ElementType>::operator++(
		int) {
	validateNode("increment");
	
	const auto iterator {*this};
	node = node->getNextNode();
	return iterator;
}

template<typename ElementType>
const DoublyLinkedListConstBidirectionalIterator<ElementType>& DoublyLinkedListConstBidirectionalIterator<ElementType>::operator--() {
	validateNode("decrement");
	
	node = node->getPreviousNode();
	return *this;
}

template<typename ElementType>
const DoublyLinkedListConstBidirectionalIterator<ElementType> DoublyLinkedListConstBidirectionalIterator<ElementType>::operator--(
		int) {
	validateNode("decrement");
	
	const auto iterator {*this};
	node = node->getPreviousNode();
	return iterator;
}

template<typename ElementType>
void DoublyLinkedListConstBidirectionalIterator<ElementType>::validateNode(const std::string_view action) const {
	if (node == nullptr) {
		throw std::runtime_error {std::format("Cannot {} a nullptr.", action)};
	}
}
}