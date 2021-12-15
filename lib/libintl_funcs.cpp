#pragma once
#include <cstddef>
#include <compare>

#include "database.hpp"
#include "libintl_funcs.h"

/*
Copyright (c)2003, 2004 Citrus Project,
All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

namespace libmo {

/*
 * string hash function by P.J.Weinberger.
 * this implementation is derived from src/lib/libc/citrus/citrus_db_hash.c.
 */
uint32_t intl_string_hash(std::string_view &str) {
	uint32_t hash = 0, tmp;

	for(auto c: str) {
		hash <<= 4;
		hash += c;
		tmp = hash & 0xF0000000;
		if(tmp != 0) {
			hash ^= tmp;
			hash ^= tmp >> 24;
		}
	}
	return hash;
}

std::string TranslationDatabaseKaitai::lookup_bisect(std::string_view &query) {
	auto &mo = *t.mo();

	auto count = mo.num_translations();
	auto &transls = *mo.translations();
	auto &origs = *mo.originals();
	size_t top = 0, bottom = count, middle, omiddle = 0;

	/* CONSTCOND */
	while (1) {
		if (top > bottom){
			break;
		}
		middle = (top + bottom) / 2;
		/* avoid possible infinite loop, when the data is not sorted */
		if (omiddle == middle){
			break;
		}
		if (static_cast<size_t>(middle) >= count){
			break;
		}

		auto n = query <=> origs[middle]->str();
		if (n == std::strong_ordering::equivalent or n == std::strong_ordering::equal) {
			return transls[middle]->str();
		} else{
			if (n == std::strong_ordering::less){
				bottom = middle;
			}else{
				top = middle;
			}
		}
		omiddle = middle;
	}

	return "";
}

};
