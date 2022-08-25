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
#include "CPACSAircraftControlElement.h"
#include "CPACSAircraftControlElements.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "CTiglUIDObject.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSAircraftControlElement::CPACSAircraftControlElement(CPACSAircraftControlElements* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
    }

    CPACSAircraftControlElement::~CPACSAircraftControlElement()
    {
        if (m_uidMgr) {
            if (m_controlDeviceUID_choice1 && !m_controlDeviceUID_choice1->empty()) m_uidMgr->TryUnregisterReference(*m_controlDeviceUID_choice1, *this);
            if (m_controlDistributorUID_choice2 && !m_controlDistributorUID_choice2->empty()) m_uidMgr->TryUnregisterReference(*m_controlDistributorUID_choice2, *this);
        }
    }

    const CPACSAircraftControlElements* CPACSAircraftControlElement::GetParent() const
    {
        return m_parent;
    }

    CPACSAircraftControlElements* CPACSAircraftControlElement::GetParent()
    {
        return m_parent;
    }

    const CTiglUIDObject* CPACSAircraftControlElement::GetNextUIDParent() const
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDObject* CPACSAircraftControlElement::GetNextUIDParent()
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDManager& CPACSAircraftControlElement::GetUIDManager()
    {
        if (!m_uidMgr) {
            throw CTiglError("UIDManager is null");
        }
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSAircraftControlElement::GetUIDManager() const
    {
        if (!m_uidMgr) {
            throw CTiglError("UIDManager is null");
        }
        return *m_uidMgr;
    }

    void CPACSAircraftControlElement::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read element controlDeviceUID
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/controlDeviceUID")) {
            m_controlDeviceUID_choice1 = tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/controlDeviceUID");
            if (m_controlDeviceUID_choice1->empty()) {
                LOG(WARNING) << "Optional element controlDeviceUID is present but empty at xpath " << xpath;
            }
            if (m_uidMgr && !m_controlDeviceUID_choice1->empty()) m_uidMgr->RegisterReference(*m_controlDeviceUID_choice1, *this);
        }

        // read element controlParameter
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/controlParameter")) {
            m_controlParameter_choice1 = tixi::TixiGetElement<double>(tixiHandle, xpath + "/controlParameter");
        }

        // read element controlDistributorUID
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/controlDistributorUID")) {
            m_controlDistributorUID_choice2 = tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/controlDistributorUID");
            if (m_controlDistributorUID_choice2->empty()) {
                LOG(WARNING) << "Optional element controlDistributorUID is present but empty at xpath " << xpath;
            }
            if (m_uidMgr && !m_controlDistributorUID_choice2->empty()) m_uidMgr->RegisterReference(*m_controlDistributorUID_choice2, *this);
        }

        // read element commandInput
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/commandInput")) {
            m_commandInput_choice2 = tixi::TixiGetElement<double>(tixiHandle, xpath + "/commandInput");
        }

        if (!ValidateChoices()) {
            LOG(ERROR) << "Invalid choice configuration at xpath " << xpath;
        }
    }

    void CPACSAircraftControlElement::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write element controlDeviceUID
        if (m_controlDeviceUID_choice1) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/controlDeviceUID");
            tixi::TixiSaveElement(tixiHandle, xpath + "/controlDeviceUID", *m_controlDeviceUID_choice1);
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/controlDeviceUID")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/controlDeviceUID");
            }
        }

        // write element controlParameter
        if (m_controlParameter_choice1) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/controlParameter");
            tixi::TixiSaveElement(tixiHandle, xpath + "/controlParameter", *m_controlParameter_choice1);
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/controlParameter")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/controlParameter");
            }
        }

        // write element controlDistributorUID
        if (m_controlDistributorUID_choice2) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/controlDistributorUID");
            tixi::TixiSaveElement(tixiHandle, xpath + "/controlDistributorUID", *m_controlDistributorUID_choice2);
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/controlDistributorUID")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/controlDistributorUID");
            }
        }

        // write element commandInput
        if (m_commandInput_choice2) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/commandInput");
            tixi::TixiSaveElement(tixiHandle, xpath + "/commandInput", *m_commandInput_choice2);
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/commandInput")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/commandInput");
            }
        }

    }

    bool CPACSAircraftControlElement::ValidateChoices() const
    {
        return
        (
            (
                (
                    // mandatory elements of this choice must be there
                    m_controlDeviceUID_choice1.is_initialized()
                    &&
                    m_controlParameter_choice1.is_initialized()
                    &&
                    // elements of other choices must not be there
                    !(
                        m_controlDistributorUID_choice2.is_initialized()
                        ||
                        m_commandInput_choice2.is_initialized()
                    )
                )
                +
                (
                    // mandatory elements of this choice must be there
                    m_controlDistributorUID_choice2.is_initialized()
                    &&
                    m_commandInput_choice2.is_initialized()
                    &&
                    // elements of other choices must not be there
                    !(
                        m_controlDeviceUID_choice1.is_initialized()
                        ||
                        m_controlParameter_choice1.is_initialized()
                    )
                )
                == 1
            )
        )
        ;
    }

    const boost::optional<std::string>& CPACSAircraftControlElement::GetControlDeviceUID_choice1() const
    {
        return m_controlDeviceUID_choice1;
    }

    void CPACSAircraftControlElement::SetControlDeviceUID_choice1(const boost::optional<std::string>& value)
    {
        if (m_uidMgr) {
            if (m_controlDeviceUID_choice1 && !m_controlDeviceUID_choice1->empty()) m_uidMgr->TryUnregisterReference(*m_controlDeviceUID_choice1, *this);
            if (value && !value->empty()) m_uidMgr->RegisterReference(*value, *this);
        }
        m_controlDeviceUID_choice1 = value;
    }

    const boost::optional<double>& CPACSAircraftControlElement::GetControlParameter_choice1() const
    {
        return m_controlParameter_choice1;
    }

    void CPACSAircraftControlElement::SetControlParameter_choice1(const boost::optional<double>& value)
    {
        m_controlParameter_choice1 = value;
    }

    const boost::optional<std::string>& CPACSAircraftControlElement::GetControlDistributorUID_choice2() const
    {
        return m_controlDistributorUID_choice2;
    }

    void CPACSAircraftControlElement::SetControlDistributorUID_choice2(const boost::optional<std::string>& value)
    {
        if (m_uidMgr) {
            if (m_controlDistributorUID_choice2 && !m_controlDistributorUID_choice2->empty()) m_uidMgr->TryUnregisterReference(*m_controlDistributorUID_choice2, *this);
            if (value && !value->empty()) m_uidMgr->RegisterReference(*value, *this);
        }
        m_controlDistributorUID_choice2 = value;
    }

    const boost::optional<double>& CPACSAircraftControlElement::GetCommandInput_choice2() const
    {
        return m_commandInput_choice2;
    }

    void CPACSAircraftControlElement::SetCommandInput_choice2(const boost::optional<double>& value)
    {
        m_commandInput_choice2 = value;
    }

    const CTiglUIDObject* CPACSAircraftControlElement::GetNextUIDObject() const
    {
        return GetNextUIDParent();
    }

    void CPACSAircraftControlElement::NotifyUIDChange(const std::string& oldUid, const std::string& newUid)
    {
        if (m_controlDeviceUID_choice1 && *m_controlDeviceUID_choice1 == oldUid) {
            m_controlDeviceUID_choice1 = newUid;
        }
        if (m_controlDistributorUID_choice2 && *m_controlDistributorUID_choice2 == oldUid) {
            m_controlDistributorUID_choice2 = newUid;
        }
    }

} // namespace generated
} // namespace tigl
