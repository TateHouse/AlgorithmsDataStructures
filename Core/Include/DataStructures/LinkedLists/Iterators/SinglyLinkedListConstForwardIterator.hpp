#pragma once

#include <format>
#include <iterator>
#include <stdexcept>

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
	reference operator*() const;
	pointer operator->() const;
	const SinglyLinkedListConstForwardIterator<ElementType>& operator++();
	const SinglyLinkedListConstForwardIterator<ElementType> operator++(int);

private:
	void validateNode(const std::string_view action) const;

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
const ElementType& SinglyLinkedListConstForwardIterator<ElementType>::operator*() const {
	validateNode("dereference");
	
	return node->getElement();
}

template<typename ElementType>
const ElementType* const SinglyLinkedListConstForwardIterator<ElementType>::operator->() const {
	validateNode("dereference");
	
	return &node->getElement();
}

template<typename ElementType>
const SinglyLinkedListConstForwardIterator<ElementType>& SinglyLinkedListConstForwardIterator<ElementType>::operator++() {
	validateNode("increment");
	
	node = node->getNextNode();
	return *this;
}

template<typename ElementType>
const SinglyLinkedListConstForwardIterator<ElementType> SinglyLinkedListConstForwardIterator<ElementType>::operator++(int) {
	validateNode("increment");
	
	auto* const previousNode {node};
	node = node->getNextNode();
	return SinglyLinkedListConstForwardIterator<ElementType> {previousNode};
}

template<typename ElementType>
void SinglyLinkedListConstForwardIterator<ElementType>::validateNode(const std::string_view action) const {
	if (node == nullptr) {
		const auto message {std::format("Cannot {} a nullptr.", action.data())};
		throw std::runtime_error(message);
	}
}
}