#pragma once

#include <algorithm>

#include "ArrayOrVectorConcept.hpp"
#include "SortingAlgorithm.hpp"

namespace Core::Algorithms::Sorting {
template<ArrayOrVectorConcept Container>
class QuickSorter final : public SortingAlgorithm<typename Container::value_type> {
public:
	explicit QuickSorter(Container& container) noexcept;
	QuickSorter(const QuickSorter& other) noexcept = delete;
	QuickSorter(QuickSorter&& other) noexcept = delete;
	~QuickSorter() noexcept override = default;

public:
	QuickSorter& operator=(const QuickSorter& other) noexcept = delete;
	QuickSorter& operator=(QuickSorter&& other) noexcept = delete;

public:
	virtual void sort(const std::function<bool(const typename Container::value_type&,
	                                           const typename Container::value_type&)>& predicate) noexcept override;

private:
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