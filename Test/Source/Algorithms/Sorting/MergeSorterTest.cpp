#include <gmock/gmock.h>

#include "Algorithms/Sorting/MergeSorter.hpp"
#include "UnsortedIntegerData.hpp"
#include "UnsortedStringData.hpp"

namespace Core::Algorithms::Sorting::Test {
TEST(MergeSorterTest, GivenUnsortedIntegerArray_WhenSortAscendingOrder_ThenArrayIsSortedInAscendingOrder) {
	std::array<int, 10> unsortedData {unsortedIntegers};
	auto mergeSorter {MergeSorter<std::array<int, 10>>(unsortedData)};
	mergeSorter.sort(std::less<int> {});
	
	EXPECT_THAT(unsortedData, testing::ElementsAre(1, 6, 23, 29, 34, 45, 73, 88, 99, 100));
}

TEST(MergeSorterTest, GivenUnsortedIntegerVector_WhenSortDescendingOrder_ThenArrayIsSortedInDescendingOrder) {
	std::vector<int> unsortedData {unsortedIntegers.begin(), unsortedIntegers.end()};
	auto mergeSorter {MergeSorter<std::vector<int>>(unsortedData)};
	mergeSorter.sort(std::greater<int> {});
	
	EXPECT_THAT(unsortedData, testing::ElementsAre(100, 99, 88, 73, 45, 34, 29, 23, 6, 1));
}

TEST(MergeSorterTest, GivenUnsortedStringArray_WhenSortAscendingOrder_ThenArrayIsSortedInAscendingOrder) {
	std::array<std::string, 10> unsortedData {unsortedStrings};
	auto mergeSorter {MergeSorter<std::array<std::string, 10>>(unsortedData)};
	mergeSorter.sort(std::less<std::string> {});
	
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

TEST(MergeSorterTest, GivenUnsortedStringVector_WhenSortDescendingOrder_ThenVectorIsSortedInDescendingOrder) {
	std::vector<std::string> unsortedData {unsortedStrings.begin(), unsortedStrings.end()};
	auto mergeSorter {MergeSorter<std::vector<std::string>>(unsortedData)};
	mergeSorter.sort(std::greater<std::string> {});
	
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