#pragma once

#include "MultiplicationMethodHashFunction.hpp"
#include "HashFunctionFactory.hpp"

namespace Core::DataStructures::Hashing {
template<typename KeyType>
class MultiplicationMethodHashFunctionFactory final : public HashFunctionFactory<KeyType> {
public:
	explicit MultiplicationMethodHashFunctionFactory() noexcept = default;
	MultiplicationMethodHashFunctionFactory(const MultiplicationMethodHashFunctionFactory& other) = delete;
	MultiplicationMethodHashFunctionFactory(MultiplicationMethodHashFunctionFactory&& other) noexcept = default;
	~MultiplicationMethodHashFunctionFactory() noexcept override = default;

public:
	MultiplicationMethodHashFunctionFactory& operator=(const MultiplicationMethodHashFunctionFactory& other) = delete;
	MultiplicationMethodHashFunctionFactory& operator=(MultiplicationMethodHashFunctionFactory&& other) noexcept = default;

public:
	std::unique_ptr<HashFunction<KeyType>> create(const std::size_t tableSize) const noexcept override;
};

template<typename KeyType>
std::unique_ptr<HashFunction<KeyType>> MultiplicationMethodHashFunctionFactory<KeyType>::create(const std::size_t tableSize) const noexcept {
	return std::make_unique<MultiplicationMethodHashFunction<KeyType>>(tableSize);
}
}