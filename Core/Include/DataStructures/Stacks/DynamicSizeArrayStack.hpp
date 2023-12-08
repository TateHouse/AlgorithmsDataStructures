#pragma once

#include <optional>
#include <vector>

namespace Core::DataStructures::Stacks {
/**
 * @brief A dynamically sized stack implemented using a std::vector.
 * @class DynamicSizeArrayStack
 * @tparam ElementType: The type of the elements stored in the dynamically sized array stack.
 */
template<typename ElementType>
class DynamicSizeArrayStack final {
public:
	/**
	 * @brief Instantiates a new dynamically sized array stack with no elements.
	 */
	DynamicSizeArrayStack() noexcept = default;
	
	/**
	 * @brief Instantiates a new dynamically sized array stack by copying the given dynamically sized array stack.
	 * @param other: The dynamically sized array stack to copy.
	 */
	DynamicSizeArrayStack(const DynamicSizeArrayStack<ElementType>& other) noexcept = default;
	
	/**
	 * @brief Instantiates a new dynamically sized array stack by moving the given dynamically sized array stack.
	 * @param other: The dynamically sized array stack to move.
	 */
	DynamicSizeArrayStack(DynamicSizeArrayStack<ElementType>&& other) noexcept = default;
	
	/**
	 * @brief Destroys the dynamically sized array stack.
	 */
	~DynamicSizeArrayStack() noexcept = default;

public:
	/**
	 * @brief Assigns the given dynamically sized array stack to this dynamically sized array stack using copy semantics.
	 * @param other: The dynamically sized array stack to copy.
	 * @return A reference to this dynamically sized array stack.
	 */
	DynamicSizeArrayStack<ElementType>& operator=(const DynamicSizeArrayStack<ElementType>& other) noexcept = default;
	
	/**
	 * @brief Assigns the given dynamically sized array stack to this dynamically sized array stack using move semantics.
	 * @param other: The dynamically sized array stack to move.
	 * @return A reference to this dynamically sized array stack.
	 */
	DynamicSizeArrayStack<ElementType>& operator=(DynamicSizeArrayStack<ElementType>&& other) noexcept = default;
	
	/**
	 * @brief Checks if the given dynamically sized array stack is equal to this dynamically sized array stack.
	 * @details Two dynamically sized array stacks are equal if they have the same size and the same elements in the
	 * same order.
	 * @param other: The dynamically sized array stack to compare to.
	 * @return True if the dynamically sized array stacks are equal, false otherwise.
	 */
	const bool operator==(const DynamicSizeArrayStack<ElementType>& other) const noexcept;

public:
	/**
	 * @brief Inserts the given element at the top of the dynamically sized array stack using copy semantics.
	 * @param element: The element to insert at the top of the dynamically sized array stack.
	 */
	void push(const ElementType& element);
	
	/**
	 * @brief Inserts the given element at the top of the dynamically sized array stack using move semantics.
	 * @param element: The element to insert at the top of the dynamically sized array stack.
	 */
	void push(ElementType&& element);
	
	/**
	 * @brief Removes the element at the top of the dynamically sized array stack.
	 * @return The element at the top of the dynamically sized array stack if the dynamically sized array stack is not
	 * empty, std::nullopt otherwise.
	 */
	std::optional<ElementType> pop();
	
	/**
	 * @brief Removes all elements from the dynamically sized array stack resulting in an empty dynamically sized array
	 * stack.
	 * @return A vector containing the elements that were in the dynamically sized array stack.
	 */
	std::vector<ElementType> popAll();
	
	/**
	 * @brief Gets a const pointer to the const element at the top of the dynamically sized array stack.
	 * @return A const pointer to the const element at the top of the dynamically sized array stack if the dynamically
	 * sized array stack is not empty, nullptr otherwise.
	 */
	const ElementType* const getTop() const noexcept;
	
	/**
	 * @brief Gets a const pointer to the element at the top of the dynamically sized array stack.
	 * @return A const pointer to the element at the top of the dynamically sized array stack if the dynamically sized
	 * array stack is not empty, nullptr otherwise.
	 */
	ElementType* const getTop() noexcept;
	
	/**
	 * @brief Checks if the dynamically sized array stack is empty.
	 * @return True if the dynamically sized array stack is empty, false otherwise.
	 */
	const bool isEmpty() const noexcept;
	
	/**
	 * @brief Gets the number of elements in the dynamically sized array stack.
	 * @return The number of elements in the dynamically sized array stack.
	 */
	const std::size_t getSize() const noexcept;

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

template<typename ElementType>
void DynamicSizeArrayStack<ElementType>::push(const ElementType& element) {
	vector.emplace_back(element);
}

template<typename ElementType>
void DynamicSizeArrayStack<ElementType>::push(ElementType&& element) {
	vector.emplace_back(std::move(element));
}

template<typename ElementType>
std::optional<ElementType> DynamicSizeArrayStack<ElementType>::pop() {
	if (vector.empty()) {
		return std::nullopt;
	}
	
	const auto element {std::move(vector.back())};
	vector.pop_back();
	return element;
}

template<typename ElementType>
std::vector<ElementType> DynamicSizeArrayStack<ElementType>::popAll() {
	std::vector<ElementType> elements {};
	elements.swap(vector);
	std::ranges::reverse(elements);
	return elements;
}

template<typename ElementType>
const ElementType* const DynamicSizeArrayStack<ElementType>::getTop() const noexcept {
	if (vector.empty()) {
		return nullptr;
	}
	
	return &vector.back();
}

template<typename ElementType>
ElementType* const DynamicSizeArrayStack<ElementType>::getTop() noexcept {
	if (vector.empty()) {
		return nullptr;
	}
	
	return &vector.back();
}

template<typename ElementType>
const bool DynamicSizeArrayStack<ElementType>::isEmpty() const noexcept {
	return vector.empty();
}

template<typename ElementType>
const std::size_t DynamicSizeArrayStack<ElementType>::getSize() const noexcept {
	return vector.size();
}
}