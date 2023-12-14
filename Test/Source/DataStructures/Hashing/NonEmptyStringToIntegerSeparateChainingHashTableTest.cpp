#include <gmock/gmock.h>

#include <memory>
#include <string>

#include "Algorithms/Hashing/DivisionMethodHashFunctionFactory.hpp"
#include "DataStructures/Hashing/SeparateChainingHashTable.hpp"

namespace Core::DataStructures::Hashing::Test {
class NonEmptyStringToIntegerSeparateChainingHashTableTest : public testing::Test {
public:
	NonEmptyStringToIntegerSeparateChainingHashTableTest() noexcept;
	virtual ~NonEmptyStringToIntegerSeparateChainingHashTableTest() noexcept = default;

protected:
	SeparateChainingHashTable<std::string, int> hashTable {11,
	                                                       std::make_unique<DivisionMethodHashFunctionFactory<std::string>>()};
};

NonEmptyStringToIntegerSeparateChainingHashTableTest::NonEmptyStringToIntegerSeparateChainingHashTableTest() noexcept {
	hashTable.insert("Thirty Four", 34);
	hashTable.insert("One Hundred Seven", 107);
	hashTable.insert("Two", 2);
	hashTable.insert("Fifty", 50);
};

TEST_F(NonEmptyStringToIntegerSeparateChainingHashTableTest, WhenConstForwardIterate_ThenIteratesOverAllElements) {
	const auto constHashTable {std::move(hashTable)};
	const auto begin {constHashTable.cbegin()};
	const auto end {constHashTable.cend()};
	
	std::vector<std::pair<std::string, int>> result {};
	for (auto iterator {begin}; iterator != end; ++iterator) {
		result.push_back(*iterator);
	}
	
	std::vector<std::pair<std::string, int>> expected {{"Thirty Four",       34},
	                                                   {"One Hundred Seven", 107},
	                                                   {"Two",               2},
	                                                   {"Fifty",             50}};
	
	EXPECT_THAT(result, testing::UnorderedElementsAreArray(expected));
}

TEST_F(NonEmptyStringToIntegerSeparateChainingHashTableTest, WhenForwardIterate_ThenIteratesOverAllElements) {
	const auto begin {hashTable.begin()};
	const auto end {hashTable.end()};
	
	std::vector<std::pair<std::string, int>> result {};
	for (auto iterator {begin}; iterator != end; ++iterator) {
		result.push_back(*iterator);
	}
	
	std::vector<std::pair<std::string, int>> expected {{"Thirty Four",       34},
	                                                   {"One Hundred Seven", 107},
	                                                   {"Two",               2},
	                                                   {"Fifty",             50}};
	
	EXPECT_THAT(result, testing::UnorderedElementsAreArray(expected));
}

TEST_F(NonEmptyStringToIntegerSeparateChainingHashTableTest, GivenKeyAndValue_WhenInsert_ThenSizeIsIncremented) {
	const auto key {"Ten"};
	const auto value {10};
	
	hashTable.insert(key, value);
	
	const auto size {hashTable.getSize()};
	EXPECT_THAT(size, testing::Eq(5));
}

TEST_F(NonEmptyStringToIntegerSeparateChainingHashTableTest,
       GivenEightKeysAndValues_WhenInsert_ThenTableSizeIsDoubled) {
	hashTable.insert("Ten", 10);
	hashTable.insert("Twenty", 20);
	hashTable.insert("Sixty Four", 64);
	hashTable.insert("One Hundred", 100);
	hashTable.insert("Nine", 9);
	
	const auto tableSize {hashTable.getTableSize()};
	EXPECT_THAT(tableSize, testing::Eq(22));
}

TEST_F(NonEmptyStringToIntegerSeparateChainingHashTableTest, GivenDuplicateKey_WhenInsert_ThenValueIsReplaced) {
	const auto key {"Fifty"};
	const auto value {100};
	
	hashTable.insert(key, value);
	
	const auto result {hashTable.find(key)};
	EXPECT_THAT(result, testing::Optional(value));
}

TEST_F(NonEmptyStringToIntegerSeparateChainingHashTableTest, GivenKey_WhenRemove_ThenReturnsValue) {
	const auto key {"Fifty"};
	const auto value {hashTable.remove(key)};
	
	EXPECT_THAT(value, testing::Optional(50));
};

TEST_F(NonEmptyStringToIntegerSeparateChainingHashTableTest, GivenKey_WhenRemove_ThenSizeIsIncremented) {
	const auto key {"Fifty"};
	hashTable.remove(key);
	
	const auto size {hashTable.getSize()};
	EXPECT_THAT(size, testing::Eq(3));
};

TEST_F(NonEmptyStringToIntegerSeparateChainingHashTableTest,
       GivenKeyThatDoesNotExist_WhenRemove_ThenSizeRemainsUnchanged) {
	const auto key {"Ten"};
	hashTable.remove(key);
	
	const auto size {hashTable.getSize()};
	EXPECT_THAT(size, testing::Eq(4));
};

TEST_F(NonEmptyStringToIntegerSeparateChainingHashTableTest, GivenKey_WhenRemove_ThenKeyValuePairIsRemoved) {
	const auto key {"Fifty"};
	hashTable.remove(key);
	
	const auto value {hashTable.find(key)};
	EXPECT_THAT(value, testing::Eq(std::nullopt));
};

TEST_F(NonEmptyStringToIntegerSeparateChainingHashTableTest, GivenKey_WhenFind_ThenReturnsValue) {
	const auto key {"Two"};
	const auto value {hashTable.find(key)};
	
	EXPECT_THAT(value, testing::Optional(2));
};

TEST_F(NonEmptyStringToIntegerSeparateChainingHashTableTest,
       GivenKeyThatDoesNotExist_WhenFind_ThenReturnsNullOptional) {
	const auto key {"Ten"};
	const auto value {hashTable.find(key)};
	
	EXPECT_THAT(value, testing::Eq(std::nullopt));
};

TEST_F(NonEmptyStringToIntegerSeparateChainingHashTableTest, GivenKey_WhenContains_ThenReturnsTrue) {
	const auto key {"Two"};
	const auto value {hashTable.contains(key)};
	
	EXPECT_THAT(value, testing::IsTrue());
};

TEST_F(NonEmptyStringToIntegerSeparateChainingHashTableTest, GivenKeyThatDoesNotExist_WhenContains_ThenReturnsFalse) {
	const auto key {"Ten"};
	const auto value {hashTable.contains(key)};
	
	EXPECT_THAT(value, testing::IsFalse());
};

TEST_F(NonEmptyStringToIntegerSeparateChainingHashTableTest, WhenIsEmpty_ThenReturnsFalse) {
	const auto value {hashTable.isEmpty()};
	
	EXPECT_THAT(value, testing::IsFalse());
};
}