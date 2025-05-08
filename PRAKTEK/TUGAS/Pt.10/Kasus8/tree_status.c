
#include "nbtrees.h"

boolean IsEmpty(Isi_Tree P) {
    return (P[1].info == '\0' || P[1].ps_fs == nil);
}
