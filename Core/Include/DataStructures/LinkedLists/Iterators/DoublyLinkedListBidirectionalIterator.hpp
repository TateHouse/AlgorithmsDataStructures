#pragma once

#include <iterator>

#include "DataStructures/LinkedLists/DoublyLinkedListNode.hpp"

namespace Core::DataStructures::LinkedLists::Iterators {
/**
 * @brief A bidirectional iterator for doubly linked list.
 * @class DoublyLinkedListBidirectionalIterator
 * @tparam ElementType: The type of the elements stored in the doubly linked list.
 */
template<typename ElementType>
class DoublyLinkedListBidirectionalIterator final {
public:
	using iterator_category = std::bidirectional_iterator_tag;
	using difference_type = std::ptrdiff_t;
	using value_type = ElementType;
	using reference = ElementType&;
	using pointer = ElementType*;
	
	/**
	 * @brief Instantiates a new doubly linked list bidirectional iterator.
	 * @param node: The node to iterate from.
	 */
	explicit DoublyLinkedListBidirectionalIterator(DoublyLinkedListNode<ElementType>* node) noexcept;
	
	/**
	 * @brief Instantiates a new doubly linked list bidirectional iterator by copying the given doubly linked list
	 * bidirectional iterator.
	 * @param other The doubly linked list bidirectional iterator to copy.
	 */
	DoublyLinkedListBidirectionalIterator(const DoublyLinkedListBidirectionalIterator<ElementType>& other) = default;
	
	/**
	 * @brief Instantiates a new doubly linked list bidirectional iterator by moving the given doubly linked list
	 * bidirectional iterator.
	 * @param other The doubly linked list bidirectional iterator to move.
	 */
	DoublyLinkedListBidirectionalIterator(DoublyLinkedListBidirectionalIterator<ElementType>&& other) noexcept = default;
	
	/**
	 * @brief Destroys the doubly linked list bidirectional iterator.
	 */
	~DoublyLinkedListBidirectionalIterator() noexcept = default;

public:
	/**
	 * @brief Assigns the given doubly linked list bidirectional iterator to this doubly linked list bidirectional
	 * iterator using copy semantics.
	 * @param other The doubly linked list bidirectional iterator to copy.
	 * @return A reference to the doubly linked list bidirectional iterator.
	 */
	DoublyLinkedListBidirectionalIterator<ElementType>& operator=(const DoublyLinkedListBidirectionalIterator<ElementType>& other) = default;
	
	/**
	 * @brief Assigns the given doubly linked list bidirectional iterator to this doubly linked list bidirectional
	 * iterator using move semantics.
	 * @param other The doubly linked list bidirectional iterator to move.
	 * @return A reference to the doubly linked list bidirectional iterator.
	 */
	DoublyLinkedListBidirectionalIterator<ElementType>& operator=(DoublyLinkedListBidirectionalIterator<ElementType>&& other) noexcept = default;

	/**
	 * @brief Compares two doubly linked list bidirectional iterators.
	 * @details Two doubly linked list bidirectional iterators are equal if they point to the same node.
	 * @param other: The other doubly linked list bidirectional iterator to compare with.
	 * @return True if the two doubly linked list bidirectional iterators are equal, false otherwise.
	 */
	bool operator==(const DoublyLinkedListBidirectionalIterator<ElementType>& other) const noexcept;

	/**
	 * @brief Dereferences the doubly linked list bidirectional iterator.
	 * @return A reference to the element stored in the node pointed to by the doubly linked list bidirectional iterator.
	 */
	reference operator*() const noexcept;
	
	/**
	 * @brief Dereferences the doubly linked list bidirectional iterator.
	 * @return A pointer to the element stored in the node pointed to by the doubly linked list bidirectional iterator.
	 */
	pointer operator->() const noexcept;
	
	/**
	 * @brief Increments the doubly linked list bidirectional iterator.
	 * @return A reference to the doubly linked list bidirectional iterator.
	 */
	DoublyLinkedListBidirectionalIterator<ElementType>& operator++() noexcept;
	
	/**
	 * @brief Increments the doubly linked list bidirectional iterator.
	 * @return A copy of the doubly linked list bidirectional iterator before it was incremented.
	 */
	DoublyLinkedListBidirectionalIterator<ElementType> operator++(int) noexcept;
	
	/**
	 * @brief Decrements the doubly linked list bidirectional iterator.
	 * @return A reference to the doubly linked list bidirectional iterator.
	 */
	DoublyLinkedListBidirectionalIterator<ElementType>& operator--() noexcept;
	
	/**
	 * @brief Decrements the doubly linked list bidirectional iterator.
	 * @return A copy of the doubly linked list bidirectional iterator before it was decremented.
	 */
	DoublyLinkedListBidirectionalIterator<ElementType> operator--(int) noexcept;

private:
	DoublyLinkedListNode<ElementType>* node;
};

template<typename ElementType>
DoublyLinkedListBidirectionalIterator<ElementType>::DoublyLinkedListBidirectionalIterator(DoublyLinkedListNode<ElementType>* node) noexcept:
		node {node} {
	
}

template<typename ElementType>
bool DoublyLinkedListBidirectionalIterator<ElementType>::operator==(const DoublyLinkedListBidirectionalIterator<ElementType>& other) const noexcept {
	return node == other.node;
}

template<typename ElementType>
ElementType& DoublyLinkedListBidirectionalIterator<ElementType>::operator*() const noexcept {
	assert(node != nullptr && "Cannot dereference a null iterator.");
	return node->getElement();
}

template<typename ElementType>
ElementType* DoublyLinkedListBidirectionalIterator<ElementType>::operator->() const noexcept {
	assert(node != nullptr && "Cannot dereference a null iterator.");
	return &node->getElement();
}

template<typename ElementType>
DoublyLinkedListBidirectionalIterator<ElementType>& DoublyLinkedListBidirectionalIterator<ElementType>::operator++() noexcept {
	assert(node != nullptr && "Cannot increment a null iterator.");
	node = node->getNextNode();
	return *this;
}

template<typename ElementType>
DoublyLinkedListBidirectionalIterator<ElementType> DoublyLinkedListBidirectionalIterator<ElementType>::operator++(int) noexcept {
	assert(node != nullptr && "Cannot increment a null iterator.");
	const auto iterator {*this};
	node = node->getNextNode();
	return iterator;
}

template<typename ElementType>
DoublyLinkedListBidirectionalIterator<ElementType>& DoublyLinkedListBidirectionalIterator<ElementType>::operator--() noexcept {
	assert(node != nullptr && "Cannot decrement a null iterator.");
	node = node->getPreviousNode();
	return *this;
}

template<typename ElementType>
DoublyLinkedListBidirectionalIterator<ElementType> DoublyLinkedListBidirectionalIterator<ElementType>::operator--(int) noexcept {
	assert(node != nullptr && "Cannot decrement a null iterator.");
	const auto iterator {*this};
	node = node->getPreviousNode();
	return iterator;
}
}