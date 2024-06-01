cmake_minimum_required(VERSION 3.5)
project(asterisk-ari-curl)

set(CMAKE_CXX_STANDARD 17)


# Set the path to the vcpkg toolchain file
set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")


# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# List of source files explicitly
file(GLOB SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)

# Add an executable
add_executable(asterisk-ari-curl src/main.cpp)


# Find and link Boost libraries
find_package(Boost REQUIRED COMPONENTS program_options)
if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(asterisk-ari-curl Boost::program_options)
endif()

# Find and link nlohmann_json
#find_package(nlohmann_json CONFIG REQUIRED)
if(nlohmann_json_FOUND)
    include_directories(${nlohmann_json_INCLUDE_DIRS})
    target_link_libraries(asterisk-ari-curl nlohmann_json::nlohmann_json)
endif()

# Find and link jsoncpp
find_package(jsoncpp CONFIG REQUIRED)
if (jsoncpp_FOUND)
    include_directories(${jsoncpp_INCLUDE_DIRS})
    target_link_libraries(asterisk-ari-curl JsonCpp::JsonCpp)
endif()




# Find and link libcurl
find_package(CURL REQUIRED)
if (CURL_FOUND)
    include_directories(${CURL_INCLUDE_DIRS})
    target_link_libraries(asterisk-ari-curl ${CURL_LIBRARIES})
endif()

