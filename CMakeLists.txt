cmake_minimum_required(VERSION 3.16)

project(lve CXX)

set(CMAKE_CXX_STANDARD 17)

find_package(Vulkan REQUIRED)
find_package(glm REQUIRED)
find_package(glfw3 REQUIRED)

file(GLOB lve_SRC
     "*.hpp"
     "*.cpp"
)

add_executable(${PROJECT_NAME} ${lve_SRC})

target_include_directories(${PROJECT_NAME} PRIVATE ${Vulkan_INCLUDE_DIRS})
target_compile_definitions(${PROJECT_NAME} PRIVATE -D VK_ENABLE_BETA_EXTENSIONS)
target_compile_options(${PROJECT_NAME} PRIVATE -fsanitize=address)

target_link_options(${PROJECT_NAME} PRIVATE -fsanitize=address)
target_link_libraries(${PROJECT_NAME} Vulkan::Vulkan glfw glm::glm)
