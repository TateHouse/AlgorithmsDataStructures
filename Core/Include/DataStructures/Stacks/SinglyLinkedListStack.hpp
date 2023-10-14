#pragma once

#include "DataStructures/LinkedLists/SinglyLinkedList.hpp"

namespace Core::DataStructures::Stacks {
template<typename ElementType>
class SinglyLinkedListStack final {
public:
	SinglyLinkedListStack() noexcept = default;
	SinglyLinkedListStack(const SinglyLinkedListStack<ElementType>& other) noexcept = default;
	SinglyLinkedListStack(SinglyLinkedListStack<ElementType>&& other) noexcept = default;
	~SinglyLinkedListStack() noexcept = default;

public:
	SinglyLinkedListStack<ElementType>& operator=(const SinglyLinkedListStack<ElementType>& other) noexcept = default;
	SinglyLinkedListStack<ElementType>& operator=(SinglyLinkedListStack<ElementType>&& other) noexcept = default;
	const bool operator==(const SinglyLinkedListStack<ElementType>& other) const noexcept;
	
public:
	void push(const ElementType& element) noexcept;
	void push(ElementType&& element) noexcept;

private:
	LinkedLists::SinglyLinkedList<ElementType> singlyLinkedList {};
};

template<typename ElementType>
const bool SinglyLinkedListStack<ElementType>::operator==(const SinglyLinkedListStack<ElementType>& other) const noexcept {
	if (this == &other) {
		return true;
	}
	
	return singlyLinkedList == other.singlyLinkedList;
}

template<typename ElementType>
void SinglyLinkedListStack<ElementType>::push(const ElementType& element) noexcept {
	singlyLinkedList.insertAtFront(element);
}

template<typename ElementType>
void SinglyLinkedListStack<ElementType>::push(ElementType&& element) noexcept {
	singlyLinkedList.insertAtFront(std::move(element));
}
}
