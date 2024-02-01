#pragma once

namespace Core::Algorithms::Searching {
/**
 * @brief A predicate used to search for an element using the binary search algorithm.
 * @tparam ElementType The type of the elements to search for.
 */
template<typename ElementType>
class BinarySearchPredicate final {
public:
	/**
	 * @brief Instantiates a new binary search predicate.
	 * @param target: The target to search for.
	 */
	explicit BinarySearchPredicate(const ElementType& target) noexcept;
	
	/**
	 * @brief Instantiates a new binary search predicate by copying the given binary search predicate.
	 * @param other: The binary search predicate to copy.
	 */
	BinarySearchPredicate(const BinarySearchPredicate& other) noexcept = default;
	
	/**
	 * @brief Instantiates a new binary search predicate by moving the given binary search predicate.
	 * @param other: The binary search predicate to move.
	 */
	BinarySearchPredicate(BinarySearchPredicate&& other) noexcept = default;
	
	/**
	 * @brief Destroys the binary search predicate.
	 */
	~BinarySearchPredicate() noexcept = default;

public:
	/**
	 * @brief Assigns the given binary search predicate to this binary search predicate using copy semantics.
	 * @param other: The binary search predicate to copy.
	 * @return A reference to this binary search predicate.
	 */
	BinarySearchPredicate& operator=(const BinarySearchPredicate& other) noexcept = default;
	
	/**
	 * @brief Assigns the given binary search predicate to this binary search predicate using move semantics.
	 * @param other: The binary search predicate to move.
	 * @return A reference to this binary search predicate.
	 */
	BinarySearchPredicate& operator=(BinarySearchPredicate&& other) noexcept = default;

public:
	/**
	 * @brief Compares the given element with the target.
	 * @param element: The element to compare.
	 * @return 0 if the element is equal to the target, -1 if the element is less than the target, 1 if the element is greater than the target.
	 */
	char operator()(const ElementType& element) const noexcept;

private:
	ElementType target;
};

template<typename ElementType>
BinarySearchPredicate<ElementType>::BinarySearchPredicate(const ElementType& target) noexcept : target {target} {

}

template<typename ElementType>
char BinarySearchPredicate<ElementType>::operator()(const ElementType& element) const noexcept {
	if (target == element) {
		return 0;
	}
	
	return target < element ? -1 : 1;
}
}
