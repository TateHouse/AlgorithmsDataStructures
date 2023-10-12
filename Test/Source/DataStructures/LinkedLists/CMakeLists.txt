CMAKE_MINIMUM_REQUIRED(VERSION 3.26)

SET(SOURCE_FILES
		EmptyIntegerDoublyLinkedListTest.cpp
		EmptyIntegerSinglyLinkedListTest.cpp
		NonEmptyIntegerSinglyLinkedListTest.cpp)

TARGET_SOURCES(${PROJECT_NAME} PRIVATE ${SOURCE_FILES})