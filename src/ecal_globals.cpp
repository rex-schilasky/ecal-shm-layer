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

#include "ecal_globals.h"

#include <stdexcept>

namespace eCAL
{
  CGlobals::CGlobals() : initialized(false), components(0)
  {}

  CGlobals::~CGlobals()
  {
  };

  int CGlobals::Initialize(unsigned int components_, std::vector<std::string>* config_keys_ /*= nullptr*/)
  {
    // will be set if any new module was initialized
    bool new_initialization(false);

    /////////////////////
    // MEMFILE MAP
    /////////////////////
    if(memfile_map_instance == nullptr) 
    {
      memfile_map_instance = std::make_unique<CMemFileMap>();
      new_initialization = true;
    }

    /////////////////////
    // MEMFILE POOL
    /////////////////////
    //if(memfile_pool_instance == nullptr) 
    //{
    //  memfile_pool_instance = std::make_unique<CMemFileThreadPool>();
    //  new_initialization = true;
    //}

    /////////////////////
    // CREATE ALL
    /////////////////////
    //if (memfile_pool_instance)  memfile_pool_instance->Create();

    initialized =  true;
    components  |= components_;

    if (new_initialization) return 0;
    else                    return 1;
  }

  int CGlobals::IsInitialized(unsigned int component_)
  {
    return(initialized);
  }

  int CGlobals::Finalize(unsigned int /*components_*/)
  {
    // start destruction
    //if (memfile_pool_instance) memfile_pool_instance->Destroy();
    if (memfile_map_instance)  memfile_map_instance->Destroy();

    initialized = false;

    return(0);
  }
}
