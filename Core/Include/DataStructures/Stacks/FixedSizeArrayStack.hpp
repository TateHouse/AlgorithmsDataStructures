#pragma once

#include <array>

namespace Core::DataStructures::Stacks {
template<typename ElementType, std::size_t Size>
class FixedSizeArrayStack final {
public:
	FixedSizeArrayStack() noexcept = default;
	FixedSizeArrayStack(const FixedSizeArrayStack<ElementType, Size>& other) noexcept = default;
	FixedSizeArrayStack(FixedSizeArrayStack<ElementType, Size>&& other) noexcept = default;

private:
	std::array<ElementType, Size> array {};
	std::size_t topIndex {0};
};
}