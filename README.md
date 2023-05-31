# Zephyr C++ Synchronization Application Sample

This is a Zephyr C++ synchronization application sample based on a [Zephyr Manifest Workspace Application](https://github.com/borrelunde/zephyr-manifest-workspace-application) project structure.

## Getting Started

Before getting started, make sure you have a proper Zephyr development environment installed. Follow the official [Zephyr Getting Started Guide](https://docs.zephyrproject.org/latest/develop/getting_started/index.html).

Clone the repository to a folder of your liking:

```shell
git clone https://github.com/borrelunde/zephyr-cpp-synchronization-app-sample workspace-app-name
```

Enter the workspace, activate the West virtual environment and update Zephyr modules:

```shell
cd workspace-app-name

# Windows (default installation)
%USERPROFILE%\zephyrproject\.venv\Scripts\activate.bat

west update
```

This should take a while.

## Building and Running

Open Command Prompt inside the workspace directory.

If not already activated, activate the West virtual environment. Change the path if yours is different:

```shell
# Windows (default installation)
%USERPROFILE%\zephyrproject\.venv\Scripts\activate.bat
```

Build the application. On the initial build, you must specify what board to build for. I build for the board `nRF52840 Development Kit`. Any supported board can be used instead:

```shell
west build -b nrf52840dk_nrf52840 application
```

Once you have built the application, flash it to the board:

```shell
west flash
```
