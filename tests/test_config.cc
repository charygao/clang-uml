/**
 * tests/test_config.cc
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
#define CATCH_CONFIG_MAIN

#include "catch.h"

#include "config/config.h"
#include "util/util.h"

TEST_CASE("Test config simple", "[unit-test]")
{
    auto cfg = clanguml::config::load("./test_config_data/simple.yml");

    CHECK(cfg.diagrams.size() == 1);
    auto &diagram = *cfg.diagrams["class_main"];
    CHECK(diagram.type() == clanguml::config::diagram_type::class_diagram);
    CHECK(diagram.glob().size() == 2);
    CHECK(clanguml::util::contains(diagram.using_namespace(), "clanguml"));
}

TEST_CASE("Test config inherited", "[unit-test]")
{
    auto cfg = clanguml::config::load("./test_config_data/inherited.yml");

    CHECK(cfg.diagrams.size() == 2);
    auto &def = *cfg.diagrams["class_default"];
    CHECK(def.type() == clanguml::config::diagram_type::class_diagram);
    CHECK(def.glob().size() == 2);
    CHECK(def.glob()[0] == "src/**/*.cc");
    CHECK(def.glob()[1] == "src/**/*.h");
    CHECK(clanguml::util::contains(def.using_namespace(), "clanguml"));

    auto &cus = *cfg.diagrams["class_custom"];
    CHECK(cus.type() == clanguml::config::diagram_type::class_diagram);
    CHECK(cus.glob().size() == 1);
    CHECK(cus.glob()[0] == "src/main.cc");
    CHECK(clanguml::util::contains(cus.using_namespace(), "clanguml::ns1"));
    CHECK(cus.include_relations_also_as_members());
}