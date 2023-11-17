#include <gmock/gmock.h>

#include "Algorithms/Sorting/SelectionSorter.hpp"
#include "UnsortedIntegerData.hpp"
#include "UnsortedStringData.hpp"

namespace Core::Algorithms::Sorting::Test {
TEST(SelectionSorterTest, GivenUnsortedIntegerArray_WhenSortAscendingOrder_ThenArrayIsSortedInAscendingOrder) {
	std::array<int, 10> unsortedData {unsortedIntegers};
	auto selectionSorter {SelectionSorter<std::array<int, 10>>(unsortedData)};
	selectionSorter.sort(std::less<int> {});
	
	EXPECT_THAT(unsortedData, testing::ElementsAre(1, 6, 23, 29, 34, 45, 73, 88, 99, 100));
}

TEST(SelectionSorterTest, GivenUnsortedIntegerVector_WhenSortDescendingOrder_ThenArrayIsSortedInDescendingOrder) {
	std::vector<int> unsortedData {unsortedIntegers.begin(), unsortedIntegers.end()};
	auto selectionSorter {SelectionSorter<std::vector<int>>(unsortedData)};
	selectionSorter.sort(std::greater<int> {});
	
	EXPECT_THAT(unsortedData, testing::ElementsAre(100, 99, 88, 73, 45, 34, 29, 23, 6, 1));
}

TEST(SelectionSorterTest, GivenUnsortedStringArray_WhenSortAscendingOrder_ThenArrayIsSortedInAscendingOrder) {
	std::array<std::string, 10> unsortedData {unsortedStrings};
	auto selectionSorter {SelectionSorter<std::array<std::string, 10>>(unsortedData)};
	selectionSorter.sort(std::less<std::string> {});
	
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

TEST(SelectionSorterTest, GivenUnsortedStringVector_WhenSortDescendingOrder_ThenVectorIsSortedInDescendingOrder) {
	std::vector<std::string> unsortedData {unsortedStrings.begin(), unsortedStrings.end()};
	auto selectionSorter {SelectionSorter<std::vector<std::string>>(unsortedData)};
	selectionSorter.sort(std::greater<std::string> {});
	
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