CMAKE_MINIMUM_REQUIRED(VERSION ${CMAKE_MINIMUM_REQUIRED_VERSION})

SET(HEADER_FILES
		BinaryTreeConstInOrderIterator.hpp
		BinaryTreeConstLevelOrderIterator.hpp
		BinaryTreeConstPostOrderIterator.hpp
		BinaryTreeConstPreOrderIterator.hpp
		BinaryTreeInOrderIterator.hpp
		BinaryTreeIteratorConcepts.hpp
		BinaryTreeLevelOrderIterator.hpp
		BinaryTreePostOrderIterator.hpp
		BinaryTreePreOrderIterator.hpp)

TARGET_SOURCES(${PROJECT_NAME} INTERFACE ${HEADER_FILES})
