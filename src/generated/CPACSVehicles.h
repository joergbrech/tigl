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
#include <CCPACSEngines.h>
#include <CCPACSProfiles.h>
#include <string>
#include <tixi.h>
#include "CPACSAircraft.h"
#include "CPACSMaterials.h"
#include "CPACSRotorcraft.h"
#include "CPACSStructuralElements.h"
#include "CreateIfNotExists.h"
#include "tigl_internal.h"

namespace tigl
{
class CTiglUIDManager;

namespace generated
{
    // This class is used in:
    // CPACSCpacs

    // generated from /xsd:schema/xsd:complexType[921]
    /// @brief vehiclesType
    /// 
    /// Vehicles node, containing all the vehicle-specific
    /// data. This includes the vehicles themselves, as well as
    /// components that are used as parts of the vehicles.
    /// 
    class CPACSVehicles
    {
    public:
        TIGL_EXPORT CPACSVehicles(CTiglUIDManager* uidMgr);
        TIGL_EXPORT virtual ~CPACSVehicles();

        TIGL_EXPORT CTiglUIDManager& GetUIDManager();
        TIGL_EXPORT const CTiglUIDManager& GetUIDManager() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const boost::optional<CPACSAircraft>& GetAircraft() const;
        TIGL_EXPORT virtual boost::optional<CPACSAircraft>& GetAircraft();

        TIGL_EXPORT virtual const boost::optional<CPACSRotorcraft>& GetRotorcraft() const;
        TIGL_EXPORT virtual boost::optional<CPACSRotorcraft>& GetRotorcraft();

        TIGL_EXPORT virtual const boost::optional<CCPACSEngines>& GetEngines() const;
        TIGL_EXPORT virtual boost::optional<CCPACSEngines>& GetEngines();

        TIGL_EXPORT virtual const boost::optional<CCPACSProfiles>& GetProfiles() const;
        TIGL_EXPORT virtual boost::optional<CCPACSProfiles>& GetProfiles();

        TIGL_EXPORT virtual const boost::optional<CPACSStructuralElements>& GetStructuralElements() const;
        TIGL_EXPORT virtual boost::optional<CPACSStructuralElements>& GetStructuralElements();

        TIGL_EXPORT virtual const boost::optional<CPACSMaterials>& GetMaterials() const;
        TIGL_EXPORT virtual boost::optional<CPACSMaterials>& GetMaterials();

        TIGL_EXPORT virtual CPACSAircraft& GetAircraft(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveAircraft();

        TIGL_EXPORT virtual CPACSRotorcraft& GetRotorcraft(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveRotorcraft();

        TIGL_EXPORT virtual CCPACSEngines& GetEngines(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveEngines();

        TIGL_EXPORT virtual CCPACSProfiles& GetProfiles(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveProfiles();

        TIGL_EXPORT virtual CPACSStructuralElements& GetStructuralElements(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveStructuralElements();

        TIGL_EXPORT virtual CPACSMaterials& GetMaterials(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveMaterials();

    protected:
        CTiglUIDManager* m_uidMgr;

        boost::optional<CPACSAircraft>           m_aircraft;
        boost::optional<CPACSRotorcraft>         m_rotorcraft;
        boost::optional<CCPACSEngines>           m_engines;
        boost::optional<CCPACSProfiles>          m_profiles;
        boost::optional<CPACSStructuralElements> m_structuralElements;
        boost::optional<CPACSMaterials>          m_materials;

    private:
        CPACSVehicles(const CPACSVehicles&) = delete;
        CPACSVehicles& operator=(const CPACSVehicles&) = delete;

        CPACSVehicles(CPACSVehicles&&) = delete;
        CPACSVehicles& operator=(CPACSVehicles&&) = delete;
    };
} // namespace generated

// Aliases in tigl namespace
using CCPACSVehicles = generated::CPACSVehicles;
} // namespace tigl
