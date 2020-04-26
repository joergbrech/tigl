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

#include <boost/optional.hpp>
#include <boost/utility/in_place_factory.hpp>
#include <CCPACSWingSparPositionUIDs.h>
#include <string>
#include <tixi.h>
#include "CPACSSparCrossSection.h"
#include "CTiglUIDObject.h"
#include "tigl_internal.h"

namespace tigl
{
class CTiglUIDManager;
class CCPACSWingSparSegments;

namespace generated
{
    // This class is used in:
    // CPACSSparSegments

    // generated from /xsd:schema/xsd:complexType[830]
    /// @brief SparSegments (=spars) of the wing.
    /// 
    /// SparSegmentType, each spar is defined by multiple
    /// sparPositions that are referenced via their uID. The spar cross
    /// section is defined in 'sparCrossSection'.
    /// 
    class CPACSSparSegment : public CTiglReqUIDObject
    {
    public:
        TIGL_EXPORT CPACSSparSegment(CCPACSWingSparSegments* parent, CTiglUIDManager* uidMgr);

        TIGL_EXPORT virtual ~CPACSSparSegment();

        TIGL_EXPORT CCPACSWingSparSegments* GetParent();

        TIGL_EXPORT const CCPACSWingSparSegments* GetParent() const;

        TIGL_EXPORT virtual CTiglUIDObject* GetNextUIDParent();
        TIGL_EXPORT virtual const CTiglUIDObject* GetNextUIDParent() const;

        TIGL_EXPORT CTiglUIDManager& GetUIDManager();
        TIGL_EXPORT const CTiglUIDManager& GetUIDManager() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const std::string& GetUID() const;
        TIGL_EXPORT virtual void SetUID(const std::string& value);

        TIGL_EXPORT virtual const std::string& GetName() const;
        TIGL_EXPORT virtual void SetName(const std::string& value);

        TIGL_EXPORT virtual const boost::optional<std::string>& GetDescription() const;
        TIGL_EXPORT virtual void SetDescription(const boost::optional<std::string>& value);

        TIGL_EXPORT virtual const CCPACSWingSparPositionUIDs& GetSparPositionUIDs() const;
        TIGL_EXPORT virtual CCPACSWingSparPositionUIDs& GetSparPositionUIDs();

        TIGL_EXPORT virtual const CPACSSparCrossSection& GetSparCrossSection() const;
        TIGL_EXPORT virtual CPACSSparCrossSection& GetSparCrossSection();

    protected:
        CCPACSWingSparSegments* m_parent;

        CTiglUIDManager* m_uidMgr;

        std::string                  m_uID;

        /// Name of the spar segment (=spar).
        std::string                  m_name;

        /// Description of the spar segment (spar).
        boost::optional<std::string> m_description;

        CCPACSWingSparPositionUIDs   m_sparPositionUIDs;

        CPACSSparCrossSection        m_sparCrossSection;

    private:
        CPACSSparSegment(const CPACSSparSegment&) = delete;
        CPACSSparSegment& operator=(const CPACSSparSegment&) = delete;

        CPACSSparSegment(CPACSSparSegment&&) = delete;
        CPACSSparSegment& operator=(CPACSSparSegment&&) = delete;
    };
} // namespace generated

// CPACSSparSegment is customized, use type CCPACSWingSparSegment directly
} // namespace tigl
