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
#include <tixi.h>
#include <typeinfo>
#include "CTiglError.h"
#include "CTiglUIDObject.h"
#include "tigl_internal.h"

namespace tigl
{
class CTiglUIDManager;
class CCPACSPointListXY;

namespace generated
{
    class CPACSGlobalBeamProperties;
    class CPACSSheet;
    class CPACSTransformation2D;

    // This class is used in:
    // CPACSGlobalBeamProperties
    // CPACSPointListXY
    // CPACSSheet
    // CPACSTransformation2D

    // generated from /xsd:schema/xsd:complexType[732]
    /// @brief Data points in x-y-space.
    /// 
    /// Point type, containing an xy data doublet.
    /// 
    class CPACSPointXY : public CTiglReqUIDObject
    {
    public:
        TIGL_EXPORT CPACSPointXY(CPACSGlobalBeamProperties* parent, CTiglUIDManager* uidMgr);
        TIGL_EXPORT CPACSPointXY(CCPACSPointListXY* parent, CTiglUIDManager* uidMgr);
        TIGL_EXPORT CPACSPointXY(CPACSSheet* parent, CTiglUIDManager* uidMgr);
        TIGL_EXPORT CPACSPointXY(CPACSTransformation2D* parent, CTiglUIDManager* uidMgr);

        TIGL_EXPORT virtual ~CPACSPointXY();

        template<typename P>
        bool IsParent() const
        {
            return m_parentType != NULL && *m_parentType == typeid(P);
        }

        template<typename P>
        P* GetParent()
        {
#ifdef HAVE_STDIS_SAME
            static_assert(std::is_same<P, CPACSGlobalBeamProperties>::value || std::is_same<P, CCPACSPointListXY>::value || std::is_same<P, CPACSSheet>::value || std::is_same<P, CPACSTransformation2D>::value, "template argument for P is not a parent class of CPACSPointXY");
#endif
            if (!IsParent<P>()) {
                throw CTiglError("bad parent");
            }
            return static_cast<P*>(m_parent);
        }

        template<typename P>
        const P* GetParent() const
        {
#ifdef HAVE_STDIS_SAME
            static_assert(std::is_same<P, CPACSGlobalBeamProperties>::value || std::is_same<P, CCPACSPointListXY>::value || std::is_same<P, CPACSSheet>::value || std::is_same<P, CPACSTransformation2D>::value, "template argument for P is not a parent class of CPACSPointXY");
#endif
            if (!IsParent<P>()) {
                throw CTiglError("bad parent");
            }
            return static_cast<P*>(m_parent);
        }

        TIGL_EXPORT virtual CTiglUIDObject* GetNextUIDParent();
        TIGL_EXPORT virtual const CTiglUIDObject* GetNextUIDParent() const;

        TIGL_EXPORT CTiglUIDManager& GetUIDManager();
        TIGL_EXPORT const CTiglUIDManager& GetUIDManager() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const std::string& GetUID() const;
        TIGL_EXPORT virtual void SetUID(const std::string& value);

        TIGL_EXPORT virtual const double& GetX() const;
        TIGL_EXPORT virtual void SetX(const double& value);

        TIGL_EXPORT virtual const double& GetY() const;
        TIGL_EXPORT virtual void SetY(const double& value);

    protected:
        void* m_parent;
        const std::type_info* m_parentType;

        CTiglUIDManager* m_uidMgr;

        std::string m_uID;

        /// X-Component
        double      m_x;

        /// Y-Component
        double      m_y;

    private:
        CPACSPointXY(const CPACSPointXY&) = delete;
        CPACSPointXY& operator=(const CPACSPointXY&) = delete;

        CPACSPointXY(CPACSPointXY&&) = delete;
        CPACSPointXY& operator=(CPACSPointXY&&) = delete;
    };
} // namespace generated

// CPACSPointXY is customized, use type CCPACSPointXY directly

// Aliases in tigl namespace
using CCPACSGlobalBeamProperties = generated::CPACSGlobalBeamProperties;
using CCPACSSheet = generated::CPACSSheet;
using CCPACSTransformation2D = generated::CPACSTransformation2D;
} // namespace tigl
