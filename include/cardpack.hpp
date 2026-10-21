#pragma once
#include "card.hpp"
#include <cstdlib>

namespace htcg {
    class CardPack {
        public:
            CardPack() {};
    
            Card** openPack() {
                Card** cards = new Card*[cardsPerPack];

                for (int i = 0; i < cardsPerPack; ++i) {
                    SpecialAttribute attrib = NONE;
                    const double shinyPull = (double)rand()/ RAND_MAX;
                    const double platedPull = (double)rand() / RAND_MAX;
                    if (shinyPull <= shinyProb) {
                        attrib = SHINY;
                    }
                    if (platedPull <= platedProb) {
                        attrib = PLATED;
                    }
                    
                    Artwork artworkPull = (Artwork)(rand() % Artwork::END_ENUM_ARTWORK);
                    
                    cards[i] = new Card(++mintedCards, artworkPull, attrib);
                }

                return cards;
            }
        public:
            const int cardsPerPack = 5;
        private:
            const double shinyProb = 0.01;
            const double platedProb = 0.0001;
            int mintedCards = 0;
    };
}