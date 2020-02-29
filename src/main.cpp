#include <iostream>
#include <string>
#include "common.h"
#include "date_of_birth/dobs_manager.h"
#include "file_handler/file_wrapper.h"
#include "file_handler/file_reader.h"
#include "file_handler/writer_RRR.h" //RRR


int main()
{
	const std::string FILE_NAME = "data/data_2.csv";
	const std::string USER10 = "fbc279e0-d944-533f-8470-2f7d58b46151,bujse@azgupdac.lv,Owen Norris,27/5/1980,CM";
	
	std::cout<<"Beginning"<<std::endl;

	std::cout<<"Opening a file"<<std::endl;

	{
		FileReader file_data_2(FILE_NAME);
		file_data_2.ProcessNewLines();
	}

	{
		Writer file_for_writing(FILE_NAME);
		file_for_writing.AddLine(USER10);
	}

	{
		FileReader file_data_2(FILE_NAME);
		file_data_2.ProcessNewLines();
	}

	DOBsManager dobs_manager;
	dobs_manager.AddUser({9, 3, 1985}, 111);
	dobs_manager.AddUser({28, 2, 1985}, 222);
	dobs_manager.AddUser({29, 2, 1985}, 333);
	dobs_manager.AddUser({4, 4, 2010}, 444);
	dobs_manager.AddUser({27, 2, 1985}, 555);

	users_unordered_cont_t users_aged_35 = dobs_manager.GetUsersInGivenAge(35);
	std::cout<<"Age 35:"<<users_aged_35.size()<<std::endl;
	for (const auto& user : users_aged_35)
	{
		std::cout<<user<<std::endl;
	}

	users_unordered_cont_t users_aged_34 = dobs_manager.GetUsersInGivenAge(34);
	std::cout<<"Age 34:"<<std::endl;
	for (const auto& user : users_aged_34)
	{
		std::cout<<user<<std::endl;
	}
	

	std::cout<<"End"<<std::endl;

	return 0;
}