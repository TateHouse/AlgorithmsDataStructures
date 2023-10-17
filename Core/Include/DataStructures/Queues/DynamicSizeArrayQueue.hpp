#pragma once

#include <vector>

namespace Core::DataStructures::Queues {
template<typename ElementType>
class DynamicSizeArrayQueue final {
public:
	DynamicSizeArrayQueue() noexcept = default;
	DynamicSizeArrayQueue(const DynamicSizeArrayQueue<ElementType>& other) noexcept = default;
	DynamicSizeArrayQueue(DynamicSizeArrayQueue<ElementType>&& other) noexcept = default;

private:
	std::vector<ElementType> vector {};
};
}