CMAKE_MINIMUM_REQUIRED(VERSION ${CMAKE_MINIMUM_REQUIRED_VERSION})

SET(SOURCE_FILES
		EmptyIntegerDynamicSizeArrayStackTest.cpp
		EmptyIntegerFixedSizeArrayStackTest.cpp
		EmptyIntegerSinglyLinkedListStackTest.cpp
		NonEmptyIntegerFixedSizeArrayStackTest.cpp
		NonEmptyIntegerDynamicSizeArrayStackTest.cpp
		NonEmptyIntegerSinglyLinkedListStackTest.cpp)

TARGET_SOURCES(${PROJECT_NAME} PRIVATE ${SOURCE_FILES})