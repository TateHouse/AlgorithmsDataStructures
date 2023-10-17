#pragma once

namespace Core::DataStructures::LinkedLists {
template<typename ElementType>
class SinglyLinkedListNode final {
public:
	explicit SinglyLinkedListNode(const ElementType& element) noexcept;
	explicit SinglyLinkedListNode(ElementType&& element) noexcept;
	SinglyLinkedListNode(const SinglyLinkedListNode<ElementType>& other) noexcept = default;
	SinglyLinkedListNode(SinglyLinkedListNode<ElementType>&& other) noexcept = default;
	~SinglyLinkedListNode() noexcept = default;

public:
	SinglyLinkedListNode<ElementType>& operator=(const SinglyLinkedListNode<ElementType>& other) noexcept = default;
	SinglyLinkedListNode<ElementType>& operator=(SinglyLinkedListNode<ElementType>&& other) noexcept = default;
	const bool operator==(const SinglyLinkedListNode<ElementType>& other) const noexcept;

public:
	ElementType& getElement() noexcept;
	const ElementType& getElement() const noexcept;
	SinglyLinkedListNode<ElementType>* getNextNode() noexcept;
	const SinglyLinkedListNode<ElementType>* getNextNode() const noexcept;
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