#pragma once

#include <optional>
#include <vector>

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
	void push(const ElementType& element);
	void push(ElementType&& element);
	std::optional<ElementType> pop() noexcept;
	std::vector<ElementType> popAll() noexcept;
	const ElementType* const getTop() const noexcept;
	const bool isEmpty() const noexcept;
	const std::size_t getSize() const noexcept;

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

template<typename ElementType>
std::optional<ElementType> SinglyLinkedListStack<ElementType>::pop() noexcept {
	return singlyLinkedList.removeAtFront();
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
const bool SinglyLinkedListStack<ElementType>::isEmpty() const noexcept {
	return singlyLinkedList.isEmpty();
}

template<typename ElementType>
const std::size_t SinglyLinkedListStack<ElementType>::getSize() const noexcept {
	return singlyLinkedList.getSize();
}
}