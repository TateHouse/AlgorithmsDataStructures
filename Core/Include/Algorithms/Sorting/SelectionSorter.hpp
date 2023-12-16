#pragma once

#include <algorithm>

#include "ArrayOrVectorConcept.hpp"
#include "SortingAlgorithm.hpp"

namespace Core::Algorithms::Sorting {
/**
 * @brief An implementation of the selection sort algorithm using iterators.
 * @tparam Container: The type of the container to sort.
 */
template<ArrayOrVectorConcept Container>
class SelectionSorter final : public SortingAlgorithm<typename Container::value_type> {
public:
	/**
	 * @brief Instantiates a new selection sorter.
	 * @param container: The container to sort.
	 */
	explicit SelectionSorter(Container& container) noexcept;
	
	/**
	 * @brief Instantiates a new selection sorter by copying the given selection sorter.
	 * @param other: The selection sorter to copy.
	 */
	SelectionSorter(const SelectionSorter& other) noexcept = delete;
	
	/**
	 * @brief Instantiates a new selection sorter by moving the given selection sorter.
	 * @param other: The selection sorter to move.
	 */
	SelectionSorter(SelectionSorter&& other) noexcept = delete;
	
	/**
	 * @brief Destroys the selection sorter.
	 */
	~SelectionSorter() noexcept override = default;

public:
	/**
	 * @brief Assigns the given selection sorter to this selection sorter using copy semantics.
	 * @param other: The selection sorter to copy.
	 * @return A reference to this selection sorter.
	 */
	SelectionSorter& operator=(const SelectionSorter& other) noexcept = delete;
	
	/**
	 * @brief Assigns the given selection sorter to this selection sorter using move semantics.
	 * @param other: The selection sorter to move.
	 * @return A reference to this selection sorter.
	 */
	SelectionSorter& operator=(SelectionSorter&& other) noexcept = delete;

public:
	/**
	 * @brief Sorts the container using the given predicate and the selection sort algorithm.
	 * @param predicate: The predicate to use to sort the container.
	 */
	void sort(const std::function<bool(const typename Container::value_type&,
	                                           const typename Container::value_type&)>& predicate) noexcept override;

private:
	/**
	 * @brief Sorts the container using the given predicate and the selection sort algorithm.
	 * @tparam Iterator: The type of the iterator.
	 * @param begin: An iterator to the beginning of the container.
	 * @param end: An iterator to the end of the container.
	 * @param predicate: The predicate to use to sort the container.
	 */
	template<typename Iterator>
	void selectionSort(Iterator begin,
	                   Iterator end,
	                   const std::function<bool(const typename Container::value_type&,
	                                            const typename Container::value_type&)>& predicate) noexcept;

private:
	Container& container;
};

template<ArrayOrVectorConcept Container>
SelectionSorter<Container>::SelectionSorter(Container& container) noexcept :
		SortingAlgorithm<typename Container::value_type> {}, container {container} {
	
}

template<ArrayOrVectorConcept Container>
void SelectionSorter<Container>::sort(const std::function<bool(const typename Container::value_type&,
                                                               const typename Container::value_type&)>& predicate) noexcept {
	selectionSort(container.begin(), container.end(), predicate);
}

template<ArrayOrVectorConcept Container>
template<typename Iterator>
void SelectionSorter<Container>::selectionSort(Iterator begin,
                                               Iterator end,
                                               const std::function<bool(const typename Container::value_type&,
                                                                        const typename Container::value_type&)>& predicate) noexcept {
	for (auto partitionIterator {begin}; partitionIterator != end; ++partitionIterator) {
		auto selectedIterator {partitionIterator};
		
		for (auto searchIterator {std::next(partitionIterator)}; searchIterator != end; ++searchIterator) {
			if (predicate(*searchIterator, *selectedIterator)) {
				selectedIterator = searchIterator;
			}
		}
		
		if (selectedIterator != partitionIterator) {
			std::iter_swap(partitionIterator, selectedIterator);
		}
	}
}
}