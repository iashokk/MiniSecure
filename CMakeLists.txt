cmake_minimum_required(VERSION 3.15)
project(MiniSecure LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
add_library(minisec
  src/handshake.cpp src/crypto.cpp src/session.cpp src/transport_sim.cpp
)
target_include_directories(minisec PUBLIC include)
add_executable(minisec_demo src/main.cpp)
target_link_libraries(minisec_demo minisec)
add_executable(minisec_tests tests/test_scenarios.cpp)
target_link_libraries(minisec_tests minisec)
