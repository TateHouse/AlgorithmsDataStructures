CMAKE_MINIMUM_REQUIRED(VERSION 3.26)

SET(HEADER_FILES
		ArrayOrVectorConcept.hpp
		BubbleSorter.hpp
		InsertionSorter.hpp
		MergeSorter.hpp
		QuickSorter.hpp
		SortingAlgorithm.hpp)

TARGET_SOURCES(${PROJECT_NAME} PRIVATE ${HEADER_FILES})