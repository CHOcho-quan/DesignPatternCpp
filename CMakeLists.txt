project(DesignPatternCpp)

set(CMAKE_CXX_STANDARD 11)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

message(STATUS ${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(Singleton ${CMAKE_SOURCE_DIR}/src/Singleton.cpp)

add_executable(TemplateMethod ${CMAKE_SOURCE_DIR}/src/TemplateMethod.cpp)

add_executable(Strategy ${CMAKE_SOURCE_DIR}/src/Strategy.cpp)

add_executable(Observer ${CMAKE_SOURCE_DIR}/src/Observer.cpp)

add_executable(Decorator ${CMAKE_SOURCE_DIR}/src/Decorator.cpp)

add_executable(Bridge ${CMAKE_SOURCE_DIR}/src/Bridge.cpp)

add_executable(FactoryMethod ${CMAKE_SOURCE_DIR}/src/FactoryMethod.cpp)

add_executable(AbstractFactory ${CMAKE_SOURCE_DIR}/src/AbstractFactory.cpp)

add_executable(Prototype ${CMAKE_SOURCE_DIR}/src/Prototype.cpp)

add_executable(Builder ${CMAKE_SOURCE_DIR}/src/Builder.cpp)

add_executable(Flyweight ${CMAKE_SOURCE_DIR}/src/Flyweight.cpp)

add_executable(Facade ${CMAKE_SOURCE_DIR}/src/Facade.cpp)

add_executable(Adapter ${CMAKE_SOURCE_DIR}/src/Adapter.cpp)
