/**
 * tests/t00015/test_case.cc
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

TEST_CASE("t00015", "[test-case][class]")
{
    auto [config, db] = load_config("t00015");

    auto diagram = config.diagrams["t00015_class"];

    REQUIRE(diagram->name == "t00015_class");

    auto model = generate_class_diagram(*db, diagram);

    REQUIRE(model->name() == "t00015_class");
    REQUIRE(model->should_include("clanguml::t00015::ns1::ns2::A"));

    auto puml = generate_class_puml(diagram, *model);
    AliasMatcher _A(puml);

    REQUIRE_THAT(puml, StartsWith("@startuml"));
    REQUIRE_THAT(puml, EndsWith("@enduml\n"));
    REQUIRE_THAT(puml, IsClass(_A("ns1::A")));
    REQUIRE_THAT(puml, IsClass(_A("ns1::ns2_v0_9_0::A")));
    REQUIRE_THAT(puml, IsClass(_A("ns1::Anon")));
    REQUIRE_THAT(puml, IsClass(_A("ns3::ns1::ns2::Anon")));
    REQUIRE_THAT(puml, IsClass(_A("ns3::B")));

    save_puml(config.output_directory() + "/" + diagram->name + ".puml", puml);
}
