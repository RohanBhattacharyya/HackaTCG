#pragma once

#include "enums.hpp"

namespace htcg {
    class Card {
        public:
            Card(): identifier(-1), art(), attrib() {}

            Card(int identifier, htcg::Artwork art, htcg::SpecialAttribute attrib) : identifier(identifier), art(art), attrib(attrib) {}

        public:
            const long long identifier;
            const htcg::Artwork art;
            const htcg::SpecialAttribute attrib;
    };
}