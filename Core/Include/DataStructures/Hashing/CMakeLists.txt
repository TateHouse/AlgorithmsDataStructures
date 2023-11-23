CMAKE_MINIMUM_REQUIRED(VERSION 3.26)

SET(HEADER_FILES
		DivisionMethodHashFunction.hpp
		DivisionMethodHashFunctionFactory.hpp
		HashConcepts.hpp
		HashFunction.hpp
		HashFunctionFactory.hpp)

TARGET_SOURCES(${PROJECT_NAME} INTERFACE ${HEADER_FILES})
