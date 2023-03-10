execute_process(
    COMMAND ${PYTHON_EXECUTABLE} -c "import distutils.sysconfig; print (distutils.sysconfig.get_python_lib(plat_specific=True, prefix=\"\"))"
    OUTPUT_VARIABLE CEGUI_INSTALL_PYTHON_DIR
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

set( CEGUI_INSTALL_PYTHON_DIR "${CEGUI_INSTALL_PYTHON_DIR}/${CMAKE_PROJECT_NAME}-${CEGUI_VERSION_MAJOR}.${CEGUI_VERSION_MINOR}" )

if( CMAKE_COMPILER_IS_GNUCXX OR (CMAKE_CXX_COMPILER_ID STREQUAL "Clang") )
    set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-unused-local-typedefs -Wno-unused-parameter -Wno-address")
    if( CMAKE_COMPILER_IS_GNUCXX )
        set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-nonnull-compare")
    endif()
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

include_directories(SYSTEM
                        ${PYTHON_INCLUDE_DIR}
                        ${Boost_INCLUDE_DIR})

cegui_add_python_module( ${CEGUI_PYCEGUI_CORE_LIBNAME} "output/CEGUI" "" )

if (CEGUI_BUILD_RENDERER_NULL)
    cegui_add_python_module( ${CEGUI_PYCEGUI_NULL_RENDERER_LIBNAME} "output/CEGUINullRenderer" ${CEGUI_NULL_RENDERER_LIBNAME} )
endif()

if (CEGUI_BUILD_RENDERER_OGRE)
    cegui_add_python_module( ${CEGUI_PYCEGUI_OGRE_RENDERER_LIBNAME} "output/CEGUIOgreRenderer" ${CEGUI_OGRE_RENDERER_LIBNAME} )
endif()

if (CEGUI_BUILD_RENDERER_OPENGL)
    cegui_add_python_module( ${CEGUI_PYCEGUI_OPENGL_RENDERER_LIBNAME} "output/CEGUIOpenGLRenderer" ${CEGUI_OPENGL_RENDERER_LIBNAME} )
endif()

