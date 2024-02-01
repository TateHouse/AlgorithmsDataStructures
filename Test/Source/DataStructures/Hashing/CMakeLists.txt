CMAKE_MINIMUM_REQUIRED(VERSION ${CMAKE_MINIMUM_REQUIRED_VERSION})

SET(SOURCE_FILES
		EmptyStringToIntegerSeparateChainingHashTableTest.cpp
		../../Algorithms/Hashing/IntegerDivisionMethodHashFunctionTest.cpp
		../../Algorithms/Hashing/IntegerMultiplicationHashFunctionTest.cpp
		NonEmptyStringToIntegerSeparateChainingHashTableTest.cpp
		../../Algorithms/Hashing/StringDivisionMethodHashFunctionTest.cpp)

TARGET_SOURCES(${PROJECT_NAME} PRIVATE ${SOURCE_FILES})
