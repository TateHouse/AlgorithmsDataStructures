CMAKE_MINIMUM_REQUIRED(VERSION 3.26)

SET(SOURCE_FILES
		EmptyIntegerDynamicSizeArrayQueueTest.cpp
		EmptyIntegerFixedSizeCircularArrayQueueTest.cpp
		NonEmptyIntegerFixedSizeCircularArrayQueueTest.cpp)

TARGET_SOURCES(${PROJECT_NAME} PRIVATE ${SOURCE_FILES})
