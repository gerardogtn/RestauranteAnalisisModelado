project(restaurante)
cmake_minimum_required(VERSION 2.6)

include_directories($ENV{GMOCK_DIR}/include $ENV{GTEST_DIR}/include)
link_directories($ENV{GMOCK_DIR}/mybuild $ENV{GTEST_DIR}/mybuild)
add_definitions(-std=c++0x)
set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -Wall")

set(sources
   ../src/*/
   ../src/food/Drink.cpp
   ../src/stockorder/StockOrderKeyGenerator.cpp
   ../src/table/Table.cpp
   main.cpp)
set(testSources
    acceptance/BartenderAcceptanceTest.cpp
    stock/StockTest.cpp
    food/DrinkTest.cpp
    stockorder/StockOrderTest.cpp
    table/TableTest.cpp
    orders/ShelfTest.cpp
    )
add_executable(tests ${testSources} ${sources})
target_link_libraries(tests gmock)
target_link_libraries(tests gtest)
target_link_libraries(tests pthread)
