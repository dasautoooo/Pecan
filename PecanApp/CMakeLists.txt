# Declare the PecanApp executable
add_executable(PecanApp
        src/PecanApp.cpp
)

# Link PecanApp with the Pecan library
target_link_libraries(PecanApp PRIVATE Pecan)

# macOS-specific settings
if(APPLE)
    target_compile_definitions(PecanApp PRIVATE PE_PLATFORM_MACOS)
    target_compile_options(PecanApp PRIVATE -Wall -Wextra -pedantic)  # Enable common warnings
endif()

# Debug configuration
if (CMAKE_BUILD_TYPE MATCHES Debug)
    target_compile_definitions(PecanApp PRIVATE PE_DEBUG)
    target_compile_options(PecanApp PRIVATE -O0)    # Disable optimization
    target_compile_options(PecanApp PRIVATE -g)     # Generate debug information
endif()

# Release configuration
if (CMAKE_BUILD_TYPE MATCHES Release)
    target_compile_definitions(PecanApp PRIVATE PE_RELEASE)
    target_compile_options(PecanApp PRIVATE -O3)    # Full optimization
    target_compile_options(PecanApp PRIVATE -g)     # Generate debug information
endif()

# Dist configuration
if (CMAKE_BUILD_TYPE MATCHES Dist)
    target_compile_definitions(PecanApp PRIVATE PE_DIST)
    target_compile_options(PecanApp PRIVATE -O3)    # Full optimization
    target_compile_options(PecanApp PRIVATE -s)     # Strip debug information
endif()

