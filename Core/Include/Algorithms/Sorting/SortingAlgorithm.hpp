#pragma once

#include <functional>

namespace Core::Algorithms::Sorting {
template<typename ElementType>
class SortingAlgorithm {
public:
	virtual ~SortingAlgorithm() noexcept = default;

public:
	virtual void sort(const std::function<bool(const ElementType&, const ElementType&)>& predicate) noexcept = 0;
};
}