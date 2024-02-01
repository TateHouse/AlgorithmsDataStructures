#pragma once

#include <algorithm>

#include "Algorithms/ArrayOrVectorConcept.hpp"
#include "SortingAlgorithm.hpp"

namespace Core::Algorithms::Sorting {
/**
 * @brief An implementation of the bubble sort algorithm using iterators.
 * @tparam Container: The type of the container to sort.
 */
template<ArrayOrVectorConcept Container>
class BubbleSorter final : public SortingAlgorithm<typename Container::value_type> {
public:
	/**
	 * @brief Instantiates a new bubble sorter.
	 * @param container: The container to sort.
	 */
	explicit BubbleSorter(Container& container) noexcept;
	
	/**
	 * @brief Instantiates a new bubble sorter by copying the given bubble sorter.
	 * @param other: The bubble sorter to copy.
	 */
	BubbleSorter(const BubbleSorter& other) noexcept = delete;
	
	/**
	 * @brief Instantiates a new bubble sorter by moving the given bubble sorter.
	 * @param other: The bubble sorter to move.
	 */
	BubbleSorter(BubbleSorter&& other) noexcept = delete;
	
	/**
	 * @brief Destroys the bubble sorter.
	 */
	~BubbleSorter() noexcept override = default;

public:
	/**
	 * @brief Assigns the given bubble sorter to this bubble sorter using copy semantics.
	 * @param other: The bubble sorter to copy.
	 * @return A reference to this bubble sorter.
	 */
	BubbleSorter& operator=(const BubbleSorter& other) noexcept = delete;
	
	/**
	 * @brief Assigns the given bubble sorter to this bubble sorter using move semantics.
	 * @param other: The bubble sorter to move.
	 * @return A reference to this bubble sorter.
	 */
	BubbleSorter& operator=(BubbleSorter&& other) noexcept = delete;

public:
	/**
	 * @brief Sorts the container using the given predicate and the bubble sort algorithm.
	 * @param predicate: The predicate to use to sort the container.
	 */
	void sort(const std::function<bool(const typename Container::value_type&,
	                                           const typename Container::value_type&)>& predicate) noexcept override;

private:
	/**
	 * @brief Sorts the container using the given predicate and the bubble sort algorithm.
	 * @tparam Iterator: The type of the iterator.
	 * @param begin: An iterator to the beginning of the container.
	 * @param end: An iterator to the end of the container.
	 * @param predicate: The predicate to use to sort the container.
	 */
	template<typename Iterator>
	void bubbleSort(Iterator begin,
	                Iterator end,
	                const std::function<bool(const typename Container::value_type&,
	                                         const typename Container::value_type&)>& predicate) noexcept;

private:
	Container& container;
};

template<ArrayOrVectorConcept Container>
BubbleSorter<Container>::BubbleSorter(Container& container) noexcept :
		SortingAlgorithm<typename Container::value_type> {}, container {container} {
	
}

template<ArrayOrVectorConcept Container>
void BubbleSorter<Container>::sort(const std::function<bool(const typename Container::value_type&,
                                                            const typename Container::value_type&)>& predicate) noexcept {
	bubbleSort(container.begin(), container.end(), predicate);
}

template<ArrayOrVectorConcept Container>
template<typename Iterator>
void BubbleSorter<Container>::bubbleSort(Iterator begin,
                                         Iterator end,
                                         const std::function<bool(const typename Container::value_type&,
                                                                  const typename Container::value_type&)>& predicate) noexcept {
	bool wasElementSwapped;
	
	for (auto passIterator {begin}; passIterator != end - 1; ++passIterator) {
		wasElementSwapped = false;
		
		for (auto elementIterator {begin};
		     elementIterator != end - std::distance(begin, passIterator) - 1; ++elementIterator) {
			auto nextElementIterator {std::next(elementIterator)};
			
			if (!predicate(*elementIterator, *nextElementIterator)) {
				std::iter_swap(elementIterator, nextElementIterator);
				wasElementSwapped = true;
			}
		}
		
		if (!wasElementSwapped) {
			break;
		}
	}
}
}