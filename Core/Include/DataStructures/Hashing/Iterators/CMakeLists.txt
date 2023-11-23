CMAKE_MINIMUM_REQUIRED(VERSION 3.26)

SET(HEADER_FILES
		SeparateChainingHashTableConstForwardIterator.hpp
		SeparateChainingHashTableForwardIterator.hpp)

TARGET_SOURCES(${PROJECT_NAME} INTERFACE ${HEADER_FILES})
