CMAKE_MINIMUM_REQUIRED(VERSION ${CMAKE_MINIMUM_REQUIRED_VERSION})

SET(HEADER_FILES
		DoublyLinkedListBidirectionalIterator.hpp
		DoublyLinkedListConstBidirectionalIterator.hpp
		DoublyLinkedListConstReverseBidirectionalIterator.hpp
		DoublyLinkedListReverseBidirectionalIterator.hpp
		SinglyLinkedListConstForwardIterator.hpp
		SinglyLinkedListConstForwardIterator.hpp)

TARGET_SOURCES(${PROJECT_NAME} INTERFACE ${HEADER_FILES})