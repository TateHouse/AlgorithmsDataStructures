#include <gmock/gmock.h>

#include "Algorithms/Searching/BinarySearcher.hpp"
#include "Algorithms/Searching/BinarySearchPredicate.hpp"
#include "SortedIntegerData.hpp"
#include "SortedStringData.hpp"

namespace Core::Algorithms::Searching::Test {
TEST(BinarySearcherTest, GivenSortedIntegerArray_WhenSearchForExistingElement_ThenReturnsTrue) {
	std::array<int, 10> sortedData {sortedIntegers};
	BinarySearchPredicate<int> predicate {73};
	auto binarySearcher {BinarySearcher<std::array<int, 10>>(sortedData)};
	const auto result {binarySearcher.search(predicate)};
	
	EXPECT_THAT(result, testing::IsTrue());
}

TEST(BinarySearcherTest, GivenSortedIntegerArray_WhenSearchForNonExistingElement_ThenReturnsFalse) {
	std::array<int, 10> sortedData {sortedIntegers};
	BinarySearchPredicate<int> predicate {101};
	auto binarySearcher {BinarySearcher<std::array<int, 10>>(sortedData)};
	const auto result {binarySearcher.search(predicate)};
	
	EXPECT_THAT(result, testing::IsFalse());
};

TEST(BinarySearcherTest, GivenSortedStringArray_WhenSearchForExistingElement_ThenReturnsTrue) {
	std::array<std::string, 10> sortedData {sortedStrings};
	BinarySearchPredicate<std::string> predicate {"Peach"};
	auto binarySearcher {BinarySearcher<std::array<std::string, 10>>(sortedData)};
	const auto result {binarySearcher.search(predicate)};
	
	EXPECT_THAT(result, testing::IsTrue());
}

TEST(BinarySearcherTest, GivenSortedStringArray_WhenSearchForNonExistingElement_ThenReturnsFalse) {
	std::array<std::string, 10> sortedData {sortedStrings};
	BinarySearchPredicate<std::string> predicate {"Pineapple"};
	auto binarySearcher {BinarySearcher<std::array<std::string, 10>>(sortedData)};
	const auto result {binarySearcher.search(predicate)};
	
	EXPECT_THAT(result, testing::IsFalse());
}
}