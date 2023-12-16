#pragma once

#include <iterator>

#include "DataStructures/LinkedLists/SinglyLinkedListNode.hpp"

namespace Core::DataStructures::LinkedLists::Iterators {
/**
 * @brief A const forward iterator for singly linked list.
 * @class SinglyLinkedListConstForwardIterator
 * @tparam ElementType: The type of the elements stored in the singly linked list.
 */
template<typename ElementType>
class SinglyLinkedListConstForwardIterator final {
public:
	using iterator_category = std::forward_iterator_tag;
	using difference_type = std::ptrdiff_t;
	using value_type = const ElementType;
	using reference = const ElementType&;
	using pointer = const ElementType* const;
	
	/**
	 * @brief Instantiates a new singly linked list const forward iterator.
	 * @param node: The node to iterate from.
	 */
	explicit SinglyLinkedListConstForwardIterator(SinglyLinkedListNode<ElementType>* node) noexcept;
	
	/**
	 * @brief Instantiates a new singly linked list const forward iterator by copying the given singly linked list
	 * const forward iterator.
	 * @param other The singly linked list const forward iterator to copy.
	 */
	SinglyLinkedListConstForwardIterator(const SinglyLinkedListConstForwardIterator<ElementType>& other) = default;
	
	/**
	 * @brief Instantiates a new singly linked list const forward iterator by moving the given singly linked list
	 * const forward iterator.
	 * @param other The singly linked list const forward iterator to move.
	 */
	SinglyLinkedListConstForwardIterator(SinglyLinkedListConstForwardIterator<ElementType>&& other) noexcept = default;
	
	/**
	 * @brief Destroys the singly linked list const forward iterator.
	 */
	~SinglyLinkedListConstForwardIterator() noexcept = default;

public:
	/**
	 * @brief Assigns the given singly linked list const forward iterator to this singly linked list const forward
	 * iterator using copy semantics.
	 * @param other The singly linked list const forward iterator to copy.
	 * @return A reference to the singly linked list const forward iterator.
	 */
	SinglyLinkedListConstForwardIterator<ElementType>& operator=(const SinglyLinkedListConstForwardIterator<ElementType>& other) = default;
	
	/**
	 * @brief Assigns the given singly linked list const forward iterator to this singly linked list const forward
	 * iterator using move semantics.
	 * @param other The singly linked list const forward iterator to move.
	 * @return A reference to the singly linked list const forward iterator.
	 */
	SinglyLinkedListConstForwardIterator<ElementType>& operator=(SinglyLinkedListConstForwardIterator<ElementType>&& other) noexcept = default;
	
	/**
	 * @brief Compares two singly linked list const forward iterators.
	 * @details Two singly linked list const forward iterators are equal if they point to the same node.
	 * @param other: The other singly linked list const forward iterator to compare with.
	 * @return True if the two singly linked list const forward iterators are equal, false otherwise.
	 */
	const bool operator==(const SinglyLinkedListConstForwardIterator<ElementType>& other) const noexcept;

	/**
	 * @brief Dereferences the singly linked list const forward iterator.
	 * @return A reference to the element stored in the node pointed to by the singly linked list const forward iterator.
	 */
	reference operator*() const noexcept;
	
	/**
	 * @brief Dereferences the singly linked list const forward iterator.
	 * @return A pointer to the element stored in the node pointed to by the singly linked list const forward iterator.
	 */
	pointer operator->() const noexcept;
	
	/**
	 * @brief Increments the singly linked list const forward iterator.
	 * @return A reference to the singly linked list const forward iterator.
	 */
	const SinglyLinkedListConstForwardIterator<ElementType>& operator++() noexcept;
	
	/**
	 * @brief Increments the singly linked list const forward iterator.
	 * @return A copy of the singly linked list const forward iterator before it was incremented.
	 */
	const SinglyLinkedListConstForwardIterator<ElementType> operator++(int) noexcept;

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
const ElementType& SinglyLinkedListConstForwardIterator<ElementType>::operator*() const noexcept {
	assert(node != nullptr && "Cannot dereference a nullptr node.");
	return node->getElement();
}

template<typename ElementType>
const ElementType* const SinglyLinkedListConstForwardIterator<ElementType>::operator->() const noexcept {
	assert(node != nullptr && "Cannot dereference a nullptr node.");
	return &node->getElement();
}

template<typename ElementType>
const SinglyLinkedListConstForwardIterator<ElementType>& SinglyLinkedListConstForwardIterator<ElementType>::operator++() noexcept {
	assert(node != nullptr && "Cannot increment a nullptr node.");
	node = node->getNextNode();
	return *this;
}

template<typename ElementType>
const SinglyLinkedListConstForwardIterator<ElementType> SinglyLinkedListConstForwardIterator<ElementType>::operator++(int) noexcept {
	assert(node != nullptr && "Cannot increment a nullptr node.");
	const auto iterator {*this};
	node = node->getNextNode();
	return iterator;
}
}