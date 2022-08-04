# ========================= eCAL LICENSE =================================
#
# Copyright (C) 2016 - 2019 Continental Corporation
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
# 
#      http://www.apache.org/licenses/LICENSE-2.0
# 
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# ========================= eCAL LICENSE =================================

cmake_minimum_required(VERSION 3.10)

set(CMAKE_FIND_PACKAGE_PREFER_CONFIG ON)

project(ecal_shm_layer)

set(ecal_shm_layer_src
    src/io/ecal_memfile.cpp
    src/io/ecal_memfile.h
    src/io/ecal_memfile_db.cpp
    src/io/ecal_memfile_db.h
    src/io/ecal_memfile_header.h
    src/io/ecal_memfile_info.h
    src/io/ecal_memfile_mtx.h
    src/io/ecal_memfile_os.h
    #src/io/ecal_memfile_pool.cpp
    #src/io/ecal_memfile_pool.h
    src/io/ecal_memfile_sync.cpp
    src/io/ecal_memfile_sync.h
    src/io/ecal_win_main.h
    src/ecal_def.h
    src/ecal_global_accessors.cpp
    src/ecal_global_accessors.h
    src/ecal_globals.cpp
    src/ecal_globals.h
    includes/ecal/ecal_event.h
    includes/ecal/ecal_eventhandle.h
    includes/ecal/ecal_log.h
    includes/ecal/ecal_log_level.h
    includes/ecal/ecal_os.h
)
if(UNIX)
  set(ecal_shm_layer_linux_src
      src/io/linux/ecal_memfile_mtx.h
      src/io/linux/ecal_memfile_os.cpp
  )
endif()

if(WIN32)
  set(ecal_shm_layer_win_src
      src/io/win32/ecal_memfile_mtx.h
      src/io/win32/ecal_memfile_os.cpp
  )
endif()

include_directories(includes)
include_directories(src)

add_library(${PROJECT_NAME} ${ecal_shm_layer_src} ${ecal_shm_layer_win_src} ${ecal_shm_layer_linux_src})
