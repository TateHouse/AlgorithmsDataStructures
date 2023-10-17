#pragma once

#include <optional>

#include "DataStructures/LinkedLists/SinglyLinkedList.hpp"

namespace Core::DataStructures::Queues {
template<typename ElementType>
class SinglyLinkedListQueue final {
public:
	SinglyLinkedListQueue() noexcept = default;
	SinglyLinkedListQueue(const SinglyLinkedListQueue<ElementType>& other) = default;
	SinglyLinkedListQueue(SinglyLinkedListQueue<ElementType>&& other) noexcept = default;
	~SinglyLinkedListQueue() noexcept = default;

public:
	SinglyLinkedListQueue<ElementType>& operator=(const SinglyLinkedListQueue<ElementType>& other) = default;
	SinglyLinkedListQueue<ElementType>& operator=(SinglyLinkedListQueue<ElementType>&& other) noexcept = default;
	const bool operator==(const SinglyLinkedListQueue<ElementType>& other) const noexcept;

public:
	void enqueue(const ElementType& element);
	void enqueue(ElementType&& element);
	std::optional<ElementType> dequeue();

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
}