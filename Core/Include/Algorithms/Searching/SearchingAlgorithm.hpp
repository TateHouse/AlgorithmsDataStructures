#pragma once

#include <functional>

namespace Core::Algorithms::Searching {
template<typename ElementType>
class SearchingAlgorithm {
public:
	virtual ~SearchingAlgorithm() noexcept = default;

public:
	virtual bool search(const std::function<char(const ElementType&)>& predicate) const noexcept = 0;
};
}