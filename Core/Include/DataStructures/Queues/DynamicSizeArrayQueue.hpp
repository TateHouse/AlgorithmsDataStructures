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
	void enqueue(const ElementType& element) noexcept;
	void enqueue(ElementType&& element) noexcept;
	std::optional<ElementType> dequeue() noexcept;
	std::vector<ElementType> dequeueAll() noexcept;
	const ElementType* const getFront() const noexcept;
	const ElementType* const getBack() const noexcept;
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

template<typename ElementType>
void DynamicSizeArrayQueue<ElementType>::enqueue(const ElementType& element) noexcept {
	vector.emplace_back(element);
	++backIndex;
}

template<typename ElementType>
void DynamicSizeArrayQueue<ElementType>::enqueue(ElementType&& element) noexcept {
	vector.emplace_back(std::move(element));
	++backIndex;
}

template<typename ElementType>
std::optional<ElementType> DynamicSizeArrayQueue<ElementType>::dequeue() noexcept {
	if (isEmpty()) {
		return std::nullopt;
	}
	
	const ElementType element {std::move(vector[frontIndex])};
	++frontIndex;
	
	if (frontIndex * 2 >= getSize()) {
		vector.erase(vector.begin(), vector.begin() + frontIndex);
		backIndex -= frontIndex;
		frontIndex = 0;
	}
	
	return element;
}

template<typename ElementType>
std::vector<ElementType> DynamicSizeArrayQueue<ElementType>::dequeueAll() noexcept {
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
const ElementType* const DynamicSizeArrayQueue<ElementType>::getBack() const noexcept {
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
	return isEmpty() ? 0 : (backIndex - frontIndex + 1);
}
}