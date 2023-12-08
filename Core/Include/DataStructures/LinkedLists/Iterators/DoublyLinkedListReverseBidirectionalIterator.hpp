#pragma once

#include <iterator>

#include "DataStructures/LinkedLists/DoublyLinkedListNode.hpp"

namespace Core::DataStructures::LinkedLists::Iterators {
/**
 * @brief A reverse bidirectional iterator for doubly linked list.
 * @class DoublyLinkedListReverseBidirectionalIterator
 * @tparam ElementType: The type of the elements stored in the doubly linked list.
 */
template<typename ElementType>
class DoublyLinkedListReverseBidirectionalIterator final {
public:
	using iterator_category = std::bidirectional_iterator_tag;
	using difference_type = std::ptrdiff_t;
	using value_type = ElementType;
	using reference = ElementType&;
	using pointer = ElementType*;
	
	/**
	 * @brief Instantiates a new doubly linked list reverse bidirectional iterator.
	 * @param node: The node to iterate from.
	 */
	explicit DoublyLinkedListReverseBidirectionalIterator(DoublyLinkedListNode<ElementType>* node) noexcept;

public:
	/**
	 * @brief Compares two doubly linked list reverse bidirectional iterators.
	 * @details Two doubly linked list reverse bidirectional iterators are equal if they point to the same node.
	 * @param other: The other doubly linked list reverse bidirectional iterator to compare with.
	 * @return True if the two doubly linked list reverse bidirectional iterators are equal, false otherwise.
	 */
	const bool operator==(const DoublyLinkedListReverseBidirectionalIterator<ElementType>& other) const noexcept;

public:
	/**
	 * @brief Dereferences the doubly linked list reverse bidirectional iterator.
	 * @return A reference to the element stored in the node pointed to by the doubly linked list reverse bidirectional iterator.
	 */
	reference operator*() const noexcept;
	
	/**
	 * @brief Dereferences the doubly linked list reverse bidirectional iterator.
	 * @return A pointer to the element stored in the node pointed to by the doubly linked list reverse bidirectional iterator.
	 */
	pointer operator->() const noexcept;
	
	/**
	 * @brief Increments the doubly linked list reverse bidirectional iterator.
	 * @return A reference to the doubly linked list reverse bidirectional iterator.
	 */
	DoublyLinkedListReverseBidirectionalIterator<ElementType>& operator++() noexcept;
	
	/**
	 * @brief Increments the doubly linked list reverse bidirectional iterator.
	 * @return A copy of the doubly linked list reverse bidirectional iterator before it was incremented.
	 */
	DoublyLinkedListReverseBidirectionalIterator<ElementType> operator++(int) noexcept;
	
	/**
	 * @brief Decrements the doubly linked list reverse bidirectional iterator.
	 * @return A reference to the doubly linked list reverse bidirectional iterator.
	 */
	DoublyLinkedListReverseBidirectionalIterator<ElementType>& operator--() noexcept;
	
	/**
	 * @brief Decrements the doubly linked list reverse bidirectional iterator.
	 * @return A copy of the doubly linked list reverse bidirectional iterator before it was decremented.
	 */
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
