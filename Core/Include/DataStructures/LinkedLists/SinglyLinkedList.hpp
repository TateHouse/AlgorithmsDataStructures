#pragma once

#include <algorithm>
#include <functional>
#include <optional>
#include <vector>

#include "DataStructures/LinkedLists/Iterators/SinglyLinkedListConstForwardIterator.hpp"
#include "DataStructures/LinkedLists/Iterators/SinglyLinkedListForwardIterator.hpp"
#include "DataStructures/LinkedLists/SinglyLinkedListNode.hpp"

namespace Core::DataStructures::LinkedLists {
/**
 * @brief A singly linked list.
 * @class SinglyLinkedList
 * @tparam ElementType: The type of the elements stored in the singly linked list.
 */
template<typename ElementType>
class SinglyLinkedList final {
public:
	/**
	 * @brief Instantiates a new singly linked list with no nodes.
	 */
	SinglyLinkedList() noexcept = default;
	
	/**
	 * @brief Instantiates a new singly linked list by copying the given singly linked list.
	 * @param other: The singly linked list to copy.
	 */
	SinglyLinkedList(const SinglyLinkedList<ElementType>& other);
	
	/**
	 * @brief Instantiates a new singly linked list by moving the given singly linked list.
	 * @param other: The singly linked list to move.
	 */
	SinglyLinkedList(SinglyLinkedList<ElementType>&& other) noexcept;
	
	/**
	 * @brief Destroys the singly linked list.
	 */
	~SinglyLinkedList() noexcept;

public:
	/**
	 * @brief Assigns the given singly linked list to this singly linked list using copy semantics.
	 * @param other: The singly linked list to copy.
	 * @return A reference to this singly linked list.
	 */
	SinglyLinkedList<ElementType>& operator=(const SinglyLinkedList<ElementType>& other);
	
	/**
	 * @brief Assigns the given singly linked list to this singly linked list using move semantics.
	 * @param other: The singly linked list to move.
	 * @return A reference to this singly linked list.
	 */
	SinglyLinkedList<ElementType>& operator=(SinglyLinkedList<ElementType>&& other) noexcept;
	
	/**
	 * @brief Checks if this singly linked list is equal to the given singly linked list.
	 * @details Two singly linked lists are considered equal if they have the same number of nodes and the elements in
	 * the nodes are equal and in the same order.
	 * @param other: The singly linked list to compare to.
	 * @return True if the singly linked lists are equal, false otherwise.
	 */
	bool operator==(const SinglyLinkedList<ElementType>& other) const noexcept;

public:
	using value_type = ElementType;
	using ConstForwardIterator = Iterators::SinglyLinkedListConstForwardIterator<ElementType>;
	using ForwardIterator = Iterators::SinglyLinkedListForwardIterator<ElementType>;
	
	/**
	 * @brief Gets a const forward iterator to the first node in the singly linked list.
	 * @return A const forward iterator to the first node in the singly linked list.
	 */
	ConstForwardIterator cbegin() const noexcept;
	
	/**
	 * @brief Gets a const forward iterator to the node after the last node in the singly linked list.
	 * @return A const forward iterator to the node after the last node in the singly linked list.
	 */
	ConstForwardIterator cend() const noexcept;
	
	/**
	 * @brief Gets a forward iterator to the first node in the singly linked list.
	 * @return A forward iterator to the first node in the singly linked list.
	 */
	ForwardIterator begin() const noexcept;
	
	/**
	 * @brief Gets a forward iterator to the node after the last node in the singly linked list.
	 * @return A forward iterator to the node after the last node in the singly linked list.
	 */
	ForwardIterator end() const noexcept;

public:
	/**
	 * @brief Inserts the given element at the head of the singly linked list using copy semantics.
	 * @param element: The element to insert.
	 * @throws std::bad_alloc: Thrown if memory allocation fails.
	 */
	void insertAtHead(const ElementType& element);
	
	/**
	 * @brief Inserts the given element at the head of the singly linked list using move semantics.
	 * @param element: The element to insert.
	 * @throws std::bad_alloc: Thrown if memory allocation fails.
	 */
	void insertAtHead(ElementType&& element);
	
	/**
	 * @brief Inserts the given element at the tail of the singly linked list using copy semantics.
	 * @param element: The element to insert.
	 * @throws std::bad_alloc: Thrown if memory allocation fails.
	 */
	void insertAtTail(const ElementType& element);
	
	/**
	 * @brief Inserts the given element at the tail of the singly linked list using move semantics.
	 * @param element: The element to insert.
	 * @throws std::bad_alloc: Thrown if memory allocation fails.
	 */
	void insertAtTail(ElementType&& element);
	
	/**
	 * @brief Inserts the given element at the given index in the singly linked list using copy semantics.
	 * @param element: The element to insert.
	 * @param index: The index to insert the element at.
	 * @return True if the element was inserted, false if the index is greater than the number of nodes in the singly
	 * linked list.
	 * @throws std::bad_alloc: Thrown if memory allocation fails.
	 */
	bool insertAtIndex(const ElementType& element, const std::size_t index);
	
	/**
	 * @brief Inserts the given element at the given index in the singly linked list using move semantics.
	 * @param element: The element to insert.
	 * @param index: The index to insert the element at.
	 * @return True if the element was inserted, false if the index is greater than the number of nodes in the singly
	 * linked list.
	 * @throws std::bad_alloc: Thrown if memory allocation fails.
	 */
	bool insertAtIndex(ElementType&& element, const std::size_t index);
	
	/**
	 * @brief Removes the element at the head of the singly linked list.
	 * @return The element at the head of the singly linked list, or std::nullopt if the singly linked list is empty.
	 */
	std::optional<ElementType> removeAtHead() noexcept;
	
	/**
	 * @brief Removes the element at the tail of the singly linked list.
	 * @return The element at the tail of the singly linked list, or std::nullopt if the singly linked list is empty.
	 */
	std::optional<ElementType> removeAtTail() noexcept;
	
	/**
	 * @brief Removes the element at the given index in the singly linked list.
	 * @param index: The index to remove the element at.
	 * @return The element at the given index in the singly linked list, or std::nullopt if the index is greater than
	 * or equal to the number of nodes in the singly linked list.
	 */
	std::optional<ElementType> removeAtIndex(const std::size_t index) noexcept;
	
	/**
	 * @brief Removes all nodes from the singly linked list resulting in an empty singly linked list.
	 * @return A vector containing the elements stored in the nodes that were removed from the singly linked list.
	 * @throws std::bad_alloc: Thrown if memory allocation fails.
	 */
	std::vector<ElementType> removeAll();
	
	/**
	 * @brief Finds the first node in the singly linked list that satisfies the given predicate.
	 * @param predicate: The predicate to satisfy.
	 * @return A const forward iterator to the first node in the singly linked list that satisfies the given predicate,
	 * or cend() if no node satisfies the given predicate.
	 */
	ConstForwardIterator findFirst(const std::function<bool(const ElementType&)>& predicate) const noexcept;
	
	/**
	 * @brief Finds the first node in the singly linked list that satisfies the given predicate.
	 * @param predicate: The predicate to satisfy.
	 * @return A forward iterator to the first node in the singly linked list that satisfies the given predicate, or
	 * end() if no node satisfies the given predicate.
	 */
	ForwardIterator findFirst(const std::function<bool(const ElementType&)>& predicate) noexcept;
	
	/**
	 * @brief Reverses the singly linked list.
	 */
	void reverse() noexcept;
	
	/**
	 * @brief Checks if the singly linked list contains a node that satisfies the given predicate.
	 * @param predicate: The predicate to satisfy.
	 * @return True if the singly linked list contains a node that satisfies the given predicate, false otherwise.
	 */
	bool contains(const std::function<bool(const ElementType&)>& predicate) const noexcept;
	
	/**
	 * @brief Checks if the singly linked list contains nodes that satisfy all of the given predicates.
	 * @details A single node does not necessarily have to satisfy all of the given predicates, each predicate must be
	 * satisfied by at least one node in the singly linked list for this function to return true.
	 * @param predicates: The predicates to satisfy.
	 * @return True if the singly linked list contains nodes that satisfy all of the given predicates, false otherwise.
	 */
	bool containsAll(const std::vector<std::function<bool(const ElementType&)>>& predicates) const noexcept;
	
	/**
	 * @brief Checks if the singly linked list is empty.
	 * @return True if the singly linked list is empty, false otherwise.
	 */
	bool isEmpty() const noexcept;
	
	/**
	 * @brief Gets the number of nodes in the singly linked list.
	 * @return The number of nodes in the singly linked list.
	 */
	std::size_t getNodeCount() const noexcept;

private:
	std::size_t nodeCount {0};
	SinglyLinkedListNode<ElementType>* headNode {nullptr};
	SinglyLinkedListNode<ElementType>* tailNode {nullptr};
};

template<typename ElementType>
SinglyLinkedList<ElementType>::SinglyLinkedList(const SinglyLinkedList<ElementType>& other) {
	for (const auto& element : other) {
		insertAtTail(element);
	}
}

template<typename ElementType>
SinglyLinkedList<ElementType>::SinglyLinkedList(SinglyLinkedList<ElementType>&& other) noexcept {
	removeAll();
	
	nodeCount = other.nodeCount;
	headNode = other.headNode;
	tailNode = other.tailNode;
	
	other.nodeCount = 0;
	other.headNode = nullptr;
	other.tailNode = nullptr;
}

template<typename ElementType>
SinglyLinkedList<ElementType>::~SinglyLinkedList() noexcept {
	removeAll();
}

template<typename ElementType>
SinglyLinkedList<ElementType>& SinglyLinkedList<ElementType>::operator=(const SinglyLinkedList<ElementType>& other) {
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
SinglyLinkedList<ElementType>& SinglyLinkedList<ElementType>::operator=(SinglyLinkedList<ElementType>&& other) noexcept {
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
bool SinglyLinkedList<ElementType>::operator==(const SinglyLinkedList<ElementType>& other) const noexcept {
	if (nodeCount != other.nodeCount) {
		return false;
	}
	
	return std::equal(cbegin(), cend(), other.cbegin(), other.cend());
}

template<typename ElementType>
SinglyLinkedList<ElementType>::ConstForwardIterator SinglyLinkedList<ElementType>::cbegin() const noexcept {
	return ConstForwardIterator {headNode};
}

template<typename ElementType>
SinglyLinkedList<ElementType>::ConstForwardIterator SinglyLinkedList<ElementType>::cend() const noexcept {
	return ConstForwardIterator {nullptr};
}

template<typename ElementType>
SinglyLinkedList<ElementType>::ForwardIterator SinglyLinkedList<ElementType>::begin() const noexcept {
	return ForwardIterator {headNode};
}

template<typename ElementType>
SinglyLinkedList<ElementType>::ForwardIterator SinglyLinkedList<ElementType>::end() const noexcept {
	return ForwardIterator {nullptr};
}

template<typename ElementType>
void SinglyLinkedList<ElementType>::insertAtHead(const ElementType& element) {
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
void SinglyLinkedList<ElementType>::insertAtHead(ElementType&& element) {
	auto* node {new SinglyLinkedListNode<ElementType> {std::move(element)}};
	
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
void SinglyLinkedList<ElementType>::insertAtTail(const ElementType& element) {
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
void SinglyLinkedList<ElementType>::insertAtTail(ElementType&& element) {
	auto* node {new SinglyLinkedListNode<ElementType> {std::move(element)}};
	
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
bool SinglyLinkedList<ElementType>::insertAtIndex(const ElementType& element, const std::size_t index) {
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
bool SinglyLinkedList<ElementType>::insertAtIndex(ElementType&& element, const std::size_t index) {
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
	
	auto* node {new SinglyLinkedListNode<ElementType> {std::move(element)}};
	
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
	delete node;
	--nodeCount;
	
	return element;
}

template<typename ElementType>
std::vector<ElementType> SinglyLinkedList<ElementType>::removeAll() {
	std::vector<ElementType> elements {};
	elements.reserve(nodeCount);
	
	auto currentNode {headNode};
	while (currentNode != nullptr) {
		elements.emplace_back(std::move(currentNode->getElement()));
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
SinglyLinkedList<ElementType>::ConstForwardIterator SinglyLinkedList<ElementType>::findFirst(const std::function<bool(
		const ElementType&)>& predicate) const noexcept {
	return std::find_if(cbegin(), cend(), predicate);
}

template<typename ElementType>
SinglyLinkedList<ElementType>::ForwardIterator SinglyLinkedList<ElementType>::findFirst(const std::function<bool(const ElementType&)>& predicate) noexcept {
	return std::find_if(begin(), end(), predicate);
}

template<typename ElementType>
void SinglyLinkedList<ElementType>::reverse() noexcept {
	if (headNode == nullptr || headNode == tailNode) {
		return;
	}
	
	SinglyLinkedListNode<ElementType>* previousNode {nullptr};
	SinglyLinkedListNode<ElementType>* currentNode {headNode};
	SinglyLinkedListNode<ElementType>* nextNode {nullptr};
	
	while (currentNode != nullptr) {
		nextNode = currentNode->getNextNode();
		currentNode->setNextNode(previousNode);
		previousNode = currentNode;
		currentNode = nextNode;
	}
	
	tailNode = headNode;
	headNode = previousNode;
}

template<typename ElementType>
bool SinglyLinkedList<ElementType>::contains(const std::function<bool(const ElementType&)>& predicate) const noexcept {
	return std::any_of(cbegin(), cend(), predicate);
}

template<typename ElementType>
bool SinglyLinkedList<ElementType>::containsAll(const std::vector<std::function<bool(const ElementType&)>>& predicates) const noexcept {
	return std::ranges::all_of(predicates, [this](const auto& predicate) {
		return contains(predicate);
	});
}

template<typename ElementType>
bool SinglyLinkedList<ElementType>::isEmpty() const noexcept {
	return nodeCount == 0 && headNode == nullptr && tailNode == nullptr;
}

template<typename ElementType>
std::size_t SinglyLinkedList<ElementType>::getNodeCount() const noexcept {
	return nodeCount;
}
}