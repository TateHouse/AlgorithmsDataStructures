#pragma once

#include <limits>
#include <stdexcept>

#include "HashConcepts.hpp"
#include "HashFunction.hpp"

namespace Core::DataStructures::Hashing {
template<Hashable KeyType>
class MultiplicationMethodHashFunction final : public HashFunction<KeyType> {
public:
	explicit MultiplicationMethodHashFunction(const std::size_t tableSize,
	                                          const double hashMultiplier = 0.61803398875f);
	MultiplicationMethodHashFunction(const MultiplicationMethodHashFunction& other) noexcept = default;
	MultiplicationMethodHashFunction(MultiplicationMethodHashFunction&& other) noexcept = default;
	~MultiplicationMethodHashFunction() noexcept = default;

public:
	MultiplicationMethodHashFunction& operator=(const MultiplicationMethodHashFunction& other) noexcept = default;
	MultiplicationMethodHashFunction& operator=(MultiplicationMethodHashFunction&& other) noexcept = default;
	virtual std::size_t operator()(const KeyType& key) const noexcept override;

private:
	std::size_t tableSize;
	double hashMultiplier;
};

template<Hashable KeyType>
MultiplicationMethodHashFunction<KeyType>::MultiplicationMethodHashFunction(const std::size_t tableSize,
                                                                            const double hashMultiplier)
		: tableSize {tableSize}, hashMultiplier {hashMultiplier} {
	if (hashMultiplier <= 0.0f || hashMultiplier >= 1.0f) {
		throw std::invalid_argument {"The hash multiplier must be in range (0, 1)"};
	}
}

template<Hashable KeyType>
std::size_t MultiplicationMethodHashFunction<KeyType>::operator()(const KeyType& key) const noexcept {
	std::hash<KeyType> hashFunction {};
	const auto hashValue {hashFunction(key)};
	const auto scaledHashValue {hashValue % std::numeric_limits<int32_t>::max()};
	const auto product {scaledHashValue * hashMultiplier};
	const auto fractionalPart {product - std::floor(product)};
	
	return static_cast<std::size_t>(fractionalPart * tableSize);
}
}