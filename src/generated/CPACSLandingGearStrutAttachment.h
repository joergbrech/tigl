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

#include <boost/optional.hpp>
#include <boost/utility/in_place_factory.hpp>
#include <string>
#include <tixi.h>
#include "CPACSStringerFramePositionUIDs.h"
#include "CPACSSupportBeam.h"
#include "CPACSUIDSequence.h"
#include "CPACSWingAttachmentPositioning.h"
#include "CreateIfNotExists.h"
#include "ITiglUIDRefObject.h"
#include "tigl_internal.h"

namespace tigl
{
class CTiglUIDManager;
class CTiglUIDObject;

namespace generated
{
    class CPACSStrutAssembly;

    // This class is used in:
    // CPACSStrutAssembly

    /// @brief Definition of the wing attachment
    /// 
    /// Definition of the wing attachment, if
    /// attached to the wing. The definition
    /// includes the position of the landing gear as
    /// well as the information to which spars resp.
    /// supportBeam the gear is attached.
    /// 
    class CPACSLandingGearStrutAttachment : public ITiglUIDRefObject
    {
    public:
        TIGL_EXPORT CPACSLandingGearStrutAttachment(CPACSStrutAssembly* parent, CTiglUIDManager* uidMgr);

        TIGL_EXPORT virtual ~CPACSLandingGearStrutAttachment();

        TIGL_EXPORT CPACSStrutAssembly* GetParent();

        TIGL_EXPORT const CPACSStrutAssembly* GetParent() const;

        TIGL_EXPORT virtual CTiglUIDObject* GetNextUIDParent();
        TIGL_EXPORT virtual const CTiglUIDObject* GetNextUIDParent() const;

        TIGL_EXPORT CTiglUIDManager& GetUIDManager();
        TIGL_EXPORT const CTiglUIDManager& GetUIDManager() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT bool ValidateChoices() const;

        TIGL_EXPORT virtual const boost::optional<std::string>& GetSparSegmentUID_choice1() const;
        TIGL_EXPORT virtual void SetSparSegmentUID_choice1(const boost::optional<std::string>& value);

        TIGL_EXPORT virtual const boost::optional<CPACSSupportBeam>& GetSupportBeam_choice2() const;
        TIGL_EXPORT virtual boost::optional<CPACSSupportBeam>& GetSupportBeam_choice2();

        TIGL_EXPORT virtual const boost::optional<CPACSStringerFramePositionUIDs>& GetStringerFramePositionUIDs_choice3() const;
        TIGL_EXPORT virtual boost::optional<CPACSStringerFramePositionUIDs>& GetStringerFramePositionUIDs_choice3();

        TIGL_EXPORT virtual const boost::optional<CPACSUIDSequence>& GetStructuralMountUIDs_choice4() const;
        TIGL_EXPORT virtual boost::optional<CPACSUIDSequence>& GetStructuralMountUIDs_choice4();

        TIGL_EXPORT virtual const boost::optional<std::string>& GetRibDefinitionUID_choice5() const;
        TIGL_EXPORT virtual void SetRibDefinitionUID_choice5(const boost::optional<std::string>& value);

        TIGL_EXPORT virtual const boost::optional<int>& GetRibNumber_choice5() const;
        TIGL_EXPORT virtual void SetRibNumber_choice5(const boost::optional<int>& value);

        TIGL_EXPORT virtual const boost::optional<CPACSWingAttachmentPositioning>& GetPositioning() const;
        TIGL_EXPORT virtual boost::optional<CPACSWingAttachmentPositioning>& GetPositioning();

        TIGL_EXPORT virtual CPACSSupportBeam& GetSupportBeam_choice2(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveSupportBeam_choice2();

        TIGL_EXPORT virtual CPACSStringerFramePositionUIDs& GetStringerFramePositionUIDs_choice3(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveStringerFramePositionUIDs_choice3();

        TIGL_EXPORT virtual CPACSUIDSequence& GetStructuralMountUIDs_choice4(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveStructuralMountUIDs_choice4();

        TIGL_EXPORT virtual CPACSWingAttachmentPositioning& GetPositioning(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemovePositioning();

    protected:
        CPACSStrutAssembly* m_parent;

        CTiglUIDManager* m_uidMgr;

        /// UID of the second spar, where the landing gear is attached to. Only used, if the landing gear is attached between two spars.
        boost::optional<std::string>                    m_sparSegmentUID_choice1;

        boost::optional<CPACSSupportBeam>               m_supportBeam_choice2;

        boost::optional<CPACSStringerFramePositionUIDs> m_stringerFramePositionUIDs_choice3;

        /// UID of the structural mount
        boost::optional<CPACSUIDSequence>               m_structuralMountUIDs_choice4;

        /// UID of a set of ribs (ribDefinition)
        boost::optional<std::string>                    m_ribDefinitionUID_choice5;

        /// Number of the rib in the rib set (ribDefinition)
        boost::optional<int>                            m_ribNumber_choice5;

        boost::optional<CPACSWingAttachmentPositioning> m_positioning;

    private:
        TIGL_EXPORT const CTiglUIDObject* GetNextUIDObject() const final;
        TIGL_EXPORT void NotifyUIDChange(const std::string& oldUid, const std::string& newUid) final;

        CPACSLandingGearStrutAttachment(const CPACSLandingGearStrutAttachment&) = delete;
        CPACSLandingGearStrutAttachment& operator=(const CPACSLandingGearStrutAttachment&) = delete;

        CPACSLandingGearStrutAttachment(CPACSLandingGearStrutAttachment&&) = delete;
        CPACSLandingGearStrutAttachment& operator=(CPACSLandingGearStrutAttachment&&) = delete;
    };
} // namespace generated

// Aliases in tigl namespace
using CCPACSLandingGearStrutAttachment = generated::CPACSLandingGearStrutAttachment;
using CCPACSStrutAssembly = generated::CPACSStrutAssembly;
} // namespace tigl
