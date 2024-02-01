CMAKE_MINIMUM_REQUIRED(VERSION ${CMAKE_MINIMUM_REQUIRED_VERSION})

SET(HEADER_FILES
		ArrayOrVectorConcept.hpp
		BubbleSorter.hpp
		InsertionSorter.hpp
		MergeSorter.hpp
		QuickSorter.hpp
		SelectionSorter.hpp
		SortingAlgorithm.hpp)

TARGET_SOURCES(${PROJECT_NAME} PRIVATE ${HEADER_FILES})