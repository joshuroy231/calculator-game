# TI Game Engine

A game engine for the TI-84 Plus CE graphing calculator

## TODO
- Change tile collision to be more similar to current entity collision---should help to reduce weird clips
    - Or maybe not (might result in super crappy tile clipping)
- Add a camera system
    - Create bigger implementation world to test camera system
        - Maybe find a better way to store/create tilemaps
- Figure out `is_falling`/`is_on_ground` status for jumping and stuff
- Generalize the current hard-coded friction value
- Create macro constants for standard values (like for velocity: `SLUGGISH`, `LEISURELY`, `UNBOTHERED`, `BRISK`, `BLISTERING`)
- Figure out the entity collision system with `onCollision()` functions and stuff