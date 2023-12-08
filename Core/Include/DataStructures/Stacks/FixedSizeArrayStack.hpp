#pragma once

#include <array>
#include <optional>
#include <vector>

namespace Core::DataStructures::Stacks {
/**
 * @brief A fixed size stack implemented using a circular array.
 * @class FixedSizeArrayStack
 * @tparam ElementType: The type of the elements stored in the fixed size array stack.
 * @tparam Size: The maximum number of elements that can be stored in the fixed size array stack.
 */
template<typename ElementType, std::size_t Size>
class FixedSizeArrayStack final {
public:
	/**
	 * @brief Instantiates a new fixed size array stack with no elements.
	 */
	FixedSizeArrayStack() noexcept = default;
	
	/**
	 * @brief Instantiates a new fixed size array stack by copying the given fixed size array stack.
	 * @param other: The fixed size array stack to copy.
	 */
	FixedSizeArrayStack(const FixedSizeArrayStack<ElementType, Size>& other) noexcept = default;
	
	/**
	 * @brief Instantiates a new fixed size array stack by moving the given fixed size array stack.
	 * @param other: The fixed size array stack to move.
	 */
	FixedSizeArrayStack(FixedSizeArrayStack<ElementType, Size>&& other) noexcept = default;
	
	/**
	 * @brief Destroys the fixed size array stack.
	 */
	~FixedSizeArrayStack() noexcept = default;

public:
	/**
	 * @brief Assigns the given fixed size array stack to this fixed size array stack using copy semantics.
	 * @param other: The fixed size array stack to copy.
	 * @return A reference to this fixed size array stack.
	 */
	FixedSizeArrayStack<ElementType, Size>& operator=(const FixedSizeArrayStack<ElementType, Size>& other) noexcept = default;
	
	/**
	 * @brief Assigns the given fixed size array stack to this fixed size array stack using move semantics.
	 * @param other: The fixed size array stack to move.
	 * @return A reference to this fixed size array stack.
	 */
	FixedSizeArrayStack<ElementType, Size>& operator=(FixedSizeArrayStack<ElementType, Size>&& other) noexcept = default;
	
	/**
	 * @brief Checks if the given fixed size array stack is equal to this fixed size array stack.
	 * @details Two fixed size array stacks are equal if they have the same size and the same elements in the
	 * same order.
	 * @param other: The fixed size array stack to compare to.
	 * @return True if the fixed size array stacks are equal, false otherwise.
	 */
	const bool operator==(const FixedSizeArrayStack<ElementType, Size>& other) const noexcept;

public:
	/**
	 * @brief Inserts the given element at the top of the fixed size array stack using copy semantics.
	 * @param element: The element to push onto the top of the fixed size array stack.
	 * @return True if the element was inserted at the top of the fixed size array stack, false otherwise.
	 */
	const bool push(const ElementType& element) noexcept;
	
	/**
	 * @brief Inserts the given element at the top of the fixed size array stack using move semantics.
	 * @param element: The element to push onto the top of the fixed size array stack.
	 * @return True if the element was inserted at the top of the fixed size array stack, false otherwise.
	 */
	const bool push(ElementType&& element) noexcept;
	
	/**
	 * @brief Removes the element at the top of the fixed size array stack.
	 * @return The element at the top of the fixed size array stack if the fixed size array stack is not empty, nullopt
	 * otherwise.
	 */
	std::optional<ElementType> pop() noexcept;
	
	/**
	 * @brief Removes all elements from the fixed size array stack resulting in an empty fixed size array stack.
	 * @return A vector containing the elements that were removed from the fixed size array stack.
	 */
	std::vector<ElementType> popAll();
	
	/**
	 * @brief Gets a const pointer to the const element at the top of the fixed size array stack.
	 * @return A const pointer to the const element at the top of the fixed size array stack, or nullptr if the fixed
	 * size array stack is empty.
	 */
	const ElementType* const getTop() const noexcept;
	
	/**
	 * @brief Gets a const pointer to the element at the top of the fixed size array stack.
	 * @return A const pointer to the element at the top of the fixed size array stack, or nullptr if the fixed size array
	 * stack is empty.
	 */
	ElementType* const getTop() noexcept;
	
	/**
	 * @brief Checks if the fixed size array stack is empty.
	 * @return True if the fixed size array stack is empty, false otherwise.
	 */
	const bool isEmpty() const noexcept;
	
	/**
	 * @brief Checks if the fixed size array stack is full.
	 * @return True if the fixed size array stack is full, false otherwise.
	 */
	const bool isFull() const noexcept;
	
	/**
	 * @brief Gets the number of elements in the fixed size array stack.
	 * @return The number of elements in the fixed size array stack.
	 */
	const std::size_t getSize() const noexcept;

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
	if (isFull()) {
		return false;
	}
	
	array[topIndex] = element;
	++topIndex;
	
	return true;
}

template<typename ElementType, std::size_t Size>
const bool FixedSizeArrayStack<ElementType, Size>::push(ElementType&& element) noexcept {
	if (isFull()) {
		return false;
	}
	
	array[topIndex] = std::move(element);
	++topIndex;
	
	return true;
}

template<typename ElementType, std::size_t Size>
std::optional<ElementType> FixedSizeArrayStack<ElementType, Size>::pop() noexcept {
	if (isEmpty()) {
		return std::nullopt;
	}
	
	--topIndex;
	
	return std::move(array[topIndex]);
}

template<typename ElementType, std::size_t Size>
std::vector<ElementType> FixedSizeArrayStack<ElementType, Size>::popAll() {
	std::vector<ElementType> elements {};
	elements.reserve(topIndex);
	
	while (!isEmpty()) {
		elements.emplace_back(array[topIndex - 1]);
		--topIndex;
	}
	
	return elements;
}

template<typename ElementType, std::size_t Size>
const ElementType* const FixedSizeArrayStack<ElementType, Size>::getTop() const noexcept {
	if (topIndex == 0) {
		return nullptr;
	}
	
	return &array[topIndex - 1];
}

template<typename ElementType, std::size_t Size>
ElementType* const FixedSizeArrayStack<ElementType, Size>::getTop() noexcept {
	if (topIndex == 0) {
		return nullptr;
	}
	
	return &array[topIndex - 1];
}

template<typename ElementType, std::size_t Size>
const bool FixedSizeArrayStack<ElementType, Size>::isEmpty() const noexcept {
	return topIndex == 0;
}

template<typename ElementType, std::size_t Size>
const bool FixedSizeArrayStack<ElementType, Size>::isFull() const noexcept {
	return topIndex == Size;
}

template<typename ElementType, std::size_t Size>
const std::size_t FixedSizeArrayStack<ElementType, Size>::getSize() const noexcept {
	return topIndex;
}
}