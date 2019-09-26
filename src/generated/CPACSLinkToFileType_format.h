// Copyright (c) 2018 RISC Software GmbH
//
// This file was generated by CPACSGen from CPACS XML Schema (c) German Aerospace Center (DLR/SC).
// Do not edit, all changes are lost when files are re-generated.
//
// Licensed under the Apache License, Version 2.0 (the "License")
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

#pragma once

#include <string>
#include <cctype>

#include "CTiglError.h"
#include "to_string.h"

namespace tigl
{
namespace generated
{
    // This enum is used in:
    // CPACSLinkToFile

    // generated from /xsd:schema/xsd:complexType[503]/xsd:simpleContent/xsd:extension/xsd:attribute[1]/xsd:simpleType
    enum CPACSLinkToFileType_format
    {
        Step,
        Iges,
        Stl
    };

    inline std::string CPACSLinkToFileType_formatToString(const CPACSLinkToFileType_format& value)
    {
        switch(value) {
        case Step: return "Step";
        case Iges: return "Iges";
        case Stl: return "Stl";
        default: throw CTiglError("Invalid enum value \"" + std_to_string(static_cast<int>(value)) + "\" for enum type CPACSLinkToFileType_format");
        }
    }
    inline CPACSLinkToFileType_format stringToCPACSLinkToFileType_format(const std::string& value)
    {
        auto toLower = [](std::string str) { for (char& c : str) { c = std::tolower(c); } return str; };
        if (toLower(value) == "step") { return Step; }
        if (toLower(value) == "iges") { return Iges; }
        if (toLower(value) == "stl") { return Stl; }
        throw CTiglError("Invalid string value \"" + value + "\" for enum type CPACSLinkToFileType_format");
    }
} // namespace generated

// Aliases in tigl namespace
using ECPACSLinkToFileType_format = generated::CPACSLinkToFileType_format;
} // namespace tigl
