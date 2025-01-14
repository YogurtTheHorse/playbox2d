// SPDX-FileCopyrightText: 2006-present Erin Catto http://www.gphysics.com
//
// SPDX-License-Identifier: MIT

#include "playbox2d/playbox2d.h"
#include "playbox2d/body.h"

#define PDBASE_LOG_ENABLE
#include "pdbase/pdbase.h"

PBBody* PBBodyCreate(void) {
  PBBody* body = PDBASE_ALLOC(sizeof(PBBody));
  
  body->position = PBVec2MakeEmpty();
  body->rotation = 0.0f;
  body->velocity = PBVec2MakeEmpty();
  body->angularVelocity = 0.0f;
  body->force = PBVec2MakeEmpty();
  body->friction = 0.2f;
  body->width = PBVec2Make(1.0f, 1.0f);
  body->AABBHalfSize = PBVec2GetLength(body->width) * 0.5f;
  body->mass = FLT_MAX;
  body->invMass = 0.0f;
  body->I = FLT_MAX;
  body->invI = 0.0f;
  body->collisionFunc = 0;
  body->tag = 0;
  
  return body;
}

void PBBodyFree(PBBody* body) {
  PDBASE_LOG("playbox: freeing body %p", body);
  PDBASE_FREE(body);
}

void PBBodyCallCollision(PBBody* first, PBBody* second) {
  const char* err = NULL;

  if (first->collisionFunc) {
    pd->lua->pushObject(first, CLASSNAME_BODY, 0);
    pd->lua->pushObject(second, CLASSNAME_BODY, 0);
    pd->lua->callFunction(first->collisionFunc, 2, &err);
  }

  if (second->collisionFunc) {
    pd->lua->pushObject(second, CLASSNAME_BODY, 0);
    pd->lua->pushObject(first, CLASSNAME_BODY, 0);
    pd->lua->callFunction(second->collisionFunc, 2, &err);
  }
}

void PBBodySet(PBBody* body, const PBVec2 w, float m) {
  body->position = PBVec2MakeEmpty();
  body->rotation = 0.0f;
  body->velocity = PBVec2MakeEmpty();
  body->angularVelocity = 0.0f;
  body->force = PBVec2MakeEmpty();
  body->torque = 0.0f;
  body->friction = 0.2f;
  
  body->width = w;
  body->AABBHalfSize = PBVec2GetLength(body->width) * 0.5f;
  body->mass = m;
  
  if(m < FLT_MAX) {
    body->invMass = 1.0f / m;
    body->I = m * (w.x * w.x + w.y * w.y) / 12.0f;
    body->invI = 1.0f / body->I;
  }
  else {
    body->invMass = 0.0f;
    body->I = FLT_MAX;
    body->invI = 0.0f;
  }
}

void PBBodyAddForce(PBBody* body, const PBVec2 f) {
  body->force = PBVec2Add(body->force, f);
}
