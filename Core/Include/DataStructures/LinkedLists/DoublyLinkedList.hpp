#pragma once

#include "DataStructures/LinkedLists/Iterators/DoublyLinkedListConstBidirectionalIterator.hpp"
#include "DataStructures/LinkedLists/Iterators/DoublyLinkedListBidirectionalIterator.hpp"
#include "DataStructures/LinkedLists/DoublyLinkedListNode.hpp"

namespace Core::DataStructures::LinkedLists {
template<typename ElementType>
class DoublyLinkedList final {
public:
	using value_type = ElementType;
	using ConstBidirectionalIterator = Iterators::DoublyLinkedListConstBidirectionalIterator<ElementType>;
	using BidirectionalIterator = Iterators::DoublyLinkedListBidirectionalIterator<ElementType>;
	
	ConstBidirectionalIterator cbegin() const noexcept;
	ConstBidirectionalIterator cend() const noexcept;
	BidirectionalIterator begin() const noexcept;
	BidirectionalIterator end() const noexcept;

private:
	std::size_t nodeCount {0};
	DoublyLinkedListNode<ElementType>* headNode {nullptr};
	DoublyLinkedListNode<ElementType>* tailNode {nullptr};
};

template<typename ElementType>
DoublyLinkedList<ElementType>::ConstBidirectionalIterator DoublyLinkedList<ElementType>::cbegin() const noexcept {
	return ConstBidirectionalIterator(headNode);
}

template<typename ElementType>
DoublyLinkedList<ElementType>::ConstBidirectionalIterator DoublyLinkedList<ElementType>::cend() const noexcept {
	return ConstBidirectionalIterator(nullptr);
}

template<typename ElementType>
DoublyLinkedList<ElementType>::BidirectionalIterator DoublyLinkedList<ElementType>::begin() const noexcept {
	return BidirectionalIterator(headNode);
}

template<typename ElementType>
DoublyLinkedList<ElementType>::BidirectionalIterator DoublyLinkedList<ElementType>::end() const noexcept {
	return BidirectionalIterator(nullptr);
}
}