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
#include <CCPACSControlSurfaceSkinCutout.h>
#include <CCPACSControlSurfaceSkinCutOutBorder.h>
#include <string>
#include <tixi.h>
#include "CPACSCutOutControlPoints.h"
#include "CPACSCutOutProfiles.h"
#include "CreateIfNotExists.h"
#include "tigl_internal.h"

namespace tigl
{
class CCPACSTrailingEdgeDevice;

namespace generated
{
    // This class is used in:
    // CPACSTrailingEdgeDevice

    // generated from /xsd:schema/xsd:complexType[194]
    /// @brief Cut out of the parents structure due to a control
    /// surface.
    /// 
    /// Optional. Definition of the parents structure cut out
    /// due to a control surface. The cut out is split into three parts:
    /// cut out of the upper and lower skin and the definition of an
    /// profile conecting the cut out of the upper and lower skin.
    /// An example for wing cut outs can be found in the
    /// picture below:
    /// @see wingCutOut
    /// In the default configuration the cut out is as wide as
    /// the control surface. If additional spacing is necessary inner
    /// and outer border may be set.
    /// 
    class CPACSControlSurfaceWingCutOut
    {
    public:
        TIGL_EXPORT CPACSControlSurfaceWingCutOut(CCPACSTrailingEdgeDevice* parent);

        TIGL_EXPORT virtual ~CPACSControlSurfaceWingCutOut();

        TIGL_EXPORT CCPACSTrailingEdgeDevice* GetParent();

        TIGL_EXPORT const CCPACSTrailingEdgeDevice* GetParent() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const CCPACSControlSurfaceSkinCutout& GetUpperSkin() const;
        TIGL_EXPORT virtual CCPACSControlSurfaceSkinCutout& GetUpperSkin();

        TIGL_EXPORT virtual const CCPACSControlSurfaceSkinCutout& GetLowerSkin() const;
        TIGL_EXPORT virtual CCPACSControlSurfaceSkinCutout& GetLowerSkin();

        TIGL_EXPORT virtual const boost::optional<CPACSCutOutControlPoints>& GetCutOutProfileControlPoint() const;
        TIGL_EXPORT virtual boost::optional<CPACSCutOutControlPoints>& GetCutOutProfileControlPoint();

        TIGL_EXPORT virtual const boost::optional<CPACSCutOutProfiles>& GetCutOutProfiles() const;
        TIGL_EXPORT virtual boost::optional<CPACSCutOutProfiles>& GetCutOutProfiles();

        TIGL_EXPORT virtual const boost::optional<CCPACSControlSurfaceSkinCutOutBorder>& GetInnerBorder() const;
        TIGL_EXPORT virtual boost::optional<CCPACSControlSurfaceSkinCutOutBorder>& GetInnerBorder();

        TIGL_EXPORT virtual const boost::optional<CCPACSControlSurfaceSkinCutOutBorder>& GetOuterBorder() const;
        TIGL_EXPORT virtual boost::optional<CCPACSControlSurfaceSkinCutOutBorder>& GetOuterBorder();

        TIGL_EXPORT virtual CPACSCutOutControlPoints& GetCutOutProfileControlPoint(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveCutOutProfileControlPoint();

        TIGL_EXPORT virtual CPACSCutOutProfiles& GetCutOutProfiles(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveCutOutProfiles();

        TIGL_EXPORT virtual CCPACSControlSurfaceSkinCutOutBorder& GetInnerBorder(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveInnerBorder();

        TIGL_EXPORT virtual CCPACSControlSurfaceSkinCutOutBorder& GetOuterBorder(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveOuterBorder();

    protected:
        CCPACSTrailingEdgeDevice* m_parent;

        CCPACSControlSurfaceSkinCutout                        m_upperSkin;
        CCPACSControlSurfaceSkinCutout                        m_lowerSkin;
        boost::optional<CPACSCutOutControlPoints>             m_cutOutProfileControlPoint;
        boost::optional<CPACSCutOutProfiles>                  m_cutOutProfiles;
        boost::optional<CCPACSControlSurfaceSkinCutOutBorder> m_innerBorder;
        boost::optional<CCPACSControlSurfaceSkinCutOutBorder> m_outerBorder;

    private:
        CPACSControlSurfaceWingCutOut(const CPACSControlSurfaceWingCutOut&) = delete;
        CPACSControlSurfaceWingCutOut& operator=(const CPACSControlSurfaceWingCutOut&) = delete;

        CPACSControlSurfaceWingCutOut(CPACSControlSurfaceWingCutOut&&) = delete;
        CPACSControlSurfaceWingCutOut& operator=(CPACSControlSurfaceWingCutOut&&) = delete;
    };
} // namespace generated

// Aliases in tigl namespace
using CCPACSControlSurfaceWingCutOut = generated::CPACSControlSurfaceWingCutOut;
} // namespace tigl
