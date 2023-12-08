#pragma once

#include <concepts>

namespace Core::DataStructures::Trees {
/**
 * @brief A concept that requires the type to have an operator< overload.
 * @tparam ElementType: The type to check.
 */
template<typename ElementType>
concept ElementTypeWithLessThanOperator = requires(const ElementType& left, const ElementType& right) {
	{ left < right } -> std::convertible_to<bool>;
};
}