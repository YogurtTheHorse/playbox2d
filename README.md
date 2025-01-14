# playbox2d for Playdate

[![MIT License](https://img.shields.io/github/license/DidierMalenfant/playbox2d)](https://spdx.org/licenses/MIT.html) [![Lua Version](https://img.shields.io/badge/Lua-5.4-yellowgreen)](https://lua.org) [![Toybox Compatible](https://img.shields.io/badge/toybox.py-compatible-brightgreen)](https://toyboxpy.io) [![Latest Version](https://img.shields.io/github/v/tag/DidierMalenfant/playbox2d)](https://github.com/DidierMalenfant/playbox2d/tags)

**playbox2d** is a port of [box2d lite](https://github.com/erincatto/box2d-lite) for the [Playdate SDK](https://play.date/dev/). Original port by [Dustin Mierau](https://github.com/mierau).

You can add it to your **Playdate** project by installing [**toybox.py**](https://toyboxpy.io), going to your project folder in a Terminal window and typing:

```console
toybox add playbox2d
toybox update
```

Then you [simply](https://github.com/toyboxpy/toybox.py#using-c-toyboxes) need to add `toyboxes/toybox.mk` to your makefile.

This **toybox** contains **Lua** toys for you to play with.

---

### world (Lua)

##### `playbox2d.world.new(gravity_x,gravity_y,iterations)`

##### `playbox2d.world.addBody(body)`

##### `playbox2d.world.removeBody(body)`

##### `playbox2d.world.addJoint(joint)`

##### `playbox2d.world.removeJoint(joint)`

##### `playbox2d.world.clear()`

##### `playbox2d.world.update(step)`

##### `playbox2d.world.getArbiterCount() -> count`

##### `playbox2d.world.getArbiterPosition(index) -> p1.x,p1.y,p2.x,p2.y...`

##### `playbox2d.world.setPixelScale(scale)`

##### `playbox2d.world.getNumberOfContacts() -> value`

### body (Lua)

##### `playbox2d.body.new(width,height,mass)`

##### `playbox2d.body.addForce(x,y)`

##### `playbox2d.body.setCenter(x,y)`

##### `playbox2d.body.getCenter() -> x,y`

##### `playbox2d.body.setRotation(rotation )`

##### `playbox2d.body.getRotation() -> rotation`

##### `playbox2d.body.setVelocity(x,y)`

##### `playbox2d.body.getVelocity() -> x,y`

##### `playbox2d.body.setAngularVelocity(velocity)`

##### `playbox2d.body.setForce(x, y)`

##### `playbox2d.body.setTorque(torque)`

##### `playbox2d.body.setSize(width, height)`

##### `playbox2d.body.getSize() -> width, height`

##### `playbox2d.body.setFriction(friction)`

##### `playbox2d.body.setMass(mass)`

##### `playbox2d.body.setI(value)`

##### `playbox2d.body.getPolygon() -> x1,y1,x2,y2,x3,y3,x4,y4`

### joint (Lua)

##### `playbox2d.joint.new(anchor_x,anchor_y)`

##### `playbox2d.joint.getPoints() -> x1.x,x1.y,p1.x,p1.y,x2.x,x2.y,p2.x,p2,y`

##### `playbox2d.joint.setSoftness(value)`

##### `playbox2d.joint.setBiasFactor(value)`

## Sample code

You can find an example of using **playbox2d** in the little [**playbox2d-sample**](https://github.com/DidierMalenfant/playbox2d-sample) project.

## License

**playbox2d** is distributed under the terms of the [MIT](https://spdx.org/licenses/MIT.html) license.
