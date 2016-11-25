/*****************************************************************************

INTEL CORPORATION PROPRIETARY INFORMATION
This software is supplied under the terms of a license agreement or
nondisclosure agreement with Intel Corporation and may not be copied
or disclosed except in accordance with the terms of that agreement.
Copyright(c) 2005-2014 Intel Corporation. All Rights Reserved.

*****************************************************************************/

#include "common_utils.h"
#include "cmd_options.h"

static void usage(CmdOptionsCtx* ctx)
{
    printf(
        "Initializes Media SDK library and queries its implementation type and version number.\n"
        "\n"
        "Usage: %s [options]\n", ctx->program);
}

int main(int argc, char** argv)
{
    mfxStatus sts = MFX_ERR_NONE;
    CmdOptions options;

    // Read options from the command line (if any is given)
    memset(&options, 0, sizeof(CmdOptions));
    options.ctx.options = OPTION_IMPL;
    options.ctx.usage = usage;
    // Set default values:
    options.values.impl = MFX_IMPL_AUTO_ANY;

    // here we parse options
    ParseOptions(argc, argv, &options);

    // Initialize Intel Media SDK session
    // - MFX_IMPL_AUTO_ANY selects HW acceleration if available (on any adapter)
    // - Version 1.0 is selected for greatest backwards compatibility.
    // OS specific notes
    // - On Windows both SW and HW libraries may present
    // - On Linux HW library only is available
    // If more recent API features are needed, change the version accordingly
    mfxIMPL impl = options.values.impl;
    mfxVersion ver = { {0, 1} };
    MFXVideoSession session;
    sts = Initialize(impl, ver, &session, NULL);
    MSDK_CHECK_RESULT(sts, MFX_ERR_NONE, sts);

    // Query selected implementation and version
    sts = session.QueryIMPL(&impl);
    MSDK_CHECK_RESULT(sts, MFX_ERR_NONE, sts);

    sts = session.QueryVersion(&ver);
    MSDK_CHECK_RESULT(sts, MFX_ERR_NONE, sts);

    printf("\n\nImplementation: %s \t\t API Version: %d.%d\n",
           (impl == MFX_IMPL_SOFTWARE) ? "SOFTWARE" : "HARDWARE",
           ver.Major, ver.Minor);

    session.Close();

    return 0;
}
