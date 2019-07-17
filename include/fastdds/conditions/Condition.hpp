// Copyright 2019 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/**
 * @file Condition.hpp
 */

#ifndef _FASTDDS_CONDITION_HPP_
#define _FASTDDS_CONDITION_HPP_

namespace eprosima {
namespace fastdds {

/**
 * Condition is a root class for all conditions
 * that may be attached to a Waitset
 * @ingroup FASTDDS_MODULE
 */
class Condition
{
protected:

    //! @brief Retrieves the trigger_value of the condition
    bool get_trigger_value () const
    {
        //TODO Implement
        return false;
    }

};

} // end of namespace fastdds
} // end of namespace eprosima

#endif // _FASTDDS_CONDITION_HPP_