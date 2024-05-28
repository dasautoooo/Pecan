find_package(Vulkan REQUIRED)

find_package(glm CONFIG REQUIRED)

find_package(imgui CONFIG REQUIRED)

find_package(glfw3 CONFIG REQUIRED)

# Source files
file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.h")

# Add the library target
add_library(Pecan STATIC ${SOURCES})

# Set an absolute path to your project source directory
set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}
        ../vendor/stb_image)

target_include_directories(Pecan PUBLIC
        ${PROJECT_SOURCE_DIR}
)

target_link_libraries(Pecan PUBLIC glfw ${Vulkan_LIBRARIES} imgui::imgui glm::glm)

# Define configurations
set(CMAKE_CONFIGURATION_TYPES Debug Release Dist)

# macOS-specific settings
if(APPLE)
    target_compile_definitions(Pecan PRIVATE PE_PLATFORM_MACOS)
    target_compile_options(Pecan PRIVATE -Wall -Wextra -pedantic)  # Enable common warnings
endif()

# Debug configuration
if (CMAKE_BUILD_TYPE MATCHES Debug)
    target_compile_definitions(Pecan PRIVATE PE_DEBUG)
    target_compile_options(Pecan PRIVATE -O0)    # Disable optimization
    target_compile_options(Pecan PRIVATE -g)     # Generate debug information
endif()

# Release configuration
if (CMAKE_BUILD_TYPE MATCHES Release)
    target_compile_definitions(Pecan PRIVATE PE_RELEASE)
    target_compile_options(Pecan PRIVATE -O3)    # Full optimization
    target_compile_options(Pecan PRIVATE -g)     # Generate debug information
endif()

# Dist configuration
if (CMAKE_BUILD_TYPE MATCHES Dist)
    target_compile_definitions(Pecan PRIVATE PE_DIST)
    target_compile_options(Pecan PRIVATE -O3)    # Full optimization
    target_compile_options(Pecan PRIVATE -s)     # Strip debug information
endif()

