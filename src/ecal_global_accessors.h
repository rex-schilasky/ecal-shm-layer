// MODIFIED FOR THIS REPO ONLY !


/* ========================= eCAL LICENSE =================================
 *
 * Copyright (C) 2016 - 2019 Continental Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *      http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * ========================= eCAL LICENSE =================================
*/

/**
 * @brief  eCAL core functions
**/

#pragma once

#include <atomic>

// Forward declaration of global accessible classes
namespace eCAL
{
  class  CGlobals;

  class  CMemFileThreadPool;
  class  CMemFileMap;

  // Declaration of getter functions for globally accessible variable instances
  CGlobals*                g_globals();

  CMemFileThreadPool*      g_memfile_pool();
  CMemFileMap*             g_memfile_map();

  // declaration of globally accessible variables
  extern CGlobals*         g_globals_ctx;
  extern std::atomic<int>  g_globals_ctx_ref_cnt;
}
