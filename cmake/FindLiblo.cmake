set(LIBLO_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/liblo/include")
if(APPLE)
    set(LIBLO_LIBRARY "${CMAKE_CURRENT_SOURCE_DIR}/liblo/lib/liblo.dylib")
elseif(WIN32)
    set(LIBLO_LIBRARY "${CMAKE_CURRENT_SOURCE_DIR}/liblo/lib/liblo.dll")
elseif(UNIX)
    set(LIBLO_LIBRARY "${CMAKE_CURRENT_SOURCE_DIR}/liblo/lib/liblo.so")
else()
    message(FATAL_ERROR "Unsupported operating system")
endif()

if (LIBLO_INCLUDE_DIR AND LIBLO_LIBRARY)
    set(Liblo_FOUND TRUE)
else()
    set(Liblo_FOUND FALSE)
endif()

if (Liblo_FOUND)
    message(STATUS "Found Liblo: ${LIBLO_LIBRARY}")

    add_library(liblo SHARED IMPORTED)
    set_target_properties(liblo PROPERTIES
        IMPORTED_LOCATION "${LIBLO_LIBRARY}"
        INTERFACE_INCLUDE_DIRECTORIES "${LIBLO_INCLUDE_DIR}"
    )
else()
    message(FATAL_ERROR "Liblo not found")
endif()