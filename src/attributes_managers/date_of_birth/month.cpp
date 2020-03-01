#include "attributes_managers/date_of_birth/month.h"


void Month::AddUUID(day_t day, uuid_t uuid)
{
    m_days[day].AddUUID(uuid);
}

void Month::add_users_in_range_to_external_cont(day_t begin_day, day_t end_day, ordered_uuids_t& ext_uuids_cont)
{
    for (day_t curr_day = begin_day; curr_day < end_day; ++curr_day)
	{
		m_days[curr_day].AddUsersToExternalCont(ext_uuids_cont);
	}
}

void Month::AddUUIDsBornAfterGivenDayToExternalCont(day_t day, ordered_uuids_t& ext_uuids_cont)
{
    add_users_in_range_to_external_cont(day + 1, MAX_DAYS_IN_MONTH + 1, ext_uuids_cont);
}

void Month::AddUUIDsBornOnOrBeforeGivenDayToExternalCont(day_t day, ordered_uuids_t& ext_uuids_cont)
{
    add_users_in_range_to_external_cont(1, day + 1, ext_uuids_cont);
}

void Month::AddUUIDsOfWholeMonthToExternalCont(ordered_uuids_t& ext_uuids_cont)
{
    add_users_in_range_to_external_cont(1, MAX_DAYS_IN_MONTH + 1, ext_uuids_cont);
}

void Month::DeleteUUID(day_t day, uuid_t uuid)
{
    m_days[day].DeleteUUID(uuid);
}

