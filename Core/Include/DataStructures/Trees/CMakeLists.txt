CMAKE_MINIMUM_REQUIRED(VERSION 3.26)

SET(HEADER_FILES
		AVLTree.hpp
		BinarySearchTree.hpp
		BinarySearchTreeConcepts.hpp
		BinaryTree.hpp
		BinaryTreeNode.hpp)

TARGET_SOURCES(${PROJECT_NAME} INTERFACE ${HEADER_FILES})

ADD_SUBDIRECTORY(Iterators)