#pragma once

#include <limits>
#include <stdexcept>

#include "HashConcepts.hpp"
#include "HashFunction.hpp"

namespace Core::DataStructures::Hashing {
/**
 * @brief A hash function that uses the multiplication method.
 * @class MultiplicationMethodHashFunction
 * @tparam KeyType: The type of the key to hash.
 */
template<Hashable KeyType>
class MultiplicationMethodHashFunction final : public HashFunction<KeyType> {
public:
	/**
	 * @brief Instantiates a new multiplication method hash function.
	 * @param tableSize: The size of the hash table.
	 * @param hashMultiplier: The hash multiplier in the range (0, 1). The default value is 0.61803398875f.
	 * @throws std::invalid_argument: Thrown if the table size is 0 or if the hash multiplier is not in range (0, 1).
	 */
	explicit MultiplicationMethodHashFunction(const std::size_t tableSize,
	                                          const double hashMultiplier = 0.61803398875f);
	
	/**
	 * @brief Instantiates a new multiplication method hash function by copying the given multiplication method hash
	 * function.
	 * @param other: The multiplication method hash function to copy.
	 */
	MultiplicationMethodHashFunction(const MultiplicationMethodHashFunction& other) noexcept = default;
	
	/**
	 * @brief Instantiates a new multiplication method hash function by moving the given multiplication method hash
	 * function.
	 * @param other: The multiplication method hash function to move.
	 */
	MultiplicationMethodHashFunction(MultiplicationMethodHashFunction&& other) noexcept = default;
	
	/**
	 * @brief Destroys the multiplication method hash function.
	 */
	~MultiplicationMethodHashFunction() noexcept = default;

public:
	/**
	 * @brief Assigns the given multiplication method hash function to this multiplication method hash function using
	 * copy semantics.
	 * @param other: The multiplication method hash function to copy.
	 * @return A reference to this multiplication method hash function.
	 */
	MultiplicationMethodHashFunction& operator=(const MultiplicationMethodHashFunction& other) noexcept = default;
	
	/**
	 * @brief Assigns the given multiplication method hash function to this multiplication method hash function using
	 * move semantics.
	 * @param other: The multiplication method hash function to move.
	 * @return A reference to this multiplication method hash function.
	 */
	MultiplicationMethodHashFunction& operator=(MultiplicationMethodHashFunction&& other) noexcept = default;
	
	/**
	 * @brief Hashes the given key.
	 * @param key: The key to hash.
	 * @return The hash value.
	 */
	virtual std::size_t operator()(const KeyType& key) const noexcept override;

private:
	std::size_t tableSize;
	double hashMultiplier;
};

template<Hashable KeyType>
MultiplicationMethodHashFunction<KeyType>::MultiplicationMethodHashFunction(const std::size_t tableSize,
                                                                            const double hashMultiplier)
		: tableSize {tableSize}, hashMultiplier {hashMultiplier} {
	if (tableSize == 0) {
		throw std::invalid_argument {"The table size must be greater than 0."};
	}
	
	if (hashMultiplier <= 0.0f || hashMultiplier >= 1.0f) {
		throw std::invalid_argument {"The hash multiplier must be in range (0, 1)"};
	}
}

template<Hashable KeyType>
std::size_t MultiplicationMethodHashFunction<KeyType>::operator()(const KeyType& key) const noexcept {
	std::hash<KeyType> hashFunction {};
	const auto hashValue {hashFunction(key)};
	const auto scaledHashValue {hashValue % std::numeric_limits<int32_t>::max()};
	const auto product {scaledHashValue * hashMultiplier};
	const auto fractionalPart {product - std::floor(product)};
	
	return static_cast<std::size_t>(fractionalPart * tableSize);
}
}