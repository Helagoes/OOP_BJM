#include <iostream>
#include <vector>
#include "participant.h"
#include "ntime.h"
#include "ooptool.h"

using namespace std;

int main(int argc, char* argv[])
{
	vector<string> nameslist = {"Hannah", "Mark", "Theodor", "WasAuchImmer"};
	int n = nameslist.size();
	vector<participant> all_participants(n);
	vector<int> rand_vals(n);
	rand_vals = create_randints(n, 0, 1000);

	for(size_t i=0; i<all_participants.size(); i++)
	{
		all_participants[i].set_name(nameslist[i]);
		all_participants[i].set_runtime(rand_vals[i]);
	}

	int mintime = 1001;
	string winner;

	for(size_t i = 0; i<all_participants.size(); i++)
	{
		if((all_participants[i].get_runtime()).justseconds() < mintime)
		{
			mintime = (all_participants[i].get_runtime()).justseconds();
			winner = all_participants[i].get_name();
		}
	}
	cout << "Gewinner ist " << winner << " mit einer Zeit von " << mintime << endl
			<< "Gesamtzahl Teilnehmer: " << count << endl;
}
