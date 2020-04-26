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
#include "CPACSSheet3D.h"
#include "CPACSSheetList3D.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSSheet3D::CPACSSheet3D(CPACSSheetList3D* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
        , m_sheetPoints(this, m_uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
    }

    CPACSSheet3D::~CPACSSheet3D()
    {
        if (m_uidMgr) m_uidMgr->TryUnregisterObject(m_uID);
    }

    const CPACSSheetList3D* CPACSSheet3D::GetParent() const
    {
        return m_parent;
    }

    CPACSSheetList3D* CPACSSheet3D::GetParent()
    {
        return m_parent;
    }

    const CTiglUIDObject* CPACSSheet3D::GetNextUIDParent() const
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDObject* CPACSSheet3D::GetNextUIDParent()
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDManager& CPACSSheet3D::GetUIDManager()
    {
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSSheet3D::GetUIDManager() const
    {
        return *m_uidMgr;
    }

    void CPACSSheet3D::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read attribute uID
        if (tixi::TixiCheckAttribute(tixiHandle, xpath, "uID")) {
            m_uID = tixi::TixiGetAttribute<std::string>(tixiHandle, xpath, "uID");
            if (m_uID.empty()) {
                LOG(WARNING) << "Required attribute uID is empty at xpath " << xpath;
            }
        }
        else {
            LOG(ERROR) << "Required attribute uID is missing at xpath " << xpath;
        }

        // read element name
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/name")) {
            m_name = tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/name");
            if (m_name.empty()) {
                LOG(WARNING) << "Required element name is empty at xpath " << xpath;
            }
        }
        else {
            LOG(ERROR) << "Required element name is missing at xpath " << xpath;
        }

        // read element description
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/description")) {
            m_description = tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/description");
            if (m_description->empty()) {
                LOG(WARNING) << "Optional element description is present but empty at xpath " << xpath;
            }
        }

        // read element sheetPoints
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/sheetPoints")) {
            m_sheetPoints.ReadCPACS(tixiHandle, xpath + "/sheetPoints");
        }
        else {
            LOG(ERROR) << "Required element sheetPoints is missing at xpath " << xpath;
        }

        if (m_uidMgr && !m_uID.empty()) m_uidMgr->RegisterObject(m_uID, *this);
    }

    void CPACSSheet3D::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        const std::vector<std::string> childElemOrder = { "name", "description", "sheetPoints" };

        // write attribute uID
        tixi::TixiSaveAttribute(tixiHandle, xpath, "uID", m_uID);

        // write element name
        tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/name", childElemOrder);
        tixi::TixiSaveElement(tixiHandle, xpath + "/name", m_name);

        // write element description
        if (m_description) {
            tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/description", childElemOrder);
            tixi::TixiSaveElement(tixiHandle, xpath + "/description", *m_description);
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/description")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/description");
            }
        }

        // write element sheetPoints
        tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/sheetPoints", childElemOrder);
        m_sheetPoints.WriteCPACS(tixiHandle, xpath + "/sheetPoints");

    }

    const std::string& CPACSSheet3D::GetUID() const
    {
        return m_uID;
    }

    void CPACSSheet3D::SetUID(const std::string& value)
    {
        if (m_uidMgr && value != m_uID) {
            if (m_uID.empty()) {
                m_uidMgr->RegisterObject(value, *this);
            }
            else {
                m_uidMgr->UpdateObjectUID(m_uID, value);
            }
        }
        m_uID = value;
    }

    const std::string& CPACSSheet3D::GetName() const
    {
        return m_name;
    }

    void CPACSSheet3D::SetName(const std::string& value)
    {
        m_name = value;
    }

    const boost::optional<std::string>& CPACSSheet3D::GetDescription() const
    {
        return m_description;
    }

    void CPACSSheet3D::SetDescription(const boost::optional<std::string>& value)
    {
        m_description = value;
    }

    const CPACSSheetPoints& CPACSSheet3D::GetSheetPoints() const
    {
        return m_sheetPoints;
    }

    CPACSSheetPoints& CPACSSheet3D::GetSheetPoints()
    {
        return m_sheetPoints;
    }

} // namespace generated
} // namespace tigl
