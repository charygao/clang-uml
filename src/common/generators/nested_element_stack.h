/**
 * src/common/generators/nested_element_stack.h
 *
 * Copyright (c) 2021-2023 Bartek Kryza <bkryza@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma once

#include <map>
#include <string>
#include <vector>

namespace clanguml::common::generators {

template <typename T> class nested_element_stack {
public:
    nested_element_stack(bool is_flat)
        : is_flat_{is_flat}
        , current_level_{0}
    {
        current_level_groups_.push_back({});
    }

    void enter()
    {
        if (!is_flat_)
            current_level_++;

        current_level_groups_.push_back({});
    }

    void leave()
    {
        if (!is_flat_)
            current_level_--;

        current_level_groups_.pop_back();
    }

    void group_together(const std::string &group_name, T *e)
    {
        current_level_groups_[current_level_][group_name].push_back(e);
    }

    const std::map<std::string, std::vector<T *>> &get_current_groups()
    {
        return current_level_groups_.at(current_level_);
    }

    const std::vector<T *> &get_group(const std::string &group_name)
    {
        return get_current_groups().at(group_name);
    }

private:
    bool is_flat_;

    uint32_t current_level_;

    std::vector<std::map<std::string, std::vector<T *>>> current_level_groups_;
};

} // namespace clanguml::common::generators