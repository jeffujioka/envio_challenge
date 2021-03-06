get_filename_component(JMF_MODULE_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)

# Project's directory
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include
                    ${CMAKE_CURRENT_SOURCE_DIR}/src
                    ${JMF_LIB_DIR}/synchronization/include)

# getting all source files ending with .cpp
file(GLOB_RECURSE SRCS **.cpp)

add_executable(${JMF_MODULE_NAME} ${SRCS})

# generates a static library to be used by the unit tests
set(JMF_LIB_MODULE_NAME_STATIC ${JMF_MODULE_NAME}-static)
add_library(${JMF_LIB_MODULE_NAME_STATIC} STATIC ${SRCS})

set_target_properties(${JMF_LIB_MODULE_NAME_STATIC}
                      PROPERTIES OUTPUT_NAME ${JMF_LIB_MODULE_NAME_STATIC})

install(TARGETS ${JMF_MODULE_NAME}
        RUNTIME DESTINATION bin
)
              
install(TARGETS ${JMF_LIB_MODULE_NAME_STATIC}
        LIBRARY DESTINATION lib
)
