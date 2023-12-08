#pragma once

#include <cstddef>

namespace Core::DataStructures::Hashing {
/**
 * @brief An interface for hash functions.
 * @class HashFunction
 * @tparam KeyType: The type of the key to hash.
 */
template<typename KeyType>
class HashFunction {
public:
	/**
	 * @brief Destroys the hash function.
	 */
	virtual ~HashFunction() = default;

public:
	/**
	 * @brief Hashes the given key.
	 * @param key: The key to hash.
	 * @return The hash of the key.
	 */
	virtual std::size_t operator()(const KeyType& key) const = 0;
};
}