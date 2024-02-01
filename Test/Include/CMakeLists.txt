CMAKE_MINIMUM_REQUIRED(VERSION ${CMAKE_MINIMUM_REQUIRED_VERSION})

SET(HEADER_FILES
		IntegerPredicates.hpp
		SortedIntegerData.hpp
		SortedStringData.hpp
		UnsortedIntegerData.hpp
		UnsortedStringData.hpp)

TARGET_SOURCES(${PROJECT_NAME} PRIVATE ${HEADER_FILES})