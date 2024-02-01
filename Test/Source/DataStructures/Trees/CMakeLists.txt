CMAKE_MINIMUM_REQUIRED(VERSION ${CMAKE_MINIMUM_REQUIRED_VERSION})

SET(SOURCE_FILES
		EmptyIntegerAVLTreeTest.cpp
		EmptyIntegerBinarySearchTreeTest.cpp
		EmptyIntegerBinaryTreeTest.cpp
		NonEmptyIntegerAVLTreeTest.cpp
		NonEmptyIntegerBinarySearchTreeTest.cpp
		NonEmptyIntegerBinaryTree.cpp)

TARGET_SOURCES(${PROJECT_NAME} PRIVATE ${SOURCE_FILES})
