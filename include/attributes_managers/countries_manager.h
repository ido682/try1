#pragma once

#include <map>

#include "common/common.h"
#include "attributes_managers/uuids_mapper.h"


class CountriesManager
{
public:
    CountriesManager() = default;
    ~CountriesManager() = default;
    CountriesManager(const CountriesManager& other) = delete;
    CountriesManager& operator=(const CountriesManager& other) = delete;

    void AddUser(country_t country, user_uid_t uuid);
    users_ordered_cont_t GetUsersByCountry(const country_t& country);
    void DeleteUser(country_t country, user_uid_t uuid);

private:
    UUIDsMapper m_countries;
}; //CountriesManager