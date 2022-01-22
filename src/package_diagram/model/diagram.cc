/**
 * src/package_diagram/model/diagram.cc
 *
 * Copyright (c) 2021-2022 Bartek Kryza <bkryza@gmail.com>
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

#include "diagram.h"

#include "util/error.h"
#include "util/util.h"

namespace clanguml::package_diagram::model {

std::string diagram::name() const { return name_; }

void diagram::set_name(const std::string &name) { name_ = name; }

std::string diagram::to_alias(const std::string &full_name) const
{
    LOG_DBG("Looking for alias for {}", full_name);

    auto fn = util::split(full_name, "::");

    if (fn.empty())
        throw error::uml_alias_missing(
            fmt::format("Missing alias for '{}'", full_name));

    auto package = get_package(fn);

    if (!package)
        throw error::uml_alias_missing(
            fmt::format("Missing alias for '{}'", full_name));

    return package.value().alias();
}
}
