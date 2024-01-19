#pragma once

#include <utility>

namespace Core::DataStructures::Trees {
/**
 * @brief A node for binary trees.
 * @class BinaryTreeNode
 * @tparam ElementType The type of the elements stored in the binary tree.
 */
template<typename ElementType>
class BinaryTreeNode final {
public:
	/**
	 * @brief Instantiates a new binary tree node with the given element using copy semantics.
	 * @param element The element to store in the node.
	 */
	explicit BinaryTreeNode(const ElementType& element) noexcept;
	
	/**
	 * @brief Instantiates a new binary tree node with the given element using move semantics.
	 * @param element The element to store in the node.
	 */
	explicit BinaryTreeNode(ElementType&& element) noexcept;
	
	/**
	 * @brief Instantiates a new binary tree node by copying the given node.
	 * @param other The node to copy.
	 */
	BinaryTreeNode(const BinaryTreeNode<ElementType>& other) noexcept = default;
	
	/**
	 * @brief Instantiates a new binary tree node by moving the given node.
	 * @param other The node to move.
	 */
	BinaryTreeNode(BinaryTreeNode<ElementType>&& other) noexcept = default;
	
	/**
	 * @brief Destroys the node.
	 */
	~BinaryTreeNode() noexcept = default;

public:
	/**
	 * @brief Assigns the given node to this node using copy semantics.
	 * @param other The node to copy.
	 * @return A reference to this node.
	 */
	BinaryTreeNode<ElementType>& operator=(const BinaryTreeNode<ElementType>& other) noexcept = default;
	
	/**
	 * @brief Assigns the given node to this node using move semantics.
	 * @param other The node to move.
	 * @return A reference to this node.
	 */
	BinaryTreeNode<ElementType>& operator=(BinaryTreeNode<ElementType>&& other) noexcept = default;
	
	/**
	 * @brief Checks if this node is equal to the given node.
	 * @details Two nodes are considered equal if their elements and children are equal.
	 * @param other The node to compare with.
	 * @return True if the two nodes are equal, false otherwise.
	 */
	bool operator==(const BinaryTreeNode<ElementType>& other) const noexcept;

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
	 * @brief Gets a pointer to the left child of the node.
	 * @return A pointer to the left child of the node.
	 */
	BinaryTreeNode<ElementType>* getLeftChild() noexcept;
	
	/**
	 * @brief Gets a const pointer to the left child of the node.
	 * @return A const pointer to the left child of the node.
	 */
	const BinaryTreeNode<ElementType>* getLeftChild() const noexcept;
	
	/**
	 * @brief Sets the left child of the node.
	 * @param leftChild A pointer to the left child of the node.
	 */
	void setLeftChild(BinaryTreeNode<ElementType>* leftChild) noexcept;
	
	/**
	 * @brief Gets a pointer to the right child of the node.
	 * @return A pointer to the right child of the node.
	 */
	BinaryTreeNode<ElementType>* getRightChild() noexcept;
	
	/**
	 * @brief Gets a const pointer to the right child of the node.
	 * @return A const pointer to the right child of the node.
	 */
	const BinaryTreeNode<ElementType>* getRightChild() const noexcept;
	
	/**
	 * @brief Sets the right child of the node.
	 * @param rightChild A pointer to the right child of the node.
	 */
	void setRightChild(BinaryTreeNode<ElementType>* rightChild) noexcept;

private:
	/**
	 * @brief Checks if the given children are equal.
	 * @details Two children are considered equal if they are both nullptr or if they are both not nullptr and their
	 * elements and children are equal.
	 * @param leftChild The left child of the node.
	 * @param rightChild The right child of the node.
	 * @return True if the children are equal, false otherwise.
	 */
	static bool areChildrenEqual(const BinaryTreeNode<ElementType>* leftChild,
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
bool BinaryTreeNode<ElementType>::operator==(const BinaryTreeNode<ElementType>& other) const noexcept {
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
BinaryTreeNode<ElementType>* BinaryTreeNode<ElementType>::getLeftChild() noexcept {
	return leftChild;
}

template<typename ElementType>
const BinaryTreeNode<ElementType>* BinaryTreeNode<ElementType>::getLeftChild() const noexcept {
	return leftChild;
}

template<typename ElementType>
void BinaryTreeNode<ElementType>::setLeftChild(BinaryTreeNode<ElementType>* leftChild) noexcept {
	this->leftChild = leftChild;
}

template<typename ElementType>
BinaryTreeNode<ElementType>* BinaryTreeNode<ElementType>::getRightChild() noexcept {
	return rightChild;
}

template<typename ElementType>
const BinaryTreeNode<ElementType>* BinaryTreeNode<ElementType>::getRightChild() const noexcept {
	return rightChild;
}

template<typename ElementType>
void BinaryTreeNode<ElementType>::setRightChild(BinaryTreeNode<ElementType>* rightChild) noexcept {
	this->rightChild = rightChild;
}

template<typename ElementType>
bool BinaryTreeNode<ElementType>::areChildrenEqual(const BinaryTreeNode<ElementType>* leftChild,
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