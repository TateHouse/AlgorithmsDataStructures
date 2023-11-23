#pragma once

#include <memory>

#include "HashFunction.hpp"

namespace Core::DataStructures::Hashing {
template<typename KeyType>
class HashFunctionFactory {
public:
	virtual ~HashFunctionFactory() noexcept = default;

public:
	virtual std::unique_ptr<HashFunction<KeyType>> create(const std::size_t tableSize) const noexcept = 0;
};
}