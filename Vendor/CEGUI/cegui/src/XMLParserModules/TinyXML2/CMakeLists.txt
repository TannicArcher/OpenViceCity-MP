set(CEGUI_TARGET_NAME ${CEGUI_TINYXML2_PARSER_LIBNAME})

cegui_gather_files()

cegui_add_loadable_module(${CEGUI_TARGET_NAME} CORE_SOURCE_FILES CORE_HEADER_FILES)

cegui_add_dependency(${CEGUI_TARGET_NAME} TINYXML2)

cegui_target_link_libraries(${CEGUI_TARGET_NAME} ${CEGUI_BASE_LIBNAME})

