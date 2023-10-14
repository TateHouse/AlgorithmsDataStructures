#pragma once

#include "DataStructures/LinkedLists/SinglyLinkedList.hpp"

namespace Core::DataStructures::Stacks {
template<typename ElementType>
class SinglyLinkedListStack final {
public:
	SinglyLinkedListStack() noexcept = default;
	SinglyLinkedListStack(const SinglyLinkedListStack<ElementType>& other) noexcept = default;
	SinglyLinkedListStack(SinglyLinkedListStack<ElementType>&& other) noexcept = default;

private:
	LinkedLists::SinglyLinkedList<ElementType> singlyLinkedList {};
};
}