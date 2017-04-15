find_path(GBA_INCLUDE_DIR
    NAMES gba.h
    HINTS /opt/devkitpro/libgba/include)

find_library(GBA_LIBRARY
    NAMES libgba.a
    HINTS /opt/devkitpro/libgba/lib)

message(STATUS "GBA_INCLUDE_DIR: ${GBA_INCLUDE_DIR}")
message(STATUS "GBA_LIBRARY: ${GBA_LIBRARY}")

include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(GBA
                                  REQUIRED_VARS GBA_LIBRARY GBA_INCLUDE_DIR)

if(GBA_FOUND)
  set( GBA_LIBRARIES ${GBA_LIBRARY} )
  set( GBA_INCLUDE_DIRS ${GBA_INCLUDE_DIR} )
endif()

mark_as_advanced(GBA_INCLUDE_DIR GBA_LIBRARY)
