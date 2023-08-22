# Generic test that uses conan libs
SET(PROJECT_NAME ThermocoupleCalculatorExample)
ADD_EXECUTABLE(${PROJECT_NAME} main.cpp)
TARGET_LINK_LIBRARIES(${PROJECT_NAME}
                      PRIVATE project_options
                      project_warnings
                      fmt::fmt)

TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME} PRIVATE ../include)

ADD_CUSTOM_COMMAND(TARGET ${PROJECT_NAME} POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${PROJECT_NAME}> ${CMAKE_BINARY_DIR}/install/bin/$<TARGET_FILE_NAME:${PROJECT_NAME}>)

ADD_CUSTOM_COMMAND(TARGET ${PROJECT_NAME} POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/include ${CMAKE_BINARY_DIR}/install/include)
