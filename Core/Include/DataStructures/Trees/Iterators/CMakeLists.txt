CMAKE_MINIMUM_REQUIRED(VERSION 3.26)

SET(HEADER_FILES
		BinaryTreeConstInOrderIterator.hpp
		BinaryTreeConstPostOrderIterator.hpp
		BinaryTreeConstPreOrderIterator.hpp
		BinaryTreeInOrderIterator.hpp
		BinaryTreePostOrderIterator.hpp
		BinaryTreePreOrderIterator.hpp)

TARGET_SOURCES(${PROJECT_NAME} INTERFACE ${HEADER_FILES})
