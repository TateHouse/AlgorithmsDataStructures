#pragma once

#include <array>
#include <optional>
#include <vector>

namespace Core::DataStructures::Queues {
/**
 * @brief A fixed size queue implemented using a circular array.
 * @class FixedSizeCircularArrayQueue
 * @tparam ElementType: The type of the elements stored in the fixed size circular array queue.
 * @tparam Size: The maximum number of elements that can be stored in the fixed size circular array queue.
 */
template<typename ElementType, std::size_t Size>
class FixedSizeCircularArrayQueue final {
public:
	/**
	 * @brief Instantiates a new fixed size circular array queue with no elements.
	 */
	FixedSizeCircularArrayQueue() noexcept = default;
	
	/**
	 * @brief Instantiates a new fixed size circular array queue by copying the given fixed size circular array queue.
	 * @param other: The fixed size circular array queue to copy.
	 */
	FixedSizeCircularArrayQueue(const FixedSizeCircularArrayQueue<ElementType, Size>& other) noexcept = default;
	
	/**
	 * @brief Instantiates a new fixed size circular array queue by moving the given fixed size circular array queue.
	 * @param other: The fixed size circular array queue to move.
	 */
	FixedSizeCircularArrayQueue(FixedSizeCircularArrayQueue<ElementType, Size>&& other) noexcept = default;
	
	/**
	 * @brief Destroys the fixed size circular array queue.
	 */
	~FixedSizeCircularArrayQueue() noexcept = default;

public:
	/**
	 * @brief Assigns the given fixed size circular array queue to this fixed size circular array queue using copy
	 * semantics.
	 * @param other: The fixed size circular array queue to copy.
	 * @return A reference to this fixed size circular array queue.
	 */
	FixedSizeCircularArrayQueue<ElementType, Size>& operator=(const FixedSizeCircularArrayQueue<ElementType, Size>& other) noexcept = default;
	
	/**
	 * @brief Assigns the given fixed size circular array queue to this fixed size circular array queue using move
	 * semantics.
	 * @param other: The fixed size circular array queue to move.
	 * @return A reference to this fixed size circular array queue.
	 */
	FixedSizeCircularArrayQueue<ElementType, Size>& operator=(FixedSizeCircularArrayQueue<ElementType, Size>&& other) noexcept = default;
	
	/**
	 * @brief Checks if the given fixed size circular array queue is equal to this fixed size circular array queue.
	 * @details Two fixed size circular array queues are equal if they have the same size and the same elements in the
	 * same order.
	 * @param other: The fixed size circular array queue to compare to.
	 * @return True if the fixed size circular array queues are equal, false otherwise.
	 */
	const bool operator==(const FixedSizeCircularArrayQueue<ElementType, Size>& other) const noexcept;

public:
	/**
	 * @brief Inserts the given element to the back of the fixed size circular array queue using copy semantics.
	 * @param element: The element to insert.
	 * @return: True if the element was inserted, false if the fixed size circular array queue is full and the element
	 * was not inserted.
	 */
	const bool enqueue(const ElementType& element) noexcept;
	
	/**
	 * @brief Inserts the given element to the back of the fixed size circular array queue using move semantics.
	 * @param element: The element to add.
	 * @return True if the element was inserted, false if the fixed size circular array queue is full and the element
	 * was not inserted.
	 */
	const bool enqueue(ElementType&& element) noexcept;
	
	/**
	 * @brief Removes the element at the front of the fixed size circular array queue.
	 * @return The element at the front of the fixed size circular array queue if the fixed size circular array queue
	 * is not empty, std::nullopt otherwise.
	 */
	std::optional<ElementType> dequeue() noexcept;
	
	/**
	 * @brief Removes all elements from the fixed size circular array queue.
	 * @return A vector containing all the elements that were removed from the fixed size circular array queue.
	 */
	std::vector<ElementType> dequeueAll();
	
	/**
	 * @brief Gets a const pointer to the const element at the front of the fixed size circular array queue.
	 * @return A const pointer to the const element at the front of the fixed size circular array queue, or nullptr if
	 * the fixed size circular array queue is empty.
	 */
	const ElementType* const getFront() const noexcept;
	
	/**
	 * @brief Gets a const pointer to the element at the front of the fixed size circular array queue.
	 * @return A const pointer to the element at the front of the fixed size circular array queue, or nullptr if the fixed
	 * size circular array queue is empty.
	 */
	ElementType* const getFront() noexcept;
	
	/**
	 * @brief Gets a const pointer to the const element at the back of the fixed size circular array queue.
	 * @return A const pointer to the const element at the back of the fixed size circular array queue, or nullptr if
	 * the fixed size circular array queue is empty.
	 */
	const ElementType* const getBack() const noexcept;
	
	/**
	 * @brief Gets a const pointer to the element at the back of the fixed size circular array queue.
	 * @return A const pointer to the element at the back of the fixed size circular array queue, or nullptr if the fixed
	 * size circular array queue is empty.
	 */
	ElementType* const getBack() noexcept;
	
	/**
	 * @brief Checks if the fixed size circular array queue is empty.
	 * @return True if the fixed size circular array queue is empty, false otherwise.
	 */
	const bool isEmpty() const noexcept;
	
	/**
	 * @brief Checks if the fixed size circular array queue is full.
	 * @return True if the fixed size circular array queue is full, false otherwise.
	 */
	const bool isFull() const noexcept;
	
	/**
	 * @brief Gets the number of elements in the fixed size circular array queue.
	 * @return The number of elements in the fixed size circular array queue.
	 */
	const std::size_t getSize() const noexcept;

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
	if (isFull()) {
		return false;
	}
	
	backIndex = (backIndex + 1) % Size;
	array[backIndex] = element;
	++elementCount;
	
	return true;
}

template<typename ElementType, std::size_t Size>
const bool FixedSizeCircularArrayQueue<ElementType, Size>::enqueue(ElementType&& element) noexcept {
	if (isFull()) {
		return false;
	}
	
	backIndex = (backIndex + 1) % Size;
	array[backIndex] = std::move(element);
	++elementCount;
	
	return true;
}

template<typename ElementType, std::size_t Size>
std::optional<ElementType> FixedSizeCircularArrayQueue<ElementType, Size>::dequeue() noexcept {
	if (isEmpty()) {
		return std::nullopt;
	}
	
	const auto element {std::move(array[frontIndex])};
	frontIndex = (frontIndex + 1) % Size;
	--elementCount;
	
	return element;
}

template<typename ElementType, std::size_t Size>
std::vector<ElementType> FixedSizeCircularArrayQueue<ElementType, Size>::dequeueAll() {
	std::vector<ElementType> elements {};
	
	while (!isEmpty()) {
		elements.emplace_back(array[frontIndex]);
		frontIndex = (frontIndex + 1) % Size;
		--elementCount;
	}
	
	return elements;
}

template<typename ElementType, std::size_t Size>
const ElementType* const FixedSizeCircularArrayQueue<ElementType, Size>::getFront() const noexcept {
	if (isEmpty()) {
		return nullptr;
	}
	
	return &array[frontIndex];
}

template<typename ElementType, std::size_t Size>
ElementType* const FixedSizeCircularArrayQueue<ElementType, Size>::getFront() noexcept {
	if (isEmpty()) {
		return nullptr;
	}
	
	return &array[frontIndex];
}

template<typename ElementType, std::size_t Size>
const ElementType* const FixedSizeCircularArrayQueue<ElementType, Size>::getBack() const noexcept {
	if (isEmpty()) {
		return nullptr;
	}
	
	return &array[backIndex];
}

template<typename ElementType, std::size_t Size>
ElementType* const FixedSizeCircularArrayQueue<ElementType, Size>::getBack() noexcept {
	if (isEmpty()) {
		return nullptr;
	}
	
	return &array[backIndex];
}

template<typename ElementType, std::size_t Size>
const bool FixedSizeCircularArrayQueue<ElementType, Size>::isEmpty() const noexcept {
	return elementCount == 0;
}

template<typename ElementType, std::size_t Size>
const bool FixedSizeCircularArrayQueue<ElementType, Size>::isFull() const noexcept {
	return elementCount == Size;
}

template<typename ElementType, std::size_t Size>
const std::size_t FixedSizeCircularArrayQueue<ElementType, Size>::getSize() const noexcept {
	return elementCount;
}
}