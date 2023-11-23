#pragma once

#include <memory>
#include <optional>
#include <vector>

#include "DataStructures/LinkedLists/SinglyLinkedList.hpp"
#include "HashConcepts.hpp"
#include "HashFunctionFactory.hpp"

namespace Core::DataStructures::Hashing {
template<Hashable KeyType, typename ValueType>
class SeparateChainingHashTable final {
public:
	explicit SeparateChainingHashTable(const std::size_t tableSize,
	                                   std::unique_ptr<HashFunctionFactory<KeyType>> hashFunctionFactory) noexcept;
	SeparateChainingHashTable(const SeparateChainingHashTable& other) = delete;
	SeparateChainingHashTable(SeparateChainingHashTable&& other) noexcept = default;
	~SeparateChainingHashTable() noexcept = default;

public:
	SeparateChainingHashTable& operator=(const SeparateChainingHashTable& other) = delete;
	SeparateChainingHashTable& operator=(SeparateChainingHashTable&& other) noexcept = default;

public:
	void insert(const KeyType& key, const ValueType& value);
	void insert(const KeyType& key, ValueType&& value);
	void resize(const std::size_t updatedTableSize);
	std::optional<ValueType> find(const KeyType& key) const noexcept;
	
	const std::size_t getSize() const noexcept;
	const std::size_t getTableSize() const noexcept;

private:
	static constexpr float loadFactor {0.75f};
	std::size_t tableSize;
	std::unique_ptr<HashFunctionFactory<KeyType>> hashFunctionFactory;
	std::vector<LinkedLists::SinglyLinkedList<std::pair<KeyType, ValueType>>> buckets;
	std::size_t elementCount {0};
};

template<Hashable KeyType, typename ValueType>
SeparateChainingHashTable<KeyType, ValueType>::SeparateChainingHashTable(const std::size_t tableSize,
                                                                         std::unique_ptr<HashFunctionFactory<KeyType>> hashFunctionFactory) noexcept
		: tableSize {tableSize}, hashFunctionFactory {std::move(hashFunctionFactory)}, buckets {tableSize} {
	
}

template<Hashable KeyType, typename ValueType>
void SeparateChainingHashTable<KeyType, ValueType>::insert(const KeyType& key, const ValueType& value) {
	const auto hashFunction {hashFunctionFactory->create(tableSize)};
	const auto hash {(*hashFunction)(key)};
	buckets[hash].insertAtTail(std::make_pair(key, value));
	++elementCount;
	
	if (static_cast<float>(elementCount) / tableSize >= loadFactor) {
		resize(tableSize * 2);
	}
}

template<Hashable KeyType, typename ValueType>
void SeparateChainingHashTable<KeyType, ValueType>::insert(const KeyType& key, ValueType&& value) {
	const auto hashFunction {hashFunctionFactory->create(tableSize)};
	const auto hash {(*hashFunction)(key)};
	buckets[hash].insertAtTail(std::make_pair(key, value));
	++elementCount;
	
	if (static_cast<float>(elementCount) / tableSize >= loadFactor) {
		resize(tableSize * 2);
	}
}

template<Hashable KeyType, typename ValueType>
void SeparateChainingHashTable<KeyType, ValueType>::resize(const std::size_t updatedTableSize) {
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
const std::size_t SeparateChainingHashTable<KeyType, ValueType>::getSize() const noexcept {
	return elementCount;
}

template<Hashable KeyType, typename ValueType>
const std::size_t SeparateChainingHashTable<KeyType, ValueType>::getTableSize() const noexcept {
	return tableSize;
}
}