cmake_minimum_required ( VERSION 3.0 )
project ( Project )

# The version number.
set ( Project_VERSION_MAJOR 1 )
set ( Project_VERSION_MINOR 0 )



# resource location
set( RESOURCES_PATH "${PROJECT_SOURCE_DIR}/res"  )
set( LIBRARIES      "${PROJECT_SOURCE_DIR}/libs" )

#
# can't continue without third party libs
#
if ( NOT EXISTS ${LIBRARIES} )

    message( FATAL "Couldn't find the commonLibs directory. Make sure the it is linked correctly." )

endif(  )


# add glfw3 functionality
set( GLFW_BUILD_DOCS     OFF CACHE BOOL "" FORCE )
set( GLFW_BUILD_TESTS    OFF CACHE BOOL "" FORCE )
set( GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE )

add_subdirectory( ${LIBRARIES}/glfw )
set ( EXTRA_LIBS  ${EXTRA_LIBS}  ${GLFW_LIBRARIES} )
set ( DEP_TARGETS ${DEP_TARGETS} glfw )


# compile flags
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic -Wall -Wextra -Wcast-align -Wcast-qual"            )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2"      )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Winit-self -Wmissing-declarations -Wmissing-include-dirs"   )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wold-style-cast -Woverloaded-virtual -Wredundant-decls"     )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-overflow=5" )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wswitch-default -Wundef -Werror -Wno-unused --std=c++11"    )


# # make project into library that can be used by multiple executables ( such as test classes )
# add_subdirectory( "${RESOURCES_PATH}" )
# add_library ( ${PROJECT_NAME}Lib ${SOURCE} ${HEADERS} ${RES_FILES} )


add_executable (        ${PROJECT_NAME} "${PROJECT_SOURCE_DIR}/src/main.cpp" )
target_link_libraries ( ${PROJECT_NAME} ${EXTRA_LIBS} ${DEP_TARGETS}         )
add_dependencies(       ${PROJECT_NAME} ${DEP_TARGETS}                       )
