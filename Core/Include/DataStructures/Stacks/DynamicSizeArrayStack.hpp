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
	
public:
	DynamicSizeArrayStack<ElementType>& operator=(const DynamicSizeArrayStack<ElementType>& other) noexcept = default;
	DynamicSizeArrayStack<ElementType>& operator=(DynamicSizeArrayStack<ElementType>&& other) noexcept = default;
	const bool operator==(const DynamicSizeArrayStack<ElementType>& other) const noexcept;
	
private:
	std::vector<ElementType> vector {};
};

template<typename ElementType>
const bool DynamicSizeArrayStack<ElementType>::operator==(const DynamicSizeArrayStack<ElementType>& other) const noexcept {
	if (this == &other) {
		return true;
	}
	
	if (vector.size() != other.vector.size()) {
		return false;
	}
	
	for (std::size_t index {0}; index < vector.size(); ++index) {
		if (vector[index] != other.vector[index]) {
			return false;
		}
	}
	
	return true;
}
}