cmake_minimum_required ( VERSION 3.0 )
project ( CrossPlatformTest )

# The version number.
set ( Project_VERSION_MAJOR 1 )
set ( Project_VERSION_MINOR 0 )


# resource location
set( RESOURCES_PATH "${PROJECT_SOURCE_DIR}/res"  )
set( LIBRARIES      "${PROJECT_SOURCE_DIR}/libs" )

set( CPT_SOURCE "${PROJECT_SOURCE_DIR}/src/main.cpp" )


# Create named folders for the sources within the .vcproj
# Empty name lists them directly under the .vcproj
source_group( "" FILES ${CPT_SOURCE} )

set( CMAKE_INSTALL_PREFIX ${PROJECT_BINARY_DIR} )
set( LIB_SUFFIX "bin" )

#
# add glfw3 functionality
#
set( GLFW_BUILD_DOCS     OFF CACHE BOOL "" FORCE )
set( GLFW_BUILD_TESTS    OFF CACHE BOOL "" FORCE )
set( GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE )

set( BUILD_SHARED_LIBS   ON  CACHE BOOL "" FORCE )

if ( WIN32 )
  set( USE_MSVC_RUNTIME_LIBRARY_DLL ON CACHE BOOL "" FORCE )
endif()

#
# glad
#
include_directories( SYSTEM ${LIBRARIES}/glad/include )
set( GLAD_SOURCE ${LIBRARIES}/glad/src/glad.c )


#
# glfw
#
add_subdirectory   ( ${LIBRARIES}/glfw )
include_directories( ${LIBRARIES}/glfw/include )

set ( EXTRA_LIBS  ${EXTRA_LIBS}  ${GLFW_LIBRARIES} )
set ( DEP_TARGETS ${DEP_TARGETS} glfw )



# compile flags
if ( NOT CMAKE_COMPILER_IS_GNUCXX )
  set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall" )
else()
  set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic -Wall -Wextra -Wcast-align -Wcast-qual"            )
  set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2"      )
  set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Winit-self -Wmissing-declarations -Wmissing-include-dirs"   )
  set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wold-style-cast -Woverloaded-virtual -Wredundant-decls"     )
  set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-overflow=5" )
  set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wswitch-default -Wundef -Werror -Wno-unused --std=c++11"    )
endif()


# # make project into library that can be used by multiple executables ( such as test classes )
# add_subdirectory( "${RESOURCES_PATH}" )
# add_library ( crossPlatformLib ${SOURCE} ${HEADERS} ${RES_FILES} )


add_executable (        crossPlatform ${CPT_SOURCE} ${GLAD_SOURCE} )
target_link_libraries ( crossPlatform ${EXTRA_LIBS} ${DEP_TARGETS} )
add_dependencies(       crossPlatform ${DEP_TARGETS}               )


# Creates a folder "executables" and adds target 
# project (crossPlatform.vcproj) under it
set_property( TARGET crossPlatform PROPERTY FOLDER "executables" )


# Adds logic to INSTALL.vcproj to copy crossPlatform.exe to destination directory
install (
         TARGETS crossPlatform
         RUNTIME DESTINATION bin
         )

install(
	    TARGETS crossPlatform
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        )

add_custom_command(
	               TARGET crossPlatform POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_if_different
                   "${PROJECT_BINARY_DIR}/libs/glfw/src/$<CONFIGURATION>/glfw3.dll"
                   $<TARGET_FILE_DIR:crossPlatform>
                   )

