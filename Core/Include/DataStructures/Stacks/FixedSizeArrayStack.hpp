#pragma once

#include <array>

namespace Core::DataStructures::Stacks {
template<typename ElementType, std::size_t Size>
class FixedSizeArrayStack final {
public:
	FixedSizeArrayStack() noexcept = default;
	FixedSizeArrayStack(const FixedSizeArrayStack<ElementType, Size>& other) noexcept = default;
	FixedSizeArrayStack(FixedSizeArrayStack<ElementType, Size>&& other) noexcept = default;
	~FixedSizeArrayStack() noexcept = default;

public:
	FixedSizeArrayStack<ElementType, Size>& operator=(const FixedSizeArrayStack<ElementType, Size>& other) noexcept = default;
	FixedSizeArrayStack<ElementType, Size>& operator=(FixedSizeArrayStack<ElementType, Size>&& other) noexcept = default;
	const bool operator==(const FixedSizeArrayStack<ElementType, Size>& other) const noexcept;

public:
	const bool push(const ElementType& element) noexcept;
	const bool push(ElementType&& element) noexcept;

private:
	std::array<ElementType, Size> array {};
	std::size_t topIndex {0};
};

template<typename ElementType, std::size_t Size>
const bool FixedSizeArrayStack<ElementType, Size>::operator==(const FixedSizeArrayStack<ElementType, Size>& other) const noexcept {
	if (this == &other) {
		return true;
	}
	
	if (topIndex != other.topIndex) {
		return false;
	}
	
	for (std::size_t index {0}; index <= topIndex; ++index) {
		if (array[index] != other.array[index]) {
			return false;
		}
	}
	
	return true;
}

template<typename ElementType, std::size_t Size>
const bool FixedSizeArrayStack<ElementType, Size>::push(const ElementType& element) noexcept {
	if (topIndex == Size) {
		return false;
	}
	
	array[topIndex] = element;
	++topIndex;
	
	return true;
}

template<typename ElementType, std::size_t Size>
const bool FixedSizeArrayStack<ElementType, Size>::push(ElementType&& element) noexcept {
	if (topIndex == Size) {
		return false;
	}
	
	array[topIndex] = std::move(element);
	++topIndex;
	
	return true;
}
}
