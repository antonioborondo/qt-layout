# qtcreator-layout

[![CI](https://github.com/antonioborondo/qtcreator-layout/actions/workflows/ci.yml/badge.svg?branch=main)](https://github.com/antonioborondo/qtcreator-layout/actions/workflows/ci.yml)

## Description

Tool to save and load the Qt Creator layout.

## Features

- Save the layout of the left panel, bottom panel, and status bar.
- Allows saving multiple layouts identified by name.

## Usage

### Save layout

1) Open Qt Creator and adjust the layout to your preference.

2) Close Qt Creator.

3) Save the layout with any name you like:

    ```shell
    $ qtcreator-layout --save widescreen
    ```

4) Verify that the layout was saved by listing the available layouts:

    ```shell
    $ qtcreator-layout --list
    Layouts:
    - widescreen
    ```

### Load layout

1) List the previously saved layouts:

    ```shell
    $ qtcreator-layout --list
    Layouts:
    - widescreen
    ```

2) Load the layout by its name:

    ```shell
    $ qtcreator-layout --load widescreen
    ```

3) Open Qt Creator.

## Libraries

- Qt: <https://qt.io>

## Tools

- CMake: <https://cmake.org>
- GitHub Actions: <https://github.com/features/actions>
