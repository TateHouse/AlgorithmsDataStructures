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

public:
	void insertAtHead(const ElementType& element) noexcept;
	void insertAtTail(const ElementType& element) noexcept;
	const bool insertAtIndex(const ElementType& element, const std::size_t index) noexcept;

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

template<typename ElementType>
void DoublyLinkedList<ElementType>::insertAtHead(const ElementType& element) noexcept {
	auto* node {new DoublyLinkedListNode<ElementType>(element)};
	
	if (headNode == nullptr) {
		headNode = node;
		tailNode = node;
	} else {
		node->setNextNode(headNode);
		headNode->setPreviousNode(node);
		headNode = node;
	}
	
	++nodeCount;
}

template<typename ElementType>
void DoublyLinkedList<ElementType>::insertAtTail(const ElementType& element) noexcept {
	auto* node {new DoublyLinkedListNode<ElementType>(element)};
	
	if (tailNode == nullptr) {
		headNode = node;
		tailNode = node;
	} else {
		node->setPreviousNode(tailNode);
		tailNode->setNextNode(node);
		tailNode = node;
	}
	
	++nodeCount;
}

template<typename ElementType>
const bool DoublyLinkedList<ElementType>::insertAtIndex(const ElementType& element, const std::size_t index) noexcept {
	if (index > nodeCount) {
		return false;
	}
	
	if (index == 0 || headNode == nullptr) {
		insertAtHead(element);
		return true;
	}
	
	if (index == nodeCount) {
		insertAtTail(element);
		return true;
	}
	
	auto* node {new DoublyLinkedListNode<ElementType>(element)};
	auto* previousNode {headNode};
	for (std::size_t currentIndex {0}; currentIndex < index - 1; ++currentIndex) {
		previousNode = previousNode->getNextNode();
	}
	
	node->setNextNode(previousNode->getNextNode());
	node->setPreviousNode(previousNode);
	node->getNextNode()->setPreviousNode(node);
	previousNode->setNextNode(node);
	++nodeCount;
	
	return true;
}
}