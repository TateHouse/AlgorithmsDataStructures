#pragma once

#include <optional>
#include <vector>

#include "DataStructures/LinkedLists/SinglyLinkedList.hpp"

namespace Core::DataStructures::Stacks {
/**
 * @brief A stack implemented using a singly linked list.
 * @class SinglyLinkedListStack
 * @tparam ElementType: The type of the elements stored in the singly linked list stack.
 */
template<typename ElementType>
class SinglyLinkedListStack final {
public:
	/**
	 * @brief Instantiates a new singly linked list stack with no elements.
	 */
	SinglyLinkedListStack() noexcept = default;
	
	/**
	 * @brief Instantiates a new singly linked list stack by copying the given singly linked list stack.
	 * @param other: The singly linked list stack to copy.
	 */
	SinglyLinkedListStack(const SinglyLinkedListStack<ElementType>& other) noexcept = default;
	
	/**
	 * @brief Instantiates a new singly linked list stack by moving the given singly linked list stack.
	 * @param other: The singly linked list stack to move.
	 */
	SinglyLinkedListStack(SinglyLinkedListStack<ElementType>&& other) noexcept = default;
	
	/**
	 * @brief Destroys the singly linked list stack.
	 */
	~SinglyLinkedListStack() noexcept = default;

public:
	/**
	 * @brief Assigns the given singly linked list stack to this singly linked list stack using copy semantics.
	 * @param other: The singly linked list stack to copy.
	 * @return A reference to this singly linked list stack.
	 */
	SinglyLinkedListStack<ElementType>& operator=(const SinglyLinkedListStack<ElementType>& other) noexcept = default;
	
	/**
	 * @brief Assigns the given singly linked list stack to this singly linked list stack using move semantics.
	 * @param other: The singly linked list stack to move.
	 * @return A reference to this singly linked list stack.
	 */
	SinglyLinkedListStack<ElementType>& operator=(SinglyLinkedListStack<ElementType>&& other) noexcept = default;
	
	/**
	 * @brief Checks if the given singly linked list stack is equal to this singly linked list stack.
	 * @details Two singly linked list stacks are equal if they have the same size and the same elements in the
	 * same order.
	 * @param other: The singly linked list stack to compare to.
	 * @return True if the singly linked list stacks are equal, false otherwise.
	 */
	bool operator==(const SinglyLinkedListStack<ElementType>& other) const noexcept;

public:
	/**
	 * @brief Inserts the given element to the back of the singly linked list stack using copy semantics.
	 * @param element: The element to insert.
	 * @throws std::bad_alloc: Thrown if memory allocation fails.
	 */
	void push(const ElementType& element);
	
	/**
	 * @brief Inserts the given element to the back of the singly linked list stack using move semantics.
	 * @param element: The element to insert.
	 * @throws std::bad_alloc: Thrown if memory allocation fails.
	 */
	void push(ElementType&& element);
	
	/**
	 * @brief Removes the element at the front of the singly linked list stack.
	 * @return The element at the front of the singly linked list stack if the singly linked list stack is not empty,
	 * std::nullopt otherwise.
	 */
	std::optional<ElementType> pop() noexcept;
	
	/**
	 * @brief Removes all elements from the singly linked list stack resulting in an empty singly linked list stack.
	 * @return A vector containing the elements that were removed from the singly linked list stack.
	 */
	std::vector<ElementType> popAll() noexcept;
	
	/**
	 * @brief Gets a const pointer to the const element at the front of the singly linked list stack.
	 * @return A const pointer to the const element at the front of the singly linked list stack if the singly linked
	 * list stack is not empty, nullptr otherwise.
	 */
	const ElementType* const getTop() const noexcept;
	
	/**
	 * @brief Gets a const pointer to the element at the front of the singly linked list stack.
	 * @return A const pointer to the element at the front of the singly linked list stack if the singly linked list
	 * stack is not empty, nullptr otherwise.
	 */
	ElementType* const getTop() noexcept;
	
	/**
	 * @brief Checks if the singly linked list stack is empty.
	 * @return True if the singly linked list stack is empty, false otherwise.
	 */
	bool isEmpty() const noexcept;
	
	/**
	 * @brief Gets the number of elements in the singly linked list stack.
	 * @return The number of elements in the singly linked list stack.
	 */
	std::size_t getSize() const noexcept;

private:
	LinkedLists::SinglyLinkedList<ElementType> singlyLinkedList {};
};

template<typename ElementType>
bool SinglyLinkedListStack<ElementType>::operator==(const SinglyLinkedListStack<ElementType>& other) const noexcept {
	if (this == &other) {
		return true;
	}
	
	return singlyLinkedList == other.singlyLinkedList;
}

template<typename ElementType>
void SinglyLinkedListStack<ElementType>::push(const ElementType& element) {
	singlyLinkedList.insertAtHead(element);
}

template<typename ElementType>
void SinglyLinkedListStack<ElementType>::push(ElementType&& element) {
	singlyLinkedList.insertAtHead(std::move(element));
}

template<typename ElementType>
std::optional<ElementType> SinglyLinkedListStack<ElementType>::pop() noexcept {
	return singlyLinkedList.removeAtHead();
}

template<typename ElementType>
std::vector<ElementType> SinglyLinkedListStack<ElementType>::popAll() noexcept {
	return singlyLinkedList.removeAll();
}

template<typename ElementType>
const ElementType* const SinglyLinkedListStack<ElementType>::getTop() const noexcept {
	if (singlyLinkedList.isEmpty()) {
		return nullptr;
	}
	
	return &(*singlyLinkedList.cbegin());
}

template<typename ElementType>
ElementType* const SinglyLinkedListStack<ElementType>::getTop() noexcept {
	if (singlyLinkedList.isEmpty()) {
		return nullptr;
	}
	
	return &(*singlyLinkedList.begin());
}

template<typename ElementType>
bool SinglyLinkedListStack<ElementType>::isEmpty() const noexcept {
	return singlyLinkedList.isEmpty();
}

template<typename ElementType>
std::size_t SinglyLinkedListStack<ElementType>::getSize() const noexcept {
	return singlyLinkedList.getNodeCount();
}
}