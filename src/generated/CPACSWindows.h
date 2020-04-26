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

#include <string>
#include <tixi.h>
#include <vector>
#include "CTiglUIDObject.h"
#include "tigl_internal.h"
#include "UniquePtr.h"

namespace tigl
{
class CTiglUIDManager;

namespace generated
{
    class CPACSCutOut;
    class CPACSStructuralElements;

    // This class is used in:
    // CPACSStructuralElements

    // generated from /xsd:schema/xsd:complexType[939]
    /// @brief windowsType
    /// 
    /// Windows type, containing windows
    /// 
    class CPACSWindows : public CTiglReqUIDObject
    {
    public:
        TIGL_EXPORT CPACSWindows(CPACSStructuralElements* parent, CTiglUIDManager* uidMgr);

        TIGL_EXPORT virtual ~CPACSWindows();

        TIGL_EXPORT CPACSStructuralElements* GetParent();

        TIGL_EXPORT const CPACSStructuralElements* GetParent() const;

        TIGL_EXPORT virtual CTiglUIDObject* GetNextUIDParent();
        TIGL_EXPORT virtual const CTiglUIDObject* GetNextUIDParent() const;

        TIGL_EXPORT CTiglUIDManager& GetUIDManager();
        TIGL_EXPORT const CTiglUIDManager& GetUIDManager() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const std::string& GetUID() const;
        TIGL_EXPORT virtual void SetUID(const std::string& value);

        TIGL_EXPORT virtual const std::vector<std::unique_ptr<CPACSCutOut>>& GetWindows() const;
        TIGL_EXPORT virtual std::vector<std::unique_ptr<CPACSCutOut>>& GetWindows();

        TIGL_EXPORT virtual CPACSCutOut& AddWindow();
        TIGL_EXPORT virtual void RemoveWindow(CPACSCutOut& ref);

    protected:
        CPACSStructuralElements* m_parent;

        CTiglUIDManager* m_uidMgr;

        std::string                               m_uID;
        std::vector<std::unique_ptr<CPACSCutOut>> m_windows;

    private:
        CPACSWindows(const CPACSWindows&) = delete;
        CPACSWindows& operator=(const CPACSWindows&) = delete;

        CPACSWindows(CPACSWindows&&) = delete;
        CPACSWindows& operator=(CPACSWindows&&) = delete;
    };
} // namespace generated

// Aliases in tigl namespace
using CCPACSWindows = generated::CPACSWindows;
using CCPACSCutOut = generated::CPACSCutOut;
using CCPACSStructuralElements = generated::CPACSStructuralElements;
} // namespace tigl
