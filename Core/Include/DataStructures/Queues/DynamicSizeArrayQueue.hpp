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
}