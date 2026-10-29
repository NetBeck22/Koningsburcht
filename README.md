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

## UML

The project's UML class diagram is available in [docs/KoningsBurchtUML.pdf](docs/KoningsBurchtUML.pdf).

## Build and Run

Open `konproj.pro` in Qt Creator, select a desktop Qt kit, then build and run. With Qt's command-line tools configured, the typical qmake workflow is:

```sh
qmake konproj.pro
make
./konproj
```

On macOS, the built application may instead be located in the generated `.app` bundle, depending on the selected Qt kit and build configuration.

## Game Data

The initial game state is stored in `data/koningsBurchtFile.json` and bundled into the application by `data/gameData.qrc`. The game loads it as a Qt resource, so launching from a different working directory does not affect the data path.

## Project Structure

- `src/model/`: board, buildings, players, resources, helpers, and game rules
- `src/cards/`: card classes and character actions
- `src/view/`: Qt graphics views and main window
- `src/main.cpp`: application entry point
- `data/`: starting game state and Qt resource file
- `docs/KoningsBurchtUML.pdf`: UML class diagram
- `konproj.pro`: qmake project configuration

This repository does not currently include automated tests or a separate rules manual. The gameplay description is based on the source code available here.