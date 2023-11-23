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

TEST_F(EmptyStringToIntegerSeparateChainingHashTableTest, GivenKeyAndValue_WhenInsert_ThenSizeIsIncremented) {
	const auto key {"Thirty Four"};
	const auto value {34};
	
	hashTable.insert(key, value);
	
	const auto size {hashTable.getSize()};
	EXPECT_THAT(size, testing::Eq(1));
}

TEST_F(EmptyStringToIntegerSeparateChainingHashTableTest, WhenResize_ThenTableSizeIsZero) {
	hashTable.resize(0);
	
	const auto size {hashTable.getSize()};
	EXPECT_THAT(size, testing::Eq(0));
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
}