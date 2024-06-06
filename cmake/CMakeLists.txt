cmake_minimum_required(VERSION 3.16)
project(sensor_gen)
add_compile_definitions(SENSOR_DLL_BUILD)
include_directories($ENV{AllIncludePaths})
link_directories($ENV{AllReleaseLibPaths})
include_directories(../../include)
aux_source_directory(../../src DIR_SRCS)
add_library(sensor_gen SHARED ${DIR_SRCS})
target_link_libraries(sensor_gen 
        infra
        json
        log
        manager
        image
        device
        camera
        camera_hikvision
        camera_basler)
