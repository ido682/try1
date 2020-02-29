#include "users/user.h"


User::User(long_id_t long_id, full_name_t full_name, date_t dob, country_t country) :
    m_long_id(long_id),
    m_full_name(full_name),
    m_dob(dob),
    m_country(country)
{
    // Intentionally left blank
}

