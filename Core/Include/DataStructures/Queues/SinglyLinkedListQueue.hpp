#pragma once

#include <optional>
#include <vector>

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
	std::vector<ElementType> dequeueAll();
	const ElementType* const getFront() const noexcept;
	const ElementType* const getBack() const noexcept;
	const bool isEmpty() const noexcept;
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
const ElementType* const SinglyLinkedListQueue<ElementType>::getBack() const noexcept {
	if (singlyLinkedList.isEmpty()) {
		return nullptr;
	}
	
	auto iterator {singlyLinkedList.cbegin()};
	auto nodeCount {singlyLinkedList.getSize()};
	std::advance(iterator, nodeCount - 1);
	
	return &(*iterator);
}

template<typename ElementType>
const bool SinglyLinkedListQueue<ElementType>::isEmpty() const noexcept {
	return singlyLinkedList.isEmpty();
}

template<typename ElementType>
const std::size_t SinglyLinkedListQueue<ElementType>::getSize() const noexcept {
	return singlyLinkedList.getSize();
}
}