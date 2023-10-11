#pragma once

#include <format>
#include <iterator>
#include <stdexcept>

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
	reference operator*() const;
	pointer operator->() const;
	DoublyLinkedListBidirectionalIterator<ElementType>& operator++();
	DoublyLinkedListBidirectionalIterator<ElementType> operator++(int);
	DoublyLinkedListBidirectionalIterator<ElementType>& operator--();
	DoublyLinkedListBidirectionalIterator<ElementType> operator--(int);

private:
	void validateNode(const std::string_view action) const;

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
ElementType& DoublyLinkedListBidirectionalIterator<ElementType>::operator*() const {
	validateNode("dereference");
	
	return node->getElement();
}

template<typename ElementType>
ElementType* DoublyLinkedListBidirectionalIterator<ElementType>::operator->() const {
	validateNode("dereference");
	
	return &node->getElement();
}

template<typename ElementType>
DoublyLinkedListBidirectionalIterator<ElementType>& DoublyLinkedListBidirectionalIterator<ElementType>::operator++() {
	validateNode("increment");
	
	node = node->getNext();
	return *this;
}

template<typename ElementType>
DoublyLinkedListBidirectionalIterator<ElementType> DoublyLinkedListBidirectionalIterator<ElementType>::operator++(int) {
	validateNode("increment");
	
	const auto iterator = *this;
	node = node->getNext();
	return iterator;
}

template<typename ElementType>
DoublyLinkedListBidirectionalIterator<ElementType>& DoublyLinkedListBidirectionalIterator<ElementType>::operator--() {
	validateNode("decrement");
	
	node = node->getPrevious();
	return *this;
}

template<typename ElementType>
DoublyLinkedListBidirectionalIterator<ElementType> DoublyLinkedListBidirectionalIterator<ElementType>::operator--(int) {
	validateNode("decrement");
	
	const auto iterator = *this;
	node = node->getPrevious();
	return iterator;
}

template<typename ElementType>
void DoublyLinkedListBidirectionalIterator<ElementType>::validateNode(const std::string_view action) const {
	if (node == nullptr) {
		throw std::runtime_error {std::format("Cannot {} a nullptr.", action)};
	}
}
}