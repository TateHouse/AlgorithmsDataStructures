#pragma once

#include <concepts>

namespace Core::DataStructures::Trees {
template<typename ElementType>
concept ElementTypeWithLessThanOperator = requires(const ElementType& left, const ElementType& right) {
	{ left < right } -> std::convertible_to<bool>;
};
}