// Copyright (c) 2016 RISC Software GmbH
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
#include <CCPACSTransformation.h>
#include <string>
#include <TiglSymmetryAxis.h>
#include <tixi.h>
#include "CPACSLinkToFile.h"
#include "tigl_internal.h"

namespace tigl
{
    class CTiglUIDManager;
    class CCPACSExternalObjects;
    
    namespace generated
    {
        // This class is used in:
        // CPACSGenericGeometryComponents
        
        // generated from /xsd:schema/xsd:complexType[387]
        class CPACSGenericGeometricComponent
        {
        public:
            TIGL_EXPORT CPACSGenericGeometricComponent(CCPACSExternalObjects* parent, CTiglUIDManager* uidMgr);
            
            TIGL_EXPORT virtual ~CPACSGenericGeometricComponent();
            
            TIGL_EXPORT CCPACSExternalObjects* GetParent() const;
            
            TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
            TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;
            
            TIGL_EXPORT virtual const std::string& GetUID() const;
            TIGL_EXPORT virtual void SetUID(const std::string& value);
            
            TIGL_EXPORT virtual const boost::optional<TiglSymmetryAxis>& GetSymmetry() const;
            TIGL_EXPORT virtual void SetSymmetry(const TiglSymmetryAxis& value);
            TIGL_EXPORT virtual void SetSymmetry(const boost::optional<TiglSymmetryAxis>& value);
            
            TIGL_EXPORT virtual const std::string& GetName() const;
            TIGL_EXPORT virtual void SetName(const std::string& value);
            
            TIGL_EXPORT virtual const boost::optional<std::string>& GetDescription() const;
            TIGL_EXPORT virtual void SetDescription(const std::string& value);
            TIGL_EXPORT virtual void SetDescription(const boost::optional<std::string>& value);
            
            TIGL_EXPORT virtual const boost::optional<std::string>& GetParentUID() const;
            TIGL_EXPORT virtual void SetParentUID(const std::string& value);
            TIGL_EXPORT virtual void SetParentUID(const boost::optional<std::string>& value);
            
            TIGL_EXPORT virtual const CCPACSTransformation& GetTransformation() const;
            TIGL_EXPORT virtual CCPACSTransformation& GetTransformation();
            
            TIGL_EXPORT virtual const CPACSLinkToFile& GetLinkToFile() const;
            TIGL_EXPORT virtual CPACSLinkToFile& GetLinkToFile();
            
        protected:
            CCPACSExternalObjects* m_parent;
            
            CTiglUIDManager* m_uidMgr;
            
            std::string                       m_uID;
            boost::optional<TiglSymmetryAxis> m_symmetry;
            std::string                       m_name;
            boost::optional<std::string>      m_description;
            boost::optional<std::string>      m_parentUID;
            CCPACSTransformation              m_transformation;
            CPACSLinkToFile                   m_linkToFile;
            
        private:
            #ifdef HAVE_CPP11
            CPACSGenericGeometricComponent(const CPACSGenericGeometricComponent&) = delete;
            CPACSGenericGeometricComponent& operator=(const CPACSGenericGeometricComponent&) = delete;
            
            CPACSGenericGeometricComponent(CPACSGenericGeometricComponent&&) = delete;
            CPACSGenericGeometricComponent& operator=(CPACSGenericGeometricComponent&&) = delete;
            #else
            CPACSGenericGeometricComponent(const CPACSGenericGeometricComponent&);
            CPACSGenericGeometricComponent& operator=(const CPACSGenericGeometricComponent&);
            #endif
        };
    }
    
    // CPACSGenericGeometricComponent is customized, use type CCPACSExternalObject directly
}
