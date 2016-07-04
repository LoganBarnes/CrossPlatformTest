# A list of all the resource files so they show up
# in the project tree when using Qt Creator
set( 
	RES_FILES
    ${RES_FILES}
    
    # shaders
    "${CMAKE_CURRENT_SOURCE_DIR}/shaders/default.vert"
    "${CMAKE_CURRENT_SOURCE_DIR}/shaders/default.frag"
    
    PARENT_SCOPE
)

