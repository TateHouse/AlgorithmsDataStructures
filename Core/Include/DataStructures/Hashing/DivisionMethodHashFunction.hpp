#pragma once

#include "HashConcepts.hpp"
#include "HashFunction.hpp"

namespace Core::DataStructures::Hashing {
template<Hashable KeyType>
class DivisionMethodHashFunction final : public HashFunction<KeyType> {
public:
	explicit DivisionMethodHashFunction(const std::size_t tableSize);
	DivisionMethodHashFunction(const DivisionMethodHashFunction& other) noexcept = default;
	DivisionMethodHashFunction(DivisionMethodHashFunction&& other) noexcept = default;
	~DivisionMethodHashFunction() noexcept = default;

public:
	DivisionMethodHashFunction& operator=(const DivisionMethodHashFunction& other) noexcept = default;
	DivisionMethodHashFunction& operator=(DivisionMethodHashFunction&& other) noexcept = default;
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