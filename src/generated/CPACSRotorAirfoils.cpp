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
#include "CCPACSProfiles.h"
#include "CPACSProfileGeometry.h"
#include "CPACSRotorAirfoils.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "CTiglUIDObject.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSRotorAirfoils::CPACSRotorAirfoils(CCPACSProfiles* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
    }

    CPACSRotorAirfoils::~CPACSRotorAirfoils()
    {
    }

    const CCPACSProfiles* CPACSRotorAirfoils::GetParent() const
    {
        return m_parent;
    }

    CCPACSProfiles* CPACSRotorAirfoils::GetParent()
    {
        return m_parent;
    }

    const CTiglUIDObject* CPACSRotorAirfoils::GetNextUIDParent() const
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDObject* CPACSRotorAirfoils::GetNextUIDParent()
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDManager& CPACSRotorAirfoils::GetUIDManager()
    {
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSRotorAirfoils::GetUIDManager() const
    {
        return *m_uidMgr;
    }

    void CPACSRotorAirfoils::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read element rotorAirfoil
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/rotorAirfoil")) {
            tixi::TixiReadElements(tixiHandle, xpath + "/rotorAirfoil", m_rotorAirfoils, 1, tixi::xsdUnbounded, reinterpret_cast<CCPACSRotorProfiles*>(this), m_uidMgr);
        }

    }

    void CPACSRotorAirfoils::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write element rotorAirfoil
        tixi::TixiSaveElements(tixiHandle, xpath + "/rotorAirfoil", m_rotorAirfoils);

    }

    const std::vector<std::unique_ptr<CPACSProfileGeometry>>& CPACSRotorAirfoils::GetRotorAirfoils() const
    {
        return m_rotorAirfoils;
    }

    std::vector<std::unique_ptr<CPACSProfileGeometry>>& CPACSRotorAirfoils::GetRotorAirfoils()
    {
        return m_rotorAirfoils;
    }

    CPACSProfileGeometry& CPACSRotorAirfoils::AddRotorAirfoil()
    {
        m_rotorAirfoils.push_back(make_unique<CPACSProfileGeometry>(reinterpret_cast<CCPACSRotorProfiles*>(this), m_uidMgr));
        return *m_rotorAirfoils.back();
    }

    void CPACSRotorAirfoils::RemoveRotorAirfoil(CPACSProfileGeometry& ref)
    {
        for (std::size_t i = 0; i < m_rotorAirfoils.size(); i++) {
            if (m_rotorAirfoils[i].get() == &ref) {
                m_rotorAirfoils.erase(m_rotorAirfoils.begin() + i);
                return;
            }
        }
        throw CTiglError("Element not found");
    }

} // namespace generated
} // namespace tigl
