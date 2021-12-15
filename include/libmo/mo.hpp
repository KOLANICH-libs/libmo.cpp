#pragma once
#include <string_view>
#include <memory>
#include <istream>

namespace libmo {

struct TranslationDatabase{
	virtual std::string lookup(std::string_view &p_query) = 0;
	virtual ~TranslationDatabase();
};

std::unique_ptr<TranslationDatabase> open(std::istream &dbStream);

};
