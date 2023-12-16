#pragma once

#include <vector>

#include "Algorithms/Hashing/HashConcepts.hpp"
#include "DataStructures/LinkedLists/SinglyLinkedList.hpp"

namespace Core::DataStructures::Hashing::Iterators {
/**
 * @brief A forward iterator for separate chaining hash table.
 * @tparam KeyType: The type of the key.
 * @tparam ValueType: The type of the value.
 */
template<Hashable KeyType, typename ValueType>
class SeparateChainingHashTableConstForwardIterator final {
public:
	using iterator_category = std::forward_iterator_tag;
	using difference_type = std::ptrdiff_t;
	using value_type = const std::pair<KeyType, ValueType>;
	using reference = const std::pair<KeyType, ValueType>&;
	using pointer = const std::pair<KeyType, ValueType>* const;
	
	/**
	 * @brief Instantiates a new separate chaining hash table const forward iterator.
	 * @param buckets: The buckets of the separate chaining hash table.
	 * @param bucketIndex: The index of the bucket to iterate from.
	 * @param iterator: The iterator of the bucket to iterate from.
	 */
	explicit SeparateChainingHashTableConstForwardIterator(const std::vector<LinkedLists::SinglyLinkedList<std::pair<KeyType, ValueType>>>* buckets,
	                                                       std::size_t bucketIndex,
	                                                       LinkedLists::SinglyLinkedList<std::pair<KeyType, ValueType>>::ConstForwardIterator iterator) noexcept;
	
	/**
	 * @brief Instantiates a new separate chaining hash table const forward iterator by copying the given separate
	 * chaining hash table const forward iterator.
	 * @param other: The separate chaining hash table const forward iterator to copy.
	 */
	SeparateChainingHashTableConstForwardIterator(const SeparateChainingHashTableConstForwardIterator<KeyType, ValueType>& other) = default;
	
	/**
	 * @brief Instantiates a new separate chaining hash table const forward iterator by moving the given separate
	 * chaining hash table const forward iterator.
	 * @param other: The separate chaining hash table const forward iterator to move.
	 */
	SeparateChainingHashTableConstForwardIterator(SeparateChainingHashTableConstForwardIterator<KeyType, ValueType>&& other) noexcept = default;
	
	/**
	 * @brief Destroys the separate chaining hash table const forward iterator.
	 */
	~SeparateChainingHashTableConstForwardIterator() noexcept = default;
	
public:
	/**
	 * @brief Assigns the given separate chaining hash table const forward iterator to this separate chaining hash
	 * table const forward iterator using copy semantics.
	 * chaining hash table const forward iterator using copy semantics.
	 * @param other The separate chaining hash table const forward iterator to copy.
	 * @return A reference to the separate chaining hash table const forward iterator.
	 */
	SeparateChainingHashTableConstForwardIterator<KeyType, ValueType>& operator=(const SeparateChainingHashTableConstForwardIterator<KeyType, ValueType>& other) = default;
	
	/**
	 * @brief Assigns the given separate chaining hash table const forward iterator to this separate chaining hash
	 * table const forward iterator using move semantics.
	 * @param other The separate chaining hash table const forward iterator to move.
	 * @return A reference to the separate chaining hash table const forward iterator.
	 */
	SeparateChainingHashTableConstForwardIterator<KeyType, ValueType>& operator=(SeparateChainingHashTableConstForwardIterator<KeyType, ValueType>&& other) noexcept = default;
	
	/**
	 * @brief Compares two separate chaining hash table const forward iterators.
	 * @details Two separate chaining hash table const forward iterators are equal if they point to the same buckets,
	 * the same bucket index, and the same iterator.
	 * @param other: The other separate chaining hash table const forward iterator to compare with.
	 * @return True if the two separate chaining hash table const forward iterators are equal, false otherwise.
	 */
	const bool operator==(const SeparateChainingHashTableConstForwardIterator<KeyType, ValueType>& other) const noexcept;

	/**
	 * @brief Dereferences the separate chaining hash table const forward iterator.
	 * @return A reference to the key-value pair stored in the node pointed to by the separate chaining hash table const forward iterator.
	 */
	reference operator*() const noexcept;
	
	/**
	 * @brief Dereferences the separate chaining hash table const forward iterator.
	 * @return A pointer to the key-value pair stored in the node pointed to by the separate chaining hash table const forward iterator.
	 */
	pointer operator->() const noexcept;
	
	/**
	 * @brief Increments the separate chaining hash table const forward iterator.
	 * @return A reference to the separate chaining hash table const forward iterator.
	 */
	SeparateChainingHashTableConstForwardIterator<KeyType, ValueType>& operator++() noexcept;
	
	/**
	 * @brief Increments the separate chaining hash table const forward iterator.
	 * @return A copy of the separate chaining hash table const forward iterator before it was incremented.
	 */
	SeparateChainingHashTableConstForwardIterator<KeyType, ValueType> operator++(int) noexcept;

private:
	const std::vector<LinkedLists::SinglyLinkedList<std::pair<KeyType, ValueType>>>* buckets;
	std::size_t bucketIndex;
	LinkedLists::SinglyLinkedList<std::pair<KeyType, ValueType>>::ConstForwardIterator iterator;
};

template<Hashable KeyType, typename ValueType>
SeparateChainingHashTableConstForwardIterator<KeyType, ValueType>::SeparateChainingHashTableConstForwardIterator(const std::vector<LinkedLists::SinglyLinkedList<std::pair<KeyType, ValueType>>>* buckets,
                                                                                                                 std::size_t bucketIndex,
                                                                                                                 LinkedLists::SinglyLinkedList<std::pair<KeyType, ValueType>>::ConstForwardIterator iterator) noexcept:
		buckets {buckets}, bucketIndex {bucketIndex}, iterator {iterator} {
	
}

template<Hashable KeyType, typename ValueType>
const bool SeparateChainingHashTableConstForwardIterator<KeyType, ValueType>::operator==(const SeparateChainingHashTableConstForwardIterator<KeyType, ValueType>& other) const noexcept {
	return buckets == other.buckets && bucketIndex == other.bucketIndex && iterator == other.iterator;
}

template<Hashable KeyType, typename ValueType>
const std::pair<KeyType, ValueType>& SeparateChainingHashTableConstForwardIterator<KeyType, ValueType>::operator*() const noexcept {
	assert(bucketIndex < buckets->size() && iterator != buckets->at(bucketIndex).cend() &&
	       "Cannot dereference a null iterator.");
	return *iterator;
}

template<Hashable KeyType, typename ValueType>
const std::pair<KeyType, ValueType>* const SeparateChainingHashTableConstForwardIterator<KeyType, ValueType>::operator->() const noexcept {
	assert(bucketIndex < buckets->size() && iterator != buckets->at(bucketIndex).cend() &&
	       "Cannot dereference a null iterator.");
	return &(*iterator);
}

template<Hashable KeyType, typename ValueType>
SeparateChainingHashTableConstForwardIterator<KeyType, ValueType>& SeparateChainingHashTableConstForwardIterator<KeyType, ValueType>::operator++() noexcept {
	assert(bucketIndex < buckets->size() && iterator != buckets->at(bucketIndex).cend() &&
	       "Cannot increment a null iterator.");
	++iterator;
	if (iterator == buckets->at(bucketIndex).cend()) {
		++bucketIndex;
		while (bucketIndex < buckets->size() && buckets->at(bucketIndex).isEmpty()) {
			++bucketIndex;
		}
		if (bucketIndex < buckets->size()) {
			iterator = buckets->at(bucketIndex).cbegin();
		}
	}
	return *this;
}

template<Hashable KeyType, typename ValueType>
SeparateChainingHashTableConstForwardIterator<KeyType, ValueType> SeparateChainingHashTableConstForwardIterator<KeyType, ValueType>::operator++(int) noexcept {
	assert(bucketIndex < buckets->size() && iterator != buckets->at(bucketIndex).cend() &&
	       "Cannot increment a null iterator.");
	auto iterator {*this};
	++(*this);
	return iterator;
}
}