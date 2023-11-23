CMAKE_MINIMUM_REQUIRED(VERSION 3.26)

SET(SOURCE_FILES
		EmptyStringToIntegerSeparateChainingHashTableTest.cpp
		IntegerDivisionMethodHashFunctionTest.cpp
		NonEmptyStringToIntegerSeparateChainingHashTableTest.cpp
		StringDivisionMethodHashFunctionTest.cpp)

TARGET_SOURCES(${PROJECT_NAME} PRIVATE ${SOURCE_FILES})
