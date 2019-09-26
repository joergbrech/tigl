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

#include <CCPACSStringVector.h>
#include <string>
#include <tixi.h>
#include "tigl_internal.h"

namespace tigl
{
namespace generated
{
    // This class is used in:
    // CPACSMaterial

    // generated from /xsd:schema/xsd:complexType[302]
    /// @brief Emissivity map, containing the diffuse emissivity of a material at different spectral lengths.
    /// 
    /// The emissivity of a material can vary with the spectral wave length. 
    /// The vectors diffuseEmissivity and waveLength must have the same size to be valid. 
    /// The data should be linearly interpolated.
    /// 
    class CPACSEmissivityMap
    {
    public:
        TIGL_EXPORT CPACSEmissivityMap();
        TIGL_EXPORT virtual ~CPACSEmissivityMap();

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const CCPACSStringVector& GetWaveLength() const;
        TIGL_EXPORT virtual CCPACSStringVector& GetWaveLength();

        TIGL_EXPORT virtual const CCPACSStringVector& GetDiffuseEmissivity() const;
        TIGL_EXPORT virtual CCPACSStringVector& GetDiffuseEmissivity();

    protected:
        /// Wave length in [m]
        CCPACSStringVector m_waveLength;

        /// Diffuse emissivity of the material
        CCPACSStringVector m_diffuseEmissivity;

    private:
        CPACSEmissivityMap(const CPACSEmissivityMap&) = delete;
        CPACSEmissivityMap& operator=(const CPACSEmissivityMap&) = delete;

        CPACSEmissivityMap(CPACSEmissivityMap&&) = delete;
        CPACSEmissivityMap& operator=(CPACSEmissivityMap&&) = delete;
    };
} // namespace generated

// Aliases in tigl namespace
using CCPACSEmissivityMap = generated::CPACSEmissivityMap;
} // namespace tigl
