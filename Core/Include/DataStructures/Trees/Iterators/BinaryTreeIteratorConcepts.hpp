#pragma once

#include <concepts>

#include "BinaryTreeConstInOrderIterator.hpp"
#include "BinaryTreeConstLevelOrderIterator.hpp"
#include "BinaryTreeConstPostOrderIterator.hpp"
#include "BinaryTreeConstPreOrderIterator.hpp"
#include "BinaryTreeInOrderIterator.hpp"
#include "BinaryTreeLevelOrderIterator.hpp"
#include "BinaryTreePostOrderIterator.hpp"
#include "BinaryTreePreOrderIterator.hpp"

namespace Core::DataStructures::Trees::Iterators {
template<typename IteratorType, typename ElementType>
concept AllowedConstIterator =
	std::same_as<IteratorType, BinaryTreeConstInOrderIterator<ElementType>> ||
	std::same_as<IteratorType, BinaryTreeConstLevelOrderIterator<ElementType>> ||
	std::same_as<IteratorType, BinaryTreeConstPostOrderIterator<ElementType>> ||
	std::same_as<IteratorType, BinaryTreeConstPreOrderIterator<ElementType>>;

template<typename IteratorType, typename ElementType>
concept AllowedIterator =
	std::same_as<IteratorType, BinaryTreeInOrderIterator<ElementType>> ||
	std::same_as<IteratorType, BinaryTreeLevelOrderIterator<ElementType>> ||
	std::same_as<IteratorType, BinaryTreePostOrderIterator<ElementType>> ||
	std::same_as<IteratorType, BinaryTreePreOrderIterator<ElementType>>;
}