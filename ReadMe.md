libmo.cpp [![Unlicensed work](https://raw.githubusercontent.com/unlicense/unlicense.org/master/static/favicon.png)](https://unlicense.org/)
=========
~~[![GitHub Actions](https://github.com/KOLANICH-libs/libmo.cpp/workflows/CI/badge.svg)](https://github.com/KOLANICH-libs/libmo.cpp/actions/)~~
[![Libraries.io Status](https://img.shields.io/librariesio/github/KOLANICH-libs/libmo.cpp.svg)](https://libraries.io/github/KOLANICH-libs/libmo.cpp)

A library to parse `gettext`/`libintl` `mo` format.

## Why?
* NIH-syndrome :)
* `libintl` doesn't expose the "middle-level" API to fetch a certain value from a `mo` file by a given a key. Only "high-level" API for translating apps, that does too much things itself (enforces policy), is exposed.
* `catgets` is a low-level lib looking up messages by their ids, not by their keys.

I needed to just have a key-value database and has chosen `mo` files for it. It seems that existing libs don't support this workflow.

## How
We use an [own Kaitai Struct-based parser of `mo` files](https://codeberg.org/kaitai-io/kaitai_struct_formats/src/branch/master/database/gettext_mo.ksy).

