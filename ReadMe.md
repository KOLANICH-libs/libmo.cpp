libmo.cpp [![Unlicensed work](https://raw.githubusercontent.com/unlicense/unlicense.org/master/static/favicon.png)](https://unlicense.org/)
=========
~~[![GitHub Actions](https://github.com/KOLANICH-libs/libmo.cpp/workflows/CI/badge.svg)](https://github.com/KOLANICH-libs/libmo.cpp/actions/)~~
[![Libraries.io Status](https://img.shields.io/librariesio/github/KOLANICH-libs/libmo.cpp.svg)](https://libraries.io/github/KOLANICH-libs/libmo.cpp)

**We have moved to https://codeberg.org/KOLANICH-libs/libmo.cpp, grab new versions there.**

Under the disguise of "better security" Micro$oft-owned GitHub has [discriminated users of 1FA passwords](https://github.blog/2023-03-09-raising-the-bar-for-software-security-github-2fa-begins-march-13/) while having commercial interest in success and wide adoption of [FIDO 1FA specifications](https://fidoalliance.org/specifications/download/) and [Windows Hello implementation](https://support.microsoft.com/en-us/windows/passkeys-in-windows-301c8944-5ea2-452b-9886-97e4d2ef4422) which [it promotes as a replacement for passwords](https://github.blog/2023-07-12-introducing-passwordless-authentication-on-github-com/). It will result in dire consequencies and is competely inacceptable, [read why](https://codeberg.org/KOLANICH/Fuck-GuanTEEnomo).

If you don't want to participate in harming yourself, it is recommended to follow the lead and migrate somewhere away of GitHub and Micro$oft. Here is [the list of alternatives and rationales to do it](https://github.com/orgs/community/discussions/49869). If they delete the discussion, there are certain well-known places where you can get a copy of it. [Read why you should also leave GitHub](https://codeberg.org/KOLANICH/Fuck-GuanTEEnomo).

---

A library to parse `gettext`/`libintl` `mo` format.

## Why?
* NIH-syndrome :)
* `libintl` doesn't expose the "middle-level" API to fetch a certain value from a `mo` file by a given a key. Only "high-level" API for translating apps, that does too much things itself (enforces policy), is exposed.
* `catgets` is a low-level lib looking up messages by their ids, not by their keys.

I needed to just have a key-value database and has chosen `mo` files for it. It seems that existing libs don't support this workflow.

## How
We use an [own Kaitai Struct-based parser of `mo` files](https://codeberg.org/kaitai-io/kaitai_struct_formats/src/branch/master/database/gettext_mo.ksy).

