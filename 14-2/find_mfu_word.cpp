#include "ooptool.h"
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main()
{

	vector<string> words = read_words("around_the_world_in_eigthy_days.txt"); //Alle Wörter in einem String
	unordered_map<string, unsigned> wordmap;

	for(string elem : words) //Gehe durch alle Wörter
	{
		//Key schon vorhanden: Erhöhe Wert
		if(wordmap.find(elem) != wordmap.end())
		{
			wordmap[elem]++;
		}
		//Key noch nicht vorhanden: Füge ein
		else
		{
			wordmap.insert({elem, 1});
		}
	}

	string most_common_word;
	unsigned quantity = 0;

	for(const auto &pair : wordmap) //Gehe alle Einträge der Hashmap durch
	{
		if(pair.second > quantity)
		{
			quantity = pair.second;
			most_common_word = pair.first;
		}
	}

	cout << "Das häufigste Wort in \"All around the world in 80 days\" ist \"" << most_common_word << "\" mit einer Häufigkeit von " << quantity << " mal." << endl;


}
