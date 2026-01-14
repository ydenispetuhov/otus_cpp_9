cmake_minimum_required(VERSION 3.23.2)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(otus_cpp_9 VERSION ${PROJECT_VESRION})

file(GLOB CPP_SOURCES "src/*.cpp")
include_directories(${PROJECT_SOURCE_DIR}/include)
set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} ${CPP_SOURCES}
        include/reader.h
        include/storage.h
        include/writer.h
        include/processor.h
        src/FileWriter.cpp
        src/CommandProcessor.cpp
        src/ConsoleReader.cpp
        main.cpp
        lib/async.cpp
        src/StringReader.cpp
)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)