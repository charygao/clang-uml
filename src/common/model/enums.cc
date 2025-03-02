/**
 * src/common/model/enums.cc
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
#include "enums.h"

#include <cassert>

namespace clanguml::common::model {

std::string to_string(relationship_t r)
{
    switch (r) {
    case relationship_t::kNone:
        return "none";
    case relationship_t::kExtension:
        return "extension";
    case relationship_t::kComposition:
        return "composition";
    case relationship_t::kAggregation:
        return "aggregation";
    case relationship_t::kContainment:
        return "containment";
    case relationship_t::kOwnership:
        return "ownership";
    case relationship_t::kAssociation:
        return "association";
    case relationship_t::kInstantiation:
        return "instantiation";
    case relationship_t::kFriendship:
        return "friendship";
    case relationship_t::kDependency:
        return "dependency";
    case relationship_t::kAlias:
        return "alias";
    default:
        assert(false);
        return "";
    }
}

std::string to_string(access_t a)
{
    switch (a) {
    case access_t::kPublic:
        return "public";
    case access_t::kProtected:
        return "protected";
    case access_t::kPrivate:
        return "private";
    default:
        assert(false);
        return "";
    }
}

std::string to_string(message_t r)
{
    switch (r) {
    case message_t::kCall:
        return "call";
    case message_t::kReturn:
        return "return";
    case message_t::kIf:
        return "if";
    case message_t::kElse:
        return "else";
    case message_t::kElseIf:
        return "else if";
    case message_t::kIfEnd:
        return "end if";
    case message_t::kWhile:
        return "while";
    case message_t::kWhileEnd:
        return "end while";
    case message_t::kDo:
        return "do";
    case message_t::kDoEnd:
        return "end do";
    case message_t::kFor:
        return "for";
    case message_t::kForEnd:
        return "end for";
    case message_t::kTry:
        return "try";
    case message_t::kCatch:
        return "catch";
    case message_t::kTryEnd:
        return "end try";
    case message_t::kSwitch:
        return "switch";
    case message_t::kCase:
        return "case";
    case message_t::kSwitchEnd:
        return "end switch";
    case message_t::kConditional:
        return "conditional";
    case message_t::kConditionalEnd:
        return "end conditional";
    default:
        assert(false);
        return "";
    }
}

std::string to_string(const diagram_t t)
{
    switch (t) {
    case diagram_t::kClass:
        return "class";
    case diagram_t::kSequence:
        return "sequence";
    case diagram_t::kPackage:
        return "package";
    case diagram_t::kInclude:
        return "include";
    default:
        assert(false);
        return "";
    }
}

} // namespace clanguml::common::model
