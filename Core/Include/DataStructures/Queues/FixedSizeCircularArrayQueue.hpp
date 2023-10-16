#pragma once

#include <array>

namespace Core::DataStructures::Queues {
template<typename ElementType, std::size_t Size>
class FixedSizeCircularArrayQueue final {
public:
	FixedSizeCircularArrayQueue() noexcept = default;
	FixedSizeCircularArrayQueue(const FixedSizeCircularArrayQueue<ElementType, Size>& other) noexcept = default;
	FixedSizeCircularArrayQueue(FixedSizeCircularArrayQueue<ElementType, Size>&& other) noexcept = default;

private:
	std::array<ElementType, Size> array {};
	std::size_t elementCount {0};
	std::size_t frontIndex {0};
	std::size_t backIndex {Size - 1};
};
}