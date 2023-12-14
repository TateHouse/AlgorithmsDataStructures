CMAKE_MINIMUM_REQUIRED(VERSION 3.26)

SET(SOURCE_FILES
		IntegerDivisionMethodHashFunctionTest.cpp
		IntegerMultiplicationHashFunctionTest.cpp
		StringDivisionMethodHashFunctionTest.cpp)

TARGET_SOURCES(${PROJECT_NAME} PRIVATE ${SOURCE_FILES})
