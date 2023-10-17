#pragma once

#include <utility>

namespace Core::DataStructures::Trees {
template<typename ElementType>
class BinaryTreeNode final {
public:
	explicit BinaryTreeNode(const ElementType& element) noexcept;
	explicit BinaryTreeNode(ElementType&& element) noexcept;
	BinaryTreeNode(const BinaryTreeNode<ElementType>& other) noexcept = default;
	BinaryTreeNode(BinaryTreeNode<ElementType>&& other) noexcept = default;
	~BinaryTreeNode() noexcept = default;

public:
	BinaryTreeNode<ElementType>& operator=(const BinaryTreeNode<ElementType>& other) noexcept = default;
	BinaryTreeNode<ElementType>& operator=(BinaryTreeNode<ElementType>&& other) noexcept = default;
	const bool operator==(const BinaryTreeNode<ElementType>& other) const noexcept;
	
public:
	ElementType& getElement() noexcept;
	const ElementType& getElement() const noexcept;

private:
	static const bool areChildrenEqual(const BinaryTreeNode<ElementType>* leftChild,
	                                   const BinaryTreeNode<ElementType>* rightChild) noexcept;

private:
	ElementType element;
	BinaryTreeNode<ElementType>* leftChild {nullptr};
	BinaryTreeNode<ElementType>* rightChild {nullptr};
};

template<typename ElementType>
BinaryTreeNode<ElementType>::BinaryTreeNode(const ElementType& element) noexcept : element {element} {

}

template<typename ElementType>
BinaryTreeNode<ElementType>::BinaryTreeNode(ElementType&& element) noexcept : element {std::move(element)} {

}

template<typename ElementType>
const bool BinaryTreeNode<ElementType>::operator==(const BinaryTreeNode<ElementType>& other) const noexcept {
	if (element != other.element) {
		return false;
	}
	
	return BinaryTreeNode<ElementType>::areChildrenEqual(leftChild, other.leftChild) &&
	       BinaryTreeNode<ElementType>::areChildrenEqual(rightChild, other.rightChild);
}

template<typename ElementType>
ElementType& BinaryTreeNode<ElementType>::getElement() noexcept {
	return element;
}

template<typename ElementType>
const ElementType& BinaryTreeNode<ElementType>::getElement() const noexcept {
	return element;
}

template<typename ElementType>
const bool BinaryTreeNode<ElementType>::areChildrenEqual(const BinaryTreeNode<ElementType>* leftChild,
                                                                const BinaryTreeNode<ElementType>* rightChild) noexcept {
	if (leftChild == nullptr && rightChild == nullptr) {
		return true;
	}
	
	if (leftChild == nullptr || rightChild == nullptr) {
		return false;
	}
	
	if (leftChild->element != rightChild->element) {
		return false;
	}
	
	return areChildrenEqual(leftChild->leftChild, rightChild->leftChild) &&
	       areChildrenEqual(leftChild->rightChild, rightChild->rightChild);
}
}