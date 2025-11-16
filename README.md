# qtcreator-layout

[![CI](https://github.com/antonioborondo/qtcreator-layout/actions/workflows/ci.yml/badge.svg?branch=main)](https://github.com/antonioborondo/qtcreator-layout/actions/workflows/ci.yml)

## Description

Tool to save and restore the Qt Creator layout.

## Features

- Save the layout of the left panel, bottom panel, and status bar.
- Restore layouts previously saved identified by name.

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

### Restore layout

1) Close Qt Creator.

2) List the previously saved layouts:

    ```shell
    $ qtcreator-layout --list
    Layouts:
    - widescreen
    ```

3) Restore the layout by its name:

    ```shell
    $ qtcreator-layout --restore widescreen
    ```

4) Open Qt Creator.

## Libraries

- Qt: <https://qt.io>

## Tools

- CMake: <https://cmake.org>
- GitHub Actions: <https://github.com/features/actions>
