CMAKE_MINIMUM_REQUIRED(VERSION ${CMAKE_MINIMUM_REQUIRED_VERSION})

SET(HEADER_FILES
		DivisionMethodHashFunction.hpp
		DivisionMethodHashFunctionFactory.hpp
		HashConcepts.hpp
		HashFunction.hpp
		HashFunctionFactory.hpp
		MultiplicationMethodHashFunction.hpp
		MultiplicationMethodHashFunctionFactory.hpp)

TARGET_SOURCES(${PROJECT_NAME} PRIVATE ${HEADER_FILES})
