/*****************************************************************************

INTEL CORPORATION PROPRIETARY INFORMATION
This software is supplied under the terms of a license agreement or
nondisclosure agreement with Intel Corporation and may not be copied
or disclosed except in accordance with the terms of that agreement.
Copyright(c) 2005-2014 Intel Corporation. All Rights Reserved.

*****************************************************************************/

#include <stdio.h>
#include "mfxdefs.h"
#include "mfxstructures.h"

#define OPTION_IMPL             0x001
#define OPTION_GEOMETRY         0x002
#define OPTION_BITRATE          0x004
#define OPTION_FRAMERATE        0x008
#define OPTION_MEASURE_LATENCY  0x010

#define OPTIONS_DECODE \
    (OPTION_IMPL)

#define OPTIONS_ENCODE \
    (OPTION_IMPL | OPTION_GEOMETRY | OPTION_BITRATE | OPTION_FRAMERATE)

#define OPTIONS_VPP \
    (OPTION_IMPL | OPTION_GEOMETRY)

#define OPTIONS_TRANSCODE \
    (OPTION_IMPL | OPTION_BITRATE | OPTION_FRAMERATE)

#define MSDK_MAX_PATH 280

struct CmdOptionsCtx {
    // bitmask of the options accepted by the program
    unsigned int options;
    // program name, if not set will be corrected to argv[0]
    const char* program;
    // function to print program usage, can be NULL
    void (*usage)(CmdOptionsCtx* ctx);
};

struct CmdOptionsValues {
    mfxIMPL impl; // OPTION_IMPL

    char SourceName[MSDK_MAX_PATH]; // OPTION_FSOURCE
    char SinkName[MSDK_MAX_PATH];   // OPTION_FSINK

    mfxU16 Width; // OPTION_GEOMETRY
    mfxU16 Height;

    mfxU16 Bitrate; // OPTION_BITRATE

    mfxU16 FrameRateN; // OPTION_FRAMERATE
    mfxU16 FrameRateD;

    bool MeasureLatency; // OPTION_MEASURE_LATENCY
};

struct CmdOptions {
    CmdOptionsCtx ctx;
    CmdOptionsValues values;
};

void ParseOptions(int argc, char** argv, CmdOptions* options);
