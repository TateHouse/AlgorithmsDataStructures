#include <gmock/gmock.h>

#include <string>

#include "DataStructures/Hashing/DivisionMethodHashFunctionFactory.hpp"
#include "DataStructures/Hashing/SeparateChainingHashTable.hpp"

namespace Core::DataStructures::Hashing::Test {
class EmptyStringToIntegerSeparateChainingHashTableTest : public testing::Test {
public:
	EmptyStringToIntegerSeparateChainingHashTableTest() noexcept = default;
	virtual ~EmptyStringToIntegerSeparateChainingHashTableTest() noexcept = default;
	
protected:
	DivisionMethodHashFunctionFactory<std::string> hashFunctionFactory {};
	SeparateChainingHashTable<std::string, int> hashTable {11, hashFunctionFactory};
};

TEST_F(EmptyStringToIntegerSeparateChainingHashTableTest, GivenKeyAndValue_WhenInsert_ThenSizeIsIncremented) {
	const auto key {"Thirty Four"};
	const auto value {34};
	
	hashTable.insert(key, value);
	
	const auto size {hashTable.getSize()};
	EXPECT_THAT(size, testing::Eq(1));
}
}