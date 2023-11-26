#include <gmock/gmock.h>

#include <memory>
#include <string>

#include "DataStructures/Hashing/DivisionMethodHashFunctionFactory.hpp"
#include "DataStructures/Hashing/SeparateChainingHashTable.hpp"

namespace Core::DataStructures::Hashing::Test {
class EmptyStringToIntegerSeparateChainingHashTableTest : public testing::Test {
public:
	EmptyStringToIntegerSeparateChainingHashTableTest() noexcept = default;
	virtual ~EmptyStringToIntegerSeparateChainingHashTableTest() noexcept = default;

protected:
	SeparateChainingHashTable<std::string, int> hashTable {11,
	                                                       std::make_unique<DivisionMethodHashFunctionFactory<std::string>>()};
};

TEST_F(EmptyStringToIntegerSeparateChainingHashTableTest, WhenConstForwardIterate_ThenIteratesOverAllElements) {
	const auto constHashTable {std::move(hashTable)};
	const auto begin {constHashTable.cbegin()};
	const auto end {constHashTable.cend()};
	
	std::vector<std::pair<std::string, int>> result {};
	for (auto iterator {begin}; iterator != end; ++iterator) {
		result.push_back(*iterator);
	}
	
	std::vector<std::pair<std::string, int>> expected {};
	
	EXPECT_THAT(result, testing::UnorderedElementsAreArray(expected));
}

TEST_F(EmptyStringToIntegerSeparateChainingHashTableTest, WhenForwardIterate_ThenIteratesOverAllElements) {
	const auto begin {hashTable.begin()};
	const auto end {hashTable.end()};
	
	std::vector<std::pair<std::string, int>> result {};
	for (auto iterator {begin}; iterator != end; ++iterator) {
		result.push_back(*iterator);
	}
	
	std::vector<std::pair<std::string, int>> expected {};
	
	EXPECT_THAT(result, testing::UnorderedElementsAreArray(expected));
}

TEST_F(EmptyStringToIntegerSeparateChainingHashTableTest, GivenKeyAndValue_WhenInsert_ThenSizeIsIncremented) {
	const auto key {"Thirty Four"};
	const auto value {34};
	
	hashTable.insert(key, value);
	
	const auto size {hashTable.getSize()};
	EXPECT_THAT(size, testing::Eq(1));
}

TEST_F(EmptyStringToIntegerSeparateChainingHashTableTest, WhenResize_ThenTableSizeIsUpdated) {
	hashTable.resize(71);
	
	const auto size {hashTable.getTableSize()};
	EXPECT_THAT(size, testing::Eq(71));
}

TEST_F(EmptyStringToIntegerSeparateChainingHashTableTest, GivenKey_WhenRemove_ThenReturnsNullOptional) {
	const auto key {"Thirty Four"};
	const auto value {hashTable.remove(key)};
	
	EXPECT_THAT(value, testing::Eq(std::nullopt));
}

TEST_F(EmptyStringToIntegerSeparateChainingHashTableTest, GivenKey_WhenRemove_ThenSizeIsZero) {
	const auto key {"Thirty Four"};
	hashTable.remove(key);
	
	const auto size {hashTable.getSize()};
	EXPECT_THAT(size, testing::Eq(0));
}

TEST_F(EmptyStringToIntegerSeparateChainingHashTableTest, GivenKey_WhenFind_ThenReturnsNullOptional) {
	const auto key {"Thirty Four"};
	const auto value {hashTable.find(key)};
	
	EXPECT_THAT(value, testing::Eq(std::nullopt));
}

TEST_F(EmptyStringToIntegerSeparateChainingHashTableTest, GivenKey_WhenContains_ThenReturnsFalse) {
	const auto key {"Thirty Four"};
	const auto value {hashTable.contains(key)};
	
	EXPECT_THAT(value, testing::IsFalse());
}

TEST_F(EmptyStringToIntegerSeparateChainingHashTableTest, WhenIsEmpty_ThenReturnsTrue) {
	const auto value {hashTable.isEmpty()};
	
	EXPECT_THAT(value, testing::IsTrue());
}
}