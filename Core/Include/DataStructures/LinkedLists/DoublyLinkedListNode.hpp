#pragma once

#include <utility>

namespace Core::DataStructures::LinkedLists {
/**
 * @brief A node in a doubly linked list.
 * @class DoublyLinkedListNode
 * @tparam ElementType: The type of the element stored in the doubly linked list node.
 */
template<typename ElementType>
class DoublyLinkedListNode final {
public:
	/**
	 * @brief Instantiates a new DoublyLinkedListNode with the given element using copy semantics.
	 * @param element: The element to store in the node.
	 */
	explicit DoublyLinkedListNode(const ElementType& element) noexcept;
	
	/**
	 * @brief Instantiates a new DoublyLinkedListNode with the given element using move semantics.
	 * @param element: The element to store in the node.
	 */
	explicit DoublyLinkedListNode(ElementType&& element) noexcept;
	
	/**
	 * @brief Instantiates a new DoublyLinkedListNode by copying the given node.
	 * @param other: The node to copy.
	 */
	DoublyLinkedListNode(const DoublyLinkedListNode<ElementType>& other) noexcept = default;
	
	/**
	 * @brief Instantiates a new DoublyLinkedListNode by moving the given node.
	 * @param other: The node to move.
	 */
	DoublyLinkedListNode(DoublyLinkedListNode<ElementType>&& other) noexcept = default;
	
	/**
	 * @brief Destroys the node.
	 */
	~DoublyLinkedListNode() noexcept = default;

public:
	/**
	 * @brief Assigns the given node to this node using copy semantics.
	 * @param other: The node to copy.
	 * @return A reference to this node.
	 */
	DoublyLinkedListNode<ElementType>& operator=(const DoublyLinkedListNode<ElementType>& other) noexcept = default;
	
	/**
	 * @brief Assigns the given node to this node using move semantics.
	 * @param other: The node to move.
	 * @return A reference to this node.
	 */
	DoublyLinkedListNode<ElementType>& operator=(DoublyLinkedListNode<ElementType>&& other) noexcept = default;
	
	/**
	 * @brief Checks if this node is equal to the given node.
	 * @details Two nodes are considered equal if their elements are equal.
	 * @param other: The node to compare to.
	 * @return True if the nodes are equal, false otherwise.
	 */
	const bool operator==(const DoublyLinkedListNode<ElementType>& other) const noexcept;

public:
	/**
	 * @brief Gets a reference to the element stored in the node.
	 * @return A reference to the element stored in the node.
	 */
	ElementType& getElement() noexcept;
	
	/**
	 * @brief Gets a const reference to the element stored in the node.
	 * @return A const reference to the element stored in the node.
	 */
	const ElementType& getElement() const noexcept;
	
	/**
	 * @brief Gets a pointer to the next node in the doubly linked list.
	 * @return A pointer to the next node in the doubly linked list.
	 */
	DoublyLinkedListNode<ElementType>* getNextNode() noexcept;
	
	/**
	 * @brief Gets a const pointer to the next node in the doubly linked list.
	 * @return A const pointer to the next node in the doubly linked list.
	 */
	const DoublyLinkedListNode<ElementType>* getNextNode() const noexcept;
	
	/**
	 * @brief Sets the next node in the doubly linked list.
	 * @param nextNode: The next node in the doubly linked list.
	 */
	void setNextNode(DoublyLinkedListNode<ElementType>* nextNode) noexcept;
	
	/**
	 * @brief Gets a pointer to the previous node in the doubly linked list.
	 * @return A pointer to the previous node in the doubly linked list.
	 */
	DoublyLinkedListNode<ElementType>* getPreviousNode() noexcept;
	
	/**
	 * @brief Gets a const pointer to the previous node in the doubly linked list.
	 * @return A const pointer to the previous node in the doubly linked list.
	 */
	const DoublyLinkedListNode<ElementType>* getPreviousNode() const noexcept;
	
	/**
	 * @brief Sets the previous node in the doubly linked list.
	 * @param previousNode: The previous node in the doubly linked list.
	 */
	void setPreviousNode(DoublyLinkedListNode<ElementType>* previousNode) noexcept;

private:
	ElementType element;
	DoublyLinkedListNode<ElementType>* nextNode {nullptr};
	DoublyLinkedListNode<ElementType>* previousNode {nullptr};
};

template<typename ElementType>
DoublyLinkedListNode<ElementType>::DoublyLinkedListNode(const ElementType& element) noexcept : element(element) {

}

template<typename ElementType>
DoublyLinkedListNode<ElementType>::DoublyLinkedListNode(ElementType&& element) noexcept : element {std::move(element)} {

}

template<typename ElementType>
const bool DoublyLinkedListNode<ElementType>::operator==(const DoublyLinkedListNode<ElementType>& other) const noexcept {
	return element == other.element;
}

template<typename ElementType>
ElementType& DoublyLinkedListNode<ElementType>::getElement() noexcept {
	return element;
}

template<typename ElementType>
const ElementType& DoublyLinkedListNode<ElementType>::getElement() const noexcept {
	return element;
}

template<typename ElementType>
DoublyLinkedListNode<ElementType>* DoublyLinkedListNode<ElementType>::getNextNode() noexcept {
	return nextNode;
}

template<typename ElementType>
const DoublyLinkedListNode<ElementType>* DoublyLinkedListNode<ElementType>::getNextNode() const noexcept {
	return nextNode;
}

template<typename ElementType>
void DoublyLinkedListNode<ElementType>::setNextNode(DoublyLinkedListNode<ElementType>* nextNode) noexcept {
	this->nextNode = nextNode;
}

template<typename ElementType>
DoublyLinkedListNode<ElementType>* DoublyLinkedListNode<ElementType>::getPreviousNode() noexcept {
	return previousNode;
}

template<typename ElementType>
const DoublyLinkedListNode<ElementType>* DoublyLinkedListNode<ElementType>::getPreviousNode() const noexcept {
	return previousNode;
}

template<typename ElementType>
void DoublyLinkedListNode<ElementType>::setPreviousNode(DoublyLinkedListNode<ElementType>* previousNode) noexcept {
	this->previousNode = previousNode;
}
}