#pragma once
#include <libmo/mo.hpp>
#include "gettext_mo.h"

namespace libmo {

struct TranslationDatabaseKaitai: public TranslationDatabase{
	kaitai::kstream ks;
	gettext_mo_t t;

	TranslationDatabaseKaitai(std::istream &dbStream);

	std::string lookup_hashtable(std::string_view &query);
	std::string lookup_bisect(std::string_view &query);
	std::string lookup(std::string_view &query) override;
	~TranslationDatabaseKaitai() override;
};

};
