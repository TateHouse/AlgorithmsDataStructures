CMAKE_MINIMUM_REQUIRED(VERSION 3.26)

SET(HEADER_FILES
		DivisionMethodHashFunction.hpp
		DivisionMethodHashFunctionFactory.hpp
		HashConcepts.hpp
		HashFunction.hpp
		HashFunctionFactory.hpp
		MultiplicationMethodHashFunction.hpp
		MultiplicationMethodHashFunctionFactory.hpp)

TARGET_SOURCES(${PROJECT_NAME} PRIVATE ${HEADER_FILES})
