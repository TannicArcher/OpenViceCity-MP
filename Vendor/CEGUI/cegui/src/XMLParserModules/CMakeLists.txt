if (CEGUI_BUILD_XMLPARSER_EXPAT)
    add_subdirectory(Expat)
endif()

if (CEGUI_BUILD_XMLPARSER_XERCES)
    add_subdirectory(Xerces)
endif()

if (CEGUI_BUILD_XMLPARSER_LIBXML2)
    add_subdirectory(Libxml2)
endif()

if (CEGUI_BUILD_XMLPARSER_TINYXML2)
    add_subdirectory(TinyXML2)
endif()

if (CEGUI_BUILD_XMLPARSER_PUGIXML)
    add_subdirectory(PugiXML)
endif()

