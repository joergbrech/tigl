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

#include <cassert>
#include "CCPACSWingComponentSegment.h"
#include "CPACSControlSurfaces.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSControlSurfaces::CPACSControlSurfaces(CCPACSWingComponentSegment* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
    }

    CPACSControlSurfaces::~CPACSControlSurfaces()
    {
    }

    CCPACSWingComponentSegment* CPACSControlSurfaces::GetParent() const
    {
        return m_parent;
    }

    CTiglUIDManager& CPACSControlSurfaces::GetUIDManager()
    {
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSControlSurfaces::GetUIDManager() const
    {
        return *m_uidMgr;
    }

    void CPACSControlSurfaces::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read element trailingEdgeDevices
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/trailingEdgeDevices")) {
            m_trailingEdgeDevices = boost::in_place(reinterpret_cast<CCPACSControlSurfaces*>(this), m_uidMgr);
            try {
                m_trailingEdgeDevices->ReadCPACS(tixiHandle, xpath + "/trailingEdgeDevices");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read trailingEdgeDevices at xpath " << xpath << ": " << e.what();
                m_trailingEdgeDevices = boost::none;
            }
        }

    }

    void CPACSControlSurfaces::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write element trailingEdgeDevices
        if (m_trailingEdgeDevices) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/trailingEdgeDevices");
            m_trailingEdgeDevices->WriteCPACS(tixiHandle, xpath + "/trailingEdgeDevices");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/trailingEdgeDevices")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/trailingEdgeDevices");
            }
        }

    }

    const boost::optional<CCPACSTrailingEdgeDevices>& CPACSControlSurfaces::GetTrailingEdgeDevices() const
    {
        return m_trailingEdgeDevices;
    }

    boost::optional<CCPACSTrailingEdgeDevices>& CPACSControlSurfaces::GetTrailingEdgeDevices()
    {
        return m_trailingEdgeDevices;
    }

    CCPACSTrailingEdgeDevices& CPACSControlSurfaces::GetTrailingEdgeDevices(CreateIfNotExistsTag)
    {
        if (!m_trailingEdgeDevices)
            m_trailingEdgeDevices = boost::in_place(reinterpret_cast<CCPACSControlSurfaces*>(this), m_uidMgr);
        return *m_trailingEdgeDevices;
    }

    void CPACSControlSurfaces::RemoveTrailingEdgeDevices()
    {
        m_trailingEdgeDevices = boost::none;
    }

} // namespace generated
} // namespace tigl
