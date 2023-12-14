#include "gmock/gmock.h"

#include "Algorithms/Hashing/DivisionMethodHashFunction.hpp"

namespace Core::DataStructures::Hashing::Test {
class IntegerDivisionMethodHashFunctionTest : public testing::Test {
public:
	IntegerDivisionMethodHashFunctionTest() noexcept = default;
	virtual ~IntegerDivisionMethodHashFunctionTest() noexcept = default;

protected:
	DivisionMethodHashFunction<int> hashFunction {11};
};

TEST_F(IntegerDivisionMethodHashFunctionTest, GivenSameInteger_WhenHash_ThenReturnsSameHash) {
	const auto key {34};
	
	const auto firstHash {hashFunction(key)};
	const auto secondHash {hashFunction(key)};
	
	EXPECT_THAT(firstHash, testing::Eq(secondHash));
}

TEST_F(IntegerDivisionMethodHashFunctionTest, GivenDifferentIntegers_WhenHash_ThenReturnsDifferentHashes) {
	const auto firstKey {34};
	const auto secondKey {107};
	
	const auto firstHash {hashFunction(firstKey)};
	const auto secondHash {hashFunction(secondKey)};
	
	EXPECT_THAT(firstHash, testing::Ne(secondHash));
}

TEST_F(IntegerDivisionMethodHashFunctionTest, GivenNegativeInteger_WhenHash_ThenReturnsNonNegativeHash) {
	const auto key {-34};
	
	const auto hash {hashFunction(key)};
	
	EXPECT_THAT(hash, testing::Ge(0));
}
}