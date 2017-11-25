#pragma once
#include "json.hpp"

using Json = nlohmann::json;

namespace cegueta {
	namespace reader {
		class JsonReader
		{
		public:
			JsonReader();
			~JsonReader();
			static Json readerFile(std::string);
		private:
			Json currentJson;
		};
	}
}
