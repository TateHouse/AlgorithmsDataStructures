CMAKE_MINIMUM_REQUIRED(VERSION 3.26)

SET(SOURCE_FILES
		EmptyIntegerDynamicSizeArrayStackTest.cpp
		EmptyIntegerFixedSizeArrayStackTest.cpp
		EmptyIntegerSinglyLinkedListStackTest.cpp
		NonEmptyIntegerFixedSizeArrayStackTest.cpp
		NonEmptyIntegerDynamicSizeArrayStackTest.cpp
		NonEmptyIntegerSinglyLinkedListStackTest.cpp)

TARGET_SOURCES(${PROJECT_NAME} PRIVATE ${SOURCE_FILES})