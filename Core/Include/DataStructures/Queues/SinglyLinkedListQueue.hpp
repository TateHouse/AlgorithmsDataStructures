#pragma once

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

private:
	LinkedLists::SinglyLinkedList<ElementType> singlyLinkedList {};
};

template<typename ElementType>
const bool SinglyLinkedListQueue<ElementType>::operator==(const SinglyLinkedListQueue<ElementType>& other) const noexcept {
	return singlyLinkedList == other.singlyLinkedList;
}
}