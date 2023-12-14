#pragma once

#include "HashConcepts.hpp"
#include "HashFunction.hpp"

namespace Core::DataStructures::Hashing {
/**
 * @brief A hash function that uses the division method to hash keys.
 * @class DivisionMethodHashFunction
 * @tparam KeyType: The type of the key to hash.
 */
template<Hashable KeyType>
class DivisionMethodHashFunction final : public HashFunction<KeyType> {
public:
	/**
	 * @brief Instantiates a new division method hash function.
	 * @param tableSize: The size of the hash table.
	 * @throws std::invalid_argument: Thrown if the table size is 0.
	 */
	explicit DivisionMethodHashFunction(const std::size_t tableSize);
	
	/**
	 * @brief Instantiates a new division method hash function by copying the given division method hash function.
	 * @param other: The division method hash function to copy.
	 */
	DivisionMethodHashFunction(const DivisionMethodHashFunction& other) noexcept = default;
	
	/**
	 * @brief Instantiates a new division method hash function by moving the given division method hash function.
	 * @param other: The division method hash function to move.
	 */
	DivisionMethodHashFunction(DivisionMethodHashFunction&& other) noexcept = default;
	
	/**
	 * @brief Destroys the division method hash function.
	 */
	~DivisionMethodHashFunction() noexcept = default;

public:
	/**
	 * @brief Assigns the given division method hash function to this division method hash function using copy semantics.
	 * @param other: The division method hash function to copy.
	 * @return A reference to this division method hash function.
	 */
	DivisionMethodHashFunction& operator=(const DivisionMethodHashFunction& other) noexcept = default;
	
	/**
	 * @brief Assigns the given division method hash function to this division method hash function using move semantics.
	 * @param other: The division method hash function to move.
	 * @return A reference to this division method hash function.
	 */
	DivisionMethodHashFunction& operator=(DivisionMethodHashFunction&& other) noexcept = default;
	
	/**
	 * @brief Hashes the given key.
	 * @param key The key to hash.
	 * @return The hash value.
	 */
	virtual std::size_t operator()(const KeyType& key) const noexcept override;

private:
	std::size_t tableSize;
};

template<Hashable KeyType>
DivisionMethodHashFunction<KeyType>::DivisionMethodHashFunction(const std::size_t tableSize)
		: tableSize {tableSize} {
	if (tableSize == 0) {
		throw std::invalid_argument {"The table size must be greater than 0."};
	}
}

template<Hashable KeyType>
std::size_t DivisionMethodHashFunction<KeyType>::operator()(const KeyType& key) const noexcept {
	std::hash<KeyType> hashFunction {};
	
	return hashFunction(key) % tableSize;
}
}