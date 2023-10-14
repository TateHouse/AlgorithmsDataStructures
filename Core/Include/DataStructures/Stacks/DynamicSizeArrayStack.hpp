#pragma once

#include <vector>

namespace Core::DataStructures::Stacks {
template<typename ElementType>
class DynamicSizeArrayStack final {
public:
	DynamicSizeArrayStack() noexcept = default;
	DynamicSizeArrayStack(const DynamicSizeArrayStack<ElementType>& other) noexcept = default;
	DynamicSizeArrayStack(DynamicSizeArrayStack<ElementType>&& other) noexcept = default;
	~DynamicSizeArrayStack() noexcept = default;

private:
	std::vector<ElementType> vector {};
};
}