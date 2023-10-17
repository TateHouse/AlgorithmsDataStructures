#pragma once

#include <algorithm>
#include <functional>
#include <optional>
#include <vector>

#include "DataStructures/LinkedLists/Iterators/DoublyLinkedListConstBidirectionalIterator.hpp"
#include "DataStructures/LinkedLists/Iterators/DoublyLinkedListConstReverseBidirectionalIterator.hpp"
#include "DataStructures/LinkedLists/Iterators/DoublyLinkedListBidirectionalIterator.hpp"
#include "DataStructures/LinkedLists/Iterators/DoublyLinkedListReverseBidirectionalIterator.hpp"
#include "DataStructures/LinkedLists/DoublyLinkedListNode.hpp"

namespace Core::DataStructures::LinkedLists {
template<typename ElementType>
class DoublyLinkedList final {
public:
	DoublyLinkedList() noexcept = default;
	DoublyLinkedList(const DoublyLinkedList<ElementType>& other) noexcept;
	DoublyLinkedList(DoublyLinkedList<ElementType>&& other) noexcept;
	~DoublyLinkedList() noexcept;

public:
	DoublyLinkedList<ElementType>& operator=(const DoublyLinkedList<ElementType>& other) noexcept;
	DoublyLinkedList<ElementType>& operator=(DoublyLinkedList<ElementType>&& other) noexcept;
	const bool operator==(const DoublyLinkedList<ElementType>& other) const noexcept;

public:
	using value_type = ElementType;
	using ConstBidirectionalIterator = Iterators::DoublyLinkedListConstBidirectionalIterator<ElementType>;
	using ConstReverseBidirectionalIterator = Iterators::DoublyLinkedListConstReverseBidirectionalIterator<ElementType>;
	using BidirectionalIterator = Iterators::DoublyLinkedListBidirectionalIterator<ElementType>;
	using ReverseBidirectionalIterator = Iterators::DoublyLinkedListReverseBidirectionalIterator<ElementType>;
	
	ConstBidirectionalIterator cbegin() const noexcept;
	ConstBidirectionalIterator cend() const noexcept;
	ConstReverseBidirectionalIterator crbegin() const noexcept;
	ConstReverseBidirectionalIterator crend() const noexcept;
	BidirectionalIterator begin() const noexcept;
	BidirectionalIterator end() const noexcept;
	ReverseBidirectionalIterator rbegin() const noexcept;
	ReverseBidirectionalIterator rend() const noexcept;

public:
	void insertAtHead(const ElementType& element);
	void insertAtHead(ElementType&& element);
	void insertAtTail(const ElementType& element);
	void insertAtTail(ElementType&& element);
	const bool insertAtIndex(const ElementType& element, const std::size_t index);
	const bool insertAtIndex(ElementType&& element, const std::size_t index);
	std::optional<ElementType> removeAtHead() noexcept;
	std::optional<ElementType> removeAtTail() noexcept;
	std::optional<ElementType> removeAtIndex(const std::size_t index) noexcept;
	std::vector<ElementType> removeAll();
	ConstBidirectionalIterator findFirst(const std::function<bool(const ElementType&)>& predicate) const noexcept;
	BidirectionalIterator findFirst(const std::function<bool(const ElementType&)>& predicate) noexcept;
	ConstReverseBidirectionalIterator findLast(const std::function<bool(const ElementType&)>& predicate) const noexcept;
	ReverseBidirectionalIterator findLast(const std::function<bool(const ElementType&)>& predicate) noexcept;
	void reverse() noexcept;
	const bool contains(const std::function<bool(const ElementType&)>& predicate) const noexcept;
	const bool containsAll(const std::vector<std::function<bool(const ElementType&)>>& predicates) const noexcept;
	const bool isEmpty() const noexcept;
	const std::size_t getNodeCount() const noexcept;

private:
	std::size_t nodeCount {0};
	DoublyLinkedListNode<ElementType>* headNode {nullptr};
	DoublyLinkedListNode<ElementType>* tailNode {nullptr};
};

template<typename ElementType>
DoublyLinkedList<ElementType>::DoublyLinkedList(const DoublyLinkedList<ElementType>& other) noexcept {
	for (const auto& element: other) {
		insertAtTail(element);
	}
}

template<typename ElementType>
DoublyLinkedList<ElementType>::DoublyLinkedList(DoublyLinkedList<ElementType>&& other) noexcept:
		nodeCount {other.nodeCount}, headNode {other.headNode}, tailNode {other.tailNode} {
	other.nodeCount = 0;
	other.headNode = nullptr;
	other.tailNode = nullptr;
}

template<typename ElementType>
DoublyLinkedList<ElementType>& DoublyLinkedList<ElementType>::operator=(const DoublyLinkedList<ElementType>& other) noexcept {
	if (this == &other) {
		return *this;
	}
	
	removeAll();
	
	for (const auto& element: other) {
		insertAtTail(element);
	}
	
	return *this;
}

template<typename ElementType>
DoublyLinkedList<ElementType>& DoublyLinkedList<ElementType>::operator=(DoublyLinkedList<ElementType>&& other) noexcept {
	if (this == &other) {
		return *this;
	}
	
	removeAll();
	
	nodeCount = other.nodeCount;
	headNode = other.headNode;
	tailNode = other.tailNode;
	
	other.nodeCount = 0;
	other.headNode = nullptr;
	other.tailNode = nullptr;
	
	return *this;
}

template<typename ElementType>
const bool DoublyLinkedList<ElementType>::operator==(const DoublyLinkedList<ElementType>& other) const noexcept {
	if (nodeCount != other.nodeCount) {
		return false;
	}
	
	return std::equal(cbegin(), cend(), other.cbegin(), other.cend());
}

template<typename ElementType>
DoublyLinkedList<ElementType>::~DoublyLinkedList() noexcept {
	removeAll();
}

template<typename ElementType>
DoublyLinkedList<ElementType>::ConstBidirectionalIterator DoublyLinkedList<ElementType>::cbegin() const noexcept {
	return ConstBidirectionalIterator(headNode);
}

template<typename ElementType>
DoublyLinkedList<ElementType>::ConstBidirectionalIterator DoublyLinkedList<ElementType>::cend() const noexcept {
	return ConstBidirectionalIterator(nullptr);
}

template<typename ElementType>
DoublyLinkedList<ElementType>::ConstReverseBidirectionalIterator DoublyLinkedList<ElementType>::crbegin() const noexcept {
	return ConstReverseBidirectionalIterator(tailNode);
}

template<typename ElementType>
DoublyLinkedList<ElementType>::ConstReverseBidirectionalIterator DoublyLinkedList<ElementType>::crend() const noexcept {
	return ConstReverseBidirectionalIterator(nullptr);
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
DoublyLinkedList<ElementType>::ReverseBidirectionalIterator DoublyLinkedList<ElementType>::rbegin() const noexcept {
	return ReverseBidirectionalIterator(tailNode);
}

template<typename ElementType>
DoublyLinkedList<ElementType>::ReverseBidirectionalIterator DoublyLinkedList<ElementType>::rend() const noexcept {
	return ReverseBidirectionalIterator(nullptr);
}

template<typename ElementType>
void DoublyLinkedList<ElementType>::insertAtHead(const ElementType& element) {
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
void DoublyLinkedList<ElementType>::insertAtHead(ElementType&& element) {
	auto* node {new DoublyLinkedListNode<ElementType>(std::move(element))};
	
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
void DoublyLinkedList<ElementType>::insertAtTail(const ElementType& element) {
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
void DoublyLinkedList<ElementType>::insertAtTail(ElementType&& element) {
	auto* node {new DoublyLinkedListNode<ElementType>(std::move(element))};
	
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
const bool DoublyLinkedList<ElementType>::insertAtIndex(const ElementType& element, const std::size_t index) {
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
const bool DoublyLinkedList<ElementType>::insertAtIndex(ElementType&& element, const std::size_t index) {
	if (index > nodeCount) {
		return false;
	}
	
	if (index == 0 || headNode == nullptr) {
		insertAtHead(std::move(element));
		return true;
	}
	
	if (index == nodeCount) {
		insertAtTail(std::move(element));
		return true;
	}
	
	auto* node {new DoublyLinkedListNode<ElementType>(std::move(element))};
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
	
	return std::move(element);
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
	
	return std::move(element);
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
	
	return std::move(element);
}

template<typename ElementType>
std::vector<ElementType> DoublyLinkedList<ElementType>::removeAll() {
	std::vector<ElementType> elements {};
	elements.reserve(nodeCount);
	
	auto currentNode {headNode};
	while (currentNode != nullptr) {
		elements.emplace_back(currentNode->getElement());
		auto* node {currentNode};
		currentNode = currentNode->getNextNode();
		delete node;
	}
	
	nodeCount = 0;
	headNode = nullptr;
	tailNode = nullptr;
	
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

template<typename ElementType>
DoublyLinkedList<ElementType>::ConstReverseBidirectionalIterator DoublyLinkedList<ElementType>::findLast(const std::function<bool(const ElementType&)>& predicate) const noexcept {
	return std::find_if(crbegin(), crend(), predicate);
}

template<typename ElementType>
DoublyLinkedList<ElementType>::ReverseBidirectionalIterator DoublyLinkedList<ElementType>::findLast(const std::function<bool(const ElementType&)>& predicate) noexcept {
	return std::find_if(rbegin(), rend(), predicate);
}

template<typename ElementType>
void DoublyLinkedList<ElementType>::reverse() noexcept {
	if (headNode == nullptr || tailNode == nullptr) {
		return;
	}
	
	DoublyLinkedListNode<ElementType>* currentNode {headNode};
	DoublyLinkedListNode<ElementType>* tempNode {nullptr};
	while (currentNode != nullptr) {
		tempNode = currentNode->getPreviousNode();
		currentNode->setPreviousNode(currentNode->getNextNode());
		currentNode->setNextNode(tempNode);
		currentNode = currentNode->getPreviousNode();
	}
	
	tempNode = headNode;
	headNode = tailNode;
	tailNode = tempNode;
}

template<typename ElementType>
const bool DoublyLinkedList<ElementType>::contains(const std::function<bool(const ElementType&)>& predicate) const noexcept {
	return std::any_of(cbegin(), cend(), predicate);
}

template<typename ElementType>
const bool DoublyLinkedList<ElementType>::containsAll(const std::vector<std::function<bool(const ElementType&)>>& predicates) const noexcept {
	return std::ranges::all_of(predicates, [this](const auto& predicate) {
		return contains(predicate);
	});
}

template<typename ElementType>
const bool DoublyLinkedList<ElementType>::isEmpty() const noexcept {
	return nodeCount == 0 && headNode == nullptr && tailNode == nullptr;
}

template<typename ElementType>
const std::size_t DoublyLinkedList<ElementType>::getNodeCount() const noexcept {
	return nodeCount;
}
}