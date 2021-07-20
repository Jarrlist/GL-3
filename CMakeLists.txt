cmake_minimum_required(VERSION 3.20.5)
project(GL-3)

set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib")
set(SOURCES "${SRC_DIR}/main.c")

add_subdirectory(${SRC_DIR})
add_subdirectory(${LIB_DIR}/glfw/)
#add_subdirectory(lib/glad/)

add_executable(${PROJECT_NAME} ${SOURCES})

add_library(glad ${LIB_DIR}/glad/src/glad.c)
target_include_directories(glad PRIVATE ${LIB_DIR}/glad/include)
# include_directories(${LIB_DIR}/glfw/include)

target_include_directories(${PROJECT_NAME} 
    PUBLIC ${SRC_DIR}
    PRIVATE ${LIB_DIR}/glad/include 
    PRIVATE ${LIB_DIR}/glfw/include
)

#target_link_directories(${PROJECT_NAME} 
#    PRIVATE src
#    PRIVATE lib/glad
#    PRIVATE lib/glfw/src
#)

target_link_libraries(${PROJECT_NAME} 
    PRIVATE src
    PRIVATE glad ${CMAKE_DL_LIBS}
    PRIVATE glfw3
)

# glad