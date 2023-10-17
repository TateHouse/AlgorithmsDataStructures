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

private:
	ElementType element;
	BinaryTreeNode<ElementType>* leftChild {nullptr};
	BinaryTreeNode<ElementType>* rightChild {nullptr};
};

template<typename ElementType>
BinaryTreeNode<ElementType>::BinaryTreeNode(const ElementType& element) noexcept : element{element} {

}

template<typename ElementType>
BinaryTreeNode<ElementType>::BinaryTreeNode(ElementType&& element) noexcept : element{std::move(element)} {

}
}