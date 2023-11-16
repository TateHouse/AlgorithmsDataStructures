#pragma once

#include "ArrayOrVectorConcept.hpp"
#include "SortingAlgorithm.hpp"

namespace Core::Algorithms::Sorting {
template<ArrayOrVectorConcept Container>
class MergeSorter final : public SortingAlgorithm<typename Container::value_type> {
public:
	explicit MergeSorter(Container& container) noexcept;
	MergeSorter(const MergeSorter& mergeSorter) noexcept = delete;
	MergeSorter(MergeSorter&& mergeSorter) noexcept = delete;
	~MergeSorter() noexcept override = default;

public:
	MergeSorter& operator=(const MergeSorter& mergeSorter) noexcept = delete;
	MergeSorter& operator=(MergeSorter&& mergeSorter) noexcept = delete;

public:
	virtual void sort(const std::function<bool(const typename Container::value_type&,
	                                           const typename Container::value_type&)>& predicate) noexcept override;

private:
	template<typename Iterator>
	void mergeSort(Iterator begin,
	               Iterator end,
	               const std::function<bool(const typename Container::value_type&,
	                                        const typename Container::value_type&)>& predicate) noexcept;
	
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