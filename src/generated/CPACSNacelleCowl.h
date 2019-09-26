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

#include <boost/optional.hpp>
#include <boost/utility/in_place_factory.hpp>
#include <CCPACSNacelleGuideCurves.h>
#include <CCPACSNacelleSections.h>
#include <CCPACSRotationCurve.h>
#include <string>
#include <tixi.h>
#include "CreateIfNotExists.h"
#include "tigl_internal.h"

namespace tigl
{
class CTiglUIDManager;

namespace generated
{
    class CPACSEngineNacelle;

    // This class is used in:
    // CPACSEngineNacelle

    // generated from /xsd:schema/xsd:complexType[999]
    /// @brief nacelleCowlType
    /// 
    /// Describes the cowl geometry for nacelles
    /// using sections positioned around the
    /// rotational center of the engine.
    /// 
    class CPACSNacelleCowl
    {
    public:
        TIGL_EXPORT CPACSNacelleCowl(CPACSEngineNacelle* parent, CTiglUIDManager* uidMgr);

        TIGL_EXPORT virtual ~CPACSNacelleCowl();

        TIGL_EXPORT CPACSEngineNacelle* GetParent();

        TIGL_EXPORT const CPACSEngineNacelle* GetParent() const;

        TIGL_EXPORT CTiglUIDManager& GetUIDManager();
        TIGL_EXPORT const CTiglUIDManager& GetUIDManager() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const std::string& GetUID() const;
        TIGL_EXPORT virtual void SetUID(const std::string& value);

        TIGL_EXPORT virtual const CCPACSNacelleSections& GetSections() const;
        TIGL_EXPORT virtual CCPACSNacelleSections& GetSections();

        TIGL_EXPORT virtual const boost::optional<CCPACSNacelleGuideCurves>& GetGuideCurves() const;
        TIGL_EXPORT virtual boost::optional<CCPACSNacelleGuideCurves>& GetGuideCurves();

        TIGL_EXPORT virtual const CCPACSRotationCurve& GetRotationCurve() const;
        TIGL_EXPORT virtual CCPACSRotationCurve& GetRotationCurve();

        TIGL_EXPORT virtual CCPACSNacelleGuideCurves& GetGuideCurves(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveGuideCurves();

    protected:
        CPACSEngineNacelle* m_parent;

        CTiglUIDManager* m_uidMgr;

        std::string                               m_uID;
        CCPACSNacelleSections                     m_sections;
        boost::optional<CCPACSNacelleGuideCurves> m_guideCurves;
        CCPACSRotationCurve                       m_rotationCurve;

    private:
        CPACSNacelleCowl(const CPACSNacelleCowl&) = delete;
        CPACSNacelleCowl& operator=(const CPACSNacelleCowl&) = delete;

        CPACSNacelleCowl(CPACSNacelleCowl&&) = delete;
        CPACSNacelleCowl& operator=(CPACSNacelleCowl&&) = delete;
    };
} // namespace generated

// CPACSNacelleCowl is customized, use type CCPACSNacelleCowl directly

// Aliases in tigl namespace
using CCPACSEngineNacelle = generated::CPACSEngineNacelle;
} // namespace tigl
