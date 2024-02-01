#pragma once

#include "Algorithms/ArrayOrVectorConcept.hpp"
#include "SearchingAlgorithm.hpp"

namespace Core::Algorithms::Searching {
/**
 * @brief An implementation of the linear search algorithm using iterators.
 * @tparam Container The type of the container to search.
 */
template<ArrayOrVectorConcept Container>
class LinearSearcher final : public SearchingAlgorithm<typename Container::value_type> {
public:
	/**
	 * @brief Instantiates a new linear searcher.
	 * @param container: The container to search.
	 */
	explicit LinearSearcher(const Container& container) noexcept;
	
	/**
	 * @brief Instantiates a new linear searcher by copying the given linear searcher.
	 * @param other: The linear searcher to copy.
	 */
	LinearSearcher(const LinearSearcher& other) noexcept = delete;
	
	/**
	 * @brief Instantiates a new linear searcher by moving the given linear searcher.
	 * @param other: The linear searcher to move.
	 */
	LinearSearcher(LinearSearcher&& other) noexcept = delete;
	
	/**
	 * @brief Destroys the linear searcher.
	 */
	~LinearSearcher() noexcept override = default;

public:
	/**
	 * @brief Assigns the given linear searcher to this linear searcher using copy semantics.
	 * @param other: The linear searcher to copy.
	 * @return A reference to this linear searcher.
	 */
	LinearSearcher& operator=(const LinearSearcher& other) noexcept = delete;
	
	/**
	 * @brief Assigns the given linear searcher to this linear searcher using move semantics.
	 * @param other: The linear searcher to move.
	 * @return A reference to this linear searcher.
	 */
	LinearSearcher& operator=(LinearSearcher&& other) noexcept = delete;

public:
	/**
	 * @brief Searches the container for the given value using the given predicate and the linear search algorithm.
	 * @param predicate: The predicate to use to search the container.
	 * @return True if the value was found, false otherwise.
	 */
	bool search(const std::function<char(const typename Container::value_type&)>& predicate) const noexcept override;

private:
	/**
	 * @brief Searches the container using the given predicate and the linear search algorithm.
	 * @tparam Iterator The type of the iterator.
	 * @param begin An iterator to the beginning of the container.
	 * @param end An iterator to the end of the container.
	 * @param predicate The predicate to use to search the container.
	 * @return True if the value was found, false otherwise.
	 */
	template<typename Iterator>
	bool linearSearch(Iterator begin,
	                  Iterator end,
	                  const std::function<char(const typename Container::value_type&)>& predicate) const noexcept;

private:
	const Container& container;
};

template<ArrayOrVectorConcept Container>
LinearSearcher<Container>::LinearSearcher(const Container& container) noexcept :
		SearchingAlgorithm<typename Container::value_type> {}, container {container} {
	
}

template<ArrayOrVectorConcept Container>
bool LinearSearcher<Container>::search(const std::function<char(const typename Container::value_type&)>& predicate) const noexcept {
	return linearSearch(container.cbegin(), container.cend(), predicate);
}

template<ArrayOrVectorConcept Container>
template<typename Iterator>
bool LinearSearcher<Container>::linearSearch(Iterator begin,
                                             Iterator end,
                                             const std::function<char(const typename Container::value_type&)>& predicate) const noexcept {
	for (auto iterator {begin}; iterator != end; ++iterator) {
		if (predicate(*iterator)) {
			return true;
		}
	}
	
	return false;
}
}