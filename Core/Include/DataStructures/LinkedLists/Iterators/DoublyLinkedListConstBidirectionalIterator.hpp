#pragma once

#include <iterator>

#include "DataStructures/LinkedLists/DoublyLinkedListNode.hpp"

namespace Core::DataStructures::LinkedLists::Iterators {
/**
 * @brief A const bidirectional iterator for doubly linked list.
 * @class DoublyLinkedListConstBidirectionalIterator
 * @tparam ElementType: The type of the elements stored in the doubly linked list.
 */
template<typename ElementType>
class DoublyLinkedListConstBidirectionalIterator final {
public:
	using iterator_category = std::bidirectional_iterator_tag;
	using difference_type = std::ptrdiff_t;
	using value_type = ElementType;
	using reference = const ElementType&;
	using pointer = const ElementType* const;
	
	/**
	 * @brief Instantiates a new doubly linked list const bidirectional iterator.
	 * @param node: The node to iterate from.
	 */
	explicit DoublyLinkedListConstBidirectionalIterator(DoublyLinkedListNode<ElementType>* const node) noexcept;
	
	/**
	 * @brief Instantiates a new doubly linked list const bidirectional iterator by copying the given doubly linked list
	 * const bidirectional iterator.
	 * @param other The doubly linked list const bidirectional iterator to copy.
	 */
	DoublyLinkedListConstBidirectionalIterator(const DoublyLinkedListConstBidirectionalIterator<ElementType>& other) = default;
	
	/**
	 * @brief Instantiates a new doubly linked list const bidirectional iterator by moving the given doubly linked list
	 * const bidirectional iterator.
	 * @param other The doubly linked list const bidirectional iterator to move.
	 */
	DoublyLinkedListConstBidirectionalIterator(DoublyLinkedListConstBidirectionalIterator<ElementType>&& other) noexcept = default;
	
	/**
	 * @brief Destroys the doubly linked list const bidirectional iterator.
	 */
	~DoublyLinkedListConstBidirectionalIterator() noexcept = default;
	
public:
	/**
	 * @brief Assigns the given doubly linked list const bidirectional iterator to this doubly linked list const
	 * bidirectional iterator using copy semantics.
	 * @param other The doubly linked list const bidirectional iterator to copy.
	 * @return A reference to the doubly linked list const bidirectional iterator.
	 */
	DoublyLinkedListConstBidirectionalIterator<ElementType>& operator=(const DoublyLinkedListConstBidirectionalIterator<ElementType>& other) = default;
	
	/**
	 * @brief Assigns the given doubly linked list const bidirectional iterator to this doubly linked list const
	 * bidirectional iterator using move semantics.
	 * @param other The doubly linked list const bidirectional iterator to move.
	 * @return A reference to the doubly linked list const bidirectional iterator.
	 */
	DoublyLinkedListConstBidirectionalIterator<ElementType>& operator=(DoublyLinkedListConstBidirectionalIterator<ElementType>&& other) noexcept = default;
	
	/**
	 * @brief Compares two doubly linked list const bidirectional iterators.
	 * @details Two doubly linked list const bidirectional iterators are equal if they point to the same node.
	 * @param other: The other doubly linked list const bidirectional iterator to compare with.
	 * @return True if the two doubly linked list const bidirectional iterators are equal, false otherwise.
	 */
	bool operator==(const DoublyLinkedListConstBidirectionalIterator<ElementType>& other) const noexcept;

	/**
	 * @brief Dereferences the doubly linked list const bidirectional iterator.
	 * @return A reference to the element stored in the node pointed to by the doubly linked list const bidirectional iterator.
	 */
	reference operator*() const noexcept;
	
	/**
	 * @brief Dereferences the doubly linked list const bidirectional iterator.
	 * @return A pointer to the element stored in the node pointed to by the doubly linked list const bidirectional iterator.
	 */
	pointer operator->() const noexcept;
	
	/**
	 * @brief Increments the doubly linked list const bidirectional iterator.
	 * @return A reference to the doubly linked list const bidirectional iterator.
	 */
	const DoublyLinkedListConstBidirectionalIterator<ElementType>& operator++() noexcept;
	
	/**
	 * @brief Increments the doubly linked list const bidirectional iterator.
	 * @return A copy of the doubly linked list const bidirectional iterator before it was incremented.
	 */
	const DoublyLinkedListConstBidirectionalIterator<ElementType> operator++(int) noexcept;
	
	/**
	 * @brief Decrements the doubly linked list const bidirectional iterator.
	 * @return A reference to the doubly linked list const bidirectional iterator.
	 */
	const DoublyLinkedListConstBidirectionalIterator<ElementType>& operator--() noexcept;
	
	/**
	 * @brief Decrements the doubly linked list const bidirectional iterator.
	 * @return A copy of the doubly linked list const bidirectional iterator before it was decremented.
	 */
	const DoublyLinkedListConstBidirectionalIterator<ElementType> operator--(int) noexcept;

private:
	DoublyLinkedListNode<ElementType>* node;
};

template<typename ElementType>
DoublyLinkedListConstBidirectionalIterator<ElementType>::DoublyLinkedListConstBidirectionalIterator(DoublyLinkedListNode<ElementType>* const node) noexcept:
		node {node} {
	
}

template<typename ElementType>
bool DoublyLinkedListConstBidirectionalIterator<ElementType>::operator==(const DoublyLinkedListConstBidirectionalIterator<ElementType>& other) const noexcept {
	return node == other.node;
}

template<typename ElementType>
const ElementType& DoublyLinkedListConstBidirectionalIterator<ElementType>::operator*() const noexcept {
	assert(node != nullptr && "Cannot dereference a null iterator.");
	return node->getElement();
}

template<typename ElementType>
const ElementType* const DoublyLinkedListConstBidirectionalIterator<ElementType>::operator->() const noexcept {
	assert(node != nullptr && "Cannot dereference a null iterator.");
	return &node->getElement();
}

template<typename ElementType>
const DoublyLinkedListConstBidirectionalIterator<ElementType>& DoublyLinkedListConstBidirectionalIterator<ElementType>::operator++() noexcept {
	assert(node != nullptr && "Cannot increment a null iterator.");
	node = node->getNextNode();
	return *this;
}

template<typename ElementType>
const DoublyLinkedListConstBidirectionalIterator<ElementType> DoublyLinkedListConstBidirectionalIterator<ElementType>::operator++(int) noexcept {
	assert(node != nullptr && "Cannot increment a null iterator.");
	const auto iterator {*this};
	node = node->getNextNode();
	return iterator;
}

template<typename ElementType>
const DoublyLinkedListConstBidirectionalIterator<ElementType>& DoublyLinkedListConstBidirectionalIterator<ElementType>::operator--() noexcept {
	assert(node != nullptr && "Cannot decrement a null iterator.");
	node = node->getPreviousNode();
	return *this;
}

template<typename ElementType>
const DoublyLinkedListConstBidirectionalIterator<ElementType> DoublyLinkedListConstBidirectionalIterator<ElementType>::operator--(int) noexcept {
	assert(node != nullptr && "Cannot decrement a null iterator.");
	const auto iterator {*this};
	node = node->getPreviousNode();
	return iterator;
}
}