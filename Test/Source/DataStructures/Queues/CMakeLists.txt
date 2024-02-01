CMAKE_MINIMUM_REQUIRED(VERSION ${CMAKE_MINIMUM_REQUIRED_VERSION})

SET(SOURCE_FILES
		EmptyIntegerDynamicSizeArrayQueueTest.cpp
		EmptyIntegerFixedSizeCircularArrayQueueTest.cpp
		EmptyIntegerSinglyLinkedListQueueTest.cpp
		NonEmptyIntegerDynamicSizeArrayQueueTest.cpp
		NonEmptyIntegerFixedSizeCircularArrayQueueTest.cpp
		NonEmptyIntegerSinglyLinkedListQueueTest.cpp)

TARGET_SOURCES(${PROJECT_NAME} PRIVATE ${SOURCE_FILES})
