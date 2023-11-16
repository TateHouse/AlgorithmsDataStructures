#include <gmock/gmock.h>

#include "Algorithms/Sorting/BubbleSorter.hpp"
#include "UnsortedIntegerData.hpp"
#include "UnsortedStringData.hpp"

namespace Core::Algorithms::Sorting::Test {
TEST(BubbleSorterTest, GivenUnsortedIntegerArray_WhenSortAscendingOrder_ThenArrayIsSortedInAscendingOrder) {
	std::array<int, 10> unsortedData {unsortedIntegers};
	auto bubbleSorter {BubbleSorter<std::array<int, 10>>(unsortedData)};
	bubbleSorter.sort(std::less<int> {});
	
	EXPECT_THAT(unsortedData, testing::ElementsAre(1, 6, 23, 29, 34, 45, 73, 88, 99, 100));
}

TEST(BubbleSorterTest, GivenUnsortedIntegerVector_WhenSortDescendingOrder_ThenArrayIsSortedInDescendingOrder) {
	std::vector<int> unsortedData {unsortedIntegers.begin(), unsortedIntegers.end()};
	auto bubbleSorter {BubbleSorter<std::vector<int>>(unsortedData)};
	bubbleSorter.sort(std::greater<int> {});
	
	EXPECT_THAT(unsortedData, testing::ElementsAre(100, 99, 88, 73, 45, 34, 29, 23, 6, 1));
}

TEST(BubbleSorterTest, GivenUnsortedStringArray_WhenSortAscendingOrder_ThenArrayIsSortedInAscendingOrder) {
	std::array<std::string, 10> unsortedData {unsortedStrings};
	auto bubbleSorter {BubbleSorter<std::array<std::string, 10>>(unsortedData)};
	bubbleSorter.sort(std::less<std::string> {});
	
	EXPECT_THAT(unsortedData,
	            testing::ElementsAre("!",
	                                 "Apple",
	                                 "Banana",
	                                 "Cherry",
	                                 "Grape",
	                                 "Melon",
	                                 "Orange",
	                                 "Peach",
	                                 "Pear",
	                                 "Strawberry"));
}

TEST(BubbleSorterTest, GivenUnsortedStringVector_WhenSortDescendingOrder_ThenVectorIsSortedInDescendingOrder) {
	std::vector<std::string> unsortedData {unsortedStrings.begin(), unsortedStrings.end()};
	auto bubbleSorter {BubbleSorter<std::vector<std::string>>(unsortedData)};
	bubbleSorter.sort(std::greater<std::string> {});
	
	EXPECT_THAT(unsortedData,
	            testing::ElementsAre("Strawberry",
	                                 "Pear",
	                                 "Peach",
	                                 "Orange",
	                                 "Melon",
	                                 "Grape",
	                                 "Cherry",
	                                 "Banana",
	                                 "Apple",
	                                 "!"));
}
}