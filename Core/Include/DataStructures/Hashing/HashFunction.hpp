#pragma once

#include <cstddef>

namespace Core::DataStructures::Hashing {
template<typename KeyType>
class HashFunction {
public:
	virtual ~HashFunction() = default;

public:
	virtual std::size_t operator()(const KeyType& key) const = 0;
};
}