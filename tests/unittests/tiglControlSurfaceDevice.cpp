/*
 * Copyright (C) 2007-2013 German Aerospace Center (DLR/SC)
 *
 * Created: 2014-01-28 Mark Geiger <Mark.Geiger@dlr.de>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "test.h"
#include "CCPACSTrailingEdgeDevice.h"
#include "CCPACSWing.h"
#include "CCPACSWingComponentSegment.h"
#include "CCPACSConfigurationManager.h"


#include "TopoDS_Face.hxx"
#include "TopExp_Explorer.hxx"
#include "BRepAdaptor_Surface.hxx"
#include "BRepLProp.hxx"
#include "BRepLProp_SLProps.hxx"
#include "BRepTools.hxx"
#include "GeomLProp_SLProps.hxx"
#include "gp_Pln.hxx"
#include "Geom_Plane.hxx"

using namespace std;

/******************************************************************************/

class TiglControlSurfaceDevice : public ::testing::Test {
 protected:
  static void SetUpTestCase() {
        const char* filename = "TestData/CPACS_30_D150.xml";
        ReturnCode tixiRet;
        TiglReturnCode tiglRet;

        tiglHandle = -1;
        tixiHandle = -1;

        tixiRet = tixiOpenDocument(filename, &tixiHandle);
        ASSERT_TRUE (tixiRet == SUCCESS);
        tiglRet = tiglOpenCPACSConfiguration(tixiHandle, "D150_VAMP", &tiglHandle);
        ASSERT_TRUE(tiglRet == TIGL_SUCCESS);
  }

  static void TearDownTestCase() {
        ASSERT_TRUE(tiglCloseCPACSConfiguration(tiglHandle) == TIGL_SUCCESS);
        ASSERT_TRUE(tixiCloseDocument(tixiHandle) == SUCCESS);
        tiglHandle = -1;
        tixiHandle = -1;
  }

  virtual void SetUp() {}
  virtual void TearDown() {}


  static TixiDocumentHandle           tixiHandle;
  static TiglCPACSConfigurationHandle tiglHandle;
};


TixiDocumentHandle TiglControlSurfaceDevice::tixiHandle = 0;
TiglCPACSConfigurationHandle TiglControlSurfaceDevice::tiglHandle = 0;

//#########################################################################################################

TEST_F(TiglControlSurfaceDevice, tiglGetControlSurfaceCount)
{
    int numDevicesPtr = 0;

    ASSERT_EQ(TIGL_NULL_POINTER, tiglGetControlSurfaceCount(tiglHandle, "D150_VAMP_W1_CompSeg1", NULL         ) );
    ASSERT_EQ(TIGL_UID_ERROR   , tiglGetControlSurfaceCount(tiglHandle, "rmplstlzchn"          , &numDevicesPtr) );
    ASSERT_EQ(TIGL_NOT_FOUND   , tiglGetControlSurfaceCount(-1        , "D150_VAMP_W1_CompSeg1", &numDevicesPtr) );
    ASSERT_EQ(TIGL_SUCCESS     , tiglGetControlSurfaceCount(tiglHandle, "D150_VAMP_W1_CompSeg1", &numDevicesPtr) );
    ASSERT_EQ( numDevicesPtr, 3);
}

TEST_F(TiglControlSurfaceDevice, tiglGetControlSurfaceUID)
{
    char* uid1 = nullptr;
    char* uid2 = nullptr;
    char* uid3 = nullptr;
    ASSERT_EQ(TIGL_NULL_POINTER, tiglGetControlSurfaceUID(tiglHandle, "D150_VAMP_W1_CompSeg1", 1, NULL  ) );
    ASSERT_EQ(TIGL_UID_ERROR   , tiglGetControlSurfaceUID(tiglHandle, "rmplstlzchn"          , 1, &uid1) );
    ASSERT_EQ(TIGL_NOT_FOUND   , tiglGetControlSurfaceUID(-1        , "D150_VAMP_W1_CompSeg1", 1, &uid1) );
    ASSERT_EQ(TIGL_INDEX_ERROR , tiglGetControlSurfaceUID(tiglHandle, "D150_VAMP_W1_CompSeg1", 0, &uid1) );
    ASSERT_EQ(TIGL_SUCCESS     , tiglGetControlSurfaceUID(tiglHandle, "D150_VAMP_W1_CompSeg1", 1, &uid1) );
    ASSERT_EQ(TIGL_SUCCESS     , tiglGetControlSurfaceUID(tiglHandle, "D150_VAMP_W1_CompSeg1", 2, &uid2) );
    ASSERT_EQ(TIGL_SUCCESS     , tiglGetControlSurfaceUID(tiglHandle, "D150_VAMP_W1_CompSeg1", 3, &uid3) );
    ASSERT_EQ(TIGL_INDEX_ERROR , tiglGetControlSurfaceUID(tiglHandle, "D150_VAMP_W1_CompSeg1", 4, &uid3) );
    ASSERT_STREQ(uid1, "D150_VAMP_W1_CompSeg1_innerFlap");
    ASSERT_STREQ(uid2, "D150_VAMP_W1_CompSeg1_outerFlap");
    ASSERT_STREQ(uid3, "D150_VAMP_W1_CompSeg1_aileron");
}

TEST_F(TiglControlSurfaceDevice, tiglGetControlSurfaceType)
{
    TiglControlSurfaceType type1, type2, type3;
    ASSERT_EQ(TIGL_UID_ERROR   , tiglGetControlSurfaceType(tiglHandle, "rmplstlzchn"                    , &type1) );
    ASSERT_EQ(TIGL_NOT_FOUND   , tiglGetControlSurfaceType(-1        , "D150_VAMP_W1_CompSeg1_innerFlap", &type1 ) );
    ASSERT_EQ(TIGL_SUCCESS     , tiglGetControlSurfaceType(tiglHandle, "D150_VAMP_W1_CompSeg1_innerFlap", &type1 ) );
    ASSERT_EQ(TIGL_SUCCESS     , tiglGetControlSurfaceType(tiglHandle, "D150_VAMP_W1_CompSeg1_outerFlap", &type2 ) );
    ASSERT_EQ(TIGL_SUCCESS     , tiglGetControlSurfaceType(tiglHandle, "D150_VAMP_W1_CompSeg1_aileron"  , &type3 ) );
    ASSERT_EQ(TRAILING_EDGE_DEVICE, type1);
    ASSERT_EQ(TRAILING_EDGE_DEVICE, type2);
    ASSERT_EQ(TRAILING_EDGE_DEVICE, type3);
}

TEST_F(TiglControlSurfaceDevice, tiglControlSurfaceGetMinimumControlParameter)
{
    double controlParm1, controlParm2, controlParm3;
    ASSERT_EQ(TIGL_UID_ERROR   , tiglControlSurfaceGetMinimumControlParameter(tiglHandle, "rmplstlzchn"                    , &controlParm1) );
    ASSERT_EQ(TIGL_NOT_FOUND   , tiglControlSurfaceGetMinimumControlParameter(-1        , "D150_VAMP_W1_CompSeg1_innerFlap", &controlParm1 ) );
    ASSERT_EQ(TIGL_SUCCESS     , tiglControlSurfaceGetMinimumControlParameter(tiglHandle, "D150_VAMP_W1_CompSeg1_innerFlap", &controlParm1 ) );
    ASSERT_EQ(TIGL_SUCCESS     , tiglControlSurfaceGetMinimumControlParameter(tiglHandle, "D150_VAMP_W1_CompSeg1_outerFlap", &controlParm2 ) );
    ASSERT_EQ(TIGL_SUCCESS     , tiglControlSurfaceGetMinimumControlParameter(tiglHandle, "D150_VAMP_W1_CompSeg1_aileron"  , &controlParm3 ) );
    ASSERT_EQ( 0, controlParm1);
    ASSERT_EQ( 0, controlParm2);
    ASSERT_EQ(-1, controlParm3);
}

TEST_F(TiglControlSurfaceDevice, tiglControlSurfaceGetMaximumControlParameter)
{
    double controlParm1, controlParm2, controlParm3;
    ASSERT_EQ(TIGL_UID_ERROR   , tiglControlSurfaceGetMaximumControlParameter(tiglHandle, "rmplstlzchn"                    , &controlParm1) );
    ASSERT_EQ(TIGL_NOT_FOUND   , tiglControlSurfaceGetMaximumControlParameter(-1        , "D150_VAMP_W1_CompSeg1_innerFlap", &controlParm1 ) );
    ASSERT_EQ(TIGL_SUCCESS     , tiglControlSurfaceGetMaximumControlParameter(tiglHandle, "D150_VAMP_W1_CompSeg1_innerFlap", &controlParm1 ) );
    ASSERT_EQ(TIGL_SUCCESS     , tiglControlSurfaceGetMaximumControlParameter(tiglHandle, "D150_VAMP_W1_CompSeg1_outerFlap", &controlParm2 ) );
    ASSERT_EQ(TIGL_SUCCESS     , tiglControlSurfaceGetMaximumControlParameter(tiglHandle, "D150_VAMP_W1_CompSeg1_aileron"  , &controlParm3 ) );
    ASSERT_EQ( 1, controlParm1);
    ASSERT_EQ( 1, controlParm2);
    ASSERT_EQ( 1, controlParm3);
}

TEST_F(TiglControlSurfaceDevice, tiglControlSurfaceGetAndSetControlParameter)
{
    double controlParm1, controlParm2, controlParm3;
    ASSERT_EQ(TIGL_UID_ERROR   , tiglControlSurfaceGetControlParameter(tiglHandle, "rmplstlzchn"                    , &controlParm1) );
    ASSERT_EQ(TIGL_NOT_FOUND   , tiglControlSurfaceGetControlParameter(-1        , "D150_VAMP_W1_CompSeg1_innerFlap", &controlParm1 ) );
    ASSERT_EQ(TIGL_SUCCESS     , tiglControlSurfaceGetControlParameter(tiglHandle, "D150_VAMP_W1_CompSeg1_innerFlap", &controlParm1 ) );
    ASSERT_EQ(TIGL_SUCCESS     , tiglControlSurfaceGetControlParameter(tiglHandle, "D150_VAMP_W1_CompSeg1_outerFlap", &controlParm2 ) );
    ASSERT_EQ(TIGL_SUCCESS     , tiglControlSurfaceGetControlParameter(tiglHandle, "D150_VAMP_W1_CompSeg1_aileron"  , &controlParm3 ) );
    ASSERT_EQ( 0, controlParm1);
    ASSERT_EQ( 0, controlParm2);
    ASSERT_EQ( 0, controlParm3);

    double controlParm;

    // error codes for set control parameter
    ASSERT_EQ(TIGL_UID_ERROR   , tiglControlSurfaceSetControlParameter(tiglHandle, "rmplstlzchn"                    , 5.0) );
    ASSERT_EQ(TIGL_NOT_FOUND   , tiglControlSurfaceSetControlParameter(-1        , "D150_VAMP_W1_CompSeg1_innerFlap", 5.0 ) );

    // clamp to max/min control parameter
    ASSERT_EQ(TIGL_SUCCESS     , tiglControlSurfaceSetControlParameter(tiglHandle, "D150_VAMP_W1_CompSeg1_innerFlap", 5.0 ) );
    ASSERT_EQ(TIGL_SUCCESS     , tiglControlSurfaceGetControlParameter(tiglHandle, "D150_VAMP_W1_CompSeg1_innerFlap", &controlParm ) );
    ASSERT_EQ(1, controlParm);

    ASSERT_EQ(TIGL_SUCCESS     , tiglControlSurfaceSetControlParameter(tiglHandle, "D150_VAMP_W1_CompSeg1_innerFlap", -5.0 ) );
    ASSERT_EQ(TIGL_SUCCESS     , tiglControlSurfaceGetControlParameter(tiglHandle, "D150_VAMP_W1_CompSeg1_innerFlap", &controlParm ) );
    ASSERT_EQ(0, controlParm);

    // value between min and max
    ASSERT_EQ(TIGL_SUCCESS     , tiglControlSurfaceSetControlParameter(tiglHandle, "D150_VAMP_W1_CompSeg1_innerFlap", 0.33 ) );
    ASSERT_EQ(TIGL_SUCCESS     , tiglControlSurfaceGetControlParameter(tiglHandle, "D150_VAMP_W1_CompSeg1_innerFlap", &controlParm ) );
    ASSERT_NEAR(0.33, controlParm, 1e-10);

}

TEST(TiglControlSurfaceDeviceSimple, setControlParameterAndExport)
{
    TiglHandleWrapper handle("TestData/simpletest-flaps.cpacs.xml", "");
    ASSERT_EQ(TIGL_SUCCESS, tiglControlSurfaceSetControlParameter(handle, "Flap", 1.0));
    tiglExportConfiguration(handle, "TestData/export/simpletest-flaps.stp", TIGL_TRUE, 0.0);
}
