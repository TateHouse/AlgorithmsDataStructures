#pragma once

#include "Algorithms/ArrayOrVectorConcept.hpp"
#include "SearchingAlgorithm.hpp"

namespace Core::Algorithms::Searching {
/**
 * @brief An implementation of the binary search algorithm using iterators.
 * @tparam Container The type of the container to search.
 */
template<ArrayOrVectorConcept Container>
class BinarySearcher final : public SearchingAlgorithm<typename Container::value_type> {
public:
	/**
	 * @brief Instantiates a new binary searcher.
	 * @param container: The container to search.
	 */
	explicit BinarySearcher(const Container& container) noexcept;
	
	/**
	 * @brief Instantiates a new binary searcher by copying the given binary searcher.
	 * @param other: The binary searcher to copy.
	 */
	BinarySearcher(const BinarySearcher& other) noexcept = delete;
	
	/**
	 * @brief Instantiates a new binary searcher by moving the given binary searcher.
	 * @param other: The binary searcher to move.
	 */
	BinarySearcher(BinarySearcher&& other) noexcept = delete;
	
	/**
	 * @brief Destroys the binary searcher.
	 */
	~BinarySearcher() noexcept override = default;

public:
	/**
	 * @brief Assigns the given binary searcher to this binary searcher using copy semantics.
	 * @param other: The binary searcher to copy.
	 * @return A reference to this binary searcher.
	 */
	BinarySearcher& operator=(const BinarySearcher& other) noexcept = delete;
	
	/**
	 * @brief Assigns the given binary searcher to this binary searcher using move semantics.
	 * @param other: The binary searcher to move.
	 * @return A reference to this binary searcher.
	 */
	BinarySearcher& operator=(BinarySearcher&& other) noexcept = delete;

public:
	/**
	 * @brief Searches the container for the given value using the given predicate and the binary search algorithm.
	 * @param predicate: The predicate to use to search the container.
	 * @return True if the value was found, false otherwise.
	 */
	bool search(const std::function<char(const typename Container::value_type&)>& predicate) const noexcept override;

private:
	/**
	 * @brief Searches the container for the given value using the given predicate and the binary search algorithm.
	 * @tparam Iterator The type of the iterator to use to search the container.
	 * @param begin: The iterator to the beginning of the container.
	 * @param end: The iterator to the end of the container.
	 * @param predicate: The predicate to use to search the container.
	 * @return True if the value was found, false otherwise.
	 */
	template<typename Iterator>
	bool search(const Iterator& begin,
	            const Iterator& end,
	            const std::function<char(const typename Container::value_type&)>& predicate) const noexcept;

private:
	const Container& container;
};

template<ArrayOrVectorConcept Container>
BinarySearcher<Container>::BinarySearcher(const Container& container) noexcept
		: SearchingAlgorithm<typename Container::value_type> {}, container {container} {
	
}

template<ArrayOrVectorConcept Container>
bool BinarySearcher<Container>::search(const std::function<char(const typename Container::value_type&)>& predicate) const noexcept {
	return search(container.cbegin(), container.cend(), predicate);
}

template<ArrayOrVectorConcept Container>
template<typename Iterator>
bool BinarySearcher<Container>::search(const Iterator& begin,
                                       const Iterator& end,
                                       const std::function<char(const typename Container::value_type&)>& predicate) const noexcept {
	if (begin == end) {
		return false;
	}
	
	auto left {begin};
	auto right {end};
	
	while (left != right) {
		const auto middle {left + std::distance(left, right) / 2};
		const auto result {predicate(*middle)};
		
		if (result == 0) {
			return true;
		}
		
		if (result < 0) {
			right = middle;
		} else {
			left = std::next(middle);
		}
	}
	
	return false;
}
}