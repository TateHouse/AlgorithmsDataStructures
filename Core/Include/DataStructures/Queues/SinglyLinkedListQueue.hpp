#pragma once

#include <optional>
#include <vector>

#include "DataStructures/LinkedLists/SinglyLinkedList.hpp"

namespace Core::DataStructures::Queues {
/**
 * @brief A queue implemented using a singly linked list.
 * @class SinglyLinkedListQueue
 * @tparam ElementType: The type of the elements stored in the singly linked list queue.
 */
template<typename ElementType>
class SinglyLinkedListQueue final {
public:
	/**
	 * @brief Instantiates a new singly linked list queue with no elements.
	 */
	SinglyLinkedListQueue() noexcept = default;
	
	/**
	 * @brief Instantiates a new singly linked list queue by copying the given singly linked list queue.
	 * @param other: The singly linked list queue to copy.
	 */
	SinglyLinkedListQueue(const SinglyLinkedListQueue<ElementType>& other) = default;
	
	/**
	 * @brief Instantiates a new singly linked list queue by moving the given singly linked list queue.
	 * @param other: The singly linked list queue to move.
	 */
	SinglyLinkedListQueue(SinglyLinkedListQueue<ElementType>&& other) noexcept = default;
	
	/**
	 * @brief Destroys the singly linked list queue.
	 */
	~SinglyLinkedListQueue() noexcept = default;

public:
	/**
	 * @brief Assigns the given singly linked list queue to this singly linked list queue using copy semantics.
	 * @param other: The singly linked list queue to copy.
	 * @return A reference to this singly linked list queue.
	 */
	SinglyLinkedListQueue<ElementType>& operator=(const SinglyLinkedListQueue<ElementType>& other) = default;
	
	/**
	 * @brief Assigns the given singly linked list queue to this singly linked list queue using move semantics.
	 * @param other: The singly linked list queue to move.
	 * @return A reference to this singly linked list queue.
	 */
	SinglyLinkedListQueue<ElementType>& operator=(SinglyLinkedListQueue<ElementType>&& other) noexcept = default;
	const bool operator==(const SinglyLinkedListQueue<ElementType>& other) const noexcept;

public:
	/**
	 * @brief Inserts the given element to the back of the singly linked list queue using copy semantics.
	 * @param element: The element to insert.
	 */
	void enqueue(const ElementType& element);
	
	/**
	 * @brief Inserts the given element to the back of the singly linked list queue using move semantics.
	 * @param element: The element to insert.
	 */
	void enqueue(ElementType&& element);
	
	/**
	 * @brief Removes the element at the front of the singly linked list queue.
	 * @return The element at the front of the singly linked list queue if the singly linked list queue is not empty,
	 * std::nullopt otherwise.
	 */
	std::optional<ElementType> dequeue();
	
	/**
	 * @brief Removes all elements from the singly linked list queue.
	 * @return A vector containing all the elements that were removed from the singly linked list queue.
	 */
	std::vector<ElementType> dequeueAll();
	
	/**
	 * @brief Gets a const pointer to the const element at the front of the singly linked list queue.
	 * @return A const pointer to the const element at the front of the singly linked list queue if the singly linked
	 * list queue is not empty, nullptr otherwise.
	 */
	const ElementType* const getFront() const noexcept;
	
	/**
	 * @brief Gets a const pointer to the element at the front of the singly linked list queue.
	 * @return A const pointer to the element at the front of the singly linked list queue if the singly linked list
	 * queue is not empty, nullptr otherwise.
	 */
	ElementType* const getFront() noexcept;
	
	/**
	 * @brief Gets a const pointer to the const element at the back of the singly linked list queue.
	 * @return A const pointer to the const element at the back of the singly linked list queue if the singly linked
	 * list queue is not empty, nullptr otherwise.
	 */
	const ElementType* const getBack() const noexcept;
	
	/**
	 * @brief Gets a const pointer to the element at the back of the singly linked list queue.
	 * @return A const pointer to the element at the back of the singly linked list queue if the singly linked list
	 * queue is not empty, nullptr otherwise.
	 */
	ElementType* const getBack() noexcept;
	
	/**
	 * @brief Checks if the singly linked list queue is empty.
	 * @return True if the singly linked list queue is empty, false otherwise.
	 */
	const bool isEmpty() const noexcept;
	
	/**
	 * @brief Gets the number of elements in the singly linked list queue.
	 * @return The number of elements in the singly linked list queue.
	 */
	const std::size_t getSize() const noexcept;

private:
	LinkedLists::SinglyLinkedList<ElementType> singlyLinkedList {};
};

template<typename ElementType>
const bool SinglyLinkedListQueue<ElementType>::operator==(const SinglyLinkedListQueue<ElementType>& other) const noexcept {
	return singlyLinkedList == other.singlyLinkedList;
}

template<typename ElementType>
void SinglyLinkedListQueue<ElementType>::enqueue(const ElementType& element) {
	singlyLinkedList.insertAtTail(element);
}

template<typename ElementType>
void SinglyLinkedListQueue<ElementType>::enqueue(ElementType&& element) {
	singlyLinkedList.insertAtTail(std::move(element));
}

template<typename ElementType>
std::optional<ElementType> SinglyLinkedListQueue<ElementType>::dequeue() {
	return std::move(singlyLinkedList.removeAtHead());
}

template<typename ElementType>
std::vector<ElementType> SinglyLinkedListQueue<ElementType>::dequeueAll() {
	return std::move(singlyLinkedList.removeAll());
}

template<typename ElementType>
const ElementType* const SinglyLinkedListQueue<ElementType>::getFront() const noexcept {
	if (singlyLinkedList.isEmpty()) {
		return nullptr;
	}
	
	return &(*singlyLinkedList.cbegin());
}

template<typename ElementType>
ElementType* const SinglyLinkedListQueue<ElementType>::getFront() noexcept {
	if (singlyLinkedList.isEmpty()) {
		return nullptr;
	}
	
	return &(*singlyLinkedList.begin());
}

template<typename ElementType>
const ElementType* const SinglyLinkedListQueue<ElementType>::getBack() const noexcept {
	if (singlyLinkedList.isEmpty()) {
		return nullptr;
	}
	
	auto iterator {singlyLinkedList.cbegin()};
	auto nodeCount {singlyLinkedList.getNodeCount()};
	std::advance(iterator, nodeCount - 1);
	
	return &(*iterator);
}

template<typename ElementType>
ElementType* const SinglyLinkedListQueue<ElementType>::getBack() noexcept {
	if (singlyLinkedList.isEmpty()) {
		return nullptr;
	}
	
	auto iterator {singlyLinkedList.begin()};
	auto nodeCount {singlyLinkedList.getNodeCount()};
	std::advance(iterator, nodeCount - 1);
	
	return &(*iterator);
}

template<typename ElementType>
const bool SinglyLinkedListQueue<ElementType>::isEmpty() const noexcept {
	return singlyLinkedList.isEmpty();
}

template<typename ElementType>
const std::size_t SinglyLinkedListQueue<ElementType>::getSize() const noexcept {
	return singlyLinkedList.getNodeCount();
}
}