#include <iostream>
#include "/home/ido/workspace/zooz/users_search/include/common.h"
#include "/home/ido/workspace/zooz/users_search/include/date_of_birth/dobs_manager.h"




int main()
{
	std::cout<<"Beginning"<<std::endl;

	std::cout<<"A"<<std::endl;

	DOBsManager dobs_manager;
	std::cout<<"B"<<std::endl;
	dobs_manager.AddUser(9, 3, 1985, 111);
	dobs_manager.AddUser(28, 2, 1985, 222);
	dobs_manager.AddUser(29, 2, 1985, 333);
	dobs_manager.AddUser(4, 4, 2010, 444);
	dobs_manager.AddUser(27, 2, 1985, 555);
	std::cout<<"C"<<std::endl;

	users_unordered_cont_t users_aged_35 = dobs_manager.GetUsersInGivenAge(35);
	std::cout<<"D"<<std::endl;
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