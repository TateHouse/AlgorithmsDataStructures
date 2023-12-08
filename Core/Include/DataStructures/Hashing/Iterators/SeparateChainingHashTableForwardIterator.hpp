#pragma once

#include <vector>

#include "DataStructures/LinkedLists/SinglyLinkedList.hpp"
#include "DataStructures/Hashing/HashConcepts.hpp"

namespace Core::DataStructures::Hashing::Iterators {
/**
 * @brief A forward iterator for separate chaining hash table.
 * @tparam KeyType: The type of the key.
 * @tparam ValueType: The type of the value.
 */
template<Hashable KeyType, typename ValueType>
class SeparateChainingHashTableForwardIterator final {
public:
	using iterator_category = std::forward_iterator_tag;
	using difference_type = std::ptrdiff_t;
	using value_type = std::pair<KeyType, ValueType>;
	using reference = std::pair<KeyType, ValueType>&;
	using pointer = std::pair<KeyType, ValueType>*;
	
	/**
	 * @brief Instantiates a new separate chaining hash table forward iterator.
	 * @param buckets: The buckets of the separate chaining hash table.
	 * @param bucketIndex: The index of the bucket to iterate from.
	 * @param iterator: The iterator of the bucket to iterate from.
	 */
	explicit SeparateChainingHashTableForwardIterator(std::vector<LinkedLists::SinglyLinkedList<std::pair<KeyType, ValueType>>>* buckets,
	                                                  std::size_t bucketIndex,
	                                                  LinkedLists::SinglyLinkedList<std::pair<KeyType, ValueType>>::ForwardIterator iterator) noexcept;

public:
	/**
	 * @brief Compares two separate chaining hash table forward iterators.
	 * @details Two separate chaining hash table forward iterators are equal if they point to the same buckets,
	 * the same bucket index, and the same iterator.
	 * @param other: The other separate chaining hash table forward iterator to compare with.
	 * @return True if the two separate chaining hash table forward iterators are equal, false otherwise.
	 */
	const bool operator==(const SeparateChainingHashTableForwardIterator<KeyType, ValueType>& other) const noexcept;

public:
	/**
	 * @brief Dereferences the separate chaining hash table forward iterator.
	 * @return A reference to the key-value pair stored in the node pointed to by the separate chaining hash table forward iterator.
	 */
	reference operator*() const noexcept;
	
	/**
	 * @brief Dereferences the separate chaining hash table forward iterator.
	 * @return A pointer to the key-value pair stored in the node pointed to by the separate chaining hash table forward iterator.
	 */
	pointer operator->() const noexcept;
	
	/**
	 * @brief Increments the separate chaining hash table forward iterator.
	 * @return A reference to the separate chaining hash table forward iterator.
	 */
	SeparateChainingHashTableForwardIterator<KeyType, ValueType>& operator++() noexcept;
	
	/**
	 * @brief Increments the separate chaining hash table forward iterator.
	 * @return A copy of the separate chaining hash table forward iterator before it was incremented.
	 */
	SeparateChainingHashTableForwardIterator<KeyType, ValueType> operator++(int) noexcept;

private:
	std::vector<LinkedLists::SinglyLinkedList<std::pair<KeyType, ValueType>>>* buckets;
	std::size_t bucketIndex;
	LinkedLists::SinglyLinkedList<std::pair<KeyType, ValueType>>::ForwardIterator iterator;
};

template<Hashable KeyType, typename ValueType>
SeparateChainingHashTableForwardIterator<KeyType, ValueType>::SeparateChainingHashTableForwardIterator(std::vector<LinkedLists::SinglyLinkedList<std::pair<KeyType, ValueType>>>* buckets,
                                                                                                       std::size_t bucketIndex,
                                                                                                       LinkedLists::SinglyLinkedList<std::pair<KeyType, ValueType>>::ForwardIterator iterator) noexcept:
		buckets {buckets}, bucketIndex {bucketIndex}, iterator {iterator} {
	
}

template<Hashable KeyType, typename ValueType>
const bool SeparateChainingHashTableForwardIterator<KeyType, ValueType>::operator==(const SeparateChainingHashTableForwardIterator<KeyType, ValueType>& other) const noexcept {
	return buckets == other.buckets && bucketIndex == other.bucketIndex && iterator == other.iterator;
}

template<Hashable KeyType, typename ValueType>
std::pair<KeyType, ValueType>& SeparateChainingHashTableForwardIterator<KeyType, ValueType>::operator*() const noexcept {
	assert(bucketIndex < buckets->size() && iterator != buckets->at(bucketIndex).end() && "Cannot dereference a null iterator.");
	return *iterator;
}

template<Hashable KeyType, typename ValueType>
std::pair<KeyType, ValueType>* SeparateChainingHashTableForwardIterator<KeyType, ValueType>::operator->() const noexcept {
	assert(bucketIndex < buckets->size() && iterator != buckets->at(bucketIndex).end() && "Cannot dereference a null iterator.");
	return &(*iterator);
}

template<Hashable KeyType, typename ValueType>
SeparateChainingHashTableForwardIterator<KeyType, ValueType>& SeparateChainingHashTableForwardIterator<KeyType, ValueType>::operator++() noexcept {
	assert(iterator != buckets->at(bucketIndex).end() && "Cannot increment a null iterator.");
	++iterator;
	
	if (bucketIndex < buckets->size() - 1 && iterator == buckets->at(bucketIndex).end()) {
		++bucketIndex;
		
		while (bucketIndex < buckets->size() && buckets->at(bucketIndex).isEmpty()) {
			++bucketIndex;
		}
		
		if (bucketIndex < buckets->size()) {
			iterator = buckets->at(bucketIndex).begin();
		}
	}
	
	return *this;
}

template<Hashable KeyType, typename ValueType>
SeparateChainingHashTableForwardIterator<KeyType, ValueType> SeparateChainingHashTableForwardIterator<KeyType, ValueType>::operator++(int) noexcept {
	assert(iterator != buckets->at(bucketIndex).end() && "Cannot increment a null iterator.");
	auto iterator {*this};
	++(*this);
	return iterator;
}
}