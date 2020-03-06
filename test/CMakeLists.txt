PROJECT(Test)
CMAKE_MINIMUM_REQUIRED(VERSION 3.15)

ADD_EXECUTABLE(${PROJECT_NAME} typeK-test.cpp typeE-test.cpp typeB-test.cpp typeJ-test.cpp typeN-test.cpp typeR-test.cpp typeS-test.cpp typeT-test.cpp)
TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME} PRIVATE ${catch2_SOURCE_DIR}/single_include ${CMAKE_CURRENT_SOURCE_DIR}/../include)