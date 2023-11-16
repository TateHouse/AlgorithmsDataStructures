#pragma once

#include "ArrayOrVectorConcept.hpp"
#include "SortingAlgorithm.hpp"

namespace Core::Algorithms::Sorting {
template<ArrayOrVectorConcept Container>
class InsertionSorter final : public SortingAlgorithm<typename Container::value_type> {
public:
	explicit InsertionSorter(Container& container) noexcept;
	InsertionSorter(const InsertionSorter& insertionSorter) noexcept = delete;
	InsertionSorter(InsertionSorter&& insertionSorter) noexcept = delete;
	~InsertionSorter() noexcept override = default;

public:
	InsertionSorter& operator=(const InsertionSorter& insertionSorter) noexcept = delete;
	InsertionSorter& operator=(InsertionSorter&& insertionSorter) noexcept = delete;

public:
	virtual void sort(const std::function<bool(const typename Container::value_type&,
	                                           const typename Container::value_type&)>& predicate) noexcept override;

private:
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