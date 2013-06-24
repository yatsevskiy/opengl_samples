cmake_minimum_required(VERSION 2.8)
set(SOURCE_EXE main.cpp)

include_directories(renderer)
add_executable(main ${SOURCE_EXE})


add_subdirectory(renderer)

target_link_libraries(main renderer)

find_package(SDL REQUIRED)
if(NOT SDL_FOUND)
    message(SEND_ERROR "Failed to find SDL")
    return()
else()
    include_directories(${SDL_INCLUDE_DIR})
endif()

##########################################################
find_package(LibXml2 REQUIRED)
if(NOT LIBXML2_FOUND)
    message(SEND_ERROR "Failed to find LibXml2")
    return()
else()
    include_directories(${LIBXML2_INCLUDE_DIR})
endif()
##########################################################
find_package(Boost COMPONENTS thread-mt REQUIRED)
if(NOT Boost_FOUND)
    message(SEND_ERROR "Failed to find boost::thread-mt.")
    return()
else()
    include_directories(${Boost_INCLUDE_DIRS})
endif()
##########################################################

find_package(OpenGL REQUIRED)
if(NOT OPENGL_FOUND)
    message(SEND_ERROR "Failed to find OPENGL")
    return()
else()
    include_directories(${OPENGL_INCLUDE_DIR})
endif()

find_package(GLUT REQUIRED)
if(NOT GLUT_FOUND)
    message(SEND_ERROR "Failed to find GLUT")
    return()
else()
#    include_directories(${GLUT_INCLUDE_DIR})
endif()

message(${OPENGL_INCLUDE_DIR})
message(${GLUT_INCLUDE_DIR})

target_link_libraries(main
                                ${SDL_LIBRARY}
                                ${LIBXML2_LIBRARIES}
                                ${Boost_LIBRARIES}
                                ${OPENGL_LIBRARIES}
                                ${GLUT_LIBRARY})
