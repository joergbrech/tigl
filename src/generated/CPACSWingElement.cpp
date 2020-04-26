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
#include "CCPACSWingSectionElements.h"
#include "CPACSWingElement.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSWingElement::CPACSWingElement(CCPACSWingSectionElements* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
        , m_transformation(reinterpret_cast<CCPACSWingSectionElement*>(this), m_uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
    }

    CPACSWingElement::~CPACSWingElement()
    {
        if (m_uidMgr) m_uidMgr->TryUnregisterObject(m_uID);
        if (m_uidMgr) {
            if (!m_airfoilUID.empty()) m_uidMgr->TryUnregisterReference(m_airfoilUID, *this);
        }
    }

    const CCPACSWingSectionElements* CPACSWingElement::GetParent() const
    {
        return m_parent;
    }

    CCPACSWingSectionElements* CPACSWingElement::GetParent()
    {
        return m_parent;
    }

    const CTiglUIDObject* CPACSWingElement::GetNextUIDParent() const
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDObject* CPACSWingElement::GetNextUIDParent()
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDManager& CPACSWingElement::GetUIDManager()
    {
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSWingElement::GetUIDManager() const
    {
        return *m_uidMgr;
    }

    void CPACSWingElement::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
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

        // read element airfoilUID
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/airfoilUID")) {
            m_airfoilUID = tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/airfoilUID");
            if (m_airfoilUID.empty()) {
                LOG(WARNING) << "Required element airfoilUID is empty at xpath " << xpath;
            }
            if (m_uidMgr && !m_airfoilUID.empty()) m_uidMgr->RegisterReference(m_airfoilUID, *this);
        }
        else {
            LOG(ERROR) << "Required element airfoilUID is missing at xpath " << xpath;
        }

        // read element transformation
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/transformation")) {
            m_transformation.ReadCPACS(tixiHandle, xpath + "/transformation");
        }
        else {
            LOG(ERROR) << "Required element transformation is missing at xpath " << xpath;
        }

        if (m_uidMgr && !m_uID.empty()) m_uidMgr->RegisterObject(m_uID, *this);
    }

    void CPACSWingElement::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write attribute uID
        tixi::TixiSaveAttribute(tixiHandle, xpath, "uID", m_uID);

        // write element name
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/name");
        tixi::TixiSaveElement(tixiHandle, xpath + "/name", m_name);

        // write element description
        if (m_description) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/description");
            tixi::TixiSaveElement(tixiHandle, xpath + "/description", *m_description);
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/description")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/description");
            }
        }

        // write element airfoilUID
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/airfoilUID");
        tixi::TixiSaveElement(tixiHandle, xpath + "/airfoilUID", m_airfoilUID);

        // write element transformation
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/transformation");
        m_transformation.WriteCPACS(tixiHandle, xpath + "/transformation");

    }

    const std::string& CPACSWingElement::GetUID() const
    {
        return m_uID;
    }

    void CPACSWingElement::SetUID(const std::string& value)
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

    const std::string& CPACSWingElement::GetName() const
    {
        return m_name;
    }

    void CPACSWingElement::SetName(const std::string& value)
    {
        m_name = value;
    }

    const boost::optional<std::string>& CPACSWingElement::GetDescription() const
    {
        return m_description;
    }

    void CPACSWingElement::SetDescription(const boost::optional<std::string>& value)
    {
        m_description = value;
    }

    const std::string& CPACSWingElement::GetAirfoilUID() const
    {
        return m_airfoilUID;
    }

    void CPACSWingElement::SetAirfoilUID(const std::string& value)
    {
        if (m_uidMgr) {
            if (!m_airfoilUID.empty()) m_uidMgr->TryUnregisterReference(m_airfoilUID, *this);
            if (!value.empty()) m_uidMgr->RegisterReference(value, *this);
        }
        m_airfoilUID = value;
    }

    const CCPACSTransformation& CPACSWingElement::GetTransformation() const
    {
        return m_transformation;
    }

    CCPACSTransformation& CPACSWingElement::GetTransformation()
    {
        return m_transformation;
    }

    const CTiglUIDObject* CPACSWingElement::GetNextUIDObject() const
    {
        return this;
    }

    void CPACSWingElement::NotifyUIDChange(const std::string& oldUid, const std::string& newUid)
    {
        if (m_airfoilUID == oldUid) {
            m_airfoilUID = newUid;
        }
    }

} // namespace generated
} // namespace tigl
