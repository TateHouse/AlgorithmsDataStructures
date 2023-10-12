CMAKE_MINIMUM_REQUIRED(VERSION 3.26)

SET(HEADER_FILES
		DoublyLinkedListBidirectionalIterator.hpp
		DoublyLinkedListConstBidirectionalIterator.hpp
		DoublyLinkedListConstReverseBidirectionalIterator.hpp
		DoublyLinkedListReverseBidirectionalIterator.hpp
		SinglyLinkedListConstForwardIterator.hpp
		SinglyLinkedListConstForwardIterator.hpp)

TARGET_SOURCES(${PROJECT_NAME} INTERFACE ${HEADER_FILES})