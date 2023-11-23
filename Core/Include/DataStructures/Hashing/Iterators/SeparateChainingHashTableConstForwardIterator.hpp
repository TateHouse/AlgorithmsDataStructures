#pragma once

#include <vector>

#include "DataStructures/LinkedLists/SinglyLinkedList.hpp"
#include "DataStructures/Hashing/HashConcepts.hpp"

namespace Core::DataStructures::Hashing::Iterators {
template<Hashable KeyType, typename ValueType>
class SeparateChainingHashTableConstForwardIterator final {
public:
	using iterator_category = std::forward_iterator_tag;
	using difference_type = std::ptrdiff_t;
	using value_type = const std::pair<KeyType, ValueType>;
	using reference = const std::pair<KeyType, ValueType>&;
	using pointer = const std::pair<KeyType, ValueType>* const;
	
	explicit SeparateChainingHashTableConstForwardIterator(const std::vector<LinkedLists::SinglyLinkedList<std::pair<KeyType, ValueType>>>* buckets,
	                                                       std::size_t bucketIndex,
	                                                       LinkedLists::SinglyLinkedList<std::pair<KeyType, ValueType>>::ConstForwardIterator iterator) noexcept;

public:
	const bool operator==(const SeparateChainingHashTableConstForwardIterator<KeyType, ValueType>& other) const noexcept;

public:
	reference operator*() const noexcept;
	pointer operator->() const noexcept;
	SeparateChainingHashTableConstForwardIterator<KeyType, ValueType>& operator++() noexcept;
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