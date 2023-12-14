#pragma once

#include <iterator>
#include <memory>
#include <optional>
#include <vector>

#include "Algorithms/Hashing/HashFunctionFactory.hpp"
#include "DataStructures/LinkedLists/SinglyLinkedList.hpp"
#include "Iterators/SeparateChainingHashTableConstForwardIterator.hpp"
#include "Iterators/SeparateChainingHashTableForwardIterator.hpp"

namespace Core::DataStructures::Hashing {
/**
 * @brief A hash table that uses separate chaining to resolve collisions.
 * @class SeparateChainingHashTable
 * @tparam KeyType: The type of the key.
 * @tparam ValueType: The type of the value.
 */
template<Hashable KeyType, typename ValueType>
class SeparateChainingHashTable final {
public:
	/**
	 * @brief Instantiates a new separate chaining hash table with no elements.
	 * @param tableSize: The size of the hash table.
	 * @param hashFunctionFactory: The hash function factory for the desired hash function.
	 * @param loadFactor: The load factor of the hash table in the range (0.0f, 1.0f). The default value is 0.75f.
	 */
	SeparateChainingHashTable(const std::size_t tableSize,
	                          std::unique_ptr<HashFunctionFactory<KeyType>> hashFunctionFactory,
	                          const float loadFactor = 0.75f);
	
	/**
	 * @brief Instantiates a new separate chaining hash table by copying the given separate chaining hash table.
	 * @param other: The separate chaining hash table to copy.
	 */
	SeparateChainingHashTable(const SeparateChainingHashTable& other) = delete;
	
	/**
	 * @brief Instantiates a new separate chaining hash table by moving the given separate chaining hash table.
	 * @param other: The separate chaining hash table to move.
	 */
	SeparateChainingHashTable(SeparateChainingHashTable&& other) noexcept = default;
	
	/**
	 * @brief Destroys the separate chaining hash table.
	 */
	~SeparateChainingHashTable() noexcept = default;

public:
	/**
	 * @brief Assigns the given separate chaining hash table to this separate chaining hash table using copy semantics.
	 * @param other: The separate chaining hash table to copy.
	 * @return A reference to this separate chaining hash table.
	 */
	SeparateChainingHashTable& operator=(const SeparateChainingHashTable& other) = delete;
	
	/**
	 * @brief Assigns the given separate chaining hash table to this separate chaining hash table by using move semantics.
	 * @param other: The separate chaining hash table to move.
	 * @return A reference to this separate chaining hash table.
	 */
	SeparateChainingHashTable& operator=(SeparateChainingHashTable&& other) noexcept = default;

public:
	using value_type = std::pair<KeyType, ValueType>;
	using ConstForwardIterator = Iterators::SeparateChainingHashTableConstForwardIterator<KeyType, ValueType>;
	using ForwardIterator = Iterators::SeparateChainingHashTableForwardIterator<KeyType, ValueType>;
	
	/**
	 * @brief Gets a const forward iterator to the first element in the separate chaining hash table.
	 * @return A const forward iterator to the first element in the separate chaining hash table.
	 */
	ConstForwardIterator cbegin() const noexcept;
	
	/**
	 * @brief Gets a const forward iterator to the element after the last element in the separate chaining hash table.
	 * @return A const forward iterator to the element after the last element in the separate chaining hash table.
	 */
	ConstForwardIterator cend() const noexcept;
	
	/**
	 * @brief Gets a forward iterator to the first element in the separate chaining hash table.
	 * @return A forward iterator to the first element in the separate chaining hash table.
	 */
	ForwardIterator begin() noexcept;
	
	/**
	 * @brief Gets a forward iterator to the element after the last element in the separate chaining hash table.
	 * @return A forward iterator to the element after the last element in the separate chaining hash table.
	 */
	ForwardIterator end() noexcept;

public:
	/**
	 * @brief Inserts the given key-value pair into the separate chaining hash table using copy semantics.
	 * @param key: The key.
	 * @param value: The value.
	 */
	void insert(const KeyType& key, const ValueType& value);
	
	/**
	 * @brief Inserts the given key-value pair into the separate chaining hash table using move semantics.
	 * @param key: The key.
	 * @param value: The value.
	 */
	void insert(const KeyType& key, ValueType&& value);
	
	/**
	 * @brief Resizes the separate chaining hash table to the given size.
	 * @param updatedTableSize: The updated size of the separate chaining hash table.
	 * @throws std::invalid_argument: Thrown if the updated table size is 0.
	 */
	void resize(const std::size_t updatedTableSize);
	
	/**
	 * @brief Removes the key-value pair with the given key from the separate chaining hash table.
	 * @param key: The key.
	 * @return The value of the removed key-value pair if it exists, otherwise std::nullopt.
	 */
	std::optional<ValueType> remove(const KeyType& key) noexcept;
	
	/**
	 * @brief Finds the value of the key-value pair with the given key in the separate chaining hash table.
	 * @param key: The key.
	 * @return The value of the key-value pair if it exists, otherwise std::nullopt.
	 */
	std::optional<ValueType> find(const KeyType& key) const noexcept;
	
	/**
	 * @brief Checks if the separate chaining hash table contains the key-value pair with the given key.
	 * @param key: The key.
	 * @return True if the separate chaining hash table contains the key-value pair, otherwise false.
	 */
	const bool contains(const KeyType& key) const noexcept;
	
	/**
	 * @brief Checks if the separate chaining hash table is empty.
	 * @return True if the separate chaining hash table is empty, otherwise false.
	 */
	const bool isEmpty() const noexcept;
	
	/**
	 * @brief Gets the number of elements in the separate chaining hash table.
	 * @return The number of elements in the separate chaining hash table.
	 */
	const std::size_t getSize() const noexcept;
	
	/**
	 * @brief Gets the size of the separate chaining hash table.
	 * @return The size of the separate chaining hash table.
	 */
	const std::size_t getTableSize() const noexcept;

private:
	std::size_t tableSize;
	std::unique_ptr<HashFunctionFactory<KeyType>> hashFunctionFactory;
	std::vector<LinkedLists::SinglyLinkedList<std::pair<KeyType, ValueType>>> buckets;
	float loadFactor;
	std::size_t elementCount {0};
};

template<Hashable KeyType, typename ValueType>
SeparateChainingHashTable<KeyType, ValueType>::SeparateChainingHashTable(const std::size_t tableSize,
                                                                         std::unique_ptr<HashFunctionFactory<KeyType>> hashFunctionFactory,
                                                                         const float loadFactor):
		tableSize {tableSize},
		hashFunctionFactory {std::move(hashFunctionFactory)},
		buckets {tableSize},
		loadFactor {loadFactor} {
	if (tableSize == 0) {
		throw std::invalid_argument {"The table size must be greater than 0."};
	}
	
	if (loadFactor <= 0.0f || loadFactor >= 1.0f) {
		throw std::invalid_argument {"The load factor must be in the range (0.0f, 1.0f)"};
	}
}

template<Hashable KeyType, typename ValueType>
typename SeparateChainingHashTable<KeyType, ValueType>::ConstForwardIterator SeparateChainingHashTable<KeyType, ValueType>::cbegin() const noexcept {
	std::size_t bucketIndex {0};
	
	while (bucketIndex < buckets.size() && buckets[bucketIndex].isEmpty()) {
		++bucketIndex;
	}
	
	if (bucketIndex < buckets.size()) {
		return ConstForwardIterator {&buckets, bucketIndex, buckets[bucketIndex].cbegin()};
	}
	
	return cend();
}

template<Hashable KeyType, typename ValueType>
typename SeparateChainingHashTable<KeyType, ValueType>::ConstForwardIterator SeparateChainingHashTable<KeyType, ValueType>::cend() const noexcept {
	return ConstForwardIterator {&buckets,
	                             buckets.size(),
	                             LinkedLists::Iterators::SinglyLinkedListConstForwardIterator<std::pair<KeyType, ValueType>> {
			                             nullptr}};
}

template<Hashable KeyType, typename ValueType>
typename SeparateChainingHashTable<KeyType, ValueType>::ForwardIterator SeparateChainingHashTable<KeyType, ValueType>::begin() noexcept {
	std::size_t bucketIndex {0};
	
	while (bucketIndex < buckets.size() && buckets[bucketIndex].isEmpty()) {
		++bucketIndex;
	}
	
	if (bucketIndex < buckets.size()) {
		return ForwardIterator {&buckets, bucketIndex, buckets[bucketIndex].begin()};
	}
	
	return end();
}

template<Hashable KeyType, typename ValueType>
typename SeparateChainingHashTable<KeyType, ValueType>::ForwardIterator SeparateChainingHashTable<KeyType, ValueType>::end() noexcept {
	return ForwardIterator {&buckets,
	                        buckets.size(),
	                        LinkedLists::Iterators::SinglyLinkedListForwardIterator<std::pair<KeyType, ValueType>> {
			                        nullptr}};
}

template<Hashable KeyType, typename ValueType>
void SeparateChainingHashTable<KeyType, ValueType>::insert(const KeyType& key, const ValueType& value) {
	const auto hashFunction {hashFunctionFactory->create(tableSize)};
	const auto hash {(*hashFunction)(key)};
	auto& bucket {buckets[hash]};
	
	auto iterator {bucket.findFirst([&key](const std::pair<KeyType, ValueType>& pair) {
		return pair.first == key;
	})};
	
	if (iterator != bucket.end()) {
		iterator->second = value;
		return;
	}
	
	bucket.insertAtTail(std::make_pair(key, value));
	++elementCount;
	
	if (static_cast<float>(elementCount) / tableSize >= loadFactor) {
		resize(tableSize * 2);
	}
}

template<Hashable KeyType, typename ValueType>
void SeparateChainingHashTable<KeyType, ValueType>::insert(const KeyType& key, ValueType&& value) {
	const auto hashFunction {hashFunctionFactory->create(tableSize)};
	const auto hash {(*hashFunction)(key)};
	auto& bucket {buckets[hash]};
	
	auto iterator {bucket.findFirst([&key](const std::pair<KeyType, ValueType>& pair) {
		return pair.first == key;
	})};
	
	if (iterator != bucket.end()) {
		iterator->second = value;
		return;
	}
	
	bucket.insertAtTail(std::make_pair(key, value));
	++elementCount;
	
	if (static_cast<float>(elementCount) / tableSize >= loadFactor) {
		resize(tableSize * 2);
	}
}

template<Hashable KeyType, typename ValueType>
void SeparateChainingHashTable<KeyType, ValueType>::resize(const std::size_t updatedTableSize) {
	if (updatedTableSize == 0) {
		throw std::invalid_argument {"The table size must be greater than 0."};
	}
	
	const auto hashFunction {hashFunctionFactory->create(updatedTableSize)};
	std::vector<LinkedLists::SinglyLinkedList<std::pair<KeyType, ValueType>>> updatedBuckets {updatedTableSize};
	
	for (const auto& bucket : buckets) {
		for (const auto& pair : bucket) {
			const auto hash {(*hashFunction)(pair.first)};
			updatedBuckets[hash].insertAtTail(pair);
		}
	}
	
	buckets = std::move(updatedBuckets);
	tableSize = updatedTableSize;
}

template<Hashable KeyType, typename ValueType>
std::optional<ValueType> SeparateChainingHashTable<KeyType, ValueType>::remove(const KeyType& key) noexcept {
	const auto hashFunction {hashFunctionFactory->create(tableSize)};
	const auto hash {(*hashFunction)(key)};
	auto& bucket {buckets[hash]};
	const auto iterator {bucket.findFirst([&key](const std::pair<KeyType, ValueType>& pair) {
		return pair.first == key;
	})};
	
	if (iterator == bucket.end()) {
		return std::nullopt;
	}
	
	const auto index {std::distance(bucket.begin(), iterator)};
	const auto value {iterator->second};
	bucket.removeAtIndex(index);
	--elementCount;
	
	return value;
}

template<Hashable KeyType, typename ValueType>
std::optional<ValueType> SeparateChainingHashTable<KeyType, ValueType>::find(const KeyType& key) const noexcept {
	const auto hashFunction {hashFunctionFactory->create(tableSize)};
	const auto hash {(*hashFunction)(key)};
	const auto& bucket {buckets[hash]};
	const auto iterator {bucket.findFirst([&key](const std::pair<KeyType, ValueType>& pair) {
		return pair.first == key;
	})};
	
	return iterator != bucket.cend() ? std::make_optional(iterator->second) : std::nullopt;
}

template<Hashable KeyType, typename ValueType>
const bool SeparateChainingHashTable<KeyType, ValueType>::contains(const KeyType& key) const noexcept {
	const auto hashFunction {hashFunctionFactory->create(tableSize)};
	const auto hash {(*hashFunction)(key)};
	const auto& bucket {buckets[hash]};
	const auto iterator {bucket.findFirst([&key](const std::pair<KeyType, ValueType>& pair) {
		return pair.first == key;
	})};
	
	return iterator != bucket.cend();
}

template<Hashable KeyType, typename ValueType>
const bool SeparateChainingHashTable<KeyType, ValueType>::isEmpty() const noexcept {
	return elementCount == 0;
}

template<Hashable KeyType, typename ValueType>
const std::size_t SeparateChainingHashTable<KeyType, ValueType>::getSize() const noexcept {
	return elementCount;
}

template<Hashable KeyType, typename ValueType>
const std::size_t SeparateChainingHashTable<KeyType, ValueType>::getTableSize() const noexcept {
	return tableSize;
}
}