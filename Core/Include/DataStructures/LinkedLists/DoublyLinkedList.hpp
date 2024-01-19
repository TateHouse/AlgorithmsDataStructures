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
/**
 * @brief A doubly linked list.
 * @class DoublyLinkedList
 * @tparam ElementType: The type of the elements in the doubly linked list.
 */
template<typename ElementType>
class DoublyLinkedList final {
public:
	/**
	 * @brief Instantiates a new doubly linked list with no nodes.
	 */
	DoublyLinkedList() noexcept = default;
	
	/**
	 * @brief Instantiates a new doubly linked list by copying the given doubly linked list.
	 * @param other: The doubly linked list to copy.
	 */
	DoublyLinkedList(const DoublyLinkedList<ElementType>& other);
	
	/**
	 * @brief Instantiates a new doubly linked list by moving the given doubly linked list.
	 * @param other: The doubly linked list to move.
	 */
	DoublyLinkedList(DoublyLinkedList<ElementType>&& other) noexcept;
	
	/**
	 * @brief Destroys the doubly linked list.
	 */
	~DoublyLinkedList() noexcept;

public:
	/**
	 * @brief Assigns the given doubly linked list to this doubly linked list using copy semantics.
	 * @param other: The doubly linked list to copy.
	 * @return A reference to this doubly linked list.
	 */
	DoublyLinkedList<ElementType>& operator=(const DoublyLinkedList<ElementType>& other);
	
	/**
	 * @brief Assigns the given doubly linked list to this doubly linked list using move semantics.
	 * @param other: The doubly linked list to move.
	 * @return A reference to this doubly linked list.
	 */
	DoublyLinkedList<ElementType>& operator=(DoublyLinkedList<ElementType>&& other) noexcept;
	
	/**
	 * @brief Checks if the given doubly linked list is equal to this doubly linked list.
	 * @details Two doubly linked lists are equal if they have the same number of nodes and the same elements in the
	 * nodes are equal and in the same order.
	 * @param other: The doubly linked list to check.
	 * @return True if the given doubly linked list is equal to this doubly linked list, false otherwise.
	 */
	bool operator==(const DoublyLinkedList<ElementType>& other) const noexcept;

public:
	using value_type = ElementType;
	using ConstBidirectionalIterator = Iterators::DoublyLinkedListConstBidirectionalIterator<ElementType>;
	using ConstReverseBidirectionalIterator = Iterators::DoublyLinkedListConstReverseBidirectionalIterator<ElementType>;
	using BidirectionalIterator = Iterators::DoublyLinkedListBidirectionalIterator<ElementType>;
	using ReverseBidirectionalIterator = Iterators::DoublyLinkedListReverseBidirectionalIterator<ElementType>;
	
	/**
	 * @brief Gets a const bidirectional iterator to the first node in the doubly linked list.
	 * @return A const bidirectional iterator to the first node in the doubly linked list.
	 */
	ConstBidirectionalIterator cbegin() const noexcept;
	
	/**
	 * @brief Gets a const bidirectional iterator to the node after the last node in the doubly linked list.
	 * @return A const bidirectional iterator to the node after the last node in the doubly linked list.
	 */
	ConstBidirectionalIterator cend() const noexcept;
	
	/**
	 * @brief Gets a const reverse bidirectional iterator to the last node in the doubly linked list.
	 * @return A const reverse bidirectional iterator to the last node in the doubly linked list.
	 */
	ConstReverseBidirectionalIterator crbegin() const noexcept;
	
	/**
	 * @brief Gets a const reverse bidirectional iterator to the node before the first node in the doubly linked list.
	 * @return A const reverse bidirectional iterator to the node before the first node in the doubly linked list.
	 */
	ConstReverseBidirectionalIterator crend() const noexcept;
	
	/**
	 * @brief Gets a bidirectional iterator to the first node in the doubly linked list.
	 * @return A bidirectional iterator to the first node in the doubly linked list.
	 */
	BidirectionalIterator begin() const noexcept;
	
	/**
	 * @brief Gets a bidirectional iterator to the node after the last node in the doubly linked list.
	 * @return A bidirectional iterator to the node after the last node in the doubly linked list.
	 */
	BidirectionalIterator end() const noexcept;
	
	/**
	 * @brief Gets a reverse bidirectional iterator to the last node in the doubly linked list.
	 * @return A reverse bidirectional iterator to the last node in the doubly linked list.
	 */
	ReverseBidirectionalIterator rbegin() const noexcept;
	
	/**
	 * @brief Gets a reverse bidirectional iterator to the node before the first node in the doubly linked list.
	 * @return A reverse bidirectional iterator to the node before the first node in the doubly linked list.
	 */
	ReverseBidirectionalIterator rend() const noexcept;

public:
	/**
	 * @brief Inserts the given element at the head of the doubly linked list using copy semantics.
	 * @param element: The element to insert.
	 * @throws std::bad_alloc: Thrown if memory allocation fails.
	 */
	void insertAtHead(const ElementType& element);
	
	/**
	 * @brief Inserts the given element at the head of the doubly linked list using move semantics.
	 * @param element: The element to insert.
	 * @throws std::bad_alloc: Thrown if memory allocation fails.
	 */
	void insertAtHead(ElementType&& element);
	
	/**
	 * @brief Inserts the given element at the tail of the doubly linked list using copy semantics.
	 * @param element: The element to insert.
	 * @throws std::bad_alloc: Thrown if memory allocation fails.
	 */
	void insertAtTail(const ElementType& element);
	
	/**
	 * @brief Inserts the given element at the tail of the doubly linked list using move semantics.
	 * @param element: The element to insert.
	 * @throws std::bad_alloc: Thrown if memory allocation fails.
	 */
	void insertAtTail(ElementType&& element);
	
	/**
	 * @brief Inserts the given element at the given index in the doubly linked list using copy semantics.
	 * @param element: The element to insert.
	 * @param index: The index to insert the element at.
	 * @return True if the element was inserted, false if the index is greater than the number of nodes in the doubly
	 * linked list.
	 * @throws std::bad_alloc: Thrown if memory allocation fails.
	 */
	bool insertAtIndex(const ElementType& element, const std::size_t index);
	
	/**
	 * @brief Inserts the given element at the given index in the doubly linked list using move semantics.
	 * @param element: The element to insert.
	 * @param index: The index to insert the element at.
	 * @return True if the element was inserted, false if the index is greater than the number of nodes in the doubly
	 * linked list.
	 * @throws std::bad_alloc: Thrown if memory allocation fails.
	 */
	bool insertAtIndex(ElementType&& element, const std::size_t index);
	
	/**
	 * @brief Removes the element at the head of the doubly linked list.
	 * @return The element at the head of the doubly linked list, or std::nullopt if the doubly linked list is empty.
	 */
	std::optional<ElementType> removeAtHead() noexcept;
	
	/**
	 * @brief Removes the element at the tail of the doubly linked list.
	 * @return The element at the tail of the doubly linked list, or std::nullopt if the doubly linked list is empty.
	 */
	std::optional<ElementType> removeAtTail() noexcept;
	
	/**
	 * @brief Removes the element at the given index in the doubly linked list.
	 * @param index: The index to remove the element at.
	 * @return The element at the given index in the doubly linked list, or std::nullopt if the index is greater than
	 * or equal to the number of nodes in the doubly linked list.
	 */
	std::optional<ElementType> removeAtIndex(const std::size_t index) noexcept;
	
	/**
	 * @brief Removes all nodes from the doubly linked list resulting in an empty doubly linked list.
	 * @return A vector containing the elements in the nodes that were removed from the doubly linked list.
	 * @throws std::bad_alloc: Thrown if memory allocation fails.
	 */
	std::vector<ElementType> removeAll();
	
	/**
	 * @brief Finds the first node in the doubly linked list that satisfies the given predicate.
	 * @param predicate: The predicate to satisfy.
	 * @return A const bidirectional iterator to the first node in the doubly linked list that satisfies the given
	 * predicate, or cend() if no node satisfies the given predicate.
	 */
	ConstBidirectionalIterator findFirst(const std::function<bool(const ElementType&)>& predicate) const noexcept;
	
	/**
	 * @brief Finds the first node in the doubly linked list that satisfies the given predicate.
	 * @param predicate: The predicate to satisfy.
	 * @return A bidirectional iterator to the first node in the doubly linked list that satisfies the given predicate,
	 * or end() if no node satisfies the given predicate.
	 */
	BidirectionalIterator findFirst(const std::function<bool(const ElementType&)>& predicate) noexcept;
	
	/**
	 * @brief Finds the last node in the doubly linked list that satisfies the given predicate.
	 * @param predicate: The predicate to satisfy.
	 * @return A const reverse bidirectional iterator to the last node in the doubly linked list that satisfies the
	 * given predicate, or crend() if no node satisfies the given predicate.
	 */
	ConstReverseBidirectionalIterator findLast(const std::function<bool(const ElementType&)>& predicate) const noexcept;
	
	/**
	 * @brief Finds the last node in the doubly linked list that satisfies the given predicate.
	 * @param predicate: The predicate to satisfy.
	 * @return A reverse bidirectional iterator to the last node in the doubly linked list that satisfies the given
	 * predicate, or rend() if no node satisfies the given predicate.
	 */
	ReverseBidirectionalIterator findLast(const std::function<bool(const ElementType&)>& predicate) noexcept;
	
	/**
	 * @brief Reverses the doubly linked list.
	 */
	void reverse() noexcept;
	
	/**
	 * @brief Checks if the doubly linked list contains a node that satisfies the given predicate.
	 * @param predicate: The predicate to satisfy.
	 * @return True if the doubly linked list contains a node that satisfies the given predicate, false otherwise.
	 */
	bool contains(const std::function<bool(const ElementType&)>& predicate) const noexcept;
	
	/**
	 * @brief Checks if the doubly linked list contains nodes that satisfy all of the given predicates.
	 * @details A single node does not necessarily have to satisfy all of the given predicates, each predicate must be
	 * satisfied by at least one node in the doubly linked list for this function to return true.
	 * @param predicates: The predicates to satisfy.
	 * @return True if the doubly linked list contains nodes that satisfy all of the given predicates, false otherwise.
	 */
	bool containsAll(const std::vector<std::function<bool(const ElementType&)>>& predicates) const noexcept;
	
	/**
	 * @brief Checks if the doubly linked list is empty.
	 * @return True if the doubly linked list is empty, false otherwise.
	 */
	bool isEmpty() const noexcept;
	
	/**
	 * @brief Gets the number of nodes in the doubly linked list.
	 * @return The number of nodes in the doubly linked list.
	 */
	std::size_t getNodeCount() const noexcept;

private:
	std::size_t nodeCount {0};
	DoublyLinkedListNode<ElementType>* headNode {nullptr};
	DoublyLinkedListNode<ElementType>* tailNode {nullptr};
};

template<typename ElementType>
DoublyLinkedList<ElementType>::DoublyLinkedList(const DoublyLinkedList<ElementType>& other) {
	for (const auto& element : other) {
		insertAtTail(element);
	}
}

template<typename ElementType>
DoublyLinkedList<ElementType>::DoublyLinkedList(DoublyLinkedList<ElementType>&& other) noexcept {
	removeAll();
	
	nodeCount = other.nodeCount;
	headNode = other.headNode;
	tailNode = other.tailNode;
	
	other.nodeCount = 0;
	other.headNode = nullptr;
	other.tailNode = nullptr;
}

template<typename ElementType>
DoublyLinkedList<ElementType>& DoublyLinkedList<ElementType>::operator=(const DoublyLinkedList<ElementType>& other) {
	if (this == &other) {
		return *this;
	}
	
	removeAll();
	
	for (const auto& element : other) {
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
bool DoublyLinkedList<ElementType>::operator==(const DoublyLinkedList<ElementType>& other) const noexcept {
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
bool DoublyLinkedList<ElementType>::insertAtIndex(const ElementType& element, const std::size_t index) {
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
bool DoublyLinkedList<ElementType>::insertAtIndex(ElementType&& element, const std::size_t index) {
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
DoublyLinkedList<ElementType>::ConstBidirectionalIterator DoublyLinkedList<ElementType>::findFirst(const std::function<bool(
		const ElementType&)>& predicate) const noexcept {
	return std::find_if(cbegin(), cend(), predicate);
}

template<typename ElementType>
DoublyLinkedList<ElementType>::BidirectionalIterator DoublyLinkedList<ElementType>::findFirst(const std::function<bool(
		const ElementType&)>& predicate) noexcept {
	return std::find_if(begin(), end(), predicate);
}

template<typename ElementType>
DoublyLinkedList<ElementType>::ConstReverseBidirectionalIterator DoublyLinkedList<ElementType>::findLast(const std::function<bool(
		const ElementType&)>& predicate) const noexcept {
	return std::find_if(crbegin(), crend(), predicate);
}

template<typename ElementType>
DoublyLinkedList<ElementType>::ReverseBidirectionalIterator DoublyLinkedList<ElementType>::findLast(const std::function<bool(
		const ElementType&)>& predicate) noexcept {
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
bool DoublyLinkedList<ElementType>::contains(const std::function<bool(const ElementType&)>& predicate) const noexcept {
	return std::any_of(cbegin(), cend(), predicate);
}

template<typename ElementType>
bool DoublyLinkedList<ElementType>::containsAll(const std::vector<std::function<bool(const ElementType&)>>& predicates) const noexcept {
	return std::ranges::all_of(predicates, [this](const auto& predicate) {
		return contains(predicate);
	});
}

template<typename ElementType>
bool DoublyLinkedList<ElementType>::isEmpty() const noexcept {
	return nodeCount == 0 && headNode == nullptr && tailNode == nullptr;
}

template<typename ElementType>
std::size_t DoublyLinkedList<ElementType>::getNodeCount() const noexcept {
	return nodeCount;
}
}