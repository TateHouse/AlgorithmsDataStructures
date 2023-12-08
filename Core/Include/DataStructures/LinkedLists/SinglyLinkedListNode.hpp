#pragma once

#include <utility>

namespace Core::DataStructures::LinkedLists {
/**
 * @brief A node in a singly linked list.
 * @class SinglyLinkedListNode
 * @tparam ElementType: The type of the element stored in the singly linked list node.
 */
template<typename ElementType>
class SinglyLinkedListNode final {
public:
	/**
	 * @brief Instantiates a new SinglyLinkedListNode with the given element using copy semantics.
	 * @param element: The element to store in the node.
	 */
	explicit SinglyLinkedListNode(const ElementType& element) noexcept;
	
	/**
	 * @brief Instantiates a new SinglyLinkedListNode with the given element using move semantics.
	 * @param element: The element to store in the node.
	 */
	explicit SinglyLinkedListNode(ElementType&& element) noexcept;
	
	/**
	 * @brief Instantiates a new SinglyLinkedListNode by copying the given node.
	 * @param other: The node to copy.
	 */
	SinglyLinkedListNode(const SinglyLinkedListNode<ElementType>& other) noexcept = default;
	
	/**
	 * @brief Instantiates a new SinglyLinkedListNode by moving the given node.
	 * @param other: The node to move.
	 */
	SinglyLinkedListNode(SinglyLinkedListNode<ElementType>&& other) noexcept = default;
	
	/**
	 * @brief Destroys the node.
	 */
	~SinglyLinkedListNode() noexcept = default;

public:
	/**
	 * @brief Assigns the given node to this node using copy semantics.
	 * @param other: The node to copy.
	 * @return A reference to this node.
	 */
	SinglyLinkedListNode<ElementType>& operator=(const SinglyLinkedListNode<ElementType>& other) noexcept = default;
	
	/**
	 * @brief Assigns the given node to this node using move semantics.
	 * @param other: The node to move.
	 * @return A reference to this node.
	 */
	SinglyLinkedListNode<ElementType>& operator=(SinglyLinkedListNode<ElementType>&& other) noexcept = default;
	
	/**
	 * @brief Checks if this node is equal to the given node.
	 * @details Two nodes are considered equal if their elements are equal.
	 * @param other: The node to compare to.
	 * @return True if the nodes are equal, false otherwise.
	 */
	const bool operator==(const SinglyLinkedListNode<ElementType>& other) const noexcept;

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
	 * @brief Gets a pointer to the next node in the singly linked list.
	 * @return A pointer to the next node in the singly linked list.
	 */
	SinglyLinkedListNode<ElementType>* getNextNode() noexcept;
	
	/**
	 * @brief Gets a const pointer to the next node in the singly linked list.
	 * @return A const pointer to the next node in the singly linked list.
	 */
	const SinglyLinkedListNode<ElementType>* getNextNode() const noexcept;
	
	/**
	 * @brief Sets the next node in the singly linked list.
	 * @param nextNode: The next node in the singly linked list.
	 */
	void setNextNode(SinglyLinkedListNode<ElementType>* nextNode) noexcept;

private:
	ElementType element;
	SinglyLinkedListNode<ElementType>* nextNode {nullptr};
};

template<typename ElementType>
SinglyLinkedListNode<ElementType>::SinglyLinkedListNode(const ElementType& element) noexcept : element(element) {

}

template<typename ElementType>
SinglyLinkedListNode<ElementType>::SinglyLinkedListNode(ElementType&& element) noexcept : element(std::move(element)) {

}

template<typename ElementType>
const bool SinglyLinkedListNode<ElementType>::operator==(const SinglyLinkedListNode<ElementType>& other) const noexcept {
	return element == other.element;
}

template<typename ElementType>
ElementType& SinglyLinkedListNode<ElementType>::getElement() noexcept {
	return element;
}

template<typename ElementType>
const ElementType& SinglyLinkedListNode<ElementType>::getElement() const noexcept {
	return element;
}

template<typename ElementType>
SinglyLinkedListNode<ElementType>* SinglyLinkedListNode<ElementType>::getNextNode() noexcept {
	return nextNode;
}

template<typename ElementType>
const SinglyLinkedListNode<ElementType>* SinglyLinkedListNode<ElementType>::getNextNode() const noexcept {
	return nextNode;
}

template<typename ElementType>
void SinglyLinkedListNode<ElementType>::setNextNode(SinglyLinkedListNode<ElementType>* nextNode) noexcept {
	this->nextNode = nextNode;
}
}