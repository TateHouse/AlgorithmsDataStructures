#pragma once

#include <algorithm>

#include "ArrayOrVectorConcept.hpp"
#include "SortingAlgorithm.hpp"

namespace Core::Algorithms::Sorting {
/**
 * @brief An implementation of the quick sort algorithm using iterators.
 * @tparam Container: The type of the container to sort.
 */
template<ArrayOrVectorConcept Container>
class QuickSorter final : public SortingAlgorithm<typename Container::value_type> {
public:
	/**
	 * @brief Instantiates a new quick sorter.
	 * @param container: The container to sort.
	 */
	explicit QuickSorter(Container& container) noexcept;
	
	/**
	 * @brief Instantiates a new quick sorter by copying the given quick sorter.
	 * @param other: The quick sorter to copy.
	 */
	QuickSorter(const QuickSorter& other) noexcept = delete;
	
	/**
	 * @brief Instantiates a new quick sorter by moving the given quick sorter.
	 * @param other: The quick sorter to move.
	 */
	QuickSorter(QuickSorter&& other) noexcept = delete;
	
	/**
	 * @brief Destroys the quick sorter.
	 */
	~QuickSorter() noexcept override = default;

public:
	/**
	 * @brief Assigns the given quick sorter to this quick sorter using copy semantics.
	 * @param other: The quick sorter to copy.
	 * @return A reference to this quick sorter.
	 */
	QuickSorter& operator=(const QuickSorter& other) noexcept = delete;
	
	/**
	 * @brief Assigns the given quick sorter to this quick sorter using move semantics.
	 * @param other: The quick sorter to move.
	 * @return A reference to this quick sorter.
	 */
	QuickSorter& operator=(QuickSorter&& other) noexcept = delete;

public:
	/**
	 * @brief Sorts the container using the given predicate and the quick sort algorithm.
	 * @param predicate: The predicate to use to sort the container.
	 */
	void sort(const std::function<bool(const typename Container::value_type&,
	                                           const typename Container::value_type&)>& predicate) noexcept override;

private:
	/**
	 * @brief Sorts the container using the given predicate and the quick sort algorithm.
	 * @tparam Iterator: The type of the iterator.
	 * @param begin: An iterator to the beginning of the container.
	 * @param end: An iterator to the end of the container.
	 * @param predicate: The predicate to use to sort the container.
	 */
	template<typename Iterator>
	void quickSort(Iterator begin,
	               Iterator end,
	               const std::function<bool(const typename Container::value_type&,
	                                        const typename Container::value_type&)>& predicate) noexcept;

private:
	Container& container;
};

template<ArrayOrVectorConcept Container>
QuickSorter<Container>::QuickSorter(Container& container) noexcept :
		SortingAlgorithm<typename Container::value_type> {}, container {container} {
}

template<ArrayOrVectorConcept Container>
void QuickSorter<Container>::sort(const std::function<bool(const typename Container::value_type&,
                                                           const typename Container::value_type&)>& predicate) noexcept {
	quickSort(container.begin(), container.end(), predicate);
}

template<ArrayOrVectorConcept Container>
template<typename Iterator>
void QuickSorter<Container>::quickSort(Iterator begin,
                                       Iterator end,
                                       const std::function<bool(const typename Container::value_type&,
                                                                const typename Container::value_type&)>& predicate) noexcept {
	const auto size {std::distance(begin, end)};
	if (size <= 1) {
		return;
	}
	
	auto pivotIterator {begin + (size / 2)};
	std::iter_swap(pivotIterator, end - 1);
	
	auto partitionIterator {begin};
	
	for (auto iterator {begin}; iterator != end - 1; ++iterator) {
		if (predicate(*iterator, *(end - 1))) {
			std::iter_swap(iterator, partitionIterator);
			++partitionIterator;
		}
	}
	
	std::iter_swap(partitionIterator, end - 1);
	
	quickSort(begin, partitionIterator, predicate);
	quickSort(partitionIterator + 1, end, predicate);
}
}