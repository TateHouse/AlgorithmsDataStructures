CMAKE_MINIMUM_REQUIRED(VERSION 3.26)

SET(SOURCE_FILES)

TARGET_SOURCES(${PROJECT_NAME} PRIVATE ${SOURCE_FILES})

ADD_SUBDIRECTORY(Hashing)
ADD_SUBDIRECTORY(Sorting)
