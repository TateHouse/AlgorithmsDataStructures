#pragma once

#include "Algorithms/ArrayOrVectorConcept.hpp"
#include "SortingAlgorithm.hpp"

namespace Core::Algorithms::Sorting {
/**
 * @brief An implementation of the merge sort algorithm using iterators.
 * @tparam Container: The type of the container to sort.
 */
template<ArrayOrVectorConcept Container>
class MergeSorter final : public SortingAlgorithm<typename Container::value_type> {
public:
	/**
	 * @brief Instantiates a new merge sorter.
	 * @param container: The container to sort.
	 */
	explicit MergeSorter(Container& container) noexcept;
	
	/**
	 * @brief Instantiates a new merge sorter by copying the given merge sorter.
	 * @param mergeSorter: The merge sorter to copy.
	 */
	MergeSorter(const MergeSorter& mergeSorter) noexcept = default;
	
	/**
	 * @brief Instantiates a new merge sorter by moving the given merge sorter.
	 * @param mergeSorter: The merge sorter to move.
	 */
	MergeSorter(MergeSorter&& mergeSorter) noexcept = default;
	
	/**
	 * @brief Destroys the merge sorter.
	 */
	~MergeSorter() noexcept override = default;

public:
	/**
	 * @brief Assigns the given merge sorter to this merge sorter using copy semantics.
	 * @param mergeSorter: The merge sorter to copy.
	 * @return A reference to this merge sorter.
	 */
	MergeSorter& operator=(const MergeSorter& mergeSorter) noexcept = default;
	
	/**
	 * @brief Assigns the given merge sorter to this merge sorter using move semantics.
	 * @param mergeSorter: The merge sorter to move.
	 * @return A reference to this merge sorter.
	 */
	MergeSorter& operator=(MergeSorter&& mergeSorter) noexcept = default;

public:
	/**
	 * @brief Sorts the container using the given predicate and the merge sort algorithm.
	 * @param predicate: The predicate to use to sort the container.
	 */
	void sort(const std::function<bool(const typename Container::value_type&,
	                                           const typename Container::value_type&)>& predicate) noexcept override;

private:
	/**
	 * @brief Sorts the container using the given predicate and the merge sort algorithm.
	 * @tparam Iterator: The type of the iterator.
	 * @param begin: An iterator to the beginning of the container.
	 * @param end: An iterator to the end of the container.
	 * @param predicate: The predicate to use to sort the container.
	 */
	template<typename Iterator>
	void mergeSort(Iterator begin,
	               Iterator end,
	               const std::function<bool(const typename Container::value_type&,
	                                        const typename Container::value_type&)>& predicate) noexcept;
	
	/**
	 * @brief Merges the two halves of the container.
	 * @tparam Iterator: The type of the iterator.
	 * @param begin: An iterator to the beginning of the container.
	 * @param middle: An iterator to the middle of the container.
	 * @param end: An iterator to the end of the container.
	 * @param predicate: The predicate to use to sort the container.
	 */
	template<typename Iterator>
	void merge(Iterator begin,
	           Iterator middle,
	           Iterator end,
	           const std::function<bool(const typename Container::value_type&,
	                                    const typename Container::value_type&)>& predicate) noexcept;

private:
	Container& container;
};

template<ArrayOrVectorConcept Container>
MergeSorter<Container>::MergeSorter(Container& container) noexcept :
		SortingAlgorithm<typename Container::value_type> {}, container {container} {
	
}

template<ArrayOrVectorConcept Container>
void MergeSorter<Container>::sort(const std::function<bool(const typename Container::value_type&,
                                                           const typename Container::value_type&)>& predicate) noexcept {
	mergeSort(container.begin(), container.end(), predicate);
}

template<ArrayOrVectorConcept Container>
template<typename Iterator>
void MergeSorter<Container>::mergeSort(Iterator begin,
                                       Iterator end,
                                       const std::function<bool(const typename Container::value_type&,
                                                                const typename Container::value_type&)>& predicate) noexcept {
	const auto size {std::distance(begin, end)};
	if (size < 2) {
		return;
	}
	
	const auto offsetToMiddle {size / 2};
	auto middle {std::next(begin, offsetToMiddle)};
	
	mergeSort(begin, middle, predicate);
	mergeSort(middle, end, predicate);
	
	merge(begin, middle, end, predicate);
}

template<ArrayOrVectorConcept Container>
template<typename Iterator>
void MergeSorter<Container>::merge(Iterator begin,
                                   Iterator middle,
                                   Iterator end,
                                   const std::function<bool(const typename Container::value_type&,
                                                            const typename Container::value_type&)>& predicate) noexcept {
	auto buffer {std::vector<typename std::iterator_traits<Iterator>::value_type> {begin, end}};
	auto leftIterator {buffer.begin()};
	auto rightIterator {buffer.begin() + (middle - begin)};
	auto leftEnd {rightIterator};
	auto rightEnd {buffer.end()};
	auto currentIterator {begin};
	
	while (leftIterator != leftEnd && rightIterator != rightEnd) {
		*currentIterator = predicate(*leftIterator, *rightIterator) ? *leftIterator++ : *rightIterator++;
		++currentIterator;
	}
	
	std::copy(leftIterator, leftEnd, currentIterator);
	std::copy(rightIterator, rightEnd, currentIterator);
}
}