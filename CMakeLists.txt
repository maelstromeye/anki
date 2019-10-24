cmake_minimum_required(VERSION 3.15)
project(anki)


set(CMAKE_CXX_STANDARD 14)

find_package(Boost 1.61.0 COMPONENTS system filesystem serialization REQUIRED)




if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(anki main.cpp)
    target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
endif()
