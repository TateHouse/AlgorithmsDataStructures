#pragma once

#include <array>
#include <optional>

namespace Core::DataStructures::Queues {
template<typename ElementType, std::size_t Size>
class FixedSizeCircularArrayQueue final {
public:
	FixedSizeCircularArrayQueue() noexcept = default;
	FixedSizeCircularArrayQueue(const FixedSizeCircularArrayQueue<ElementType, Size>& other) noexcept = default;
	FixedSizeCircularArrayQueue(FixedSizeCircularArrayQueue<ElementType, Size>&& other) noexcept = default;
	~FixedSizeCircularArrayQueue() noexcept = default;

public:
	FixedSizeCircularArrayQueue<ElementType, Size>& operator=(const FixedSizeCircularArrayQueue<ElementType, Size>& other) noexcept = default;
	FixedSizeCircularArrayQueue<ElementType, Size>& operator=(FixedSizeCircularArrayQueue<ElementType, Size>&& other) noexcept = default;
	const bool operator==(const FixedSizeCircularArrayQueue<ElementType, Size>& other) const noexcept;

public:
	const bool enqueue(const ElementType& element) noexcept;
	const bool enqueue(ElementType&& element) noexcept;
	std::optional<ElementType> dequeue() noexcept;
	const ElementType* const getFront() const noexcept;
	const ElementType* const getBack() const noexcept;

private:
	std::array<ElementType, Size> array {};
	std::size_t elementCount {0};
	std::size_t frontIndex {0};
	std::size_t backIndex {Size - 1};
};

template<typename ElementType, std::size_t Size>
const bool FixedSizeCircularArrayQueue<ElementType, Size>::operator==(const FixedSizeCircularArrayQueue<ElementType, Size>& other) const noexcept {
	if (this == &other) {
		return true;
	}
	
	if (elementCount != other.elementCount || other.frontIndex != frontIndex || other.backIndex != backIndex) {
		return false;
	}
	
	for (std::size_t index {0}; index < elementCount; ++index) {
		if (array[(frontIndex + index) % Size] != other.array[(other.frontIndex + index) % Size]) {
			return false;
		}
	}
	
	return true;
}

template<typename ElementType, std::size_t Size>
const bool FixedSizeCircularArrayQueue<ElementType, Size>::enqueue(const ElementType& element) noexcept {
	if (elementCount == Size) {
		return false;
	}
	
	backIndex = (backIndex + 1) % Size;
	array[backIndex] = element;
	++elementCount;
	
	return true;
}

template<typename ElementType, std::size_t Size>
const bool FixedSizeCircularArrayQueue<ElementType, Size>::enqueue(ElementType&& element) noexcept {
	if (elementCount == Size) {
		return false;
	}
	
	backIndex = (backIndex + 1) % Size;
	array[backIndex] = std::move(element);
	++elementCount;
	
	return true;
}

template<typename ElementType, std::size_t Size>
std::optional<ElementType> FixedSizeCircularArrayQueue<ElementType, Size>::dequeue() noexcept {
	if (elementCount == 0) {
		return std::nullopt;
	}
	
	const auto element {std::move(array[frontIndex])};
	frontIndex = (frontIndex + 1) % Size;
	--elementCount;
	
	return element;
}

template<typename ElementType, std::size_t Size>
const ElementType* const FixedSizeCircularArrayQueue<ElementType, Size>::getFront() const noexcept {
	if (elementCount == 0) {
		return nullptr;
	}
	
	return &array[frontIndex];
}

template<typename ElementType, std::size_t Size>
const ElementType* const FixedSizeCircularArrayQueue<ElementType, Size>::getBack() const noexcept {
	if (elementCount == 0) {
		return nullptr;
	}
	
	return &array[backIndex];
}
}