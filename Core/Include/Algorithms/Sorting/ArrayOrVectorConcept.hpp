#pragma once

#include <array>
#include <vector>

namespace Core::Algorithms::Sorting {
/**
 * @brief A concept that requires the container to be either an std::array or an std::vector.
 * @tparam Container: The container type.
 */
template<typename Container>
concept ArrayOrVectorConcept = requires(Container container) {
	requires std::is_same_v<Container, std::array<typename Container::value_type, std::tuple_size<Container>::value>> ||
			 std::is_same_v<Container, std::vector<typename Container::value_type>>;
};
}