cmake_minimum_required(VERSION 3.16)

project(lve)

set(CMAKE_CXX_STANDARD 17)

find_package(Vulkan REQUIRED)
#find_package(glm REQUIRED)
find_package(glfw3 REQUIRED)

file(GLOB lve_SRC
     "*.hpp"
     "*.cpp"
)

add_executable(${PROJECT_NAME} ${lve_SRC})

target_include_directories(${PROJECT_NAME} PUBLIC ${Vulkan_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} Vulkan::Vulkan glfw)
