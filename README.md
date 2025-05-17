# QMK Userspace

This is the git repo for my QMK keyboard layouts.

<https://docs.qmk.fm/newbs_getting_started>

## Setup

```bash
brew install qmk/qmk/qmk
qmk setup
```

## Howto build locally

1. Clone your fork of this repo to your local machine
1. `cd` into this repository's clone directory
1. Set global userspace path: `qmk config user.overlay_dir="$(realpath .)"`
    - This will be automatically detected if you've `cd`ed into your userspace
      repository, but the above makes your userspace available regardless of your
      shell location.
1. Compile normally: `qmk compile -kb your_keyboard -km your_keymap` or `make
your_keyboard:your_keymap`

Add userspace:

```bash
qmk userspace-add -kb splitkb/kyria/rev3 -km alphaone
```

If you configured your build targets above, you can use `qmk userspace-compile`
to build all of your userspace targets at once.

## Configure

```bash
qmk config user.keyboard=splitkb/kyria/rev3
qmk config user.keyboard=splitkb/kyria/alphaone
```

## Flash

If keyboard and layout are configured correctly, you can flash your keyboard with:

```bash
qmk flash
```

Or:

```bash
qmk flash -kb splitkb/kyria/rev3 -km alphaone
```
