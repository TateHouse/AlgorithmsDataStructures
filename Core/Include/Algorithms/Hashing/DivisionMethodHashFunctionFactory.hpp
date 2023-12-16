#pragma once

#include "DivisionMethodHashFunction.hpp"
#include "HashFunctionFactory.hpp"

namespace Core::DataStructures::Hashing {
/**
 * @brief A factory for instantiating division method hash functions.
 * @class DivisionMethodHashFunctionFactory
 * @tparam KeyType: The type of the key to hash.
 */
template<typename KeyType>
class DivisionMethodHashFunctionFactory final : public HashFunctionFactory<KeyType> {
public:
	/**
	 * @brief Instantiates a new division method hash function factory.
	 */
	explicit DivisionMethodHashFunctionFactory() noexcept = default;
	
	/**
	 * @brief Instantiates a new division method hash function factory by copying the given division method hash function
	 * factory.
	 * @param other: The division method hash function factory to copy.
	 */
	DivisionMethodHashFunctionFactory(const DivisionMethodHashFunctionFactory& other) = default;
	
	/**
	 * @brief Instantiates a new division method hash function factory by moving the given division method hash function
	 * factory.
	 * @param other: The division method hash function factory to move.
	 */
	DivisionMethodHashFunctionFactory(DivisionMethodHashFunctionFactory&& other) noexcept = default;
	
	/**
	 * @brief Destroys the division method hash function factory.
	 */
	~DivisionMethodHashFunctionFactory() noexcept override = default;

public:
	/**
	 * @brief Assigns the given division method hash function factory to this division method hash function factory using
	 * copy semantics.
	 * @param other: The division method hash function factory to copy.
	 * @return A reference to this division method hash function factory.
	 */
	DivisionMethodHashFunctionFactory& operator=(const DivisionMethodHashFunctionFactory& other) = delete;
	
	/**
	 * @brief Assigns the given division method hash function factory to this division method hash function factory using
	 * move semantics.
	 * @param other: The division method hash function factory to move.
	 * @return A reference to this division method hash function factory.
	 */
	DivisionMethodHashFunctionFactory& operator=(DivisionMethodHashFunctionFactory&& other) noexcept = default;

public:
	/**
	 * @brief Instantiates a division method hash function.
	 * @param tableSize: The size of the hash table.
	 * @return A division method hash function.
	 */
	[[nodiscard]] std::unique_ptr<HashFunction<KeyType>> create(const std::size_t tableSize) const noexcept override;
};

template<typename KeyType>
std::unique_ptr<HashFunction<KeyType>> DivisionMethodHashFunctionFactory<KeyType>::create(const std::size_t tableSize) const noexcept {
	return std::make_unique<DivisionMethodHashFunction<KeyType>>(tableSize);
}
}