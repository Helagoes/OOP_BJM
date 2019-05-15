#include "damen.h"
using namespace std;

bool solve_queens_puzzle(vector<int>& fieldvec, size_t algorithm_depth)
{
	size_t N = fieldvec.size() - algorithm_depth; //for reuse of single-time-calculated value
	//cout << "Testausgabe, Tiefe: " << algorithm_depth << endl;
	fieldvec[N] = 0;

	while(fieldvec[N] < fieldvec.size())
	{
		if(algorithm_depth > 1)
		{
			if(solve_queens_puzzle(fieldvec, algorithm_depth-1) == false) //recursion, go "deeper" into algorithm-structure
			{
				fieldvec[N]++; //move queen one position further
			}
			else
			{
				return true;
			}
		}
		else //deepest algorithm level
		{
			return field_integrity(fieldvec);
		}
	}
	return false;
}

bool field_integrity(vector<int> fieldvec) //validation if given field arrangement is permitted
{
	for(size_t i = 0; i < fieldvec.size(); i++)
	{
		for(size_t j = 0; j < fieldvec.size(); j++)
		{
			if(fieldvec[i] == fieldvec[j] && (i != j)) //rule 1: no queens in same row
			{
				return false;
			}
			else if( ((i-j) > 0) && ( (i-j) == fabs(fieldvec[i] - fieldvec[j])) ) //rule 2: no queens diagonal to another
			{
				return false;
			}
		}
	}
	return true;
}

int main(int argc, const char** argv)
{
	argsp_t cmd(argc, argv);

	size_t N = stoi(cmd.pos(0, "8"));
	vector<int> brettspalten(N);

	if(solve_queens_puzzle(brettspalten, N))
	{
		cout << "Lösung für " << N << " Damen gefunden. Lösung: {";
		for(size_t i = 0; i < brettspalten.size(); i++)
		{
			cout << brettspalten[i];
			if(i < (brettspalten.size() - 1))
				cout << ",";
			else
				cout << "}" << endl;
		}
	}
	else
	{
		cout << "Es gibt keine Lösung dafür " << N << " Damen auf einem " << N << "x" << N << " Spielfeld zu platzieren." << endl;
	}
}
