#pragma once

#include <algorithm>

#include "ArrayOrVectorConcept.hpp"
#include "SortingAlgorithm.hpp"

namespace Core::Algorithms::Sorting {
template<ArrayOrVectorConcept Container>
class BubbleSorter final : public SortingAlgorithm<typename Container::value_type> {
public:
	explicit BubbleSorter(Container& container) noexcept;
	BubbleSorter(const BubbleSorter& other) noexcept = delete;
	BubbleSorter(BubbleSorter&& other) noexcept = delete;
	~BubbleSorter() noexcept override = default;

public:
	BubbleSorter& operator=(const BubbleSorter& other) noexcept = delete;
	BubbleSorter& operator=(BubbleSorter&& other) noexcept = delete;

public:
	virtual void sort(const std::function<bool(const typename Container::value_type&,
	                                           const typename Container::value_type&)>& predicate) noexcept override;

private:
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