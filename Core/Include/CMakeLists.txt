CMAKE_MINIMUM_REQUIRED(VERSION 3.26)

SET(HEADER_FILES)

TARGET_SOURCES(${PROJECT_NAME} PRIVATE ${HEADER_FILES})

ADD_SUBDIRECTORY(Algorithms)
ADD_SUBDIRECTORY(DataStructures)