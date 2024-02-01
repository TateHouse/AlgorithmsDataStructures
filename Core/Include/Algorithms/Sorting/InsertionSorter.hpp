#pragma once

#include "Algorithms/ArrayOrVectorConcept.hpp"
#include "SortingAlgorithm.hpp"

namespace Core::Algorithms::Sorting {
/**
 * @brief An implementation of the insertion sort algorithm using iterators.
 * @tparam Container: The type of the container to sort.
 */
template<ArrayOrVectorConcept Container>
class InsertionSorter final : public SortingAlgorithm<typename Container::value_type> {
public:
	/**
	 * @brief Instantiates a new insertion sorter.
	 * @param container: The container to sort.
	 */
	explicit InsertionSorter(Container& container) noexcept;
	
	/**
	 * @brief Instantiates a new insertion sorter by copying the given insertion sorter.
	 * @param other: The insertion sorter to copy.
	 */
	InsertionSorter(const InsertionSorter& other) noexcept = delete;
	
	/**
	 * @brief Instantiates a new insertion sorter by moving the given insertion sorter.
	 * @param other: The insertion sorter to move.
	 */
	InsertionSorter(InsertionSorter&& other) noexcept = delete;
	
	/**
	 * @brief Destroys the insertion sorter.
	 */
	~InsertionSorter() noexcept override = default;

public:
	/**
	 * @brief Assigns the given insertion sorter to this insertion sorter using copy semantics.
	 * @param other: The insertion sorter to copy.
	 * @return A reference to this insertion sorter.
	 */
	InsertionSorter& operator=(const InsertionSorter& other) noexcept = delete;
	
	/**
	 * @brief Assigns the given insertion sorter to this insertion sorter using move semantics.
	 * @param other: The insertion sorter to move.
	 * @return A reference to this insertion sorter.
	 */
	InsertionSorter& operator=(InsertionSorter&& other) noexcept = delete;

public:
	/**
	 * @brief Sorts the container using the given predicate and the insertion sort algorithm.
	 * @param predicate: The predicate to use to sort the container.
	 */
	void sort(const std::function<bool(const typename Container::value_type&,
	                                           const typename Container::value_type&)>& predicate) noexcept override;

private:
	/**
	 * @brief Sorts the container using the given predicate and the insertion sort algorithm.
	 * @tparam Iterator: The type of the iterator.
	 * @param begin: An iterator to the beginning of the container.
	 * @param end: An iterator to the end of the container.
	 * @param predicate: The predicate to use to sort the container.
	 */
	template<typename Iterator>
	void insertionSort(Iterator begin,
	                   Iterator end,
	                   const std::function<bool(const typename Container::value_type&,
	                                            const typename Container::value_type&)>& predicate) noexcept;

private:
	Container& container;
};

template<ArrayOrVectorConcept Container>
InsertionSorter<Container>::InsertionSorter(Container& container) noexcept :
		SortingAlgorithm<typename Container::value_type> {}, container {container} {
}

template<ArrayOrVectorConcept Container>
void InsertionSorter<Container>::sort(const std::function<bool(const typename Container::value_type&,
                                                               const typename Container::value_type&)>& predicate) noexcept {
	insertionSort(container.begin(), container.end(), predicate);
}

template<ArrayOrVectorConcept Container>
template<typename Iterator>
void InsertionSorter<Container>::insertionSort(Iterator begin,
                                               Iterator end,
                                               const std::function<bool(const typename Container::value_type&,
                                                                        const typename Container::value_type&)>& predicate) noexcept {
	for (auto elementIterator {begin + 1}; elementIterator != end; ++elementIterator) {
		auto currentElement {*elementIterator};
		auto currentIterator {elementIterator};
		
		while (currentIterator != begin && predicate(currentElement, *(currentIterator - 1))) {
			*currentIterator = *(currentIterator - 1);
			--currentIterator;
		}
		
		*currentIterator = currentElement;
	}
}
}