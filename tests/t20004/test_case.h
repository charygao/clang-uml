/**
 * tests/t20004/test_case.h
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

TEST_CASE("t20004", "[test-case][sequence]")
{
    auto [config, db] = load_config("t20004");

    auto diagram = config.diagrams["t20004_sequence"];

    REQUIRE(diagram->name == "t20004_sequence");

    auto model = generate_sequence_diagram(*db, diagram);

    REQUIRE(model->name() == "t20004_sequence");

    auto puml = generate_sequence_puml(diagram, *model);
    AliasMatcher _A(puml);

    REQUIRE_THAT(puml, StartsWith("@startuml"));
    REQUIRE_THAT(puml, HasCall(_A("main()"), _A("m1<float>(float)"), ""));
    REQUIRE_THAT(
        puml, !HasCall(_A("m1<float>(float)"), _A("m1<float>(float)"), ""));
    REQUIRE_THAT(
        puml, !HasCall(_A("m1<float>(float)"), _A("m1<float>(float)"), ""));

    REQUIRE_THAT(puml,
        HasCall(_A("main()"), _A("m1<unsigned long>(unsigned long)"), ""));
    REQUIRE_THAT(puml,
        HasCall(_A("m1<unsigned long>(unsigned long)"),
            _A("m4<unsigned long>(unsigned long)"), ""));

    REQUIRE_THAT(
        puml, HasCall(_A("main()"), _A("m1<std::string>(std::string)"), ""));
    REQUIRE_THAT(puml,
        HasCall(_A("m1<std::string>(std::string)"),
            _A("m2<std::string>(std::string)"), ""));

    REQUIRE_THAT(puml, HasCall(_A("main()"), _A("m1<int>(int)"), ""));
    REQUIRE_THAT(puml, HasCall(_A("m1<int>(int)"), _A("m2<int>(int)"), ""));
    REQUIRE_THAT(puml, HasCall(_A("m2<int>(int)"), _A("m3<int>(int)"), ""));
    REQUIRE_THAT(puml, HasCall(_A("m3<int>(int)"), _A("m4<int>(int)"), ""));
    REQUIRE_THAT(puml, EndsWith("@enduml\n"));

    save_puml(config.output_directory() + "/" + diagram->name + ".puml", puml);
}