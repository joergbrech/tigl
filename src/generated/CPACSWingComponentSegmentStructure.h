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
#include <CCPACSWingRibsDefinitions.h>
#include <CCPACSWingShell.h>
#include <CCPACSWingSpars.h>
#include <string>
#include <tixi.h>
#include <typeinfo>
#include "CreateIfNotExists.h"
#include "CTiglError.h"
#include "tigl_internal.h"

namespace tigl
{
class CTiglUIDManager;
class CCPACSWingComponentSegment;
class CCPACSTrailingEdgeDevice;

namespace generated
{
    // This class is used in:
    // CPACSComponentSegment
    // CPACSTrailingEdgeDevice

    // generated from /xsd:schema/xsd:complexType[928]
    class CPACSWingComponentSegmentStructure
    {
    public:
        TIGL_EXPORT CPACSWingComponentSegmentStructure(CCPACSWingComponentSegment* parent, CTiglUIDManager* uidMgr);
        TIGL_EXPORT CPACSWingComponentSegmentStructure(CCPACSTrailingEdgeDevice* parent, CTiglUIDManager* uidMgr);

        TIGL_EXPORT virtual ~CPACSWingComponentSegmentStructure();

        template<typename P>
        bool IsParent() const
        {
            return m_parentType != NULL && *m_parentType == typeid(P);
        }

        template<typename P>
        P* GetParent() const
        {
#ifdef HAVE_STDIS_SAME
            static_assert(std::is_same<P, CCPACSWingComponentSegment>::value || std::is_same<P, CCPACSTrailingEdgeDevice>::value, "template argument for P is not a parent class of CPACSWingComponentSegmentStructure");
#endif
            if (!IsParent<P>()) {
                throw CTiglError("bad parent");
            }
            return static_cast<P*>(m_parent);
        }

        TIGL_EXPORT CTiglUIDManager& GetUIDManager();
        TIGL_EXPORT const CTiglUIDManager& GetUIDManager() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const CCPACSWingShell& GetUpperShell() const;
        TIGL_EXPORT virtual CCPACSWingShell& GetUpperShell();

        TIGL_EXPORT virtual const CCPACSWingShell& GetLowerShell() const;
        TIGL_EXPORT virtual CCPACSWingShell& GetLowerShell();

        TIGL_EXPORT virtual const boost::optional<CCPACSWingRibsDefinitions>& GetRibsDefinitions() const;
        TIGL_EXPORT virtual boost::optional<CCPACSWingRibsDefinitions>& GetRibsDefinitions();

        TIGL_EXPORT virtual const boost::optional<CCPACSWingSpars>& GetSpars() const;
        TIGL_EXPORT virtual boost::optional<CCPACSWingSpars>& GetSpars();

        TIGL_EXPORT virtual CCPACSWingRibsDefinitions& GetRibsDefinitions(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveRibsDefinitions();

        TIGL_EXPORT virtual CCPACSWingSpars& GetSpars(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveSpars();

    protected:
        void* m_parent;
        const std::type_info* m_parentType;

        CTiglUIDManager* m_uidMgr;

        CCPACSWingShell                            m_upperShell;
        CCPACSWingShell                            m_lowerShell;
        boost::optional<CCPACSWingRibsDefinitions> m_ribsDefinitions;
        boost::optional<CCPACSWingSpars>           m_spars;

    private:
#ifdef HAVE_CPP11
        CPACSWingComponentSegmentStructure(const CPACSWingComponentSegmentStructure&) = delete;
        CPACSWingComponentSegmentStructure& operator=(const CPACSWingComponentSegmentStructure&) = delete;

        CPACSWingComponentSegmentStructure(CPACSWingComponentSegmentStructure&&) = delete;
        CPACSWingComponentSegmentStructure& operator=(CPACSWingComponentSegmentStructure&&) = delete;
#else
        CPACSWingComponentSegmentStructure(const CPACSWingComponentSegmentStructure&);
        CPACSWingComponentSegmentStructure& operator=(const CPACSWingComponentSegmentStructure&);
#endif
    };
} // namespace generated

// CPACSWingComponentSegmentStructure is customized, use type CCPACSWingCSStructure directly
} // namespace tigl
