#pragma once

#include "DivisionMethodHashFunction.hpp"
#include "HashFunctionFactory.hpp"

namespace Core::DataStructures::Hashing {
template<typename KeyType>
class DivisionMethodHashFunctionFactory final : public HashFunctionFactory<KeyType> {
public:
	explicit DivisionMethodHashFunctionFactory() noexcept = default;
	DivisionMethodHashFunctionFactory(const DivisionMethodHashFunctionFactory& other) = delete;
	DivisionMethodHashFunctionFactory(DivisionMethodHashFunctionFactory&& other) noexcept = default;
	~DivisionMethodHashFunctionFactory() noexcept override = default;

public:
	DivisionMethodHashFunctionFactory& operator=(const DivisionMethodHashFunctionFactory& other) = delete;
	DivisionMethodHashFunctionFactory& operator=(DivisionMethodHashFunctionFactory&& other) noexcept = default;

public:
	std::unique_ptr<HashFunction<KeyType>> create(const std::size_t tableSize) const noexcept override {
		return std::make_unique<DivisionMethodHashFunction<KeyType>>(tableSize);
	}
};
}