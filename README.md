# TI-84 Plus CE Game Engine

A game engine for the TI-84 Plus CE graphing calculator

## TODO
- Change tile collision to be more similar to current entity collision---should help to reduce weird clips
    - Or maybe not (might result in super crappy tile clipping)
- Maybe find a better way to store/create tilemaps
- Figure out `is_falling`/`is_on_ground` status for jumping and stuff
- Generalize the current hard-coded friction value
- Create macro constants for standard values (like for velocity: `SLUGGISH`, `LEISURELY`, `UNBOTHERED`, `BRISK`, `BLISTERING`)
- Figure out the entity collision system with `onCollision()` functions and stuff
- Switch coordinate system (reverse y axis)
- Resolve the dependency structure between entity and actuator
- Make consistent the use of `this`
- Change entity profile to be stored as an int/enum id
- Lock down all enum usages using enum class
- Work out a proper implementation template
- Add an execution frame to event object
  - Need to actually add a frame counter to the game engine
  - Event queue should probably be quite big in this case

### Implementation Game
- This will help guide my design decisions. Will just try to make mario or something
#### Entity Ideas
- Player
- Mystery Box
- Goomba
- Mushroom
- Fire Flower
- Flag pole
- Hammer bro