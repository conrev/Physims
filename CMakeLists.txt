cmake_minimum_required(VERSION 3.16)

project(Physims)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} 
    PRIVATE
    # include source here
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/src/particle.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/src/world.cc

)

# Eigen
find_package (Eigen3 3.3 REQUIRED NO_MODULE)
 
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries (${PROJECT_NAME} PRIVATE Eigen3::Eigen)

