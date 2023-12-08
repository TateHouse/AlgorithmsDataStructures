#pragma once

#include <iterator>

#include "DataStructures/LinkedLists/SinglyLinkedListNode.hpp"

namespace Core::DataStructures::LinkedLists::Iterators {
/**
 * @brief A forward iterator for singly linked list.
 * @class SinglyLinkedListForwardIterator
 * @tparam ElementType: The type of the elements stored in the singly linked list.
 */
template<typename ElementType>
class SinglyLinkedListForwardIterator final {
public:
	using iterator_category = std::forward_iterator_tag;
	using difference_type = std::ptrdiff_t;
	using value_type = ElementType;
	using reference = ElementType&;
	using pointer = ElementType*;
	
	/**
	 * @brief Instantiates a new singly linked list forward iterator.
	 * @param node: The node to iterate from.
	 */
	explicit SinglyLinkedListForwardIterator(SinglyLinkedListNode<ElementType>* node) noexcept;

public:
	/**
	 * @brief Compares two singly linked list forward iterators.
	 * @details Two singly linked list forward iterators are equal if they point to the same node.
	 * @param other: The other singly linked list forward iterator to compare with.
	 * @return True if the two singly linked list forward iterators are equal, false otherwise.
	 */
	const bool operator==(const SinglyLinkedListForwardIterator<ElementType>& other) const noexcept;

public:
	/**
	 * @brief Dereferences the singly linked list forward iterator.
	 * @return A reference to the element stored in the node pointed to by the singly linked list forward iterator.
	 */
	reference operator*() const noexcept;
	
	/**
	 * @brief Dereferences the singly linked list forward iterator.
	 * @return A pointer to the element stored in the node pointed to by the singly linked list forward iterator.
	 */
	pointer operator->() const noexcept;
	
	/**
	 * @brief Increments the singly linked list forward iterator.
	 * @return A reference to the singly linked list forward iterator.
	 */
	SinglyLinkedListForwardIterator<ElementType>& operator++() noexcept;
	
	/**
	 * @brief Increments the singly linked list forward iterator.
	 * @return A copy of the singly linked list forward iterator before it was incremented.
	 */
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