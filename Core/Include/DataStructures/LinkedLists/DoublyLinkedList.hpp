#pragma once

#include <functional>
#include <optional>
#include <vector>

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
	std::optional<ElementType> removeAtHead() noexcept;
	std::optional<ElementType> removeAtTail() noexcept;
	std::optional<ElementType> removeAtIndex(const std::size_t index) noexcept;
	std::vector<ElementType> removeAll() noexcept;
	ConstBidirectionalIterator findFirst(const std::function<bool(const ElementType&)>& predicate) const noexcept;
	BidirectionalIterator findFirst(const std::function<bool(const ElementType&)>& predicate) noexcept;

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

template<typename ElementType>
std::optional<ElementType> DoublyLinkedList<ElementType>::removeAtHead() noexcept {
	if (headNode == nullptr) {
		return std::nullopt;
	}
	
	auto* node {headNode};
	const auto element {node->getElement()};
	headNode = headNode->getNextNode();
	delete node;
	--nodeCount;
	
	if (headNode == nullptr) {
		tailNode = nullptr;
	} else {
		headNode->setPreviousNode(nullptr);
	}
	
	return element;
}

template<typename ElementType>
std::optional<ElementType> DoublyLinkedList<ElementType>::removeAtTail() noexcept {
	if (headNode == nullptr) {
		return std::nullopt;
	}
	
	if (headNode == tailNode) {
		return removeAtHead();
	}
	
	auto* node {tailNode};
	auto* previousNode {tailNode->getPreviousNode()};
	const auto element {node->getElement()};
	delete node;
	tailNode = previousNode;
	tailNode->setNextNode(nullptr);
	--nodeCount;
	
	return element;
}

template<typename ElementType>
std::optional<ElementType> DoublyLinkedList<ElementType>::removeAtIndex(const std::size_t index) noexcept {
	if (index >= nodeCount) {
		return std::nullopt;
	}
	
	if (index == 0 || headNode == nullptr) {
		return removeAtHead();
	}
	
	if (index == nodeCount - 1) {
		return removeAtTail();
	}
	
	auto* previousNode {headNode};
	for (std::size_t currentIndex {0}; currentIndex < index - 1; ++currentIndex) {
		previousNode = previousNode->getNextNode();
	}
	
	auto* node {previousNode->getNextNode()};
	const auto element {node->getElement()};
	previousNode->setNextNode(node->getNextNode());
	node->getNextNode()->setPreviousNode(previousNode);
	delete node;
	--nodeCount;
	
	return element;
}

template<typename ElementType>
std::vector<ElementType> DoublyLinkedList<ElementType>::removeAll() noexcept {
	std::vector<ElementType> elements {};
	
	while (headNode != nullptr) {
		elements.emplace_back(removeAtHead().value());
	}
	
	return elements;
}

template<typename ElementType>
DoublyLinkedList<ElementType>::ConstBidirectionalIterator DoublyLinkedList<ElementType>::findFirst(const std::function<bool(const ElementType&)>& predicate) const noexcept {
	return std::find_if(cbegin(), cend(), predicate);
}

template<typename ElementType>
DoublyLinkedList<ElementType>::BidirectionalIterator DoublyLinkedList<ElementType>::findFirst(const std::function<bool(const ElementType&)>& predicate) noexcept {
	return std::find_if(begin(), end(), predicate);
}
}