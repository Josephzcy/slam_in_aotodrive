

SET(MODULE_NAME chapter2)
SET(MODULE_HOME_PATH ${SRC_HOME_PATH}/${MODULE_NAME})
message(STATUS "MODULE_HOME_PATH = ${MODULE_HOME_PATH}")
# set(CMAKE_CXX_STANDARD 17)


INCLUDE_DIRECTORIES(
  ${MODULE_HOME_PATH}
  ${MODULE_HOME_PATH}/test
  ${WORKSPACE_HOME}/../
)
LINK_DIRECTORIES()


file(GLOB SRC_FILES "${MODULE_HOME_PATH}/*.h")

foreach(src ${SRC_FILES})
  get_filename_component(FILENAME ${src} NAME_WE)
  message(STATUS "File name: ${FILENAME}")
  SET(SRC_HEADER "${FILENAME}.h" )

  add_executable(${FILENAME}_node "${FILENAME}.cpp" "${MODULE_HOME_PATH}/test/${FILENAME}_test.cpp")
  # add_library(${FILENAME} SHARED "${FILENAME}.cpp" )

  target_link_libraries(${FILENAME}_node
    # ${MODULE_NAME_GLOBAL_LINK_LIBS}
    ${third_party_libs}
    SLAM_AUTODRIVE_tools
  )
endforeach()








