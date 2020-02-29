#include "attributes_managers/countries_manager.h"


void CountriesManager::AddUser(country_t country, user_uid_t uuid)
{
    m_countries.AddUser(country, uuid);
}

users_ordered_cont_t CountriesManager::GetUsersByCountry(const country_t& country)
{
    users_ordered_cont_t users;
    
    m_countries.AddUsersWithGivenKeyToExternalCont(country, users);

    return users;                                           
}

