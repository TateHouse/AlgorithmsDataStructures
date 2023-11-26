#include <gmock/gmock.h>

#include "DataStructures/Hashing/MultiplicationMethodHashFunction.hpp"

namespace Core::DataStructures::Hashing::Test {
class IntegerMultiplicationMethodHashFunctionTest : public testing::Test {
public:
	IntegerMultiplicationMethodHashFunctionTest() noexcept = default;
	virtual ~IntegerMultiplicationMethodHashFunctionTest() noexcept = default;

protected:
	MultiplicationMethodHashFunction<int> hashFunction {11};
};

TEST_F(IntegerMultiplicationMethodHashFunctionTest, GivenSameInteger_WhenHash_ThenReturnsSameHash) {
	const auto key {34};
	
	const auto firstHash {hashFunction(key)};
	const auto secondHash {hashFunction(key)};
	
	EXPECT_THAT(firstHash, testing::Eq(secondHash));
}

TEST_F(IntegerMultiplicationMethodHashFunctionTest, GivenDifferentIntegers_WhenHash_ThenReturnsDifferentHashes) {
	const auto firstKey {1};
	const auto secondKey {2};
	
	const auto firstHash {hashFunction(firstKey)};
	const auto secondHash {hashFunction(secondKey)};
	
	EXPECT_THAT(firstHash, testing::Ne(secondHash));
}

TEST_F(IntegerMultiplicationMethodHashFunctionTest, GivenNegativeInteger_WhenHash_ThenReturnsNonNegativeHash) {
	const auto key {-34};
	
	const auto hash {hashFunction(key)};
	
	EXPECT_THAT(hash, testing::Ge(0));
}

TEST_F(IntegerMultiplicationMethodHashFunctionTest, GivenZeroMultiplier_WhenConstruct_ThenThrowsInvalidArgument) {
	const auto tableSize {11};
	
	EXPECT_THROW(MultiplicationMethodHashFunction<int>(tableSize, 0.0f), std::invalid_argument);
}

TEST_F(IntegerMultiplicationMethodHashFunctionTest, GivenOneMultiplier_WhenConstruct_ThenThrowsInvalidArgument) {
	const auto tableSize {11};
	
	EXPECT_THROW(MultiplicationMethodHashFunction<int>(tableSize, 1.0f), std::invalid_argument);
}
}