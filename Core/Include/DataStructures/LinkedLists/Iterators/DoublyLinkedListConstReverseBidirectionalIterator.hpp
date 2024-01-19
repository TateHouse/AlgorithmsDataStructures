#pragma once

#include <iterator>

#include "DataStructures/LinkedLists/DoublyLinkedListNode.hpp"

namespace Core::DataStructures::LinkedLists::Iterators {
/**
 * @brief A reverse bidirectional iterator for doubly linked list.
 * @class DoublyLinkedListConstReverseBidirectionalIterator
 * @tparam ElementType: The type of the elements stored in the doubly linked list.
 */
template<typename ElementType>
class DoublyLinkedListConstReverseBidirectionalIterator final {
public:
	using iterator_category = std::bidirectional_iterator_tag;
	using difference_type = std::ptrdiff_t;
	using value_type = ElementType;
	using reference = const ElementType&;
	using pointer = const ElementType* const;
	
	/**
	 * @brief Instantiates a new doubly linked list const reverse bidirectional iterator.
	 * @param node: The node to iterate from.
	 */
	explicit DoublyLinkedListConstReverseBidirectionalIterator(DoublyLinkedListNode<ElementType>* node) noexcept;
	
	/**
	 * @brief Instantiates a new doubly linked list const reverse bidirectional iterator by copying the given doubly
	 * linked list const reverse bidirectional iterator.
	 * @param other The doubly linked list const reverse bidirectional iterator to copy.
	 */
	DoublyLinkedListConstReverseBidirectionalIterator(const DoublyLinkedListConstReverseBidirectionalIterator<ElementType>& other) = default;
	
	/**
	 * @brief Instantiates a new doubly linked list const reverse bidirectional iterator by moving the given doubly
	 * linked list const reverse bidirectional iterator.
	 * @param other The doubly linked list const reverse bidirectional iterator to move.
	 */
	DoublyLinkedListConstReverseBidirectionalIterator(DoublyLinkedListConstReverseBidirectionalIterator<ElementType>&& other) noexcept = default;

public:
	/**
	 * @brief Assigns the given doubly linked list const reverse bidirectional iterator to this doubly linked list
	 * const reverse bidirectional iterator using copy semantics.
	 * @param other The doubly linked list const reverse bidirectional iterator to copy.
	 * @return A reference to the doubly linked list const reverse bidirectional iterator.
	 */
	DoublyLinkedListConstReverseBidirectionalIterator<ElementType>& operator=(const DoublyLinkedListConstReverseBidirectionalIterator<ElementType>& other) = default;
	
	/**
	 * @brief Assigns the given doubly linked list const reverse bidirectional iterator to this doubly linked list
	 * const reverse bidirectional iterator using move semantics.
	 * @param other The doubly linked list const reverse bidirectional iterator to move.
	 * @return A reference to the doubly linked list const reverse bidirectional iterator.
	 */
	DoublyLinkedListConstReverseBidirectionalIterator<ElementType>& operator=(DoublyLinkedListConstReverseBidirectionalIterator<ElementType>&& other) noexcept = default;
	
	/**
	 * @brief Compares two doubly linked list const reverse bidirectional iterators.
	 * @details Two doubly linked list const reverse bidirectional iterators are equal if they point to the same node.
	 * @param other: The other doubly linked list const reverse bidirectional iterator to compare with.
	 * @return True if the two doubly linked list const reverse bidirectional iterators are equal, false otherwise.
	 */
	bool operator==(const DoublyLinkedListConstReverseBidirectionalIterator<ElementType>& other) const noexcept;

	/**
	 * @brief Dereferences the doubly linked list const reverse bidirectional iterator.
	 * @return A reference to the element stored in the node pointed to by the doubly linked list const reverse
	 * bidirectional iterator.
	 */
	reference operator*() const noexcept;
	
	/**
	 * @brief Dereferences the doubly linked list const reverse bidirectional iterator.
	 * @return A pointer to the element stored in the node pointed to by the doubly linked list const reverse
	 * bidirectional iterator.
	 */
	pointer operator->() const noexcept;
	
	/**
	 * @brief Increments the doubly linked list const reverse bidirectional iterator.
	 * @return A reference to the doubly linked list const reverse bidirectional iterator.
	 */
	const DoublyLinkedListConstReverseBidirectionalIterator<ElementType>& operator++() noexcept;
	
	/**
	 * @brief Increments the doubly linked list const reverse bidirectional iterator.
	 * @return A copy of the doubly linked list const reverse bidirectional iterator before it was incremented.
	 */
	const DoublyLinkedListConstReverseBidirectionalIterator<ElementType> operator++(int) noexcept;
	
	/**
	 * @brief Decrements the doubly linked list const reverse bidirectional iterator.
	 * @return A reference to the doubly linked list const reverse bidirectional iterator.
	 */
	const DoublyLinkedListConstReverseBidirectionalIterator<ElementType>& operator--() noexcept;
	
	/**
	 * @brief Decrements the doubly linked list const reverse bidirectional iterator.
	 * @return A copy of the doubly linked list const reverse bidirectional iterator before it was decremented.
	 */
	const DoublyLinkedListConstReverseBidirectionalIterator<ElementType> operator--(int) noexcept;

private:
	DoublyLinkedListNode<ElementType>* node;
};

template<typename ElementType>
DoublyLinkedListConstReverseBidirectionalIterator<ElementType>::DoublyLinkedListConstReverseBidirectionalIterator(
		DoublyLinkedListNode<ElementType>* node) noexcept : node {node} {
	
}

template<typename ElementType>
bool DoublyLinkedListConstReverseBidirectionalIterator<ElementType>::operator==(const DoublyLinkedListConstReverseBidirectionalIterator<ElementType>& other) const noexcept {
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