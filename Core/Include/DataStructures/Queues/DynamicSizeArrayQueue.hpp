#pragma once

#include <optional>
#include <vector>

namespace Core::DataStructures::Queues {
template<typename ElementType>
class DynamicSizeArrayQueue final {
public:
	DynamicSizeArrayQueue() noexcept = default;
	DynamicSizeArrayQueue(const DynamicSizeArrayQueue<ElementType>& other) noexcept = default;
	DynamicSizeArrayQueue(DynamicSizeArrayQueue<ElementType>&& other) noexcept = default;
	~DynamicSizeArrayQueue() noexcept = default;

public:
	DynamicSizeArrayQueue<ElementType>& operator=(const DynamicSizeArrayQueue<ElementType>& other) noexcept = default;
	DynamicSizeArrayQueue<ElementType>& operator=(DynamicSizeArrayQueue<ElementType>&& other) noexcept = default;
	const bool operator==(const DynamicSizeArrayQueue<ElementType>& other) const noexcept;

public:
	void enqueue(const ElementType& element);
	void enqueue(ElementType&& element);
	std::optional<ElementType> dequeue();
	std::vector<ElementType> dequeueAll();
	const ElementType* const getFront() const noexcept;
	ElementType* const getFront() noexcept;
	const ElementType* const getBack() const noexcept;
	ElementType* const getBack() noexcept;
	const bool isEmpty() const noexcept;
	const std::size_t getSize() const noexcept;

private:
	std::vector<ElementType> vector {};
	std::size_t frontIndex {0};
	std::size_t backIndex {0};
};

template<typename ElementType>
const bool DynamicSizeArrayQueue<ElementType>::operator==(const DynamicSizeArrayQueue<ElementType>& other) const noexcept {
	if (this == &other) {
		return true;
	}
	
	if (getSize() != other.getSize()) {
		return false;
	}
	
	for (std::size_t index {0}; index < getSize(); ++index) {
		if (vector[frontIndex + index] != other.vector[other.frontIndex + index]) {
			return false;
		}
	}
	
	return true;
}

template<typename ElementType>
void DynamicSizeArrayQueue<ElementType>::enqueue(const ElementType& element) {
	vector.emplace_back(element);
	++backIndex;
}

template<typename ElementType>
void DynamicSizeArrayQueue<ElementType>::enqueue(ElementType&& element) {
	vector.emplace_back(std::move(element));
	++backIndex;
}

template<typename ElementType>
std::optional<ElementType> DynamicSizeArrayQueue<ElementType>::dequeue() {
	if (isEmpty()) {
		return std::nullopt;
	}
	
	const ElementType element {std::move(vector[frontIndex])};
	++frontIndex;
	
	static constexpr std::size_t SHRINK_THRESHOLD_MULTIPLIER {2};
	if (const std::size_t shrinkThreshold {frontIndex * SHRINK_THRESHOLD_MULTIPLIER}; shrinkThreshold >= getSize()) {
		vector.erase(vector.begin(), vector.begin() + frontIndex);
		backIndex -= frontIndex;
		frontIndex = 0;
	}
	
	return element;
}

template<typename ElementType>
std::vector<ElementType> DynamicSizeArrayQueue<ElementType>::dequeueAll() {
	std::vector<ElementType> elements {};
	
	while (frontIndex != backIndex) {
		elements.emplace_back(std::move(vector[frontIndex]));
		++frontIndex;
	}
	
	vector.clear();
	frontIndex = 0;
	backIndex = 0;
	
	return elements;
}

template<typename ElementType>
const ElementType* const DynamicSizeArrayQueue<ElementType>::getFront() const noexcept {
	if (isEmpty()) {
		return nullptr;
	}
	
	return &vector[frontIndex];
}

template<typename ElementType>
ElementType* const DynamicSizeArrayQueue<ElementType>::getFront() noexcept {
	if (isEmpty()) {
		return nullptr;
	}
	
	return &vector[frontIndex];
}

template<typename ElementType>
const ElementType* const DynamicSizeArrayQueue<ElementType>::getBack() const noexcept {
	if (isEmpty()) {
		return nullptr;
	}
	
	return &vector[backIndex - 1];
}

template<typename ElementType>
ElementType* const DynamicSizeArrayQueue<ElementType>::getBack() noexcept {
	if (isEmpty()) {
		return nullptr;
	}
	
	return &vector[backIndex - 1];
}

template<typename ElementType>
const bool DynamicSizeArrayQueue<ElementType>::isEmpty() const noexcept {
	return frontIndex == backIndex;
}

template<typename ElementType>
const std::size_t DynamicSizeArrayQueue<ElementType>::getSize() const noexcept {
	return backIndex - frontIndex;
}
}