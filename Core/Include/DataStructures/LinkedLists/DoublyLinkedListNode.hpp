#pragma once

namespace Core::DataStructures::LinkedLists {
template<typename ElementType>
class DoublyLinkedListNode final {
public:
	explicit DoublyLinkedListNode(const ElementType& element) noexcept;
	explicit DoublyLinkedListNode(ElementType&& element) noexcept;
	DoublyLinkedListNode(const DoublyLinkedListNode<ElementType>& other) noexcept = default;
	DoublyLinkedListNode(DoublyLinkedListNode<ElementType>&& other) noexcept = default;

public:
	const bool operator==(const DoublyLinkedListNode<ElementType>& other) const noexcept;

public:
	ElementType& getElement() noexcept;
	const ElementType& getElement() const noexcept;
	DoublyLinkedListNode<ElementType>* getNextNode() noexcept;
	const DoublyLinkedListNode<ElementType>* getNextNode() const noexcept;
	void setNextNode(DoublyLinkedListNode<ElementType>* nextNode) noexcept;
	DoublyLinkedListNode<ElementType>* getPreviousNode() noexcept;
	const DoublyLinkedListNode<ElementType>* getPreviousNode() const noexcept;
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