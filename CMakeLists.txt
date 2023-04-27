cmake_minimum_required(VERSION 3.0.0)
# プロジェクト名
project(Example VERSION 0.1.0)

# include(CTest)
# enable_testing()


# C++標準の設定
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True) ## C++17であることを指定して、C++11以外のコンパイラを使うとエラーにする


# My Library
set(MY_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
add_library(mylib STATIC 
    ${MY_SOURCE_DIR}/CSVParser.cpp
    ${MY_SOURCE_DIR}/MyClass.cpp
)
target_include_directories(mylib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)


# buildターゲット（この場合はPROJECT_NAMEであるExampleに）main.cppを追加
add_executable(${PROJECT_NAME} ./main.cpp) 

# ライブラリをリンクする。
target_link_libraries(${PROJECT_NAME} mylib)


# Third paty library
# link liblo
# libloのインクルードディレクトリを指定
set(LIBLO_DIR ${CMAKE_CURRENT_SOURCE_DIR}/liblo)
include_directories(${LIBLO_DIR}/include)

# libloのライブラリを指定
add_library(liblo SHARED IMPORTED)
set_property(TARGET liblo PROPERTY 
    IMPORTED_LOCATION ${LIBLO_DIR}/lib/liblo.dylib)
target_link_libraries(${PROJECT_NAME} liblo)


## assetをコピーする
configure_file(${CMAKE_SOURCE_DIR}/data/sample.csv ${CMAKE_CURRENT_BINARY_DIR}/data/sample.csv COPYONLY)


get_target_property(headers ${PROJECT_NAME} SOURCES)
message(STATUS "headers : ${headers}") # これはあってもなくても良いけどメッセージを確認す

