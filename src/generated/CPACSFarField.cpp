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
#include "CPACSCFDTool.h"
#include "CPACSFarField.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDObject.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSFarField::CPACSFarField(CPACSCFDTool* parent)
        : m_referenceLength(0)
        , m_multiplier(0)
    {
        //assert(parent != NULL);
        m_parent = parent;
    }

    CPACSFarField::~CPACSFarField()
    {
    }

    const CPACSCFDTool* CPACSFarField::GetParent() const
    {
        return m_parent;
    }

    CPACSCFDTool* CPACSFarField::GetParent()
    {
        return m_parent;
    }

    const CTiglUIDObject* CPACSFarField::GetNextUIDParent() const
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDObject* CPACSFarField::GetNextUIDParent()
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    void CPACSFarField::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read element type
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/type")) {
            m_type = stringToTiglFarFieldType(tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/type"));
        }
        else {
            LOG(ERROR) << "Required element type is missing at xpath " << xpath;
        }

        // read element referenceLength
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/referenceLength")) {
            m_referenceLength = tixi::TixiGetElement<double>(tixiHandle, xpath + "/referenceLength");
        }
        else {
            LOG(ERROR) << "Required element referenceLength is missing at xpath " << xpath;
        }

        // read element multiplier
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/multiplier")) {
            m_multiplier = tixi::TixiGetElement<double>(tixiHandle, xpath + "/multiplier");
        }
        else {
            LOG(ERROR) << "Required element multiplier is missing at xpath " << xpath;
        }

    }

    void CPACSFarField::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        const std::vector<std::string> childElemOrder = { "type", "referenceLength", "multiplier" };

        // write element type
        tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/type", childElemOrder);
        tixi::TixiSaveElement(tixiHandle, xpath + "/type", TiglFarFieldTypeToString(m_type));

        // write element referenceLength
        tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/referenceLength", childElemOrder);
        tixi::TixiSaveElement(tixiHandle, xpath + "/referenceLength", m_referenceLength);

        // write element multiplier
        tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/multiplier", childElemOrder);
        tixi::TixiSaveElement(tixiHandle, xpath + "/multiplier", m_multiplier);

    }

    const TiglFarFieldType& CPACSFarField::GetType() const
    {
        return m_type;
    }

    void CPACSFarField::SetType(const TiglFarFieldType& value)
    {
        m_type = value;
    }

    const double& CPACSFarField::GetReferenceLength() const
    {
        return m_referenceLength;
    }

    void CPACSFarField::SetReferenceLength(const double& value)
    {
        m_referenceLength = value;
    }

    const double& CPACSFarField::GetMultiplier() const
    {
        return m_multiplier;
    }

    void CPACSFarField::SetMultiplier(const double& value)
    {
        m_multiplier = value;
    }

} // namespace generated
} // namespace tigl
