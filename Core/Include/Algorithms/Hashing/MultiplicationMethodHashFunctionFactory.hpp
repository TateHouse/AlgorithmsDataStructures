#pragma once

#include "MultiplicationMethodHashFunction.hpp"
#include "HashFunctionFactory.hpp"

namespace Core::DataStructures::Hashing {
/**
 * @brief A factory for instantiating multiplication method hash functions.
 * @class MultiplicationMethodHashFunctionFactory
 * @tparam KeyType: The type of the key to hash.
 */
template<typename KeyType>
class MultiplicationMethodHashFunctionFactory final : public HashFunctionFactory<KeyType> {
public:
	/**
	 * @brief Instantiates a new multiplication method hash function factory.
	 */
	explicit MultiplicationMethodHashFunctionFactory() noexcept = default;
	
	/**
	 * @brief Instantiates a new multiplication method hash function factory by copying the given multiplication method
	 * hash function factory.
	 * @param other: The multiplication method hash function factory to copy.
	 */
	MultiplicationMethodHashFunctionFactory(const MultiplicationMethodHashFunctionFactory& other) = default;
	
	/**
	 * @brief Instantiates a new multiplication method hash function factory by moving the given multiplication method
	 * hash function factory.
	 * @param other: The multiplication method hash function factory to move.
	 */
	MultiplicationMethodHashFunctionFactory(MultiplicationMethodHashFunctionFactory&& other) noexcept = default;
	
	/**
	 * @brief Destroys the multiplication method hash function factory.
	 */
	~MultiplicationMethodHashFunctionFactory() noexcept override = default;

public:
	/**
	 * @brief Assigns the given multiplication method hash function factory to this multiplication method hash function
	 * factory using copy semantics.
	 * @param other: The multiplication method hash function factory to copy.
	 * @return A reference to this multiplication method hash function factory.
	 */
	MultiplicationMethodHashFunctionFactory& operator=(const MultiplicationMethodHashFunctionFactory& other) = delete;
	
	/**
	 * @brief Assigns the given multiplication method hash function factory to this multiplication method hash function
	 * factory using move semantics.
	 * @param other: The multiplication method hash function factory to move.
	 * @return A reference to this multiplication method hash function factory.
	 */
	MultiplicationMethodHashFunctionFactory& operator=(MultiplicationMethodHashFunctionFactory&& other) noexcept = default;

public:
	/**
	 * @brief Instantiates a multiplication method hash function.
	 * @param tableSize: The size of the hash table.
	 * @return A multiplication method hash function.
	 */
	[[nodiscard]] std::unique_ptr<HashFunction<KeyType>> create(const std::size_t tableSize) const noexcept override;
};

template<typename KeyType>
std::unique_ptr<HashFunction<KeyType>> MultiplicationMethodHashFunctionFactory<KeyType>::create(const std::size_t tableSize) const noexcept {
	return std::make_unique<MultiplicationMethodHashFunction<KeyType>>(tableSize);
}
}