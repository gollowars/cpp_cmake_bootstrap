cmake_minimum_required(VERSION 3.0.0)
# プロジェクト名
project(Example VERSION 0.1.0)

# include(CTest)
# enable_testing()


# C++標準の設定
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True) ## C++11であることを指定して、C++11以外のコンパイラを使うとエラーにする



# buildターゲット（この場合はPROJECT_NAMEであるExampleに）main.cppを追加
add_executable(${PROJECT_NAME} ./src/main.cpp) 

# ヘッダーファイルの読み込み
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

## ソースファイルを追加する 
set(MY_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_sources(${PROJECT_NAME} PRIVATE 
    ${MY_SOURCE_DIR}/MyClass.cpp
    ${MY_SOURCE_DIR}/CSVParser.cpp
)


## assetをコピーする
configure_file(${CMAKE_SOURCE_DIR}/data/sample.csv ${CMAKE_CURRENT_BINARY_DIR}/data/sample.csv COPYONLY)


get_target_property(headers ${PROJECT_NAME} SOURCES)
message(STATUS "headers : ${headers}")

