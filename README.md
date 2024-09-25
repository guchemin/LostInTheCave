# Lost In The Cave

**Lost In The Cave** is a 2D adventure game developed in C++ using Object-Oriented Programming (OOP) principles. The game is set in a mysterious cave environment where the objective is to navigate through obstacles, avoid enemies, and find the exit. The game supports both single-player and two-player modes and features two distinct levels with varying characters, obstacles, and difficulty levels. The project was developed as part of the Techniques of Programming course.

## Authors

- Gabriel de França Picinato - gabrielpicinato@alunos.utfpr.edu.br
- Gustavo Chemin Ribeiro - gustavochemin@alunos.utfpr.edu.br

## Features

- **Single and Two-Player Modes**: Play solo or team up with a friend.
- **Two Unique Levels**: Each level presents a different set of challenges and environments.
- **Dynamic Obstacles and Enemies**: Navigate through moving obstacles and face various enemies.
- **Save and Load System**: Players can save their progress and resume from where they left off.
- **Scoreboard**: Save high scores with player names for competition and replayability.

## Technologies Used

- **C++**: Core programming language.
- **SFML 2.5.1**: Used for graphics, audio, and input handling.
- **UML Diagrams**: Used to plan and design the class structures and interactions.
- **JSON**: For saving game states and loading saved progress.

## Game Mechanics

- **Controls**:
  - **Player 1**: Controlled using `A`, `W`, `D` for movement and `Space` to shoot.
  - **Player 2 (if present)**: Controlled using the arrow keys for movement and `K` to attack.
- **Collision Detection**: A custom collision manager checks and handles interactions between players, enemies, and obstacles.
- **Enemies**: The game features 3 different enemies that challenge the player.
- **Obstacles**: There are 3 distinct obstacles that make gameplay more difficult.
- **Lives and Health**: Players must maintain their health to survive the cave's challenges.

## Installation

1. **Clone the repository**:
   ```bash
   git clone https://github.com/guchemin/LostInTheCave.git
