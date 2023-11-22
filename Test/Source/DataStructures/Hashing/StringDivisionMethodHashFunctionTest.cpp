#include <gmock/gmock.h>

#include <string>

#include "DataStructures/Hashing/DivisionMethodHashFunction.hpp"

namespace Core::DataStructures::Hashing::Test {
class StringDivisionMethodHashFunctionTest : public testing::Test {
public:
	StringDivisionMethodHashFunctionTest() noexcept = default;
	virtual ~StringDivisionMethodHashFunctionTest() noexcept = default;

protected:
	DivisionMethodHashFunction<std::string> hashFunction {11};
};

TEST_F(StringDivisionMethodHashFunctionTest, GivenSameString_WhenHash_ThenReturnsSameHash) {
	const auto key {"Hello"};
	
	const auto firstHash {hashFunction(key)};
	const auto secondHash {hashFunction(key)};
	
	EXPECT_THAT(firstHash, testing::Eq(secondHash));
}

TEST_F(StringDivisionMethodHashFunctionTest, GivenDifferentStrings_WhenHash_ThenReturnsDifferentHashes) {
	const auto firstKey {"Hello"};
	const auto secondKey {"World"};
	
	const auto firstHash {hashFunction(firstKey)};
	const auto secondHash {hashFunction(secondKey)};
	
	EXPECT_THAT(firstHash, testing::Ne(secondHash));
}

TEST_F(StringDivisionMethodHashFunctionTest, GivenEmptyString_WhenHash_ThenReturnsNonNegativeHash) {
	const auto key {""};
	
	const auto hash {hashFunction(key)};
	
	EXPECT_THAT(hash, testing::Ge(0));
}
}