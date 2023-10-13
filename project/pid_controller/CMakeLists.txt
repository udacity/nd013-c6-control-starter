project(PidController)

cmake_minimum_required (VERSION 3.10)

# -g allows for gdb debugging
# turn on -03 for best performance
add_definitions(-std=c++14 -O3)

set(CXX_FLAGS "-pthread -fPIC -DNDEBUG -Wall -Wextra")
set(CMAKE_CXX_FLAGS "${CXX_FLAGS} -Wl,-Bstatic -lcarla_client -lrpc -lboost_filesystem -Wl,-Bdynamic")

set(sources main.cpp behavior_planner_FSM.cpp motion_planner.cpp cubic_spiral.cpp spiral_base.cpp integral.cpp spiral_equations.cpp cost_functions.cpp utils.cpp velocity_profile_generator.cpp pid_controller.cpp)

# Use includes and libs from CARLA_SOURCE_DIR.
set(CARLA_SOURCE_DIR /opt/carla-source)
set(CARLA_BUILD_DIR ${CARLA_SOURCE_DIR}/Build)
set(CARLA_BUILD_BOOST_DIR ${CARLA_BUILD_DIR}/boost-1.72.0-c8-install)
set(CARLA_BUILD_RECAST_DIR ${CARLA_BUILD_DIR}/recast-cdce4e-c8-install)
set(CARLA_BUILD_RPCLIB_DIR ${CARLA_BUILD_DIR}/rpclib-v2.2.1_c2-c8-libstdcxx-install)

set(CARLA_BUILD_LIBCARLA_DIR ${CARLA_BUILD_DIR}/libcarla-client-build.release/LibCarla/cmake/client)
set(CARLA_BUILD_BOOST_LIB_DIR ${CARLA_BUILD_BOOST_DIR}/lib)
set(CARLA_BUILD_RECAST_LIB_DIR ${CARLA_BUILD_RECAST_DIR}/lib)
set(CARLA_BUILD_RPCLIB_LIB_DIR ${CARLA_BUILD_RPCLIB_DIR}/lib)

set(carla_libs ${CARLA_BUILD_BOOST_LIB_DIR}/libboost_filesystem.a ${CARLA_BUILD_BOOST_LIB_DIR}/libboost_program_options.a ${CARLA_BUILD_BOOST_LIB_DIR}/libboost_python38.a ${CARLA_BUILD_BOOST_LIB_DIR}/libboost_system.a ${CARLA_BUILD_LIBCARLA_DIR}/libcarla_client.a ${CARLA_BUILD_RPCLIB_LIB_DIR}/librpc.a ${CARLA_BUILD_RECAST_LIB_DIR}/libDebugUtils.a ${CARLA_BUILD_RECAST_LIB_DIR}/libDetour.a ${CARLA_BUILD_RECAST_LIB_DIR}/libDetourCrowd.a ${CARLA_BUILD_RECAST_LIB_DIR}/libDetourTileCache.a ${CARLA_BUILD_RECAST_LIB_DIR}/libRecast.a)

include_directories(/usr/local/include)
link_directories(/usr/local/lib)

include_directories(eigen-3.3.7)

include_directories(${CARLA_SOURCE_DIR}/LibCarla/source)
include_directories(${CARLA_BUILD_BOOST_DIR}/include)
include_directories(${CARLA_BUILD_RECAST_DIR}/include)
include_directories(${CARLA_BUILD_RPCLIB_DIR}/include)

link_directories(${CARLA_BUILD_LIBCARLA_DIR})
link_directories(${CARLA_BUILD_BOOST_LIB_DIR})
link_directories(${CARLA_BUILD_RECAST_LIB_DIR})
link_directories(${CARLA_BUILD_RPCLIB_LIB_DIR})

if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")

endif(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")

add_executable(pid_controller ${sources} )

target_link_libraries(pid_controller z ssl uv uWS ${carla_libs} gtest glog boost_filesystem lapack)
