CMAKE_MINIMUM_REQUIRED(VERSION ${CMAKE_MINIMUM_REQUIRED_VERSION})

SET(HEADER_FILES
		ArrayOrVectorConcept.hpp)

TARGET_SOURCES(${PROJECT_NAME} PRIVATE ${HEADER_FILES})

ADD_SUBDIRECTORY(Hashing)
ADD_SUBDIRECTORY(Searching)
ADD_SUBDIRECTORY(Sorting)