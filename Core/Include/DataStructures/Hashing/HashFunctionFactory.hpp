#pragma once

#include <memory>

#include "HashFunction.hpp"

namespace Core::DataStructures::Hashing {
/**
 * @brief An interface for instantiating hash functions.
 * @class HashFunctionFactory
 * @tparam KeyType: The type of the key to hash.
 */
template<typename KeyType>
class HashFunctionFactory {
public:
	/**
	 * @brief Destroys the hash function factory.
	 */
	virtual ~HashFunctionFactory() noexcept = default;

public:
	/**
	 * @brief Instantiates a hash function.
	 * @param tableSize: The size of the hash table.
	 * @return A hash function.
	 */
	[[nodiscard]] virtual std::unique_ptr<HashFunction<KeyType>> create(const std::size_t tableSize) const noexcept = 0;
};
}