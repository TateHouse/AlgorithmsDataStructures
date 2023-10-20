#pragma once

#include "DataStructures/Trees/BinaryTreeNode.hpp"
#include "DataStructures/Trees/Iterators/BinaryTreeConstInOrderIterator.hpp"
#include "DataStructures/Trees/Iterators/BinaryTreeConstLevelOrderIterator.hpp"
#include "DataStructures/Trees/Iterators/BinaryTreeConstPostOrderIterator.hpp"
#include "DataStructures/Trees/Iterators/BinaryTreeConstPreOrderIterator.hpp"
#include "DataStructures/Trees/Iterators/BinaryTreeInOrderIterator.hpp"
#include "DataStructures/Trees/Iterators/BinaryTreeLevelOrderIterator.hpp"
#include "DataStructures/Trees/Iterators/BinaryTreePostOrderIterator.hpp"
#include "DataStructures/Trees/Iterators/BinaryTreePreOrderIterator.hpp"

namespace Core::DataStructures::Trees {
template<typename ElementType>
class BinaryTree final {
public:
	BinaryTree() noexcept = default;

public:
	using value_type = ElementType;
	using ConstInOrderIterator = Iterators::BinaryTreeConstInOrderIterator<ElementType>;
	using ConstLevelOrderIterator = Iterators::BinaryTreeConstLevelOrderIterator<ElementType>;
	using ConstPostOrderIterator = Iterators::BinaryTreeConstPostOrderIterator<ElementType>;
	using ConstPreOrderIterator = Iterators::BinaryTreeConstPreOrderIterator<ElementType>;
	using InOrderIterator = Iterators::BinaryTreeInOrderIterator<ElementType>;
	using LevelOrderIterator = Iterators::BinaryTreeLevelOrderIterator<ElementType>;
	using PostOrderIterator = Iterators::BinaryTreePostOrderIterator<ElementType>;
	using PreOrderIterator = Iterators::BinaryTreePreOrderIterator<ElementType>;
	
	ConstInOrderIterator cbeginInOrder() const noexcept;
	ConstInOrderIterator cendInOrder() const noexcept;
	ConstLevelOrderIterator cbeginLevelOrder() const noexcept;
	ConstLevelOrderIterator cendLevelOrder() const noexcept;
	ConstPostOrderIterator cbeginPostOrder() const noexcept;
	ConstPostOrderIterator cendPostOrder() const noexcept;
	ConstPreOrderIterator cbeginPreOrder() const noexcept;
	ConstPreOrderIterator cendPreOrder() const noexcept;
	InOrderIterator beginInOrder() const noexcept;
	InOrderIterator endInOrder() const noexcept;
	LevelOrderIterator beginLevelOrder() const noexcept;
	LevelOrderIterator endLevelOrder() const noexcept;
	PostOrderIterator beginPostOrder() const noexcept;
	PostOrderIterator endPostOrder() const noexcept;
	PreOrderIterator beginPreOrder() const noexcept;
	PreOrderIterator endPreOrder() const noexcept;

private:
	std::size_t nodeCount {0};
	BinaryTreeNode<ElementType>* root {nullptr};
};

template<typename ElementType>
BinaryTree<ElementType>::ConstInOrderIterator BinaryTree<ElementType>::cbeginInOrder() const noexcept {
	return ConstInOrderIterator(root);
}

template<typename ElementType>
BinaryTree<ElementType>::ConstInOrderIterator BinaryTree<ElementType>::cendInOrder() const noexcept {
	return ConstInOrderIterator(nullptr);
}

template<typename ElementType>
BinaryTree<ElementType>::ConstLevelOrderIterator BinaryTree<ElementType>::cbeginLevelOrder() const noexcept {
	return ConstLevelOrderIterator(root);
}

template<typename ElementType>
BinaryTree<ElementType>::ConstLevelOrderIterator BinaryTree<ElementType>::cendLevelOrder() const noexcept {
	return ConstLevelOrderIterator(nullptr);
}

template<typename ElementType>
BinaryTree<ElementType>::ConstPostOrderIterator BinaryTree<ElementType>::cbeginPostOrder() const noexcept {
	return ConstPostOrderIterator(root);
}

template<typename ElementType>
BinaryTree<ElementType>::ConstPostOrderIterator BinaryTree<ElementType>::cendPostOrder() const noexcept {
	return ConstPostOrderIterator(nullptr);
}

template<typename ElementType>
BinaryTree<ElementType>::ConstPreOrderIterator BinaryTree<ElementType>::cbeginPreOrder() const noexcept {
	return ConstPreOrderIterator(root);
}

template<typename ElementType>
BinaryTree<ElementType>::ConstPreOrderIterator BinaryTree<ElementType>::cendPreOrder() const noexcept {
	return ConstPreOrderIterator(nullptr);
}

template<typename ElementType>
BinaryTree<ElementType>::InOrderIterator BinaryTree<ElementType>::beginInOrder() const noexcept {
	return InOrderIterator(root);
}

template<typename ElementType>
BinaryTree<ElementType>::InOrderIterator BinaryTree<ElementType>::endInOrder() const noexcept {
	return InOrderIterator(nullptr);
}

template<typename ElementType>
BinaryTree<ElementType>::LevelOrderIterator BinaryTree<ElementType>::beginLevelOrder() const noexcept {
	return LevelOrderIterator(root);
}

template<typename ElementType>
BinaryTree<ElementType>::LevelOrderIterator BinaryTree<ElementType>::endLevelOrder() const noexcept {
	return LevelOrderIterator(nullptr);
}

template<typename ElementType>
BinaryTree<ElementType>::PostOrderIterator BinaryTree<ElementType>::beginPostOrder() const noexcept {
	return PostOrderIterator(root);
}

template<typename ElementType>
BinaryTree<ElementType>::PostOrderIterator BinaryTree<ElementType>::endPostOrder() const noexcept {
	return PostOrderIterator(nullptr);
}

template<typename ElementType>
BinaryTree<ElementType>::PreOrderIterator BinaryTree<ElementType>::beginPreOrder() const noexcept {
	return PreOrderIterator(root);
}

template<typename ElementType>
BinaryTree<ElementType>::PreOrderIterator BinaryTree<ElementType>::endPreOrder() const noexcept {
	return PreOrderIterator(nullptr);
}
}