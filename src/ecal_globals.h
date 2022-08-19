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

#include "ecal_global_accessors.h"

//#include "io/ecal_memfile_pool.h"
#include "io/ecal_memfile_db.h"

#include <memory>

namespace eCAL
{
  class CGlobals
  {
  public:
    CGlobals();
    ~CGlobals();

    int Initialize    ( unsigned int components_, std::vector<std::string>* config_keys_ = nullptr);
    int IsInitialized ( unsigned int component_  );

    unsigned int GetComponents() { return(components); };

    int Finalize(unsigned int components_);

    //const std::unique_ptr<CMemFileThreadPool>&     memfile_pool()     { return memfile_pool_instance; };
    const std::unique_ptr<CMemFileMap>&            memfile_map()      { return memfile_map_instance; };

  private:
    bool                                           initialized;
    unsigned int                                   components;
    //std::unique_ptr<CMemFileThreadPool>            memfile_pool_instance;
    std::unique_ptr<CMemFileMap>                   memfile_map_instance;
  };
}
