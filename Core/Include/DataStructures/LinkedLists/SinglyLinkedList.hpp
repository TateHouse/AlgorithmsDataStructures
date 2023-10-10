#pragma once

#include <functional>
#include <optional>
#include <vector>

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
	std::optional<ElementType> removeAtHead() noexcept;
	std::optional<ElementType> removeAtTail() noexcept;
	std::optional<ElementType> removeAtIndex(const std::size_t index) noexcept;
	std::vector<ElementType> removeAll() noexcept;
	ForwardIterator findFirst(const std::function<bool(const ElementType&)>& predicate) noexcept;
	ConstForwardIterator findFirst(const std::function<bool(const ElementType&)>& predicate) const noexcept;
	const bool contains(const std::function<bool(const ElementType&)>& predicate) const noexcept;
	const bool containsAll(const std::vector<const std::function<bool(const ElementType&)>>& predicates) const noexcept;
	const bool isEmpty() const noexcept;

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

template<typename ElementType>
std::optional<ElementType> SinglyLinkedList<ElementType>::removeAtHead() noexcept {
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
	}
	
	return element;
}

template<typename ElementType>
std::optional<ElementType> SinglyLinkedList<ElementType>::removeAtTail() noexcept {
	if (headNode == nullptr) {
		return std::nullopt;
	}
	
	if (headNode == tailNode) {
		return removeAtHead();
	}
	
	auto* previousNode {headNode};
	while (previousNode->getNextNode()->getNextNode() != nullptr) {
		previousNode = previousNode->getNextNode();
	}
	
	const auto element {tailNode->getElement()};
	delete tailNode;
	tailNode = previousNode;
	tailNode->setNextNode(nullptr);
	--nodeCount;
	
	return element;
}

template<typename ElementType>
std::optional<ElementType> SinglyLinkedList<ElementType>::removeAtIndex(const std::size_t index) noexcept {
	if (index >= nodeCount) {
		return std::nullopt;
	}
	
	if (index == 0) {
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
	delete node;
	--nodeCount;
	
	return element;
}

template<typename ElementType>
std::vector<ElementType> SinglyLinkedList<ElementType>::removeAll() noexcept {
	std::vector<ElementType> elements {};
	
	while (headNode != nullptr) {
		elements.emplace_back(removeAtHead().value());
	}
	
	return elements;
}

template<typename ElementType>
SinglyLinkedList<ElementType>::ForwardIterator SinglyLinkedList<ElementType>::findFirst(const std::function<bool(const ElementType&)>& predicate) noexcept {
	return std::find_if(begin(), end(), predicate);
}

template<typename ElementType>
SinglyLinkedList<ElementType>::ConstForwardIterator SinglyLinkedList<ElementType>::findFirst(const std::function<bool(const ElementType&)>& predicate) const noexcept {
	return std::find_if(cbegin(), cend(), predicate);
}

template<typename ElementType>
const bool SinglyLinkedList<ElementType>::contains(const std::function<bool(const ElementType&)>& predicate) const noexcept {
	return std::any_of(cbegin(), cend(), predicate);
}

template<typename ElementType>
const bool SinglyLinkedList<ElementType>::containsAll(const std::vector<const std::function<bool(const ElementType&)>>& predicates) const noexcept {
	return std::all_of(predicates.cbegin(), predicates.cend(), [this](const auto& predicate) {
		return contains(predicate);
	});
}

template<typename ElementType>
const bool SinglyLinkedList<ElementType>::isEmpty() const noexcept {
	return nodeCount == 0 && headNode == nullptr && tailNode == nullptr;
}
}