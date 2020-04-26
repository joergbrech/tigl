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

#include <cassert>
#include <CCPACSWingSegment.h>
#include "CCPACSEnginePylon.h"
#include "CCPACSWing.h"
#include "CPACSWingSegments.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "CTiglUIDObject.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSWingSegments::CPACSWingSegments(CCPACSEnginePylon* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
        m_parentType = &typeid(CCPACSEnginePylon);
    }

    CPACSWingSegments::CPACSWingSegments(CCPACSWing* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
        m_parentType = &typeid(CCPACSWing);
    }

    CPACSWingSegments::~CPACSWingSegments()
    {
    }

    const CTiglUIDObject* CPACSWingSegments::GetNextUIDParent() const
    {
        if (m_parent) {
            if (IsParent<CCPACSEnginePylon>()) {
                return GetParent<CCPACSEnginePylon>();
            }
            if (IsParent<CCPACSWing>()) {
                return GetParent<CCPACSWing>();
            }
        }
        return nullptr;
    }

    CTiglUIDObject* CPACSWingSegments::GetNextUIDParent()
    {
        if (m_parent) {
            if (IsParent<CCPACSEnginePylon>()) {
                return GetParent<CCPACSEnginePylon>();
            }
            if (IsParent<CCPACSWing>()) {
                return GetParent<CCPACSWing>();
            }
        }
        return nullptr;
    }

    CTiglUIDManager& CPACSWingSegments::GetUIDManager()
    {
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSWingSegments::GetUIDManager() const
    {
        return *m_uidMgr;
    }

    void CPACSWingSegments::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read element segment
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/segment")) {
            tixi::TixiReadElements(tixiHandle, xpath + "/segment", m_segments, 1, tixi::xsdUnbounded, reinterpret_cast<CCPACSWingSegments*>(this), m_uidMgr);
        }

    }

    void CPACSWingSegments::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write element segment
        tixi::TixiSaveElements(tixiHandle, xpath + "/segment", m_segments);

    }

    const std::vector<std::unique_ptr<CCPACSWingSegment>>& CPACSWingSegments::GetSegments() const
    {
        return m_segments;
    }

    std::vector<std::unique_ptr<CCPACSWingSegment>>& CPACSWingSegments::GetSegments()
    {
        return m_segments;
    }

    CCPACSWingSegment& CPACSWingSegments::AddSegment()
    {
        m_segments.push_back(make_unique<CCPACSWingSegment>(reinterpret_cast<CCPACSWingSegments*>(this), m_uidMgr));
        return *m_segments.back();
    }

    void CPACSWingSegments::RemoveSegment(CCPACSWingSegment& ref)
    {
        for (std::size_t i = 0; i < m_segments.size(); i++) {
            if (m_segments[i].get() == &ref) {
                m_segments.erase(m_segments.begin() + i);
                return;
            }
        }
        throw CTiglError("Element not found");
    }

} // namespace generated
} // namespace tigl
