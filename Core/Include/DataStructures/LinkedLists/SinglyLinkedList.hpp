#pragma once

#include "DataStructures/LinkedLists/Iterators/SinglyLinkedListConstForwardIterator.hpp"
#include "DataStructures/LinkedLists/Iterators/SinglyLinkedListForwardIterator.hpp"
#include "DataStructures/LinkedLists/SinglyLinkedListNode.hpp"

namespace Core::DataStructures::LinkedLists {
template<typename ElementType>
class SinglyLinkedList final {
public:
	using ConstForwardIterator = Iterators::SinglyLinkedListConstForwardIterator<ElementType>;
	using ForwardIterator = Iterators::SinglyLinkedListForwardIterator<ElementType>;
	
	ConstForwardIterator cbegin() const noexcept;
	ConstForwardIterator cend() const noexcept;
	ForwardIterator begin() noexcept;
	ForwardIterator end() noexcept;

public:
	void insertAtHead(const ElementType& element) noexcept;
	void insertAtTail(const ElementType& element) noexcept;
	const bool insertAtIndex(const ElementType& element, const std::size_t index) noexcept;

private:
	std::size_t nodeCount {0};
	SinglyLinkedListNode<ElementType>* headNode {nullptr};
	SinglyLinkedListNode<ElementType>* tailNode {nullptr};
};

template<typename ElementType>
SinglyLinkedList<ElementType>::ConstForwardIterator SinglyLinkedList<ElementType>::cbegin() const noexcept {
	return ConstForwardIterator {headNode};
}

template<typename ElementType>
SinglyLinkedList<ElementType>::ConstForwardIterator SinglyLinkedList<ElementType>::cend() const noexcept {
	return ConstForwardIterator {nullptr};
}

template<typename ElementType>
SinglyLinkedList<ElementType>::ForwardIterator SinglyLinkedList<ElementType>::begin() noexcept {
	return ForwardIterator {headNode};
}

template<typename ElementType>
SinglyLinkedList<ElementType>::ForwardIterator SinglyLinkedList<ElementType>::end() noexcept {
	return ForwardIterator {nullptr};
}

template<typename ElementType>
void SinglyLinkedList<ElementType>::insertAtHead(const ElementType& element) noexcept {
	auto* node {new SinglyLinkedListNode<ElementType> {element}};
	
	if (headNode == nullptr) {
		headNode = node;
		tailNode = node;
	} else {
		node->setNextNode(headNode);
		headNode = node;
	}
	
	++nodeCount;
}

template<typename ElementType>
void SinglyLinkedList<ElementType>::insertAtTail(const ElementType& element) noexcept {
	auto* node {new SinglyLinkedListNode<ElementType> {element}};
	
	if (headNode == nullptr) {
		headNode = node;
		tailNode = node;
	} else {
		tailNode->setNextNode(node);
		tailNode = node;
	}
	
	++nodeCount;
}

template<typename ElementType>
const bool SinglyLinkedList<ElementType>::insertAtIndex(const ElementType& element, const std::size_t index) noexcept {
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
	
	auto* node {new SinglyLinkedListNode<ElementType> {element}};
	
	auto* previousNode {headNode};
	for (std::size_t currentIndex {0}; currentIndex < index - 1; ++currentIndex) {
		previousNode = previousNode->getNextNode();
	}
	
	node->setNextNode(previousNode->getNextNode());
	previousNode->setNextNode(node);
	++nodeCount;
	
	return true;
}
}