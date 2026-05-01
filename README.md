https://github.com/user-attachments/assets/647799a2-7161-4e21-8998-d1b216627c51

# so_long

A lightweight 2D game built in C as part of the 42 School curriculum, focused on graphics programming fundamentals.

## About

**so_long** explores core concepts in 2D game development using the **MiniLibX** — 42's internal graphical library. The project covers:

- Window management & event handling
- Texture and sprite rendering
- Basic gameplay mechanics
- Keyboard & mouse input

Beyond graphics, the project reinforces rigorous C programming, algorithm design, and independent research skills.

## Platform

> ⚠️ **macOS only** — Compilation flags and key codes are tuned for Apple platforms and keyboards.

## Installation

```bash
git clone https://github.com/jocuni-p/so_long.git
cd so_long
```

**Standard build:**
```bash
make
```

**Bonus build:**
```bash
make bonus
```

**Clean up:**
```bash
make clean    # removes object files
make fclean   # full clean, including binaries
make re       # full rebuild
```

## Usage

**Standard mode:**
```bash
./so_long maps/valid/map_6.ber
```

**Bonus mode:**
```bash
./so_long_bonus maps/valid_bonus/map_bonus_6.ber
```
