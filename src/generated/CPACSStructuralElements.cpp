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
#include "CPACSStructuralElements.h"
#include "CPACSVehicles.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "CTiglUIDObject.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSStructuralElements::CPACSStructuralElements(CPACSVehicles* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
    }

    CPACSStructuralElements::~CPACSStructuralElements()
    {
    }

    const CPACSVehicles* CPACSStructuralElements::GetParent() const
    {
        return m_parent;
    }

    CPACSVehicles* CPACSStructuralElements::GetParent()
    {
        return m_parent;
    }

    const CTiglUIDObject* CPACSStructuralElements::GetNextUIDParent() const
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDObject* CPACSStructuralElements::GetNextUIDParent()
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDManager& CPACSStructuralElements::GetUIDManager()
    {
        if (!m_uidMgr) {
            throw CTiglError("UIDManager is null");
        }
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSStructuralElements::GetUIDManager() const
    {
        if (!m_uidMgr) {
            throw CTiglError("UIDManager is null");
        }
        return *m_uidMgr;
    }

    void CPACSStructuralElements::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read element sheetBasedStructuralElements
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/sheetBasedStructuralElements")) {
            m_sheetBasedStructuralElements = boost::in_place(this, m_uidMgr);
            try {
                m_sheetBasedStructuralElements->ReadCPACS(tixiHandle, xpath + "/sheetBasedStructuralElements");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read sheetBasedStructuralElements at xpath " << xpath << ": " << e.what();
                m_sheetBasedStructuralElements = boost::none;
            }
        }

        // read element profileBasedStructuralElements
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/profileBasedStructuralElements")) {
            m_profileBasedStructuralElements = boost::in_place(this, m_uidMgr);
            try {
                m_profileBasedStructuralElements->ReadCPACS(tixiHandle, xpath + "/profileBasedStructuralElements");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read profileBasedStructuralElements at xpath " << xpath << ": " << e.what();
                m_profileBasedStructuralElements = boost::none;
            }
        }

        // read element structuralWallElements
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/structuralWallElements")) {
            m_structuralWallElements = boost::in_place(this, m_uidMgr);
            try {
                m_structuralWallElements->ReadCPACS(tixiHandle, xpath + "/structuralWallElements");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read structuralWallElements at xpath " << xpath << ": " << e.what();
                m_structuralWallElements = boost::none;
            }
        }

        // read element pressureBulkheads
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/pressureBulkheads")) {
            m_pressureBulkheads = boost::in_place(this, m_uidMgr);
            try {
                m_pressureBulkheads->ReadCPACS(tixiHandle, xpath + "/pressureBulkheads");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read pressureBulkheads at xpath " << xpath << ": " << e.what();
                m_pressureBulkheads = boost::none;
            }
        }

        // read element windows
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/windows")) {
            m_windows = boost::in_place(this, m_uidMgr);
            try {
                m_windows->ReadCPACS(tixiHandle, xpath + "/windows");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read windows at xpath " << xpath << ": " << e.what();
                m_windows = boost::none;
            }
        }

        // read element doors
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/doors")) {
            m_doors = boost::in_place(this, m_uidMgr);
            try {
                m_doors->ReadCPACS(tixiHandle, xpath + "/doors");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read doors at xpath " << xpath << ": " << e.what();
                m_doors = boost::none;
            }
        }

        // read element doorSurroundStructures
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/doorSurroundStructures")) {
            m_doorSurroundStructures = boost::in_place(this, m_uidMgr);
            try {
                m_doorSurroundStructures->ReadCPACS(tixiHandle, xpath + "/doorSurroundStructures");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read doorSurroundStructures at xpath " << xpath << ": " << e.what();
                m_doorSurroundStructures = boost::none;
            }
        }

        // read element seatModules
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/seatModules")) {
            m_seatModules = boost::in_place(this, m_uidMgr);
            try {
                m_seatModules->ReadCPACS(tixiHandle, xpath + "/seatModules");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read seatModules at xpath " << xpath << ": " << e.what();
                m_seatModules = boost::none;
            }
        }

        // read element rivets
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/rivets")) {
            m_rivets = boost::in_place(this, m_uidMgr);
            try {
                m_rivets->ReadCPACS(tixiHandle, xpath + "/rivets");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read rivets at xpath " << xpath << ": " << e.what();
                m_rivets = boost::none;
            }
        }

    }

    void CPACSStructuralElements::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write element sheetBasedStructuralElements
        if (m_sheetBasedStructuralElements) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/sheetBasedStructuralElements");
            m_sheetBasedStructuralElements->WriteCPACS(tixiHandle, xpath + "/sheetBasedStructuralElements");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/sheetBasedStructuralElements")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/sheetBasedStructuralElements");
            }
        }

        // write element profileBasedStructuralElements
        if (m_profileBasedStructuralElements) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/profileBasedStructuralElements");
            m_profileBasedStructuralElements->WriteCPACS(tixiHandle, xpath + "/profileBasedStructuralElements");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/profileBasedStructuralElements")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/profileBasedStructuralElements");
            }
        }

        // write element structuralWallElements
        if (m_structuralWallElements) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/structuralWallElements");
            m_structuralWallElements->WriteCPACS(tixiHandle, xpath + "/structuralWallElements");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/structuralWallElements")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/structuralWallElements");
            }
        }

        // write element pressureBulkheads
        if (m_pressureBulkheads) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/pressureBulkheads");
            m_pressureBulkheads->WriteCPACS(tixiHandle, xpath + "/pressureBulkheads");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/pressureBulkheads")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/pressureBulkheads");
            }
        }

        // write element windows
        if (m_windows) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/windows");
            m_windows->WriteCPACS(tixiHandle, xpath + "/windows");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/windows")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/windows");
            }
        }

        // write element doors
        if (m_doors) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/doors");
            m_doors->WriteCPACS(tixiHandle, xpath + "/doors");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/doors")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/doors");
            }
        }

        // write element doorSurroundStructures
        if (m_doorSurroundStructures) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/doorSurroundStructures");
            m_doorSurroundStructures->WriteCPACS(tixiHandle, xpath + "/doorSurroundStructures");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/doorSurroundStructures")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/doorSurroundStructures");
            }
        }

        // write element seatModules
        if (m_seatModules) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/seatModules");
            m_seatModules->WriteCPACS(tixiHandle, xpath + "/seatModules");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/seatModules")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/seatModules");
            }
        }

        // write element rivets
        if (m_rivets) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/rivets");
            m_rivets->WriteCPACS(tixiHandle, xpath + "/rivets");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/rivets")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/rivets");
            }
        }

    }

    const boost::optional<CPACSSheetBasedStructuralElements>& CPACSStructuralElements::GetSheetBasedStructuralElements() const
    {
        return m_sheetBasedStructuralElements;
    }

    boost::optional<CPACSSheetBasedStructuralElements>& CPACSStructuralElements::GetSheetBasedStructuralElements()
    {
        return m_sheetBasedStructuralElements;
    }

    const boost::optional<CPACSProfileBasedStructuralElements>& CPACSStructuralElements::GetProfileBasedStructuralElements() const
    {
        return m_profileBasedStructuralElements;
    }

    boost::optional<CPACSProfileBasedStructuralElements>& CPACSStructuralElements::GetProfileBasedStructuralElements()
    {
        return m_profileBasedStructuralElements;
    }

    const boost::optional<CPACSStructuralWallElements>& CPACSStructuralElements::GetStructuralWallElements() const
    {
        return m_structuralWallElements;
    }

    boost::optional<CPACSStructuralWallElements>& CPACSStructuralElements::GetStructuralWallElements()
    {
        return m_structuralWallElements;
    }

    const boost::optional<CCPACSPressureBulkheads>& CPACSStructuralElements::GetPressureBulkheads() const
    {
        return m_pressureBulkheads;
    }

    boost::optional<CCPACSPressureBulkheads>& CPACSStructuralElements::GetPressureBulkheads()
    {
        return m_pressureBulkheads;
    }

    const boost::optional<CPACSWindows>& CPACSStructuralElements::GetWindows() const
    {
        return m_windows;
    }

    boost::optional<CPACSWindows>& CPACSStructuralElements::GetWindows()
    {
        return m_windows;
    }

    const boost::optional<CCPACSDoors>& CPACSStructuralElements::GetDoors() const
    {
        return m_doors;
    }

    boost::optional<CCPACSDoors>& CPACSStructuralElements::GetDoors()
    {
        return m_doors;
    }

    const boost::optional<CPACSDoorSurroundStructuresAssembly>& CPACSStructuralElements::GetDoorSurroundStructures() const
    {
        return m_doorSurroundStructures;
    }

    boost::optional<CPACSDoorSurroundStructuresAssembly>& CPACSStructuralElements::GetDoorSurroundStructures()
    {
        return m_doorSurroundStructures;
    }

    const boost::optional<CPACSSeatModules>& CPACSStructuralElements::GetSeatModules() const
    {
        return m_seatModules;
    }

    boost::optional<CPACSSeatModules>& CPACSStructuralElements::GetSeatModules()
    {
        return m_seatModules;
    }

    const boost::optional<CPACSRivets>& CPACSStructuralElements::GetRivets() const
    {
        return m_rivets;
    }

    boost::optional<CPACSRivets>& CPACSStructuralElements::GetRivets()
    {
        return m_rivets;
    }

    CPACSSheetBasedStructuralElements& CPACSStructuralElements::GetSheetBasedStructuralElements(CreateIfNotExistsTag)
    {
        if (!m_sheetBasedStructuralElements)
            m_sheetBasedStructuralElements = boost::in_place(this, m_uidMgr);
        return *m_sheetBasedStructuralElements;
    }

    void CPACSStructuralElements::RemoveSheetBasedStructuralElements()
    {
        m_sheetBasedStructuralElements = boost::none;
    }

    CPACSProfileBasedStructuralElements& CPACSStructuralElements::GetProfileBasedStructuralElements(CreateIfNotExistsTag)
    {
        if (!m_profileBasedStructuralElements)
            m_profileBasedStructuralElements = boost::in_place(this, m_uidMgr);
        return *m_profileBasedStructuralElements;
    }

    void CPACSStructuralElements::RemoveProfileBasedStructuralElements()
    {
        m_profileBasedStructuralElements = boost::none;
    }

    CPACSStructuralWallElements& CPACSStructuralElements::GetStructuralWallElements(CreateIfNotExistsTag)
    {
        if (!m_structuralWallElements)
            m_structuralWallElements = boost::in_place(this, m_uidMgr);
        return *m_structuralWallElements;
    }

    void CPACSStructuralElements::RemoveStructuralWallElements()
    {
        m_structuralWallElements = boost::none;
    }

    CCPACSPressureBulkheads& CPACSStructuralElements::GetPressureBulkheads(CreateIfNotExistsTag)
    {
        if (!m_pressureBulkheads)
            m_pressureBulkheads = boost::in_place(this, m_uidMgr);
        return *m_pressureBulkheads;
    }

    void CPACSStructuralElements::RemovePressureBulkheads()
    {
        m_pressureBulkheads = boost::none;
    }

    CPACSWindows& CPACSStructuralElements::GetWindows(CreateIfNotExistsTag)
    {
        if (!m_windows)
            m_windows = boost::in_place(this, m_uidMgr);
        return *m_windows;
    }

    void CPACSStructuralElements::RemoveWindows()
    {
        m_windows = boost::none;
    }

    CCPACSDoors& CPACSStructuralElements::GetDoors(CreateIfNotExistsTag)
    {
        if (!m_doors)
            m_doors = boost::in_place(this, m_uidMgr);
        return *m_doors;
    }

    void CPACSStructuralElements::RemoveDoors()
    {
        m_doors = boost::none;
    }

    CPACSDoorSurroundStructuresAssembly& CPACSStructuralElements::GetDoorSurroundStructures(CreateIfNotExistsTag)
    {
        if (!m_doorSurroundStructures)
            m_doorSurroundStructures = boost::in_place(this, m_uidMgr);
        return *m_doorSurroundStructures;
    }

    void CPACSStructuralElements::RemoveDoorSurroundStructures()
    {
        m_doorSurroundStructures = boost::none;
    }

    CPACSSeatModules& CPACSStructuralElements::GetSeatModules(CreateIfNotExistsTag)
    {
        if (!m_seatModules)
            m_seatModules = boost::in_place(this, m_uidMgr);
        return *m_seatModules;
    }

    void CPACSStructuralElements::RemoveSeatModules()
    {
        m_seatModules = boost::none;
    }

    CPACSRivets& CPACSStructuralElements::GetRivets(CreateIfNotExistsTag)
    {
        if (!m_rivets)
            m_rivets = boost::in_place(this, m_uidMgr);
        return *m_rivets;
    }

    void CPACSStructuralElements::RemoveRivets()
    {
        m_rivets = boost::none;
    }

} // namespace generated
} // namespace tigl
