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
	std::cout<<"------------------------------------------------------------"<<std::endl;
	std::cout<<"long_id: "<<user.long_id<<std::endl;
	std::cout<<"full_name: "<<user.full_name<<std::endl;
	std::cout<<"dob: "<<user.dob<<std::endl;
	std::cout<<"country: "<<user.country<<std::endl;
	std::cout<<"------------------------------------------------------------"<<std::endl;
}

int main()
{
	const std::string FILE_NAME = "data/data_2.csv";
	
	std::cout<<"MAIN Beginning"<<std::endl;

	DBProxy db_proxy(FILE_NAME);

	std::cout<<"MAIN - names #1 - hA"<<std::endl;
	auto users = db_proxy.GetUsersByAttribute(NAME, "hA");
	for (const auto& user : users)
	{
		print_user(user);
	}

	std::cout<<"MAIN - names #2 - HA"<<std::endl;
	users = db_proxy.GetUsersByAttribute(NAME, "HA");
	for (const auto& user : users)
	{
		print_user(user);
	}

	std::cout<<"MAIN - names #3 - HAM"<<std::endl;
	users = db_proxy.GetUsersByAttribute(NAME, "HAM");
	for (const auto& user : users)
	{
		print_user(user);
	}

	std::cout<<"MAIN - names #4 - HaM"<<std::endl;
	users = db_proxy.GetUsersByAttribute(NAME, "HaM");
	for (const auto& user : users)
	{
		print_user(user);
	}

	std::cout<<"MAIN - age #1 - 50"<<std::endl;
	users = db_proxy.GetUsersByAttribute(AGE, "50");
	for (const auto& user : users)
	{
		print_user(user);
	}

	std::cout<<"MAIN - age #2 - 50"<<std::endl;
	users = db_proxy.GetUsersByAttribute(AGE, "50");
	for (const auto& user : users)
	{
		print_user(user);
	}

	std::cout<<"MAIN - country #1 - ET"<<std::endl;
	users = db_proxy.GetUsersByAttribute(COUNTRY, "ET");
	for (const auto& user : users)
	{
		print_user(user);
	}

	std::cout<<"MAIN - country #2 - ET"<<std::endl;
	users = db_proxy.GetUsersByAttribute(COUNTRY, "ET");
	for (const auto& user : users)
	{
		print_user(user);
	}

	std::cout<<"MAIN - country #3 - TA"<<std::endl;
	users = db_proxy.GetUsersByAttribute(COUNTRY, "TA");
	for (const auto& user : users)
	{
		print_user(user);
	}

	std::cout<<"MAIN - long_id #1 - 8e6fbab1-0244-5fc0-9619-8c1006e22afc"<<std::endl;
	long_id_t long_id1 = "8e6fbab1-0244-5fc0-9619-8c1006e22afc";
	user_t user1 = db_proxy.GetUserByLongID(long_id1);
	print_user(user1);

	std::cout<<"MAIN - long_id #2 - 8e6fbab1-0244-5fc0-9619-8c1006e22afc"<<std::endl;
	user_t user2 = db_proxy.GetUserByLongID(long_id1);
	print_user(user2);


	std::cout<<"MAIN End"<<std::endl;

	return 0;
}