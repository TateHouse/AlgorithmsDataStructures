#pragma once

#include <functional>

namespace Core::DataStructures::Hashing {
/**
 * @brief A concept that requires a type to be hashable.
 * @tparam KeyType: The type to check.
 */
template<typename KeyType>
concept Hashable = requires(KeyType key) {
	{ std::hash<KeyType> {}(key) } -> std::convertible_to<std::size_t>;
};
}