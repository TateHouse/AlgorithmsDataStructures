#pragma once

#include <functional>

namespace Core::DataStructures::Hashing {
template<typename KeyType>
concept Hashable = requires(KeyType key) {
	{ std::hash<KeyType> {}(key) } -> std::convertible_to<std::size_t>;
};
}