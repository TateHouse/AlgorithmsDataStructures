#pragma once

#include <optional>
#include <vector>

namespace Core::DataStructures::Queues {
/**
 * @brief A dynamically sized queue implemented using a std::vector.
 * @class DynamicSizeArrayQueue
 * @tparam ElementType: The type of the elements stored in the dynamically sized array queue.
 */
template<typename ElementType>
class DynamicSizeArrayQueue final {
public:
	/**
	 * @brief Instantiates a new dynamically sized array queue with no elements.
	 */
	DynamicSizeArrayQueue() noexcept = default;
	
	/**
	 * @brief Instantiates a new dynamically sized array queue by copying the given dynamically sized array queue.
	 * @param other: The dynamically sized array queue to copy.
	 */
	DynamicSizeArrayQueue(const DynamicSizeArrayQueue<ElementType>& other) noexcept = default;
	
	/**
	 * @brief Instantiates a new dynamically sized array queue by moving the given dynamically sized array queue.
	 * @param other: The dynamically sized array queue to move.
	 */
	DynamicSizeArrayQueue(DynamicSizeArrayQueue<ElementType>&& other) noexcept = default;
	
	/**
	 * @brief Destroys the dynamically sized array queue.
	 */
	~DynamicSizeArrayQueue() noexcept = default;

public:
	/**
	 * @brief Assigns the given dynamically sized array queue to this dynamically sized array queue using copy semantics.
	 * @param other: The dynamically sized array queue to copy.
	 * @return A reference to this dynamically sized array queue.
	 */
	DynamicSizeArrayQueue<ElementType>& operator=(const DynamicSizeArrayQueue<ElementType>& other) noexcept = default;
	
	/**
	 * @brief Assigns the given dynamically sized array queue to this dynamically sized array queue using move semantics.
	 * @param other: The dynamically sized array queue to move.
	 * @return A reference to this dynamically sized array queue.
	 */
	DynamicSizeArrayQueue<ElementType>& operator=(DynamicSizeArrayQueue<ElementType>&& other) noexcept = default;
	
	/**
	 * @brief Checks if the given dynamically sized array queue is equal to this dynamically sized array queue.
	 * @details Two dynamically sized array queues are equal if they have the same size and the same elements in the
	 * same order.
	 * @param other: The dynamically sized array queue to compare to.
	 * @return True if the dynamically sized array queues are equal, false otherwise.
	 */
	bool operator==(const DynamicSizeArrayQueue<ElementType>& other) const noexcept;

public:
	/**
	 * @brief Inserts the given element to the back of the dynamically sized array queue using copy semantics.
	 * @param element: The element to insert.
	 * @throws std::bad_alloc: Thrown if memory allocation fails.
	 */
	void enqueue(const ElementType& element);
	
	/**
	 * @brief Inserts the given element to the back of the dynamically sized array queue using move semantics.
	 * @param element: The element to add.
	 * @throws std::bad_alloc: Thrown if memory allocation fails.
	 */
	void enqueue(ElementType&& element);
	
	/**
	 * @brief Removes the element at the front of the dynamically sized array queue.
	 * @details The underlying std::vector is shrunk if the number of elements in the dynamically sized array queue
	 * falls below a certain threshold.
	 * @return The element at the front of the dynamically sized array queue, or std::nullopt if the dynamically sized
	 * array queue is empty.
	 */
	std::optional<ElementType> dequeue() noexcept;
	
	/**
	 * @brief Removes all elements from the dynamically sized array queue resulting in an empty dynamically sized array.
	 * @return A std::vector containing the elements stored in the dynamically sized array queue.
	 */
	std::vector<ElementType> dequeueAll();
	
	/**
	 * @brief Gets a const pointer to the const element at the front of the dynamically sized array queue.
	 * @return A const pointer to the const element at the front of the dynamically sized array queue, or nullptr if
	 * the dynamically sized array queue is empty.
	 */
	const ElementType* const getFront() const noexcept;
	
	/**
	 * @brief Gets a const pointer to the element at the front of the dynamically sized array queue.
	 * @return A const pointer to the element at the front of the dynamically sized array queue, or nullptr if the
	 * dynamically sized array queue is empty.
	 */
	ElementType* const getFront() noexcept;
	
	/**
	 * @brief Gets a const pointer to the const element at the back of the dynamically sized array queue.
	 * @return A const pointer to the const element at the back of the dynamically sized array queue, or nullptr if
	 * the dynamically sized array queue is empty.
	 */
	const ElementType* const getBack() const noexcept;
	
	/**
	 * @brief Gets a const pointer to the element at the back of the dynamically sized array queue.
	 * @return A const pointer to the element at the back of the dynamically sized array queue, or nullptr if the
	 * dynamically sized array queue is empty.
	 */
	ElementType* const getBack() noexcept;
	
	/**
	 * @brief Checks if the dynamically sized array queue is empty.
	 * @return True if the dynamically sized array queue is empty, false otherwise.
	 */
	bool isEmpty() const noexcept;
	
	/**
	 * @brief Gets the number of elements in the dynamically sized array queue.
	 * @return The number of elements in the dynamically sized array queue.
	 */
	std::size_t getSize() const noexcept;

private:
	std::vector<ElementType> vector {};
	std::size_t frontIndex {0};
	std::size_t backIndex {0};
};

template<typename ElementType>
bool DynamicSizeArrayQueue<ElementType>::operator==(const DynamicSizeArrayQueue<ElementType>& other) const noexcept {
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
std::optional<ElementType> DynamicSizeArrayQueue<ElementType>::dequeue() noexcept {
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
bool DynamicSizeArrayQueue<ElementType>::isEmpty() const noexcept {
	return frontIndex == backIndex;
}

template<typename ElementType>
std::size_t DynamicSizeArrayQueue<ElementType>::getSize() const noexcept {
	return backIndex - frontIndex;
}
}