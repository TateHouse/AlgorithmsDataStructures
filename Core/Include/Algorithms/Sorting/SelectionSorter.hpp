#pragma once

#include <algorithm>

#include "ArrayOrVectorConcept.hpp"
#include "SortingAlgorithm.hpp"

namespace Core::Algorithms::Sorting {
template<ArrayOrVectorConcept Container>
class SelectionSorter final : public SortingAlgorithm<typename Container::value_type> {
public:
	explicit SelectionSorter(Container& container) noexcept;
	SelectionSorter(const SelectionSorter& other) noexcept = delete;
	SelectionSorter(SelectionSorter&& other) noexcept = delete;
	~SelectionSorter() noexcept override = default;

public:
	SelectionSorter& operator=(const SelectionSorter& other) noexcept = delete;
	SelectionSorter& operator=(SelectionSorter&& other) noexcept = delete;

public:
	virtual void sort(const std::function<bool(const typename Container::value_type&,
	                                           const typename Container::value_type&)>& predicate) noexcept override;

private:
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