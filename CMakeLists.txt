cmake_minimum_required(VERSION 3.1)
#CMAKE_MINIMUM_REQUIRED(VERSION 3.4 FATAL_ERROR)
project (pyABP)
# set(CMAKE_BUILD_TYPE "Release")
# place all executables in the build directory 
#set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# ########### ADD C++ SUPPORT - adjust here for different operatingn systems ##############
# find_program(CMAKE_C_COMPILER NAMES $ENV{CC} gcc PATHS ENV PATH NO_DEFAULT_PATH)
# find_program(CMAKE_CXX_COMPILER NAMES $ENV{CXX} g++ PATHS ENV PATH NO_DEFAULT_PATH)
# ########### SET C++ COMPILER FLAGS  ############
# set(CMAKE_CXX_FLAGS_DEBUG "-g -Wall" CACHE STRING "Flags used by the compiler during debug builds." FORCE)
# set(CMAKE_CXX_FLAGS_MINSIZEREL "-Os -Wall -DNDEBUG" CACHE STRING "Flags used by the compiler during minimum size release builds." FORCE)
# set(CMAKE_CXX_FLAGS_RELEASE "-O3 -funroll-loops -ffast-math -DNDEBUG -std=c++14 -fvisibility=hidden -fpermissive" CACHE STRING "Flags used by the compiler during release builds." FORCE)
# set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-g -O -funroll-loops -ffast-math -DNDEBUG -Wall" CACHE STRING "Flags used by the compiler during release builds with debug info." FORCE)
# ############################################


########## ADD VTK LIBRARIES #########
find_package(VTK REQUIRED) #add VTK libs
include(${VTK_USE_FILE}) # include vtk libs
set(VTK_PYTHON_VERSION=3) # give VTK the flag that we're using python3
########################################

####### Actual source files: located in src #########
file(GLOB include "src/*.h")
file(GLOB sources "src/*.cpp") #add source files
##############################################

########## Linking and naming the module #######
#target_link_libraries(pyABP PRIVATE ${VTK_LIBRARIES}) #link VTK libs
#target_link_libraries(pyABP PRIVATE ${AJM_LIBS})


########### ADD PYBIND SUPPORT  ###############
# On Ubuntu 18 where pybind is *still* broken
# set(PYBIND11_PYTHON_VERSION 3.6)
add_subdirectory(include/pybind11)
# otherwise
#find_package(pybind11 REQUIRED)

#set(PYBIND11_CPP_STANDARD -std=c++14)
############################################

########## Making the module ########
pybind11_add_module(pyABP ${sources} ${include}) #makes a python module by using all specified source files 
target_link_libraries(pyABP PRIVATE ${VTK_LIBRARIES}) #link VTK libs


# Add executable target for library demo.

# add_executable(cppABP ${sources} ${include})



