CMAKE_MINIMUM_REQUIRED(VERSION 3.26)

SET(HEADER_FILES
		DoublyLinkedList.hpp
		DoublyLinkedListNode.hpp
		SinglyLinkedList.hpp
		SinglyLinkedListNode.hpp)

TARGET_SOURCES(${PROJECT_NAME} INTERFACE ${HEADER_FILES})

ADD_SUBDIRECTORY(Iterators)