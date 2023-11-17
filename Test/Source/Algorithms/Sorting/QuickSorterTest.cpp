#include <gmock/gmock.h>

#include "Algorithms/Sorting/QuickSorter.hpp"
#include "UnsortedIntegerData.hpp"
#include "UnsortedStringData.hpp"

namespace Core::Algorithms::Sorting::Test {
TEST(QuickSorterTest, GivenUnsortedIntegerArray_WhenSortAscendingOrder_ThenArrayIsSortedInAscendingOrder) {
	std::array<int, 10> unsortedData {unsortedIntegers};
	auto quickSorter {QuickSorter<std::array<int, 10>>(unsortedData)};
	quickSorter.sort(std::less<int> {});
	
	EXPECT_THAT(unsortedData, testing::ElementsAre(1, 6, 23, 29, 34, 45, 73, 88, 99, 100));
}

TEST(QuickSorterTest, GivenUnsortedIntegerVector_WhenSortDescendingOrder_ThenArrayIsSortedInDescendingOrder) {
	std::vector<int> unsortedData {unsortedIntegers.begin(), unsortedIntegers.end()};
	auto quickSorter {QuickSorter<std::vector<int>>(unsortedData)};
	quickSorter.sort(std::greater<int> {});
	
	EXPECT_THAT(unsortedData, testing::ElementsAre(100, 99, 88, 73, 45, 34, 29, 23, 6, 1));
}

TEST(QuickSorterTest, GivenUnsortedStringArray_WhenSortAscendingOrder_ThenArrayIsSortedInAscendingOrder) {
	std::array<std::string, 10> unsortedData {unsortedStrings};
	auto quickSorter {QuickSorter<std::array<std::string, 10>>(unsortedData)};
	quickSorter.sort(std::less<std::string> {});
	
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

TEST(QuickSorterTest, GivenUnsortedStringVector_WhenSortDescendingOrder_ThenVectorIsSortedInDescendingOrder) {
	std::vector<std::string> unsortedData {unsortedStrings.begin(), unsortedStrings.end()};
	auto quickSorter {QuickSorter<std::vector<std::string>>(unsortedData)};
	quickSorter.sort(std::greater<std::string> {});
	
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