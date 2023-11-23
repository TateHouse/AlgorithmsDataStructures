#include <gmock/gmock.h>

#include <memory>
#include <string>

#include "DataStructures/Hashing/DivisionMethodHashFunctionFactory.hpp"
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

TEST_F(NonEmptyStringToIntegerSeparateChainingHashTableTest, GivenKeyAndValue_WhenInsert_ThenSizeIsIncremented) {
	const auto key {"Ten"};
	const auto value {10};
	
	hashTable.insert(key, value);
	
	const auto size {hashTable.getSize()};
	EXPECT_THAT(size, testing::Eq(5));
}

TEST_F(NonEmptyStringToIntegerSeparateChainingHashTableTest, GivenEightKeysAndValues_WhenInsert_ThenTableSizeIsDoubled) {
	hashTable.insert("Ten", 10);
	hashTable.insert("Twenty", 20);
	hashTable.insert("Sixty Four", 64);
	hashTable.insert("One Hundred", 100);
	hashTable.insert("Nine", 9);
	
	const auto tableSize {hashTable.getTableSize()};
	EXPECT_THAT(tableSize, testing::Eq(22));
}

TEST_F(NonEmptyStringToIntegerSeparateChainingHashTableTest, GivenKey_WhenFind_ThenReturnsValue) {
	const auto key {"Two"};
	const auto value {hashTable.find(key)};
	
	EXPECT_THAT(value, testing::Optional(2));
};

TEST_F(NonEmptyStringToIntegerSeparateChainingHashTableTest, GivenKeyThatDoesNotExist_WhenFind_ThenReturnsNullOptional) {
	const auto key {"Ten"};
	const auto value {hashTable.find(key)};
	
	EXPECT_THAT(value, testing::Eq(std::nullopt));
};
}