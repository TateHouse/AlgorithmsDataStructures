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

private:
	LinkedLists::SinglyLinkedList<ElementType> singlyLinkedList {};
};
}