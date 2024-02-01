#include <gmock/gmock.h>

#include "Algorithms/Searching/BinarySearcher.hpp"
#include "SortedIntegerData.hpp"
#include "SortedStringData.hpp"

namespace Core::Algorithms::Searching::Test {
TEST(BinarySearcherTest, GivenSortedIntegerArray_WhenSearchForExistingElement_ThenReturnsTrue) {
	std::array<int, 10> sortedData {sortedIntegers};
	const auto predicate {[](const int& element) {
		const auto target {73};
		
		if (target == element) {
			return 0;
		}
		
		if (target < element) {
			return -1;
		}
		
		return 1;
	}};
	
	auto binarySearcher {BinarySearcher<std::array<int, 10>>(sortedData)};
	const auto result {binarySearcher.search(predicate)};
	
	EXPECT_THAT(result, testing::IsTrue());
}

TEST(BinarySearcherTest, GivenSortedIntegerArray_WhenSearchForNonExistingElement_ThenReturnsFalse) {
	std::array<int, 10> sortedData {sortedIntegers};
	const auto predicate {[](const int& element) {
		const auto target {101};
		
		if (target == element) {
			return 0;
		}
		
		if (target < element) {
			return -1;
		}
		
		return 1;
	}};
	
	auto binarySearcher {BinarySearcher<std::array<int, 10>>(sortedData)};
	const auto result {binarySearcher.search(predicate)};
	
	EXPECT_THAT(result, testing::IsFalse());
};

TEST(BinarySearcherTest, GivenSortedStringArray_WhenSearchForExistingElement_ThenReturnsTrue) {
	std::array<std::string, 10> sortedData {sortedStrings};
	const auto predicate {[](const std::string& element) {
		const auto target {"Peach"};
		
		if (target == element) {
			return 0;
		}
		
		if (target < element) {
			return -1;
		}
		
		return 1;
	}};
	
	auto binarySearcher {BinarySearcher<std::array<std::string, 10>>(sortedData)};
	const auto result {binarySearcher.search(predicate)};
	
	EXPECT_THAT(result, testing::IsTrue());
}

TEST(BinarySearcherTest, GivenSortedStringArray_WhenSearchForNonExistingElement_ThenReturnsFalse) {
	std::array<std::string, 10> sortedData {sortedStrings};
	const auto predicate {[](const std::string& element) {
		const auto target {"Pineapple"};
		
		if (target == element) {
			return 0;
		}
		
		if (target < element) {
			return -1;
		}
		
		return 1;
	}};
	
	auto binarySearcher {BinarySearcher<std::array<std::string, 10>>(sortedData)};
	const auto result {binarySearcher.search(predicate)};
	
	EXPECT_THAT(result, testing::IsFalse());
}
}