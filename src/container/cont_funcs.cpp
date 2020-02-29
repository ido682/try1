#include "container/cont_funcs.h"

namespace ContFuncs
{
    void AddUsersInContToExternalCont(const users_ordered_cont_t& base_cont,
                                      users_ordered_cont_t& ext_cont)
    {
        for (const auto& user : base_cont)
        {
            ext_cont.insert(user);
        }
    }
} //ContFuncs