#include <string>
namespace htcg {
    enum Artwork {
        RATTICUS,
        ANGRY,
        HALO,
        SAD,
        END_ENUM_ARTWORK
    };

    enum SpecialAttribute {
        NONE,
        SHINY,
        PLATED,
        END_ENUM_SPECIAL
    };

    inline std::string getName(Artwork art) {
        switch (art) {
            case RATTICUS:
                return "Ratticus";
            case ANGRY:
                return "A. Ratticus";
            case HALO:
                return "H. Ratticus";
            case SAD:
                return "S. Ratticus";
            default:
                return "error";
        }
    }

}