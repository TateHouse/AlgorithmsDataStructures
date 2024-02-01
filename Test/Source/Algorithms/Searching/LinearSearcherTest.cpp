#include <gmock/gmock.h>

#include "Algorithms/Searching/LinearSearcher.hpp"
#include "SortedIntegerData.hpp"
#include "SortedStringData.hpp"

namespace Core::Algorithms::Searching::Test {
TEST(LinearSearcherTest, GivenSortedIntegerArray_WhenSearchForExistingElement_ThenReturnsTrue) {
	std::array<int, 10> sortedData {sortedIntegers};
	auto linearSearcher {LinearSearcher<std::array<int, 10>>(sortedData)};
	const auto result {linearSearcher.search([](const int& element) {
		return element == 73;
	})};
	
	EXPECT_THAT(result, testing::IsTrue());
}

TEST(LinearSearcherTest, GivenSortedIntegerArray_WhenSearchForNonExistingElement_ThenReturnsFalse) {
	std::array<int, 10> sortedData {sortedIntegers};
	auto linearSearcher {LinearSearcher<std::array<int, 10>>(sortedData)};
	const auto result {linearSearcher.search([](const int& element) {
		return element == 101;
	})};
	
	EXPECT_THAT(result, testing::IsFalse());
}

TEST(LinearSearcherTest, GivenSortedStringArray_WhenSearchForExistingElement_ThenReturnsTrue) {
	std::array<std::string, 10> sortedData {sortedStrings};
	auto linearSearcher {LinearSearcher<std::array<std::string, 10>>(sortedData)};
	const auto result {linearSearcher.search([](const std::string& element) {
		return element == "Peach";
	})};
	
	EXPECT_THAT(result, testing::IsTrue());
}

TEST(LinearSearcherTest, GivenSortedStringArray_WhenSearchForNonExistingElement_ThenReturnsFalse) {
	std::array<std::string, 10> sortedData {sortedStrings};
	auto linearSearcher {LinearSearcher<std::array<std::string, 10>>(sortedData)};
	const auto result {linearSearcher.search([](const std::string& element) {
		return element == "Pineapple";
	})};
	
	EXPECT_THAT(result, testing::IsFalse());
}
}