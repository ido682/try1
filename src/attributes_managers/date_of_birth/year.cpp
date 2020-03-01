#include "attributes_managers/date_of_birth/year.h"


void Year::AddUUID(day_t day, month_t month, uuid_t uuid)
{
	m_months[month].AddUUID(day, uuid);
}

void Year::AddUUIDsBornAfterGivenDayToExternalCont(day_t day, month_t month, ordered_uuids_t& ext_uuids_cont)
{	
	m_months[month].AddUUIDsBornAfterGivenDayToExternalCont(day, ext_uuids_cont);

	for (month_t curr_month = month + 1; curr_month <= MONTHS_IN_YEAR; ++curr_month)
	{
		m_months[curr_month].AddUUIDsOfWholeMonthToExternalCont(ext_uuids_cont);
	}
}

void Year::AddUUIDsBornOnOrBeforeGivenDayToExternalCont(day_t day, month_t month, ordered_uuids_t& ext_uuids_cont)
{
	for (month_t curr_month = 1; curr_month < month; ++curr_month)
	{
		m_months[curr_month].AddUUIDsOfWholeMonthToExternalCont(ext_uuids_cont);
	}

	m_months[month].AddUUIDsBornOnOrBeforeGivenDayToExternalCont(day, ext_uuids_cont);
}

void Year::DeleteUUID(day_t day, month_t month, uuid_t uuid)
{
	m_months[month].DeleteUUID(day, uuid);
}

