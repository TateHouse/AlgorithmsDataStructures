CMAKE_MINIMUM_REQUIRED(VERSION 3.26)

SET(SOURCE_FILES
		BubbleSorterTest.cpp
		InsertionSorterTest.cpp
		MergeSorterTest.cpp
		QuickSorterTest.cpp
		SelectionSorterTest.cpp)

TARGET_SOURCES(${PROJECT_NAME} PRIVATE ${SOURCE_FILES})
