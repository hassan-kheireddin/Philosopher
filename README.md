# philosopher

[![42 École](https://img.shields.io/badge/42-École-000000?style=flat&logo=42&logoColor=white)](https://42.fr)

**philosopher** is a concurrency-focused project from the 42 École curriculum. It involves solving the "Dining Philosophers Problem," a classic problem in computer science that explores resource sharing and deadlock avoidance using multithreading and synchronization.

---

## Table of Contents
- [About the Project](#about-the-project)
- [Features](#features)
- [Getting Started](#getting-started)
- [Installation](#installation)
---

## About the Project

The **philosopher** project requires simulating the behavior of philosophers who alternate between eating, thinking, and sleeping. The challenge is to ensure that no deadlock or race conditions occur while multiple threads interact and share resources.

This project focuses on:
- Thread creation and synchronization using mutexes.
- Solving concurrency problems like deadlocks and starvation.
- Understanding and implementing inter-process communication techniques.

---

## Features

- **Multithreading:** Each philosopher runs as an independent thread.
- **Synchronization:** Prevents race conditions with mutexes.
- **Deadlock Avoidance:** Implements strategies to prevent resource deadlocks.
- **Customizable Simulation:** Configure the number of philosophers, time to eat, sleep, and die via command-line arguments.

---

## Getting Started

### Prerequisites
- A Unix-based operating system (Linux or macOS recommended).
- GCC or another compatible C compiler.
- Make utility.

---

## Installation

1. Clone the repository:
   ```bash
   git clone  https://github.com/hassan-kheireddin/Philosopher.git
   cd philosopher
   ```
