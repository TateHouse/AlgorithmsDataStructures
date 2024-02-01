CMAKE_MINIMUM_REQUIRED(VERSION ${CMAKE_MINIMUM_REQUIRED_VERSION})

SET(SOURCE_FILES
		IntegerDivisionMethodHashFunctionTest.cpp
		IntegerMultiplicationHashFunctionTest.cpp
		StringDivisionMethodHashFunctionTest.cpp)

TARGET_SOURCES(${PROJECT_NAME} PRIVATE ${SOURCE_FILES})
