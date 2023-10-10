#pragma once

#include <format>
#include <iterator>
#include <stdexcept>

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
	reference operator*() const;
	pointer operator->() const;
	SinglyLinkedListForwardIterator<ElementType>& operator++();
	SinglyLinkedListForwardIterator<ElementType> operator++(int);

private:
	void validateNode(const std::string_view action) const;

private:
	SinglyLinkedListNode<ElementType>* node;
};

template<typename ElementType>
SinglyLinkedListForwardIterator<ElementType>::SinglyLinkedListForwardIterator(SinglyLinkedListNode<ElementType>* node) noexcept:
		node {node} {
	
}

template<typename ElementType>
const bool SinglyLinkedListForwardIterator<ElementType>::operator==(const SinglyLinkedListForwardIterator<ElementType>& other) const noexcept {
	validateNode("compare equality");
	
	return node == other.node;
}

template<typename ElementType>
ElementType& SinglyLinkedListForwardIterator<ElementType>::operator*() const {
	validateNode("dereference");
	
	return node->getElement();
}

template<typename ElementType>
ElementType* SinglyLinkedListForwardIterator<ElementType>::operator->() const {
	validateNode("dereference");
	
	return &node->getElement();
}

template<typename ElementType>
SinglyLinkedListForwardIterator<ElementType>& SinglyLinkedListForwardIterator<ElementType>::operator++() {
	validateNode("increment");
	
	node = node->getNextNode();
	return *this;
}

template<typename ElementType>
SinglyLinkedListForwardIterator<ElementType> SinglyLinkedListForwardIterator<ElementType>::operator++(int) {
	validateNode("increment");
	
	auto iterator {*this};
	node = node->getNextNode();
	return iterator;
}

template<typename ElementType>
void SinglyLinkedListForwardIterator<ElementType>::validateNode(const std::string_view action) const {
	if (node == nullptr) {
		const auto message {std::format("Cannot {} a nullptr.", action.data())};
		throw std::runtime_error(message);
	}
}
}