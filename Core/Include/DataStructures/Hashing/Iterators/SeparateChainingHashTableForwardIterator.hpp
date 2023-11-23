#pragma once

#include <vector>

#include "DataStructures/LinkedLists/SinglyLinkedList.hpp"
#include "DataStructures/Hashing/HashConcepts.hpp"

namespace Core::DataStructures::Hashing::Iterators {
template<Hashable KeyType, typename ValueType>
class SeparateChainingHashTableForwardIterator final {
public:
	using iterator_category = std::forward_iterator_tag;
	using difference_type = std::ptrdiff_t;
	using value_type = std::pair<KeyType, ValueType>;
	using reference = std::pair<KeyType, ValueType>&;
	using pointer = std::pair<KeyType, ValueType>*;
	
	explicit SeparateChainingHashTableForwardIterator(std::vector<LinkedLists::SinglyLinkedList<std::pair<KeyType, ValueType>>>* buckets,
	                                                  std::size_t bucketIndex,
	                                                  LinkedLists::SinglyLinkedList<std::pair<KeyType, ValueType>>::ForwardIterator iterator) noexcept;

public:
	const bool operator==(const SeparateChainingHashTableForwardIterator<KeyType, ValueType>& other) const noexcept;

public:
	reference operator*() const noexcept;
	pointer operator->() const noexcept;
	SeparateChainingHashTableForwardIterator<KeyType, ValueType>& operator++() noexcept;
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