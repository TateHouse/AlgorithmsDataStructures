#pragma once

#include <functional>

namespace Core::Algorithms::Sorting {
/**
 * @brief An interface for sorting algorithms.
 * @tparam ElementType: The type of the elements to sort.
 */
template<typename ElementType>
class SortingAlgorithm {
public:
	/**
	 * @brief Destroys the sorting algorithm.
	 */
	virtual ~SortingAlgorithm() noexcept = default;

public:
	/**
	 * @brief Sorts the container using the given predicate and the sorting algorithm.
	 * @param predicate: The predicate to use to sort the container.
	 */
	virtual void sort(const std::function<bool(const ElementType&, const ElementType&)>& predicate) noexcept = 0;
};
}