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
#include "CCPACSExternalObjects.h"
#include "CPACSGenericGeometricComponent.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSGenericGeometricComponent::CPACSGenericGeometricComponent(CCPACSExternalObjects* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
        , m_transformation(reinterpret_cast<CCPACSExternalObject*>(this), m_uidMgr)
        , m_linkToFile(reinterpret_cast<CCPACSExternalObject*>(this))
    {
        //assert(parent != NULL);
        m_parent = parent;
    }

    CPACSGenericGeometricComponent::~CPACSGenericGeometricComponent()
    {
        if (m_uidMgr) m_uidMgr->TryUnregisterObject(m_uID);
        if (m_uidMgr) {
            if (m_parentUID && !m_parentUID->empty()) m_uidMgr->TryUnregisterReference(*m_parentUID, *this);
        }
    }

    const CCPACSExternalObjects* CPACSGenericGeometricComponent::GetParent() const
    {
        return m_parent;
    }

    CCPACSExternalObjects* CPACSGenericGeometricComponent::GetParent()
    {
        return m_parent;
    }

    const CTiglUIDObject* CPACSGenericGeometricComponent::GetNextUIDParent() const
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDObject* CPACSGenericGeometricComponent::GetNextUIDParent()
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDManager& CPACSGenericGeometricComponent::GetUIDManager()
    {
        if (!m_uidMgr) {
            throw CTiglError("UIDManager is null");
        }
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSGenericGeometricComponent::GetUIDManager() const
    {
        if (!m_uidMgr) {
            throw CTiglError("UIDManager is null");
        }
        return *m_uidMgr;
    }

    void CPACSGenericGeometricComponent::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
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

        // read attribute symmetry
        if (tixi::TixiCheckAttribute(tixiHandle, xpath, "symmetry")) {
            m_symmetry = stringToTiglSymmetryAxis(tixi::TixiGetAttribute<std::string>(tixiHandle, xpath, "symmetry"));
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

        // read element parentUID
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/parentUID")) {
            m_parentUID = tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/parentUID");
            if (m_parentUID->empty()) {
                LOG(WARNING) << "Optional element parentUID is present but empty at xpath " << xpath;
            }
            if (m_uidMgr && !m_parentUID->empty()) m_uidMgr->RegisterReference(*m_parentUID, *this);
        }

        // read element transformation
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/transformation")) {
            m_transformation.ReadCPACS(tixiHandle, xpath + "/transformation");
        }
        else {
            LOG(ERROR) << "Required element transformation is missing at xpath " << xpath;
        }

        // read element linkToFile
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/linkToFile")) {
            m_linkToFile.ReadCPACS(tixiHandle, xpath + "/linkToFile");
        }
        else {
            LOG(ERROR) << "Required element linkToFile is missing at xpath " << xpath;
        }

        if (m_uidMgr && !m_uID.empty()) m_uidMgr->RegisterObject(m_uID, *this);
    }

    void CPACSGenericGeometricComponent::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write attribute uID
        tixi::TixiSaveAttribute(tixiHandle, xpath, "uID", m_uID);

        // write attribute symmetry
        if (m_symmetry) {
            tixi::TixiSaveAttribute(tixiHandle, xpath, "symmetry", TiglSymmetryAxisToString(*m_symmetry));
        }
        else {
            if (tixi::TixiCheckAttribute(tixiHandle, xpath, "symmetry")) {
                tixi::TixiRemoveAttribute(tixiHandle, xpath, "symmetry");
            }
        }

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

        // write element parentUID
        if (m_parentUID) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/parentUID");
            tixi::TixiSaveElement(tixiHandle, xpath + "/parentUID", *m_parentUID);
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/parentUID")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/parentUID");
            }
        }

        // write element transformation
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/transformation");
        m_transformation.WriteCPACS(tixiHandle, xpath + "/transformation");

        // write element linkToFile
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/linkToFile");
        m_linkToFile.WriteCPACS(tixiHandle, xpath + "/linkToFile");

    }

    const std::string& CPACSGenericGeometricComponent::GetUID() const
    {
        return m_uID;
    }

    void CPACSGenericGeometricComponent::SetUID(const std::string& value)
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

    const boost::optional<TiglSymmetryAxis>& CPACSGenericGeometricComponent::GetSymmetry() const
    {
        return m_symmetry;
    }

    void CPACSGenericGeometricComponent::SetSymmetry(const boost::optional<TiglSymmetryAxis>& value)
    {
        m_symmetry = value;
    }

    const std::string& CPACSGenericGeometricComponent::GetName() const
    {
        return m_name;
    }

    void CPACSGenericGeometricComponent::SetName(const std::string& value)
    {
        m_name = value;
    }

    const boost::optional<std::string>& CPACSGenericGeometricComponent::GetDescription() const
    {
        return m_description;
    }

    void CPACSGenericGeometricComponent::SetDescription(const boost::optional<std::string>& value)
    {
        m_description = value;
    }

    const boost::optional<std::string>& CPACSGenericGeometricComponent::GetParentUID() const
    {
        return m_parentUID;
    }

    void CPACSGenericGeometricComponent::SetParentUID(const boost::optional<std::string>& value)
    {
        if (m_uidMgr) {
            if (m_parentUID && !m_parentUID->empty()) m_uidMgr->TryUnregisterReference(*m_parentUID, *this);
            if (value && !value->empty()) m_uidMgr->RegisterReference(*value, *this);
        }
        m_parentUID = value;
    }

    const CCPACSTransformation& CPACSGenericGeometricComponent::GetTransformation() const
    {
        return m_transformation;
    }

    CCPACSTransformation& CPACSGenericGeometricComponent::GetTransformation()
    {
        return m_transformation;
    }

    const CPACSLinkToFile& CPACSGenericGeometricComponent::GetLinkToFile() const
    {
        return m_linkToFile;
    }

    CPACSLinkToFile& CPACSGenericGeometricComponent::GetLinkToFile()
    {
        return m_linkToFile;
    }

    const CTiglUIDObject* CPACSGenericGeometricComponent::GetNextUIDObject() const
    {
        return this;
    }

    void CPACSGenericGeometricComponent::NotifyUIDChange(const std::string& oldUid, const std::string& newUid)
    {
        if (m_parentUID && *m_parentUID == oldUid) {
            m_parentUID = newUid;
        }
    }

} // namespace generated
} // namespace tigl
