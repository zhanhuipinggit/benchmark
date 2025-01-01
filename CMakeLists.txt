cmake_minimum_required(VERSION 3.15)
project(WebSocketTest)

# 设置 C++ 标准（可选）
set(CMAKE_C_STANDARD 11)

# 添加项目源文件
add_executable(WebSocketTest main.c)


# 查找 libwebsockets 库
find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBWEBSOCKETS REQUIRED libwebsockets)

# 添加 include 路径和链接库
include_directories(${LIBWEBSOCKETS_INCLUDE_DIRS})
link_directories(${LIBWEBSOCKETS_LIBRARY_DIRS})
add_definitions(${LIBWEBSOCKETS_CFLAGS_OTHER})

# 链接 libwebsockets 到目标程序
target_link_libraries(WebSocketTest ${LIBWEBSOCKETS_LIBRARIES})
