#include "database.hpp"

#include "libintl_funcs.h"

#include "gettext_mo.h"

namespace libmo {

TranslationDatabase::~TranslationDatabase() = default;
TranslationDatabaseKaitai::~TranslationDatabaseKaitai() = default;

std::string TranslationDatabaseKaitai::lookup(std::string_view &query) {
	auto res = lookup_hashtable(query);
	if(res.empty()){
		return lookup_bisect(query);
	}
	return res;
};

std::string TranslationDatabaseKaitai::lookup_hashtable(std::string_view &query) {
	auto hash = intl_string_hash(query);
	//std::cerr << query << " " << hash << std::endl;
	auto lookup = gettext_mo_t::gettext_mo_t::hashtable_lookup_t(query, hash, t._io(), &t, &t);
	gettext_mo_t::lookup_iteration_t *entry {lookup.entry()};
	for(; !entry->found(); entry = entry->next()) {
		//std::cerr << "original: " << entry->current()->original() << " translation: " << entry->current()->translation() << std::endl;
		if(entry->current()->original().empty()) {
			return "";
		}
	}
	return entry->current()->translation();
};

TranslationDatabaseKaitai::TranslationDatabaseKaitai(std::istream &dbStream): ks(&dbStream), t(&ks){}

std::unique_ptr<TranslationDatabase> open(std::istream &dbStream){
	return std::make_unique<TranslationDatabaseKaitai>(dbStream);
}

};
