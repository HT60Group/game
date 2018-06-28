#include "leaf/API.h"

class Player
{
public:
	Server * p_server;
	Client* p_client;

	static Player* getInstance(){
		static Player INSTANCE;
	    return &INSTANCE;
	}

	std::string getname() { return name; }
	void setname(std::string newName) { name = newName; }
	bool is_Server;
private:

	std::string name;
};