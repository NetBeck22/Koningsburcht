# Koningsburcht

Koningsburcht is a first-year school project for an object-oriented programming course. It is a C++ desktop implementation inspired by the board game of the same name, built with Qt Widgets.

The project models the game using classes for players, resources, buildings, helpers, and character cards. A Qt graphics scene provides the game interface, while a JSON file stores the initial game state.

## Gameplay

This is a two-player, turn-based game. Players choose character cards, gather and trade resources, construct buildings, and assign helpers. Character actions are resolved in order, and the game awards points based on the players' progress and helper placements.

The implemented character actions include:

- **Messenger:** collects coins from the bank.
- **Trader:** gathers resources reserved through the courier.
- **Bricklayer:** uses resources to construct buildings and manage helpers.
- **Master Builder:** returns cards to the player and awards points for building activity.

The interface and prompts are currently in Dutch.

## Technologies

- C++17
- Qt Widgets (Qt 5 or Qt 6)
- qmake project configuration
- JSON for initial game state

## Build and Run

Open `konproj.pro` in Qt Creator, select a desktop Qt kit, then build and run. With Qt's command-line tools configured, the typical qmake workflow is:

```sh
qmake konproj.pro
make
./konproj
```

On macOS, the built application may instead be located in the generated `.app` bundle, depending on the selected Qt kit and build configuration.

## Current Checkout Limitations

This checkout is not currently buildable as-is. `konproj.pro` references project files that are not present in the repository directory, including `board.cpp`, `building.cpp`, and related headers. Restore the missing files or update the project configuration before building.

The game also loads its JSON data from a hardcoded Windows path in `game.cpp`. That path must be changed to the location of `koningsBurchtFile.json` (or resolved relative to the application). The JSON file is currently at the repository root, while `konproj.pro` refers to `files/koningsBurchtFile.json`.

## Main Files

- `game.cpp`, `gameview.cpp`: game logic and interface coordination
- `player.cpp`, `resources.cpp`: player and resource state
- `messengercard.cpp`, `tradercard.cpp`, `masterBuilderCard.cpp`: character actions
- `mainwindow.cpp`, `mainwindow.ui`: application window
- `koningsBurchtFile.json`: initial board and player state
- `konproj.pro`: qmake project configuration

This repository does not currently include automated tests or a separate rules manual. The gameplay description is based on the source code available here.