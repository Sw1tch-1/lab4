cmake_minimum_required(VERSION 3.10)
project(ClientServer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Проверяем ОС
if (WIN32)
    set(Boost_USE_STATIC_LIBS ON)
elseif (APPLE)
    set(Boost_INCLUDE_DIR /opt/homebrew/include)
endif()

find_package(Boost REQUIRED COMPONENTS system)
include_directories(${Boost_INCLUDE_DIRS})

# Компиляция сервера
add_executable(server server/server.cpp)
target_link_libraries(server Boost::system)

# Компиляция клиента
add_executable(client client/client.cpp)
target_link_libraries(client Boost::system)
