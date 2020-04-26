// Copyright (c) 2020 RISC Software GmbH
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
    // CPACSFarField

    // generated from /xsd:schema/xsd:complexType[331]/xsd:complexContent/xsd:extension/xsd:sequence/xsd:element[1]/xsd:complexType/xsd:simpleContent
    enum CPACSFarField_type
    {
        halfSphere,
        fullSphere,
        halfCube,
        fullCube
    };

    inline std::string TiglFarFieldTypeToString(const CPACSFarField_type& value)
    {
        switch(value) {
        case halfSphere: return "halfSphere";
        case fullSphere: return "fullSphere";
        case halfCube: return "halfCube";
        case fullCube: return "fullCube";
        default: throw CTiglError("Invalid enum value \"" + std_to_string(static_cast<int>(value)) + "\" for enum type CPACSFarField_type");
        }
    }
    inline CPACSFarField_type stringToTiglFarFieldType(const std::string& value)
    {
        auto toLower = [](std::string str) { for (char& c : str) { c = std::tolower(c); } return str; };
        if (toLower(value) == "halfsphere") { return halfSphere; }
        if (toLower(value) == "fullsphere") { return fullSphere; }
        if (toLower(value) == "halfcube") { return halfCube; }
        if (toLower(value) == "fullcube") { return fullCube; }
        throw CTiglError("Invalid string value \"" + value + "\" for enum type CPACSFarField_type");
    }
} // namespace generated

// CPACSFarField_type is customized, use type TiglFarFieldType directly
} // namespace tigl
