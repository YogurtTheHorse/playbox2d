// SPDX-FileCopyrightText: 2006-present Erin Catto http://www.gphysics.com
//
// SPDX-License-Identifier: MIT

#ifndef DUSTINMIERAU_PLAYBOX2D_H
#define DUSTINMIERAU_PLAYBOX2D_H

#include "pd_api.h"

#define CLASSNAME_WORLD "playbox2d.world"
#define CLASSNAME_BODY "playbox2d.body"
#define CLASSNAME_JOINT "playbox2d.joint"

#ifndef PBPositionCorrection
#define PBPositionCorrection 1
#endif

#ifndef PBWarmStarting
#define PBWarmStarting 0
#endif

#ifndef PBAccumulateImpulses
#define PBAccumulateImpulses 1
#endif

extern void register_playbox2d(PlaydateAPI*);

#endif
