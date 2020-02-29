#include <iostream>
#include <string>
#include "common.h"
#include "date_of_birth/dobs_manager.h"
#include "file_handler/file_wrapper.h"
#include "file_handler/file_reader.h"
#include "file_handler/writer_RRR.h" //RRR
#include "users/parser.h"
#include "db_proxy/db_proxy.h"


void print_user(user_t user)
{
	std::cout<<"----------------------"<<std::endl;
	std::cout<<"long_id: "<<user.long_id<<std::endl;
	std::cout<<"full_name: "<<user.full_name<<std::endl;
	std::cout<<"dob: "<<user.dob<<std::endl;
	std::cout<<"country: "<<user.country<<std::endl;
	std::cout<<"----------------------"<<std::endl;
}

int main()
{
	const std::string FILE_NAME = "data/data_2.csv";
	const std::string USER10 = "fbc279e0-d944-533f-8470-2f7d58b46151,bujse@azgupdac.lv,Owen Norris,27/5/1980,CM";
	
	std::cout<<"Beginning"<<std::endl;

	users_ordered_cont_t test();

	std::cout<<"MAIN 1"<<std::endl;

	DBProxy db_proxy(FILE_NAME);

	std::cout<<"MAIN 2"<<std::endl;

	auto users = db_proxy.GetUsersByAttribute(NAME, "hA");

	std::cout<<"MAIN 3"<<std::endl;

	for (const auto& user : users)
	{
		print_user(user);
	}

	users = db_proxy.GetUsersByAttribute(NAME, "HA");

	std::cout<<"MAIN 4"<<std::endl;

	for (const auto& user : users)
	{
		print_user(user);
	}

	users = db_proxy.GetUsersByAttribute(AGE, "50");

	std::cout<<"MAIN 5"<<std::endl;

	for (const auto& user : users)
	{
		print_user(user);
	}

	std::cout<<"MAIN END"<<std::endl;


	std::cout<<"End"<<std::endl;

	return 0;
}