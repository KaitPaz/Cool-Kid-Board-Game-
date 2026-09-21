# 🎲 Cool Kid Game

**A terminal board game where the board fights back.**

Two players race from square 0 to square 35. Simple, right? Except the board is
littered with spaces that flip your roll, hurl you across the map, or swallow
you into a loop you can only escape by landing on the *exact* right number.
Built from the ground up in modern C++ as a showcase of clean object-oriented
design — real polymorphism, RAII memory management, and a color-coded live
board rendered straight to your terminal.

```
[00.] X O   [01.]       [02.]       [03N]       [04.]       [05.]
[06E]       [07.]       [08.]       [09S]       [10.]       [11.]
[12E]       [13.]       [14.]       [15N]       [16.]       [17.]
[18S]       [19.]       [20L]       [21.]       [22.]       [23.]
[24.]       [25X]       [26.]       [27.]       [28N]       [29.]
[30.]       [31E]       [32.]       [33S]       [34.]       [35.]

Legend: .=Plain  N=Number  E=EvenOdd  S=Shortcut  L=Loop  X=Exit
```
*(In your terminal, every space above is color-coded and each player's token
lights up wherever they're standing.)*

---

## ✨ Why it's fun to read (not just play)

This isn't just "roll dice, move token." It's a small, deliberately-designed
simulation:

- 🎨 **A living, color-coded board** — every space type gets its own color,
  and both players' tokens are rendered live on the grid as they move.
- ⏸️ **You control the pace** — press **Enter** to take each turn, so you can
  actually watch the story of the game unfold instead of a wall of text
  scrolling by.
- 🧩 **Six distinct space types**, each with its own personality (see below).
- 🌀 **A real trap** — the Endless Loop isn't just flavor text. Land on it and
  you're stuck circling until you roll *exactly* right to land on the exit.
- 🏗️ **Genuine OOP under the hood** — a `Space` base class with real virtual
  dispatch, not a pile of `if` statements pretending to be inheritance.

## 🗺️ The spaces

| Symbol | Space | What happens |
|:---:|---|---|
| 🟡 `N` | **Number** | Roll the operation die — `+` moves you forward, `-` sends you back, by the space's number. |
| 🔵 `E` | **Even/Odd** | Roll a die needing to match EVEN or ODD to break free and move; miss it and you lose your next turn. |
| 🟣 `S` | **Shortcut** | Instant teleport to another space on the board. |
| 🔴 `L` | **Endless Loop** | You're trapped, circling a fixed loop of spaces until you roll the exact number to land on... |
| 🟢 `X` | **Exit** | ...this. Land here precisely (while in the matching loop) to finally escape. |
| ⚪ `.` | **Plain** | Nothing to see here. Breathe easy. |

## 🚀 Getting started

```bash
make
./coolkidgame
```

You'll be asked for two player names, then the board appears. Hit **Enter**
to take each turn — the current player's roll, movement, and any space
effects print right above the updated board.

```bash
make clean   # remove the built binary
```

**Requirements:** a C++17-capable compiler (`g++`) and a terminal that
supports ANSI color codes (virtually all modern terminals do).

## 🏛️ Architecture

```
Game
 ├── Board ──── vector<Space*>  (36 positions, real polymorphism)
 │              ├── EvenOddSpace
 │              ├── NumberSpace
 │              ├── ShortcutSpace
 │              ├── EndlessLoopSpace
 │              └── ExitSpace
 ├── Player × 2 ──── Token
 ├── NumberDie × 2
 └── OperationDie
```

- **`Space`** is a genuine polymorphic base class — every space type inherits
  from it, gets stored as a `Space*` on the board, and is dispatched to its
  real behavior with `dynamic_cast` at runtime. No slicing, no shortcuts.
- **`Board`** owns its spaces (`vector<Space*>`), manages loop-aware
  movement, and renders the color-coded terminal view.
- **`Game`** is the referee: rolls dice, moves players, resolves whatever
  space they land on, and checks for a winner.
- **`Player`** carries its own turn-skip flag and loop state — no player
  ever needs to reach into the board to know if they're trapped.

## 🧪 Verified, not just vibes

The trickiest logic — loop entry, wrap-around movement, exact-landing exits,
and the even/odd skip-turn penalty — was validated with a direct logic test
harness (independent of dice RNG), not just by eyeballing playthroughs.

## 📄 License

Free to use, modify, and build on for coursework, learning, or your own
spin-off board game.
