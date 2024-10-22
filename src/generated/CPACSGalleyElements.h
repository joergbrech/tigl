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
#include "tigl_internal.h"
#include "UniquePtr.h"

namespace tigl
{
class CTiglUIDManager;
class CTiglUIDObject;

namespace generated
{
    class CPACSGalleyElement;
    class CPACSDeckElements;

    // This class is used in:
    // CPACSDeckElements

    /// @brief Galley elements
    /// 
    /// Galley element collection type
    /// 
    class CPACSGalleyElements
    {
    public:
        TIGL_EXPORT CPACSGalleyElements(CPACSDeckElements* parent, CTiglUIDManager* uidMgr);

        TIGL_EXPORT virtual ~CPACSGalleyElements();

        TIGL_EXPORT CPACSDeckElements* GetParent();

        TIGL_EXPORT const CPACSDeckElements* GetParent() const;

        TIGL_EXPORT virtual CTiglUIDObject* GetNextUIDParent();
        TIGL_EXPORT virtual const CTiglUIDObject* GetNextUIDParent() const;

        TIGL_EXPORT CTiglUIDManager& GetUIDManager();
        TIGL_EXPORT const CTiglUIDManager& GetUIDManager() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const std::vector<std::unique_ptr<CPACSGalleyElement>>& GetGalleyElements() const;
        TIGL_EXPORT virtual std::vector<std::unique_ptr<CPACSGalleyElement>>& GetGalleyElements();

        TIGL_EXPORT virtual CPACSGalleyElement& AddGalleyElement();
        TIGL_EXPORT virtual void RemoveGalleyElement(CPACSGalleyElement& ref);

    protected:
        CPACSDeckElements* m_parent;

        CTiglUIDManager* m_uidMgr;

        /// Galley element for use in the decks
        std::vector<std::unique_ptr<CPACSGalleyElement>> m_galleyElements;

    private:
        CPACSGalleyElements(const CPACSGalleyElements&) = delete;
        CPACSGalleyElements& operator=(const CPACSGalleyElements&) = delete;

        CPACSGalleyElements(CPACSGalleyElements&&) = delete;
        CPACSGalleyElements& operator=(CPACSGalleyElements&&) = delete;
    };
} // namespace generated

// Aliases in tigl namespace
using CCPACSGalleyElements = generated::CPACSGalleyElements;
using CCPACSGalleyElement = generated::CPACSGalleyElement;
using CCPACSDeckElements = generated::CPACSDeckElements;
} // namespace tigl
